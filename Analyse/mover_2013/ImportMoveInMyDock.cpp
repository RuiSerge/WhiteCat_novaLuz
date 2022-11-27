int ImportMoveInMyDock(int move_selected)
{
for (int cop=1;cop<dock_moves_contains_steps[move_selected]+1;cop++)
{
Move_AddStep(dock_move_selected);
dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0]=dock_move_xy[move_selected][cop][0];
dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1]=dock_move_xy[move_selected][cop][1];
dock_move_xy_16b[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0]=dock_move_xy_16b[move_selected][cop][0];
dock_move_xy_16b[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1]=dock_move_xy_16b[move_selected][cop][1];
dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0]=dock_asservis[move_selected][cop][0];
dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1]=dock_asservis[move_selected][cop][1];
dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][2]=dock_asservis[move_selected][cop][2];
dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])]=dock_time[move_selected][cop];
}
Move_refresh_xy(dock_move_selected);
return(0);
}
