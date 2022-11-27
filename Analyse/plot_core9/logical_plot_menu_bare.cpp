int logical_plot_menu_bare(int plotx,int ploty)
{

    if(window_focus_id==W_PLOT && mouse_button==1 && mouse_released==0 && index_click_inside_relativ_xy==0 && index_click_inside_plot==0)
    {
        if(mouse_x>plotx && mouse_x<plotx+35 && mouse_y>ploty && mouse_y<ploty+20)
        {
            index_edit_light_plot=toggle(index_edit_light_plot);
            mouse_released=1;
        }
        for(int i=0; i<4; i++)
        {
            if(mouse_x>plotx+45+(i*15) && mouse_x<plotx+45+(i*15)+10 )
            {
                if( mouse_y>ploty-5 && mouse_y<ploty+5)//vision
                {
                    if( Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_solo_affectation(1605+i,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        if(index_main_clear==0 && index_plot_send_to_mode==0)
                        {
                            switch(plot_layer_mode)
                            {
                            case 0:
                                show_calc_number[i]=toggle(show_calc_number[i]);
                                mouse_released=1;
                                break;
                            case 1:
                                for(int j=0; j<4; j++)
                                {
                                    show_calc_number[j]=0;
                                }
                                show_calc_number[i]=1;
                                view_plot_calc_number_is=i;
                                mouse_released=1;
                                break;
                            default:
                                break;
                            }
                            plot_generate_appareils_list();
                        }
                        else if(index_main_clear==1 && index_plot_send_to_mode==0)
                        {
                            plot_layer_selected=i;
                            index_ask_delete_symbols_on_calc=1;
                            index_ask_confirm=1;
                        }
                        else if(index_main_clear==0 && index_plot_send_to_mode==1)
                        {
                            plot_layer_selected=i;
                            send_symbols_from_calc_to_calc(view_plot_calc_number_is,plot_layer_selected)     ;
                            recount_symbols_on_calc(view_plot_calc_number_is);
                            index_plot_send_to_mode=0;
                            plot_layer_selected=0;
                            plot_generate_appareils_list();
                        }
                    }
                }
                else if(mouse_y>ploty+10 && mouse_y<ploty+20)
                {
                    reset_symbols_selected(view_plot_calc_number_is);
                    index_click_inside_plot=0;
                    switch(plot_layer_mode)
                    {
                    case 0:
                        view_plot_calc_number_is=i;
                        show_calc_number[i]=1;
                        break;
                    case 1:
                        for(int j=0; j<4; j++)
                        {
                            show_calc_number[j]=0;
                        }
                        show_calc_number[i]=1;
                        view_plot_calc_number_is=i;
                        mouse_released=1;
                        break;
                    default:
                        break;
                    }
                    plot_generate_appareils_list();
                }

                mouse_released=1;
            }


        }

        if(mouse_x>plotx+130 && mouse_x<plotx+130+100 && mouse_y>ploty-5 && mouse_y<ploty-5+25)
        {
            if(index_main_clear==0)
            {
                int previous_pos=index_menus_lighting_plot;
                index_menus_lighting_plot++;

                if(index_menus_lighting_plot>4)
                {
                    index_menus_lighting_plot=0;
                }
                if(index_menus_lighting_plot>1)
                {
                    plot_generate_appareils_list();
                }
                if(index_menus_lighting_plot==3 )//legende
                {
                    plot_correcteur_portx=plot_view_port_x;
                    plot_correcteur_porty=plot_view_port_y;
                }
                if(index_menus_lighting_plot==4 )
                {
                    plot_window_x_size-=position_plan_x;
                    if(plot_window_x_size<840)
                    {
                        plot_window_x_size=840;
                    }
                    position_plan_x=0;
                }
                if(previous_pos==4)
                {
                    position_plan_x=230;
                    plot_window_x_size+=position_plan_x;
                }
            }
            else//clear
            {
                index_ask_general_clear_on_plot=1;
                index_ask_confirm=1;
            }
            mouse_released=1;
        }

        if(mouse_x>plotx+240 && mouse_x<plotx+240+120 && mouse_y>ploty-5 && mouse_y<ploty-5+25)
        {
            if(index_main_clear==1)
            {
                plot_view_port_x=0;
                plot_view_port_y=0;
            }
            else
            {
                index_move_plot_view_port=toggle( index_move_plot_view_port);
                mouse_released=1;
            }
            mouse_released=1;
        }

        if(mouse_x>plotx+110 && mouse_x<plotx+110+10 && mouse_y>ploty+2 && mouse_y<ploty+2+10)
        {
            if(  Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(1609,Midi_Faders_Affectation_Mode);
            }
            else
            {
                plot_layer_mode=toggle(plot_layer_mode);
            }
            mouse_released=1;
        }



        command_button_logical(plotx+380,ploty-5,plot_index_show_levels,"SeeLevels","",1595,100);// int x, inty ,bool state, char *textedesc, int midiaffectation

        command_button_logical(plotx+460,ploty-5,plot_index_show_levels_from_faders,"SeeFaders","",1596,101);// int x, inty ,bool state, char *textedesc, int midiaffectation

        command_button_logical(plotx+540,ploty-5,index_blind,"Blind","",754,110);// int x, inty ,bool state, char *textedesc, int midiaffectation, int the command number

        if(index_menus_lighting_plot!=4)
        {
            if(mouse_x>plotx+620 && mouse_x<plotx+620+100 && mouse_y>ploty-5 && mouse_y<ploty-5+20 && mouse_x<plotx+plot_window_x_size)
            {
                index_do_a_plot_screen_capture=1;
                index_show_button_export=1.0;
                mouse_released=1;
            }
            if(index_type==1 && mouse_x>plotx+730 && mouse_x<plotx+730+220 && mouse_x<plotx+plot_window_x_size-position_plan_x && mouse_y>ploty-5 && mouse_y<ploty+15)
            {
                sprintf(plot_name_of_capture,numeric);
                reset_numeric_entry();
                numeric_postext=0;
                if(index_text_auto_close==1)
                {
                    index_type=0;
                }
                mouse_released=1;
            }
        }

    }
    return(0);
}
