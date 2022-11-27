int store_state_of_fader_before_bang(int fader_num)
{
remember_state_of_banged_fader[fader_num][0]=FaderLocked[fader_num];//lock state is
remember_state_of_banged_fader[fader_num][1]=(int)Fader[fader_num];//level is
remember_state_of_banged_fader[fader_num][2]=detect_dock_used(fader_num);//dock is
remember_state_of_banged_fader[fader_num][3]=(int)lfo_speed[fader_num];//lfo level is
remember_state_of_banged_fader[fader_num][4]=is_dock_for_lfo_selected[fader_num][0];//loop dk 0 is
remember_state_of_banged_fader[fader_num][5]=is_dock_for_lfo_selected[fader_num][1];//loop dk 1 is
remember_state_of_banged_fader[fader_num][6]=is_dock_for_lfo_selected[fader_num][2];//loop dk 2 is
remember_state_of_banged_fader[fader_num][7]=is_dock_for_lfo_selected[fader_num][3];//loop dk 3 is
remember_state_of_banged_fader[fader_num][8]=is_dock_for_lfo_selected[fader_num][4];//loop dk 4 is
remember_state_of_banged_fader[fader_num][9]=is_dock_for_lfo_selected[fader_num][5];//loop dk 5 is
remember_state_of_banged_fader[fader_num][10]= lfo_mode_is[fader_num];//0 nothing 1 up 2 down
remember_state_of_banged_fader[fader_num][11]= lfo_cycle_is_on[fader_num];//saw
remember_state_of_banged_fader[fader_num][12]= lfo_cycle_steps[fader_num];//up down
remember_state_of_banged_fader[fader_num][13]=lfo_do_next_step[fader_num][0];//prev dock
remember_state_of_banged_fader[fader_num][14]=lfo_do_next_step[fader_num][1];//next dock
remember_state_of_banged_fader[fader_num][15]=FaderCurves[fader_num];//curves
return(0);
}
