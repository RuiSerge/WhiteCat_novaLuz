int do_logical_selecteur_binary_save_solo_global(int xrep, int yrep)
{

    if(window_focus_id==W_SAVE && mouse_x>xrep+170 && mouse_x<xrep+240 && mouse_y>yrep-35 && mouse_y<yrep-15)
    {

        if(mouse_button==1 && mouse_released==0)
        {

            index_save_global_is=toggle(index_save_global_is);
            if(index_save_global_is==1)
            {
                set_all_saves_indexes_at(1);
            }
            else // si mode choice, on efface tous les indexes
            {
                set_all_saves_indexes_at(0);
            }
            mouse_released=1;
        }
    }


    for(int u=0; u<12; u++)
    {
        if(window_focus_id==W_SAVE && mouse_x>xrep && mouse_x<xrep+50 && mouse_y>yrep+(u*15) && mouse_y<yrep+(u*15)+15)
        {
            {
                if(mouse_button==1 && mouse_released==0)
                {
                    index_save_global_is=0;
                    specify_who_to_save_load[u]=toggle(specify_who_to_save_load[u]);
                    mouse_released=1;
                }
            }
        }



        if(window_focus_id==W_SAVE && mouse_x>xrep+110 && mouse_x<xrep+120 && mouse_y>yrep+(u*15) && mouse_y<yrep+(u*15)+10)
        {
            {
                if(mouse_button==1 && mouse_released==0)
                {
                    index_save_global_is=0;
                    specify_who_to_save_load[u+12]=toggle(specify_who_to_save_load[u+12]);
                    mouse_released=1;
                }
            }
        }



        if(window_focus_id==W_SAVE && mouse_x>xrep+240 && mouse_x<xrep+250 && mouse_y>yrep+(u*15) && mouse_y<yrep+(u*15)+10)
        {
            {
                if(mouse_button==1 && mouse_released==0)
                {
                    index_save_global_is=0;
                    specify_who_to_save_load[u+24]=toggle(specify_who_to_save_load[u+24]);
                    mouse_released=1;
                }
            }
        }

    }

    return(0);
}
