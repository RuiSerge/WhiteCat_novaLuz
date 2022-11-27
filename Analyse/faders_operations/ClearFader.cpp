int ClearFader(int fad)
{

for(int p=0;p<6;p++)
  {
  ClearDock(fader_selected_for_record,p);
  FaderDirectChan[fad][p]=0;
  }
 //mise a plat niveau
 Fader[fad]=0;
 Fader_dampered[fad].fix_all_damper_state_value(Fader[fad]);
 Fader_dampered[fad].set_target_val(Fader[fad]);
 Fader_dampered[fad].set_damper_decay(1.0);
 Fader_dampered[fad].set_damper_dt(0.1);
 FaderLocked[fad]=0;
 LockFader_is_FullLevel[fad]=0;
 StateOfFaderBeforeLock[fad]=0;
 LevelFaderBeforeFlash[fad]=0;
 LevelStopPos[fad]=0;
 PreviousLevelStopPos[fad]=0;
 ActionnateStopOn[fad]=0;
 midi_levels[fad]=0;
 if(midi_send_out[fad]==1)
 {
 index_send_midi_out[fad]=1;
 }
 //dock 0 selected
 DockIsSelected[fad][0]=1;
 Unselect_other_docks(fad,0);
 //lfos
 lfo_speed[fad]=64;
 midi_levels[196+fad]=64;
 if(midi_send_out[196+fad]==1)
 {
 index_send_midi_out[196+fad]=1;
 }
 //les index_lfos
 lfo_mode_is[fad]=0;
 lfo_cycle_is_on[fad]=0;
 lfo_do_next_step[fad][0]=0;
 lfo_do_next_step[fad][1]=0;
 lfo_cycle_steps[fad]=0;
 //direct chan
 beforeloop_for_directch[fad]=0;
 //courbe
 FaderCurves[fad]=0;
 return(0);
}
