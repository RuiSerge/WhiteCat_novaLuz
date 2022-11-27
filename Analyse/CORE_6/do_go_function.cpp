int do_go_function()
{

    if(index_go==0)
    {
        index_go=1;
        index_go_back=0;
        crossfade_start_time=actual_time;
        index_pause=0;
        if(show_gridplayer_in_seq==1)
        {
            grid_in_preset[0][0]=index_grider_selected[0];
            grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_preset]-1;
            if(grider_is_playing[0]==0 && set_from_seq_gridplayer1_next_step[position_preset]!=-1
                    && set_from_seq_gridplayer1_next_step[position_preset]!=index_grider_step_is[0])
            {
                gridder_prepare_cross(0,index_grider_selected[0],set_from_seq_gridplayer1_next_step[position_preset]-1);
                grider_is_playing[0]=1;
                grid_crossfade_start_time[0]=actual_time;
            }
        }
    }

    else if(index_go==1 && index_pause==0)
    {
        index_pause=1;
        if(crossfade_time_delay_in>(actual_time-crossfade_start_time))
        {
            crossfade_time_delay_in-=actual_time-crossfade_start_time;
        };
        if(crossfade_time_delay_out>(actual_time-crossfade_start_time))
        {
            crossfade_time_delay_out-=actual_time-crossfade_start_time;
        };
        if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1)
        {
            grid_in_preset[0][0]=index_grider_selected[0];
            grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_preset]-1;
            if(grider_is_playing[0]==1 )
            {
                grider_is_playing[0]=0;
                if(grid_delay_in[0]>(actual_time-grid_crossfade_start_time[0]))
                {
                    grid_delay_in[0]-=actual_time-grid_crossfade_start_time[0];
                };
                if(grid_delay_out[0]>(actual_time-grid_crossfade_start_time[0]))
                {
                    grid_delay_out[0]-=actual_time-grid_crossfade_start_time[0];
                }
            }
        }
    }
    else if(index_go==1 && index_pause==1)
    {
        crossfade_start_time=actual_time;
        index_pause=0;
        if(crossfade_time_delay_in>(actual_time-crossfade_start_time))
        {
            crossfade_time_delay_in-=actual_time-crossfade_start_time;
        }
        if(crossfade_time_delay_in<0)
        {
            crossfade_time_delay_in=0;
        }
        if(crossfade_time_delay_out>(actual_time-crossfade_start_time))
        {
            crossfade_time_delay_out-=actual_time-crossfade_start_time;
        };
        if(crossfade_time_delay_out<0)
        {
            crossfade_time_delay_out=0;
        }
        if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 && grider_is_playing[0]==0)
        {
            grid_in_preset[0][0]=index_grider_selected[0];
            grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_preset]-1;
            gridder_prepare_cross(0,index_grider_selected[0],set_from_seq_gridplayer1_next_step[position_preset]-1);
            grider_is_playing[0]=1;
            if(grid_delay_in[0]>(actual_time-grid_crossfade_start_time[0]))
            {
                grid_delay_in[0]-=actual_time-grid_crossfade_start_time[0];
            }
            if(grid_delay_in[0]<0)
            {
                grid_delay_in[0]=0;
            }
            if(grid_delay_out[0]>(actual_time-grid_crossfade_start_time[0]))
            {
                grid_delay_out[0]-=actual_time-grid_crossfade_start_time[0];
            };
            if(grid_delay_out[0]<0)
            {
                grid_delay_out[0]=0;
            }
        }
    }
    return(0);
}
