int TimeShift(int move_selected)
{

    int total_deplacement=0;
    int report_temp_deplacement_x=0;
    int report_temp_deplacement_y=0;
    int amplitude[48];
    int last_amplitude=0;//(mvt de loop)
    float fraction_pixel_temps=0;
    for (int o=1; o<dock_moves_contains_steps[move_selected]; o++)
    {
        report_temp_deplacement_x=dock_move_xy[move_selected][o][0]-dock_move_xy[move_selected][o+1][0];
        report_temp_deplacement_y=dock_move_xy[move_selected][o][1]-dock_move_xy[move_selected][o+1][1];
        if(report_temp_deplacement_x<0)
        {
            report_temp_deplacement_x=-(report_temp_deplacement_x);
        }
        if(report_temp_deplacement_y<0)
        {
            report_temp_deplacement_y=-(report_temp_deplacement_y);
        }
        if(report_temp_deplacement_x>report_temp_deplacement_y)
        {
            amplitude[o]=report_temp_deplacement_x;
        }
        else
        {
            amplitude[o]=report_temp_deplacement_y;
        }
        total_deplacement+=amplitude[o];
    }
    report_temp_deplacement_x=dock_move_xy[move_selected][dock_moves_contains_steps[move_selected]][0]-dock_move_xy[move_selected][1][0];
    report_temp_deplacement_y=dock_move_xy[move_selected][dock_moves_contains_steps[move_selected]][1]-dock_move_xy[move_selected][1][1];
    if(report_temp_deplacement_x<0)
    {
        report_temp_deplacement_x=-(report_temp_deplacement_x);
    }
    if(report_temp_deplacement_y<0)
    {
        report_temp_deplacement_y=-(report_temp_deplacement_y);
    }
    if(report_temp_deplacement_x>report_temp_deplacement_y)
    {
        last_amplitude=report_temp_deplacement_x;
    }
    else
    {
        last_amplitude=report_temp_deplacement_y;
    }
    total_deplacement+=last_amplitude;

    Tracker_speed_is=((float)Tracker_speedlevel)/8; // secondes
    fraction_pixel_temps=(Tracker_speed_is*BPS_RATE)/total_deplacement;

    for (int r=1; r<dock_moves_contains_steps[move_selected]; r++)
    {
        dock_time[move_selected][r]=(int)(amplitude[r]*fraction_pixel_temps);
    }
    dock_time[move_selected][dock_moves_contains_steps[move_selected]]=(int)(last_amplitude*fraction_pixel_temps);

    sprintf(string_time_shift,"total_pixel_shift %d",total_deplacement);
    index_time_shift=0;
    Tracker_speedlevel=(int)(((float)dock_time[move_selected][dock_move_actual_step[move_selected]]/BPS_RATE)*8);

    return(0);
}
