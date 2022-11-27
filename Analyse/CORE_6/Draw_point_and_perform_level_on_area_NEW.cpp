int Draw_point_and_perform_level_on_area_NEW(int pr, int position_x, int position_y)
{


    draw_centre_x[pr]=( position_x/draw_largeur_case[pr]);
    draw_centre_y[pr]=(position_y/draw_hauteur_case[pr]);


    index_case[pr]=(draw_centre_x[pr]) + (draw_centre_y[pr]*draw_preset_parameters[pr][0]) ;

    if(index_do_dock==0 && index_main_clear==0 )
    {
        dragging_draw=1;
    }

    else if(index_do_dock==1 && index_main_clear==0 )
    {
        if(index_enable_edit_Draw==1 && mouse_released==0)
        {
            draw_preset_channel_routing[pr][index_case[pr]]=atoi(numeric);
            if(draw_preset_channel_routing[pr][index_case[pr]]>512)
            {
                draw_preset_channel_routing[pr][index_case[pr]]=512;
            }
            else if(draw_preset_channel_routing[pr][index_case[pr]]<0)
            {
                draw_preset_channel_routing[pr][index_case[pr]]=0;
            }
            int idpos=0;

            switch(draw_channel_recording_mode) //4 modes: 0 solo - 1 until end of line - 2 until end of col - 3 until end of matrix
            {
            case 1://end of line
                for(int pos=index_case[pr]; pos<draw_preset_parameters[pr][0]+ ((position_y/draw_hauteur_case[pr])*draw_preset_parameters[pr][0]) ; pos++)
                {
                    draw_preset_channel_routing[pr][pos]=draw_preset_channel_routing[pr][index_case[pr]]+idpos;
                    if(draw_preset_channel_routing[pr][pos]>512)
                    {
                        draw_preset_channel_routing[pr][pos]=512;
                    }
                    idpos++;
                }
                break;
            case 2://end of col
                for(int pos=draw_centre_y[pr]; pos<draw_preset_parameters[draw_preset_selected][1] ; pos++)
                {
                    draw_preset_channel_routing[pr][index_case[pr]+(pos*draw_preset_parameters[pr][0])]=draw_preset_channel_routing[pr][index_case[pr]]+idpos;
                    if(draw_preset_channel_routing[pr][pos]>512)
                    {
                        draw_preset_channel_routing[pr][pos]=512;
                    }
                    idpos++;
                }
                break;
            case 3://all grid from position
                for(int pos=index_case[pr]; pos<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]) ; pos++)
                {
                    draw_preset_channel_routing[pr][pos]=draw_preset_channel_routing[pr][index_case[pr]]+idpos;
                    if(draw_preset_channel_routing[pr][pos]>512)
                    {
                        draw_preset_channel_routing[pr][pos]=512;
                    }
                    idpos++;
                }
                break;
            default:
                break;
            }
            reset_numeric_entry();
            index_do_dock=0;
            mouse_released=1;
        }
    }
    else if(index_do_dock==0 && index_main_clear==1 )
    {
        if(index_enable_edit_Draw==1 && mouse_released==0)
        {
            draw_preset_channel_routing[pr][index_case[pr]]=0;
            //sab 02/03/2014 unused var int idpos=0;

            switch(draw_channel_recording_mode) //4 modes: 0 solo - 1 until end of line - 2 until end of col - 3 until end of matrix
            {
            case 1://end of line
                for(int pos=index_case[pr]; pos<draw_preset_parameters[pr][0]+ ((position_y/draw_hauteur_case[pr])*draw_preset_parameters[pr][0]) ; pos++)
                {
                    draw_preset_channel_routing[pr][pos]=0;
                }
                break;
            case 2://end of col
                for(int pos=draw_centre_y[pr]; pos<draw_preset_parameters[pr][1] ; pos++)
                {
                    draw_preset_channel_routing[pr][index_case[pr]+(pos*draw_preset_parameters[pr][0])]=0;
                }
                break;
            case 3://all grid from position
                for(int pos=index_case[pr]; pos<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]) ; pos++)
                {
                    draw_preset_channel_routing[pr][pos]=0;
                }
                break;
            default:
                break;
            }
            index_main_clear=0;
            mouse_released=1;
        }
    }


    return(0);
}
