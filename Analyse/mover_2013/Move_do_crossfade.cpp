int Move_do_crossfade(int move_selected)//crossfades
{

    if (index_move_crossfade_is_on==1)
    {
        move_elapsed_time=move_current_time-move_start_value;
        if(move_current_time<move_end_value)
        {
            if(tracker_mode==0)
            {
                if(index_spline==0)
                {
                    if(x_val_at_beg[move_selected]==x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=(int)x_val_at_end[move_selected];
                    }
                    if(y_val_at_beg[move_selected]==y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=(int)y_val_at_end[move_selected];
                    }
                    if(x_val_at_beg[move_selected]>x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=(int)(x_val_at_beg[move_selected]-(x_fract[move_selected]*move_elapsed_time));
                    }
                    if(y_val_at_beg[move_selected]>y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=(int)(y_val_at_beg[move_selected]-(y_fract[move_selected]*move_elapsed_time));
                    }
                    if(x_val_at_beg[move_selected]<x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=(int)(x_val_at_beg[move_selected]+(x_fract[move_selected]*move_elapsed_time));
                    }
                    if(y_val_at_beg[move_selected]<y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=(int)(y_val_at_beg[move_selected]+(y_fract[move_selected]*move_elapsed_time));
                    }
                }
                else if(index_spline==1)
                {
                    mover_params[0][0]=my_spline_path_X[(int)(actual_spline_tick)]-(xmover_window+20);
                    mover_params[1][0]=my_spline_path_Y[(int)(actual_spline_tick)]-(ymover_window+20);
                    if(mover_params[0][0]<0)
                    {
                        mover_params[0][0]=0;
                    }
                    else if(mover_params[0][0]>255)
                    {
                        mover_params[0][0]=255;
                    }
                    if(mover_params[1][0]<0)
                    {
                        mover_params[1][0]=0;
                    }
                    else if(mover_params[1][0]>255)
                    {
                        mover_params[1][0]=255;
                    }
                }
            }//8 bits end

            if(tracker_mode==1)
            {
                if(index_spline==0)
                {
                    if(x_val_at_beg[move_selected]==x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=((int)x_val_at_end[move_selected])>>8;
                        mover_params[0][1]=((int)x_val_at_end[move_selected])& 0X00FF;
                    }
                    if(y_val_at_beg[move_selected]==y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=((int)y_val_at_end[move_selected])>>8;
                        mover_params[1][1]=(((int)y_val_at_end[move_selected]))& 0X00FF;
                    }
                    if(x_val_at_beg[move_selected]>x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=((int)(x_val_at_beg[move_selected]-(x_fract[move_selected]*move_elapsed_time)))>>8 ;
                        mover_params[0][1]=((int)(x_val_at_beg[move_selected]-(x_fract[move_selected]*move_elapsed_time)))& 0X00FF;
                    }
                    if(y_val_at_beg[move_selected]>y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=((int)(y_val_at_beg[move_selected]-(y_fract[move_selected]*move_elapsed_time)))>>8;
                        mover_params[1][1]=((int)(y_val_at_beg[move_selected]-(y_fract[move_selected]*move_elapsed_time)))& 0X00FF;
                    }
                    if(x_val_at_beg[move_selected]<x_val_at_end[move_selected])
                    {
                        mover_params[0][0]=((int)(x_val_at_beg[move_selected]+(x_fract[move_selected]*move_elapsed_time)))>>8;
                        mover_params[0][1]=((int)(x_val_at_beg[move_selected]+(x_fract[move_selected]*move_elapsed_time)))& 0X00FF;
                    }
                    if(y_val_at_beg[move_selected]<y_val_at_end[move_selected])
                    {
                        mover_params[1][0]=((int)(y_val_at_beg[move_selected]+(y_fract[move_selected]*move_elapsed_time)))>>8;
                        mover_params[1][1]=((int)(y_val_at_beg[move_selected]+(y_fract[move_selected]*move_elapsed_time)))& 0X00FF;
                    }
                }
                else if(index_spline==1)
                {
                    mover_params[0][0]=my_spline_path_X[(int)(actual_spline_tick)]-(xmover_window+20);
                    mover_params[1][0]=my_spline_path_Y[(int)(actual_spline_tick)]-(ymover_window+20);
                    if(mover_params[0][0]<0)
                    {
                        mover_params[0][0]=0;
                    }
                    else if(mover_params[0][0]>255)
                    {
                        mover_params[0][0]=255;
                    }
                    if(mover_params[1][0]<0)
                    {
                        mover_params[1][0]=0;
                    }
                    else if(mover_params[1][0]>255)
                    {
                        mover_params[1][0]=255;
                    }
                }
            }//16 bits end




            if(iris_at_beg[move_selected]==iris_at_end[move_selected])
            {
                mover_params[2][0]=(int)iris_at_end[move_selected];
            }
            if(focus_at_beg[move_selected]==focus_at_end[move_selected])
            {
                mover_params[3][0]=(int)focus_at_end[move_selected];
            }
            if(zoom_at_beg[move_selected]==zoom_at_end[move_selected])
            {
                mover_params[4][0]=(int)zoom_at_end[move_selected];
            }
            if(iris_at_beg[move_selected]>iris_at_end[move_selected])
            {
                mover_params[2][0]=(int)(iris_at_beg[move_selected]-(iris_fract[move_selected]*move_elapsed_time));
            }
            if(focus_at_beg[move_selected]>focus_at_end[move_selected])
            {
                mover_params[3][0]=(int)(focus_at_beg[move_selected]-(focus_fract[move_selected]*move_elapsed_time));
            }
            if(zoom_at_beg[move_selected]>zoom_at_end[move_selected])
            {
                mover_params[4][0]=(int)(zoom_at_beg[move_selected]-(zoom_fract[move_selected]*move_elapsed_time));
            }
            if(iris_at_beg[move_selected]<iris_at_end[move_selected])
            {
                mover_params[2][0]=(int)(iris_at_beg[move_selected]+(iris_fract[move_selected]*move_elapsed_time));
            }
            if(focus_at_beg[move_selected]<focus_at_end[move_selected])
            {
                mover_params[3][0]=(int)(focus_at_beg[move_selected]+(focus_fract[move_selected]*move_elapsed_time));
            }
            if(zoom_at_beg[move_selected]<zoom_at_end[move_selected])
            {
                mover_params[4][0]=(int)(zoom_at_beg[move_selected]+(zoom_fract[move_selected]*move_elapsed_time));
            }
        }

        if(move_current_time>move_end_value)
        {
            if(GotoMoves[move_selected][dock_move_actual_step[move_selected]]!=0 && index_move_back==0)
            {
                dock_move_selected=GotoMoves[move_selected][dock_move_actual_step[move_selected]];
                move_selected=dock_move_selected;
                dock_move_actual_step[move_selected]=Moves_Inpoint[move_selected]-1;
                if(dock_move_actual_step[move_selected]<0)
                {
                    dock_move_actual_step[move_selected]=dock_moves_contains_steps[move_selected];
                }
            }
            if(tracker_mode==0)//not spline
            {
                mover_params[0][0]=(int)x_val_at_end[move_selected];
                if (mover_params[0][0]<0)
                {
                    mover_params[0][0]=0;
                }
                else if (mover_params[0][0] >255)
                {
                    mover_params[0][0]=255;
                }
                mover_params[1][0]=(int) y_val_at_end[move_selected];
                if (mover_params[1][0]<0)
                {
                    mover_params[1][0]=0;
                }
                else if (mover_params[1][0] >255)
                {
                    mover_params[1][0]=255;
                }
                if (mover_params[2][0]<0)
                {
                    mover_params[2][0]=0;
                }
                else if (mover_params[2][0] >255)
                {
                    mover_params[2][0]=255;
                }
                if (mover_params[3][0]<0)
                {
                    mover_params[3][0]=0;
                }
                else if (mover_params[3][0] >255)
                {
                    mover_params[3][0]=255;
                }
                if (mover_params[4][0]<0)
                {
                    mover_params[4][0]=0;
                }
                else if (mover_params[4][0] >255)
                {
                    mover_params[4][0]=255;
                }
            }
            else if(tracker_mode==1)//spline
            {
                mover_params[0][0]=((int)x_val_at_end[move_selected])>>8 ;

                if (mover_params[0][0]<0)
                {
                    mover_params[0][0]=0;
                }
                else if (mover_params[0][0] >255)
                {
                    mover_params[0][0]=255;
                }

                mover_params[1][0]=((int) y_val_at_end[move_selected])>>8;

                if (mover_params[1][0]<0)
                {
                    mover_params[1][0]=0;
                }
                else if (mover_params[1][0] >255)
                {
                    mover_params[1][0]=255;
                }

                mover_params[0][1]=((int)x_val_at_end[move_selected])& 0X00FF;
                mover_params[1][1]=((int)y_val_at_end[move_selected])& 0X00FF;
                if (mover_params[2][0]<0)
                {
                    mover_params[2][0]=0;
                }
                else if (mover_params[2][0] >255)
                {
                    mover_params[2][0]=255;
                }
                if (mover_params[3][0]<0)
                {
                    mover_params[3][0]=0;
                }
                else if (mover_params[3][0] >255)
                {
                    mover_params[3][0]=255;
                }
                if (mover_params[4][0]<0)
                {
                    mover_params[4][0]=0;
                }
                else if (mover_params[4][0] >255)
                {
                    mover_params[4][0]=255;
                }
            }

            if(index_move_forward==1)
            {
                Move_StepForward(dock_move_selected);
            }
            else if(index_move_back==1)
            {
                Move_StepBackward(dock_move_selected);
            }
            if(index_cycle==0)
            {
                index_move_crossfade_is_on=0;
                if(index_move_forward==1)
                {
                    index_move_forward=0;
                }
                else if(index_move_back==1)
                {
                    index_move_back=0;
                }
            }
            if(index_cycle==1)
            {
                prepare_move_values(dock_move_selected);

            }


        }

    }

    return(0);
}
