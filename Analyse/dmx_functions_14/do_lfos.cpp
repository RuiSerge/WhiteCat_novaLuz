int do_lfos()
{
 for(int cmptfader=0; cmptfader<core_user_define_nb_faders; cmptfader++)
 {

 int dockis=detect_dock_used(cmptfader);
 prepare_lfos(cmptfader, dockis);
 index_lfoing[cmptfader]=0;//pour lock faisait bugguer le next step

 ////////////////////////////ONCE/////////////////////////////////////////////////////////////////
 if (is_dock_for_lfo_selected[cmptfader][ dockis]==0 && lfo_cycle_is_on[cmptfader]==0)//ONCE CASE
 {
 //up only once
 if(lfo_mode_is[cmptfader]==1 && actual_time>(start_time_for_delays[cmptfader]+time_delay_in[cmptfader]))
 {
 index_lfoing[cmptfader]=1;
 faders_in_float[cmptfader]+=fraction_lfo_in[cmptfader];
 if(faders_in_float[cmptfader]>255){faders_in_float[cmptfader]=255;}
 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }

 lfo_running_is_upward[cmptfader]=1;
 if(faders_in_float[cmptfader]>=255)
 {
 lfo_mode_is[cmptfader]=0;faders_in_float[cmptfader]=255.0;
 }
 //ONSTOP UP LIMITE
 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader]
 || Fader[cmptfader]>LevelStopPos[cmptfader]) && FaderIsFlash[cmptfader]==0)
 {
  //Fader[cmptfader]=LevelStopPos[cmptfader];
  fader_set_level(cmptfader,LevelStopPos[cmptfader]);
  lfo_mode_is[cmptfader]=0;ActionnateStopOn[cmptfader]=0;
  }
 //report midi
 midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}

 }

 //down only once
 else if(lfo_mode_is[cmptfader]==2 && actual_time>(start_time_for_delays[cmptfader]+time_delay_out[cmptfader]))
 {
 index_lfoing[cmptfader]=1;
 faders_in_float[cmptfader]-=fraction_lfo_out[cmptfader];
 if(faders_in_float[cmptfader]<0){faders_in_float[cmptfader]=0;}
 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }

 lfo_running_is_upward[cmptfader]=0;
 if(faders_in_float[cmptfader]==0.0)
 {
 lfo_mode_is[cmptfader]=0;faders_in_float[cmptfader]=0.0;
 }
 //ONSTOP DOWN LIMITE
 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader]
 || Fader[cmptfader]<LevelStopPos[cmptfader]) && FaderIsFlash[cmptfader]==0)
 {
 //Fader[cmptfader]=LevelStopPos[cmptfader];
 fader_set_level(cmptfader,LevelStopPos[cmptfader]);
 lfo_mode_is[cmptfader]=0;ActionnateStopOn[cmptfader]=0;
 }
 //report midi
  midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}


 }
 }
 ////////////////////////////////LOOP ON ONCE//////////////////////////////////////////////////////////////////
 if (is_dock_for_lfo_selected[cmptfader][ dockis]==1 && lfo_cycle_is_on[cmptfader]==0)//LOOP LFO ON ONE DOCK ONLY ( NO DOCK CYCLING)
 {
 //up On Fade IN only
 if(lfo_mode_is[cmptfader]==1 && actual_time>(start_time_for_delays[cmptfader]+time_delay_in[cmptfader]))
 {
 index_lfoing[cmptfader]=1;
 faders_in_float[cmptfader]+=fraction_lfo_in[cmptfader];
 if(faders_in_float[cmptfader]>255){faders_in_float[cmptfader]=255;}
 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }

 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader] || Fader[cmptfader]>LevelStopPos[cmptfader])
 && FaderIsFlash[cmptfader]==0)
 {//Fader[cmptfader]=LevelStopPos[cmptfader];
 fader_set_level(cmptfader,LevelStopPos[cmptfader]);
 }
 //report midi
 midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}

 lfo_running_is_upward[cmptfader]=1;
 if(faders_in_float[cmptfader]>=255)
 {
 start_time_for_delays[cmptfader]=actual_time;
 faders_in_float[cmptfader]=0.0;
 //Fader[cmptfader]=0;
 fader_set_level(cmptfader,0);
 }


 if(faders_in_float[cmptfader]==0.0)//renvoi next dock quand à 0 pos
 {
 if(lfo_do_next_step[cmptfader][1]==1)//down dock
 {
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt<core_user_define_nb_docks-1){ DockIsSelected[cmptfader][tt+1]=1;break;}
  else if(tt==core_user_define_nb_docks-1){DockIsSelected[cmptfader][0]=1;break;}
  }
 }
 }
 else if(lfo_do_next_step[cmptfader][0]==1)//up dock
 {
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt>0){ DockIsSelected[cmptfader][tt-1]=1;break;}
  else if(tt==0){DockIsSelected[cmptfader][core_user_define_nb_docks-1]=1;break;}
  }
 }
}
}
}
 //down On Fade OUT only
 else if(lfo_mode_is[cmptfader]==2 && actual_time>(start_time_for_delays[cmptfader]+time_delay_out[cmptfader]))
 {
 index_lfoing[cmptfader]=1;
 faders_in_float[cmptfader]-=fraction_lfo_out[cmptfader];
 if(faders_in_float[cmptfader]<0){faders_in_float[cmptfader]=0;}
 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }

 //ONSTOP est plancher de la boucle
 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader]
 || Fader[cmptfader]<LevelStopPos[cmptfader]) && FaderIsFlash[cmptfader]==0)
 {
 //    Fader[cmptfader]=255;
   fader_set_level(cmptfader,255);
 }
  //report midi
 midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}

 lfo_running_is_upward[cmptfader]=0;
 if(faders_in_float[cmptfader]==0.0)
 {
 //Fader[cmptfader]=255;
 fader_set_level(cmptfader,255);
 faders_in_float[cmptfader]=255.0;
 start_time_for_delays[cmptfader]=actual_time;
 if(lfo_do_next_step[cmptfader][1]==1)
 {
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt<core_user_define_nb_docks-1){ DockIsSelected[cmptfader][tt+1]=1;break;}
  else if(tt==core_user_define_nb_docks-1){DockIsSelected[cmptfader][0]=1;break;}
  }
 }
 }
  if(lfo_do_next_step[cmptfader][0]==1)
 {
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt>0){ DockIsSelected[cmptfader][tt-1]=1;break;}
  else if(tt==0){  DockIsSelected[cmptfader][core_user_define_nb_docks-1]=1;break;}
  }
 }
 }
 }
 }
 }
 /////////////////////CYCLING SMOOTH IN OUT/ SAW///////////////////////////
 if (lfo_cycle_is_on[cmptfader]==1 )//LOOP LFO ( CYCLING + TIMES)
 {

 index_lfoing[cmptfader]=1;
 //up way
 if(lfo_running_is_upward[cmptfader]==1 && actual_time>(start_time_for_delays[cmptfader]+time_delay_in[cmptfader]))
 {
 faders_in_float[cmptfader]+=fraction_lfo_in[cmptfader];
 if(faders_in_float[cmptfader]>255){faders_in_float[cmptfader]=255;}

 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }

 //ONSTOP est plancher de la boucle
 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader] || Fader[cmptfader]<LevelStopPos[cmptfader])
 && FaderIsFlash[cmptfader]==0)
 { //Fader[cmptfader]=LevelStopPos[cmptfader];
 fader_set_level(cmptfader,LevelStopPos[cmptfader]);
 }
  //report midi
 midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}
 lfo_running_is_upward[cmptfader]=1;
 if(faders_in_float[cmptfader]==255)
 {
 faders_in_float[cmptfader]=255.0;
 //Fader[cmptfader]=255;
 fader_set_level(cmptfader,255);
 start_time_for_delays[cmptfader]=actual_time;
 lfo_running_is_upward[cmptfader]=0;
 }
 }
 //down
 else if(lfo_running_is_upward[cmptfader]==0 && actual_time>(start_time_for_delays[cmptfader]+time_delay_out[cmptfader]))
 {
 faders_in_float[cmptfader]-=fraction_lfo_out[cmptfader];
 if(faders_in_float[cmptfader]<0){faders_in_float[cmptfader]=0;}
 if(FaderIsFlash[cmptfader]==0)//tous calculs ok si pas de flash
 {
 //Fader[cmptfader]=int(faders_in_float[cmptfader]);
 fader_set_level(cmptfader,int(faders_in_float[cmptfader]));
 }


 //ONSTOP est plancher de la boucle
 if( ActionnateStopOn[cmptfader]==1 && StopPosOn[cmptfader]==1 && (Fader[cmptfader]==LevelStopPos[cmptfader] || Fader[cmptfader]<LevelStopPos[cmptfader])
 && FaderIsFlash[cmptfader]==0)
 {
 //Fader[cmptfader]=LevelStopPos[cmptfader];
 fader_set_level(cmptfader,LevelStopPos[cmptfader]);
 }
 //report midi
 midi_levels[cmptfader]=(Fader[cmptfader]/2);
 if(midi_send_out[cmptfader]==1  )
 {index_send_midi_out[cmptfader]=1;}

 if(faders_in_float[cmptfader]==0.0)
 {
 faders_in_float[cmptfader]=0.0;
 if( ActionnateStopOn[cmptfader]==0 && FaderIsFlash[cmptfader]==0)
    {
    //Fader[cmptfader]=0;
    fader_set_level(cmptfader,0);
    }

 start_time_for_delays[cmptfader]=actual_time;
 prepare_lfos(cmptfader, dockis);
 lfo_running_is_upward[cmptfader]=1;

if (is_dock_for_lfo_selected[cmptfader][ dockis]==1 )
{
 if(lfo_do_next_step[cmptfader][1]==1)
 {
  start_time_for_delays[cmptfader]=actual_time;
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt<core_user_define_nb_docks-1){ DockIsSelected[cmptfader][tt+1]=1;break;}
  else if(tt==core_user_define_nb_docks-1)
  {
  DockIsSelected[cmptfader][0]=1;   break;}
  }
 }
 }
 else if(lfo_do_next_step[cmptfader][0]==1)
 {
  start_time_for_delays[cmptfader]=actual_time;
 for (int tt=0;tt<core_user_define_nb_docks;tt++)
  {
 if ( DockIsSelected[cmptfader][tt]==1)
  {
  DockIsSelected[cmptfader][tt]=0;
  if(tt>0){ DockIsSelected[cmptfader][tt-1]=1;break;}
  else if(tt==0){DockIsSelected[cmptfader][core_user_define_nb_docks-1]=1;break;}
  }
 }
 }
}
else if(is_dock_for_lfo_selected[cmptfader][ dockis]==0)
{
 lfo_cycle_is_on[cmptfader]=0;

 }
 }
 }
 }
 if(index_lfoing[cmptfader]==1)
 {
 index_fader_is_manipulated[cmptfader]=1; //pour direct channel
  if(FaderLocked[cmptfader]==1 && LockFader_is_FullLevel[cmptfader]==1)//masterisation au lock des autres faders
 {
 DoLock(cmptfader,Fader[cmptfader]);//remasterisation des niveaux
 //changement du niveau de lock, si on l augmente au dessus de son niveau de lock stocké
 if(Fader[cmptfader]>StateOfFaderBeforeLock[cmptfader] && FaderIsFlash[cmptfader]==0){StateOfFaderBeforeLock[cmptfader]=Fader[cmptfader];}
 }
 }
 /////CYCLE NETX / PREVIOUS ///////////////
  if(lfo_cycle_steps[cmptfader]==1 && lfo_do_next_step[cmptfader][0]==1 && dockis==0)
  {
  lfo_do_next_step[cmptfader][0]=0;
  lfo_do_next_step[cmptfader][1]=1;
  }
  else   if(lfo_cycle_steps[cmptfader]==1 && lfo_do_next_step[cmptfader][1]==1 && dockis==core_user_define_nb_docks-1)
  {
  lfo_do_next_step[cmptfader][1]=0;
  lfo_do_next_step[cmptfader][0]=1;
  }
  ////////////////////////////////


}
 return(0);
}
