int Move_AddStep(int move_selected)
{
    int temp_move_list[48][2];
    int temp_move_list_16b[48][2];
    int temp_asservis_list[48][16];
    int temp_time_list[48];
    bool temp_autostop[48];

    for(int cp=0; cp<48; cp++)
    {
        temp_move_list[cp][0]=dock_move_xy[move_selected][cp][0];
        temp_move_list[cp][1]=dock_move_xy[move_selected][cp][1];
        temp_move_list_16b[cp][0]=dock_move_xy_16b[move_selected][cp][0];
        temp_move_list_16b[cp][1]=dock_move_xy_16b[move_selected][cp][1];
        temp_time_list[cp]=dock_time[move_selected][cp];
        temp_autostop[cp]=move_auto_stop[move_selected][cp];
        for (int dd=0; dd<16; dd++)
        {
            temp_asservis_list[cp][dd]=dock_asservis[move_selected][cp][dd];//iris zoom etc
        }
    }

    if(dock_moves_contains_steps[move_selected]<48)
    {
        dock_moves_contains_steps[move_selected]+=1;
        for (int mov=dock_move_actual_step[move_selected]; mov<=dock_moves_contains_steps[move_selected]; mov++)
        {
            dock_move_xy[move_selected][mov+1][0]=temp_move_list[mov][0];
            dock_move_xy[move_selected][mov+1][1]=temp_move_list[mov][1];
            dock_move_xy_16b[move_selected][mov+1][0]=temp_move_list_16b[mov][0];
            dock_move_xy_16b[move_selected][mov+1][1]=temp_move_list_16b[mov][1];
            dock_time[move_selected][mov+1]=temp_time_list[mov];
            move_auto_stop[move_selected][mov+1]=temp_autostop[mov];
            for (int dd=0; dd<16; dd++)
            {
                dock_asservis[move_selected][mov+1][dd]=temp_asservis_list[mov][dd];//iris zoom etc
            }
        }

        dock_move_actual_step[move_selected]+=1;
        dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[0][0];
        dock_move_xy[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[1][0];
        dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[0][1];
        dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[1][1];
        dock_time[move_selected][(dock_move_actual_step[move_selected])]=(int)(Tracker_speed_is*BPS_RATE);
        dock_asservis[move_selected][(dock_move_actual_step[move_selected])][0]=mover_params[2][0];
        dock_asservis[move_selected][(dock_move_actual_step[move_selected])][1]=mover_params[3][0];
        dock_asservis[move_selected][(dock_move_actual_step[move_selected])][2]=mover_params[4][0];
        move_auto_stop[move_selected][(dock_move_actual_step[move_selected])]=0;
    }

    return(0);
}
