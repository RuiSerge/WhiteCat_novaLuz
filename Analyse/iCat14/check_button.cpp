int check_button( int tp)
{

    int fsBx=FS_touch_point_begin[0][tp];
    int fsBy=FS_touch_point_begin[1][tp];
    int fsEx=FS_touch_point_end[0][tp];
    int fsEy=FS_touch_point_end[1][tp];

    int fsTestX2=0;
    int fsTestY2=0;

    for(int bt=1; bt<iCat_nbre_de_boutons[iCatPageis]+1; bt++)
    {

        fsTestX2=(iCat_pos_bouton[iCatPageis][bt][0]*2)+(largueur_bouton*ratio_iCat_button[iCatPageis][bt]);
        fsTestY2=(iCat_pos_bouton[iCatPageis][bt][1]*2)+(largueur_bouton*ratio_iCat_button[iCatPageis][bt]);
        /* original avec appui = action
        if (  fsBx>=(iCat_pos_bouton[iCatPageis][bt][0]*2) && fsBx<=fsTestX2 && fsBy>=(iCat_pos_bouton[iCatPageis][bt][1]*2) && fsBy<=fsTestY2 )
        {
        button_is_touched[iCatPageis][bt]=1;
        button_is_controlled_by_point[iCatPageis][bt]=tp;
        }
        if ( fsEx>=(iCat_pos_bouton[iCatPageis][bt][0]*2) && fsEx<=fsTestX2 && fsEy>=(iCat_pos_bouton[iCatPageis][bt][1]*2) && fsEy<=fsTestY2 )
        {
        button_is_touched[iCatPageis][bt]=0;
        button_is_controlled_by_point[iCatPageis][bt]=tp;
        FS_touch_point_end[0][tp]=-999;FS_touch_point_end[1][tp]=-999;
        }
        */
        if (  fsBx>=(iCat_pos_bouton[iCatPageis][bt][0]*2) && fsBx<=fsTestX2 && fsBy>=(iCat_pos_bouton[iCatPageis][bt][1]*2) && fsBy<=fsTestY2 )
        {
            button_is_touched[iCatPageis][bt]=0;
            FS_touch_point_end[0][tp]=-999;
            FS_touch_point_end[1][tp]=-999;
        }
        if ( fsEx>=(iCat_pos_bouton[iCatPageis][bt][0]*2) && fsEx<=fsTestX2 && fsEy>=(iCat_pos_bouton[iCatPageis][bt][1]*2) && fsEy<=fsTestY2 )
        {
            button_is_touched[iCatPageis][bt]=1;
            button_is_controlled_by_point[iCatPageis][bt]=tp;
        }


        if(button_is_touched[iCatPageis][bt]==1 && button_is_controlled_by_point[iCatPageis][bt]==tp  )
        {
            int fis=0;
            bool index_choose_mode_dkloop=0;//0 toggle tt le monde / 1 copie l etat du dck selctionn� dans tt le monde
            int the_chaser=0;
            int the_audio_player=0;
            int the_grid_player=0;
            int banger_back_is=0;
            int action_minif=0;
            int dock_selected_is=0;
            int bangeriCat=0;

            switch(iCat_affectation_bouton_type_is[iCatPageis][bt])
            {
            case 0:
                break;
            case 1://faders
                fis=(iCat_affectation_bouton_value_is[iCatPageis][bt]-1);

                if(DockTypeIs[fis][dock_used_by_fader_is[fis]]==11 || DockTypeIs[fis][dock_used_by_fader_is[fis]]==12
                        || DockTypeIs[fis][dock_used_by_fader_is[fis]]==6 || DockTypeIs[fis][dock_used_by_fader_is[fis]]==7 || DockTypeIs[fis][dock_used_by_fader_is[fis]]==8  )

                {

                    if ( DockTypeIs[fis][dock_used_by_fader_is[fis]]==11) the_chaser=ChaserAffectedToDck[fis][dock_used_by_fader_is[fis]];
                    else if ( DockTypeIs[fis][dock_used_by_fader_is[fis]]==12 )  the_grid_player=faders_dock_grid_affectation[fis][dock_used_by_fader_is[fis]];
                    else if( DockTypeIs[fis][dock_used_by_fader_is[fis]]==6 ) the_audio_player=DockHasAudioVolume[fis][dock_used_by_fader_is[fis]]-1;
                    else if ( DockTypeIs[fis][dock_used_by_fader_is[fis]]==7 ) the_audio_player=DockHasAudioPan[fis][dock_used_by_fader_is[fis]]-1;
                    else if ( DockTypeIs[fis][dock_used_by_fader_is[fis]]==8 ) the_audio_player=DockHasAudioPitch[fis][dock_used_by_fader_is[fis]]-1;
                }

                switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                {
                case 0://desafected
                    break;
                case 1: //"UP");
                    //for delays
                    start_time_for_delays[fis]=actual_time;
                    if(lfo_mode_is[fis]!=1)//up
                    {
                        lfo_mode_is[fis]=1;
                        faders_in_float[fis]=Fader[fis];
                    }
                    else
                    {
                        lfo_mode_is[fis]=0;
                    }
                    lfo_cycle_is_on[fis]=0;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 2://"DOWN");
                    //for delays
                    start_time_for_delays[fis]=actual_time;
                    if(lfo_mode_is[fis]!=2)//down
                    {
                        lfo_mode_is[fis]=2;
                        faders_in_float[fis]=Fader[fis];
                    }
                    else
                    {
                        lfo_mode_is[fis]=0;
                    }
                    lfo_cycle_is_on[fis]=0;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 3://"SAW");
                    start_time_for_delays[fis]=actual_time;
                    faders_in_float[fis]=Fader[fis];
                    if(lfo_cycle_is_on[fis]==0)//
                    {
                        lfo_cycle_is_on[fis]=1;
                        lfo_mode_is[fis]=0;
                        //bug saw at 0 / 1
                        lfo_running_is_upward[fis]=1;
                    }
                    else if(lfo_cycle_is_on[fis]==1)
                    {
                        lfo_cycle_is_on[fis]=0;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 4://ToPREVDock");
                    if (lfo_do_next_step[fis][0]==0)
                    {
                        lfo_do_next_step[fis][0]=1;
                        lfo_do_next_step[fis][1]=0;
                    }
                    else if (lfo_do_next_step[fis][0]==1)
                    {
                        lfo_do_next_step[fis][0]=0;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 5://ToNEXTDock");
                    if (lfo_do_next_step[fis][1]==0)
                    {
                        lfo_do_next_step[fis][1]=1;
                        lfo_do_next_step[fis][0]=0; ;
                    }
                    else if (lfo_do_next_step[fis][1]==1)
                    {
                        lfo_do_next_step[fis][1]=0;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 6://Up/Down");
                    lfo_cycle_steps[fis]= toggle(lfo_cycle_steps[fis]);
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 7://LOCK");
                    switch(FaderLocked[fis])
                    {
                    case 0:
                        FaderLocked[fis]=1;
                        StateOfFaderBeforeLock[fis]=Fader[fis];
                        if(StateOfFaderBeforeLock[fis]==255)
                        {
                            LockFader_is_FullLevel[fis]=1;
                        }
                        else if(StateOfFaderBeforeLock[fis]<255)
                        {
                            LockFader_is_FullLevel[fis]=0;
                        }
                        if(LockFader_is_FullLevel[fis]==0)//quand mis en lock et pas full level rajout 0.7.6
                        {
                            lfo_mode_is[fis]=0;
                            lfo_cycle_is_on[fis]=0;
                        }
                        break;
                    case 1:
                        FaderLocked[fis]=0;
                        //remise � plat du niveau
                        fader_set_level(fis,(unsigned char)((((float)(StateOfFaderBeforeLock[fis]))/255)*locklevel));
                        /*
                        Fader[fis]=(unsigned char)((((float)(StateOfFaderBeforeLock[fis]))/255)*locklevel);
                        midi_levels[fis]=(int)(((float)Fader[fis])/2);*/
                        break;
                    default:
                        break;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 8://FLASH");
                    if(FaderIsFlash[fis]==0)
                    {
                        FaderIsFlash[fis]=1;
                    }
                    break;

                case 9://L/Unloop dock");
                    is_dock_for_lfo_selected[fis][dock_used_by_fader_is[fis]]=toggle(is_dock_for_lfo_selected[fis][dock_used_by_fader_is[fis]]);
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 10://L/Unloop all");

                    for (int ck=0; ck<5; ck++)
                    {
                        if(is_dock_for_lfo_selected[fis][ck]!=is_dock_for_lfo_selected[fis][ck+1])
                        {
                            index_choose_mode_dkloop=1;
                            break;
                        }
                    }
                    switch(index_choose_mode_dkloop)
                    {
                    case 0:
                        for(int op=0; op<6; op++)
                        {
                            is_dock_for_lfo_selected[fis][op]=toggle(is_dock_for_lfo_selected[fis][op]);
                        }
                        break;
                    case 1:
                        //tout le monde prend la valeur du dock selectionn�
                        for(int j=0; j<6; j++)
                        {
                            if(DockIsSelected[fis][j]==1)
                            {
                                int tempval_dockloop=toggle(is_dock_for_lfo_selected[fis][j]);
                                for(int k=0; k<6; k++)
                                {
                                    is_dock_for_lfo_selected[fis][k]=toggle(tempval_dockloop);
                                }
                                break;
                            }
                        }
                        break;
                    default:
                        break;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 11://Play eCHASER");

                    switch(DockTypeIs[fis][dock_used_by_fader_is[fis]])
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
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                                sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                            sprintf(string_Last_Order,">> PLAY OFF from Fader %d Chaser %d",fis+1,the_chaser+1);
                            break;
                        case 1:
                            sprintf(string_Last_Order,">> PLAY ON from Fader %d Chaser %d",fis+1,the_chaser+1);
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
                            sprintf(string_Last_Order,">> PLAY OFF from Fader %d GridPl %d",fis+1,the_grid_player+1);
                            break;
                        case 1:
                            sprintf(string_Last_Order,">> PLAY ON from Fader %d GridPl %d",fis+1,the_grid_player+1);
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }


                    reset_button(iCatPageis,bt, tp);
                    break;
                case 12://seek embedded
                    switch(DockTypeIs[fis][dock_used_by_fader_is[fis]])
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
                            sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",fis+1,the_audio_player+1);
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
                            sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",fis+1,the_audio_player+1);
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
                            sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",fis+1,the_audio_player+1);
                        }
                        break;
                    case 11://chaser
                        chaser_seek_at_beg(the_chaser);
                        sprintf(string_Last_Order,">> Seek To Beg from Fader %d Chaser %d",fis+1,the_chaser+1);
                        break;
                    case 12://grid
                        gridplayer_seek(the_grid_player);
                        sprintf(string_Last_Order,">> Seek from Fader %d GridPl %d",fis+1,the_grid_player+1);
                        break;
                    default:
                        break;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 13://loop eCHASER
                    switch(DockTypeIs[fis][dock_used_by_fader_is[fis]])
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
                                sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                                sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                                sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",fis+1,the_audio_player+1);
                                break;
                            case 1:
                                sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",fis+1,the_audio_player+1);
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
                            sprintf(string_Last_Order,">> LOOP OFF from Fader %d Chaser %d",fis+1, the_chaser+1);
                            break;
                        case 1:
                            sprintf(string_Last_Order,">> LOOP ON from Fader %d Chaser %d",fis+1, the_chaser+1);
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
                            sprintf(string_Last_Order,">> AutoStop OFF from Fader %d Gpl %d",fis+1, the_grid_player+1);
                            break;
                        case 1:
                            sprintf(string_Last_Order,">> AutoStop ON from Fader %d Gpl %d",fis+1, the_grid_player+1);
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                default:
                    break;
                }

                //fin faders
                break;
            case 2://minifaders
                switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                {
                case 1: //fader up
                    action_minif=3;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 2://fader down
                    action_minif=4;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 3://Fader saw
                    action_minif=5;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 4://"ToPREVDoid");
                    action_minif=9;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 5://"ToNEXTDoid");
                    action_minif=10;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 6://"Up/Down");
                    action_minif=11;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 7://"LOck");
                    action_minif=1;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 8://"FLASH");action_minif=0
                    action_minif=0;
                    for(int tt=0; tt<47; tt++)
                    {
                        if( minifaders_selected[tt]==1 && FaderIsFlash[tt]==0)
                        {
                            FaderIsFlash[tt]=1;
                        }
                    }
                    break;
                case 9://"L/Unloop dock");
                    action_minif=2;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 10://"L/Unloop all");
                    action_minif=6;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 11://"Dock -");
                    action_minif=12;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 12://"Dock +");
                    action_minif=13;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 13://"Play eCHASER");
                    action_minif=14;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 14://all at 0
                    action_minif=7;
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 15://Set pos
                    action_minif=8;
                    break;
                case 16://"Select M.Fader");
                    minifaders_selected[iCat_affectation_bouton_value_is[iCatPageis][bt]-1]=toggle(minifaders_selected[iCat_affectation_bouton_value_is[iCatPageis][bt]-1]);

                    switch(minifaders_selected[iCat_affectation_bouton_value_is[iCatPageis][bt]-1])
                    {
                    case 0:
                        sprintf(string_Last_Order,"Minifader %d UN selected",iCat_affectation_bouton_value_is[iCatPageis][bt]);
                        break;
                    case 1:
                        sprintf(string_Last_Order,"Minifader %d SELected",iCat_affectation_bouton_value_is[iCatPageis][bt]);
                        break;
                    default:
                        break;
                    }
                    dock_selected_is=detect_dock_used(iCat_affectation_bouton_value_is[iCatPageis][bt]-1);


                    if(minifaders_selected[iCat_affectation_bouton_value_is[iCatPageis][bt]-1] ==1 && index_do_dock==1 && index_direct_chan==0)
                    {
                        fader_selected_for_record=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;
                        dock_selected_for_record=dock_selected_is;
                        index_do_record_on_faders=1;
                        index_ask_confirm=1;
                    }
                    //report
                    else if( index_do_report==1 && index_type==0 && index_do_dock==0 && index_do_modify==0 )
                    {
                        fader_selected_for_record=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;
                        dock_selected_for_record=dock_selected_is;
                        index_do_report_on_faders=1;
                        index_ask_confirm=1;
                        sprintf(string_Last_Order,"Report");
                    }

                    //modify
                    else if( index_do_modify==1 )
                    {
                        fader_selected_for_record=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;
                        dock_selected_for_record=dock_selected_is;
                        index_do_modify_on_faders=1;
                        index_ask_confirm=1;
                    }

                    //clear
                    else if(index_main_clear==1 )
                    {
                        fader_selected_for_record=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;
                        dock_selected_for_record=dock_selected_is;
                        index_do_clear_dock=1;
                        index_ask_confirm=1;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 17://"Unselect All");
                    for(int tt=0; tt<48; tt++)
                    {
                        minifaders_selected[tt]=0;
                    }
                    sprintf(string_Last_Order,"Minifaders ALL UNselected");
                    break;
                case 18://"Select All");
                    for(int tt=0; tt<48; tt++)
                    {
                        minifaders_selected[tt]=1;
                    }
                    sprintf(string_Last_Order,"Minifaders ALL SELected");
                    break;
                case 19://"Select M.Fader Pst");
                    if(iCat_affectation_bouton_value_is[iCatPageis][bt]-1 >=0 && iCat_affectation_bouton_value_is[iCatPageis][bt]-1<8)
                    {
                        for(int olp=0; olp<48; olp++)
                        {
                            minifaders_selected[olp]=minifaders_preset_selection[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)][olp];
                        }
                    }
                    sprintf(string_Last_Order,"Minifaders Preset %d SELected",iCat_affectation_bouton_value_is[iCatPageis][bt]);
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 20://locks presets
                    do_lock_preset(iCat_affectation_bouton_value_is[iCatPageis][bt]-1);
                    reset_button(iCatPageis,bt, tp);
                    break;
                default:
                    break;
                }

                do_action_on_selected_minifaders(action_minif);

                break;
            case 3://sequenciel
                reset_button(iCatPageis,bt, tp);  //reset pour eviter la frappe r�p�titive
                if(before_check_button_state[bt]==0)
                {
                    before_check_button_state[bt]=1;
                    switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                    {
                    case 1: //"GO");
                        do_go_function();
                        if(index_go==1 && index_pause==0)
                        {
                            do_send_bang();
                        }
                        reset_button(iCatPageis,bt, tp);
                        break;
                    case 2://"GO BACK");
                        do_go_back_function();
                        banger_back_is=Banger_Memoire[position_preset]-1;
                        do_go_back_bang(banger_back_is);
                        reset_button(iCatPageis,bt, tp);
                        break;
                    case 3://"JUMP");
                        do_double_go_function();
                        if(index_go==1 && index_pause==0)
                        {
                            do_send_bang();
                        }
                        reset_button(iCatPageis,bt, tp);
                        break;
                    case 4://"STAGE -");
                        if(index_go==0 && index_go_back==0 && index_pause==0)
                        {
                            position_onstage=mem_before_one;
                        }
                        else
                        {
                            index_go=0;
                            index_pause=0;
                            index_go_back=0;
                        }

                        refresh_mem_onstage(position_onstage);
                        detect_mem_before_one();
                        detect_mem_preset();
                        refresh_mem_onpreset(position_preset);
                        niveauX1=255;
                        niveauX2=0;
                        refresh_banger_wx();
                        reset_button(iCatPageis,bt, tp);
                        someone_changed_in_sequences=1;
                        break;
                    case 5://"STAGE +");
                        if(index_go==0 && index_go_back==0 && index_pause==0)
                        {
                            position_onstage=position_preset;
                        }
                        else
                        {
                            index_go=0;
                            index_pause=0;
                            index_go_back=0;
                        }

                        refresh_mem_onstage(position_onstage);
                        detect_mem_before_one();
                        detect_mem_preset();
                        refresh_mem_onpreset(position_preset);
                        niveauX1=255;
                        niveauX2=0;
                        refresh_banger_wx();
                        reset_button(iCatPageis,bt, tp);
                        someone_changed_in_sequences=1;
                        break;
                    case 6://"PRESET -");
                        index_go=0;
                        index_pause=0;
                        index_go_back=0;
                        detect_mem_preset_previous();
                        refresh_mem_onpreset(position_preset);
                        niveauX2=0;
                        reset_button(iCatPageis,bt, tp);
                        someone_changed_in_sequences=1;
                        break;
                    case 7://"PRESET +");
                        index_go=0;
                        index_pause=0;
                        index_go_back=0;
                        detect_next_preset();
                        refresh_mem_onpreset(position_preset);
                        niveauX2=0;
                        reset_button(iCatPageis,bt, tp);
                        someone_changed_in_sequences=1;
                        break;
                    case 8://GOTO
                        if(numeric_postext>0)
                        {
                            if(MemoiresExistantes[(int)(atof(numeric)*10)]==1)
                            {
                                position_preset=(int)(atof(numeric)*10);
                                refresh_mem_onpreset(position_preset);
                                reset_numeric_entry();
                                numeric_postext=0;
                                reset_button(iCatPageis,bt, tp);
                                someone_changed_in_sequences=1;
                            }
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 4:
                clear_keybuf();
                reset_button(iCatPageis,bt, tp);  //reset pour eviter la frappe r�p�titive
                if(before_check_button_state[bt]==0)
                {
                    before_check_button_state[bt]=1;
                    switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                    {
                    case 0://"0");
                        simulate_keypress(KEY_0 << 8);
                        break;
                    case 1://"1");
                        simulate_keypress(KEY_1 << 8);
                        break;
                    case 2://"2");
                        simulate_keypress(KEY_2 << 8);
                        break;
                    case 3://"3");
                        simulate_keypress(KEY_3 << 8);
                        break;
                    case 4://"4");
                        simulate_keypress(KEY_4 << 8);
                        break;
                    case 5://"5");
                        simulate_keypress(KEY_5 << 8);
                        break;
                    case 6://"6");
                        simulate_keypress(KEY_6 << 8);
                        break;
                    case 7://"7");
                        simulate_keypress(KEY_7 << 8);
                        break;
                    case 8://"8");
                        simulate_keypress(KEY_8 << 8);
                        break;
                    case 9://"9");
                        simulate_keypress(KEY_9 << 8);
                        break;
                    case 10://".");
                        simulate_keypress(KEY_COMMA<< 8);
                        break;
                    case 11://"PLUS");
                        simulate_keypress(KEY_PLUS_PAD << 8);
                        break;
                    case 12://"MINUS");
                        simulate_keypress(KEY_MINUS << 8);
                        break;
                    case 13://"ALL");
                        simulate_keypress(KEY_Y << 8);
                        break;
                    case 14://"INV");
                        simulate_keypress(KEY_U << 8);
                        break;
                    case 15://"TAB");
                        simulate_keypress(KEY_TAB << 8);
                        break;
                    case 16://"ESC");
                        simulate_keypress(KEY_ESC << 8);
                        break;
                    case 17://"ENT");
                        simulate_keypress(KEY_ENTER << 8);
                        break;
                    case 18://FULL
                        simulate_keypress(KEY_I << 8);
                        break;
                    case 19://a ZERO
                        simulate_keypress(KEY_O << 8);
                        break;
                    case 20://backspace
                        simulate_keypress(KEY_BACKSPACE << 8);
                        break;
                    case 21://DEL
                        simulate_keypress(KEY_DEL << 8);
                        break;
                    case 22://arrow Up
                        simulate_keypress(KEY_UP << 8);
                        break;
                    case 23://arrow down
                        simulate_keypress(KEY_DOWN << 8);
                        break;
                    case 24://arrow left
                        simulate_keypress(KEY_LEFT << 8);
                        break;
                    case 25://arrow right
                        simulate_keypress(KEY_RIGHT << 8);
                        break;
                    case 26://"F1");
                        simulate_keypress(KEY_F1 << 8);
                        break;
                    case 27://"F2");
                        simulate_keypress(KEY_F2 << 8);
                        break;
                    case 28://"F3");
                        simulate_keypress(KEY_F3 << 8);
                        break;
                    case 29://"F4");
                        simulate_keypress(KEY_F4 << 8);
                        break;
                    case 30://"F11");
                        simulate_keypress(KEY_F11 << 8);
                        break;
                    case 31://"F12");
                        simulate_keypress(KEY_F12 << 8);
                        break;
                    case 32://"SHFT");
                        index_false_shift=  toggle(index_false_shift);
                        index_false_control=0;
                        break;
                    case 33://"CTRL");
                        index_false_control=  toggle(index_false_control);
                        index_false_shift=0;
                        break;
                    default://
                        break;
                    }

                    reset_button(iCatPageis,bt, tp);
                }
                break;
            case 5://banger


                bangeriCat=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;

                if( bangeriCat>=0 && bangeriCat<127  )
                {
                    bang_is_sended[bangeriCat]=toggle(bang_is_sended[bangeriCat]);
                    switch (bang_is_sended[bangeriCat])
                    {
                    case 0://reset des send events et on demarre � la souris le banger
                        for (int y=0; y<6; y++)
                        {
                            event_sended[bangeriCat][y]=0;
                        }
                        start_time_for_banger[bangeriCat]=actual_time;
                        for (int y=0; y<6; y++)
                        {
                            if(bangers_delay[bangeriCat][y]> end_time_for_banger[bangeriCat])
                            {
                                end_time_for_banger[bangeriCat]= bangers_delay[bangeriCat][y];
                            }
                        }
                        if(end_time_for_banger[bangeriCat]<default_time_of_the_bang)
                        {
                            end_time_for_banger[bangeriCat]=default_time_of_the_bang;
                        }
                        last_banger_sended_manually=bangeriCat;
                        reset_button(iCatPageis,bt, tp);
                        break;
                    case 1://go back sur le banger
                        for (int y=0; y<6; y++)
                        {
                            if(bangers_type[bangeriCat][y]!=0 )
                            {
                                Bang_event_back(bangeriCat, y);
                                event_sended[bangeriCat][y]=1;
                            }
                        }
                        bang_is_sended[bangeriCat]=1;//bloquage de l envoi des autres �v�nements
                        reset_button(iCatPageis,bt, tp);
                        break;
                    default:
                        break;
                    }
                }

                break;

            case 6://icat commandes
                if(finished_to_send_orders_to_iCat==1)
                {
                    switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                    {
                    case 1://page --
                        reset_button(iCatPageis,bt, tp); //avant car on reset la donn�e du bouton par icatpageis !
                        iCatPageis--;
                        if(iCatPageis<0)
                        {
                            iCatPageis=7;
                        }
                        init_iCat_data();
                        load_iCat_page(iCatPageis);
                        do_send_icat_init_page=1;

                        /*nbrbytessendediCat=sendto(sockiCat, "clearmodels",sizeof("clearmodels"),0,(SOCKADDR*)&siniCat,sinsizeiCat); //dans routine laod avant appel du rafraichissement
                        do_refresh_iCat(iCatPageis);*/

                        break;
                    case 2://page ++
                        reset_button(iCatPageis,bt, tp);
                        iCatPageis++;
                        if(iCatPageis>7)
                        {
                            iCatPageis=0;
                        }
                        init_iCat_data();
                        load_iCat_page(iCatPageis);
                        do_send_icat_init_page=1;

                        /*nbrbytessendediCat=sendto(sockiCat, "clearmodels",sizeof("clearmodels"),0,(SOCKADDR*)&siniCat,sinsizeiCat); //dans routine laod avant appel du rafraichissement
                        do_refresh_iCat(iCatPageis);*/

                        break;
                    case 3://page num
                        reset_button(iCatPageis,bt, tp);
                        //    if(iCat_affectation_bouton_value_is[iCatPageis][bt]>0 && iCat_affectation_bouton_value_is[iCatPageis][bt]<9)
                        //

                        iCatPageis=iCat_affectation_bouton_value_is[iCatPageis][bt]-1;
                        iCatPageis=constrain_int_data_to_this_range(iCatPageis,0,7);
                        init_iCat_data();
                        load_iCat_page(iCatPageis);
                        do_send_icat_init_page=1;

                        break;
                    case 4: //refresh
                        reset_button(iCatPageis,bt, tp);
                        do_refresh_iCat(iCatPageis);
                        break;
                    case 5://page Orientation
                        reset_button(iCatPageis,bt, tp);
                        iCat_preset_orientation[iCatPageis]++;
                        if(iCat_preset_orientation[iCatPageis]>2)
                        {
                            iCat_preset_orientation[iCatPageis]=0;
                        }
                        do_refresh_iCat(iCatPageis);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 7://DRAW

                switch(iCat_affectation_bouton_action_is[iCatPageis][bt])
                {
                case 1://"Brush Type" selected
                    draw_brush_type[draw_preset_selected]=toggle(draw_brush_type[draw_preset_selected]);
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 2://draw_mode selected
                    draw_mode[draw_preset_selected]++;
                    if(draw_mode[draw_preset_selected]>3)
                    {
                        draw_mode[draw_preset_selected]=0;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 3://"Brush Type" par valeur de matrice
                    draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)]=toggle(draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)]);
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 4://draw_mode par valeur de matrice
                    draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)]++;
                    if(draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)]>3)
                    {
                        draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][bt]-1)]=0;
                    }
                    reset_button(iCatPageis,bt, tp);
                    break;
                case 5://preset matrix
                    draw_preset_selected=(iCat_affectation_bouton_value_is[iCatPageis][bt]-1);
                    recalculate_draw_sizes(draw_preset_selected);
                    reset_button(iCatPageis,bt, tp);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            /*fsBx=-999;
            fsBy=-999;
            fsMx=-999;
            fsMy=-999;
            fsEx=-999;
            fsEy=-999;
            fsTestX2=-999; fsTestY2=-999;        */
        }

        else if(button_is_touched[iCatPageis][bt]==0 && previous_button_is_touched[iCatPageis][bt]==1 && button_is_controlled_by_point[iCatPageis][bt]==tp )
        {
            if(iCat_affectation_bouton_type_is[iCatPageis][bt]==1 && iCat_affectation_bouton_action_is[iCatPageis][bt]==8)
            {
                FaderIsFlash[iCat_affectation_bouton_value_is[iCatPageis][bt]-1] =0;
            }
            if(iCat_affectation_bouton_type_is[iCatPageis][bt]==2 && iCat_affectation_bouton_action_is[iCatPageis][bt]==8)
            {
                for(int tt=0; tt<47; tt++)
                {
                    if( minifaders_selected[tt]==1 && FaderIsFlash[tt]==1 )
                    {
                        FaderIsFlash[tt]=0;
                    }
                }
            }
            reset_button(iCatPageis,bt, tp);
        }
        previous_button_is_touched[iCatPageis][bt]=button_is_touched[iCatPageis][bt];
    }


    return(0);
}
