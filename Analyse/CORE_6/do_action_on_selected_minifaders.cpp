int do_action_on_selected_minifaders(int action)
{
    bool index_choose_mode_dkloop=0;//0 toggle tt le monde / 1 copie l etat du dck selctionn� dans tt le monde
    //sab 02/03/2014 unsued var int tpdkval=0;
    int dockused=0;

    for(int cmptfader=0; cmptfader<max_faders; cmptfader++)
    {
        if( minifaders_selected[cmptfader]==1)
        {
            switch(action)
            {
            case 0://flash
                break;
            case 1://lock
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
                    //remise � plat du niveau
                    Fader[cmptfader]=(unsigned char)((((float)(StateOfFaderBeforeLock[cmptfader]))/255)*locklevel);
                    midi_levels[cmptfader]=(int)(((float)Fader[cmptfader])/2);
                    sprintf(string_Last_Order,">> UNLOCKED Fader %d",cmptfader+1);
                    break;
                 default:break;
                }
                break;
            case 2://loop on off
                for(int j=0; j<core_user_define_nb_docks; j++)
                {
                    if(DockIsSelected[cmptfader][j]==1)
                    {
                        is_dock_for_lfo_selected[cmptfader][j]=toggle(is_dock_for_lfo_selected[cmptfader][j]);
                        break;
                    }
                }
                break;
            case 3://UP
                if(FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1)
                {
                    start_time_for_delays[cmptfader]=actual_time;
                    if(lfo_mode_is[cmptfader]!=1)//up
                    {
                        lfo_mode_is[cmptfader]=1;
                        faders_in_float[cmptfader]=Fader[cmptfader];
                        if(index_midi_mute_on_lfo==1)
                        {
                            is_raccrochage_midi_remote[cmptfader]=1;
                        }
                    }
                    else
                    {
                        lfo_mode_is[cmptfader]=0;
                    }
                    lfo_cycle_is_on[cmptfader]=0;
                }
                break;
            case 4://DOWN
                if(FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1)
                {
                    start_time_for_delays[cmptfader]=actual_time;
                    if(lfo_mode_is[cmptfader]!=2)//down
                    {
                        lfo_mode_is[cmptfader]=2;
                        faders_in_float[cmptfader]=Fader[cmptfader];
                        if(index_midi_mute_on_lfo==1)
                        {
                            is_raccrochage_midi_remote[cmptfader]=1;
                        }
                    }
                    else
                    {
                        lfo_mode_is[cmptfader]=0;
                    }
                    lfo_cycle_is_on[cmptfader]=0;
                }
                break;
            case 5://SAW
                if(FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1)
                {
                    start_time_for_delays[cmptfader]=actual_time;
                    faders_in_float[cmptfader]=Fader[cmptfader];
                    if(lfo_cycle_is_on[cmptfader]==0)//
                    {
                        lfo_cycle_is_on[cmptfader]=1;
                        lfo_mode_is[cmptfader]=0;
                        lfo_running_is_upward[cmptfader]=1;
                        if(index_midi_mute_on_lfo==1)
                        {
                            is_raccrochage_midi_remote[cmptfader]=1;
                        }
                    }
                    else if(lfo_cycle_is_on[cmptfader]==1)
                    {
                        lfo_cycle_is_on[cmptfader]=0;
                    }
                }
                break;
            case 6://Loop all
                for (int ck=0; ck<5; ck++)
                {
                    if(is_dock_for_lfo_selected[cmptfader][ck]!=is_dock_for_lfo_selected[cmptfader][ck+1])
                    {
                        index_choose_mode_dkloop=1;
                        break;
                    }
                }
                switch(index_choose_mode_dkloop)
                {
                case 0:
                    for(int op=0; op<core_user_define_nb_docks; op++)
                    {
                        is_dock_for_lfo_selected[cmptfader][op]=toggle(is_dock_for_lfo_selected[cmptfader][op]);
                    }
                    break;
                case 1:
                    for(int j=0; j<core_user_define_nb_docks; j++)
                    {
                        if(DockIsSelected[cmptfader][j]==1)
                        {
                            int tempval_dockloop=toggle(is_dock_for_lfo_selected[cmptfader][j]);
                            for(int k=0; k<core_user_define_nb_docks; k++)
                            {
                                is_dock_for_lfo_selected[cmptfader][k]=toggle(tempval_dockloop);
                            }
                            break;
                        }
                    }
                    break;
                    default:break;

                }
                break;
            case 7://all at zero
                do_stock_fadersstate(1,1,1,1,1);

                Fader[cmptfader]=0;
                midi_levels[cmptfader]=0;
                index_send_midi_out[cmptfader]=1;
                lfo_speed[cmptfader]=64;
                midi_levels[196+cmptfader]=64;
                index_send_midi_out[196+cmptfader]=1;
                FaderLocked[cmptfader]=0;
                lfo_mode_is[cmptfader]=0;//no lfo
                lfo_cycle_is_on[cmptfader]=0;//saw
                lfo_cycle_steps[cmptfader]=0;
                lfo_do_next_step[cmptfader][0]=0;
                lfo_do_next_step[cmptfader][1]=0;
                for(int d=0; d<core_user_define_nb_docks; d++)
                {
                    is_dock_for_lfo_selected[cmptfader][d]=0;
                }

            break;

            case 8://Set pos job

                if(index_do_dock==0 && index_main_clear==0)
                {
                    ActionnateStopOn[cmptfader]=toggle(ActionnateStopOn[cmptfader]);
                    mouse_released=1;
                }

                else if(index_do_dock==1 && index_main_clear==0 )
                {
                    if(numeric_postext>0 )//affectation stop pos par chaine de carcatere
                    {
                        int lStopPos=999;
                        switch(dmx_view)
                        {
                        case 0:
                            lStopPos=(int)((atof(numeric) *2.55) +1);//+1 pour arrondir le %
                            break;
                        case 1:
                            lStopPos=atol(numeric);
                            break;
                         default:break;
                        }
                        reset_numeric_entry();
                        if (lStopPos>=0 && lStopPos<=255)
                        {
                            StopPosOn[cmptfader]=1;
                            LevelStopPos[cmptfader]=lStopPos;
                            index_do_dock=0;
                            do_light_setpos[cmptfader]=1;
                        }
                    }
                    else if (numeric_postext==0) //affectation stop pos depuis le cursuer fader
                    {
                        StopPosOn[cmptfader]=1;
                        LevelStopPos[cmptfader]=Fader[cmptfader];
                        index_do_dock=0;
                        do_light_setpos[cmptfader]=1;
                    }
                }

                else if(index_main_clear==1 && index_do_dock==0)//clear
                {
                    StopPosOn[cmptfader]=0;
                    LevelStopPos[cmptfader]=999;
                    index_main_clear=0;
                    do_light_setpos[cmptfader]=1;
                }
                break;
            case 9://PrEV DOCK MODE
                if (lfo_do_next_step[cmptfader][0]==0)
                {
                    lfo_do_next_step[cmptfader][0]=1;
                    lfo_do_next_step[cmptfader][1]=0;
                }
                else if (lfo_do_next_step[cmptfader][0]==1)
                {
                    lfo_do_next_step[cmptfader][0]=0;
                }
                break;
            case 10://NEXT DOCK MODE
                if (lfo_do_next_step[cmptfader][1]==0)
                {
                    lfo_do_next_step[cmptfader][1]=1;
                    lfo_do_next_step[cmptfader][0]=0; ;
                }
                else if (lfo_do_next_step[cmptfader][1]==1)
                {
                    lfo_do_next_step[cmptfader][1]=0;
                }
                break;
            case 11://VA ET VIENT
                lfo_cycle_steps[cmptfader]= toggle(lfo_cycle_steps[cmptfader]);
                break;
            case 12: //dock minus
                dockused=detect_dock_used(cmptfader);
                DockIsSelected[cmptfader][dockused]=0;
                if (dockused>0)
                {
                    DockIsSelected[cmptfader][dockused]=0;
                    dockused--;
                    DockIsSelected[cmptfader][dockused]=1;
                }
                else if (dockused==0)
                {
                    DockIsSelected[cmptfader][dockused]=0;
                    dockused=5;//6 docks pos 5
                    DockIsSelected[cmptfader][dockused]=1;
                }

                break;
            case 13: // dock plus
                dockused=detect_dock_used(cmptfader);
                DockIsSelected[cmptfader][dockused]=0;
                if (dockused<5)
                {
                    DockIsSelected[cmptfader][dockused]=0;
                    dockused++;
                    DockIsSelected[cmptfader][dockused]=1;
                }
                else if (dockused==5)
                {
                    DockIsSelected[cmptfader][dockused]=0;
                    dockused=0;//6 docks pos 5
                    DockIsSelected[cmptfader][dockused]=1;
                }

                break;
            case 14: //play embeded
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
                                    //player1->stop();
                                    player1_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                            case 1://PLAYER 2
                                switch(player2->isPlaying())
                                {
                                case 0:
                                    player2->play();
                                    break;
                                case 1:
                                    //player2->stop();
                                    player2_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                            case 2://PLAYER 3
                                switch(player3->isPlaying())
                                {
                                case 0:
                                    player3->play();
                                    break;
                                case 1:
                                    //player3->stop();
                                    player3_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                            case 3://PLAYER 4
                                switch(player4->isPlaying())
                                {
                                case 0:
                                    player4->play();
                                    break;
                                case 1:
                                    //player4->stop();
                                    player4_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                                default: break;
                            }
                            switch(player_is_playing[the_audio_player])//inversed by action
                            {
                            case 0:
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                                 default:break;
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
                                    //player1->stop();
                                    player1_do_stop();
                                    break;
                                 default:break;
                                }
                                break;
                            case 1://PLAYER 2
                                switch(player2->isPlaying())
                                {
                                case 0:
                                    player2->play();
                                    break;
                                case 1:
                                    //player2->stop();
                                    player2_do_stop();
                                    break;
                                 default:break;
                                }
                                break;
                            case 2://PLAYER 3
                                switch(player3->isPlaying())
                                {
                                case 0:
                                    player3->play();
                                    break;
                                case 1:
                                    //player3->stop();
                                    player3_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                            case 3://PLAYER 4
                                switch(player4->isPlaying())
                                {
                                case 0:
                                    player4->play();
                                    break;
                                case 1:
                                    //player4->stop();
                                    player4_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                                default: break;
                            }
                            switch(player_is_playing[the_audio_player])//inversed by action
                            {
                            case 0:
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                                 default:break;
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
                                    //player1->stop();
                                    player1_do_stop();
                                    break;
                                 default:break;
                                }
                                break;
                            case 1://PLAYER 2
                                switch(player2->isPlaying())
                                {
                                case 0:
                                    player2->play();
                                    break;
                                case 1:
                                    //player2->stop();
                                    player2_do_stop();
                                    break;
                                     default:break;
                                }
                                break;
                            case 2://PLAYER 3
                                switch(player3->isPlaying())
                                {
                                case 0:
                                    player3->play();
                                    break;
                                case 1:
                                    //player3->stop();
                                    player3_do_stop();
                                    break;
                                 default:break;
                                }
                                break;

                            case 3://PLAYER 4
                                switch(player4->isPlaying())
                                {
                                case 0:
                                    player4->play();
                                    break;
                                case 1:
                                    //player4->stop();
                                    player4_do_stop();
                                    break;
                                 default:break;
                                }
                                break;
                                 default:break;
                            }
                            switch(player_is_playing[the_audio_player])//inversed by action
                            {
                            case 0:
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",cmptfader+1,the_audio_player+1);
                                break;
                                 default:break;
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
                             default:break;
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
                             default:break;
                        }
                        break;
                    default:
                    break;
                    }
                }

                break;
            default:
                break;
            }
        }

    }
    return(0);
}
