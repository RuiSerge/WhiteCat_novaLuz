int do_main_config(int cfgnetw_X, int cfgnetw_Y, int largeurCFGdmxwindow,int hauteurCFGdmxwindow)
{
    for (int oi=0; oi<5; oi++)
    {
        Rect UnderParam(Vec2D(cfgnetw_X+155,cfgnetw_Y+55+(oi*30)),Vec2D(50,25));
        UnderParam.SetRoundness(7.5);
        UnderParam.SetLineWidth(epaisseur_ligne_fader);
        UnderParam.Draw(CouleurFond.WithAlpha(0.5));
        if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+155 && mouse_x<cfgnetw_X+155+50 && mouse_y>cfgnetw_Y+55+(oi*30) && mouse_y<cfgnetw_Y+55+(oi*30)+25)
        {
            UnderParam.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                int param_data_in=0;
                switch(dmx_view)
                {
                case 0:
                    if(oi!=1)
                    {
                        param_data_in=(int)(atoi(numeric)*2.55)+1;
                    }
                    else
                    {
                        param_data_in=atoi(numeric);
                    }
                    reset_numeric_entry();
                    break;
                case 1:
                    param_data_in=atoi(numeric);
                    reset_numeric_entry();
                    break;
                default:
                    break;
                }
                switch(oi)
                {
                case 0:
                    dmx_view=toggle(dmx_view);
                    break;
                case 1:
                    default_step_level=param_data_in;
                    break;
                case 2:
                    check_channel_level=param_data_in;
                    break;
                case 3:
                    dimmer_check_level=param_data_in;
                    break;
                case 4:
                    index_blink_change_memories=toggle(index_blink_change_memories);
                    break;
                default:
                    break;
                }
                UnderParam.Draw(CouleurBlind);
                mouse_released=1;
            }
        }
    }
    char string_cfg_main[32];
    petitchiffre.Print("Channels: ",(cfgnetw_X+10), (cfgnetw_Y+40));
    Line(Vec2D(cfgnetw_X+10,cfgnetw_Y+45),Vec2D(cfgnetw_X+100,cfgnetw_Y+45)).Draw(CouleurLigne);
    petitchiffre.Print("Display mode:", (cfgnetw_X+20), (cfgnetw_Y+70) );
    switch(dmx_view)
    {
    case 0:
        sprintf(string_cfg_main,"/100");
        break;
    case 1:
        sprintf(string_cfg_main,"/255");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main, (cfgnetw_X+170), (cfgnetw_Y+70) );

    sprintf(string_cfg_main,"%d", default_step_level);
    petitchiffre.Print("Default step level:", (cfgnetw_X+20), (cfgnetw_Y+100) );
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+100));

    switch(dmx_view)
    {
    case 0:
        sprintf(string_cfg_main,"%d", (int)(((float)check_channel_level)/2.55));
        break;
    case 1:
        sprintf(string_cfg_main,"%d", check_channel_level);
        break;
    default:
        break;
    }
    petitchiffre.Print("Check channels level:", (cfgnetw_X+20), (cfgnetw_Y+130) );
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+130));

    switch(dmx_view)
    {
    case 0:
        sprintf(string_cfg_main,"%d", (int)(((float)dimmer_check_level)/2.55));
        break;
    case 1:
        sprintf(string_cfg_main,"%d", dimmer_check_level);
        break;
    default:
        break;
    }
    petitchiffre.Print("Check dimmers level:", (cfgnetw_X+20), (cfgnetw_Y+160) );
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+160));



    switch(index_blink_change_memories)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print("Show Change/Mem:", (cfgnetw_X+20), (cfgnetw_Y+190) );
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+190));


    Rect UnderParam(Vec2D(cfgnetw_X+155,cfgnetw_Y+235),Vec2D(50,25));
    UnderParam.SetRoundness(7.5);
    UnderParam.SetLineWidth(epaisseur_ligne_fader);
    UnderParam.Draw(CouleurFond.WithAlpha(0.5));

    Rect UnderParam2(Vec2D(cfgnetw_X+155,cfgnetw_Y+265),Vec2D(50,20));
    UnderParam2.SetRoundness(7.5);
    UnderParam2.SetLineWidth(epaisseur_ligne_fader);
    UnderParam2.Draw(CouleurFond.WithAlpha(0.5));




    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+155 && mouse_x<cfgnetw_X+155+50 )
    {
        if( mouse_y>cfgnetw_Y+235 && mouse_y<cfgnetw_Y+235+25)//nbre de channels audio
        {
            UnderParam.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                int param_data_in=0;
                param_data_in=atoi(numeric);
                index_nbre_players_visibles=param_data_in;
                if(index_nbre_players_visibles<1)
                {
                    index_nbre_players_visibles=1;
                }
                else if(index_nbre_players_visibles>4)
                {
                    index_nbre_players_visibles=4;
                }
                reset_numeric_entry();
                UnderParam.Draw(CouleurBlind);
                mouse_released=1;
            }
        }
        if(window_focus_id==W_CFGMENU &&  mouse_y>cfgnetw_Y+265 && mouse_y<cfgnetw_Y+265+20)//nbre de channels audio
        {
            UnderParam2.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                index_preloaded_sounds=toggle(index_preloaded_sounds);
                UnderParam2.Draw(CouleurBlind);
                mouse_released=1;
            }
        }
    }


    petitchiffre.Print("Audio: ",(cfgnetw_X+10), (cfgnetw_Y+220));
    petitchiffre.Print(audio_device_name,(cfgnetw_X+120), (cfgnetw_Y+220));
    Line(Vec2D(cfgnetw_X+10,cfgnetw_Y+225),Vec2D(cfgnetw_X+100,cfgnetw_Y+225)).Draw(CouleurLigne);
    petitchiffre.Print("Number of Players:", (cfgnetw_X+20), (cfgnetw_Y+250) );
    sprintf(string_cfg_main,"%d", index_nbre_players_visibles);
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+250));
    petitchiffre.Print("Preload on read:",(cfgnetw_X+20), (cfgnetw_Y+280));
    switch(index_preloaded_sounds)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+170), (cfgnetw_Y+280));




    for (int oi=0; oi<8; oi++)
    {
        Rect UnderParam(Vec2D(cfgnetw_X+365,cfgnetw_Y+55+(oi*30)),Vec2D(50,25));
        UnderParam.SetRoundness(7.5);
        UnderParam.SetLineWidth(epaisseur_ligne_fader);
        UnderParam.Draw(CouleurFond.WithAlpha(0.5));
        if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+365 && mouse_x<cfgnetw_X+365+50 && mouse_y>cfgnetw_Y+55+(oi*30) && mouse_y<cfgnetw_Y+55+(oi*30)+25)
        {
            UnderParam.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {

                switch(oi)//action souris
                {
                case 0://Temps par defaut
                    default_time=atof(numeric);
                    reset_numeric_entry();
                    break;
                case 1://temps par defaut d un bang
                    default_time_of_the_bang=atof(numeric);
                    reset_numeric_entry();
                    break;
                case 2://time digit nbre decimales affichages chasers
                    index_affichage_digit_time_unit=atoi(numeric)-1;
                    if(index_affichage_digit_time_unit<=0)
                    {
                        index_affichage_digit_time_unit=0;
                    }
                    else
                    {
                        if (index_affichage_digit_time_unit>3)
                        {
                            index_affichage_digit_time_unit=3;
                        }
                        reset_numeric_entry();
                    }
                    break;
                case 3://nbre tracks visualisables chasers
                    nbre_track_visualisables=atoi(numeric);
                    if(nbre_track_visualisables<1)
                    {
                        nbre_track_visualisables=1;
                    }
                    if(nbre_track_visualisables>nbre_tracks_par_chaser)
                    {
                        nbre_track_visualisables=nbre_tracks_par_chaser;
                    }
                    reset_numeric_entry();
                    break;
                case 4://midi force mode pour le play
                    Midi_Force_Go=toggle(Midi_Force_Go);
                    break;
                case 5://nombre cues dans preset view
                    nbre_memoires_visualisables_en_preset=atoi(numeric);
                    if(nbre_memoires_visualisables_en_preset<5)
                    {
                        nbre_memoires_visualisables_en_preset=5;
                    }
                    if(nbre_memoires_visualisables_en_preset>25)
                    {
                        nbre_memoires_visualisables_en_preset=25;
                    }
                    hauteur_globale_sequenciel=180+(35*(nbre_memoires_visualisables_en_preset+1))+35;
                    reset_numeric_entry();
                    break;
                case 6: // on Go light Channel
                    go_channel_is=atoi(numeric);
                    if(go_channel_is<1 || ( go_channel_is> 512))
                    {
                        go_channel_is=0;
                    }
                    reset_numeric_entry();
                    break;
                case 7: // on Pause light Channel
                    pause_channel_is=atoi(numeric);
                    if(pause_channel_is<1 || ( pause_channel_is> 512))
                    {
                        pause_channel_is=0;
                    }
                    reset_numeric_entry();
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }

        switch(oi)//affichage
        {
        case 0://Temps par defaut
            petitchiffre.Print("CueList / Bangs / Chasers ",(cfgnetw_X+225), (cfgnetw_Y+40));
            Line(Vec2D(cfgnetw_X+225,cfgnetw_Y+45),Vec2D(cfgnetw_X+410,cfgnetw_Y+45)).Draw(CouleurLigne);
            petitchiffre.Print("Record Default time:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(default_time),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 1:
            petitchiffre.Print("Bang stay-on time:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            char tmpo[10];
            sprintf(tmpo,"%.1f",default_time_of_the_bang);
            petitchiffre.Print(tmpo,cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 2:
            petitchiffre.Print("Time Unit Digits:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(index_affichage_digit_time_unit+1),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 3:
            petitchiffre.Print("Chaser View Tracks:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(nbre_track_visualisables),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 4:
            petitchiffre.Print("GO Midi ForceMode:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            switch(Midi_Force_Go)
            {
            case 0:
                petitchiffre.Print("/Off",cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
                break;
            case 1:
                petitchiffre.Print("/On",cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
                break;
            default:
                break;
            }
            break;
        case 5:
            petitchiffre.Print("Cues in Preset:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(nbre_memoires_visualisables_en_preset),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 6:
            petitchiffre.Print("Go Channel:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(go_channel_is),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        case 7:
            petitchiffre.Print("Pause Channel:",cfgnetw_X+235,cfgnetw_Y+70+(oi*30));
            petitchiffre.Print(ol::ToString(pause_channel_is),cfgnetw_X+380,cfgnetw_Y+70+(oi*30));
            break;
        default:
            break;
        }

    }


    petitchiffre.Print("On Start",(cfgnetw_X+430), (cfgnetw_Y+40));
    Line(Vec2D(cfgnetw_X+430,cfgnetw_Y+45),Vec2D(cfgnetw_X+530,cfgnetw_Y+45)).Draw(CouleurLigne);
    petitchiffre.Print("Open Camera",cfgnetw_X+430,cfgnetw_Y+70);
    Rect CamOn(Vec2D(cfgnetw_X+525,cfgnetw_Y+55),Vec2D(50,20));
    CamOn.SetRoundness(7.5);
    CamOn.SetLineWidth(epaisseur_ligne_fader);
    CamOn.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+55 && mouse_y<cfgnetw_Y+55+20)
    {
        CamOn.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            camera_on_open=toggle(camera_on_open);
            CamOn.Draw(CouleurBlind);
            mouse_released=1;
            switch(camera_on_open)
            {
            case 0:
                CloseVideo();
                break;
            case 1:
                InitVideo();
                break;
            default:
                break;
            }
        }
    }
    switch(camera_on_open)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,cfgnetw_X+540,cfgnetw_Y+70);



    petitchiffre.Print("Open Arduino",cfgnetw_X+430,cfgnetw_Y+100);
    Rect ArduinOn(Vec2D(cfgnetw_X+525,cfgnetw_Y+85),Vec2D(50,20));
    ArduinOn.SetRoundness(7.5);
    ArduinOn.SetLineWidth(epaisseur_ligne_fader);
    ArduinOn.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+85 && mouse_y<cfgnetw_Y+85+20)
    {
        ArduinOn.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            open_arduino_on_open=toggle(open_arduino_on_open);
            ArduinOn.Draw(CouleurBlind);
            mouse_released=1;
        }
    }
    switch(open_arduino_on_open)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,cfgnetw_X+540,cfgnetw_Y+100);

    petitchiffre.Print("Open iCat",cfgnetw_X+430,cfgnetw_Y+130);
    Rect iCatOn(Vec2D(cfgnetw_X+525,cfgnetw_Y+115),Vec2D(50,20));
    iCatOn.SetRoundness(7.5);
    iCatOn.SetLineWidth(epaisseur_ligne_fader);
    iCatOn.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+115 && mouse_y<cfgnetw_Y+115+20)
    {
        iCatOn.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            enable_iCat=toggle(enable_iCat);
            mouse_released=1;
        }
    }
    switch(enable_iCat)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,cfgnetw_X+540,cfgnetw_Y+130);




    Rect ProcessB(Vec2D(cfgnetw_X+525,cfgnetw_Y+190),Vec2D(50,20));
    ProcessB.SetRoundness(7.5);
    ProcessB.SetLineWidth(epaisseur_ligne_fader);
    ProcessB.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+190 && mouse_y<cfgnetw_Y+190+20)
    {
        ProcessB.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            index_allow_multicore=toggle(index_allow_multicore);
            ProcessB.Draw(CouleurBlind);
            mouse_released=1;
            if(index_allow_multicore==1 && core_to_assign>0 && core_to_assign<9)
            {
                process_assign_to_core(core_to_assign);
            }
        }
    }


    Rect ProcessCorB(Vec2D(cfgnetw_X+525,cfgnetw_Y+215),Vec2D(50,20));
    ProcessCorB.SetRoundness(7.5);
    ProcessCorB.SetLineWidth(epaisseur_ligne_fader);
    ProcessCorB.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+215 && mouse_y<cfgnetw_Y+215+20)
    {
        ProcessCorB.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            core_to_assign=atoi(numeric);
            reset_numeric_entry();
            if(core_to_assign>0 && core_to_assign<9 && index_allow_multicore==1)
            {
                process_assign_to_core(core_to_assign);
            }
            ProcessCorB.Draw(CouleurBlind);
            mouse_released=1;
        }
    }
    petitchiffre.Print("Multicore: ",(cfgnetw_X+430), (cfgnetw_Y+203));
    Line(Vec2D(cfgnetw_X+430,cfgnetw_Y+210),Vec2D(cfgnetw_X+500,cfgnetw_Y+210)).Draw(CouleurLigne);
    switch(index_allow_multicore)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+540), (cfgnetw_Y+203));
    petitchiffre.Print("Affect to Core:",cfgnetw_X+430,cfgnetw_Y+228);
    petitchiffre.Print(ol::ToString(core_to_assign),cfgnetw_X+545,cfgnetw_Y+228);




    Rect faderSpace(Vec2D(cfgnetw_X+525,cfgnetw_Y+265),Vec2D(50,20));
    faderSpace.SetRoundness(7.5);
    faderSpace.SetLineWidth(epaisseur_ligne_fader);
    faderSpace.Draw(CouleurFond.WithAlpha(0.5));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+525 && mouse_x<cfgnetw_X+525+50 && mouse_y>cfgnetw_Y+265 && mouse_y<cfgnetw_Y+265+20)
    {
        faderSpace.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            LargeurEspaceFaderSize=atoi(numeric);
            reset_numeric_entry();
            if(LargeurEspaceFaderSize<1024 )
            {
                LargeurEspaceFaderSize=1024;
            }
            if(LargeurEspaceFaderSize>largeur_ecran)
            {
                LargeurEspaceFaderSize=largeur_ecran;
            }
            faderSpace.Draw(CouleurBlind);
            mouse_released=1;
        }
    }
    petitchiffre.Print("Fader Space Width: ",(cfgnetw_X+430), (cfgnetw_Y+255));
    Line(Vec2D(cfgnetw_X+430,cfgnetw_Y+260),Vec2D(cfgnetw_X+560,cfgnetw_Y+260)).Draw(CouleurLigne);
    petitchiffre.Print(ol::ToString(LargeurEspaceFaderSize),(cfgnetw_X+540), (cfgnetw_Y+280));





    do_keyboard_conf((cfgnetw_X+620), (cfgnetw_Y+40));



    Rect ExpertB(Vec2D(cfgnetw_X+740,cfgnetw_Y+225),Vec2D(50,20));
    ExpertB.SetRoundness(7.5);
    ExpertB.SetLineWidth(epaisseur_ligne_fader);
    ExpertB.Draw(CouleurFond.WithAlpha(0.5));
    ExpertB.Draw(CouleurFader.WithAlpha(expert_mode*alpha_blinker));

    if(window_focus_id==W_CFGMENU && mouse_x> cfgnetw_X+740 && mouse_x<cfgnetw_X+740+50 && mouse_y>cfgnetw_Y+225 && mouse_y<cfgnetw_Y+225+20)
    {
        ExpertB.DrawOutline(CouleurLevel);
        if(mouse_button==1 && mouse_released==0)
        {
            expert_mode=toggle(expert_mode);
            ExpertB.Draw(CouleurBlind);
            mouse_released=1;
        }
    }


    petitchiffre.Print("EXPERT MODE: ",(cfgnetw_X+620), (cfgnetw_Y+240));
    switch(expert_mode)
    {
    case 0:
        sprintf(string_cfg_main,"/Off");
        break;
    case 1:
        sprintf(string_cfg_main,"/On");
        break;
    default:
        break;
    }
    petitchiffre.Print(string_cfg_main,(cfgnetw_X+750), (cfgnetw_Y+240));



    return(0);
}
