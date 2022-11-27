int do_logical_menu_curve(int XCurv, int YCurv)
{

    if(mouse_x>(XCurv+30) && mouse_x<(XCurv+30+50) && mouse_y>(YCurv+10) && mouse_y<(YCurv+10+20))
    {
        index_enable_curve_editing=toggle(index_enable_curve_editing);
        mouse_released=1;
    }


    for(int l=0; l<4; l++)
    {
        for (int curvenumber=0; curvenumber<4; curvenumber++)
        {

            if(mouse_x>(XCurv+20+(curvenumber*70)) && mouse_x<(XCurv+20+(curvenumber*70)+60) && mouse_y>(YCurv+370+(30*l)) && mouse_y<(YCurv+370+(30*l))+20)
            {

                curve_selected=curvenumber+(l*4);

                if(index_reset_curve==1 && index_enable_curve_editing==1 && index_square_curve==0 && index_fluo_curve==0 && index_preheat_curve==0)
                {
                    build_default_curve(curve_selected);
                    index_reset_curve=0;
                    mouse_released=1;
                }
                else if (index_square_curve==1 &&  index_enable_curve_editing==1 && index_reset_curve==0 && index_fluo_curve==0 && index_preheat_curve==0)
                {
                    build_square_curve(curve_selected);
                    index_square_curve=0;
                    mouse_released=1;
                }
                else if (index_preheat_curve==1 && index_enable_curve_editing==1 && index_square_curve==0 && index_reset_curve==0 && index_fluo_curve==0  )
                {
                    build_preheat_curve(curve_selected);
                    index_preheat_curve=0;
                    mouse_released=1;
                }
                else if (index_fluo_curve==1 && index_enable_curve_editing==1 && index_square_curve==0 && index_reset_curve==0 && index_preheat_curve==0)
                {
                    build_fluo_curve(curve_selected);
                    index_fluo_curve=0;
                    mouse_released=1;
                }

                else if(index_reset_curve==0 && index_square_curve==0 && index_fluo_curve==0 && index_preheat_curve==0 && mouse_released==0)//selection du curve
                {
                    load_curve_in_temp_curve();
                    mouse_released=1;
                }
            }

        }
    }


    for (int act=0; act<4; act++)
    {
        if(mouse_x>(XCurv+20+(act*70)) && mouse_x<(XCurv+20+(act*70)+60) && mouse_y>(YCurv+510) && mouse_y<(YCurv+510)+20)
        {
            switch(act)
            {
            case 0:
                if(index_reset_curve==0)
                {
                    dessafect_index_curves();
                    index_reset_curve=1;
                }
                else if (index_reset_curve==1)
                {
                    index_reset_curve=0;
                }
                break;
            case 1:
                if(index_square_curve==0)
                {
                    dessafect_index_curves();
                    index_square_curve=1;
                }
                else if (index_square_curve==1)
                {
                    index_square_curve=0;
                }
                break;
            case 2:
                if(index_preheat_curve==0)
                {
                    dessafect_index_curves();
                    index_preheat_curve=1;
                }
                else if (index_preheat_curve==1)
                {
                    index_preheat_curve=0;
                }
                break;
            case 3:
                if(index_fluo_curve==0)
                {
                    dessafect_index_curves();
                    index_fluo_curve=1;
                }
                else if (index_fluo_curve==1)
                {
                    index_fluo_curve=0;
                }
                break;
            default:
                break;
            }
            mouse_released=1;
        }

    }

    if(mouse_x>XCurv+65 && mouse_x<XCurv+65+200 && mouse_y>YCurv+560 && mouse_y<YCurv+560+30)
    {
        do_curve_affectation();
        patch_unselect_all_dimmers();
        sprintf(string_Last_Order,">>Affected Curve  %d to Dimmer", curve_selected);
        mouse_released=1;
    }

    return(0);
}
