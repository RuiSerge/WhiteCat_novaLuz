int Bang_event_back(int banger_num, int event_num)
{
    int the_fader_is=0;
    int param1_is=0;
    int param2_is=0;

    switch (bangers_type[banger_num][event_num])
    {
    case 1: //fader
        the_fader_is=bangers_params[banger_num][event_num][0]-1;
        param2_is=bangers_params[banger_num][event_num][1];


        if(the_fader_is>=0 && the_fader_is<core_user_define_nb_faders)
        {
            switch(bangers_action[banger_num][event_num])
            {
            case 0://lock
                FaderLocked[the_fader_is]=remember_state_of_banged_fader[the_fader_is][0];//lock state is
                switch(FaderLocked[the_fader_is])
                {
                case 0:
                    FaderLocked[the_fader_is]=0;
                    //remise à plat du niveau
                    Fader[the_fader_is]=(unsigned char)((((float)(StateOfFaderBeforeLock[the_fader_is]))/255)*locklevel);
                    midi_levels[the_fader_is]=(int)(((float)Fader[the_fader_is])/2);
                    break;
                case 1:
                    FaderLocked[the_fader_is]=1;
                    StateOfFaderBeforeLock[the_fader_is]=Fader[the_fader_is];
                    if(StateOfFaderBeforeLock[the_fader_is]==255)
                    {
                        LockFader_is_FullLevel[the_fader_is]=1;
                    }
                    else if(StateOfFaderBeforeLock[the_fader_is]<255)
                    {
                        LockFader_is_FullLevel[the_fader_is]=0;
                    }
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Lock Fader %d",the_fader_is+1);
                break;
            case 1://up devient down
                start_time_for_delays[the_fader_is]=actual_time;
                switch(param2_is)
                {
                case 0:
                    lfo_mode_is[the_fader_is]=0;
                    break;
                case 1:
                    lfo_mode_is[the_fader_is]=2;
                    faders_in_float[the_fader_is]=Fader[the_fader_is];
                    break;
                default:
                    break;
                }
                lfo_cycle_is_on[the_fader_is]=0;
                sprintf(string_event,"BACK:UP Fader %d",the_fader_is+1);
                break;
            case 2://down devient up
                start_time_for_delays[the_fader_is]=actual_time;
                switch(param2_is)
                {
                case 0:
                    lfo_mode_is[the_fader_is]=0;
                    break;
                case 1:
                    lfo_mode_is[the_fader_is]=1;
                    faders_in_float[the_fader_is]=Fader[the_fader_is];
                    break;
                default:
                    break;
                }
                lfo_cycle_is_on[the_fader_is]=0;
                sprintf(string_event,"BACK:Down Fader %d",the_fader_is+1);
                break;
            case 3://saw // inversion
                start_time_for_delays[the_fader_is]=actual_time;
                switch(param2_is)
                {
                case 0:
                    lfo_mode_is[the_fader_is]=0;
                    lfo_cycle_is_on[the_fader_is]=1;
                    if(Fader[the_fader_is]>0 && Fader[the_fader_is]<255 )
                    {
                        lfo_running_is_upward[the_fader_is]=1;
                    }
                    break;
                case 1:
                    lfo_cycle_is_on[the_fader_is]=0;
                    lfo_mode_is[the_fader_is]=2;//descente du fader
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Saw Fader %d",the_fader_is+1);
                break;
            case 4://to prev dock devient inversé
                switch(param2_is)
                {
                case 0:
                    lfo_do_next_step[the_fader_is][0]=1;
                    lfo_do_next_step[the_fader_is][1]=0;
                    break;
                case 1:
                    lfo_do_next_step[the_fader_is][0]=0;
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Prev Dock Fader %d",the_fader_is+1);
                break;
            case 5://to next dock
                switch(param2_is)
                {
                case 0:
                    lfo_do_next_step[the_fader_is][1]=1;
                    lfo_do_next_step[the_fader_is][0]=0;
                    break;
                case 1:
                    lfo_do_next_step[the_fader_is][1]=0;
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Next Dock Fader %d",the_fader_is+1);
                break;
            case 6://up down
                switch(param2_is)
                {
                case 0:
                    lfo_cycle_steps[the_fader_is]=1;
                    break;
                case 1:
                    lfo_cycle_steps[the_fader_is]=0;
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Up-Down Fader %d",the_fader_is+1);
                break;
            case 7://set dock  looped
                dock_selected_for_record=detect_dock_used(the_fader_is);//utilise en temporaire
                switch(param2_is)
                {
                case 0:
                    is_dock_for_lfo_selected[the_fader_is][dock_selected_for_record]=1;
                    break;
                case 1:
                    is_dock_for_lfo_selected[the_fader_is][dock_selected_for_record]=0;
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:Dock looped Fader %d",the_fader_is+1);
                break;
            case 8://set all looped
                switch(param2_is)
                {
                case 0:
                    for(int p=0; p<core_user_define_nb_docks; p++)
                    {
                        is_dock_for_lfo_selected[the_fader_is][p]=1;
                    }
                    break;
                case 1:
                    for(int p=0; p<core_user_define_nb_docks; p++)
                    {
                        is_dock_for_lfo_selected[the_fader_is][p]=0;
                    }
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:All Looped Fader %d",the_fader_is+1);
                break;
            case 9://set dock selected is
                if(param2_is>0 && param2_is<7)
                {
                    DockIsSelected[the_fader_is][remember_state_of_banged_fader[the_fader_is][2]]=1;
                    Unselect_other_docks(the_fader_is, (remember_state_of_banged_fader[the_fader_is][2]));
                }
                sprintf(string_event,"BACK:Select dock Fader %d",the_fader_is+1);
                break;
            case 10://set LFO at
                lfo_speed[the_fader_is]=remember_state_of_banged_fader[the_fader_is][3];
                midi_levels[196+the_fader_is]=remember_state_of_banged_fader[the_fader_is][3];
                index_send_midi_out[196+the_fader_is]=1;

                if(DockTypeIs[the_fader_is][dock_used_by_fader_is[the_fader_is]]==12)//enchassement Grid si slave
                {
                    asservissement_gridplayer(the_fader_is,dock_used_by_fader_is[the_fader_is]);
                }
                sprintf(string_event,"BACK:Set Speed Fader %d",the_fader_is+1);
                break;

            case 11://set Fader At
                int niv_transforme;
                switch( dmx_view)
                {
                case 0:
                    if(remember_state_of_banged_fader[the_fader_is][1]>=0 && remember_state_of_banged_fader[the_fader_is][1]<=100)
                    {
                        niv_transforme=(int)((float)(remember_state_of_banged_fader[the_fader_is][1])*2.55);
                        if(param2_is==100)
                        {
                            niv_transforme=255;
                        }
                    }
                    break;
                case 1:
                    if(remember_state_of_banged_fader[the_fader_is][1]>=0 && remember_state_of_banged_fader[the_fader_is][1]<=255)
                    {
                        niv_transforme=remember_state_of_banged_fader[the_fader_is][1];
                    }
                    break;
                default:
                    break;
                }
                /*Fader[the_fader_is]= niv_transforme;
                midi_levels[the_fader_is]= niv_transforme/2;
                index_send_midi_out[the_fader_is]=1;*/
                fader_set_level(the_fader_is,niv_transforme);

                if(lfo_mode_is[the_fader_is]==1 || lfo_mode_is[the_fader_is]==2 || lfo_cycle_is_on[the_fader_is]==1)
                {
                    lfo_mode_is[the_fader_is]=0;
                    lfo_mode_is[the_fader_is]=0;
                    lfo_cycle_is_on[the_fader_is]=0;
                }
                sprintf(string_event,"BACK:Set Fader %d",the_fader_is+1);
                break;

            case 12://end pos pour auto mouvement
                StopPosOn[the_fader_is]=1;
                LevelStopPos[the_fader_is]=PreviousLevelStopPos[the_fader_is];
                do_light_setpos[the_fader_is]=1;
                sprintf(string_event,"BACK:SetStopPos at %d Fader %d",PreviousLevelStopPos[the_fader_is],the_fader_is+1);
                break;

            case 13://on off end pos
                if(param2_is==0 || param2_is==1)
                {
                    ActionnateStopOn[the_fader_is]=toggle(param2_is);
                    do_light_setpos[the_fader_is]=1;
                    switch(param2_is)
                    {
                    case 0:
                        sprintf(string_event,"BACK: ENDPOS ON Fader %d",the_fader_is+1);
                        break;
                    case 1:
                        sprintf(string_event,"BACK: ENDPOS OFF Fader %d",the_fader_is+1);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 14://paste to stage output of faders annulé et récup de l etat de la memoire
                //no back up
                sprintf(string_event,"NO BACK: Paste Fader %d",the_fader_is+1);
                break;
            case 15://set midi out inversee
                switch(param2_is)
                {
                case 0:
                    midi_send_out[the_fader_is]=1;
                    break;
                case 1:
                    midi_send_out[the_fader_is]=0;
                    break;
                default:
                    break;
                }
                sprintf(string_event,"BACK:MidiOut Fader %d",the_fader_is+1);
                break;
            case 16://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 17://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 18://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 19://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 20://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 21://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 22://recall back
                do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                                       stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
                break;
            case 23: // recall n a pas de back
                break;
            case 24://LOCKS PRESET inversé
                param1_is=bangers_params[banger_num][event_num][0]-1;
                do_lock_preset(param1_is);
                break;
            case 25://assign curve  back
                FaderCurves[the_fader_is]=before_bang_FaderCurves[the_fader_is];//pour go back
                sprintf(string_event,"BACK: Fader %d Curve %d",the_fader_is+1,FaderCurves[the_fader_is]+1);
                break;
            case 26://load chaser in activ dock PAS DE BACK
                break;
            case 27://play chaser in activ dock
                if( param2_is==0 || param2_is==1)
                {
                    if(DockTypeIs[the_fader_is][(dock_used_by_fader_is[the_fader_is])]==11)
                    {
                        chaser_is_playing[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])]=1-param2_is;
                        switch(param2_is)
                        {
                        case 0:
                            sprintf(string_event,"BACK: PLAY Chaser %d in Fader %d Dock %d ",ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])], the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                            break;
                        case 1:
                            sprintf(string_event,"BACK: STOP Chaser %d in Fader %d Dock %d ",ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])], the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        sprintf(string_event,"BACK: No Chaser loaded in Fader %d Dock %d ", the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                    }
                }
                else
                {
                    sprintf(string_event,"Play Chaser entry must be 0 or 1s");
                }
                break;
            case 28://seek chaser in activ dock
                if(DockTypeIs[the_fader_is][(dock_used_by_fader_is[the_fader_is])]==11)
                {
                    index_progression_chaser_step[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])]=previous_index_progression_chaser_step[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])];
                    chaser_step_is[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])]=previous_chaser_step_is[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])];
                    sprintf(string_event,"BACK: Seek At Beg Chaser %d in Fader %d Dock %d ",ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])], the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                }
                else
                {
                    sprintf(string_event,"BACK: No Chaser loaded in Fader %d Dock %d ", the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                }
                break;
            case 29://loop chaserin activ dock
                if( param2_is==0 || param2_is==1)
                {
                    if(DockTypeIs[the_fader_is][(dock_used_by_fader_is[the_fader_is])]==11)
                    {
                        chaser_is_in_loop[(ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])])]=1-param2_is;
                        switch(param2_is)
                        {
                        case 0:
                            sprintf(string_event,"BACK: LOOP ON Chaser %d in Fader %d Dock %d ",ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])], the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                            break;
                        case 1:
                            sprintf(string_event,"BACK: LOOP OFF Chaser %d in Fader %d Dock %d ",ChaserAffectedToDck[the_fader_is][(dock_used_by_fader_is[param1_is])], the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        sprintf(string_event,"BACK: No Chaser loaded in Fader %d Dock %d ", the_fader_is+1,dock_used_by_fader_is[param1_is]+1);
                    }
                }
                else
                {
                    sprintf(string_event,"BACK: LOOP Chaser entry must be 0 or 1");
                }
                break;

            default:
                break;

            }
            break;
        case 2: //midi send
            param1_is=bangers_params[banger_num][event_num][0];
            param2_is=bangers_params[banger_num][event_num][1];
            if((param1_is>=0 && param1_is<=15 ) && (param2_is>=0 && param2_is<=127))
            {
                switch(bangers_action[banger_num][event_num])
                {
                case 0://key on 127
                    switch (cheat_key_off)
                    {
                    case 0:
                        send_my_midi_note( 2,  param1_is, param2_is, 127, 10);//velocite / duree
                        break;
                    case 1:
                        send_my_midi_note( 1,  param1_is, param2_is, 0, 10);//velocite / duree
                        break;
                    default:
                        break;
                    }
                    sprintf(string_event,"BACK:key-on Ch:%d P:%d V:127",param1_is,param2_is);
                    break;
                case 1://key on 0
                    send_my_midi_note( 1,  param1_is, param2_is, 127, 10);//velocite / duree
                    printf(string_event,"BACK:key-on Ch:%d P:%d V:0",param1_is,param2_is);
                    break;
                case 2://key off
                    send_my_midi_note( 1,  param1_is, param2_is, 127, 10);//velocite / duree
                    sprintf(string_event,"BACK:key-on Ch:%d P:%d V:127",param1_is,param2_is);
                    break;
                case 3://Ctrl-Change 127
                    send_my_midi_note( 4,  param1_is, param2_is, 0, 10);//velocite / duree
                    sprintf(string_event,"BACK:ctrl-change Ch:%d P:%d V:0",param1_is,param2_is);
                    break;
                case 4://Ctrl-Change 0
                    send_my_midi_note( 4,  param1_is, param2_is, 127, 10);//velocite / duree
                    sprintf(string_event,"BACK:ctrl-change Ch:%d P:%d V:127",param1_is,param2_is);
                    break;
                default:
                    break;
                }
            }
            break;
        case 3:

            param1_is=bangers_params[banger_num][event_num][0];
            param2_is=bangers_params[banger_num][event_num][1];

            switch(bangers_action[banger_num][event_num])
            {

            case 1://seq BACK
                if(param2_is==1)
                {
                    add_a_window(W_SEQUENCIEL);
                    sprintf(string_event,"BACK: Sequences Window /ON");
                }
                else
                {
                    substract_a_window(W_SEQUENCIEL);
                    sprintf(string_event,"BACK: Sequences Window /OFF");
                }
                break;


            case 2://faders BACK
                //-50 parrapport au code des affichages
                if(param1_is>0 && param1_is<7)
                {
                    goto_scroll_faderspace=15;
                }
                else if(param1_is>6 && param1_is<13)
                {
                    goto_scroll_faderspace=127;
                }
                else if(param1_is>12 && param1_is<19)
                {
                    goto_scroll_faderspace=236;
                }
                else if(param1_is>18 && param1_is<25)
                {
                    goto_scroll_faderspace=345;
                }
                else if(param1_is>24 && param1_is<31)
                {
                    goto_scroll_faderspace=454;
                }
                else if(param1_is>30 && param1_is<37)
                {
                    goto_scroll_faderspace=563;
                }
                else if(param1_is>36 && param1_is<43)
                {
                    goto_scroll_faderspace=672;
                }
                else if(param1_is>42 && param1_is<49)
                {
                    goto_scroll_faderspace=782;
                }

                if(param2_is==1)
                {
                    add_a_window(W_FADERS);
                    sprintf(string_event,"BACK: Faders space/ seeing Fader %d /ON",param1_is);
                }
                else
                {
                    substract_a_window(W_FADERS);
                    sprintf(string_event,"BACK :Faders space/ seeing Fader Dock %d /OFF",param1_is);
                }
                break;

            case 3://minifaders
                if(param2_is==1)
                {
                    add_a_window(W_MINIFADERS);
                    sprintf(string_event,"BACK: MiniFaders /ON");
                }
                else
                {
                    substract_a_window(W_MINIFADERS);
                    sprintf(string_event,"BACK :MiniFaders space /OFF");
                }
                break;

            case 4://banger BACK
                if (param1_is>0 && param1_is<128)
                {
                    index_banger_selected=param1_is-1;
                }
                if(param2_is==1)
                {
                    add_a_window(W_BANGER);
                    sprintf(string_event,"BACK: Banger Window/ /OFF");
                }
                else
                {
                    substract_a_window(W_BANGER);
                    sprintf(string_event,"BACK: Banger Window/ /ON");
                }
                break;

            case 5://audio
                if(param2_is==1)
                {
                    add_a_window(W_AUDIO);
                    sprintf(string_event,"BACK: Audio Window /ON");
                }
                else
                {
                    substract_a_window(W_AUDIO);
                    sprintf(string_event,"BACK: Audio Window /OFF");
                }
                break;

            case 6://time
                if(param2_is==1)
                {
                    add_a_window(W_TIME);
                    sprintf(string_event,"BACK: Audio Time /ON");
                }
                else
                {
                    substract_a_window(W_TIME);
                    sprintf(string_event,"BACK: Time Window /OFF");
                }
                break;

            case 7://audio
                if(param2_is==1)
                {
                    add_a_window(W_PLOT);
                    sprintf(string_event,"BACK: Plot Window /ON");
                }
                else
                {
                    substract_a_window(W_PLOT);
                    sprintf(string_event,"BACK: Plot Window /OFF");
                }
                break;

            case 8://audio
                if(param2_is==1)
                {
                    add_a_window(W_LIST);
                    sprintf(string_event,"BACK: LIST Window /ON");
                }
                else
                {
                    substract_a_window(W_LIST);
                    sprintf(string_event,"BACK: List Window /OFF");
                }
                break;

            case 9://trichro BACK
                if(param2_is==1)
                {

                    dock_color_selected=previous_preset_color;

                    add_a_window(W_TRICHROMY);
                    load_etat_picker_dans_dockcolor(dock_color_selected);
                    sprintf(string_event,"BACK: Trichowindow/ ColorPreset %d /ON",dock_color_selected);
                }
                else
                {
                    dock_color_selected=previous_preset_color;
                    substract_a_window(W_TRICHROMY);
                    load_etat_picker_dans_dockcolor(dock_color_selected);
                    sprintf(string_event,"BACK: Trichowindow/ ColorPreset %d /OFF",dock_color_selected);
                }
                break;

            case 10://videotracking BACK
                if(param2_is==1)
                {
                    tracking_dock_selected=previous_preset_video;
                    add_a_window(W_TRACKINGVIDEO);
                    sprintf(string_event,"BACK: Tracking Video/ Tracking Dock %d, /ON",previous_preset_video);
                }
                else
                {
                    tracking_dock_selected=previous_preset_video;
                    substract_a_window(W_TRACKINGVIDEO);
                    sprintf(string_event,"BACK: Tracking Video/ Tracking Dock %d /OFF",previous_preset_video);
                }
                break;

            case 11://chasers
                if(param2_is==1)
                {
                    add_a_window(W_CHASERS);
                    sprintf(string_event,"BACK: Chasers Window /ON");
                }
                else
                {
                    substract_a_window(W_CHASERS);
                    sprintf(string_event,"BACK: Chasers Window /OFF");
                }
                break;

            case 12://Gridplayers
                if(param2_is==1)
                {
                    add_a_window(W_GRID);
                    sprintf(string_event,"BACK: Gridplayers Window /ON");
                }
                else
                {
                    substract_a_window(W_GRID);
                    sprintf(string_event,"BACK: Gridplayers Window /OFF");
                }
                break;

            case 13://Draw
                if(param2_is==1)
                {
                    add_a_window(W_DRAW);
                    sprintf(string_event,"BACK: Draw Window /ON");
                }
                else
                {
                    substract_a_window(W_DRAW);
                    sprintf(string_event,"BACK: Draw Window /OFF");
                }
                break;


            case 14://Echo
                if(param2_is==1)
                {
                    add_a_window(W_ECHO);
                    sprintf(string_event,"BACK: Echo Window /ON");
                }
                else
                {
                    substract_a_window(W_ECHO);
                    sprintf(string_event,"BACK: Echo Window /OFF");
                }
                break;

            case 15://mover
                if(param2_is==1)
                {
                    add_a_window(W_MOVER);
                    sprintf(string_event,"BACK: Mover Window /ON");
                }
                else
                {
                    substract_a_window(W_AUDIO);
                    sprintf(string_event,"BACK: AudioMover Window /OFF");
                }
                break;

            case 16://numpad
                if(param2_is==1)
                {
                    add_a_window(W_NUMPAD);
                    sprintf(string_event,"BACK: NumPad Window /ON");
                }
                else
                {
                    substract_a_window(W_NUMPAD);
                    sprintf(string_event,"BACK: NumPadWindow /OFF");
                }
                break;

            case 17://cfg
                if(param2_is==1)
                {
                    add_a_window(W_CFGMENU);
                    sprintf(string_event,"BACK: CFG Window /ON");
                }
                else
                {
                    substract_a_window(W_CFGMENU);
                    sprintf(string_event,"BACK: CFG Window /OFF");
                }
                break;

            case 18://icat
                if(param2_is==1)
                {
                    add_a_window(W_iCAT);
                    sprintf(string_event,"BACK: iCAT Window /ON");
                }
                else
                {
                    substract_a_window(W_iCAT);
                    sprintf(string_event,"BACK: iCAT Window /OFF");
                }
                break;

            default:
                break;
            }
            break;
        case 4:
            param2_is=bangers_params[banger_num][event_num][1];
            switch(param2_is)
            {
            case 0:
                add_a_window(W_ALARM);
                sprintf(string_event,"BACK: Alarm /ON");
                break;
            case 1:
                sprintf(string_THE_alarm,string_alarm[banger_num]);
                index_alarm_from_banger_num=banger_num;
                substract_a_window(W_ALARM);
                sprintf(string_event,"BACK: Alarm /OFF");
                break;
            default:
                break;
            }
            break;
        case 5: //param 1 player param 2 action 0 1
            param1_is=bangers_params[banger_num][event_num][0]-1;
            param2_is=bangers_params[banger_num][event_num][1];
            if(param1_is>=0 && param1_is<4)//etait 5 ! aout 2016
            {
                switch(bangers_action[banger_num][event_num])
                {
                case 0: //back de clear audio player
                    switch(param1_is)//lecteur
                    {
                    case 0:
                        //rechargement du previous fichier
                        sprintf(audiofile_name,audiofile_name_was[param1_is]);
                        AffectSoundFile(param1_is);
                        if(player_ignited[param1_is]==1)
                        {
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[616+param1_is]=audio_volume_was[param1_is];
                            player1->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[616+param1_is]==1)
                            {
                                index_send_midi_out[616+param1_is]=1;   //VOL
                            }

                            player_pan[param1_is]=audio_pan_was[param1_is];
                            midi_levels[620+param1_is]=audio_pan_was[param1_is];
                            player1->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[620+param1_is]==1)
                            {
                                index_send_midi_out[620+param1_is]=1;   //PAN
                            }

                            player_pitch[param1_is]=audio_pitch_was[param1_is];
                            midi_levels[624+param1_is]=audio_pitch_was[param1_is];
                            player1->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[624+param1_is]==1)
                            {
                                index_send_midi_out[624+param1_is]=1;   //PICTH
                            }

                            player1->setPosition(audio_position_was[param1_is]);

                            player_seek_position[param1_is]=audio_cue_in_was[param1_is];
                            player_loop_out_position[param1_is]=audio_cue_out_was[param1_is];

                            if(player_was_playing[param1_is]==1)
                            {
                                player1->play();
                                player_is_playing[param1_is]=(player1->isPlaying());
                            }
                            if(player_was_onloop[param1_is]==1)
                            {
                                player1->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                            }
                            else if(player_was_onloopCue[param1_is]==1)
                            {
                                player1->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                            }
                        }
                        break;
                    case 1:
                        //rechargement du previous fichier
                        sprintf(audiofile_name,audiofile_name_was[param1_is]);
                        AffectSoundFile(param1_is);
                        if(player_ignited[param1_is]==1)
                        {
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[616+param1_is]=audio_volume_was[param1_is];
                            player2->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[616+param1_is]==1)
                            {
                                index_send_midi_out[616+param1_is]=1;   //VOL
                            }

                            player_pan[param1_is]=audio_pan_was[param1_is];
                            midi_levels[620+param1_is]=audio_pan_was[param1_is];
                            player2->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[620+param1_is]==1)
                            {
                                index_send_midi_out[620+param1_is]=1;   //PAN
                            }

                            player_pitch[param1_is]=audio_pitch_was[param1_is];
                            midi_levels[624+param1_is]=audio_pitch_was[param1_is];
                            player2->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[624+param1_is]==1)
                            {
                                index_send_midi_out[624+param1_is]=1;   //PICTH
                            }

                            player2->setPosition(audio_position_was[param1_is]);

                            player_seek_position[param1_is]=audio_cue_in_was[param1_is];
                            player_loop_out_position[param1_is]=audio_cue_out_was[param1_is];

                            if(player_was_playing[param1_is]==1)
                            {
                                player2->play();
                                player_is_playing[param1_is]=(player2->isPlaying());
                            }
                            if(player_was_onloop[param1_is]==1)
                            {
                                player2->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                            }
                            else if(player_was_onloopCue[param1_is]==1)
                            {
                                player2->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                            }
                        }
                        break;
                    case 2:
                        //rechargement du previous fichier
                        sprintf(audiofile_name,audiofile_name_was[param1_is]);
                        AffectSoundFile(param1_is);
                        if(player_ignited[param1_is]==1)
                        {
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[616+param1_is]=audio_volume_was[param1_is];
                            player3->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[616+param1_is]==1)
                            {
                                index_send_midi_out[616+param1_is]=1;   //VOL
                            }

                            player_pan[param1_is]=audio_pan_was[param1_is];
                            midi_levels[620+param1_is]=audio_pan_was[param1_is];
                            player3->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[620+param1_is]==1)
                            {
                                index_send_midi_out[620+param1_is]=1;   //PAN
                            }

                            player_pitch[param1_is]=audio_pitch_was[param1_is];
                            midi_levels[624+param1_is]=audio_pitch_was[param1_is];
                            player3->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[624+param1_is]==1)
                            {
                                index_send_midi_out[624+param1_is]=1;   //PICTH
                            }

                            player3->setPosition(audio_position_was[param1_is]);

                            player_seek_position[param1_is]=audio_cue_in_was[param1_is];
                            player_loop_out_position[param1_is]=audio_cue_out_was[param1_is];

                            if(player_was_playing[param1_is]==1)
                            {
                                player3->play();
                                player_is_playing[param1_is]=(player3->isPlaying());
                            }
                            if(player_was_onloop[param1_is]==1)
                            {
                                player3->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                            }
                            else if(player_was_onloopCue[param1_is]==1)
                            {
                                player3->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                            }
                        }
                        break;
                    case 3:
                        //rechargement du previous fichier
                        sprintf(audiofile_name,audiofile_name_was[param1_is]);
                        AffectSoundFile(param1_is);
                        if(player_ignited[param1_is]==1)
                        {
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[616+param1_is]=audio_volume_was[param1_is];
                            player4->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[616+param1_is]==1)
                            {
                                index_send_midi_out[616+param1_is]=1;   //VOL
                            }

                            player_pan[param1_is]=audio_pan_was[param1_is];
                            midi_levels[620+param1_is]=audio_pan_was[param1_is];
                            player4->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[620+param1_is]==1)
                            {
                                index_send_midi_out[620+param1_is]=1;   //PAN
                            }

                            player_pitch[param1_is]=audio_pitch_was[param1_is];
                            midi_levels[624+param1_is]=audio_pitch_was[param1_is];
                            player4->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[624+param1_is]==1)
                            {
                                index_send_midi_out[624+param1_is]=1;   //PICTH
                            }

                            player4->setPosition(audio_position_was[param1_is]);

                            player_seek_position[param1_is]=audio_cue_in_was[param1_is];
                            player_loop_out_position[param1_is]=audio_cue_out_was[param1_is];

                            if(player_was_playing[param1_is]==1)
                            {
                                player4->play();
                                player_is_playing[param1_is]=(player4->isPlaying());
                            }
                            if(player_was_onloop[param1_is]==1)
                            {
                                player4->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                            }
                            else if(player_was_onloopCue[param1_is]==1)
                            {
                                player4->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                            }
                        }
                        break;
                    default:
                        break;
                    }


                    sprintf(string_event,"BACK: Reloaded the Cleared Player %d",param1_is);
                    break;
                case 1:
                    //sprintf(bangers_type_action,"Load in Player");
                    sprintf(audiofile_name,audiofile_name_was[param1_is]);
                    AffectSoundFile(param1_is);
                    sprintf(string_event,"BACK:Affected Audio %d to Player 1",param2_is);
                    break;

                case 2://play pause
                    //sprintf(bangers_type_action,"SetPlay Player");
                    switch(param1_is)//lecteur
                    {
                    case 0:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player1_do_stop();
                                player_is_playing[param1_is]=(player1->isPlaying());
                                sprintf(string_event,"BACK: Player 1 STOP");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player1->play();
                                player_is_playing[param1_is]=(player1->isPlaying());
                                sprintf(string_event,"BACK: Player 1 PLAY");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 1:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player2_do_stop();
                                player_is_playing[param1_is]=(player2->isPlaying());
                                sprintf(string_event,"BACK: Player 2 STOP");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player2->play();
                                player_is_playing[param1_is]=(player2->isPlaying());
                                sprintf(string_event,"BACK: Player 2 PLAY");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 2:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player3_do_stop();
                                player_is_playing[param1_is]=(player3->isPlaying());
                                sprintf(string_event,"BACK: Player 3 STOP");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player3->play();
                                player_is_playing[param1_is]=(player3->isPlaying());
                                sprintf(string_event,"BACK: Player 3 PLAY");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 3:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player4_do_stop();
                                player_is_playing[param1_is]=(player4->isPlaying());
                                sprintf(string_event,"BACK: Player 4 STOP");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player4->play();
                                player_is_playing[param1_is]=(player4->isPlaying());
                                sprintf(string_event,"BACK: Player 4 PLAY");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case 3:
                    //BACK load and play

                    switch(param1_is)//lecteur
                    {
                    case 0:

                        if(player_ignited[param1_is]==1)
                        {
                            player1_do_stop();
                            player_is_playing[param1_is]=(player1->isPlaying());
                            sprintf(string_event,"BACK: Player 1 STOP");
                        }
                        break;

                    case 1:

                        if(player_ignited[param1_is]==1)
                        {
                            player2_do_stop();
                            player_is_playing[param1_is]=(player2->isPlaying());
                            sprintf(string_event,"BACK: Player 2 STOP");
                        }
                        break;
                    case 2:

                        if(player_ignited[param1_is]==1)
                        {
                            player3_do_stop();
                            player_is_playing[param1_is]=(player3->isPlaying());
                            sprintf(string_event,"BACK: Player 3 STOP");
                        }
                        break;
                    case 3:

                        if(player_ignited[param1_is]==1)
                        {
                            player4_do_stop();
                            player_is_playing[param1_is]=(player4->isPlaying());
                            sprintf(string_event,"BACK: Player 4 STOP");
                        }
                        break;
                    default:
                        break;
                    }

                    //reload
                    sprintf(audiofile_name,audiofile_name_was[param1_is]);
                    AffectSoundFile(param1_is);




                    break;
                case 4:

                    switch(param1_is)//lecteur
                    {
                    case 0:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player1->setRepeat(false);
                                player_is_onloop[param1_is]=0;
                                sprintf(string_event,"BACK: Player 1 Loop OFF");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player1->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                                sprintf(string_event,"BACK: Player 1 Loop ON");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 1:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player2->setRepeat(false);
                                player_is_onloop[param1_is]=0;
                                sprintf(string_event,"BACK: Player 2 Loop OFF");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player2->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                                sprintf(string_event,"BACK: Player 2 Loop ON");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 2:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player3->setRepeat(false);
                                player_is_onloop[param1_is]=0;
                                sprintf(string_event,"BACK: Player 3 Loop OFF");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player3->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                                sprintf(string_event,"BACK: Player 3 Loop ON");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case 3:
                        switch(param2_is)
                        {
                        case 1:
                            if(player_ignited[param1_is]==1)
                            {
                                player4->setRepeat(false);
                                player_is_onloop[param1_is]=0;
                                sprintf(string_event,"BACK: Player 4 Loop OFF");
                            }
                            break;
                        case 0:
                            if(player_ignited[param1_is]==1)
                            {
                                player4->setRepeat(true);
                                player_is_onloop[param1_is]=1;
                                sprintf(string_event,"BACK: Player 4 Loop ON");
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }

                    break;
                case 5:
                    //sprintf(bangers_type_action,"Seek Player");
                    switch(param1_is)//lecteur
                    {
                    case 0:
                        if(player_ignited[param1_is]==1)
                        {
                            player1->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 1 SeekToZero");
                        }
                        break;
                    case 1:
                        if(player_ignited[param1_is]==1)
                        {
                            player3->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 2 SeekToZero");
                        }
                        break;
                    case 2:
                        if(player_ignited[param1_is]==1)
                        {
                            player3->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 3 SeekToZero");
                        }
                        break;
                    case 3:
                        if(player_ignited[param1_is]==1)
                        {
                            player4->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 4 SeekToZero");
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case 6:
                    //sprintf(bangers_type_action,"SetVolume Player");
                    if(player_ignited[param1_is]==1 && param2_is<128 && param2_is>=0)
                    {
                        switch(param1_is)
                        {
                        case 0:
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[616]=audio_volume_was[param1_is];
                            player1->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[616]==1)
                            {
                                index_send_midi_out[616]=1;   //vol
                            }
                            sprintf(string_event,"BACK: Player 1 SetVolume at %d", audio_volume_was[param1_is]);
                            break;
                        case 1:
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[617]=audio_volume_was[param1_is];
                            player2->setVolume(((float)player_niveauson[param1_is])/127);
                            if(midi_send_out[617]==1)
                            {
                                index_send_midi_out[617]=1;   //vol
                            }
                            sprintf(string_event,"BACK: Player 2 SetVolume at %d", audio_volume_was[param1_is]);
                            break;
                        case 2:
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[618]=audio_volume_was[param1_is];
                            if(midi_send_out[618]==1)
                            {
                                index_send_midi_out[618]=1;   //vol
                            }
                            player3->setVolume(((float)player_niveauson[param1_is])/127);
                            sprintf(string_event,"BACK: Player 3 SetVolume at %d", audio_volume_was[param1_is]);
                            break;
                        case 3:
                            player_niveauson[param1_is]=audio_volume_was[param1_is];
                            midi_levels[619]=audio_volume_was[param1_is];
                            if(midi_send_out[619]==1)
                            {
                                index_send_midi_out[619]=1;   //vol
                            }
                            player4->setVolume(((float)player_niveauson[param1_is])/127);
                            sprintf(string_event,"BACK: Player 4 SetVolume at %d", audio_volume_was[param1_is]);
                            break;
                        default:
                            break;
                        }
                    }

                    break;
                case 7:
                    //sprintf(bangers_type_action,"Set Cue Player");
                    if(player_ignited[param1_is]==1)
                    {
                        switch(param1_is)
                        {
                        case 0://PLAYER 1
                            switch(param2_is)
                            {
                            case 1:
                                player1->setRepeat(false);
                                player_is_onloopCue[param1_is]=0;
                                sprintf(string_event,"BACK: Player 1 CUE OFF");
                                break;
                            case 0:
                                player1->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                                sprintf(string_event,"BACK: Player 1 CUE ON");
                                break;
                            default:
                                break;
                            }
                            break;
                        case 1://PLAYER 2
                            switch(param2_is)
                            {
                            case 1:
                                player2->setRepeat(false);
                                player_is_onloopCue[param1_is]=0;
                                sprintf(string_event,"BACK: Player 2 CUE OFF");
                                break;
                            case 0:
                                player2->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                                sprintf(string_event,"BACK: Player 2 CUE ON");
                                break;
                            default:
                                break;
                            }
                            break;
                        case 2://PLAYER 3
                            switch(param2_is)
                            {
                            case 1:
                                player3->setRepeat(false);
                                player_is_onloopCue[param1_is]=0;
                                sprintf(string_event,"BACK: Player 3 CUE OFF");
                                break;
                            case 0:
                                player3->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                                sprintf(string_event,"BACK: Player 3 CUE ON");
                                break;
                            default:
                                break;
                            }
                            break;
                        case 3://PLAYER 4
                            switch(param2_is)
                            {
                            case 1:
                                player4->setRepeat(false);
                                player_is_onloopCue[param1_is]=0;
                                sprintf(string_event,"BACK: Player 4 CUE OFF");
                                break;
                            case 0:
                                player4->setRepeat(true);
                                player_is_onloopCue[param1_is]=1;
                                sprintf(string_event,"Player 4 CUE ON");
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 8:
                    //sprintf(bangers_type_action,"Seek to CueIn Pl.");
                    if(player_ignited[param1_is]==1 && param2_is==1)//christoph 03/12/14
                    {
                        switch(param1_is)
                        {

                        case 0://PLAYER 1
                            player1->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 1 SeekToCueIn");
                            break;
                        case 1://PLAYER 2
                            player2->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 2 SeekToCueIn");
                            break;
                        case 2://PLAYER 3
                            player3->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 3 SeekToCueIn");
                            break;
                        case 3://PLAYER 4
                            player4->setPosition(audio_position_was[param1_is]);
                            sprintf(string_event,"BACK: Player 4 SeekToCueIn");
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 9:
                    //sprintf(bangers_type_action,"SetPan Player");
                    if(player_ignited[param1_is]==1 && param2_is<128 && param2_is>=0)
                    {
                        param2_is=audio_pan_was[param1_is];
                        switch(param1_is)
                        {
                        case 0:
                            player_pan[param1_is]=param2_is;
                            midi_levels[620]=param2_is;
                            player1->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[620]==1)
                            {
                                index_send_midi_out[620]=1;   //PAN
                            }
                            sprintf(string_event,"BACK: Player 1 SetPan at %d",param2_is);
                            break;
                        case 1:
                            player_pan[param1_is]=param2_is;
                            midi_levels[621]=param2_is;
                            player2->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[621]==1)
                            {
                                index_send_midi_out[621]=1;   //PAN
                            }
                            sprintf(string_event,"BACK: Player 2 SetPan at %d",param2_is);
                            break;
                        case 2:
                            player_pan[param1_is]=param2_is;
                            midi_levels[622]=param2_is;
                            player3->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[622]==1)
                            {
                                index_send_midi_out[622]=1;   //PAN
                            }
                            sprintf(string_event,"BACK: Player 3 SetPan at %d",param2_is);
                            break;
                        case 3:
                            player_pan[param1_is]=param2_is;
                            midi_levels[623]=param2_is;
                            player4->setPan(((float)player_pan[param1_is])/127);
                            if(midi_send_out[623]==1)
                            {
                                index_send_midi_out[623]=1;   //PAN
                            }
                            sprintf(string_event,"BACK: Player 4 SetPan at %d",param2_is);
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 10:
                    //sprintf(bangers_type_action,"SetPitch Player");
                    if(player_ignited[param1_is]==1 && param2_is<128 && param2_is>=0)
                    {
                        param2_is=audio_pitch_was[param1_is];
                        switch(param1_is)
                        {
                        case 0:
                            player_pitch[param1_is]=param2_is;
                            midi_levels[624]=param2_is;
                            player1->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[624]==1)
                            {
                                index_send_midi_out[624]=1;   //PICTH
                            }
                            sprintf(string_event,"BACK: Player 1 SetPitch at %d",param2_is);
                            break;
                        case 1:
                            player_pitch[param1_is]=param2_is;
                            midi_levels[625]=param2_is;
                            player2->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[625]==1)
                            {
                                index_send_midi_out[625]=1;   //PICTH
                            }
                            sprintf(string_event,"BACK: Player 2 SetPitch at %d",param2_is);
                            break;
                        case 2:
                            player_pitch[param1_is]=param2_is;
                            midi_levels[626]=param2_is;
                            player3->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[626]==1)
                            {
                                index_send_midi_out[626]=1;   //PICTH
                            }
                            sprintf(string_event,"BACK: Player 3 SetPitch at %d",param2_is);
                            break;
                        case 3:
                            player_pitch[param1_is]=param2_is;
                            midi_levels[627]=param2_is;
                            player4->setPitchShift(((float)player_pitch[param1_is])/127);
                            if(midi_send_out[627]==1)
                            {
                                index_send_midi_out[627]=1;   //PICTH
                            }
                            sprintf(string_event,"BACK: Player 4 SetPitch at %d",param2_is);
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 11:
                    //sprintf(bangers_type_action,"SetMidiOut Player");
                    midi_send_out[616+param1_is]=toggle(param2_is);
                    midi_send_out[620+param1_is]=toggle(param2_is);
                    midi_send_out[624+param1_is]=toggle(param2_is);
                    switch(midi_send_out[616+param1_is])
                    {
                    case 0:
                        sprintf(string_event,"BACK: Player %d SetMidiOut OFF",param1_is);
                        break;
                    case 1:
                        sprintf(string_event,"BACK: Player %d SetMidiOut ON",param1_is);
                        break;
                    default:
                        break;
                    }
                    break;
                }
            }
            break;
        default:
            break;
            sprintf(string_Last_Order,">> Banged %d Event %d %s", banger_num+1, event_num+1, string_event);

        }

    }
    return(0);

}
