int launchpad_refresh_buffer_led()
{
    for(int i=0; i<48; i++)
    {
        midi_launchpad_state[i+146]=FaderLocked[i];
        if(lfo_mode_is[i]==0)
        {
            midi_launchpad_state[i+245]=0;
            midi_launchpad_state[i+294]=0;
            midi_launchpad_state[i+343]=0;
        }
        else if(lfo_mode_is[i]==1)
        {
            midi_launchpad_state[i+245]=1;
            midi_launchpad_state[i+294]=0;
            midi_launchpad_state[i+343]=0;
        }
        else if(lfo_mode_is[i]==2)
        {
            midi_launchpad_state[i+294]=1;
            midi_launchpad_state[i+245]=0;
            midi_launchpad_state[i+343]=0;
        }
        if(lfo_cycle_is_on[i]==1)
        {
            midi_launchpad_state[i+343]=1;
            midi_launchpad_state[i+294]=0;
            midi_launchpad_state[i+245]=0;
        }
        midi_launchpad_state[i+392]=lfo_do_next_step[i][0];
        midi_launchpad_state[i+441]=lfo_do_next_step[i][1];
        midi_launchpad_state[i+499]=lfo_cycle_steps[i];
        midi_launchpad_state[i+685]=ActionnateStopOn[i];
        midi_launchpad_state[i+900]=FaderIsFlash[i];
        midi_launchpad_state[i+802]=is_dock_for_lfo_selected[i][(dock_used_by_fader_is[i])];
        if( is_dock_for_lfo_selected[i][0]==1 && is_dock_for_lfo_selected[i][1]==1 && is_dock_for_lfo_selected[i][2]==1 &&
                is_dock_for_lfo_selected[i][3]==1 && is_dock_for_lfo_selected[i][4]==1 && is_dock_for_lfo_selected[i][5]==1 )
        {
            midi_launchpad_state[i+851]=1;
        }
        else
        {
            midi_launchpad_state[i+851]=0;
        }

        midi_launchpad_state[i+1115]=chaser_is_playing[ChaserAffectedToDck[i][dock_used_by_fader_is[i]]];//Play
        midi_launchpad_state[i+1213]=chaser_is_in_loop[ChaserAffectedToDck[i][dock_used_by_fader_is[i]]];//loop
    }

    if(index_go==1)
    {
        switch(index_pause)
        {
        case 0:
            midi_launchpad_state[495]=1;
            launchpad_is_a_cycling_effect[495]=0;
            launchpad_color_defined[495]=lch_red;
            break;
        case 1:
            midi_launchpad_state[495]=1;
            launchpad_is_a_cycling_effect[495]=1;
            launchpad_color_defined[495]=lch_red;
            break;
        default:
            break;
        }
    }
    else if(index_go==0)
    {
        midi_launchpad_state[495]=0;
        launchpad_is_a_cycling_effect[495]=0;
    }

    if(index_go_back==1)
    {
        midi_launchpad_state[494]=1;
        launchpad_color_defined[494]=lch_red;
    }
    else
    {
        midi_launchpad_state[494]=0;
    }

    for(int lc=0; lc<5; lc++)
    {
        launchpad_color_defined[605+lc]=lch_green;
        midi_launchpad_state[605+lc]=lock_preset[lc];
    }

    for(int pl=0; pl<4; pl++)
    {
        midi_launchpad_state[628+pl]=player_is_playing[pl];
        midi_launchpad_state[636+pl]=player_is_onloop[pl];
        midi_launchpad_state[656+pl]=player_is_onloopCue[pl];
    }
    midi_launchpad_state[734]=1-bang_is_sended[index_banger_selected];
    if(bang_is_sended[index_banger_selected]==0)
    {
        launchpad_is_a_cycling_effect[734]=1;
    }


    midi_launchpad_state[743]=index_do_dock;
    midi_launchpad_state[744]=index_do_modify;
    midi_launchpad_state[745]=index_do_report;
    midi_launchpad_state[746]=index_main_clear;
    midi_launchpad_state[747]=index_type;
    midi_launchpad_state[748]=index_time;
    midi_launchpad_state[749]=index_trichro_window;
    midi_launchpad_state[750]=index_video_window;
    midi_launchpad_state[751]=index_window_sequentiel;
    midi_launchpad_state[752]=index_show_faders;
    midi_launchpad_state[753]=index_show_banger_window;
    midi_launchpad_state[754]=index_blind;
    midi_launchpad_state[755]=index_show_config_window;
    midi_launchpad_state[756]=index_show_audio_window;

    for(int p=0; p<4; p++)
    {
        midi_launchpad_state[760+p]=index_type_of_time_to_affect[p] ;
    }
    for (int co=0; co<8; co++)
    {
        if(dock_color_selected!=co)
        {
            midi_launchpad_state[949+co]=0;
        }
        else
        {
            midi_launchpad_state[949+co]=1;
        }
    }


    for(int u=0; u<12; u++)
    {
        midi_launchpad_state[957+u]=tracking_spaces_on_off[tracking_dock_selected][u];
    }
    for(int d=0; d<5; d++)
    {
        if(tracking_dock_selected!=d)
        {
            midi_launchpad_state[969+d]=0;
        }
        else
        {
            midi_launchpad_state[969+d]=1;
        }
    }

    for(int op=0; op<8; op++) //presets minifaders
    {
        if(mf_preset_selected_is==op && minifader_preset_is_empty[op]==0)
        {
            midi_launchpad_state[794+op]=1;
        }
        else
        {
            midi_launchpad_state[794+op]=0;
        }
    }
    midi_launchpad_state[978]=chaser_is_playing[chaser_selected];
    midi_launchpad_state[980]=chaser_is_in_loop[chaser_selected];
    switch (chaser_way[chaser_selected])
    {
    case 0:
        midi_launchpad_state[981]=1;
        midi_launchpad_state[982]=0;
        break;
    case 1:
        midi_launchpad_state[981]=0;
        midi_launchpad_state[982]=1;
        break;
    default:
        break;
    }
    midi_launchpad_state[983]=chaser_aller_retour[chaser_selected];
    midi_launchpad_state[994]=chaser_time_mode[chaser_selected];

    switch (chaser_operator_is)
    {
    case 0:
        midi_launchpad_state[991]=0;
        midi_launchpad_state[992]=0;
        midi_launchpad_state[993]=0;
        break;
    case 1:
        midi_launchpad_state[991]=1;
        midi_launchpad_state[992]=0;
        midi_launchpad_state[993]=0;
        break;
    case 2:
        midi_launchpad_state[991]=0;
        midi_launchpad_state[992]=1;
        midi_launchpad_state[993]=0;
        break;
    case 3:
        midi_launchpad_state[991]=0;
        midi_launchpad_state[992]=0;
        midi_launchpad_state[993]=1;
        break;
    default:
        break;
    }


    for(int yo=0; yo<24; yo++)
    {
        midi_launchpad_state[998+yo]=track_is_on[chaser_selected][yo];    //on off des tracks

    }

    for(int yo=0; yo<8; yo++)
    {
        if(yo==iCatPageis)
        {
            midi_launchpad_state[1267+yo]=1;   //on iCat preset
        }
        else
        {
            midi_launchpad_state[1267+yo]=0;
        }
    }

    midi_launchpad_state[1277]=index_midi_mute;    //midi mute general


    midi_launchpad_state[1329]=index_show_wizard_window;
    midi_launchpad_state[1330]=index_menu_save ;
    midi_launchpad_state[1331]=index_patch_window ;
    midi_launchpad_state[1332]=index_list_projecteurs ;
    midi_launchpad_state[1333]=index_direct_chan ;
    midi_launchpad_state[1334]=index_inspekt ;
    midi_launchpad_state[1335]=index_do_freeze ;
    midi_launchpad_state[1336]=index_show_minifaders ;
    midi_launchpad_state[1337]=index_window_chasers ;
    midi_launchpad_state[1338]=index_visual_pad ;
    midi_launchpad_state[1339]=index_show_mover_window ;
    midi_launchpad_state[1340]=index_grider_window ;
    midi_launchpad_state[1341]=index_window_gui_iCat;


    for(int io=0; io<4; io++)
    {
        midi_launchpad_state[io+1472]=index_show_grid_player[io];//on off affichage players
        midi_launchpad_state[io+1492]=grider_is_playing[io];//play player
        midi_launchpad_state[io+1500]=grider_autostopmode[io];//autostop mode
        midi_launchpad_state[io+1504]=grid_player_slave[io];//slave
        midi_launchpad_state[io+1512]=grider_goto_mode[io];//macro goto
        midi_launchpad_state[io+1516]=grider_count_mode[io];//macro count
        midi_launchpad_state[io+1520]=grider_seekto_mode[io];//macro seek pos
        midi_launchpad_state[io+1524]=grider_stoplay_mode[io];//stopplay macro
    }
    midi_launchpad_state[1540]=index_link_speed_crossfade_to_gpl1;//on off asservissement sequenciel gpl1

    midi_launchpad_state[1591]=auto_reset_crossfade_speed_on_link;//auto reset crossfade speed

    for(int l=0; l<3072; l++)
    {
        if(midi_launchpad_state[l]!=midi_launchpad_state_before[l])
        {
            switch(midi_launchpad_state[l])
            {
            case 0:
                temp_launchpad=8;
                break;
            case 1:
                temp_launchpad= launchpad_color_defined[l];
                break;
            default:
                break;
            }
            if(miditable[0][l]<5 && miditable[1][l]<128 && miditable[2][l]<128)
            {
                //mode led fixe
                send_my_midi_note(miditable[0][l],miditable[1][l],miditable[2][l],temp_launchpad,1);//etait 10 en temps
            }
            midi_launchpad_state_before[l]=midi_launchpad_state[l];
        }
    }

    return(0);
}
