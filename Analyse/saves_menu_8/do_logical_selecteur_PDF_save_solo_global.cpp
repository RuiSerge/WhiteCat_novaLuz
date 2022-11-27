int do_logical_selecteur_PDF_save_solo_global(int xrep, int yrep)
{

    for(int u=0; u<12; u++)
    {

        if(window_focus_id==W_SAVE && mouse_x>xrep && mouse_x<xrep+10 && mouse_y>yrep+(u*15) && mouse_y<yrep+(u*15)+10)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                specify_who_to_save_PDF[u]=toggle(specify_who_to_save_PDF[u]);
                mouse_released=1;
            }
        }

        if(window_focus_id==W_SAVE && mouse_x>xrep+190 && mouse_x<xrep+200 && mouse_y>yrep+(u*15) && mouse_y<yrep+(u*15)+10)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                specify_who_to_save_PDF[u+12]=toggle(specify_who_to_save_PDF[u+12]);
                mouse_released=1;
            }
        }

    }

    return(0);
}
