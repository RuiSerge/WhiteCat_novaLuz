int gridder_prepare_cross(int grid_pl, int gr_actual_grid, int gr_actual_step)
{

    switch(grider_goto_mode[grid_pl])
    {
    case 0:
        if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 && grid_pl==0)
        {
            grid_in_preset[grid_pl][0]=gr_actual_grid ;
            grid_in_preset[grid_pl][1]=set_from_seq_gridplayer1_next_step[position_preset];
        }
        else
        {
            grid_in_preset[grid_pl][0]=gr_actual_grid ;
            grid_in_preset[grid_pl][1]=gr_actual_step+1;
        }
        break;
    case 1:
        if(grid_goto[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][0]>=0
                && grid_goto[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][1]>=0)//0 = step 1. désafecté val=-1
        {

            if( grider_count_mode[grid_pl]==1 &&  grid_count[gr_actual_grid][gr_actual_step]>0
                    && grid_counted_times[gr_actual_grid][gr_actual_step]>grid_count[gr_actual_grid][gr_actual_step]-1)
            {
                grid_in_preset[grid_pl][0]=gr_actual_grid ;
                grid_in_preset[grid_pl][1]=gr_actual_step+1;
            }
            else
            {
                grid_in_preset[grid_pl][0]=grid_goto[gr_actual_grid][gr_actual_step][0] ;
                grid_in_preset[grid_pl][1]=grid_goto[gr_actual_grid][gr_actual_step][1] ;
            }

        }
        else
        {
            if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 && grid_pl==0 && index_go==0 && index_go_back==0 && index_pause==0)
            {
                grid_in_preset[grid_pl][0]=gr_actual_grid ;
                grid_in_preset[grid_pl][1]=set_from_seq_gridplayer1_next_step[position_preset];
            }
            else
            {
                grid_in_preset[grid_pl][0]=gr_actual_grid ;
                grid_in_preset[grid_pl][1]=gr_actual_step+1 ;
                if(grid_in_preset[grid_pl][1]>1023)
                {
                    grid_in_preset[grid_pl][1]=1023;
                }
            }
        }
        break;
    default:
        break;
    }

    float in_speed=0.0,out_speed=0.0, in_speed_preset=0.0, out_speed_preset=0.0;
    float delay_in_speed=0.0, delay_out_speed=0.0, delay_in_speed_preset=0.0, delay_out_speed_preset=0.0;
    char the_in[12];
    char the_out[12];

    char the_delay_in[12];
    char the_delay_out[12];

    char the_in_preset[12];
    char the_out_preset[12];

    char the_delay_in_preset[12];
    char the_delay_out_preset[12];
    if(grid_crossfade_speed[grid_pl]<64)
    {
        grid_fraction_X2_in[grid_pl]= 255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1]*(((float)BPS_RATE)*(64.0/grid_crossfade_speed[grid_pl])));
        grid_fraction_X1_out[grid_pl]=  255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3]*(((float)BPS_RATE)*(64.0/grid_crossfade_speed[grid_pl])));
        in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][1]*(64.0/grid_crossfade_speed[grid_pl]);
        out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][3]*(64.0/grid_crossfade_speed[grid_pl]);
        delay_in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][0]*(64.0/grid_crossfade_speed[grid_pl]);
        delay_out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][2]*(64.0/grid_crossfade_speed[grid_pl]);

        in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1]*(64.0/grid_crossfade_speed[grid_pl]);
        out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3]*(64.0/grid_crossfade_speed[grid_pl]);
        delay_in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][0]*(64.0/grid_crossfade_speed[grid_pl]);
        delay_out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][2]*(64.0/grid_crossfade_speed[grid_pl]);
    }
    else if(grid_crossfade_speed[grid_pl]==64)
    {
        grid_fraction_X2_in[grid_pl]= 255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1]*BPS_RATE);
        grid_fraction_X1_out[grid_pl]= 255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3]*BPS_RATE);
        in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][1];
        out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][3];
        delay_in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][0];
        delay_out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][2];

        in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1];
        out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3];
        delay_in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][0];
        delay_out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][2];
    }
    else if(grid_crossfade_speed[grid_pl]>64)
    {
        float correcteur=(127.0-grid_crossfade_speed[grid_pl])/(grid_crossfade_speed[grid_pl]/3);
        grid_fraction_X2_in[grid_pl]= 255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1]*((((float)(BPS_RATE))*correcteur)/(grid_crossfade_speed[grid_pl]-62))); //-62 evite un passage de temps pas bon, cf curseur
        grid_fraction_X1_out[grid_pl]=  255.0/ (grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3]*((((float)(BPS_RATE))*correcteur)/(grid_crossfade_speed[grid_pl]-62)));
        in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][1]*(correcteur/(grid_crossfade_speed[grid_pl]-62)) ;
        out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][3]*(correcteur/(grid_crossfade_speed[grid_pl]-62));
        delay_in_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][0]*(correcteur/(grid_crossfade_speed[grid_pl]-62)) ;
        delay_out_speed=grid_times[(index_grider_selected[grid_pl])][(index_grider_step_is[grid_pl])][2]*(correcteur/(grid_crossfade_speed[grid_pl]-62));

        in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][1]*(correcteur/(grid_crossfade_speed[grid_pl]-62)) ;
        out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][3]*(correcteur/(grid_crossfade_speed[grid_pl]-62));
        delay_in_speed_preset=grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][0]*(correcteur/(grid_crossfade_speed[grid_pl]-62)) ;
        delay_out_speed_preset= grid_times[(grid_in_preset[grid_pl][0])][(grid_in_preset[grid_pl][1])][2]*(correcteur/(grid_crossfade_speed[grid_pl]-62));

    }


    affichage_time_format(in_speed);//in
    sprintf(the_in,string_conversion_timeis);
    affichage_time_format(out_speed);//out
    sprintf(the_out,string_conversion_timeis);
    affichage_time_format(delay_in_speed);//din
    sprintf(the_delay_in,string_conversion_timeis);
    affichage_time_format(delay_out_speed);//dout
    sprintf(the_delay_out,string_conversion_timeis);


    if(delay_in_speed>0 && delay_out_speed>0)
    {
        sprintf(string_time_in_grider[grid_pl],"%s- IN:%s / %s -OUT:%s ",the_delay_in,the_in,the_delay_out,the_out);
    }
    else if (delay_in_speed>0 && delay_out_speed==0)
    {
        sprintf(string_time_in_grider[grid_pl],"%s- IN:%s / OUT:%s ",the_delay_in,the_in,the_out);
    }
    else if (delay_in_speed==0 && delay_out_speed>0)
    {
        sprintf(string_time_in_grider[grid_pl],"IN:%s / %s -OUT:%s ",the_in,the_delay_out,the_out);
    }
    else
    {
        sprintf(string_time_in_grider[grid_pl],"IN:%s / OUT:%s ",the_in,the_out);
    }


    affichage_time_format(in_speed_preset);//in
    sprintf(the_in_preset,string_conversion_timeis);
    affichage_time_format(out_speed_preset);//out
    sprintf(the_out_preset,string_conversion_timeis);
    affichage_time_format(delay_in_speed_preset);//din
    sprintf(the_delay_in_preset,string_conversion_timeis);
    affichage_time_format(delay_out_speed_preset);//dout
    sprintf(the_delay_out_preset,string_conversion_timeis);

    if(delay_in_speed_preset>0 && delay_out_speed_preset>0)
    {
        sprintf(string_time_in_grider_next_step[grid_pl],"%s- IN:%s / %s -OUT:%s ",the_delay_in_preset,the_in_preset,the_delay_out_preset,the_out_preset);
    }
    else if (delay_in_speed_preset>0 && delay_out_speed_preset==0)
    {
        sprintf(string_time_in_grider_next_step[grid_pl],"%s- IN:%s / OUT:%s ",the_delay_in_preset,the_in_preset,the_out_preset);
    }
    else if (delay_in_speed_preset==0 && delay_out_speed_preset>0)
    {
        sprintf(string_time_in_grider_next_step[grid_pl],"IN:%s / %s -OUT:%s ",the_in_preset,the_delay_out_preset,the_out_preset);
    }
    else
    {
        sprintf(string_time_in_grider_next_step[grid_pl],"IN:%s / OUT:%s ",the_in_preset,the_out_preset);
    }

    grid_delay_in[grid_pl]=int(delay_in_speed_preset*BPS_RATE);
    grid_delay_out[grid_pl]=int(delay_out_speed_preset*BPS_RATE);



    sprintf( string_next_step_to[grid_pl],"%d - %d ", grid_in_preset[grid_pl][0]+1,grid_in_preset[grid_pl][1]+1);
    return(0);
}
