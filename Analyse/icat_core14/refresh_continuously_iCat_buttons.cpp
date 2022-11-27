int refresh_continuously_iCat_buttons()
{

    int fis;
    for (int ck=1; ck<iCat_nbre_de_boutons[iCatPageis]+1; ck++) //bouton des faders
    {
        switch(iCat_affectation_bouton_type_is[iCatPageis][ck])
        {
        case 1: //faders

            fis=iCat_affectation_bouton_value_is[iCatPageis][ck]-1;
            fis=(constrain_int_data_to_this_range(fis,0,47));
            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 1: //fader up
                if(lfo_mode_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]==1)
                {
                    check_button_state[ck]=1;
                    if(index_midi_mute_on_lfo==1)
                    {
                        is_raccrochage_midi_remote[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]=1;
                    }
                }
                else
                {
                    check_button_state[ck]=0;
                }
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_up_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_up_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2://fader down
                if(lfo_mode_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]==2)
                {
                    check_button_state[ck]=1;
                    if(index_midi_mute_on_lfo==1)
                    {
                        is_raccrochage_midi_remote[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]=1;
                    }
                }
                else
                {
                    check_button_state[ck]=0;
                }
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_down_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_down_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 3://Fader saw
                check_button_state[ck]=lfo_cycle_is_on[iCat_affectation_bouton_value_is[iCatPageis][ck]-1];
                if(lfo_cycle_is_on[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]==1)
                {
                    if(index_midi_mute_on_lfo==1)
                    {
                        is_raccrochage_midi_remote[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]=1;
                    }
                }
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_saw_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_saw_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 4://ToPREVDock");
                check_button_state[ck]=lfo_do_next_step[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][0];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_prev_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_prev_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 5://ToNEXTDock
                check_button_state[ck]=lfo_do_next_step[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][1];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_next_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_next_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 6://Up/Down
                check_button_state[ck]=lfo_cycle_steps[iCat_affectation_bouton_value_is[iCatPageis][ck]-1];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_ar_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_ar_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 7://LOCK
                check_button_state[ck]=FaderLocked[iCat_affectation_bouton_value_is[iCatPageis][ck]-1];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lock_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lock_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 8://FLASH
                check_button_state[ck]=FaderIsFlash[iCat_affectation_bouton_value_is[iCatPageis][ck]-1];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_flash_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_flash_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 9://loop a dock
                check_button_state[ck]=
                    is_dock_for_lfo_selected[fis][(dock_used_by_fader_is[fis])];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;

            case 11://Play embeded

                switch(DockTypeIs[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]])
                {
                case 6:
                    check_button_state[ck]= player_is_playing[DockHasAudioVolume[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 7:
                    check_button_state[ck]= player_is_playing[DockHasAudioPan[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 8:
                    check_button_state[ck]= player_is_playing[DockHasAudioPitch[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 11:
                    check_button_state[ck]= chaser_is_playing[ChaserAffectedToDck[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]];
                    break;
                case 12:
                    check_button_state[ck]= grider_is_playing[faders_dock_grid_affectation[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]];
                    break;
                default:
                    break;
                }

                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/play_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/play_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 13://Loop chaser
                fis=iCat_affectation_bouton_value_is[iCatPageis][ck]-1;

                switch(DockTypeIs[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]])
                {
                case 6:
                    check_button_state[ck]=  player_is_onloop[DockHasAudioVolume[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 7:
                    check_button_state[ck]=  player_is_onloop[DockHasAudioPan[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 8:
                    check_button_state[ck]=  player_is_onloop[DockHasAudioPitch[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]-1];
                    break;
                case 11:
                    check_button_state[ck]= chaser_is_in_loop[ChaserAffectedToDck[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]];
                    break;
                case 12:
                    check_button_state[ck]= grider_autostopmode[faders_dock_grid_affectation[iCat_affectation_bouton_value_is[iCatPageis][ck]-1][dock_used_by_fader_is[iCat_affectation_bouton_value_is[iCatPageis][ck]-1]]];
                    break;
                default:
                    break;
                }
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                }
                break;
            default:
                strcpy(StrOrderToiCat,"");
                break;
            }

            break;

        case 2://minifaders
            int num_mf;
            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 16:
                num_mf=iCat_affectation_bouton_value_is[iCatPageis][ck]-1;
                if(num_mf>=0 && num_mf<48)
                {
                    check_button_state[ck]= minifaders_selected[num_mf] ;
                    if(before_check_button_state[ck]!=check_button_state[ck])
                    {
                        switch(check_button_state[ck])
                        {
                        case 0:
                            sprintf(StrOrderToiCat,"model MFnum%d color 1.0 1.0 1.0",ck);
                            break;
                        case 1:
                            sprintf(StrOrderToiCat,"model MFnum%d color 1.0 0.0 0.0",ck);
                            break;
                        default:
                            break;
                        }
                    }
                }
                break;
            case 20://lock preset
                num_mf=iCat_affectation_bouton_value_is[iCatPageis][ck]-1;
                if(num_mf>=0 && num_mf<8)
                {
                    check_button_state[ck]= lock_preset[num_mf] ;
                    if(before_check_button_state[ck]!=check_button_state[ck])
                    {
                        switch(check_button_state[ck])
                        {
                        case 0:
                            sprintf(StrOrderToiCat,"model MFnum%d color 1.0 1.0 1.0",ck);
                            break;
                        case 1:
                            sprintf(StrOrderToiCat,"model MFnum%d color 0.0 0.4 0.3",ck);
                            break;
                        default:
                            break;
                        }
                    }
                }
                break;
            default:
                break;
            }

            break;



        case 3://sequences
            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 0://desafected
                break;
            case 1: //GO
                check_button_state[ck]=index_go ;

                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(index_go)
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/go_off.jpg",ck);
                        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/go_on.jpg",ck);
                        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        break;
                    default:
                        break;
                    }
                }

                if(index_pause==1 && index_go_back==0)
                {
                    sprintf(StrOrderToiCat, "model tBut%d color %.1f 0.0 0.0",ck,1.0);
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                else
                {
                    sprintf(StrOrderToiCat, "model tBut%d color 1.0 1.0 1.0",ck);
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 2://GO BACK
                check_button_state[ck]=index_go_back ;
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/goback_off.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/goback_on.jpg",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    if( index_go_back==1)
                    {
                        switch(index_pause)
                        {
                        case 0:
                            sprintf(StrOrderToiCat, "model tBut%d color 1.0 1.0 1.0",ck);
                            break;
                        case 1:
                            sprintf(StrOrderToiCat, "model tBut%d color 1.0 0.0 0.0",ck);
                            break;
                        default:
                            break;
                        }
                        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                }
                break;
            default:
                break;
            }
            break;

        case 4://EMULATE

            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 26://"F1");
                check_button_state[ck]=index_do_dock ;
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch( index_do_dock)
                    {
                    case 0:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 27://"F2");
                check_button_state[ck]=index_do_modify ;
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch( index_do_modify)
                    {
                    case 0:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 28://"F3");
                check_button_state[ck]=index_do_report ;
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch( index_do_report)
                    {
                    case 0:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 29://"F4");
                check_button_state[ck]=index_main_clear ;
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch( index_main_clear)
                    {
                    case 0:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 30://"F11");
                break;
            case 31://"F12");
                break;
            case 32://"SHFT");
                switch( index_false_shift)
                {
                case 0:
                    sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                    break;
                case 1:
                    sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                    break;
                default:
                    break;
                }
                nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                break;
            case 33://"CTRL");
                switch( index_false_control)
                {
                case 0:
                    sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                    break;
                case 1:
                    sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck);
                    break;
                default:
                    break;
                }
                nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                break;


            default://
                break;
            }


            break;
        case 5://banger
            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 0:
                break;
            case 1://bang solo
                check_button_state[ck]=bang_is_sended[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)];
                if(before_check_button_state[ck]!=check_button_state[ck])
                {
                    switch(check_button_state[ck])
                    {
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/rond_banger_off.png",ck);
                        break;
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/rond_banger_on.png",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
            default:
                break;
            }


            break;

        case 6://icat commandes
            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 3://page iCat num selectionnnee
                if(iCatPageis!=oldiCatPageis)
                {
                    if(iCatPageis==iCat_affectation_bouton_value_is[iCatPageis][ck]-1)
                    {
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 0.0 0.0",ck) ;
                    }
                    else
                    {
                        sprintf(StrOrderToiCat, "model SimB%d color 1.0 1.0 1.0",ck);
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                oldiCatPageis=iCatPageis;
                break;
            default://
                break;
            }
            break;
        case 7://draw

            switch(iCat_affectation_bouton_action_is[iCatPageis][ck])
            {
            case 1://"Brush Type" selected
                if(draw_brush_type[draw_preset_selected]!=previous_draw_brush_type[draw_preset_selected] || draw_preset_selected!=previous_draw_preset_selected )
                {
                    switch(draw_brush_type[draw_preset_selected])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_point.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_gpl.jpg",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }

                break;
            case 2://draw_mode selected
                if(draw_mode[draw_preset_selected]!=previous_draw_mode[draw_preset_selected] || draw_preset_selected!=previous_draw_preset_selected)
                {
                    switch(draw_mode[draw_preset_selected])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_draw.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_erase.jpg",ck);
                        break;
                    case 2:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_solo.jpg",ck);
                        break;
                    case 3:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_ghost.jpg",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }

                break;

            case 3://"Brush Type" par valeur de matrice
                if(draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)]!=previous_draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)] || draw_preset_selected!=previous_draw_preset_selected)
                {
                    switch(draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_point.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_gpl.jpg",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;
            case 4://draw_mode par valeur de matrice
                if(draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)]!=previous_draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)] || draw_preset_selected!=previous_draw_preset_selected)
                {
                    switch(draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][ck]-1)])
                    {
                    case 0:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_draw.jpg",ck);
                        break;
                    case 1:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_erase.jpg",ck);
                        break;
                    case 2:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_solo.jpg",ck);
                        break;
                    case 3:
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_ghost.jpg",ck);
                        break;
                    default:
                        break;
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                break;

            case 5://preset matrix
                if(draw_preset_selected!=previous_draw_preset_selected)
                {
                    if( (iCat_affectation_bouton_value_is[iCatPageis][ck]-1 )==draw_preset_selected )
                    {
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_preset_selected.png",ck);
                    }
                    else
                    {
                        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_preset_vide.png",ck);
                    }
                    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

                    //rafraichissement de la page icat des déclarations car les tailles de colonnes les circuits  etc changent !
                    refresh_icatpage_please=1;;
                }

                //pas de previous ici car il y a plusieurs presets
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }



        if(before_check_button_state[ck]!=check_button_state[ck])
        {
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        }
        before_check_button_state[ck]=check_button_state[ck];
    }

    previous_draw_preset_selected=draw_preset_selected;
    for(int i=0; i<6; i++)
    {
        previous_draw_brush_type[i]=draw_brush_type[i];
        previous_draw_mode[i]=draw_mode[i];
    }
    return(0);
}
