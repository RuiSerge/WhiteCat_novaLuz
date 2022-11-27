int do_logical_TheGrid_matrix ( int xb, int yb,int sizecase, int num_grid_player)
{
    int grid_selected=index_grider_selected[num_grid_player];
    int gr_st_selected=index_grider_step_is[num_grid_player];

    if(index_enable_edit_Grider==1 && mouse_x>=xb && mouse_x<=xb+(grider_nb_col*sizecase) && mouse_y>=yb && mouse_y<=yb+(grider_nb_row*sizecase))
    {
        if( mouse_released==0)
        {
            if(numeric_postext==0)
            {
                if(grid_levels[index_grider_selected[num_grid_player]][gr_st_selected][position_grid_editing]==0)
                {
                    grid_levels[grid_selected][gr_st_selected][position_grid_editing]=255;
                }
                else if(grid_levels[grid_selected][gr_st_selected][position_grid_editing]==255
                        || grid_levels[index_grider_selected[num_grid_player]][gr_st_selected][position_grid_editing]>0 )
                {
                    grid_levels[grid_selected][gr_st_selected][position_grid_editing]=0;
                }
            }
            else if(numeric_postext>0)
            {
                int lev_to_attr_to_grid=0;
                lev_to_attr_to_grid=atoi(numeric);
                switch(dmx_view)
                {
                case 0://pourcent
                    if(lev_to_attr_to_grid>0)
                    {
                        grid_levels[grid_selected][gr_st_selected][position_grid_editing]=
                            (int)(((float)(lev_to_attr_to_grid) *2.55) +1);// + 1 pour arrondir le pourcentage lors de la conversion % -> dmx
                    }
                    else
                    {
                        grid_levels[grid_selected][gr_st_selected][position_grid_editing]=0;
                    }
                    break;
                case 1://dmx
                    if(lev_to_attr_to_grid>=0 && lev_to_attr_to_grid<=255)
                    {
                        grid_levels[grid_selected][gr_st_selected][position_grid_editing]=lev_to_attr_to_grid;
                    }
                    break;
                default:
                    break;
                }

            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }

    return(0);
}
