int restore_state_of_fader_before_bang(int fader_num)
{
FaderLocked[fader_num]=remember_state_of_banged_fader[fader_num][0];//lock state is
Fader[fader_num]=remember_state_of_banged_fader[fader_num][1];//level is
for(int io=0;io<core_user_define_nb_docks;io++)
{
DockIsSelected[fader_num][io]=0;
}
DockIsSelected[fader_num][remember_state_of_banged_fader[fader_num][2]]=1;//dock is
lfo_speed[fader_num]=remember_state_of_banged_fader[fader_num][3];//lfo level is
is_dock_for_lfo_selected[fader_num][0]=remember_state_of_banged_fader[fader_num][4];//loop dk 0 is
is_dock_for_lfo_selected[fader_num][1]=remember_state_of_banged_fader[fader_num][5];//loop dk 1 is
is_dock_for_lfo_selected[fader_num][2]=remember_state_of_banged_fader[fader_num][6];//loop dk 2 is
is_dock_for_lfo_selected[fader_num][3]=remember_state_of_banged_fader[fader_num][7];//loop dk 3 is
is_dock_for_lfo_selected[fader_num][4]=remember_state_of_banged_fader[fader_num][8];//loop dk 4 is
is_dock_for_lfo_selected[fader_num][5]=remember_state_of_banged_fader[fader_num][9];//loop dk 5 is
lfo_mode_is[fader_num]=remember_state_of_banged_fader[fader_num][10];//0 nothing 1 up 2 down
lfo_cycle_is_on[fader_num]=remember_state_of_banged_fader[fader_num][11];//saw
lfo_cycle_steps[fader_num]=remember_state_of_banged_fader[fader_num][12];//up down
lfo_do_next_step[fader_num][0]=remember_state_of_banged_fader[fader_num][13];//prev dock
lfo_do_next_step[fader_num][1]=remember_state_of_banged_fader[fader_num][14];//next dock
FaderCurves[fader_num]=remember_state_of_banged_fader[fader_num][15];//curves
return(0);
}
