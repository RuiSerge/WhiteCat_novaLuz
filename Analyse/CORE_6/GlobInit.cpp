int GlobInit()
{
    index_menu_save=1;
    for(int i=0; i<24; i++)
    {
        core_do_calculations[i]=1;
    }

    clear_ip_artnet();
    if(specify_who_to_save_load[0]==1)//memoires ///////////////////////////////////
    {


        for (int m=0; m<9999; m++)
        {
            MemoiresExistantes[m]=0;
            MemoiresDetruites[m]=0;
            MemoiresExclues[m]=0;
            nbre_de_mems_manipulees=0;
            strcpy(descriptif_memoires[m],"");
            strcpy(annotation_memoires[m],"");

            descriptif_memoires[m][24]='\n';
            annotation_memoires[m][24]='\n';
            for(int i=0; i<514; i++)
            {
                Memoires[m][i]=0;
            }
        }
        position_onstage=10;
        position_preset=10;
        MemoiresExistantes[10]=1;
    }

    if(specify_who_to_save_load[1]==1)//memoires times /////////////////////////////
    {
        for (int m=0; m<9999; m++)
        {
            Times_Memoires[m][0]=0.0;
            Times_Memoires[m][2]=0.0;
            Times_Memoires[m][1]=default_time;
            Times_Memoires[m][3]=default_time;
        }
    }

    if(specify_who_to_save_load[2]==1)//memoires links//////////////////////////////
    {
        for (int m=0; m<9999; m++)
        {
            Links_Memoires[m]=0;
        }
    }

    if(specify_who_to_save_load[3]==1)//memoires banger in mem//////////////////////
    {
        for (int m=0; m<9999; m++)
        {
            Banger_Memoire[m]=0;
        }
    }


    if(specify_who_to_save_load[4]==1)//memoires  ratio manuel//////////////////////
    {
        for (int m=0; m<9999; m++)
        {
            ratio_cross_manuel[m]=0;
        }
    }




    if(specify_who_to_save_load[5]==1)//channels LIST///////////////////////////////
    {
        for(int io=0; io<514; io++)
        {
            strcpy(descriptif_projecteurs[io],"");

            descriptif_projecteurs[io][24]='\n';
            previous_state_of_outputted_channels[io]=-1;//18/12/14 christoph pour rafraichissement macros a ouv whitecat
            for(int macr=0; macr<4; macr++)
            {
                macro_channel_on[io][macr]=0;
                channel_macro_reaction[io][macr]=0;
                channel_macro_action[io][macr]=0;
                channel_macro_val[io][macr][0]=0;
                channel_macro_val[io][macr][1]=0;
            }

            for(int view_is=0; view_is<nbre_de_vues_circuits; view_is++)
            {
                Channel_View_ROUTING[view_is][io]=0;
            }
        }
        line_list_is=0;



        for(int i=0; i<nbre_de_vues_circuits; i++)
        {
            sprintf(channel_view_Name[i],"CHANNEL VIEW %d", i+1);
            channel_view_link_type[i]=0;
            channel_view_link_ref[i]=0;
            sprintf(channel_view_Name[i],"CHANNEL VIEW %d",i+1);
            channel_number_in_View[i]=0;
            channel_number_of_lines[i]=0;
            Channel_View_MODE[i]=0;
        }
        ClassicalChannelView=1;
        sprintf(channel_view_Name[0],"PATCHED CHANNELS");
    }

    if(specify_who_to_save_load[6]==1)//channels directCh///////////////////////////
    {
        for(int fd=0; fd<48; fd++)
        {
            for(int dk=0; dk<6; dk++)
            {
                if(DockTypeIs[fd][dk]==10)
                {
                    DockTypeIs[fd][dk]=9;
                }
            }
        }
    }


    if(specify_who_to_save_load[7]==1)//channels freeze exclude/////////////////////////////
    {
        for(int io=0; io<514; io++)
        {
            freeze_array[io]=0;
            freeze_state[io]=0;
            Channels_excluded_from_grand_master[io]=0;
        }
    }


    if(specify_who_to_save_load[8]==1)//patch  circuits/////////////////////////////
    {
        for(int i=0; i<514; i++)
        {
            Patch[i]=i;
            for(int llo=0; llo<4; llo++)
            {
                show_first_dim_array[i][llo]=0;
            }
            show_first_dim_array[i][0]=i;
        }
    }

    if(specify_who_to_save_load[9]==1)//patch HTP/LTP//////////////////////////////
    {
        for(int i=0; i<514; i++)
        {
            dimmer_type[i]=0;
        }
        generate_channel_view_list_from_patched_circuits();
    }

    if(specify_who_to_save_load[10]==1)//patch curves///////////////////////////////
    {
        for(int i=0; i<514; i++)
        {
            curves[i]=0;
        }
    }

    if(specify_who_to_save_load[11]==1)///banger////////////////////////////////////
    {
        for (int bg=0; bg<127; bg++) //127 max=126++
        {
            clear_banger(bg);
        }
    }


    if(specify_who_to_save_load[12]==1)//faders contents////////////////////////////
    {
        for (int in=0; in<48; in++)
        {
            Fader[in]=0;
            Fader_dampered[in].fix_all_damper_state_value(Fader[in]);
            Fader_dampered[in].set_target_val(Fader[in]);
            Fader_dampered[in].set_damper_decay(1.0);
            Fader_dampered[in].set_damper_dt(0.1);
            FaderLocked[in]=0;
            LockFader_is_FullLevel[in]=0;
            StateOfFaderBeforeLock[in]=0;
            fader_mode_with_buffers[in]=0;//fx
            fader_fx_route[in]=0;
            autolaunch[in]=0;

            for(int dd=0; dd<6; dd++)
            {
                DockTypeIs[in][dd]=9;
                DockIsSelected[in][dd]=0;//alls dock not selected
                DockHasMem[in][dd]=0;
                strcpy(DockName[in][dd],"");

                DockName[in][dd][24]='\n';
                DrawAffectedToDck[in][dd]=0;
                for(int c=0; c<514; c++)
                {
                    FaderDockContains[in][dd][c]=0;
                }
            }
            DockIsSelected[in][0]=1;//dock 1 enclench�
            dock_used_by_fader_is[in]=0;
        }
    }


    if(specify_who_to_save_load[13]==1)//faders lfos  + times//////////////////////
    {
        for (int in=0; in<48; in++)
        {
            lfo_mode_is[in]=0;
            lfo_cycle_is_on[in]=0;
            lfo_cycle_steps[in]=0;
            lfo_running_is_upward[in]=0;
            lfo_do_next_step[in][0]=0;
            lfo_do_next_step[in][1]=0; // 0 backward 1 forward
            StopPosOn[in]=0;
            LevelStopPos[in]=0;
            PreviousLevelStopPos[in]=0;//pour banger back
            ActionnateStopOn[in]=0;//activation du mode stop on
            lfo_speed[in]=64;
            do_light_setpos[in]=0;
            FaderIsFlash[in]=0;
            FaderIsFlashBefore[in]=0;
            LevelFaderBeforeFlash[in]=0;
            for(int dd=0; dd<6; dd++)
            {
                is_dock_for_lfo_selected[in][dd]=0;
                DockHasMem[in][dd]=0;
                time_per_dock[in][dd][0]=0.0;
                time_per_dock[in][dd][2]=0.0;
                time_per_dock[in][dd][1]=default_time; //IN default
                time_per_dock[in][dd][3]=default_time; //OUT default
            }
        }
    }


    if(specify_who_to_save_load[14]==1)//faders curves//////////////////////////////
    {
        for (int in=0; in<48; in++)
        {
            FaderCurves[in]=0;
        }
    }

    if(specify_who_to_save_load[15]==1)//faders Presets locks minifaders pst////////
    {
        for (int in=0; in<48; in++)
        {
            minifaders_selected[in]=0;
            for(int dp=0; dp<8; dp++)
            {
                FaderLocked_Preset[dp][in]=0;
                StateOfFaderBeforeLock_Preset[dp][in]=0;
                LockFader_is_FullLevel_Preset[dp][in]=0;
                master_lock_preset[dp]=0;
                minifaders_preset_selection[dp][in]=0;
            }
        }
        position_minifader_selected=0;
    }

    if(specify_who_to_save_load[16]==1)//chasers////////////////////////////////////
    {
        for (int l=0; l<128; l++)
        {
            strcpy(chaser_name[l],"");

            time_unit[l]=1.0;
            chaser_is_playing[l]=0;
            chaser_is_in_loop[l]=0;
            chaser_aller_retour[l]=0;
            chaser_step_is[l]=0;
            chaser_way[l]=0;
            chaser_begin_step_is[l]=0;
            chaser_end_step_is[l]=35;
            position_affichage_track_num[l]=0;
            chaser_step_launchpad[l]=0;
            view_chaser_affected_to_fader[l][0]=999;
            view_chaser_affected_to_fader[l][1]=999;
            index_slave_chaser_to_accelerometre[l]=0;
            for(int tr=0; tr<nbre_tracks_par_chaser; tr++)
            {
                track_is_on[l][tr]=0;
                track_level[l][tr]=127;
                TrackTypeIs[l][tr]=0;
                TrackHasMem[l][tr]=0;
                strcpy(chaser_track_name[l][tr],"");

                chaser_track_name[l][tr][24]='\n';
                for(int ste=0; ste<nbre_de_cases_par_track; ste++)
                {
                    chaser_step_operation[l][tr][ste]=0;
                }
            }
        }
    }



    if(specify_who_to_save_load[17]==1)//midi affect////////////////////////////////
    {
        for(int mi=0; mi<3072; mi++)
        {
            miditable[0][mi]=999;
            miditable[1][mi]=999;
            miditable[2][mi]=999;
            midi_levels[mi]=0;
            midi_send_out[mi]=0;//atribu� ou pas
            index_send_midi_out[mi]=0;
            is_raccrochage_midi_remote[mi]=0;
            val_raccrochage_midi[mi]=0;
        }
    }

    if(specify_who_to_save_load[18]==1)//midi cheat////////////////////////////////
    {
        for (int li=0; li<16; li++)
        {
            for(int u=0; u<128; u++)
            {
                midi_change_vel_type[li][u]=0;
                midi_recognize_on_off[li][u]=0;
            }
        }

        //midi clock personnal
        bpm_personnal[0]=160;
        bpm_personnal[1]=140;
        bpm_personnal[2]=120;
        bpm_personnal[3]=100;
        bpm_personnal[4]=90;
        bpm_personnal[5]=80;
        bpm_personnal[6]=70;
        bpm_personnal[7]=60;
        bpm_personnal[8]=50;
        bpm_personnal[9]=40;
        bpm_personnal[10]=30;
        bpm_personnal[11]=20;
        bpm_personnal[12]=10;
        bpm_personnal[13]=5;
        bpm_personnal[14]=2;
        bpm_personnal[15]=1;
    }


    if(specify_who_to_save_load[19]==1)//trichro/////////////////////////////////////
    {
        for(int i=0; i<8; i++)
        {
            colorpreset_linked_to_dock[i][0]=-1;
            colorpreset_linked_to_dock[i][1]=-1;
            dock_color_type[i]=0;
            angle_hue_par_colordock[i]=0.1;
            picker_trichro[i][0]=0;
            picker_trichro[i][1]=0;
            picker_trichro[i][2]=0;
            picker_trichro[i][3]=0;
            for (int c=0; c<514; c++)
            {
                dock_color_channels[i][0][c]=0;
                dock_color_channels[i][1][c]=0;
                dock_color_channels[i][2][c]=0;
                dock_color_channels[i][3][c]=0;
            }
        }
    }


    if(specify_who_to_save_load[20]==1)//video tracking//////////////////////////////
    {
        ocv_calcul_mode=1;
        tracking_dock_selected=0;
        for (int c=0; c<6; c++)
        {
            set_to_default_this_tracker(c);
            tracker_clearmode=0;

            for(int u=0; u<12; u++)
            {
                tracker_level[c][u]=0;
                tracking_spaces_on_off[c][u]=0;
            }
        }
    }




    if(specify_who_to_save_load[21]==1)//arduino/////////////////////////////////////
    {

        for(int i=0; i<digital_limit; i++)
        {
            arduino_digital_type[i]=0;
            arduino_digital_function_input[i][0]=0;
            arduino_digital_function_input[i][1]=0;
            arduino_digital_function_output[i][0]=0;
            arduino_digital_function_output[i][1]=0;
        }
        for(int i=0; i<analog_limit; i++)
        {
            arduino_analog_function_input[i]=0;
            arduino_analog_attribution_input[i]=0;
        }

        arduino_baud_rate0=14400;
        arduino_max_digital=13;
        arduino_max_analog=5;

    }

    if(specify_who_to_save_load[22]==1)//AudioConf////////////////////////////////////////
    {
        //
        sprintf(audio_folder,"demo");
        for(int i=0; i<4; i++)
        {
            audio_autoload[i]=0;
            audio_autopause[i]=0;
            player_has_file_coming_from_pos[i]=0;
            player_position_on_save[i]=0;
        }
    }

    if(specify_who_to_save_load[23]==1)//iCat////////////////////////////////////////
    {
        for(int nbp=0; nbp<8; nbp++)
        {
            clear_iCat_page(nbp);
        }
    }

    if(specify_who_to_save_load[24]==1)//windows////////////////////////////////////
    {
        index_trichro_window=0;
        index_video_window=0;
        index_video_window=0;
        index_patch_window=0;
        index_type=0;
        index_visual_pad=0;
        index_time=0;
        index_window_sequentiel=0;
        index_config_midi=0;
        midi_page=0;
        index_list_projecteurs=0;
        index_menu_save=0;
        scroll_faderspace=0;
        index_show_faders=0;
        index_config_general=0;
        index_show_audio_window=0;
        index_config_network=0;
        index_show_config_window=0;
        index_show_wizard_window=0;
        index_show_minifaders=0;
        index_window_chasers=0;
        config_page_is=0;

        index_show_mover_window=0;
        index_window_gui_iCat=0;
        window_focus_id=0;
        recall_windows_focus_id=0;
        config_page_is=0;
        index_config_dmx=1;
        index_config_arduino=0;
        reset_window_positions();
        reset_window_opened_indexes();

    }


    if(specify_who_to_save_load[25]==1)//color profile//////////////////////////////
    {
        config_color_style_is=0;
        LoadWhiteCatColorProfil();
    }


    if(specify_who_to_save_load[26]==1)//mapping keyboard///////////////////////////
    {
        for(int map=0; map<128; map++)
        {
            mapping_temporaire[map]=999;
        }
    }


    if(specify_who_to_save_load[27]==1)//indexes////////////////////////////////////
    {
        index_allow_grand_master=1;
        config_color_style_is=0;
        index_link_is_on=1;
        index_decay_tracker=0;
        cheat_key_off=0;
        index_banger_is_on=1;
        index_banger_selected=0;
        index_show_banger_window=0;
        index_allow_sunlite_dmxIN=0;//sunlite
        niveauGMaster=255;//grand master
        index_allow_multicore=0;
        allow_artnet_in=0;
        index_setup_gfx=0;
        core_to_assign=0;

        enable_launchpad=0;
        nbre_track_visualisables=8;
        chaser_operator_is=0;
        chaser_selected=0;
        index_affichage_digit_time_unit=2;
        launchpad_chaser_mode=0;
        index_enable_edit_chaser=0;
        chaser_midi_rows=8;
        line_list_is=0;
        iCatPageis=0;

        surface_type=0;//icat
        L_tablier_iCat=240;
        H_tablier_iCat=160;
        grid_icat_modulo=5;
    }




    if(specify_who_to_save_load[29]==1)//Grid////////////////////////////////////
    {
        for(int y=0; y<127; y++)
        {
            clear_a_grid(y);
        }
        //sab 02/03/2014 unsued var int grider_begin_channel_is=1;
        //sab 02/03/2014 unsued var int grider_nb_col=12;
        //sab 02/03/2014 unsued var int grider_nb_row=10;
        index_clear_a_grid_step=0;
        index_clear_a_grid=0;
        grid_to_clear=0;
        step_grid_to_clear=0;
        index_clear_a_grid_serie_step=0;
        index_for_grid_stepto=0;
        index_for_copy_grid=0;
        destination_grid_for_copy=0;
        destination_step_for_copy=0;
        index_grid_tostep_or_not=0;
        from_gridstep_to=0;
        gridplayer_to_affect_is=-1;
        for(int pl=0; pl<4; pl++)
        {
            index_grider_selected[pl]=1;
            index_grider_step_is[pl]=1;
            grider_is_playing[pl]=0;
            grider_autostopmode[pl]=0;
            grider_goto_mode[pl]=1;
            grider_seekto_mode[pl]=1;
            grider_stoplay_mode[pl]=1;
            to_step_editing_mode[pl]=0;
            index_StepTo[pl]=0;
            index_Grid_copyto[pl][0]=0;//0 grid 1 step
            index_Grid_copyto[pl][1]=0;
            grid_player_slave[pl]=0;
            grid_crossfade_speed[pl]=64;
            grid_niveauX1[pl]=255;
            grid_niveauX2[pl]=0;
            grid_floatX1[pl]=255.0;
            grid_floatX2[pl]=0;
            GplSnapFader[pl]=0;
        }
    }

    if(specify_who_to_save_load[30]==1)//Grid in mems////////////////////////////////////
    {
        for (int m=0; m<10000; m++)
        {
            set_from_seq_gridplayer1_next_step[m]=-1;
        }
    }


    if(specify_who_to_save_load[31]==1)//PLOT////////////////////////////////////
    {
        size_symbol[0]=0.3;//pc500
        sprintf(symbol_nickname[0],"PC 650w");
        plot_ecartement_legende[0]=40;
        size_symbol[1]=0.5;//pc1Kw
        sprintf(symbol_nickname[1],"PC 1kw");
        plot_ecartement_legende[1]=40;
        size_symbol[2]=0.7;//pc2kw
        sprintf(symbol_nickname[2],"PC 2kw");
        plot_ecartement_legende[2]=40;
        size_symbol[3]=0.5;//fresnel 1kw
        sprintf(symbol_nickname[3],"Fresnel 1kw");
        plot_ecartement_legende[3]=40;
        size_symbol[4]=0.7;//fresnel 2Kw
        sprintf(symbol_nickname[4],"Fresnel 2kw");
        plot_ecartement_legende[4]=40;
        size_symbol[5]=1.0;//fersnel 5kw
        sprintf(symbol_nickname[5],"Fresnel 5kw");
        plot_ecartement_legende[5]=40;
        size_symbol[6]=0.4;//source four
        sprintf(symbol_nickname[6],"SourceFour 26�");
        plot_ecartement_legende[6]=80;
        size_symbol[7]=0.4;//source four
        sprintf(symbol_nickname[7],"Source Four 36�");
        plot_ecartement_legende[7]=80;
        size_symbol[8]=0.4;//source four
        sprintf(symbol_nickname[8],"Source Four 50�");
        plot_ecartement_legende[8]=80;
        size_symbol[9]=0.7;//dec 1kw longue
        sprintf(symbol_nickname[9],"Dec 611SX");
        plot_ecartement_legende[9]=80;
        size_symbol[10]=0.7;//dec 1Kw  med
        sprintf(symbol_nickname[10],"Dec 614SX");
        plot_ecartement_legende[10]=80;
        size_symbol[11]=0.7;//dec 1kw   wide
        sprintf(symbol_nickname[11],"Dec 613SX");
        plot_ecartement_legende[11]=80;
        size_symbol[12]=1.0;//dec 2kw  longue
        sprintf(symbol_nickname[12],"Dec 711S");
        plot_ecartement_legende[12]=80;
        size_symbol[13]=1.0;//dec 2Kw  med
        sprintf(symbol_nickname[13],"Dec 714SX");
        plot_ecartement_legende[13]=80;
        size_symbol[14]=1.0;//dec 2kw   wide
        sprintf(symbol_nickname[14],"Dec 713SX");
        plot_ecartement_legende[14]=80;
        size_symbol[15]=0.8;//Par64 cp60
        sprintf(symbol_nickname[15],"Par64 CP60");
        plot_ecartement_legende[15]=40;
        size_symbol[16]=0.8;//Par64 cp61
        sprintf(symbol_nickname[16],"Par64 CP61");
        plot_ecartement_legende[16]=40;
        size_symbol[17]=0.8;//Par64 cp62
        sprintf(symbol_nickname[17],"Par64 CP62");
        plot_ecartement_legende[17]=40;
        size_symbol[18]=0.8;//Par64 cp95
        sprintf(symbol_nickname[18],"Par64 CP95");
        plot_ecartement_legende[18]=40;
        size_symbol[19]=0.5;//Par56 cp60
        sprintf(symbol_nickname[19],"Par56 NSP");
        plot_ecartement_legende[19]=40;
        size_symbol[20]=0.5;//Par56 cp61
        sprintf(symbol_nickname[20],"Par56 MFL");
        plot_ecartement_legende[20]=40;
        size_symbol[21]=0.5;//Par56 cp62
        sprintf(symbol_nickname[21],"Par56 WFL");
        plot_ecartement_legende[21]=40;
        size_symbol[22]=0.4;//Par36
        sprintf(symbol_nickname[22],"Par36");
        plot_ecartement_legende[22]=40;
        size_symbol[23]=0.3;//Par20
        sprintf(symbol_nickname[23],"Par20");
        plot_ecartement_legende[23]=40;
        size_symbol[24]=0.2;//Par16
        sprintf(symbol_nickname[24],"Par16");
        plot_ecartement_legende[24]=40;
        size_symbol[25]=1.0;//assy
        sprintf(symbol_nickname[25],"Cycliode");
        plot_ecartement_legende[25]=40;
        size_symbol[26]=1.0;//sym
        sprintf(symbol_nickname[26],"Horiziode");
        plot_ecartement_legende[26]=40;
        size_symbol[27]=0.5;//hallogene chantier
        sprintf(symbol_nickname[27],"500W Floodlight");
        plot_ecartement_legende[27]=40;
        size_symbol[28]=0.5;//BT250
        sprintf(symbol_nickname[28],"BT 250w");
        plot_ecartement_legende[28]=40;
        size_symbol[29]=0.8;//BT500
        sprintf(symbol_nickname[29],"BT 500w");
        plot_ecartement_legende[29]=40;
        size_symbol[30]=0.5;//rampe T8
        sprintf(symbol_nickname[30],"T8");
        plot_ecartement_legende[30]=20;
        size_symbol[31]=0.5;//Blinder
        sprintf(symbol_nickname[31],"Blinder");
        plot_ecartement_legende[41]=40;
        size_symbol[32]=0.8;//Svob
        sprintf(symbol_nickname[32],"Svoboda");
        plot_ecartement_legende[32]=60;
        size_symbol[33]=0.7;//ACL
        sprintf(symbol_nickname[33],"ACL");
        plot_ecartement_legende[33]=40;
        size_symbol[34]=0.7;//FLUOS
        sprintf(symbol_nickname[34],"Fluorescent 60cm");
        plot_ecartement_legende[34]=15;
        size_symbol[35]=0.7;//FLUOS
        sprintf(symbol_nickname[35],"Fluorescent 120cm");
        plot_ecartement_legende[35]=15;
        size_symbol[36]=0.6;//Follow Spot
        sprintf(symbol_nickname[36],"Follow Spot 575w");
        plot_ecartement_legende[36]=90;
        size_symbol[37]=0.8;//Follow Spot
        sprintf(symbol_nickname[37],"Follow Spot 1200w");
        plot_ecartement_legende[37]=110;
        size_symbol[38]=0.7;//VP
        sprintf(symbol_nickname[38],"Video Projector 1");
        plot_ecartement_legende[38]=40;
        size_symbol[39]=0.8;//VP
        sprintf(symbol_nickname[39],"Video Projector 2");
        plot_ecartement_legende[39]=75;
        size_symbol[40]=0.8;//Slide Projector
        sprintf(symbol_nickname[40],"Slide Projector");
        plot_ecartement_legende[40]=40;
        size_symbol[40]=0.9;//r�tro projecteur
        sprintf(symbol_nickname[41],"OverHead");
        plot_ecartement_legende[41]=60;


        size_symbol[42]=0.7;//accessoire
        sprintf(symbol_nickname[42],"BarnDoors");
        plot_ecartement_legende[42]=30;
        size_symbol[43]=0.4;//accessoire
        sprintf(symbol_nickname[43],"TopHat");
        plot_ecartement_legende[43]=20;
        size_symbol[44]=0.7;//accessoire
        sprintf(symbol_nickname[44],"Color Extender");
        plot_ecartement_legende[44]=30;
        size_symbol[45]=0.7;//accessoire
        sprintf(symbol_nickname[45],"Color Changer");
        plot_ecartement_legende[45]=15;
        size_symbol[46]=0.7;//accessoire
        sprintf(symbol_nickname[46],"Louvers");
        plot_ecartement_legende[46]=15;

        size_symbol[47]=0.3;//accessoire
        sprintf(symbol_nickname[47],"Iris");
        plot_ecartement_legende[47]=20;
        size_symbol[48]=0.3;//accessoire
        sprintf(symbol_nickname[48],"Gobo Holder");
        plot_ecartement_legende[48]=70;
        size_symbol[49]=0.3;//accessoire
        sprintf(symbol_nickname[49],"Shutter");
        plot_ecartement_legende[49]=50;
        size_symbol[50]=0.3;//accessoire
        sprintf(symbol_nickname[50],"Motorized mirror");
        plot_ecartement_legende[50]=50;

        size_symbol[51]=0.5;//Machine � fum�e
        sprintf(symbol_nickname[51],"Smoke machine");
        plot_ecartement_legende[51]=30;
        size_symbol[52]=0.5;//Machine � fum�e
        sprintf(symbol_nickname[52],"Fog machine");
        plot_ecartement_legende[52]=20;

        size_symbol[53]=0.5;//Dimmer
        sprintf(symbol_nickname[53],"Dimmer Plug");
        plot_ecartement_legende[53]=60;
        size_symbol[54]=0.5;//Direct
        sprintf(symbol_nickname[54],"Direct Plug");
        plot_ecartement_legende[54]=40;
        size_symbol[55]=0.5;//Services
        sprintf(symbol_nickname[55],"Running Light");
        plot_ecartement_legende[55]=40;

        size_symbol[56]=0.7;//platine de sol
        sprintf(symbol_nickname[56],"Mounting Plate");
        plot_ecartement_legende[56]=60;
        size_symbol[57]=0.5;//petit pied
        sprintf(symbol_nickname[57],"Simple Little Stand");
        plot_ecartement_legende[57]=200;
        size_symbol[58]=0.5;//grand pied
        sprintf(symbol_nickname[58],"Big Stand 3,5m");
        plot_ecartement_legende[58]=200;
        size_symbol[59]=0.5;//Barre de couplage
        sprintf(symbol_nickname[59],"Cross Bar");
        plot_ecartement_legende[59]=20;
        size_symbol[60]=0.7;//�chelle
        sprintf(symbol_nickname[60],"Ladder");
        plot_ecartement_legende[60]=240;

        size_symbol[61]=0.5;//Pont solo 50
        sprintf(symbol_nickname[61],"Truss 1m diam 50cm");
        plot_ecartement_legende[61]=92;
        size_symbol[62]=0.5;//Pont 3m 50
        sprintf(symbol_nickname[62],"Truss 3m diam 50cm");
        plot_ecartement_legende[62]=292;
        size_symbol[63]=0.5;//Pont solo 50
        sprintf(symbol_nickname[63],"Truss Junction diam 50cm");
        plot_ecartement_legende[63]=42;
        size_symbol[64]=0.5;//Pont solo 50
        sprintf(symbol_nickname[64],"Truss 1m diam 30cm");
        plot_ecartement_legende[64]=92;
        size_symbol[65]=0.5;//Pont 3m 50
        sprintf(symbol_nickname[65],"Truss 3m diam 30cm");
        plot_ecartement_legende[65]=292;
        size_symbol[66]=0.5;//Pont solo 50
        sprintf(symbol_nickname[66],"Truss Junction diam 30cm");
        plot_ecartement_legende[66]=22;



        sprintf(shape_nickname[0],"Curtain");
        sprintf(shape_nickname[1],"Plain Line");
        sprintf(shape_nickname[2],"Stippled Lines 1");
        sprintf(shape_nickname[3],"Stippled Lines 2");
        sprintf(shape_nickname[4],"Stippled Lines 3");
        sprintf(shape_nickname[5],"Stippled Lines 4");
        sprintf(shape_nickname[6],"Stippled Lines 5");
        sprintf(shape_nickname[7],"Rectangle");
        sprintf(shape_nickname[8],"Circle");
        sprintf(shape_nickname[9],"Circle Slice");
        sprintf(shape_nickname[10],"Polygon");
        sprintf(shape_nickname[11],"Text");




        for(int calc=0; calc<4; calc++)
        {
            nbre_symbols_on_plot[calc]=0;
            for (int s=0; s<nbre_symbol_per_layer; s++)
            {
                symbol_type[calc][s]=999;
                symbol_is_selected[calc][s]=0;
                angle_symbol[calc][s]=0.0;
                pos_symbol[calc][s][0]=0;
                pos_symbol[calc][s][1]=0;
                stored_plot_position[s][0]=0;
                stored_plot_position[s][1]=0;
                symbol_channel_is[calc][s]=0;
                symbol_dimmer_is[calc][s]=0;
                gelat[calc][s][0]=0;
                gelat[calc][s][1]=0;
                gelat[calc][s][2]=0;
                gelat_family[calc][s][0]=0;
                gelat_family[calc][s][1]=0;
                gelat_family[calc][s][2]=0;
                symbol_is_linked_to[calc][s]=0;
                strcpy(symbol_note[calc][s][0],"");
                strcpy(symbol_note[calc][s][1],"");
                strcpy(symbol_note[calc][s][2],"");
                strcpy(symbol_note[calc][s][3],"");

                for(int opt=0; opt<5; opt++)
                {
                    relatif_plot_xy[calc][s][opt][0]=0;
                    relatif_plot_xy[calc][s][opt][1]=0;
                }
            }
        }
        for(int t=0; t<5; t++)
        {
            adjust_xy_type[t]=0;
        }
        adjust_xy_type[0]=1;
        position_relative_plan_theatre[0]=(x_plot+position_plan_x);
        position_relative_plan_theatre[1]=(y_plot+position_plan_y);


        nbre_shapes_on_plot=0;
        number_of_shapes_groups=0;
        for (int s=0; s<nbre_symbol_per_layer; s++)
        {
            shape_selected[s]=0;
            shape_type[s]=0;
            shape_attributes[s][0]=10.0;//size G
            shape_attributes[s][1]=0.0;//angle rot
            shape_attributes[s][2]=1.0;//size x
            shape_attributes[s][3]=10.0;//size y
            shape_attributes[s][4]=0.1;//opening angle
            shape_groups[s]=0;
            for(int i=0; i<4; i++)
            {
                shape_position[s][i]=0;//pour les lignes
            }
            strcpy(shape_legend_name[s],"");

            shape_legend_name[s][24]='\0';
            shape_relativ_position_legend_name[s][0]=0;
            shape_relativ_position_legend_name[s][1]=0;
            shape_color_type[s]=0;
        }


        clear_plot_legend();
        generate_channel_view_list_from_patched_circuits();

    }



    if(specify_who_to_save_load[32]==1)//DRAW
    {
        for(int p=0; p<6; p++)
        {
            clear_draw_preset(p);
        }
    }

    if(specify_who_to_save_load[33]==1)//ECHO
    {
        for(int p=0; p<24; p++)
        {
            clear_echo_preset(p);
        }
    }

    //////////////WAVE//////////////////////////
    for(int i=0; i<26; i++)
    {
        // Wave_Dampered[i].fix_all_damper_state_value(Fader[in]);
        // Wave_Dampered[i].set_target_val(Fader[in]);
        Wave_Dampered[i].set_damper_decay(1.0);
        Wave_Dampered[i].set_damper_dt(0.1);
    }



    if(specify_who_to_save_load[35]==1)//preset de sauvegarde personnalises
    {
        for(int p=0; p<80; p++)
        {
            for(int o=0; o<3; o++)
            {
                preset_specify_who_to_save_load[p][o]=0;
            }
        }
        for(int i=0; i<36; i++)
        {
            specify_who_to_save_PDF[i]=0;
        }
    }



    for(int i=0; i<514; i++)
    {
        bufferSaisie[i]=0;
        bufferFaders[i]=0;
        bufferBlind[i]=0;
        Selected_Channel[i]=0;
        Dimmers_selected[i]=0;
        DmxBlock[i]=0;
        MergerArray[i]=0;
        buffer_tracker[i]=0;
        highest_level_comes_from_fader[i]=0;
        show_who_is_in_FADER_DOCK[i]=0;
    }

    bool show_is_virgin_=1;
    for(int iu=0; iu<72; iu++)
    {
        if(specify_who_to_save_load[iu]==0)
        {
            show_is_virgin_=0;
            break;
        }
    }

    if(show_is_virgin_==1)
    {
        sprintf(my_show_is_coming_from,"A complete New show");
        write_show_coming_from();
        set_all_saves_indexes_at(1);
    }
    //set_all_saves_indexes_at(1); // a cass� le chargement s�lectif 3 mars 2016
    index_menu_save=0;
    substract_a_window(W_SAVE);
    return(0);
}
