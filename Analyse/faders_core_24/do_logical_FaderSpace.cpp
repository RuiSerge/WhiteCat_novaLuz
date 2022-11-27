int do_logical_FaderSpace(int x, int y,int largeur, int espacement, int nbr_fader)
{
    if(index_moving_fader_space==0)
    {
        for (int cmptfader=0; cmptfader<nbr_fader; cmptfader++)
        {
            if(((x+(cmptfader*espacement)+espacement)>0)&& ((x+(cmptfader*espacement)+largeur)< LargeurEspaceFaderSize))
            {
                if(mouse_released==0 && mouse_x>x+(cmptfader*espacement)+(largeur+20) && mouse_x<x+(cmptfader*espacement)+(largeur+20)+10 && mouse_y>=y-30 && mouse_y<=y-20)
                {
                    fader_fx_route[cmptfader]=toggle(fader_fx_route[cmptfader]);
                    mouse_released=1;
                }

                if(mouse_released==0 && mouse_x>x+(cmptfader*espacement)+(largeur+35) && mouse_x<x+(cmptfader*espacement)+(largeur+35)+largeur && mouse_y>=y-30 && mouse_y<=y-20)
                {
                    if( Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_to_control(1543+cmptfader, Midi_Faders_Affectation_Type,  Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        fader_mode_with_buffers[cmptfader]++;
                        if(fader_mode_with_buffers[cmptfader]>5)
                        {
                            fader_mode_with_buffers[cmptfader]=0;
                        }
                    }
                    mouse_released=1;
                }
                if(mouse_x>x+(cmptfader*espacement) && mouse_x<x+(cmptfader*espacement)+largeur && mouse_y>=y && mouse_y<=y+255)
                {
                    show_who_is_in_dock( cmptfader,   detect_dock_used(cmptfader));
                    set_mouse_range(x+(cmptfader*espacement), y, x+(cmptfader*espacement)+largeur, y+255);//pour pas deborder
                    if( index_main_clear==0)
                    {
                        int val=((y+255)-mouse_y);
                        fader_set_level(cmptfader,val);
                        index_fader_is_manipulated[cmptfader]=1;
                        if(midi_send_out[cmptfader]==1)
                        {
                            index_send_midi_out[cmptfader]=1;
                        }
                        if(lfo_mode_is[cmptfader]==1 || lfo_mode_is[cmptfader]==2 || lfo_cycle_is_on[cmptfader]==1)
                        {
                            lfo_mode_is[cmptfader]=0;
                            lfo_mode_is[cmptfader]=0;
                            lfo_cycle_is_on[cmptfader]=0;
                        }
                        switch(miditable[0][cmptfader])
                        {
                        case 0:
                            sprintf(thetypinfo,"Note");
                            break;
                        case 1:
                            sprintf(thetypinfo,"Key On");
                            break;
                        case 2:
                            sprintf(thetypinfo,"Key Off");
                            break;
                        case 4:
                            sprintf(thetypinfo,"Ctrl Change");
                            break;
                        default:
                            break;
                        }
                        sprintf(string_last_midi_id,"Fader is Ch: %d Pitch: %d Type: %s", miditable[1][cmptfader],miditable[2][cmptfader],thetypinfo);

                        if( Midi_Faders_Affectation_Type!=0)
                        {
                            attribute_midi_to_control(cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                        }
                    }
                    if(index_main_clear==1)//clear de tous les dock du fader
                    {
                        fader_selected_for_record=cmptfader;
                        index_do_clear_on_faders=1;
                        index_ask_confirm=1;
                        mouse_released=1  ;
                    }
                }

                if(mouse_x>x+(cmptfader*espacement)+largeur+95 && mouse_x<x+(cmptfader*espacement)+largeur+95+15 &&
                        mouse_y>y-35 && mouse_y<y-35+15 )
                {
                    switch(miditable[0][556+cmptfader])
                    {
                    case 0:
                        sprintf(thetypinfo,"Note");
                        break;
                    case 1:
                        sprintf(thetypinfo,"Key On");
                        break;
                    case 2:
                        sprintf(thetypinfo,"Key Off");
                        break;
                    case 4:
                        sprintf(thetypinfo,"Ctrl Change");
                        break;
                    default:
                        break;
                    }
                    sprintf(string_last_midi_id,"MIDI DO ORDER BUTTON:Ch: %d Pitch: %d Type: %s", miditable[1][556+cmptfader],miditable[2][556+cmptfader],thetypinfo);
                    if( Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_to_control(cmptfader+556, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    }
                }
                for (int dd=0; dd<core_user_define_nb_docks; dd++)
                {

                    if (DockIsSelected[cmptfader][dd]==1)
                    {

                        if(DockTypeIs[cmptfader][dd]==5)
                        {
                            for(int tt=0; tt<24; tt++)
                            {
                                DockName[cmptfader][dd][tt]=descriptif_memoires[(DockHasMem[cmptfader][dd])][tt] ;
                            }
                            DockName[cmptfader][dd][24]='\0';
                        }


                    }

                    if(mouse_x>=(x+(cmptfader*espacement)+(largeur+30)) && mouse_x<=(x+(cmptfader*espacement)+(largeur+80))
                            && mouse_y>=(y + (dd*40)) && mouse_y<=(y + (dd*40)+20)
                            && index_over_function_call==0 )
                    {


                        if(index_do_dock==0 && index_do_modify==0  && index_type==0    && index_main_clear==0 )
                        {
                            DockIsSelected[cmptfader][dd]=1;
                            Unselect_other_docks(cmptfader, dd);
                            mouse_released=1;
                        }
                        else if( index_type==1)
                        {
                            for(int tt=0; tt<24; tt++)
                            {
                                DockName[cmptfader][dd][tt]=numeric[tt];
                            }
                            DockName[cmptfader][dd][24]='\0';
                            reset_numeric_entry();
                            numeric_postext=0;
                            if(index_text_auto_close==1)
                            {
                                index_type=0;
                            }


                            if( DockTypeIs[cmptfader][dd]==10 )
                            {
                                sprintf(descriptif_projecteurs[(FaderDirectChan[cmptfader][dd])],DockName[cmptfader][dd]);
                            }
                            sprintf(string_Last_Order,">>On Master %d GIVED A NAME FOR DOCK %d ", cmptfader+1,dd);
                            mouse_released=1;
                        }

                        else if(index_do_dock==1 && index_direct_chan==0   && index_affect_chaser_to_dock==0  && index_affect_time==0 && index_affect_color_to_dock==0 && index_do_affect_net_to_dock==0
                                && index_affect_dmxin==0 && index_affect_video_tracking_to_dock==0 && index_affect_audio_to_dock==0 && gridplayer_to_affect_is==-1
                                && index_do_fgroup==0 && index_affect_to_dock_mover==0 && index_affect_draw_to_dock==0 &&  index_affect_echo_to_dock==0 && index_affect_wave_to_dock==0)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_record_on_faders=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        //store direct CH
                        else if(index_do_dock==1 && index_direct_chan==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;

                            index_do_record_direct_ch=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }


                        else if (  index_do_dock==1 && index_do_fgroup==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_fgroup=1;
                            index_ask_confirm=1;
                        }

                        else if( index_do_dock==1 && index_affect_time==1)
                        {
                            show_im_recording_a_time=1;
                            DoTimeToDock(cmptfader,dd);
                            sprintf(string_Last_Order,">>Time affected to Master %d Dock %d", cmptfader+1,dd);
                            index_affect_time=0;
                            mouse_released=1;
                        }
                        else if(index_do_dock==1 && index_affect_color_to_dock==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_color_on_faders=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        //Store Chaser dans dock
                        else if (index_do_dock==1 && index_affect_chaser_to_dock==1 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_fx=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        //Store Grid dans dock
                        else if ( index_do_dock==1 &&  gridplayer_to_affect_is>=0 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_grid_to_fader=1;
                            index_ask_confirm=1;
                        }

                        else if( index_do_dock==1 && index_affect_video_tracking_to_dock==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_video_to_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else if( index_do_dock==1 && index_affect_audio_to_dock==1)
                        {
                            if(player_to_affect_to_dock>=0 && player_to_affect_to_dock<4 )
                            {
                                fader_selected_for_record=cmptfader;
                                dock_selected_for_record=dd;
                                index_do_audio_to_dock=1;
                                index_ask_confirm=1;
                            }
                            mouse_released=1;
                        }
                        //Store Mover dans dock
                        else if (  index_do_dock==1 && index_affect_to_dock_mover==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_mover=1;
                            index_ask_confirm=1;
                        }
                        else if( index_do_dock==1 && index_affect_dmxin==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_dmx_to_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else if(index_do_dock==1 && index_do_affect_net_to_dock==1 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_artnet_to_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else if(index_do_dock==1 && index_affect_draw_to_dock==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            draw_preset_selected_for_order=draw_preset_selected;
                            index_do_draw_affect_to_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        //echo
                        else if(index_do_dock==1 && index_affect_echo_to_dock==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_affect_echo_to_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else if(index_do_dock==1 && index_affect_wave_to_dock==1)
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else if( index_do_modify==1 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_modify_on_faders=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }

                        //report
                        if( index_do_report==1 && index_type==0 && index_do_dock==0 && index_do_modify==0 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_report_on_faders=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }

                        //clear
                        else if(index_main_clear==1 )
                        {
                            fader_selected_for_record=cmptfader;
                            dock_selected_for_record=dd;
                            index_do_clear_dock=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }


                        else if(Midi_Faders_Affectation_Type!=0 && dd<2)
                        {
                            attribute_midi_to_control(cmptfader+48+(dd*48), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                            mouse_released=1;
                        }

                    }


                }

                if(mouse_x> x+((cmptfader*espacement)+(largeur+30)-10) && mouse_x< x+((cmptfader*espacement)+(largeur+30)+10)
                        && mouse_y>y+250-10 && mouse_y<y+250+10 )
                {

                    if(midi_send_out[cmptfader]==0)
                    {
                        midi_send_out[cmptfader]=1;
                    }
                    else if(midi_send_out[cmptfader]==1)
                    {
                        midi_send_out[cmptfader]=0;
                    }
                    //midi_send_out[cmptfader+196]= midi_send_out[cmptfader];//LFOS
                    mouse_released=1;
                }

                raccrochage_midi_logical_vertical_dmx(x+(cmptfader*espacement),y,cmptfader,largeur,255);
                if(mouse_y>(y+280) && mouse_y<(y+280+(largeur/2)+7) && mouse_x>x+(cmptfader*espacement) && mouse_x<(x+largeur+(cmptfader*espacement))
                  )
                {
                    switch(miditable[0][146+cmptfader])
                    {
                    case 0:
                        sprintf(thetypinfo,"Note");
                        break;
                    case 1:
                        sprintf(thetypinfo,"Key On");
                        break;
                    case 2:
                        sprintf(thetypinfo,"Key Off");
                        break;
                    case 4:
                        sprintf(thetypinfo,"Ctrl Change");
                        break;
                    default:
                        break;
                    }
                    sprintf(string_last_midi_id,"LOCK is Ch: %d Pitch: %d Type: %s", miditable[1][146+cmptfader],miditable[2][146+cmptfader],thetypinfo);

                    if(Midi_Faders_Affectation_Type!=0)
                    {
                        attribute_midi_to_control(cmptfader+146, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                        mouse_released=1;
                    }
                    //action lock on/off
                    else
                    {
                        switch(FaderLocked[cmptfader])
                        {
                        case 0:
                            FaderLocked[cmptfader]=1;
                            StateOfFaderBeforeLock[cmptfader]=Fader[cmptfader];
                            if(StateOfFaderBeforeLock[cmptfader]==255)
                            {
                                LockFader_is_FullLevel[cmptfader]=1;
                            }
                            else if(StateOfFaderBeforeLock[cmptfader]<255)
                            {
                                LockFader_is_FullLevel[cmptfader]=0;
                            }
                            sprintf(string_Last_Order,">> LOCKED Fader %d",cmptfader+1);
                            if(LockFader_is_FullLevel[cmptfader]==0)//quand mis en lock et pas full level rajout 0.7.6
                            {
                                lfo_mode_is[cmptfader]=0;
                                lfo_cycle_is_on[cmptfader]=0;
                            }
                            break;
                        case 1:
                            FaderLocked[cmptfader]=0;
                            //remise à plat du niveau
                            Fader[cmptfader]=(unsigned char)((((float)(StateOfFaderBeforeLock[cmptfader]))/255)*locklevel);
                            midi_levels[cmptfader]=(int)(((float)Fader[cmptfader])/2);
                            sprintf(string_Last_Order,">> UNLOCKED Fader %d",cmptfader+1);
                            break;
                        default:
                            break;
                        }
                        mouse_released=1;
                    }

                }

                if(mouse_x>x+(cmptfader*espacement)-10 && mouse_x<x+(cmptfader*espacement)-10+20 && mouse_y>y+410 && mouse_y<y+410+20)
                {

                    if(index_do_dock==1)
                    {
                        fader_selected_for_record=cmptfader;
                        curve_asked_for_fader=atoi(numeric);
                        if(curve_asked_for_fader>16 || curve_asked_for_fader<1)
                        {
                            curve_asked_for_fader=16;
                        }
                        index_ask_curv_to_fader=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }

                }

                do_logical_lfo_fader_functions(cmptfader, x-((int)(largeur-(largeur*size_faders))), y,50,espacement);

            }

            int the_chaser;
            int the_grid_player;
            int the_audio_player;

            if(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==11 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==12
                    || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==6 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==7 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==8  )

            {

                if ( DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==11) the_chaser=ChaserAffectedToDck[cmptfader][dock_used_by_fader_is[cmptfader]];
                else if ( DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==12 )  the_grid_player=faders_dock_grid_affectation[cmptfader][dock_used_by_fader_is[cmptfader]];
                else if( DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==6 ) the_audio_player=DockHasAudioVolume[cmptfader][dock_used_by_fader_is[cmptfader]]-1;
                else if ( DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==7 ) the_audio_player=DockHasAudioPan[cmptfader][dock_used_by_fader_is[cmptfader]]-1;
                else if ( DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==8 ) the_audio_player=DockHasAudioPitch[cmptfader][dock_used_by_fader_is[cmptfader]]-1;

                if(mouse_x>x+(cmptfader*espacement)+20 && mouse_x<x+(cmptfader*espacement)+20+20 && mouse_y>y+410 && mouse_y<y+410+20   && mouse_released==0)
                {
                    show_type_midi(1115+cmptfader, "Play embeded");
                    if(Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1115+cmptfader,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        switch(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]])
                        {
                        case 6://vol
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1->isPlaying())
                                    {
                                    case 0:
                                        player1->play();
                                        break;
                                    case 1:
                                        player1->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2->isPlaying())
                                    {
                                    case 0:
                                        player2->play();
                                        break;
                                    case 1:
                                        player2->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3->isPlaying())
                                    {
                                    case 0:
                                        player3->play();
                                        break;
                                    case 1:
                                        player3->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4->isPlaying())
                                    {
                                    case 0:
                                        player4->play();
                                        break;
                                    case 1:
                                        player4->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }
                                switch(player_is_playing[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        case 7://pan
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1->isPlaying())
                                    {
                                    case 0:
                                        player1->play();
                                        break;
                                    case 1:
                                        player1->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2->isPlaying())
                                    {
                                    case 0:
                                        player2->play();
                                        break;
                                    case 1:
                                        player2->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3->isPlaying())
                                    {
                                    case 0:
                                        player3->play();
                                        break;
                                    case 1:
                                        player3->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4->isPlaying())
                                    {
                                    case 0:
                                        player4->play();
                                        break;
                                    case 1:
                                        player4->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }

                                switch(player_is_playing[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        case 8://pitch
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1->isPlaying())
                                    {
                                    case 0:
                                        player1->play();
                                        break;
                                    case 1:
                                        player1->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2->isPlaying())
                                    {
                                    case 0:
                                        player2->play();
                                        break;
                                    case 1:
                                        player2->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3->isPlaying())
                                    {
                                    case 0:
                                        player3->play();
                                        break;
                                    case 1:
                                        player3->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4->isPlaying())
                                    {
                                    case 0:
                                        player4->play();
                                        break;
                                    case 1:
                                        player4->stop();
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }

                                switch(player_is_playing[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        case 11://chaser
                            chaser_is_playing[the_chaser]=toggle(chaser_is_playing[the_chaser]);
                            if(chaser_is_playing[the_chaser]==1)//snap du temps at beg
                            {
                                chaser_start_time[the_chaser]=actual_time;
                                if(chaser_step_is[chaser_selected]<0)
                                {
                                    chaser_step_is[chaser_selected]=0;
                                }
                                else if(chaser_step_is[chaser_selected]>35)
                                {
                                    chaser_step_is[chaser_selected]=35;
                                }
                            }
                            switch(chaser_is_playing[the_chaser])
                            {
                            case 0:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Chaser %d",cmptfader+1,the_chaser+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Chaser %d",cmptfader+1,the_chaser+1);
                                break;
                            default:
                                break;
                            }
                            break;
                        case 12://grid
                            grider_is_playing[the_grid_player]=toggle(grider_is_playing[the_grid_player]);
                            if(grider_is_playing[the_grid_player]==1)
                            {
                                grid_crossfade_start_time[the_grid_player]=actual_time;
                            }
                            switch(player_is_playing[the_grid_player])
                            {
                            case 0:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d GridPl %d",cmptfader+1,the_grid_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d GridPl %d",cmptfader+1,the_grid_player+1);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }

                    }
                    mouse_released=1;
                }


                if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+65 && mouse_y>y+410 && mouse_y<y+410+20  && mouse_button==1 && mouse_released==0)
                {
                    show_type_midi(1164+cmptfader, "Seek to Beg embedded");
                    if( Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1164+cmptfader,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        switch(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]])
                        {
                        case 6://vol
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    player1->setPosition(0);
                                    break;
                                case 1://PLAYER 2
                                    player2->setPosition(0);
                                    break;
                                case 2://PLAYER 3
                                    player3->setPosition(0);
                                    break;
                                case 3://PLAYER 4
                                    player4->setPosition(0);
                                    break;
                                default:
                                    break;
                                }
                                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",cmptfader+1,the_audio_player+1);
                            }
                            break;
                        case 7://pan
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    player1->setPosition(0);
                                    break;
                                case 1://PLAYER 2
                                    player2->setPosition(0);
                                    break;
                                case 2://PLAYER 3
                                    player3->setPosition(0);
                                    break;
                                case 3://PLAYER 4
                                    player4->setPosition(0);
                                    break;
                                default:
                                    break;
                                }
                                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",cmptfader+1,the_audio_player+1);
                            }
                            break;
                        case 8://pitch
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    if(player_is_onloopCue[0]==0  )
                                    {
                                        player1->setPosition(0);
                                    }
                                    else
                                    {
                                        player1->setPosition(player_seek_position[0]);
                                    }
                                    break;
                                case 1://PLAYER 2
                                    if(player_is_onloopCue[1]==0  )
                                    {
                                        player2->setPosition(0);
                                    }
                                    else
                                    {
                                        player2->setPosition(player_seek_position[1]);
                                    }
                                    break;
                                case 2://PLAYER 3
                                    player3->stop();
                                    if(player_is_onloopCue[2]==0  )
                                    {
                                        player1->setPosition(0);
                                    }
                                    else
                                    {
                                        player3->setPosition(player_seek_position[2]);
                                    }
                                    break;
                                case 3://PLAYER 4
                                    if(player_is_onloopCue[3]==0  )
                                    {
                                        player4->setPosition(0);
                                    }
                                    else
                                    {
                                        player4->setPosition(player_seek_position[3]);
                                    }
                                    break;
                                default:
                                    break;
                                }
                                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",cmptfader+1,the_audio_player+1);
                            }
                            break;
                        case 11://chaser
                            chaser_seek_at_beg(the_chaser);
                            sprintf(string_Last_Order,">> Seek To Beg from Fader %d Chaser %d",cmptfader+1,the_chaser+1);
                            break;
                        case 12://grid
                            gridplayer_seek(the_grid_player);
                            sprintf(string_Last_Order,">> Seek from Fader %d GridPl %d",cmptfader+1,the_grid_player+1);
                            break;
                        default:
                            break;
                        }
                    }

                    mouse_released=1;
                }

                if(mouse_x>x+(cmptfader*espacement)+70 && mouse_x<x+(cmptfader*espacement)+70+20 && mouse_y>y+410 && mouse_y<y+410+20 && mouse_button==1 && mouse_released==0)
                {
                    show_type_midi(1213+cmptfader, "Loop Selected CHASER");
                    if( Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1213+cmptfader,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        switch(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]])
                        {
                        case 6://vol the_audio_player
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1-> getRepeat())
                                    {
                                    case 0:
                                        player1->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player1->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2-> getRepeat())
                                    {
                                    case 0:
                                        player2->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player2->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3-> getRepeat())
                                    {
                                    case 0:
                                        player3->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player3->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4-> getRepeat())
                                    {
                                    case 0:
                                        player4->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player4->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }

                                switch(player_is_onloop[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }

                            }
                            break;
                        case 7://pan
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1-> getRepeat())
                                    {
                                    case 0:
                                        player1->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player1->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2-> getRepeat())
                                    {
                                    case 0:
                                        player2->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player2->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3-> getRepeat())
                                    {
                                    case 0:
                                        player3->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player3->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4-> getRepeat())
                                    {
                                    case 0:
                                        player4->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player4->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }

                                switch(player_is_onloop[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }

                            }
                            break;
                        case 8://pitch
                            if(player_ignited[the_audio_player]==1)
                            {
                                switch(the_audio_player)
                                {
                                case 0://PLAYER 1
                                    switch(player1-> getRepeat())
                                    {
                                    case 0:
                                        player1->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player1->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 1://PLAYER 2
                                    switch(player2-> getRepeat())
                                    {
                                    case 0:
                                        player2->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player2->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 2://PLAYER 3
                                    switch(player3-> getRepeat())
                                    {
                                    case 0:
                                        player3->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player3->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                case 3://PLAYER 4
                                    switch(player4-> getRepeat())
                                    {
                                    case 0:
                                        player4->setRepeat(true);
                                        player_is_onloop[the_audio_player]=1;
                                        break;
                                    case 1:
                                        player4->setRepeat(false);
                                        player_is_onloop[the_audio_player]=0;
                                        break;
                                    default:
                                        break;
                                    }
                                    break;
                                default:
                                    break;
                                }

                                switch(player_is_onloop[the_audio_player])//inversed by action
                                {
                                case 0:
                                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                case 1:
                                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                    break;
                                default:
                                    break;
                                }

                            }
                            break;
                        case 11: //chaser
                            chaser_is_in_loop[the_chaser]=toggle(chaser_is_in_loop[the_chaser]);
                            switch(chaser_is_in_loop[the_chaser])
                            {
                            case 0:
                                sprintf(string_Last_Order,">> LOOP OFF from Fader %d Chaser %d",cmptfader+1, the_chaser+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> LOOP ON from Fader %d Chaser %d",cmptfader+1, the_chaser+1);
                                break;
                            default:
                                break;
                            }
                            break;
                        case 12: //grid
                            grider_autostopmode[the_grid_player]=toggle(grider_autostopmode[the_grid_player]);
                            switch(grider_autostopmode[the_grid_player])
                            {
                            case 0:
                                sprintf(string_Last_Order,">> AutoStop OFF from Fader %d Gpl %d",cmptfader+1, the_grid_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> AutoStop ON from Fader %d Gpl %d",cmptfader+1, the_grid_player+1);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }

                    mouse_released=1;
                }

                if(mouse_x>x+(cmptfader*espacement)+95 && mouse_x<x+(cmptfader*espacement)+95+20 && mouse_y>y+410 && mouse_y<y+410+20  && mouse_button==1 && mouse_released==0)
                {
                    show_type_midi(1278+cmptfader, "Autolaunch Selected");
                    if( Midi_Faders_Affectation_Type!=0)//config midi
                    {
                        attribute_midi_solo_affectation(1278+cmptfader,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        autolaunch[cmptfader]=toggle( autolaunch[cmptfader] );
                        switch(autolaunch[cmptfader])
                        {
                        case 0:
                            sprintf(string_Last_Order,">> AUTOLAUNCH OFF Fader %d",cmptfader+1);
                            break;
                        case 1:
                            sprintf(string_Last_Order,">> AUTOLAUNCH ON Fader %d",cmptfader+1);
                            break;
                        default:
                            break;
                        }
                    }

                    mouse_released=1;
                }



            }//fin si chaser embeded


            do_logical_fader_damper_commands(x+(cmptfader*espacement)-10,y+440, cmptfader );


        }
    }//fin de la condition moving fader space


    do_logical_MoveFaderSpace(y-70);// fonction pour se deplacer sur les 48 masters

    return(0);
}
