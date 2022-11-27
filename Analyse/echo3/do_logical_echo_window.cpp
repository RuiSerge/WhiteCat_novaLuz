int do_logical_echo_window(int xe, int ye)
{
    if(window_focus_id==W_ECHO && dragging_channel_in_echo==0 && mouse_button==1)
    {

        if( mouse_released==0 && mouse_x>xe+610 && mouse_x<xe+610+50 && mouse_y>ye+10 && mouse_y<ye+10+20 )
        {
            index_enable_edit_echo=toggle(index_enable_edit_echo);
            mouse_released=1;
        }


        int index_ec=0;
        for(int le=0; le<3; le++)
        {
            for(int cel=0; cel<8; cel++)
            {
                index_ec=cel+(le*8);
                if( mouse_x> xe+180+(40*cel) && mouse_x<xe+180+(40*cel)+30 && mouse_y>ye+10+(le*25) && mouse_y<ye+10+(le*25)+20)
                {
                    if( mouse_released==0 )
                    {
                        if( Midi_Faders_Affectation_Type!=0)//config midi
                        {
                            attribute_midi_to_control(1663+index_ec,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                        }
                        else
                        {
                            if(index_main_clear==1)
                            {
                                if(index_enable_edit_echo==1)
                                {
                                    index_selected_echo_for_manipulation=index_ec;
                                    index_ask_clear_echo_preset=1;
                                    index_ask_confirm=1;             //clear_echo_preset(index_selected_echo_for_manipulation);
                                }
                            }

                            else
                            {
                                echo_selected=index_ec;

                            }
                        }
                        mouse_released=1;
                    }
                }
            }
        }


        if( mouse_x>xe+615 && mouse_x<xe+615+40 && mouse_y>ye+65 && mouse_y<ye+65+20 && mouse_released==0 && dragging_channel_in_echo==0 && numeric_postext>0)
        {
            echo_grid_channel_position[echo_selected]=atoi(numeric)-1;
            echo_grid_channel_position[echo_selected]= constrain_int_data_to_this_range(echo_grid_channel_position[echo_selected],0,511-14);
            reset_numeric_entry();
            numeric_postext=0;
            mouse_released=1;
        }



        for (int n=0; n<5; n++)
        {
            if(mouse_x>xe+30 && mouse_x<xe+30+115 && mouse_y>ye+50+(n*30) && mouse_y<ye+50+30+(n*30))
            {
                if( mouse_released==0 )
                {
                    if( Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1686+n,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        switch(n)
                        {
                        case 0:
                            echo_is_echo_mode[echo_selected]=toggle(echo_is_echo_mode[echo_selected]);
                            do_bounce[echo_selected]=echo_is_echo_mode[echo_selected];
                            break;
                        case 1:
                            snap_fader_state(echo_selected,echo_pointing_fader_num[echo_selected]-1);
                            break;
                        case 2:
                            bounce(echo_selected);
                            break;
                        case 3:
                            snap_kill_and_bounce(echo_selected,echo_pointing_fader_num[echo_selected]-1);
                            break;
                        case 4:
                            recall_fader_state_echo(echo_pointing_fader_num[echo_selected]-1);
                            break;
                        default:
                            break;
                        }
                    }
                    mouse_released=1;
                }

            }
        }

        if( mouse_x>xe+70 && mouse_x<xe+70+45 && mouse_y>ye+200 && mouse_y<ye+200+35 && mouse_released==0 && numeric_postext>0)
        {
            echo_pointing_fader_num[echo_selected]=constrain_int_data_to_this_range(atoi(numeric),1,48);
            reset_numeric_entry();
            numeric_postext=0;
            mouse_released=1;
        }


        if( mouse_released==0 && mouse_x>xe+10 && mouse_x<xe+10+110 && mouse_y>ye+245 && mouse_y<ye+245+20  )
        {
            if(index_affect_echo_to_dock==0)
            {
                reset_index_actions();
                reset_indexs_confirmation();
                index_affect_echo_to_dock=1;
            }
            else
            {
                reset_index_actions();
            }
            index_do_dock=index_affect_echo_to_dock;
            mouse_released=1;
        }


        if( mouse_released==0 && mouse_x>xe+500 && mouse_x<xe+500+70 && mouse_y>ye+10 && mouse_y<ye+10+20)
        {
            if( Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(1696,Midi_Faders_Affectation_Mode);
            }
            else
            {
                if(index_main_clear==1 && index_enable_edit_echo==1)
                {
                    switch(echo_channel_manipulate_mode[echo_selected])
                    {
                    case 0://levels
                        clear_echo_levels(echo_selected);
                        break;
                    case 1:
                        clear_ground_levels(echo_selected);
                        break;
                    default:
                        break;
                    }
                    index_main_clear=0;
                }
                else
                {
                    echo_channel_manipulate_mode[echo_selected]=toggle(echo_channel_manipulate_mode[echo_selected]);
                }
            }
            mouse_released=1;
        }






        for (int cl=0; cl<3; cl++)
        {

            if(mouse_x>=xe+155+(cl*180) && mouse_x<=xe+155+(cl*180)+130 && mouse_y>=ye+255 && mouse_y<=ye+255+10)
            {
                if(  mouse_released==0)
                {
                    if( Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1693+cl,Midi_Faders_Affectation_Mode);
                        mouse_released=1;
                    }
                    else
                    {
                        echo_global_params[echo_selected][cl]= (float)(constrain_data_to_midi_range(mouse_x-( xe+155+(cl*180))))/127;
                        midi_levels[1693+cl]=(int)(echo_global_params[echo_selected][cl]*127);
                    }
                }
            }
            if( mouse_released==0 && mouse_x>=xe+290+(cl*180) && mouse_x<=xe+290+(cl*180)+10 && mouse_y>=ye+260 && mouse_y<=ye+265+10)
            {
                midi_send_out[1693+cl]=toggle(midi_send_out[1693+cl]);
                mouse_released=1;
            }

        }//fin des 3 sliders



    }
    do_logical_Echo_Aera(xe+155,ye+95);
    return(0);
}
