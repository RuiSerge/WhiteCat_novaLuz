int logical_plot_symbol_edition(int plotx, int ploty)
{

    if(window_focus_id==W_PLOT && mouse_button==1 && mouse_released==0 && index_click_inside_relativ_xy==0)
    {
        if( mouse_x>=plotx+10 && mouse_x<=plotx+10+100+5 && mouse_y>ploty+40 && mouse_y<ploty+40+10)
        {

            if(mouse_released==0 &&  Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(1601,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }
            else
            {
                angle_projo_selectionne=((float)(mouse_x-(plotx+10)))/100;
                if(angle_projo_selectionne<0.0)
                {
                    angle_projo_selectionne=0.0;
                }
                if (angle_projo_selectionne>1.0)
                {
                    angle_projo_selectionne=1.0;
                }
                affect_angle_to_symbols(view_plot_calc_number_is,angle_projo_selectionne);
            }
        }

        if(mouse_x>plotx+76 && mouse_x<plotx+76+60 && mouse_y>ploty+22 && mouse_y<ploty+22+15 && index_click_inside_relativ_xy==0 && mouse_released==0)
        {
            float numof=atof(numeric);
            angle_projo_selectionne=numof;
            if(angle_projo_selectionne<0.0)
            {
                angle_projo_selectionne=0.0;
            }
            else if(angle_projo_selectionne>1.0)
            {
                angle_projo_selectionne=1.0;
            }
            affect_angle_to_symbols(view_plot_calc_number_is,angle_projo_selectionne);
            mouse_released=1;
            reset_numeric_entry();
            numeric_postext=0;
            mouse_released=1;
        }

        for(int l=0; l<3; l++)
        {
            for(int c=0; c<3; c++)
            {
                int pos2=(l*3) + c;
                if( mouse_x>plotx+140+(c*15) && mouse_x<plotx+140+(c*15)+10 && mouse_y>ploty+10+(l*15) && mouse_y<ploty+10+(l*15)+10 )
                {
                    switch(pos2)
                    {
                    case 0:
                        angle_projo_selectionne=0.12;
                        break;
                    case 1:
                        angle_projo_selectionne=0.0;
                        break;
                    case 2:
                        angle_projo_selectionne=0.84;
                        break;
                    case 3:
                        angle_projo_selectionne=0.242;
                        break;
                    case 4:
                        //nothing
                        break;
                    case 5:
                        angle_projo_selectionne=0.725;
                        break;
                    case 6:
                        angle_projo_selectionne=0.36;
                        break;
                    case 7:
                        angle_projo_selectionne=0.483;
                        break;
                    case 8:
                        angle_projo_selectionne=0.605;
                        break;
                    default:
                        break;
                    }
                    affect_angle_to_symbols(view_plot_calc_number_is,angle_projo_selectionne);
                    mouse_released=1;
                }
            }
        }



    }

    for(int c=0; c<3; c++)
    {
        for(int l=0; l<2; l++)
        {
            if(index_edit_light_plot==1 && index_click_inside_relativ_xy==0
                    && mouse_x>plotx+5+(c*65) && mouse_x<plotx+5+(c*65)+60 && mouse_y>ploty+60+(l*20) && mouse_y<ploty+60+(l*20)+18
                    && mouse_button==1 && mouse_released==0)
            {
                switch(c+(l*3))
                {
                case 0://"Dub",plotx+20+(c*65),ploty+82+(l*20));

                    if(  Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_solo_affectation(1602,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        duplicate_selected_symbols(view_plot_calc_number_is);
                    }
                    break;
                case 1://"Delete",plotx+10+(c*65),ploty+82+(l*20));



                    if(  Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_solo_affectation(1603,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        snapshot_calc(view_plot_calc_number_is);
                        delete_selected_symbols(view_plot_calc_number_is);


                        plot_generate_appareils_list();
                        generate_channel_view_list_from_patched_circuits();


                    }
                    break;
                case 2://"SendTo"
                    if(  Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_solo_affectation(1604,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        index_plot_send_to_mode=toggle(index_plot_send_to_mode);
                    }
                    break;
                case 3://"Down"
                    position_down_selected_symbols(view_plot_calc_number_is);
                    break;
                case 4://"Top"
                    position_on_top(view_plot_calc_number_is);
                    break;
                case 5://"Grp/ungroup"
                    group_symbols_selected(view_plot_calc_number_is);
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }


        for(int c=0; c<4; c++)
        {
            if( index_edit_light_plot==1 && index_click_inside_relativ_xy==0
                    && mouse_button==1 && mouse_released==0
                    && mouse_x>plotx+10+(c*45)&&mouse_x<plotx+10+(c*45)+40 && mouse_y>ploty+110 && mouse_y<ploty+110+18)
            {
                switch(c)
                {
                case 0://align x
                    plot_align_x(view_plot_calc_number_is);
                    break;
                case 1://align y
                    plot_align_y(view_plot_calc_number_is);
                    break;
                case 2://ventilation x
                    plot_ventilate_x(view_plot_calc_number_is);
                    break;
                case 3://ventilation y
                    plot_ventilate_y(view_plot_calc_number_is);
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }



    }


    return(0);
}
