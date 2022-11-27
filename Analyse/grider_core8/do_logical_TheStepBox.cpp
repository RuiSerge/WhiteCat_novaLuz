int do_logical_TheStepBox(int xb,int yb, int num_grid_player)
{


if(mouse_x>xb && mouse_x<xb+20 && mouse_y>yb && mouse_y<yb+20 )
{
if( mouse_released==0)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1484+num_grid_player,Midi_Faders_Affectation_Mode);
}
else
{
  gridplayer_step_minus(num_grid_player);
 }
  mouse_released=1;
}
}
 //Step plus
if(mouse_x>xb+60 && mouse_x<xb+60+20 && mouse_y>yb && mouse_y<yb+20 )
{
if( mouse_released==0)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1488+num_grid_player,Midi_Faders_Affectation_Mode);
}
else
{
  gridplayer_step_plus(num_grid_player);
}
  mouse_released=1;
 }
}

if(mouse_x>xb+60 && mouse_x<xb+60+20 && mouse_y>yb-6 && mouse_y<yb-6+5)
{
if( mouse_released==0)
 {
 if( Midi_Faders_Affectation_Type!=0)//config midi
 {
 attribute_midi_solo_affectation(1536+num_grid_player,Midi_Faders_Affectation_Mode);
 }
 mouse_released=1;
}
}
if(mouse_x>xb+22 && mouse_x<xb+22+35 && mouse_y>yb-5 && mouse_y<yb-5+30 )
 {
if( mouse_released==0)
 {
 if( Midi_Faders_Affectation_Type!=0)//config midi
 {
 attribute_midi_solo_affectation(1532+num_grid_player,Midi_Faders_Affectation_Mode);
 }
 else
 {
 if(numeric_postext>0 && index_affect_time==0 && index_main_clear==0 && index_do_dock==0 )
                      {
                      int step_to_affect_to_grid=0;
                      step_to_affect_to_grid=atoi(numeric);
                      if(step_to_affect_to_grid>0 && step_to_affect_to_grid<1024)
                      {
                       index_grider_step_is[num_grid_player]=step_to_affect_to_grid-1;
                       if(grider_seekto_mode[num_grid_player]==1 && grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]>0 )//seek position
                       {index_grider_seek_pos[num_grid_player]=grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]];}
                      }
                      reset_numeric_entry();
                      }
 else if (numeric_postext>0  && index_do_dock==1 && index_enable_edit_Grider==1)//charge mem
 {
  int offset=grider_begin_channel_is-1;
  int mem_to_affect_to_grid=0;
  mem_to_affect_to_grid=int(atof(numeric)*10);

  if(MemoiresExistantes[mem_to_affect_to_grid]==1)
  {
   for(int i=offset;i<513;i++)////A REVOIR COMME SUR EN DESSOUS
   {
   if(i+1<513)
   {
   grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i-offset-1]=Memoires[mem_to_affect_to_grid][i];
   }
   }
   reset_numeric_entry();
   index_do_dock=0;
  }
 }
 else if (index_do_dock==1 && numeric_postext==0 && index_enable_edit_Grider==1)//charge circuits
 {
 int ofset=grider_begin_channel_is-1;
 if(index_affect_time==0)
 {
 switch(index_blind)
 {
 case 0:
  for(int i=ofset;i<513;i++)//OK FEVRIER 2015
 {
  grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i-1-ofset]=bufferSaisie[i];
  bufferSaisie[i]=0;
 }
 break;
  case 1:
  for(int i=1;i<513;i++)
 {
  grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i-1-ofset]=bufferBlind[i];
  bufferBlind[i]=0;
 }
 break;
 default: break;
 }
 }
  else if(index_affect_time==1 )
 {
 switch(to_step_editing_mode[num_grid_player])
 {
 case 0:
                      for(int ty=0;ty<4;ty++)
                      {
                      if(index_type_of_time_to_affect[ty]==1)
                      {
                      grid_times[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][ty]=
                      (time_minutes*60)+time_secondes+(0.01*time_centiemes);
                      }
                      }
                      gridder_prepare_cross(num_grid_player, index_grider_selected[num_grid_player], index_grider_step_is[num_grid_player]);
 break;
 case 1://step to step mode
 if(index_grider_step_is[index_grider_selected[num_grid_player]]<index_StepTo[num_grid_player])
 {
 for(int st=index_grider_step_is[num_grid_player];st<=index_StepTo[num_grid_player];st++)
 {
                       for(int ty=0;ty<4;ty++)
                      {
                      if(index_type_of_time_to_affect[ty]==1)
                      {
                      grid_times[index_grider_selected[num_grid_player]][st][ty]=
                      (time_minutes*60)+time_secondes+(0.01*time_centiemes);
                      }
                      }
 }
 }
 break;
 default: break;
 }
 index_affect_time=0;
 }

 index_do_dock=0;
 }
 else if(index_do_modify==1 && index_enable_edit_Grider==1)
 {
 switch(index_blind)
 {
 case 0:
  for(int i=1;i<513;i++)
 {
  if(Selected_Channel[i]==1)
  {
  grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i-1]=bufferSaisie[i];
  bufferSaisie[i]=0;
 }
 }
 break;
  case 1:
  for(int i=1;i<513;i++)
 {
 if(Selected_Channel[i]==1)
 {
  grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i-1]=bufferBlind[i];
  bufferBlind[i]=0;
 }
 }
 break;
 default: break;
 }
 index_do_modify=0;
 }

 else if(index_do_report==1 && index_enable_edit_Grider==1)
 {

 for (int u=1;u<513;u++)
 {
 if(bufferSequenciel[u] >= bufferFaders[u])
 {
  grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][u-1]
 =  bufferSequenciel[u];
 }
 if(bufferFaders[u]>bufferSequenciel[u])
 {
grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][u-1]=bufferFaders[u];
 }
 Selected_Channel[u]=0;
 }

 index_do_report=0;
 }

 else if(index_main_clear==1 && index_affect_time==0 && index_enable_edit_Grider==1 )
 {
 grid_to_clear=index_grider_selected[num_grid_player];

  switch(to_step_editing_mode[num_grid_player])
 {
 case 0:
 step_grid_to_clear=index_grider_step_is[num_grid_player];
 index_ask_confirm=1;
 index_clear_a_grid_step=1;
 break;
 case 1:
 index_ask_confirm=1;
 step_grid_to_clear=index_grider_step_is[num_grid_player];
 index_clear_a_grid_serie_step=1;
 index_for_grid_stepto=index_StepTo[num_grid_player];
 break;
 default: break;
 }
 }
 }
 mouse_released=1;
 }

}

 return(0);
}
