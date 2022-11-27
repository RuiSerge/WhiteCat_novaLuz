int Move_refresh_xy(int move_selected)
{


 mover_params[0][0]=dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][0];
 mover_params[1][0]=dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][1];

if (tracker_mode==1)
 {
 mover_params[0][1]=dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][0] ;
 mover_params[1][1]=dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][1] ;
 }
 mover_params[2][0]=dock_asservis[move_selected][(dock_move_actual_step[move_selected])][0];
 mover_params[3][0]=dock_asservis[move_selected][(dock_move_actual_step[move_selected])][1];
 mover_params[4][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][2];

 Tracker_speedlevel=(int)(((float)dock_time[move_selected][(dock_move_actual_step[move_selected])]/BPS_RATE)*8);

  if (move_auto_stop[move_selected][dock_move_actual_step[move_selected]]==1)
  {index_cycle=0;}

 return(0);
}
