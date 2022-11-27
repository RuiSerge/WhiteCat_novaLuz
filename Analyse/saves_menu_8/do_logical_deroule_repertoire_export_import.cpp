void do_logical_deroule_repertoire_export_import(int xrep, int yrep, const std::string label)
{
    const std::string name_of_rep 		= label.substr (0,24);

    for (int y=0; y<8; y++)
    {


        if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+155 && mouse_y>(yrep+175+(y*20)) && mouse_y<(yrep+190+(y*20)))
        {

            if(mouse_button==1 && mouse_released==0)
            {
                importfile_selected=(y+line_import);
                if(y+line_import<127)
                {
                    sprintf(importfile_name,list_import_files[importfile_selected]);
                }
                check_import_type();
                mouse_released=1;
            }
        }

    }





    if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+205 && mouse_y>yrep+347 && mouse_y<yrep+367)
    {

        if(mouse_button==1 && mouse_released==0 && index_type==1 )
        {
            for (int tt=0; tt<24; tt++)
            {
                importfile_name[tt]=numeric[tt];
            }
            reset_numeric_entry();
            index_type=0;
            check_import_type();
            mouse_released=1;
        }
    }





    if(window_focus_id==W_SAVE && mouse_x>xrep+208 && mouse_x<xrep+232)
    {
        if(mouse_y>yrep+188 && mouse_y<yrep+212)
        {

            if(mouse_button==1)
            {
                if(line_import>0)
                {
                    line_import--;
                }
                mouse_released=1;
            }
        }
        else if(window_focus_id==W_SAVE && mouse_y>yrep+298 && mouse_y<yrep+322)
        {

            if(mouse_button==1)
            {
                if(line_import<127)
                {
                    line_import++;
                }
                mouse_released=1;
            }
        }
    }


    if(enable_export==1)
    {
        if(window_focus_id==W_SAVE && mouse_x>xrep+40 && mouse_x<xrep+110 && mouse_y>yrep+390 && mouse_y<yrep+420)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                index_do_export=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
        }
    }
    if(enable_import==1)
    {
        if(window_focus_id==W_SAVE && mouse_x>xrep+140 && mouse_x<xrep+210 && mouse_y>yrep+390 && mouse_y<yrep+420)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                index_do_import=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
        }
    }
}
