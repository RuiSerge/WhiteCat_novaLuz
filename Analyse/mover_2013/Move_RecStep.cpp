int Move_RecStep(int move_selected)
{

    dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[0][0];
    dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[1][0];

    if(tracker_mode==1)//16 bits
    {
        dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[0][1];
        dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[1][1];
    }
    dock_asservis[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[2][0];
    dock_asservis[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[3][0];
    dock_asservis[move_selected][(dock_move_actual_step[move_selected])][2]=mover_params[4][0];
    dock_time[move_selected][(dock_move_actual_step[move_selected])]=(int)(Tracker_speed_is*BPS_RATE);

    return(0);
}
