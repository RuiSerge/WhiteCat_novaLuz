int do_logical_ChannelsMenuSelection(int chx, int chy)
{

    if(window_focus_id==0 && index_over_faderspace==0 && mouse_button==1 && mouse_released==0)
    {
        if( mouse_y>chy+1 && mouse_y<chy+1+18 && mouse_x>chx+70 && mouse_x<chx+70+60 )
        {
            if(Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(1644,Midi_Faders_Affectation_Mode);
            }
            else
            {
                ClassicalChannelView=toggle(ClassicalChannelView);
            }
            mouse_released=1;
        }
        for(int lv=0; lv<2; lv++)
        {
            for(int i=0; i<8; i++)
            {
                if(mouse_x>chx+140+(i*15) && mouse_x<chx+140+(i*15)+10 && mouse_y>chy+1+(15*lv) && mouse_y<chy+1+(15*lv)+10)
                {
                    if(Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_to_control(1628+i+(lv*8),Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        if(index_do_dock==0 && index_do_modify==0 && index_main_clear==0)
                        {
                            if(ClassicalChannelView==1)
                            {
                                ClassicalChannelView=0;
                                if(Channel_View_MODE[i+(lv*8)]==0)
                                {
                                    Channel_View_MODE[i+(lv*8)]=1;
                                }
                            }
                            else
                            {
                                Channel_View_MODE[i+(lv*8)]=toggle(Channel_View_MODE[i+(lv*8)]);
                                ClassicalChannelView=0;
                            }
                        }
                        else if(index_do_dock==1 && i+(lv*8)!=0)//=vue patch
                        {
                            channel_view_is=i+(lv*8);
                            index_ask_record_selection_of_view=i+(lv*8);
                            index_ask_confirm=1;
                        }
                        else if(index_do_modify==1 && i+(lv*8)!=0)//=vue patch
                        {
                            channel_view_is=i+(lv*8);

                            index_ask_modify_selection_of_view=1;
                            index_ask_confirm=1;
                        }
                        else if(index_main_clear==1 && i+(lv*8)!=0)//=vue patch
                        {
                            channel_view_is=i+(lv*8);
                            index_ask_confirm=1;
                            index_ask_clear_selection_of_view=1;
                        }
                    }
                    mouse_released=1;
                }
            }
        }
        command_button_logical(chx+270,chy+1,index_blind,"Blind","Shift-F10",754,110);
        command_button_logical(chx+340,chy+1,index_direct_chan,"Direct CH.","",1333,111);
        command_button_logical(chx+410,chy+1,index_inspekt,"View","",1334,112);// int x, inty ,bool state, char *textedesc, int midiaffectation
        command_button_logical(chx+480,chy+1,index_do_hipass,"HiPass","",1542,113);// int x, inty ,bool state, char *textedesc, int midiaffectation
        command_button_logical(chx+550,chy+1,index_do_fgroup,"FGroup","",1592,114);// int x, inty ,bool state, char *textedesc, int midiaffectation

        command_button_logical(chx+620,chy+1,Midi_Faders_Affectation_Type,"MidiAffect","",1625,106);// int x, inty ,bool state, char *textedesc, int midiaffectation
        command_button_logical(chx+690,chy+1,index_midi_mute,"MidiMute","",1277,107);// int x, inty ,bool state, char *textedesc, int midiaffectation
        command_button_logical(chx+760,chy+1,index_global_midi_send_on_faders,"M.Out Fad.","",1593,109);// int x, inty ,bool state, char *textedesc, int midiaffectation

        command_button_logical(chx+830,chy+1,index_do_dock,"STORE","F1",743,102);// int x, inty ,bool state, char *textedesc, int midiaffectation
        command_button_logical(chx+900,chy+1,index_do_modify,"MODIFY","F2",744,103);
        command_button_logical(chx+970,chy+1,index_do_report,"REPORT","F3",745,104);
        command_button_logical(chx+1040,chy+1,index_main_clear,"CLEAR","F4",746,105);
        command_button_logical(chx+1110,chy+1,index_show_main_menu,"MENUS","RIGHT CLICK",1626,108);
    }
    return(0);
}
