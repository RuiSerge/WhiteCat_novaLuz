int prepare_move_values(int move_selected)//prepa du crossfade
{
    if(tracker_mode==0)
    {
        x_val_at_beg[move_selected]=(float)mover_params[0][0];
        y_val_at_beg[move_selected]=(float)mover_params[1][0];
    }
    if (tracker_mode==1)
    {
        x_val_at_beg[move_selected]=(float)convert_bytes_to_int(mover_params[0][0],mover_params[0][1]);
        y_val_at_beg[move_selected]=(float)convert_bytes_to_int(mover_params[1][0],mover_params[1][1]);
    }

    iris_at_beg[move_selected]=(float)mover_params[2][0];
    focus_at_beg[move_selected]=(float)mover_params[3][0];
    zoom_at_beg[move_selected]=(float)mover_params[4][0];
    if(GotoMoves[move_selected][dock_move_actual_step[move_selected]]==0)
    {
        if(index_move_forward==1)
        {
            index_move_back=0;
            if(dock_move_actual_step[move_selected]<dock_moves_contains_steps[move_selected]+1)
            {
                next_step[move_selected]=(dock_move_actual_step[move_selected]+1);
            }
            else
            {
                next_step[move_selected]=1;
            }

            if (dock_move_actual_step[move_selected]<dock_moves_contains_steps[move_selected])
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][0];
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][1];
                }
                else if(tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][0],dock_move_xy_16b[move_selected][(next_step[move_selected])][0]);
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][1],dock_move_xy_16b[move_selected][(next_step[move_selected])][1]);
                }

                iris_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][1];
                zoom_at_end[move_selected]=(float)dock_asservis[dock_move_selected][(next_step[move_selected])][2];
            }

            else if (dock_move_actual_step[move_selected]==dock_moves_contains_steps[move_selected])//pas une redite, permet de revenir en cross vers pos 0
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][1][0];//pas 1
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][1][1];//pas 1
                }
                else if(tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][1][0],dock_move_xy_16b[move_selected][1][0]);//pas 1
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][1][1],dock_move_xy_16b[move_selected][1][1]);//pas 1
                }
                iris_at_end[move_selected]=(float)dock_asservis[move_selected][1][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][1][1];
                zoom_at_end[move_selected]=(float)dock_asservis[move_selected][1][2];;
            }
        }
        if(index_move_back==1)
        {
            index_move_forward=0;
            if(dock_move_actual_step[move_selected]>1)
            {
                next_step[move_selected]=(dock_move_actual_step[move_selected]-1);
            }
            else
            {
                next_step[move_selected]=dock_moves_contains_steps[move_selected];
            }

            if (dock_move_actual_step[move_selected]>1)
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][0];
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][1];
                }
                else if(tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][0],dock_move_xy_16b[move_selected][(next_step[move_selected])][0]);
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][1],dock_move_xy_16b[move_selected][(next_step[move_selected])][1]);
                }
                iris_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][1];
                zoom_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][2];
            }
            if (dock_move_actual_step[move_selected]==1)//pas une redite, permet de revenir en cross vers pos 1
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][0];
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][1];
                }
                else if (tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][0],dock_move_xy_16b[move_selected][(dock_moves_contains_steps[move_selected])][0]);
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][1],dock_move_xy_16b[move_selected][(dock_moves_contains_steps[move_selected])][1]);
                }
                iris_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][1];
                zoom_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][2];
            }
        }
    }
    if(GotoMoves[move_selected][dock_move_actual_step[move_selected]]!=0)
    {
        next_step[move_selected]=Moves_Inpoint[(GotoMoves[move_selected][dock_move_actual_step[move_selected]])];

        if(index_move_forward==1)
        {
            index_move_back=0;
            if(tracker_mode==0)
            {
                x_val_at_end[move_selected]=(float)dock_move_xy[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][0];
                y_val_at_end[move_selected]=(float)dock_move_xy[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][1];
            }
            else if(tracker_mode==1)
            {
                x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][0],dock_move_xy_16b[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][0]);
                y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][1],dock_move_xy_16b[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][1]);
            }
            iris_at_end[move_selected]=(float)dock_asservis[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][0];
            focus_at_end[move_selected]=(float)dock_asservis[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][1];
            zoom_at_end[move_selected]=(float)dock_asservis[GotoMoves[move_selected][dock_move_actual_step[move_selected]]][next_step[move_selected]][2];
        }
        if(index_move_back==1)
        {
            index_move_forward=0;
            if(dock_move_actual_step[move_selected]>1)
            {
                next_step[move_selected]=(dock_move_actual_step[move_selected]-1);
            }
            else
            {
                next_step[move_selected]=dock_moves_contains_steps[move_selected];
            }

            if (dock_move_actual_step[move_selected]>1)
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][0];
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(next_step[move_selected])][1];
                }
                else if(tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][0],dock_move_xy_16b[move_selected][(next_step[move_selected])][0]);
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(next_step[move_selected])][1],dock_move_xy_16b[move_selected][(next_step[move_selected])][1]);
                }
                iris_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][1];
                zoom_at_end[move_selected]=(float)dock_asservis[move_selected][(next_step[move_selected])][2];
            }
            if (dock_move_actual_step[move_selected]==1)//pas une redite, permet de revenir en cross vers pos 1
            {
                if(tracker_mode==0)
                {
                    x_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][0];
                    y_val_at_end[move_selected]=(float)dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][1];
                }
                else if(tracker_mode==1)
                {
                    x_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][0],dock_move_xy_16b[move_selected][(dock_moves_contains_steps[move_selected])][0]);
                    y_val_at_end[move_selected]=(float)convert_bytes_to_int(dock_move_xy[move_selected][(dock_moves_contains_steps[move_selected])][1],dock_move_xy_16b[move_selected][(dock_moves_contains_steps[move_selected])][1]);
                }
                iris_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][0];
                focus_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][1];
                zoom_at_end[move_selected]=(float)dock_asservis[move_selected][(dock_moves_contains_steps[move_selected])][2];
            }
        }

    }



    if(x_val_at_beg[move_selected]>x_val_at_end[move_selected])
    {
        x_fract[move_selected]=(x_val_at_beg[move_selected] - x_val_at_end[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    else if (x_val_at_beg[move_selected]<x_val_at_end[move_selected])
    {
        x_fract[move_selected]=(x_val_at_end[move_selected] - x_val_at_beg[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }

    if(y_val_at_beg[move_selected]>y_val_at_end[move_selected])
    {
        y_fract[move_selected]=(y_val_at_beg[move_selected] - y_val_at_end[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    else if (y_val_at_beg[move_selected]<y_val_at_end[move_selected])
    {
        y_fract[move_selected]=( y_val_at_end[move_selected] - y_val_at_beg[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    if(iris_at_beg[move_selected]>iris_at_end[move_selected])
    {
        iris_fract[move_selected]=(iris_at_beg[move_selected] - iris_at_end[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    else if (iris_at_beg[move_selected]<iris_at_end[move_selected])
    {
        iris_fract[move_selected]=(iris_at_end[move_selected] - iris_at_beg[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    if(focus_at_beg[move_selected]>focus_at_end[move_selected])
    {
        focus_fract[move_selected]=(focus_at_beg[move_selected] - focus_at_end[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    else if (focus_at_beg[move_selected]<focus_at_end[move_selected])
    {
        focus_fract[move_selected]=(focus_at_end[move_selected] - focus_at_beg[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    if(zoom_at_beg[move_selected]>zoom_at_end[move_selected])
    {
        zoom_fract[move_selected]=(zoom_at_beg[move_selected] - zoom_at_end[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }
    else if (zoom_at_beg[move_selected]<zoom_at_end[move_selected])
    {
        zoom_fract[move_selected]=(zoom_at_end[move_selected] - zoom_at_beg[move_selected])/ dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    }


    move_start_value=ticks_move;
    move_end_value=(move_start_value + dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])]);

    if (index_spline==1)
    {
        Prepare_Cross_Spline(dock_move_selected);
    }

    return(0);
}
