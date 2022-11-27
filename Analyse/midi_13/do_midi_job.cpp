int do_midi_job(int control)
{

    if(control<=47)
    {
        if((FaderLocked[control]==1 && LockFader_is_FullLevel[control]==1)|| (FaderLocked[control]==0 ))
        {

            if(midi_levels[control]==127)
            {
                fader_set_level(control,255);   //pour mettre � full
            }
            else
            {
                fader_set_level(control,midi_levels[control]*2);
            }
        }
    }

    if(lfo_mode_is[control]==1 || lfo_mode_is[control]==2 || lfo_cycle_is_on[control]==1)
    {
        lfo_mode_is[control]=0;
        lfo_mode_is[control]=0;
        lfo_cycle_is_on[control]=0;
    }
    if(control>=48 && control <96 )
    {

        int dockused=detect_dock_used(control-48);
        DockIsSelected[control-48][dockused]=0;
        if (dockused>0)
        {
            DockIsSelected[control-48][dockused]=0;
            dockused--;
            DockIsSelected[control-48][dockused]=1;
        }
        else if (dockused==0)
        {
            DockIsSelected[control-48][dockused]=0;
            dockused=5;//6 docks pos 5
            DockIsSelected[control-48][dockused]=1;
        }
        /* if( enable_launchpad==1)
         {launchpad_impulsion(control,orange);}*/
        rest(midi_keyboard_wait);

    }

    if(control>=96 && control <144 )//etait 145 pouvait poser un d�bordement de pointeur aout 2016
    {
        int dockused=detect_dock_used(control-96);
        DockIsSelected[control-96][dockused]=0;
        if (dockused<core_user_define_nb_docks-1)
        {
            DockIsSelected[control-96][dockused]=0;
            dockused++;
            DockIsSelected[control-96][dockused]=1;
        }
        else if (dockused==core_user_define_nb_docks-1)
        {
            DockIsSelected[control-96][dockused]=0;
            dockused=0;//6 docks pos 5
            DockIsSelected[control-96][dockused]=1;
        }
        /* if( enable_launchpad==1)
         {launchpad_impulsion(control, orange);}      */
        rest(midi_keyboard_wait);
    }
    if(control>47 && control <=95 && miditable[0][control]==4)
    {

        int dockused=detect_dock_used(control-48);
        DockIsSelected[control-48][dockused]=0;

        if((midi_levels[control]>=0 && midi_levels[control]<=5) || (midi_levels[control]>=36 && midi_levels[control]<=41)
                ||(midi_levels[control]>=72 && midi_levels[control]<=77) ||( midi_levels[control]>=108 && midi_levels[control]<=110 ))
        {
            dockused=0;
        }
        if((midi_levels[control]>=6 && midi_levels[control]<=11) || (midi_levels[control]>=42 && midi_levels[control]<=47)
                || (midi_levels[control]>=78 && midi_levels[control]<=83) || (midi_levels[control]>=111 && midi_levels[control]<=113) )
        {
            dockused=1;
        }
        if((midi_levels[control]>=12 && midi_levels[control]<=17) || (midi_levels[control]>=48 && midi_levels[control]<=53)
                || (midi_levels[control]>=84 && midi_levels[control]<=89) || (midi_levels[control]>=114 && midi_levels[control]<=117) )
        {
            dockused=2;
        }
        if((midi_levels[control]>=18 && midi_levels[control]<=23) || ( midi_levels[control]>=54 && midi_levels[control]<=59)
                || (midi_levels[control]>=90 && midi_levels[control]<=95) || (midi_levels[control]>=118 && midi_levels[control]<=121) )
        {
            dockused=3;
        }
        if((midi_levels[control]>=24 && midi_levels[control]<=29) || (midi_levels[control]>=60 && midi_levels[control]<=65)
                || (midi_levels[control]>=96 && midi_levels[control]<=101) || (midi_levels[control]>=122 && midi_levels[control]<=124) )
        {
            dockused=4;
        }
        if((midi_levels[control]>=30 && midi_levels[control]<=35) ||(midi_levels[control]>=66 && midi_levels[control]<=71)
                || (midi_levels[control]>=102 && midi_levels[control]<=107) || (midi_levels[control]>=125 && midi_levels[control]<=127) )
        {
            dockused=5;
        }

        DockIsSelected[control-48][dockused]=1;
        rest(midi_keyboard_wait);
    }

    if(control==145)//SELECT ALL MINIFADERS
    {
        for(int i=0; i<core_user_define_nb_faders; i++)
        {
            minifaders_selected[i]=1;
        }
        do_light_minifaders_commands[23]=1;
    }

    if(control>=146 && control <194)//etait 195 peut etre un debordement de pointeur
    {
        if(FaderLocked[control-146]==1)
        {
            FaderLocked[control-146]=0;
            Fader[control-146]=(unsigned char)((((float)(StateOfFaderBeforeLock[control-146]))/255)*locklevel);
            midi_levels[control-146]=(int)(((float)Fader[control-146])/2);
            rest(midi_keyboard_wait);
        }
        else   if(FaderLocked[control-146]==0)
        {
            FaderLocked[control-146]=1;
            StateOfFaderBeforeLock[control-146]=Fader[control-146];
            if(StateOfFaderBeforeLock[control-146]==255)
            {
                LockFader_is_FullLevel[control-146]=1;
            }
            else if(StateOfFaderBeforeLock[control-146]<255)
            {
                LockFader_is_FullLevel[control-146]=0;
            }
            lfo_cycle_is_on[control-146]=0;//rajout 0.7.6
            lfo_mode_is[control-146]=0;
            rest(midi_keyboard_wait);
        }
    }
    if(control>=196 && control <244)//etait 245 pouvait poser pb de debordement aout 2016
    {
        lfo_speed[control-196]=midi_levels[control];

        if(DockTypeIs[control-196][dock_used_by_fader_is[control-196]]==12)//enchassement Grid si slave
        {
            asservissement_gridplayer(control-196,dock_used_by_fader_is[control-196]);
        }

    }
    if(control>=245 && control <293)//etait 294 possible debordement aout 2016
    {
        if(lfo_mode_is[control-245]!=1 && (FaderLocked[control-245]==0 || LockFader_is_FullLevel[control-245]==1))//rajout lock 0.7.6)//up
        {
            lfo_mode_is[control-245]=1;
            faders_in_float[control-245]=Fader[control-245];
        }
        else
        {
            lfo_mode_is[control-245]=0;
        }

        lfo_cycle_is_on[control-245]=0;
        rest(midi_keyboard_wait);
    }
    if(control>=294 && control <342)//etait 343 possible debordement aout 2016
    {
        if(lfo_mode_is[control-294]!=2 && (FaderLocked[control-294]==0 || LockFader_is_FullLevel[control-294]==1))//rajout lock 0.7.6)//down
        {
            lfo_mode_is[control-294]=2;
            faders_in_float[control-294]=Fader[control-294];
        }
        else
        {
            lfo_mode_is[control-294]=0;
        }
        lfo_cycle_is_on[control-294]=0;
        rest(midi_keyboard_wait);
    }
    if(control>=343 && control <392)
    {
        faders_in_float[control-343]=Fader[control-343];
        if(lfo_cycle_is_on[control-343]==0 && (FaderLocked[control-343]==0 || LockFader_is_FullLevel[control-343]==1))//rajout lock 0.7.6)//up
        {
            lfo_cycle_is_on[control-343]=1;
            lfo_running_is_upward[control-343]=1;
            lfo_mode_is[control-343]=0;
            if(Fader[control-343]>0 && Fader[control-343]<255 )
            {
                lfo_running_is_upward[control-343]=1;
            }
        }
        else if(lfo_cycle_is_on[control-343]==1)
        {
            lfo_cycle_is_on[control-343]=0;
        }
        rest(midi_keyboard_wait);
    }
    if(control>=392 && control <441)
    {
        if (lfo_do_next_step[control-392][0]==0)
        {
            lfo_do_next_step[control-392][0]=1;
            lfo_do_next_step[control-392][1]=0;
            rest(midi_wait);
        }
        else if (lfo_do_next_step[control-392][0]==1)
        {
            lfo_do_next_step[control-392][0]=0;
            rest(midi_wait);
        }
    }
    if(control>=441 && control <490)
    {
        if (lfo_do_next_step[control-441][1]==0)
        {
            lfo_do_next_step[control-441][1]=1;
            lfo_do_next_step[control-441][0]=0;
            rest(midi_wait);
        }
        else if (lfo_do_next_step[control-441][1]==1)
        {
            lfo_do_next_step[control-441][1]=0;
            rest(midi_wait);
        }
    }


    if(control==494)
    {
        do_go_back_function();
        rest(midi_keyboard_wait);
    }

    if(control==495)
    {
        switch (Midi_Force_Go)
        {
        case 0:
            do_go_function();
            break;
        case 1:
            if(index_go==1)
            {
                do_double_go_function();
            }
            else
            {
                do_go_function();
            }
            index_pause=0;
            break;
        default:
            break;
        }
        if(index_go==1 && index_pause==0)
        {
            do_send_bang();
        }
        rest(midi_keyboard_wait);
    }

    if(control==496)
    {
        do_double_go_function();
        /*if(enable_launchpad==1){launchpad_impulsion(control, red);}   */
        if(index_go==1 && index_pause==0)
        {
            do_send_bang();
        }
        rest(midi_keyboard_wait);
    }

    if(control==493)
    {
        crossfade_speed=midi_levels[control];
        prepare_crossfade();
        someone_changed_in_time_sequences=1;
        if(index_link_speed_crossfade_to_gpl1==1)
        {
            grid_crossfade_speed[0]=crossfade_speed;
            midi_levels[1508]=crossfade_speed;
            gridder_prepare_cross(0,index_grider_selected[0],index_grider_step_is[0]);
        }
    }
    if(control==491)
    {
        if(midi_levels[control]<127 && index_get_back_faders_need_to_be_done==0)
        {
            niveauX1=midi_levels[control]*2;
        }
        if(midi_levels[control]==127 && index_get_back_faders_need_to_be_done==0)
        {
            niveauX1=255;
        }
    }

    if(control==492)//X2
    {
        if((127-midi_levels[control])<127 && index_get_back_faders_need_to_be_done==0)
        {
            niveauX2=(127-midi_levels[control])*2;
        }
        if((127-midi_levels[control])==127 && index_get_back_faders_need_to_be_done==0)
        {
            niveauX2=255;
        }
    }

    if(midi_levels[491]==127 && (127-midi_levels[492])==0 )
    {
        index_get_back_faders_need_to_be_done=0;
    }

    if(midi_levels[491]==0 && (127-midi_levels[492])==127 && niveauX1==0 && niveauX2==255 )
    {
        next_mem_crossfade_finished(position_preset);
        index_go=0;
        if(index_auto_mute_cuelist_speed==1 && crossfade_speed!=64)
        {
            is_raccrochage_midi_remote[493]=1;
        }
        crossfade_speed=64;
        if(midi_send_out[493]==1)
        {
            index_send_midi_out[493]=1;   //remise du speed midi
        }
        index_get_back_faders_need_to_be_done=1;
    }

    /*(control==497)
    {
    //MIS DANS LA FENETRE TRICHRO POUR RAFFRAIHIR LE TRIANGLE

    }*/


    if(control==498)
    {
        index_decay_tracker=midi_levels[498];
        refresh_decay();
    }


    if(control>=499 && control<548)
    {
        lfo_cycle_steps[control-499]= toggle(lfo_cycle_steps[control-499]);
        rest(midi_wait);
    }

    if(control==548)//fader off
    {
        do_stock_fadersstate(1,0,0,0,0);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                Fader[p]=0;
                midi_levels[p]=0;
                index_send_midi_out[p]=1;
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }

    if(control==549)//speed off
    {
        do_stock_fadersstate(0,1,0,0,0);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                lfo_speed[p]=64;
                midi_levels[196+p]=64;
                index_send_midi_out[196+p]=1;
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }

    if(control==550)//lock off
    {
        do_stock_fadersstate(0,0,1,0,0);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                FaderLocked[p]=0;
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }
    if(control==551)//lfo off
    {
        do_stock_fadersstate(0,0,0,1,0);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                lfo_mode_is[p]=0;//no lfo
                lfo_cycle_is_on[p]=0;//saw
                lfo_cycle_steps[p]=0;
                lfo_do_next_step[p][0]=0;
                lfo_do_next_step[p][1]=0;
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }
    if(control==552)//loop off
    {
        do_stock_fadersstate(0,0,0,0,1);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                for(int d=0; d<core_user_define_nb_docks; d++)
                {
                    is_dock_for_lfo_selected[p][d]=0;
                }
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }
    if(control==553)// ALL OFF
    {
        do_stock_fadersstate(1,1,1,1,1);
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                Fader[p]=0;
                midi_levels[p]=0;
                index_send_midi_out[p]=1;
                lfo_speed[p]=64;
                midi_levels[196+p]=64;
                index_send_midi_out[196+p]=1;
                FaderLocked[p]=0;
                lfo_mode_is[p]=0;//no lfo
                lfo_cycle_is_on[p]=0;//saw
                lfo_cycle_steps[p]=0;
                lfo_do_next_step[p][0]=0;
                lfo_do_next_step[p][1]=0;
                for(int d=0; d<core_user_define_nb_docks; d++)
                {
                    is_dock_for_lfo_selected[p][d]=0;
                }
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }
    if(control==554)//midi out off
    {
        for (int p=0; p<core_user_define_nb_faders; p++)
        {
            if(minifaders_selected[p]==1)
            {
                midi_send_out[p]=0;//faders
            }
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, green);}*/
    }
    if(control==555)// RECALL
    {
        do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
                               stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
    }

    if(control>=556 && control<605)
    {
        do_midi_call_order(control-556);
        midi_levels[control]=0;//clean de l'�tat midi pour visu
        /*if(enable_launchpad==1){launchpad_impulsion(control,red);}      */
    }

    if(control>=605 && control<614)
    {
        do_lock_preset(control-605);
    }
    if (control==615)
    {
        if(index_allow_grand_master==1)
        {
            if(midi_levels[control]<127 )
            {
                niveauGMaster=midi_levels[control]*2;
            }
            if(midi_levels[control]==127)
            {
                niveauGMaster=255;
            }
        }
    }

    for (int bum=0; bum<4; bum++)
    {
        if (control==616+bum)
        {
            player_niveauson[bum]=midi_levels[control];
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0:
                    player1->setVolume(((float)player_niveauson[bum])/127);
                    break;
                case 1:
                    player2->setVolume(((float)player_niveauson[bum])/127);
                    break;
                case 2:
                    player3->setVolume(((float)player_niveauson[bum])/127);
                    break;
                case 3:
                    player4->setVolume(((float)player_niveauson[bum])/127);
                    break;
                default:
                    break;
                }
            }
        }
        if (control==620+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    player_pan[bum]=midi_levels[control] ;
                    if(player_pan[bum]<1)
                    {
                        player_pan[bum]=1;
                    }
                    else if(player_pan[bum]>127)
                    {
                        player_pan[bum]=127;
                    }
                    player1->setPan(((float)(player_pan[bum]-64))/63); // -64 /63 OK POUR AVOIR -1.00 +1.00 GAUCHE DROITE
                    break;
                case 1://PLAYER 2
                    player_pan[bum]=midi_levels[control];
                    if(player_pan[bum]<1)
                    {
                        player_pan[bum]=1;
                    }
                    else if(player_pan[bum]>127)
                    {
                        player_pan[bum]=127;
                    }
                    player2->setPan(((float)(player_pan[bum]-64))/63);
                    break;
                case 2://PLAYER 3
                    player_pan[bum]=midi_levels[control];
                    if(player_pan[bum]<1)
                    {
                        player_pan[bum]=1;
                    }
                    else if(player_pan[bum]>127)
                    {
                        player_pan[bum]=127;
                    }
                    player3->setPan(((float)(player_pan[bum]-64))/63);
                    break;
                case 3://PLAYER 4
                    player_pan[bum]=midi_levels[control];
                    if(player_pan[bum]<1)
                    {
                        player_pan[bum]=1;
                    }
                    else if(player_pan[bum]>127)
                    {
                        player_pan[bum]=127;
                    }
                    player4->setPan(((float)(player_pan[bum]-64))/63);
                    break;
                default:
                    break;
                }
            }
        }
        if (control==624+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    player_pitch[bum]=midi_levels[control];
                    if(player_pitch[bum]<1)
                    {
                        player_pitch[bum]=1;
                    }
                    else if(player_pitch[bum]>127)
                    {
                        player_pitch[bum]=127;
                    }
                    player1->setPitchShift((((float)player_pitch[bum])/64));
                    break;
                case 1://PLAYER 2
                    player_pitch[bum]=midi_levels[control];
                    if(player_pitch[bum]<1)
                    {
                        player_pitch[bum]=1;
                    }
                    else if(player_pitch[bum]>127)
                    {
                        player_pitch[bum]=127;
                    }
                    player2->setPitchShift((((float)player_pitch[bum])/64));
                    break;
                case 2://PLAYER 3
                    player_pitch[bum]=midi_levels[control] ;
                    if(player_pitch[bum]<1)
                    {
                        player_pitch[bum]=1;
                    }
                    else if(player_pitch[bum]>127)
                    {
                        player_pitch[bum]=127;
                    }
                    player3->setPitchShift((((float)player_pitch[bum])/64));
                    break;
                case 3://PLAYER 4
                    player_pitch[bum]=midi_levels[control] ;
                    if(player_pitch[bum]<1)
                    {
                        player_pitch[bum]=1;
                    }
                    else if(player_pitch[bum]>127)
                    {
                        player_pitch[bum]=127;
                    }
                    player4->setPitchShift((((float)player_pitch[bum])/64));
                    break;
                default:
                    break;
                }
            }
        }

        if (control==628+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    switch(player1->isPlaying())
                    {
                    case 0:
                        player1->play();
                        player_is_playing[bum]=1;
                        break;
                    case 1:
                        player1_do_stop();
                        player_is_playing[bum]=0;
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
                        player_is_playing[bum]=1;
                        break;
                    case 1:
                        player2_do_stop();
                        player_is_playing[bum]=0;
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
                        player_is_playing[bum]=1;
                        break;
                    case 1:
                        player3_do_stop();
                        player_is_playing[bum]=0;
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
                        player_is_playing[bum]=1;
                        break;
                    case 1:
                        player4_do_stop();
                        player_is_playing[bum]=0;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (control==632+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
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
                midi_show_flash_seektouch[bum]=1;
                /*if(enable_launchpad==1){launchpad_impulsion(control, orange);}*/
            }
        }

        if (control==636+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    switch(player1-> getRepeat())
                    {
                    case 0:
                        player1->setRepeat(true);
                        player_is_onloop[bum]=1;
                        break;
                    case 1:
                        player1->setRepeat(false);
                        player_is_onloop[bum]=0;
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
                        player_is_onloop[bum]=1;
                        break;
                    case 1:
                        player2->setRepeat(false);
                        player_is_onloop[bum]=0;
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
                        player_is_onloop[bum]=1;
                        break;
                    case 1:
                        player3->setRepeat(false);
                        player_is_onloop[bum]=0;
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
                        player_is_onloop[bum]=1;
                        break;
                    case 1:
                        player4->setRepeat(false);
                        player_is_onloop[bum]=0;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (control==640+bum)
        {
            if(player_ignited[bum]==1  && position_of_file_in_player[bum]-100000>0)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    player1->setPosition(position_of_file_in_player[bum]-100000);
                    break;
                case 1://PLAYER 2
                    player2->setPosition(position_of_file_in_player[bum]-100000);
                    break;
                case 2://PLAYER 3
                    player3->setPosition(position_of_file_in_player[bum]-1000000);
                    break;
                case 3://PLAYER 4
                    player4->setPosition(position_of_file_in_player[bum]-100000);
                    break;
                default:
                    break;
                }
            }
            midi_show_flash_backwardtouch[bum]=1;
            /*if(enable_launchpad==1){launchpad_impulsion(control, orange);}*/
        }
        if (control==644+bum)
        {
            if(player_ignited[bum]==1 && position_of_file_in_player[bum]+100000<length_of_file_in_player[bum])
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    player1->setPosition(position_of_file_in_player[bum]+100000);
                    break;
                case 1://PLAYER 2
                    player2->setPosition(position_of_file_in_player[bum]+100000);
                    break;
                case 2://PLAYER 3
                    player3->setPosition(position_of_file_in_player[bum]+100000);
                    break;
                case 3://PLAYER 4
                    player4->setPosition(position_of_file_in_player[bum]+100000);
                    break;
                default:
                    break;
                }
            }
            midi_show_flash_forwardtouch[bum]=1;
            /*if(enable_launchpad==1){launchpad_impulsion(control, orange);}*/
        }
        if (control==648+bum)
        {
            if(player_ignited[bum]==1 && index_edit_audio==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    if(index_main_clear==0)
                    {
                        player_seek_position[bum]=(player1->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else  if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_seek_position[bum]=0;
                        index_main_clear=0;
                    }
                    break;
                case 1://PLAYER 2
                    if(index_main_clear==0)
                    {
                        player_seek_position[bum]=(player2->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else  if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_seek_position[bum]=0;
                        index_main_clear=0;
                    }
                    break;
                case 2://PLAYER 3
                    if(index_main_clear==0)
                    {
                        player_seek_position[bum]=(player3->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else  if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_seek_position[bum]=0;
                        index_main_clear=0;
                    }
                    break;
                case 3://PLAYER 4
                    if(index_main_clear==0)
                    {
                        player_seek_position[bum]=(player4->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else  if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_seek_position[bum]=0;
                        index_main_clear=0;
                    }
                    break;
                default:
                    break;
                }
            }
            midi_show_flash_cueIntouch[bum]=1;
            /*if(enable_launchpad==1){launchpad_impulsion(control,red);}*/
        }
        if (control==652+bum)
        {
            if(player_ignited[bum]==1 && index_edit_audio==1)
            {
                switch(bum)
                {

                case 0://PLAYER 1
                    if(index_main_clear==0)
                    {
                        player_loop_out_position[bum]=(player1->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_loop_out_position[bum]=(player1->getLength());
                    }
                    break;
                case 1://PLAYER 2
                    if(index_main_clear==0)
                    {
                        player_loop_out_position[bum]=(player2->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_loop_out_position[bum]=(player2->getLength());
                    }
                    break;
                case 2://PLAYER 3
                    if(index_main_clear==0)
                    {
                        player_loop_out_position[bum]=(player3->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_loop_out_position[bum]=(player3->getLength());
                    }
                    break;
                case 3://PLAYER 4
                    if(index_main_clear==0)
                    {
                        player_loop_out_position[bum]=(player4->getPosition());
                        if(player_loop_out_position[bum]<=player_seek_position[bum])
                        {
                            player_loop_out_position[bum]=player_seek_position[bum]+1;
                        }
                    }
                    else  if(player_loop_out_position[bum]!=player_seek_position[bum])
                    {
                        player_loop_out_position[bum]=(player4->getLength());
                    }
                    break;
                default:
                    break;
                }
                /*if(enable_launchpad==1){launchpad_impulsion(control, red);}*/
                midi_show_flash_cueOuttouch[bum]=1;
            }
        }
        if (control==656+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    switch(player1-> getRepeat())
                    {
                    case 0:
                        player1->setRepeat(true);
                        player_is_onloopCue[bum]=1;
                        break;
                    case 1:
                        player1->setRepeat(false);
                        player_is_onloopCue[bum]=0;
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
                        player_is_onloopCue[bum]=1;
                        break;
                    case 1:
                        player2->setRepeat(false);
                        player_is_onloopCue[bum]=0;
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
                        player_is_onloopCue[bum]=1;
                        break;
                    case 1:
                        player3->setRepeat(false);
                        player_is_onloopCue[bum]=0;
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
                        player_is_onloopCue[bum]=1;
                        break;
                    case 1:
                        player4->setRepeat(false);
                        player_is_onloopCue[bum]=0;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (control==660+bum)
        {
            if(player_ignited[bum]==1)
            {
                switch(bum)
                {
                case 0://PLAYER 1
                    player1->setPosition(player_seek_position[bum]);
                    break;
                case 1://PLAYER 2
                    player2->setPosition(player_seek_position[bum]);
                    break;
                case 2://PLAYER 3
                    player3->setPosition(player_seek_position[bum]);
                    break;
                case 3://PLAYER 4
                    player4->setPosition(player_seek_position[bum]);
                    break;
                default:
                    break;
                }
                midi_show_flash_cueSeektouch[bum]=1;
                /*if(enable_launchpad==1){launchpad_impulsion(control, red);}*/
            }

        }

    }
    if (control==664)
    {
        do_wheel_level_job(midi_levels[664]);
        angle_snap_pad=(((PIknob*2)+angle_correction_wheel) / 128)*midi_levels[664];
        pad_vx = cos(angle_snap_pad)* rayon_wheel_level;
        pad_vy = sin(angle_snap_pad)* rayon_wheel_level;
        position_curseur_pad_x= xnum_window+10+260+pad_vx;
        position_curseur_pad_y=ynum_window+35+pad_vy ;
        index_level_attribue=1;

    }
    if(control==665)
    {
        simulate_keypress(KEY_ENTER<<8);
    }
    if(control==666)
    {
        simulate_keypress(KEY_PLUS_PAD<<8);
    }
    if(control==667)
    {
        simulate_keypress(KEY_MINUS_PAD<<8);
    }
    if(control==668)
    {
        simulate_keypress(KEY_UP<<8);
    }
    if(control==669)
    {
        simulate_keypress(KEY_DOWN<<8);
    }
    if(control==670)
    {
        simulate_keypress(KEY_0<<8);
    }
    if(control==671)
    {
        simulate_keypress(KEY_1<<8);
    }
    if(control==672)
    {
        simulate_keypress(KEY_2<<8);
    }
    if(control==673)
    {
        simulate_keypress(KEY_3<<8);
    }
    if(control==674)
    {
        simulate_keypress(KEY_4<<8);
    }
    if(control==675)
    {
        simulate_keypress(KEY_5<<8);
    }
    if(control==676)
    {
        simulate_keypress(KEY_6<<8);
    }
    if(control==677)
    {
        simulate_keypress(KEY_7<<8);
    }
    if(control==678)
    {
        simulate_keypress(KEY_8<<8);
    }
    if(control==679)
    {
        simulate_keypress(KEY_9<<8);
    }
    if(control==680)
    {
        simulate_keypress(KEY_COMMA<<8);   //POINT
    }
    if(control==681)
    {
        simulate_keypress(KEY_ESC<<8);   //ESC
    }
    if(control==682)
    {
        simulate_keypress(KEY_Y<<8);   //ALL
    }
    if(control==683)
    {
        simulate_keypress(KEY_U<<8);   //INV
    }
    if(control==684)
    {
        simulate_keypress(KEY_TAB<<8);
    }

    if(control>=685 && control<=732) //STOPOS FADERS //etait 732 possible debordement aout 2016
    {
        if(index_do_dock==0 && index_main_clear==0)
        {
            ActionnateStopOn[control-685]=toggle(ActionnateStopOn[control-685]);
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
                default:
                    break;
                }
                reset_numeric_entry();
                if (lStopPos>=0 && lStopPos<=255)
                {
                    StopPosOn[control-685]=1;
                    LevelStopPos[control-685]=lStopPos;
                    index_do_dock=0;
                    do_light_setpos[control-685]=1;
                }
            }
            else if (numeric_postext==0) //affectation stop pos depuis le cursuer fader
            {
                StopPosOn[control-685]=1;
                LevelStopPos[control-685]=Fader[control-685];
                index_do_dock=0;
                do_light_setpos[control-685]=1;
            }
        }

        else if(index_main_clear==1 && index_do_dock==0)//clear
        {
            StopPosOn[control-685]=0;
            LevelStopPos[control-685]=999;
            index_main_clear=0;
            do_light_setpos[control-685]=1;
        }
    }
    if (control==734)
    {
        start_time_for_banger[index_banger_selected]=actual_time;
        end_time_for_banger[index_banger_selected]=0;
        for (int o=0; o<6; o++) //reset des �v�nements
        {
            event_sended[index_banger_selected][o]=0;
            if(bangers_delay[index_banger_selected][o]>end_time_for_banger[index_banger_selected])
            {
                end_time_for_banger[index_banger_selected]=(int)(bangers_delay[index_banger_selected][o]);
            }
        }
        bang_is_sended[index_banger_selected]=0;//reset du bang sended is
        do_light_bang_it=1;
        /*if(enable_launchpad==1){launchpad_impulsion(control, red);} */
    }

    if (control>=735 && control<=740)
    {
        Bang_event(index_banger_selected,control-735);
        do_light_bang_solo[control-735]=1;
        /*if(enable_launchpad==1){launchpad_impulsion(control, red);}*/
    }
    if(control==741)
    {
        if(index_banger_selected>0)
        {
            index_banger_selected--;
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, red);}*/
        rest(midi_keyboard_wait);
    }
    if(control==742)
    {
        if(index_banger_selected<127)
        {
            index_banger_selected++;
        }
        /*if(enable_launchpad==1){launchpad_impulsion(control, red);} */
        rest(midi_keyboard_wait);
    }

    if(control>=743 && control<=757)
    {
        switch(control)
        {
        case 743: //DOCK
            index_do_modify=0;
            index_do_report=0;
            index_main_clear=0;
            index_do_dock=toggle(index_do_dock);

            switch(index_do_dock)
            {
            case 0:
                sprintf(string_Last_Order,">> Record ready");
                break;
            case 1:
                sprintf(string_Last_Order,">> No Record");
                break;
            default:
                break;
            }

            switch (window_focus_id)
            {
            case W_CHASERS:
                index_affect_chaser_to_dock=index_do_dock;
                break;
            case W_GRID:
                for(int i=0; i<4; i++)
                {
                    if(index_show_grid_player[i]==1)
                    {
                        gridplayer_to_affect_is=i;
                        break;
                    }
                }
                break;
            case W_MOVER:
                index_affect_to_dock_mover=index_do_dock;
                break;
            case W_DRAW:
                index_affect_draw_to_dock=index_do_dock;
                break;
            case W_ECHO:
                index_affect_echo_to_dock=index_do_dock;
                break;
            case W_TIME:
                index_affect_time=index_do_dock;
                break;
            case W_TRACKINGVIDEO:
                index_affect_video_tracking_to_dock=index_do_dock;
                break;
            case W_TRICHROMY:
                index_affect_color_to_dock=index_do_dock;
                break;
            case W_AUDIO:
                index_affect_audio_to_dock=index_do_dock;
                player_to_affect_to_dock=0;
                audio_type_for_dock_affectation_is=0;
                break;
            case W_CFGMENU:
                if(config_page_is==1)
                {
                    index_affect_dmxin=index_do_dock;
                }
                else if(config_page_is==3)
                {
                    index_do_affect_net_to_dock=index_do_dock;
                }
                break;
            default:
                break;
            }

            break;
        case 744://MODIFY
            if(index_do_modify==0)
            {
                reset_index_actions();
                index_do_modify=1;
                sprintf(string_Last_Order,">> Modify ready");
            }
            else if(index_do_modify==1)
            {
                index_do_modify=0;
                sprintf(string_Last_Order,">> No Modify");
            }
            break;
        case 745://REPORT
            if(index_do_report==0)
            {
                reset_index_actions();
                index_do_report=1;
                sprintf(string_Last_Order,">> Report ready");
            }
            else if(index_do_report==1)
            {
                index_do_report=0;
                sprintf(string_Last_Order,">> No Report");
            }
            break;
        case 746://clear
            if(index_main_clear==0)
            {
                reset_index_actions();
                index_main_clear=1;
                sprintf(string_Last_Order,">> Clear ready");
            }
            else if(index_main_clear==1)
            {
                index_main_clear=0;
                sprintf(string_Last_Order,">> Clear Report");
            }
            break;
        case 747:       //NAME
            index_type=toggle(index_type);
            //sab 02/03/2014 sprintf(numeric,"");numeric_postext=0;
            strcpy(numeric,"");
            numeric_postext=0;
            break;
        case 748://TIME
            if(index_time==0)
            {
                add_a_window(W_TIME);
            }
            else
            {
                substract_a_window(W_TIME);
            }
            break;
        case 749:     //TRICHRO
            if(index_trichro_window==0)
            {
                add_a_window(W_TRICHROMY);
            }
            else
            {
                substract_a_window(W_TRICHROMY);
            }
            break;
        case 750://CAMERA
            if(index_video_window==0)
            {
                add_a_window(W_TRACKINGVIDEO);
            }
            else
            {
                substract_a_window(W_TRACKINGVIDEO);
            }
            break;
        case 751://SEQUENCIEL
            if(index_window_sequentiel==0)
            {
                ;
                add_a_window(W_SEQUENCIEL);
            }
            else
            {
                substract_a_window(W_SEQUENCIEL);
            }
            break;
        case 752://FADERS
            if(index_show_faders==0)
            {
                add_a_window(W_FADERS);
            }
            else
            {
                substract_a_window(W_FADERS);
            }
            break;
        case 753://BANGERS
            if(index_show_banger_window==0)
            {
                add_a_window(W_BANGER);
                mouse_level_for_event=mouse_z;
                mouse_level_for_banger=mouse_z;
            }
            else
            {
                substract_a_window(W_BANGER);
            }
            break;
        case 754://BLIND
            index_blind=toggle(index_blind);
            break;
        case 755://CFG MAIN
            if(index_show_config_window==0)
            {
                add_a_window(W_CFGMENU);
            }
            else
            {
                substract_a_window(W_CFGMENU);
            }
            break;
        case 756://AUDIO PLAYERS
            if(index_show_audio_window==0)
            {
                add_a_window(W_AUDIO);
            }
            else
            {
                substract_a_window(W_AUDIO);
            }
            reset_audio_indexs_to_dock();
            break;
        case 757://QUIT
            index_ask_confirm=1;
            index_do_quit_with_save=1;
            break;
        }
        rest(midi_keyboard_wait);
    }


    if(control>=758 && control<=766)
    {
        switch(control)
        {
        case 758://roue
            angle_timesnap=(5.980005 / 128)*midi_levels[758];
            vtimex = cos(angle_timesnap)*100;
            vtimey = sin(angle_timesnap)*100;
            position_curseur_time_x= xtime_window+150+vtimex;
            position_curseur_time_y=ytime_window+150+vtimey ;
            if(time_wheel_datatype_is==0)//minutes
            {
                angle_timesnap_min=angle_timesnap;
                time_minutes=(int)((angle_timesnap_min/5.980005)*60);
            }
            if(time_wheel_datatype_is==1)//secondes
            {
                angle_timesnap_sec=angle_timesnap;
                time_secondes=(int)((angle_timesnap_sec/5.980005)*60);
            }
            if(time_wheel_datatype_is==2)//dixiemes
            {
                angle_timesnap_dix=angle_timesnap;
                time_centiemes=(int)((angle_timesnap_dix/5.980005)*100);
            }
            break;
        case 759://type de temps
            time_wheel_datatype_is++;
            if(time_wheel_datatype_is>2)
            {
                time_wheel_datatype_is=0;
            }
            set_time_cursor_to_time_type(time_wheel_datatype_is);
            break;
        case 760://delay in
            if(index_type_of_time_to_affect[0]==0)
            {
                index_type_of_time_to_affect[0]=1;
            }
            else if(index_type_of_time_to_affect[0]==1)
            {
                index_type_of_time_to_affect[0]=0;
            }
            break;
        case 761://in
            if(index_type_of_time_to_affect[1]==0)
            {
                index_type_of_time_to_affect[1]=1;
            }
            else if(index_type_of_time_to_affect[1]==1)
            {
                index_type_of_time_to_affect[1]=0;
            }
            break;
        case 762://delay out
            if(index_type_of_time_to_affect[2]==0)
            {
                index_type_of_time_to_affect[2]=1;
            }
            else if(index_type_of_time_to_affect[2]==1)
            {
                index_type_of_time_to_affect[2]=0;
            }
            break;
        case 763://time out button
            if(index_type_of_time_to_affect[3]==0)
            {
                index_type_of_time_to_affect[3]=1;
            }
            else if(index_type_of_time_to_affect[3]==1)
            {
                index_type_of_time_to_affect[3]=0;
            }
            break;
        case 764://affect time button
            if(index_affect_time==0)
            {
                index_affect_time=1;
            }
            else if(index_affect_time==1)
            {
                index_affect_time=0;
            }
            break;
        case 765: //chrono play pause
            Chrono_PlayPause();
            break;
        case 766://chrono reset
            Chrono_Reset();
            break;
        default:
            break;
        }
    }

    if(control==767)
    {
        scroll_faderspace=((920/128)*midi_levels[767])-15;   //920 valeur tres personnelle  //-15 pour avant les faders: group et all at
    }

    if(control==768)// create new mem
    {
        reset_indexs_confirmation();
        index_do_create_mem=1;
        index_ask_confirm=1;
    }
    if(control==769)// delete new mem
    {
        reset_indexs_confirmation();
        index_do_delete_mem=1;
        index_ask_confirm=1;
    }
    if(control==770)// stage minus
    {
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
        refresh_integrated_gridplayer1();
        someone_changed_in_sequences=1;//icat
    }
    if(control==771)// stage plus
    {
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
        position_onstage=position_preset;
        refresh_mem_onstage(position_onstage);
        detect_mem_before_one();
        detect_mem_preset();
        refresh_mem_onpreset(position_preset);
        niveauX1=255;
        niveauX2=0;
        refresh_banger_wx();
        refresh_integrated_gridplayer1();
        someone_changed_in_sequences=1;//icat
    }
    if(control==772)// preset minus
    {
        index_go=0;
        index_pause=0;
        index_go_back=0;
        detect_mem_preset_previous();
        refresh_mem_onpreset(position_preset);
        niveauX2=0;
        someone_changed_in_sequences=1;//icat
    }
    if(control==773)// preset plus
    {
        index_go=0;
        index_pause=0;
        index_go_back=0;
        detect_next_preset();
        refresh_mem_onpreset(position_preset);
        niveauX2=0;
        someone_changed_in_sequences=1;//icat
    }



    if(control==774)//previous sel
    {
        position_minifader_selected--;
        if(position_minifader_selected<0)
        {
            position_minifader_selected=48;
        }
        refresh_minifader_state_view_core(position_minifader_selected);
        do_light_minifaders_commands[0]=1;
    }
    if(control==775)//next sel
    {
        position_minifader_selected++;
        if(position_minifader_selected>48)
        {
            position_minifader_selected=0;
        }
        refresh_minifader_state_view_core(position_minifader_selected);
        do_light_minifaders_commands[1]=1;
    }
    if(control==776 && midi_levels[control]!=0)//select
    {
        minifaders_selected[position_minifader_selected]=toggle(minifaders_selected[position_minifader_selected]);
        do_light_minifaders_commands[2]=1;
    }
    if(control==777)//unselect
    {
        for(int l=0; l<core_user_define_nb_faders; l++)
        {
            minifaders_selected[l]=0;
        }
        do_light_minifaders_commands[3]=1;
    }

    if(control==778)//FLASH
    {
        if(midi_levels[778]>0)
        {
            for(int tt=0; tt<core_user_define_nb_faders; tt++)
            {
                if( minifaders_selected[tt]==1  && FaderIsFlash[tt]==0)
                {
                    FaderIsFlash[tt]=1;
                }
            }
        }
        else //key on ==0
        {
            for(int tn=0; tn<core_user_define_nb_faders; tn++)
            {
                if( minifaders_selected[tn]==1)
                {
                    FaderIsFlash[tn]=0;
                }
            }
        }
    }


    if(control>778 && control<793)
    {
        do_action_on_selected_minifaders(control-778);
        do_light_minifaders_commands[(control-774)]=1;//decalages
    }


    if(control>=794 && control<802)//minifaders preset de selection
    {
        int log=control-794;

        for(int olp=0; olp<core_user_define_nb_faders; olp++)
        {
            minifaders_selected[olp]=minifaders_preset_selection[log][olp];
        }
        sprintf(string_Last_Order,"Called Fader Selection from Preset %d", log+1);
    }


    if(control>=802 && control<850 )//etait 850 possible debordement aout 2016
    {
        int docktotouch=(dock_used_by_fader_is[control-802]);
        is_dock_for_lfo_selected[control-802][docktotouch]=toggle(is_dock_for_lfo_selected[control-802][docktotouch]);
    }


    if(control>=851 && control<859 )//etait 900 possible debordement aout 2016
    {
        bool index_choose_mode_dkloop=0;//0 toggle tt le monde / 1 copie l etat du dck selctionn� dans tt le monde

        for (int ck=0; ck<core_user_define_nb_docks-1; ck++)
        {
            if(is_dock_for_lfo_selected[control-851][ck]!=is_dock_for_lfo_selected[control-851][ck+1])
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
                is_dock_for_lfo_selected[control-851][op]=toggle(is_dock_for_lfo_selected[control-851][op]);
            }
            break;
        case 1:
            for(int j=0; j<core_user_define_nb_docks; j++)
            {
                if(DockIsSelected[control-851][j]==1)
                {
                    int tempval_dockloop=toggle(is_dock_for_lfo_selected[control-851][j]);
                    for(int k=0; k<core_user_define_nb_docks; k++)
                    {
                        is_dock_for_lfo_selected[control-851][k]=toggle(tempval_dockloop);
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }

    if(control>=900 && control<948)//etait 949 possible debordement aout 2016
    {
        if(midi_levels[control]>0)
        {
            FaderIsFlash[control-900]=toggle(FaderIsFlash[control-900]);// auparavant =1
        }
        else  //key on ==0
        {
            FaderIsFlash[control-900]=0;
        }
    }

    if(control>=949 && control<957)
    {
        dock_color_selected=control-949;
        load_etat_picker_dans_dockcolor(dock_color_selected);
        sprintf(string_Last_Order,">>MIDI Dock Color Selected %d",(dock_color_selected+1));
    }

    if(control>=957 && control<969)//trcaks roi
    {
        tracking_spaces_on_off[tracking_dock_selected][control-957] =toggle(tracking_spaces_on_off[tracking_dock_selected][control-957]);
    }
    if(control>=969 && control<974)//tracking preset
    {
        tracking_dock_selected=control-969;
    }


    /*974 Chaser -
    975 Chaser +
    976 view track Up
    977 view track down
    978 Play
    979 Seek
    980 Loop*/
    if(control==974 && midi_levels[control]>0)//chaser selected up
    {
        chaser_selected--;
        if(chaser_selected<0)
        {
            chaser_selected=core_user_define_nb_chasers-1;
        }
        refresh_chaser_midi_out();
    }
    if(control==975 && midi_levels[control]>0)//chaser selected down
    {
        chaser_selected++;
        if(chaser_selected>core_user_define_nb_chasers-1)
        {
            chaser_selected=0;
        }
        refresh_chaser_midi_out();
    }
    if(control==976 && midi_levels[control]>0)//chaser track up
    {
        position_affichage_track_num[chaser_selected]--;
        if(position_affichage_track_num[chaser_selected]<0)
        {
            position_affichage_track_num[chaser_selected]=0;
        }
    }
    if(control==977 && midi_levels[control]>0)//chaser track down
    {
        position_affichage_track_num[chaser_selected]++;
        if(position_affichage_track_num[chaser_selected]> core_user_define_nb_tracks_per_chasers-nbre_track_visualisables)
        {
            position_affichage_track_num[chaser_selected]= core_user_define_nb_tracks_per_chasers-nbre_track_visualisables;
        }
    }

    if(control==978 && midi_levels[control]>0)
    {
        chaser_is_playing[chaser_selected]=toggle(chaser_is_playing[chaser_selected]);
        if(chaser_is_playing[chaser_selected]==1)//snap du temps at beg
        {
            chaser_start_time[chaser_selected]=actual_time;
        }
    }

    if(control==979 && midi_levels[control]>0)
    {
        chaser_seek_at_beg(chaser_selected);
    }

    if(control==980 && midi_levels[control]>0)
    {
        chaser_is_in_loop[chaser_selected]=toggle(chaser_is_in_loop[chaser_selected]);
        switch(chaser_is_in_loop[chaser_selected])
        {
        case 0:
            sprintf(string_Last_Order,">> LOOP OFF Chaser %d",chaser_selected+1);
            break;
        case 1:
            sprintf(string_Last_Order,">> LOOP ON Chaser %d",chaser_selected+1);
            break;
        default:
            break;
        }
    }
    /*
    981 Forward
    982 backward
    983 aller retour
    984 All
    985 Seek
    986 Off
    987 -> 990 P1 � P4

    */
    if(control==981 && midi_levels[control]>0)
    {
        chaser_way[chaser_selected]=0;
    }
    if(control==982 && midi_levels[control]>0)
    {
        chaser_way[chaser_selected]=1;
    }
    if(control==983 && midi_levels[control]>0)
    {
        chaser_aller_retour[chaser_selected]=toggle(chaser_aller_retour[chaser_selected]);
    }
    if(control==984 && midi_levels[control]>0)
    {
        chaser_select_all_track(chaser_selected);
    }
    if(control==985 && midi_levels[control]>0)
    {
        chaser_select_inv_track(chaser_selected);
    }
    if(control==986 && midi_levels[control]>0)
    {
        chaser_select_off_all_track(chaser_selected);
    }
    if(control==987 && midi_levels[control]>0)
    {
        chaser_load_from_preset(chaser_selected,0);
    }
    if(control==988 && midi_levels[control]>0)
    {
        chaser_load_from_preset(chaser_selected,1);
    }
    if(control==989 && midi_levels[control]>0)
    {
        chaser_load_from_preset(chaser_selected,2);
    }
    if(control==990 && midi_levels[control]>0)
    {
        chaser_load_from_preset(chaser_selected,3);
    }
    /*
    991-> 993 Operator Up Stay Down
    994 T join / T Std*/

    if(control==991 && midi_levels[control]>0)
    {
        if(chaser_operator_is!=1)
        {
            chaser_operator_is=1;
        }
        else
        {
            chaser_operator_is=0;
        }
    }
    if(control==992 && midi_levels[control]>0)
    {
        if(chaser_operator_is!=2)
        {
            chaser_operator_is=2;
        }
        else
        {
            chaser_operator_is=0;
        }
    }
    if(control==993 && midi_levels[control]>0)
    {
        if(chaser_operator_is!=3)
        {
            chaser_operator_is=3;
        }
        else
        {
            chaser_operator_is=0;
        }
    }

    if(control==994 && midi_levels[control]>0)
    {
        chaser_time_mode[chaser_selected]=toggle(chaser_time_mode[chaser_selected]);
    }
    /*
    995 Beg Point
    996 End Point
    997 Pos Timeline*/
    if(control==995 )
    {
        chaser_begin_step_is[chaser_selected]=(int)((36.0/127)*midi_levels[control]);
        if(chaser_begin_step_is[chaser_selected]>=chaser_end_step_is[chaser_selected])
        {
            chaser_begin_step_is[chaser_selected]=chaser_end_step_is[chaser_selected]-1;
        }
        if(chaser_begin_step_is[chaser_selected]<0)
        {
            chaser_begin_step_is[chaser_selected]=0;
        }
    }
    if(control==996)
    {
        chaser_end_step_is[chaser_selected]=(int)((36.0/127)*midi_levels[control]);
        if(chaser_end_step_is[chaser_selected]<=chaser_begin_step_is[chaser_selected])
        {
            chaser_end_step_is[chaser_selected]=chaser_begin_step_is[chaser_selected]+1;
        }
        if(chaser_end_step_is[chaser_selected]>nbre_de_cases_par_track)
        {
            chaser_end_step_is[chaser_selected]=nbre_de_cases_par_track;
        }
    }
    if(control==997)
    {
        chaser_step_is[chaser_selected]=(int)((36.0/127)*midi_levels[control]);
        if(chaser_step_is[chaser_selected]<0)
        {
            chaser_step_is[chaser_selected]=0;
        }
        if(chaser_step_is[chaser_selected]>nbre_de_cases_par_track)
        {
            chaser_step_is[chaser_selected]=nbre_de_cases_par_track;
        }
        chaser_calcul_step(chaser_selected,0.0);
        chaser_calcul_time_joint(chaser_selected);
    }

    /*998 -> 1022 ON OFF tracks
    1023 -> 1047 Level tracks*/
    if(control>=998 && control<1022 && midi_levels[control]>0)//etait 1023 possible debordement aout 2016
    {
        track_is_on[chaser_selected][control-998]=toggle(track_is_on[chaser_selected][control-998]);
    }

    if(control>=1023 && control<1047 )//etait 1048 possible debordement aout 2016
    {
        track_level[chaser_selected][control-1023]=midi_levels[control];
    }


    if(control>=1048 && control<1113 && index_enable_edit_chaser==1 && launchpad_chaser_mode==1)
    {
        int piste=(int)((float)(control-1048)/8);
        int step_of=chaser_step_launchpad[chaser_selected]+ ((control-1048-(piste*8))%8);

        if(step_of>=0 && step_of<nbre_de_cases_par_track)
        {
            if(chaser_step_operation[chaser_selected][piste][step_of]!=chaser_operator_is)
                chaser_step_operation[chaser_selected][piste][step_of]=chaser_operator_is;
            else
            {
                chaser_step_operation[chaser_selected][piste][step_of]=0;
            }

        }
        refresh_launchpad_on_chaser();
    }

    if(control==1113)//launchpad pos minus
    {
        chaser_step_launchpad[chaser_selected]--;
        if(chaser_step_launchpad[chaser_selected]<0)
        {
            chaser_step_launchpad[chaser_selected]=0;
        }
    }
    if(control==1114)//launchpad pos plus
    {
        chaser_step_launchpad[chaser_selected]++;
        if(chaser_step_launchpad[chaser_selected]>nbre_de_cases_par_track-8 )
        {
            chaser_step_launchpad[chaser_selected]=nbre_de_cases_par_track-8;
        }

    }

    if(control>=1115 && control <=1162  && midi_levels[control]>0)//Faders: Play embeded chaser //etait 1163 possible debordement aout 2016
    {
        int the_chaser;
        int the_grid_player;
        int the_audio_player;

        if ( DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]]==11) the_chaser=ChaserAffectedToDck[control-1115][dock_used_by_fader_is[control-1115]];
        else if ( DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]]==12 )  the_grid_player=faders_dock_grid_affectation[control-1115][dock_used_by_fader_is[control-1115]];
        else if( DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]]==6 ) the_audio_player=DockHasAudioVolume[control-1115][dock_used_by_fader_is[control-1115]]-1;
        else if ( DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]]==7 ) the_audio_player=DockHasAudioPan[control-1115][dock_used_by_fader_is[control-1115]]-1;
        else if ( DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]]==8 ) the_audio_player=DockHasAudioPitch[control-1115][dock_used_by_fader_is[control-1115]]-1;

        switch(DockTypeIs[control-1115][dock_used_by_fader_is[control-1115]])
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
                        player1_do_stop();
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
                        player2_do_stop();
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
                        player3_do_stop();
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
                        player4_do_stop();
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
                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",control-1115+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",control-1115+1,the_audio_player+1);
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
                        player1_do_stop();
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
                        player2_do_stop();
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
                        player3_do_stop();
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
                        player4_do_stop();
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
                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",control-1115+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",control-1115+1,the_audio_player+1);
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
                        player1_do_stop();
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
                        player2_do_stop();
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
                        player3_do_stop();
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
                        player4_do_stop();
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
                    sprintf(string_Last_Order,">> PLAY ON from Fader %d Audio %d",control-1115+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> PLAY OFF from Fader %d Audio %d",control-1115+1,the_audio_player+1);
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
                sprintf(string_Last_Order,">> PLAY OFF from Fader %d Chaser %d",control-1115+1,the_chaser+1);
                break;
            case 1:
                sprintf(string_Last_Order,">> PLAY ON from Fader %d Chaser %d",control-1115+1,the_chaser+1);
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
                sprintf(string_Last_Order,">> PLAY OFF from Fader %d GridPl %d",control-1115+1,the_grid_player+1);
                break;
            case 1:
                sprintf(string_Last_Order,">> PLAY ON from Fader %d GridPl %d",control-1115+1,the_grid_player+1);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

    }
    if(control>=1164 && control <=1211  && midi_levels[control]>0)//Faders: Seek to beg embeded chaser //etait 1212 possible debordement aout 2016
    {
        int the_chaser;
        int the_grid_player;
        int the_audio_player;

        if ( DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]]==11) the_chaser=ChaserAffectedToDck[control-1164][dock_used_by_fader_is[control-1164]];
        else if ( DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]]==12 )  the_grid_player=faders_dock_grid_affectation[control-1164][dock_used_by_fader_is[control-1164]];
        else if( DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]]==6 ) the_audio_player=DockHasAudioVolume[control-1164][dock_used_by_fader_is[control-1164]]-1;
        else if ( DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]]==7 ) the_audio_player=DockHasAudioPan[control-1164][dock_used_by_fader_is[control-1164]]-1;
        else if ( DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]]==8 ) the_audio_player=DockHasAudioPitch[control-1164][dock_used_by_fader_is[control-1164]]-1;

        switch(DockTypeIs[control-1164][dock_used_by_fader_is[control-1164]])
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
                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",control-1164+1,the_audio_player+1);
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
                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",control-1164+1,the_audio_player+1);
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
                sprintf(string_Last_Order,">> Seek from Fader %d AudioPl %d",control-1164+1,the_audio_player+1);
            }
            break;
        case 11://chaser
            chaser_seek_at_beg(the_chaser);
            sprintf(string_Last_Order,">> Seek To Beg from Fader %d Chaser %d",control-1164+1,the_chaser+1);
            break;
        case 12://grid
            gridplayer_seek(the_grid_player);
            sprintf(string_Last_Order,">> Seek from Fader %d GridPl %d",control-1164+1,the_grid_player+1);
            break;
        default:
            break;
        }
    }


    if(control>=1213 && control <=1263  && midi_levels[control]>0)//Faders: Seek to beg embeded chaser //etait 1264 possible debordement aout 2016
    {


        int the_chaser;
        int the_grid_player;
        int the_audio_player;

        if ( DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]]==11) the_chaser=ChaserAffectedToDck[control-1213][dock_used_by_fader_is[control-1213]];
        else if ( DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]]==12 )  the_grid_player=faders_dock_grid_affectation[control-1213][dock_used_by_fader_is[control-1213]];
        else if( DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]]==6 ) the_audio_player=DockHasAudioVolume[control-1213][dock_used_by_fader_is[control-1213]]-1;
        else if ( DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]]==7 ) the_audio_player=DockHasAudioPan[control-1213][dock_used_by_fader_is[control-1213]]-1;
        else if ( DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]]==8 ) the_audio_player=DockHasAudioPitch[control-1213][dock_used_by_fader_is[control-1213]]-1;

        switch(DockTypeIs[control-1213][dock_used_by_fader_is[control-1213]])
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
                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",control-1213+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",control-1213+1,the_audio_player+1);
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
                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",control-1213+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",control-1213+1,the_audio_player+1);
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
                    sprintf(string_Last_Order,">> LOOP OFF from Fader %d Audio %d",control-1213+1,the_audio_player+1);
                    break;
                case 1:
                    sprintf(string_Last_Order,">> LOOP ON from Fader %d Audio %d",control-1213+1,the_audio_player+1);
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
                sprintf(string_Last_Order,">> LOOP OFF from Fader %d Chaser %d",control-1213+1, the_chaser+1);
                break;
            case 1:
                sprintf(string_Last_Order,">> LOOP ON from Fader %d Chaser %d",control-1213+1, the_chaser+1);
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
                sprintf(string_Last_Order,">> AutoStop OFF from Fader %d Gpl %d",control-1213+1, the_grid_player+1);
                break;
            case 1:
                sprintf(string_Last_Order,">> AutoStop ON from Fader %d Gpl %d",control-1213+1, the_grid_player+1);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

    }

    /*1265 1266 iCatPage - +
    1267 ->1274 iCatpage Num
    1275 icat Oreintation
    1276 icat refresh page construction*/
    if(control>=1265 && control<=1276 && enable_iCat==1 && iCat_serveur_is_initialized==1)
    {
        if(control==1265 &&  midi_levels[control]>0 )
        {
            iCatPageis--;
            if(iCatPageis<0)
            {
                iCatPageis=7;
            }
            load_iCat_page(iCatPageis);
            do_send_icat_init_page=1;
        }
        if(control==1266 &&  midi_levels[control]>0 )
        {
            iCatPageis++;
            if(iCatPageis>7)
            {
                iCatPageis=0;
            }
            load_iCat_page(iCatPageis);
            do_send_icat_init_page=1;
        }
        if(control>=1267 && control<=1274 &&  midi_levels[control]>0 )    //page num
        {
            iCatPageis=control-1267;
            load_iCat_page(iCatPageis);
            do_send_icat_init_page=1;
        }
        if(control==1275 &&  midi_levels[control]>0 )
        {
            iCat_preset_orientation[iCatPageis]++;
            if(iCat_preset_orientation[iCatPageis]>2)
            {
                iCat_preset_orientation[iCatPageis]=0;
            }
            if(iCat_preset_orientation[iCatPageis]==0)
            {
                L_tablier_iCat=160;
                H_tablier_iCat=240;
            }
            else
            {
                L_tablier_iCat=240;
                H_tablier_iCat=160;
            }
            do_refresh_iCat(iCatPageis);
        }
        if(control==1276 &&  midi_levels[control]>0)
        {
            do_refresh_iCat(iCatPageis);
        }
    }

    if(control==1277  )
    {
        index_midi_mute=toggle(index_midi_mute);

        switch(index_midi_mute)
        {
        case 0:
            for(int y=0; y<3072; y++)
            {
                is_raccrochage_midi_remote[y]=0;
                sprintf(string_Last_Order,">>Midi IN un-muted");
            }
            break;
        case 1:
            for(int y=0; y<3072; y++)
            {
                is_raccrochage_midi_remote[y]=1;
                sprintf(string_Last_Order,">>Midi IN muted");
            }
            break;
        }
    }

    if(control>=1278 && control<=1325)
    {
        autolaunch[control-1278]=toggle( autolaunch[control-1278] );
        switch (autolaunch[control-1278])
        {
        case 0:
            sprintf(string_Last_Order,">>Autolaunch OFF Fader %d", control-1278);
            break;
        case 1:
            sprintf(string_Last_Order,">>Autolaunch ON Fader %d", control-1278);
            break;
        }
    }



    if(control==1326)//tap
    {
        set_new_time_in_tap_tempo();
    }

    if (control==1327)//rec tap
    {
        index_recording_tap_tempo=toggle(index_recording_tap_tempo);
        if(index_recording_tap_tempo==1)
        {
            start_tempo_ticks=actual_time;
            nbr_steps_tempo=0;
            tempo_interm=0;
            sprintf(string_tap_tempo_average,"Step:   -    Global: -");
            sprintf(string_actual_tap_tempo,"Last: ");
            sprintf(string_Last_Order,"Tap Tempo Rec ON");
        }
        else sprintf(string_Last_Order,"Tap Tempo Rec Off");
    }

    if (control==1328)//set tap tempo into activ chaser
    {

        if(numeric_postext==0 && index_window_chasers==1)
        {
            set_chaser_tempo_unit(chaser_selected);
        }
        else//si chiffre de chaser tap�
        {
            int chazr=atoi(numeric);
            if(chazr>0 && chazr<127)
            {
                set_chaser_tempo_unit(chazr-1);
                numeric_postext=0;
                reset_numeric_entry();
            }
        }
        do_light_send_tap=1;
    }

    if(control>=1329 && control<1343)
    {
        switch(control)
        {
        case 1329://call wizard windod
            if(index_show_wizard_window==0)
            {
                add_a_window(W_WIZARD);
            }
            else
            {
                substract_a_window(W_WIZARD);
            }
            break;
        case 1330://call save window

            if(index_menu_save==0)
            {
                add_a_window(W_SAVE);
            }
            else
            {
                substract_a_window(W_SAVE);
            }
            break;
        case 1331: // patch
            if(index_patch_window==0)
            {
                add_a_window(W_PATCH);
            }
            else
            {
                substract_a_window(W_PATCH);
            }
            break;
        case 1332: //list
            if(index_list_projecteurs==0)
            {
                add_a_window(W_LIST);
            }
            else
            {
                substract_a_window(W_LIST);
            }
            break;
        case 1333: //direct CH
            if(index_direct_chan==0 && multiple_direct_chan==0)
            {
                reset_index_actions();
                reset_indexs_confirmation();
                index_direct_chan=1;
                index_do_dock=index_direct_chan;
            }
            else if(index_direct_chan==1 && multiple_direct_chan==0)
            {
                index_direct_chan=1;
                multiple_direct_chan=1;
                index_do_dock=1;
            }
            else if(index_direct_chan==1 && multiple_direct_chan==1)
            {
                reset_index_actions();
                reset_indexs_confirmation();
            }
            break;
        case 1334: // view
            index_inspekt=toggle(index_inspekt);
            i_m_over_a_track=0;
            break;
        case 1335: // freeze
            index_do_freeze=1;
            index_ask_confirm=1;
            break;
        case 1336: // minifaders
            if(index_show_minifaders==0)
            {
                add_a_window(W_MINIFADERS);
            }
            else
            {
                substract_a_window(W_MINIFADERS);
            }
            break;
        case 1337: //chasers
            if(index_window_chasers==0)
            {
                add_a_window(W_CHASERS);
            }
            else
            {
                substract_a_window(W_CHASERS);
            }
            break;
        case 1338: //numeric pad
            if(index_visual_pad==0)
            {
                add_a_window(W_NUMPAD);
            }
            else
            {
                substract_a_window(W_NUMPAD);
            }
            break;
        case 1339: //Mover
            //sab 02/03/2014 IMPACT if(index_show_mover_window=0){add_a_window(W_MOVER);}
            if(index_show_mover_window==0)
            {
                add_a_window(W_MOVER);
            }
            else
            {
                substract_a_window(W_MOVER);
            }
            break;
        case 1340: //grider
            if(index_grider_window==0)
            {
                add_a_window(W_GRID);
            }
            else
            {
                substract_a_window(W_GRID);
            }
            break;
        case 1341: //iCat builder view
            if(index_window_gui_iCat==0)
            {
                add_a_window(W_iCAT);
            }
            else
            {
                substract_a_window(W_iCAT);
            }
            break;
        case 1342: //help
            index_call_help=toggle(index_call_help);
            if(index_call_help==1)
            {
                system("start /max /wait file:///C:/white_cat/doc/export/introduction.htm");
            }
            index_call_help=0;
            break;
        default:
            break;
        }
    }
    if(control>=1343 && control<=1470)
    {
        bang_is_sended[control-1343]=toggle(bang_is_sended[control-1343]);
        switch (bang_is_sended[control-1343])
        {
        case 0://reset des send events et on demarre � la souris le banger
            for (int y=0; y<6; y++)
            {
                event_sended[control-1343][y]=0;
            }
            start_time_for_banger[control-1343]=actual_time;

            for (int y=0; y<6; y++)
            {
                if(bangers_delay[control-1343][y]> end_time_for_banger[control-1343])
                {
                    end_time_for_banger[control-1343]= bangers_delay[control-1343][y];
                }
            }
            if(end_time_for_banger[control-1343]<default_time_of_the_bang)
            {
                end_time_for_banger[control-1343]=default_time_of_the_bang;
            }
            last_banger_sended_manually=control-1343;
            break;
        case 1://go back sur le banger
            for (int y=0; y<6; y++)
            {
                if(bangers_type[control-1343][y]!=0 )
                {
                    Bang_event_back(control-1343, y);
                    event_sended[control-1343][y]=1;
                }
            }
            bang_is_sended[control-1343]=1;//bloquage de l envoi des autres �v�nements
            break;
        }
    }

    if(control>=1472 && control<=1475)
    {
        if(control-1472<=core_user_define_nb_gridplayers)
        {
            index_show_grid_player[control-1472]=toggle(index_show_grid_player[control-1472]);
        }
        refresh_hauteur_fenetre_grider();
    }
    if(control>=1476 && control<=1479 )//grid minus
    {
        int num_grider=control-1476;
        if(index_grider_selected[num_grider]>0)
        {
            index_grider_selected[num_grider]--;
        }
    }
    if(control>=1480 && control<=1483 )//grid plus
    {
        int num_grider=control-1480;
        if(index_grider_selected[num_grider]<127)
        {
            index_grider_selected[num_grider]++;
        }
    }
    if(control>=1484 && control<=1487 )//step minus
    {
        int num_grider=control-1484;
        gridplayer_step_minus(num_grider);
    }
    if(control>=1488 && control<=1491 )//step plus
    {
        int num_grider=control-1488;
        gridplayer_step_plus(num_grider);
    }
    if(control>=1492 && control<=1495 )//play gridplayer
    {
        int num_grider=control-1492;
        grider_is_playing[num_grider]=toggle(grider_is_playing[num_grider]);
        if(grider_is_playing[num_grider])
        {
            grid_crossfade_start_time[num_grider]=actual_time;
        }
    }
    if(control>=1496 && control<=1499 )// seek gridplayer
    {
        int num_grider=control-1496;
        gridplayer_seek(num_grider);
    }
    if(control>=1500 && control<=1503 )// autostop gridplayer
    {
        int num_grider=control-1500;
        grider_autostopmode[num_grider]=toggle(grider_autostopmode[num_grider]);
    }

    if(control>=1504 && control<=1507 )// slave mode
    {
        int num_grider=control-1504;
        grid_player_slave[num_grider]=toggle(grid_player_slave[num_grider]);
    }

    if(control>=1508 && control<=1511 )// grid accelerometer speed
    {
        int num_grider=control-1508;
        if(grid_player_slave[num_grider]==0 )
        {
            grid_crossfade_speed[num_grider]=midi_levels[control];
            if(grid_crossfade_speed[num_grider]<0)
            {
                grid_crossfade_speed[num_grider]=0;
            }
            else  if(grid_crossfade_speed[num_grider]>127)
            {
                grid_crossfade_speed[num_grider]=127;
            }
            if(num_grider==0 && index_link_speed_crossfade_to_gpl1==1)
            {
                grid_crossfade_speed[num_grider]=crossfade_speed;
            }
            gridder_prepare_cross(num_grider,index_grider_selected[num_grider],index_grider_step_is[num_grider]);
        }
    }


    if(control>=1512 && control<=1515 )////Goto mode
    {
        int num_grider=control-1512;
        grider_goto_mode[num_grider]=toggle(grider_goto_mode[num_grider]);
    }
    if(control>=1516 && control<=1519 )//count mode
    {
        int num_grider=control-1516;
        grider_count_mode[num_grider]=toggle(grider_count_mode[num_grider]);
    }

    if(control>=1520 && control<=1523)//on off seek
    {
        int num_grider=control-1520;
        grider_seekto_mode[num_grider]=toggle(grider_seekto_mode[num_grider]);
    }

    if(control>=1524 && control<=1527 )//stoplplay mode
    {
        int num_grider=control-1524;
        grider_stoplay_mode[num_grider]=toggle(grider_stoplay_mode[num_grider]);
    }

    if(control>=1528 && control<=1531 )//grid is
    {
        int num_grider=control-1528;
        index_grider_selected[num_grider]=midi_levels[control];
    }


    if(control>=1532 && control<=1535 )//step is +127
    {
        int num_grider=control-1532;
        index_grider_step_is[num_grider]=midi_levels[control]+(grid_midi_multiple_for_step_call[num_grider]*7);
        grid_niveauX1[num_grider]=255;
        grid_niveauX2[num_grider]=0;
        grid_floatX1[num_grider]=grid_niveauX1[num_grider];
        grid_floatX2[num_grider]=grid_niveauX2[num_grider];
        gridder_prepare_cross(num_grider, index_grider_selected[num_grider], index_grider_step_is[num_grider]);
        if(grider_is_playing[num_grider]==1)
        {
            grid_crossfade_start_time[num_grider]=actual_time;
        }
    }


    if(control>=1536 && control<=1539 )//step is *7
    {
        int num_grider=control-1536;
        grid_midi_multiple_for_step_call[num_grider]=midi_levels[control];
    }

    if(control==1540)//on off asservissement speed sequenciel sur gridplayer 1
    {
        index_link_speed_crossfade_to_gpl1=toggle(index_link_speed_crossfade_to_gpl1);
        if(index_link_speed_crossfade_to_gpl1==1)
        {
            grid_crossfade_speed[0]=crossfade_speed;
            midi_levels[1508]=crossfade_speed;
        }
    }

    if(control==1541)//do exlcude channels from GM
    {
        index_do_exclude=1;
        index_ask_confirm=1;
    }

    if(control==1542)
    {
        index_do_hipass=toggle( index_do_hipass);
        index_inspekt=index_do_hipass;
    }

    if(control>=1543 && control<=1590)
    {
        int fad=control-1543;
        fader_mode_with_buffers[fad]++;
        if(fader_mode_with_buffers[fad]>5)
        {
            fader_mode_with_buffers[fad]=0;
        }
    }

    if(control==1591)
    {
        auto_reset_crossfade_speed_on_link=toggle(auto_reset_crossfade_speed_on_link);
    }

    if(control==1592)
    {
        if(index_do_fgroup==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_do_fgroup=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_do_fgroup;
    }


    if(control==1593)
    {
        index_global_midi_send_on_faders=toggle(index_global_midi_send_on_faders);
        set_all_faders_midi_out(index_global_midi_send_on_faders);
        do_light_midi_send_on_faders=1;
    }


    if(control>=1594 && control<=1622)
    {
        if(control==1594)
        {
            index_plot_window=toggle(index_plot_window);
            switch( index_plot_window)
            {
            case 0:
                substract_a_window(W_PLOT);
                break;
            case 1:
                add_a_window(W_PLOT);
                break;
            default:
                break;
            }
        }

        else if(control==1595)
        {
            plot_index_show_levels=toggle(plot_index_show_levels);
        }

        else if(control==1596)
        {
            plot_index_show_levels_from_faders=toggle(plot_index_show_levels_from_faders);
        }

        else if(control==1597)//UP
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                shape_selected_type++;
                if(shape_selected_type>max_shape_type)
                {
                    shape_selected_type=0;
                }
                if(index_edit_light_plot==1)
                {
                    change_shape_type(shape_selected_type);
                }
                refresh_shape_factors(shape_selected_type);
                break;
            case 2://symbols
                symbol_selected_type++;
                if(symbol_selected_type>max_symbol_type)
                {
                    symbol_selected_type=0;
                }
                if(index_edit_light_plot==1)
                {
                    change_symbol_type(view_plot_calc_number_is,symbol_selected_type);
                }
                break;
            default:
                break;
            }
        }

        else if(control==1598)//DOWN
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                shape_selected_type--;
                if(shape_selected_type<0)
                {
                    shape_selected_type=max_shape_type;
                }
                if(index_edit_light_plot==1)
                {
                    change_shape_type(shape_selected_type);
                }
                refresh_shape_factors(shape_selected_type);
                break;
            case 2://symbols
                symbol_selected_type--;
                if(symbol_selected_type<0)
                {
                    symbol_selected_type=max_symbol_type;
                }
                if(index_edit_light_plot==1)
                {
                    change_symbol_type(view_plot_calc_number_is,symbol_selected_type);
                }
                break;
            default:
                break;
            }
        }

        else if(control==1599)//SLIDER
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                shape_selected_type= midi_levels[control]/12;
                if(shape_selected_type<0)
                {
                    shape_selected_type=0;
                }
                else if(shape_selected_type>max_shape_type)
                {
                    shape_selected_type=max_shape_type;
                }
                break;
            case 2://symbols
                symbol_selected_type= midi_levels[control];
                if(symbol_selected_type<0)
                {
                    symbol_selected_type=0;
                }
                else if(symbol_selected_type>126)
                {
                    symbol_selected_type=126;
                }
                break;
            default:
                break;
            }
        }

        else if(control==1600)//ADD A SYMBOL
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                add_shape_to_plot(shape_selected_type);
                break;
            case 2://symbols
                add_a_symbol_to_plot(view_plot_calc_number_is);
                break;
            default:
                break;
            }
        }


        else if(control==1601)//ROTATE
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                angle_shape_selected=((float)midi_levels[control])/127;
                if(angle_shape_selected<0.0)
                {
                    angle_shape_selected=0.0;
                }
                if (angle_shape_selected>1.0)
                {
                    angle_shape_selected=1.0;
                }
                affect_angle_to_shapes(angle_shape_selected);
                break;
            case 2://symbols
                angle_projo_selectionne=((float)midi_levels[control])/127;
                if(angle_projo_selectionne<0.0)
                {
                    angle_projo_selectionne=0.0;
                }
                if (angle_projo_selectionne>1.0)
                {
                    angle_projo_selectionne=1.0;
                }
                affect_angle_to_symbols(view_plot_calc_number_is,angle_projo_selectionne);
                break;
            default:
                break;
            }
        }

        else if(control==1602)//DUB
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                duplicate_selected_shapes();
                break;
            case 2://symbols
                duplicate_selected_symbols(view_plot_calc_number_is);
                break;
            default:
                break;
            }
        }

        else if(control==1603)//DELETE
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                delete_selected_shapes();
                break;
            case 2://symbols
                delete_selected_symbols(view_plot_calc_number_is);
                break;
            default:
                break;
            }
        }

        else if(control==1604)//UNSELECT OU SEND TO
        {
            switch(index_menus_lighting_plot)
            {
            case 1://shapes
                unselect_all_shapes();
                break;
            case 2://symbols
                index_plot_send_to_mode=toggle(index_plot_send_to_mode);
                break;
            default:
                break;
            }
        }

        else if(control>=1605 && control<=1608)
        {
            int calc=control-1605;
            if(index_main_clear==0 && index_plot_send_to_mode==0)
            {
                switch(plot_layer_mode)
                {
                case 0:
                    show_calc_number[calc]=toggle(show_calc_number[calc]);
                    break;
                case 1:
                    for(int j=0; j<4; j++)
                    {
                        show_calc_number[j]=0;
                    }
                    show_calc_number[calc]=1;
                    view_plot_calc_number_is=calc;
                    mouse_released=1;
                    break;
                default:
                    break;
                }
                plot_generate_appareils_list();
            }
            else if(index_main_clear==1 && index_plot_send_to_mode==0)
            {
                plot_layer_selected=calc;
                index_ask_delete_symbols_on_calc=1;
                index_ask_confirm=1;
            }
            else if(index_main_clear==0 && index_plot_send_to_mode==1)
            {
                plot_layer_selected=calc;
                send_symbols_from_calc_to_calc(view_plot_calc_number_is,plot_layer_selected)     ;
                index_plot_send_to_mode=0;
                plot_layer_selected=0;
                plot_generate_appareils_list();
            }
        }

        else if(control==1609)//toggle Layer mode
        {
            plot_layer_mode=toggle(plot_layer_mode);
        }

        else if(control>=1610 && control<=1614)//les relatifs en �dition
        {
            int rx=control-1610;
            switch(mode_relatif_xy_solo)
            {
            case 0:
                adjust_xy_type[rx]=toggle(adjust_xy_type[rx]);
                break;
            case 1:
                for(int j=0; j<5; j++)
                {
                    adjust_xy_type[j]=0;
                }
                adjust_xy_type[rx]=1;
                break;
            }
        }

        if(control>=1615 && control<=1622)//preset reatifs xy
        {
            xyrelativ_preset=control-1615;
            if(index_main_clear==0)
            {
                if(index_do_dock==0 )
                {
                    affect_preset_xy_to_symbols(xyrelativ_preset);
                }
                else if(index_do_dock==1 )
                {
                    record_preset_xy_from_symbol(xyrelativ_preset);
                    reset_symbols_selected(view_plot_calc_number_is);
                    index_do_dock=0;
                }
            }
            else
            {
                index_ask_clear_preset_relativ=1;
                index_ask_confirm=1;
            }
            plot_light_preset_on_click[xyrelativ_preset]=1.0;
            last_xyrelativ_preset=xyrelativ_preset;
            xyrelativ_preset=999;
        }

    }//fin plot


    if(control==1624)//poignee
    {
        scroll_channelspace=midi_levels[control]*2;
    }


    if(control==1625)//midi affect
    {
        Midi_Faders_Affectation_Type++;//0 pas d affectation / 1 solo / 2 x8
        if(Midi_Faders_Affectation_Type>2)
        {
            Midi_Faders_Affectation_Type=0;
        }
    }

    if(control==1626)//main menu call
    {
        index_show_main_menu=toggle(index_show_main_menu);
        if( index_show_main_menu==1)
        {
            add_a_window(W_MAINMENU);
        }
        else
        {
            substract_a_window(W_MAINMENU);
        }
    }

    if(control==1627)//UP DOWN FADER SPACE
    {
        YFader=(hauteur_ecran/127)*(127-midi_levels[control]) ;
    }

    if(control>=1628 && control<= 1643)
    {
        if(ClassicalChannelView==1)
        {
            ClassicalChannelView=0;
            if(Channel_View_MODE[control-1628]==0)
            {
                Channel_View_MODE[control-1628]=1;
            }
        }
        else
        {
            Channel_View_MODE[control-1628]=toggle(Channel_View_MODE[control-1628]);
            ClassicalChannelView=0;
        }
    }

    if(control==1644)//Classical View
    {
        ClassicalChannelView=toggle(ClassicalChannelView);
    }

    if(control==1645)//Sequenciel GOTO
    {
        int index_atoi=0;
        if(numeric_postext>0)
        {
            index_atoi=(int)(atof(numeric)*10);
            if(MemoiresExistantes[index_atoi]==1)
            {
                position_preset=index_atoi;
                refresh_mem_onpreset(position_preset);
                reset_numeric_entry();
                numeric_postext=0;
            }
        }
    }


    if(control>=1646 && control<=1651)//preset choice
    {
        draw_preset_selected=control-1646;
        recalculate_draw_sizes(draw_preset_selected);
    }
    if(control==1652)//draw mode
    {
        draw_mode[draw_preset_selected]++;
        if(draw_mode[draw_preset_selected]>3)
        {
            draw_mode[draw_preset_selected]=0;
        }
    }
    if(control==1653)//pressure
    {
        draw_level_to_do[draw_preset_selected]=((float)(midi_levels[control])/127);
    }
    if(control==1654)//damper decay factor
    {
        previous_draw_damper_decay_factor[draw_preset_selected]=draw_damper_decay_factor[draw_preset_selected];
        draw_damper_decay_factor[draw_preset_selected]=((float)(midi_levels[control])/127);
    }

    if(control==1655)//ghost
    {
        previous_draw_ghost_to_do[draw_preset_selected]=draw_ghost_to_do[draw_preset_selected];
        draw_ghost_to_do[draw_preset_selected]=((float)(midi_levels[control])/127);
    }



    if(control==1657)//erase drawing
    {
        draw_erase_drawing(draw_preset_selected);
    }

    if(control==1658)//brush type
    {
        draw_brush_type[draw_preset_selected]=toggle(draw_brush_type[draw_preset_selected]);
        switch(draw_brush_type[draw_preset_selected])
        {
        case 0:
            sprintf(string_Last_Order,"DOT brush selected");
            break;
        case 1:
            sprintf(string_Last_Order,"GridPlayer selected");
            break;
        default:
            break;
        }
    }


    if(control==1659)//commande fenetre draw
    {
        index_draw_window=toggle(index_draw_window);
        if(index_draw_window==1)
        {
            add_a_window(W_DRAW);
            substract_a_window(W_MAINMENU);
        }
        else
        {
            substract_a_window(W_DRAW);
        }
    }

    if(control==1660)//draw midi x
    {
        int pr=draw_preset_selected;
        draw_centre_x[pr]=(int) ( ((float)midi_levels[control]/127) *(draw_preset_parameters[pr][0]-1));
        draw_centre_y[pr]=(int) ( ((float)(127-midi_levels[1661])/127) *(draw_preset_parameters[pr][1]-1));
        index_case[pr]=(draw_centre_x[pr]) + (draw_centre_y[pr]*draw_preset_parameters[pr][0]) ;
        draw_point_is_traced[pr]=1;
    }

    if(control==1661)//draw midi y
    {
        int pr=draw_preset_selected;
        draw_centre_x[pr]=(int) ( ((float)midi_levels[1660]/127) *(draw_preset_parameters[pr][0]-1));
        draw_centre_y[pr]=(int) ( ((float)(127-midi_levels[control])/127) *(draw_preset_parameters[pr][1]-1));
        index_case[pr]=(draw_centre_x[pr]) + (draw_centre_y[pr]*draw_preset_parameters[pr][0]) ;
        draw_point_is_traced[pr]=1;
    }

    if(control==1662)//commande fenetre echo
    {
        index_show_echo_window=toggle(index_show_echo_window);
        if(index_show_echo_window==1)
        {
            add_a_window(W_ECHO);
        }
        else
        {
            substract_a_window(W_ECHO);
        }
    }

    if(control>=1663 && control<=1685)//les echos presets
    {
        int index_ec=control-1663;
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

    if(control>=1686 && control<=1690)//les 4 actions de bounce etc
    {
        switch(control-1686)
        {
        case 0:
            echo_is_echo_mode[echo_selected]=toggle(echo_is_echo_mode[echo_selected]);
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



    if(control==1691)//prev chan
    {
        if(echo_grid_channel_position[echo_selected]>0)
        {
            echo_grid_channel_position[echo_selected]--;
        }
    }
    if(control==1692)//next chan
    {
        if(echo_grid_channel_position[echo_selected]<(511-14))
        {
            echo_grid_channel_position[echo_selected]++;
        }
    }

    if(control>=1693 && control<= 1695)
    {
        echo_global_params[echo_selected][control-1693]= (float)(midi_levels[control])/127;
    }

    if(control==1696)//mode level ou ground pour l �dition de channel
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

    if(control>=1800 && control<=1824)
    {
        if(control>=1800 && control<=1804)//autoload
        {
            int lect=control-1800;
            audio_autoload[lect]=toggle(audio_autoload[lect]);
        }
        if(control>=1805 && control<=1808)//autostop
        {
            int lect=control-1805;
            audio_autopause[lect]=toggle(audio_autopause[lect]);
        }

        if(control>=1809 && control<=1812  )//load file
        {
            int lect=control-1809;
            audiofile_selected=(int)midi_levels[control];
            if( audiofile_selected>0  && audiofile_selected<127 )
            {

                sprintf(audiofile_name,list_audio_files[audiofile_selected]);
                if(strcmp (audiofile_name,"")!=0)
                {
                    AffectSoundFile(lect);
                }
            }
        }

        if(control>=1813 && control<=1816)//prev track
        {
            int lect=control-1813;
            if(player_ignited[lect]==1 && index_loading_a_sound_file==0)
            {
                /*midi_levels[control]=0;
                control=-1;
                index_loading_a_sound_file=1;
                audiofile_selected=player_has_file_coming_from_pos[lect]-1;
                player_has_file_coming_from_pos[lect]=audiofile_selected;
                if(audiofile_selected<1){audiofile_selected=1;}
                sprintf(audiofile_name,list_audio_files[audiofile_selected]);
                if(strcmp (audiofile_name,"")!=0)
                {
                AffectSoundFile(lect);
                }
                */
                midi_levels[control]=0;
                control=-1;
                audio_do_load_midi_prev_file[lect]=1;
            }
        }

        if(control>=1817 && control<=1820)//next track
        {
            int lect=control-1817;
            if(player_ignited[lect]==1 && index_loading_a_sound_file==0)
            {
                /*midi_levels[control]=0;
                control=-1;
                index_loading_a_sound_file=1;
                audiofile_selected=player_has_file_coming_from_pos[lect]+1;
                player_has_file_coming_from_pos[lect]=audiofile_selected;
                if(audiofile_selected>=audio_number_total_in_folder){audiofile_selected=audio_number_total_in_folder;}
                sprintf(audiofile_name,list_audio_files[audiofile_selected]);
                if(strcmp (audiofile_name,"")!=0 )
                {
                AffectSoundFile(lect);
                }
                */
                midi_levels[control]=0;
                control=-1;
                audio_do_load_midi_next_file[lect]=1;
            }
        }
        if(control>=1821 && control<=1824)
        {
            int lect=control-1821;
            if(player_ignited[lect]==1 && index_loading_a_sound_file==0)
            {
                switch(lect)
                {
                case 0://PLAYER 1
                    player1->setPosition(length_of_file_in_player[lect]-1000);
                    break;
                case 1://PLAYER 2
                    player2->setPosition(length_of_file_in_player[lect]-1000);
                    break;
                case 2://PLAYER 3
                    player3->setPosition(length_of_file_in_player[lect]-1000);
                    break;
                case 3://PLAYER 4
                    player4->setPosition(length_of_file_in_player[lect]-1000);
                    break;
                default:
                    break;
                }
            }
        }
    }
    if(control == 1825 )//check minus
    {
        index_false_control= 1;
        index_false_shift=0;
        simulate_keypress(KEY_LEFT<<8);
    }
    if( control == 1826 )//check plus
    {
        index_false_control= 1;
        index_false_shift=0;
        simulate_keypress(KEY_RIGHT<<8);
    }
    if(control == 1827 )//at full
    {
        simulate_keypress(KEY_I<<8);
        index_false_shift=0;
        index_false_control=0;
    }
    if(control == 1828 )//at zero
    {
        simulate_keypress(KEY_O<<8);
        index_false_shift=0;
        index_false_control=0;
        sprintf(string_Last_Order,"Midi simulate FULL");
    }

    if(control == 1829 )//window WAVE
    {
        if(index_wave_menu_window==0)
        {
            add_a_window(W_WAVE);
        }
        else
        {
            substract_a_window(W_WAVE);
        }
        rest(midi_keyboard_wait);
    }

    if(control>=1830 && control<=1830+63)//arduino analogic on/off
    {
        int d=control-1830;
        ventilate_analog_data[d]=toggle(ventilate_analog_data[d]);
    }



    if(control ==1894)
    {
        do_clock_level_modification(midi_levels[1894]);

        angle_snap_clock=(((PIknob*2)+angle_correction_wheel) / 128)*midi_levels[1894];
        clock_vx = cos(angle_snap_clock)* rayon_wheel_level;
        clock_vy = sin(angle_snap_clock)* rayon_wheel_level;
        position_curseur_clock_x= window_cfgX+770+clock_vx;
        position_curseur_clock_y=window_cfgY+115+clock_vy ;

    }

    if(control>=1895 && control <=1911)
    {
        int cl=control-1895;

        if(bpm_personnal[cl]>0)
        {
            midi_BPM=bpm_personnal[cl];
            ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
            install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
        }
    }


    if(control>=1912 && control <=1959)
    {
        if(fader_damper_is_on[control-1912]==0)
        {
            Fader_dampered[control-1912].fix_all_damper_state_value(Fader[control-1912]);
            Fader_dampered[control-1912].set_target_val(Fader[control-1912]);
        }
        fader_damper_is_on[control-1912]=toggle(fader_damper_is_on[control-1912]);
        if(fader_damper_is_on[control-1912]==1)
        {
            index_fader_is_manipulated[control-1912]=1;
        }
    }

    if(control>=1960 && control <=2007)
    {
        Fader_dampered[control-1960].set_damper_decay((((float)midi_levels[control])/127));
    }
    if(control>=2008 && control <=2055)
    {
        Fader_dampered[control-2008].set_damper_mode((Fader_dampered[control-2008].getdampermode()+1));
    }

    if(control>=2056 && control <=2113)
    {
        Fader_dampered[control-2056].set_damper_dt((((float)midi_levels[control])/127)/10);
    }

    if(control==2114) //level damper decay wave
    {
        float u=1.0-((float)(midi_levels[control])/127);
        for(int i=0; i<26; i++)
        {
            Wave_Dampered[i].set_damper_decay(u);
        }
    }

    if(control==2115) //level damper delta wave
    {
        float u=(1.0-(((float)midi_levels[control])/127))/10;
        for(int i=0; i<26; i++)
        {
            Wave_Dampered[i].set_damper_dt(u);
        }
    }

    if(control==2116) //mode damper delta wave bouton
    {
        Wave_Dampered[0].set_damper_mode(Wave_Dampered[0].getdampermode()+1);
        int u=Wave_Dampered[0].getdampermode();
        for(int i=1; i<26; i++)
        {
            Wave_Dampered[i].set_damper_mode(u);
        }
    }

    if(control==2117) //slider du wave wavecontroller
    {
        waver_control=((float)midi_levels[control]*2)/10 ;
        waver_control=constrain_int_data_to_this_range(waver_control, 0,26);
        wave_calculations();

    }

    return(0);
}
