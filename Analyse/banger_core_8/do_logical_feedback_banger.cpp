int do_logical_feedback_banger(int xvis, int yvis)
{
    int banger_overoll=0;
    if(window_focus_id==917 )
    {
        for (int nb=0; nb<8; nb++)
        {
            for (int lb=0; lb<16; lb++)
            {
                if((nb)+(lb*8)<core_user_define_nb_bangers)
                {
                    if( mouse_x>xvis+(nb*12)+30-5 && mouse_x<xvis+(nb*12)+30+5 && mouse_y>yvis+(lb*12)+30-5 && mouse_y<yvis+(lb*12)+30+5)
                    {
                        banger_overoll=(nb)+(lb*8);

                        if(banger_overoll<127 && banger_overoll>=0)
                        {
                            if(mouse_button==1 && mouse_released==0)
                            {
                                if(Midi_Faders_Affectation_Type!=0 )//config midi
                                {
                                    attribute_midi_to_control(1343+banger_overoll, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                                }
                                else
                                {
                                    if(index_copy_banger==1)
                                    {
                                        index_ask_copy_banger=1;
                                        index_ask_confirm=1;
                                        index_banger_to_copy_in=banger_overoll;
                                        mouse_released=1;
                                    }
                                    else
                                    {
                                        bang_is_sended[banger_overoll]=toggle(bang_is_sended[banger_overoll]);
                                        switch (bang_is_sended[banger_overoll])
                                        {
                                        case 0://reset des send events et on demarre à la souris le banger
                                            for (int y=0; y<6; y++)
                                            {
                                                event_sended[banger_overoll][y]=0;
                                            }
                                            start_time_for_banger[banger_overoll]=actual_time;

                                            for (int y=0; y<6; y++)
                                            {
                                                if(bangers_delay[banger_overoll][y]> end_time_for_banger[banger_overoll])
                                                {
                                                    end_time_for_banger[banger_overoll]= bangers_delay[banger_overoll][y];
                                                }
                                            }
                                            if(end_time_for_banger[banger_overoll]<default_time_of_the_bang)
                                            {
                                                end_time_for_banger[banger_overoll]=default_time_of_the_bang;
                                            }

                                            last_banger_sended_manually=banger_overoll;
                                            break;
                                        case 1://go back sur le banger
                                            for (int y=0; y<6; y++)
                                            {
                                                if(bangers_type[banger_overoll][y]!=0 )
                                                {
                                                    Bang_event_back(banger_overoll, y);
                                                    event_sended[banger_overoll][y]=1;
                                                }
                                            }
                                            bang_is_sended[banger_overoll]=1;//bloquage de l envoi des autres évènements
                                            break;
                                        default:
                                            break;
                                        }
                                    }
                                }
                                mouse_released=1;
                            }
                        }
                    }
                }
            }
        }
    }
    return(0);
}
