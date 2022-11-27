int do_grid()
{
    int gr_grille=0;
    int gr_step=0;

    int gr_grille_pr=0;
    int gr_step_pr=0;

    for(int grid_pl=0; grid_pl<core_user_define_nb_gridplayers; grid_pl++)
    {
        gr_grille=index_grider_selected[grid_pl];
        gr_step=index_grider_step_is[grid_pl];

        gr_grille_pr=grid_in_preset[grid_pl][0];
        gr_step_pr=grid_in_preset[grid_pl][1];

        for(int cg=0; cg<512; cg++)
        {

            if(grid_levels[gr_grille][gr_step][cg]>grid_levels[gr_grille_pr][gr_step_pr][cg])
            {
                buffer_gridder[grid_pl][cg]=
                    grid_levels[gr_grille_pr][gr_step_pr][cg]
                    + (unsigned char)((((float)(grid_levels[gr_grille][gr_step][cg]-grid_levels[gr_grille_pr][gr_step_pr][cg])/255)*grid_niveauX1[grid_pl])) ;
            }
            if(grid_levels[gr_grille][gr_step][cg]<grid_levels[gr_grille_pr][gr_step_pr][cg])
            {
                buffer_gridder[grid_pl][cg]=
                    grid_levels[gr_grille][gr_step][cg]
                    + (unsigned char)((((float)(grid_levels[gr_grille_pr][gr_step_pr][cg]-grid_levels[gr_grille][gr_step][cg])/255)*grid_niveauX2[grid_pl])) ;
            }
            if(grid_levels[gr_grille][gr_step][cg]==grid_levels[gr_grille_pr][gr_step_pr][cg])
            {
                buffer_gridder[grid_pl][cg]=grid_levels[gr_grille_pr][gr_step_pr][cg];
            }
        }




        switch(grider_is_playing[grid_pl])
        {
        case 0:
            gridder_prepare_cross(grid_pl,gr_grille,gr_step);
            break;
        case 1:
            if(actual_time>(grid_crossfade_start_time[grid_pl]+grid_delay_out[grid_pl]))
            {
                grid_floatX1[grid_pl]-=grid_fraction_X1_out[grid_pl];
                if(grid_floatX1[grid_pl]<0.0)
                {
                    grid_floatX1[grid_pl]=0.0;
                }
                grid_niveauX1[grid_pl]=(int)grid_floatX1[grid_pl];
            }
            if(actual_time>(grid_crossfade_start_time[grid_pl]+grid_delay_in[grid_pl]))
            {
                grid_floatX2[grid_pl]+=grid_fraction_X2_in[grid_pl];
                if(grid_floatX2[grid_pl]>255.0)
                {
                    grid_floatX2[grid_pl]=255.0;
                }
                grid_niveauX2[grid_pl]=(int)grid_floatX2[grid_pl];
            }
            if(grid_niveauX1[grid_pl]==0 && grid_niveauX2[grid_pl]==255)
            {
                index_grider_selected[grid_pl]=grid_in_preset[grid_pl][0];
                index_grider_step_is[grid_pl]=grid_in_preset[grid_pl][1];
                grid_delay_in[grid_pl]=0;
                grid_delay_out[grid_pl]=0;

                if(grid_in_preset[grid_pl][1]>1023)
                {
                    index_grider_step_is[grid_pl]=1023;
                }
                gridder_prepare_cross(grid_pl,index_grider_selected[grid_pl],index_grider_step_is[grid_pl]);
                grid_niveauX1[grid_pl]=255;
                grid_niveauX2[grid_pl]=0;
                grid_floatX1[grid_pl]=grid_niveauX1[grid_pl];
                grid_floatX2[grid_pl]=grid_niveauX2[grid_pl];

                if((grider_stoplay_mode[grid_pl]==1 && grid_stoplay[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]==1)
                        ||grider_autostopmode[grid_pl]==1)
                {
                    grider_is_playing[grid_pl]=0;
                }
                else//start time recalcul
                {
                    grid_crossfade_start_time[grid_pl]=actual_time;
                }
                if(grider_seekto_mode[grid_pl]==1 && grid_seekpos[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]>0)//seek position
                {
                    index_grider_seek_pos[grid_pl]=grid_seekpos[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]];
                }
                if( grider_count_mode[grid_pl]==1 &&  grid_count[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]>0)
                {
                    grid_counted_times[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]++;
                    sprintf( string_grid_count[grid_pl],"%d/%d from S.%d",  grid_counted_times[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]],grid_count[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]], index_grider_step_is[grid_pl]+1);
                    if(grid_counted_times[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]>grid_count[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]])
                    {
                        strcpy( string_grid_count[grid_pl],"");

                        grid_counted_times[index_grider_selected[grid_pl]][index_grider_step_is[grid_pl]]=0;
                    }
                }

            }
            break;
        default:
            break;
        }
    }

    return(0);
}
