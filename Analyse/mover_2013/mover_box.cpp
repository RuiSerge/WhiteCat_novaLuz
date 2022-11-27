int mover_box(int x_track,int y_track)
{

    int track_aera_x=x_track+20, track_aera_y=y_track+20;
    Tracker_speed_is=((float)Tracker_speedlevel)/8;

    Rect TrckBackground(Vec2D (x_track, y_track-40 ), Vec2D ( 1000,660));
    TrckBackground.SetRoundness(15);
    TrckBackground.Draw(CouleurFond);

    TrckBackground.SetLineWidth(triple_epaisseur_ligne_fader);
    TrckBackground.DrawOutline(Rgba::WHITE);
    if(window_focus_id==W_MOVER)
    {
        TrckBackground.DrawOutline(CouleurFader);
    }

    neuro.Print("MOVER",x_track+100, y_track-10);

    Rect BorderTrckWindow(Vec2D(track_aera_x-10,track_aera_y-10),Vec2D(275,275));
    BorderTrckWindow.SetRoundness(15);
    BorderTrckWindow.SetLineWidth(demi_epaisseur_ligne_fader);
    BorderTrckWindow.DrawOutline(Rgba::WHITE);

    Rect TrckWindow(Vec2D(track_aera_x,track_aera_y),Vec2D(255,255));
    TrckWindow.SetRoundness(7.5);
    TrckWindow.SetLineWidth(demi_epaisseur_ligne_fader);



    Circle monTracker( Vec2D(mover_params[0][0]+track_aera_x, mover_params[1][0]+track_aera_y), 10 );
    monTracker.SetLineWidth(epaisseur_ligne_fader);

    Circle monTrackerfine( Vec2D(mover_params[0][1]+track_aera_x, mover_params[1][1]+track_aera_y), 10 );
    monTrackerfine.SetLineWidth(epaisseur_ligne_fader);

    if(tracker_16b_edit==0)
    {
        TrckWindow.Draw( CouleurSelection);
    }
    else if(tracker_16b_edit==1)
    {
        TrckWindow.Draw(CouleurBleuProcedure.WithAlpha(0.5));
        monTrackerfine.DrawOutline( Rgba::YELLOW );
    }


    Line(Vec2D(track_aera_x+127,track_aera_y), Vec2D( track_aera_x+127,track_aera_y+255)).Draw(CouleurLigne);
    Line(Vec2D(track_aera_x,track_aera_y+127), Vec2D( track_aera_x+255,track_aera_y+127)).Draw(CouleurLigne);
    Circle CercleMire( Vec2D(track_aera_x+127, track_aera_y+127), 127 );
    CercleMire.DrawOutline( Rgba::WHITE );


    Circle CercleZeroPoint( Vec2D(position_defaut[0]+track_aera_x+127,position_defaut[1]+track_aera_y+127), 6 );
    CercleZeroPoint.Draw(Rgba::BLACK.WithAlpha(0.3));




    if(tracker_16b_edit==0)
    {
        Circle CercleShowIris( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[2][0]/2) );
        CercleShowIris.Draw(Rgba::WHITE.WithAlpha(0.2));
        Circle CercleShowFocus( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[3][0]/2) );
        CercleShowFocus.Draw(Rgba::BLUE.WithAlpha(0.2));
        Circle CercleShowZoom( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[4][0]/2) );
        CercleShowZoom.SetLineWidth(demi_epaisseur_ligne_fader);
        CercleShowZoom.DrawOutline(Rgba::BLACK);
    }
    else if(tracker_16b_edit==1)
    {
        Circle CercleShowIris( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[2][1]/2) );
        CercleShowIris.Draw(Rgba::WHITE.WithAlpha(0.2));
        Circle CercleShowFocus( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[3][1]/2) );
        CercleShowFocus.Draw(Rgba::BLUE.WithAlpha(0.2));
        Circle CercleShowZoom( Vec2D(track_aera_x+127,track_aera_y+127), (int)(mover_params[4][1]/2) );
        CercleShowZoom.SetLineWidth(demi_epaisseur_ligne_fader);
        CercleShowZoom.DrawOutline(Rgba::BLACK);
    }


    if(window_focus_id==W_MOVER && mouse_x>=track_aera_x && mouse_x<=track_aera_x+255 && mouse_y>=track_aera_y && mouse_y<=track_aera_y+255 )
    {
        if(tracker_16b_edit==0)
        {
            monTracker.Draw( Rgba::RED );
            if(mouse_button==1)
            {

                index_move_crossfade_is_on=0;
                index_move_back=0;
                index_move_forward=0;
                index_mouse_is_tracking=1;

                if(lockX_on==0 )
                {
                    mover_params[0][0]=mouse_x-track_aera_x;
                }
                if(lockY_on==0)
                {
                    mover_params[1][0]=mouse_y-track_aera_y;
                }


            }
        }
        else if(tracker_16b_edit==1)
        {
            monTrackerfine.Draw( Rgba::YELLOW );
            if(mouse_button==1)
            {
                index_mouse_is_tracking=1;
                if(lockX_on==0)
                {
                    mover_params[0][1]=mouse_x-track_aera_x;
                }
                if(lockY_on==0)
                {
                    mover_params[1][1]=mouse_y-track_aera_y;
                }
            }
        }
    }


    if(index_spline==1)
    {

        ShowSpline(dock_move_selected);
    }


    Rect SliderFaderSpeed( Vec2D( x_track+420,y_track+350 ), Vec2D ( 50,255));//box du fader
    SliderFaderSpeed.SetRoundness(15);
    SliderFaderSpeed.SetLineWidth(epaisseur_ligne_fader);
    Rect LevelFaderSpeed( Vec2D( x_track+420,y_track+350+255-Tracker_speedlevel ), Vec2D ( 50,Tracker_speedlevel));//box du fader
    LevelFaderSpeed.SetRoundness(15);
    LevelFaderSpeed.SetLineWidth(epaisseur_ligne_fader);
    if(window_focus_id==W_MOVER && mouse_x>x_track+420 && mouse_x<x_track+470 && mouse_y>y_track+350 && mouse_y<=y_track+350+255)
    {
        if(mouse_button==1  && index_mouse_is_tracking==0 )
        {
            Tracker_speedlevel=(y_track+350+255)-mouse_y;
            Tracker_speed_is=((float)Tracker_speedlevel)/8;
            dock_time[dock_move_selected][dock_move_actual_step[dock_move_selected]]=(int)(Tracker_speed_is*BPS_RATE);
        }
    }
    if(index_move_crossfade_is_on==0)
    {
        LevelFaderSpeed.Draw(CouleurNiveau);
        color_cycling=0.0;
    }
    else if(index_move_crossfade_is_on==1)
    {
        if(color_cycling<=0.95)
        {
            color_cycling+=0.05;
        }
        else
        {
            color_cycling=0.05;
        }
        Rgba Cycling(1.0,0.0+color_cycling,0.0);
        LevelFaderSpeed.Draw(Cycling);
    }
    SliderFaderSpeed.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("STEP",x_track+427, y_track+305);
    petitchiffre.Print("SPEED",x_track+425, y_track+320);
    sprintf(string_seconds_Tracker_speed_is,"%.1f sec.",Tracker_speed_is);
    petitchiffre.Print(string_seconds_Tracker_speed_is,x_track+425, y_track+335);


    for (int lopt=0; lopt<4; lopt++)
    {
        Rect StepActionL1(Vec2D(x_track+20+(lopt*40),track_aera_y+275),Vec2D(30,20));

        Rect StepActionL2(Vec2D(x_track+20+(lopt*40),track_aera_y+305),Vec2D(30,20));

        switch(lopt)
        {
        case 0:
            sprintf(string_titre_stepsL1,"Add");
            sprintf(string_titre_stepsL2," <<<");
            StepActionL1.DrawOutline(Rgba::WHITE);
            StepActionL2.DrawOutline(Rgba::WHITE);
            break;
        case 1:
            sprintf(string_titre_stepsL1," Rec");
            sprintf(string_titre_stepsL2," >>>");
            StepActionL1.DrawOutline(Rgba::WHITE);
            StepActionL2.DrawOutline(Rgba::WHITE);
            break;
        case 2:
            sprintf(string_titre_stepsL1," Del");
            sprintf(string_titre_stepsL2,"S.CYC");
            if (move_auto_stop[dock_move_selected][dock_move_actual_step[dock_move_selected]]==1)
            {
                StepActionL2.Draw(Rgba::RED);
            }
            StepActionL1.DrawOutline(Rgba::WHITE);
            StepActionL2.DrawOutline(Rgba::WHITE);
            break;
        case 3:
            sprintf(string_titre_stepsL1,"  %d",Moves_Inpoint[dock_move_selected]);
            sprintf(string_titre_stepsL2,"  %d",GotoMoves[dock_move_selected][(dock_move_actual_step[dock_move_selected])]);
            if(Moves_Inpoint[dock_move_selected]==dock_move_actual_step[dock_move_selected])
            {
                StepActionL1.Draw(CouleurLock.WithAlpha(0.5));
            }
            if(GotoMoves[dock_move_selected][(dock_move_actual_step[dock_move_selected])]!=0)
            {
                StepActionL2.Draw(CouleurBlind.WithAlpha(0.5));
            }
            if(index_goto_record==1)
            {
                StepActionL2.Draw(CouleurFader.WithAlpha(alpha_blinker));
            }
            StepActionL1.DrawOutline(CouleurLock);
            StepActionL2.DrawOutline(CouleurBlind);
            break;
        default:
            break;
        }
        if( window_focus_id==W_MOVER && mouse_x>x_track+20+(lopt*40) && mouse_x<x_track+20+30+(lopt*40) && mouse_y>track_aera_y+275 && mouse_y<track_aera_y+295)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
            {
                switch(lopt)
                {
                case 0:
                    Move_AddStep(dock_move_selected);
                    break;
                case 1:
                    Move_RecStep(dock_move_selected);
                    break;
                case 2:
                    Move_DelStep(dock_move_selected);
                    break;
                case 3:
                    if(  index_main_clear==0 && index_goto_record==0)
                    {
                        Moves_Inpoint[dock_move_selected]=dock_move_actual_step[dock_move_selected];
                    }
                    else if(  index_goto_record==0 && index_main_clear==1)
                    {
                        ClearIntoStep(dock_move_selected);
                        index_main_clear=0;
                    }
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }
        if(window_focus_id==W_MOVER && mouse_x>x_track+20+(lopt*40) && mouse_x<x_track+20+30+(lopt*40) && mouse_y>track_aera_y+305 && mouse_y<track_aera_y+325)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0  )
            {
                switch(lopt)
                {
                case 0:
                    Move_StepBackward(dock_move_selected);
                    break;
                case 1:
                    Move_StepForward(dock_move_selected);
                    break;
                case 2:
                    Move_Autostop(dock_move_selected);
                    break;
                case 3:
                    if(  index_main_clear==0)
                    {
                        if(index_goto_record==0)
                        {
                            index_goto_record=1;
                            index_main_clear=0;
                        }
                        else  if(index_goto_record==1)
                        {
                            index_goto_record=0;
                        }
                    }
                    else if( index_main_clear==1)
                    {
                        ClearGotoStep(dock_move_selected);
                        index_main_clear=0;
                    }
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }

        petitchiffre.Print(string_titre_stepsL1,x_track+20+(lopt*40), track_aera_y+288);
        petitchiffre.Print(string_titre_stepsL2,x_track+20+(lopt*40), track_aera_y+318);
    }




    sprintf(string_dock_selection,"Bank %d : Step %d / %d ",dock_move_selected,dock_move_actual_step[dock_move_selected],dock_moves_contains_steps[dock_move_selected] );
    neuromoyen.Print(string_dock_selection, x_track+180,y_track+310);
    if(index_move_crossfade_is_on==1)
    {
        if (next_step[dock_move_selected]!=1 || next_step[dock_move_selected]!=dock_moves_contains_steps[dock_move_selected]+1)
        {
            if(GotoMoves[dock_move_selected][dock_move_actual_step[dock_move_selected]]==0)
            {
                sprintf(string_dock_selection2,">> to step %d Bank %d",next_step[dock_move_selected],dock_move_selected );
                if(next_step[dock_move_selected]>dock_moves_contains_steps[dock_move_selected])
                {
                    sprintf(string_dock_selection2,">> to step 1" );
                }
            }
            if(GotoMoves[dock_move_selected][dock_move_actual_step[dock_move_selected]]!=0)
            {
                sprintf(string_dock_selection2,">> GOTO step %d Bank %d",Moves_Inpoint[(GotoMoves[dock_move_selected][dock_move_actual_step[dock_move_selected]])],GotoMoves[dock_move_selected][dock_move_actual_step[dock_move_selected]] );
            }
        }
        neuromoyen.Print(string_dock_selection2, x_track+180,y_track+340);
    }



    Rect PlayBackMove( Vec2D( x_track+20,y_track+360 ), Vec2D ( 60,25));//box du fader
    PlayBackMove.SetRoundness(4);

    if( window_focus_id==W_MOVER && mouse_x>x_track+20 && mouse_x<x_track+20+60 && mouse_y>y_track+360 && mouse_y<y_track+385)
    {
        PlayBackMove.Draw(CouleurSurvol);
        if(mouse_button==1  && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            if(index_move_back==0 )
            {
                if(index_move_forward==1)//si dejà cross en cours, permet de recaler la position
                {
                    index_move_forward=0;
                    dock_move_actual_step[dock_move_selected]++;
                    if(dock_move_actual_step[dock_move_selected]>dock_moves_contains_steps[dock_move_selected])
                    {
                        dock_move_actual_step[dock_move_selected]=1;
                    }
                }
                index_move_back=1;
                index_move_crossfade_is_on=1;
            }

            else //stop du move
            {
                index_move_crossfade_is_on=0;
                index_move_forward=0;
                index_move_back=0;
            }
            prepare_move_values(dock_move_selected);
            mouse_released=1;
        }
    }
    if(index_move_back==1)
    {
        PlayBackMove.Draw(CouleurFader);
    }
    PlayBackMove.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("GO BACK",x_track+25, y_track+375);

    Rect PlayGoMove( Vec2D( x_track+100,y_track+360 ), Vec2D ( 60,25));//box du fader
    PlayGoMove.SetRoundness(4);

    if( window_focus_id==W_MOVER && mouse_x>x_track+100 && mouse_x<x_track+100+60 && mouse_y>y_track+360 && mouse_y<y_track+385)
    {
        PlayGoMove.Draw(CouleurSurvol);
        if(mouse_button==1  && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            if(index_move_crossfade_is_on==0)
            {
                index_move_back=0;
                index_move_forward=1;
                index_move_crossfade_is_on=1;
                prepare_move_values(dock_move_selected);
            }
            else
            {
                index_move_crossfade_is_on=0;
                index_move_forward=0;
            }
            mouse_released=1;
        }
    }
    if(index_move_forward==1)
    {
        PlayGoMove.Draw(CouleurFader);
    }
    PlayGoMove.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("GO",x_track+120, y_track+375);


    Rect CycleMove( Vec2D( x_track+180,y_track+360 ), Vec2D ( 60,25));//box du fader
    CycleMove.SetRoundness(4);

    if(window_focus_id==W_MOVER && mouse_x>x_track+180 && mouse_x<x_track+240 && mouse_y>y_track+360 && mouse_y<y_track+385)
    {
        if(mouse_button==1  && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            index_cycle=toggle(index_cycle);
            mouse_released=1;
        }
    }
    if(index_cycle==1)
    {
        CycleMove.Draw(CouleurBlind.WithAlpha(alpha_blinker));
    }
    CycleMove.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("CYCLE",x_track+190, y_track+375);





    Rect SplineOn( Vec2D( x_track+260,y_track+360 ), Vec2D ( 60,25));//box du fader
    SplineOn.SetRoundness(4);
    SplineOn.Draw(CouleurFader.WithAlpha(index_spline));
    if(window_focus_id==W_MOVER && mouse_x>x_track+260 && mouse_x<x_track+320 && mouse_y>y_track+360 && mouse_y<y_track+385)
    {
        if(mouse_button==1  && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            index_spline=toggle(index_spline);
            mouse_released=1;
        }
    }

    SplineOn.DrawOutline(Rgba::WHITE);
    petitchiffre.Print(" SPLINE",x_track+260, y_track+375);

    sprintf(string_spline_ratio,"  %.2f",spline_ratio[dock_move_selected]*-1);

    petitpetitchiffre.Print(string_spline_ratio,x_track+340,y_track+365);
    Rect SliderFaderSpline( Vec2D( x_track+230,y_track+400 ), Vec2D ( 127,20));//box du fader
    SliderFaderSpline.SetRoundness(3);
    Rect LevelFaderSpline( Vec2D( x_track+230,y_track+400), Vec2D ( Tracker_splinelevel,20)); //box du fader
    LevelFaderSpline.SetRoundness(3);

    if(window_focus_id==W_MOVER && mouse_x>=x_track+230-10 && mouse_x<=x_track+230+127+10 && mouse_y>=y_track+400 && mouse_y<=y_track+420)
    {
        if(mouse_button==1  && index_mouse_is_tracking==0  )
        {
            int data=mouse_x-(x_track+230);
            Tracker_splinelevel=constrain_data_to_midi_range(data);
            spline_ratio[dock_move_selected]=Tracker_splinelevel/127.0;
        }
    }

    LevelFaderSpline.Draw(CouleurLock);
    SliderFaderSpline.DrawOutline(Rgba::WHITE);
    Line(Vec2D(x_track+230+63,y_track+400), Vec2D(x_track+230+63,y_track+400+20)).Draw(CouleurLigne);
    Line(Vec2D(x_track+230+65,y_track+400), Vec2D(x_track+230+65,y_track+400+20)).Draw(CouleurLigne);

    Rect Timeshift(Vec2D(x_track+300,y_track+490),Vec2D(70,20));
    Timeshift.SetRoundness(3);


    if(window_focus_id==W_MOVER && mouse_x>x_track+300 && mouse_x<x_track+300+70 && mouse_y>y_track+490 && mouse_y<y_track+490+20)
    {
        Timeshift.Draw(CouleurSurvol);
        if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            index_time_shift=toggle(index_time_shift);
            mouse_released=1;
        }
    }

    Timeshift.Draw(CouleurFader.WithAlpha(index_time_shift));

    Timeshift.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("TimeShift",x_track+305, y_track+505);




    petitchiffre.Print("Banks of moves:",x_track+300,y_track-10);
    for(int dkmov=0; dkmov<5; dkmov++)
    {
        for(int dkline=0; dkline<6; dkline++)
        {
            Rect DockMove( Vec2D( x_track+300+(dkmov*40),y_track+(dkline*30) ), Vec2D ( 30,25));//box du fader
            DockMove.SetRoundness(5);

            if(window_focus_id==W_MOVER && mouse_x> x_track+300+(dkmov*40) && mouse_x< x_track+330+(dkmov*40) && mouse_y>y_track+(dkline*30) && mouse_y<y_track+25+(dkline*30))
            {
                DockMove.Draw(CouleurSurvol);
                if(mouse_button==1  && mouse_released==0)//index_mouse_is_tracking==0 )
                {
                    if(index_main_clear==0 && index_goto_record==0 && index_time_shift==0 && index_copy_params==0 )
                    {
                        dock_move_selected=(dkmov+(dkline*5)+1);
                        Tracker_speedlevel=(int)(((float)dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])]/BPS_RATE)*8);
                        Tracker_splinelevel=(int)((spline_ratio[dock_move_selected]+1)*100);
                    }
                    else if(index_main_clear==1 && index_goto_record==0 && index_time_shift==0 && index_copy_params==0 )
                    {
                        index_ask_clear_a_move=1;
                        move_to_clear=dkmov+(dkline*5)+1;
                        index_ask_confirm=1;
                    }
                    else if(index_goto_record==1 && index_main_clear==0 && index_time_shift==0  && index_copy_params==0 )
                    {
                        if(dock_move_selected!=(dkmov+(dkline*5)+1))
                        {
                            MoveAffectGoto(dock_move_selected,(dkmov+(dkline*5)+1));
                        }
                        else
                        {
                            MoveAffectGoto(dock_move_selected,0);
                        }
                    }

                    else if(index_time_shift==1 && index_main_clear==0 && index_goto_record==0  && index_copy_params==0 )
                    {
                        TimeShift(dock_move_selected);
                    }
                    else if(index_copy_params==1 &&  index_time_shift==0 && index_main_clear==0 && index_goto_record==0 )
                    {
                        SetAllParams(dkmov+(dkline*5)+1);
                        index_copy_params=0;
                    }

                    mouse_released=1;
                }
            }

            if(dock_move_selected==(dkmov+(dkline*5)+1))
            {
                DockMove.Draw(CouleurFader);
            }

            petitchiffre.Print(ol::ToString(dkmov+(dkline*5)+1), x_track+310+(dkmov*40),y_track+15+(dkline*30));
            DockMove.DrawOutline(Rgba::WHITE);
        }
    }

    param_editor(x_track+530,y_track);


    if(index_show_points==1)
    {
        Print_Points(dock_move_selected);
    }



    monTracker.DrawOutline( Rgba::WHITE );











    Rect AffectToDock( Vec2D( x_track+310,y_track+250 ), Vec2D ( 150,25));//box du fader
    AffectToDock.SetRoundness(7.5);
    AffectToDock.Draw(CouleurFader.WithAlpha(index_affect_to_dock_mover));
    AffectToDock.DrawOutline(CouleurLigne);

    petitchiffre.Print("Affect Mover to Dock",x_track+315,y_track+265);
    if(window_focus_id==W_MOVER && mouse_x>x_track+310 && mouse_x<x_track+310+150 && mouse_y>y_track+250 && mouse_y<y_track+250+25 && mouse_button==1 && mouse_released==0)
    {
        if(index_affect_to_dock_mover==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_affect_to_dock_mover=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_affect_to_dock_mover;
        mouse_released=1;
    }



    Rect BitMode(Vec2D(track_aera_x+20,track_aera_y+380),Vec2D(60,25));
    BitMode.SetRoundness(7.5);
    BitMode.SetLineWidth(epaisseur_ligne_fader);
    sprintf(string_tracker_coordonates,">> X: %d - Y: %d", buffer_moving_head[xadress],buffer_moving_head[yadress]);

    if(window_focus_id==W_MOVER && mouse_x>track_aera_x+20 && mouse_x< track_aera_x+80 && mouse_y>track_aera_y+380 && mouse_y<track_aera_y+405)
    {
        if(mouse_button==1  && mouse_released==0 && index_mouse_is_tracking==0 )
        {
            tracker_mode=toggle(tracker_mode);
            mouse_released=1;
        }
    }
    if (tracker_mode==0)
    {
        sprintf(string_tracker_mode," 8 Bits");
    }
    else if (tracker_mode==1)
    {
        BitMode.Draw(CouleurFader);
        sprintf(string_tracker_coordonates_fine,">> X: %d - Y: %d ", buffer_moving_head[xadress+1], buffer_moving_head[yadress+1]);
        sprintf(string_tracker_mode,"16 Bits")  ;
        petitchiffre.Print(string_tracker_coordonates_fine,x_track+110, y_track+450);
        v16viewX=convert_bytes_to_int(mover_params[0][0], mover_params[0][1]);
        v16viewY=convert_bytes_to_int(mover_params[1][0], mover_params[1][1]);
        sprintf(string_view_16bits_coordonates,"16 bits : X: %d  / Y: %d", v16viewX,v16viewY);
        petitchiffre.Print(string_view_16bits_coordonates,x_track+230,y_track+450);
    }
    BitMode.DrawOutline(Rgba::WHITE);
    petitchiffre.Print(string_tracker_mode,x_track+45, y_track+415);
    petitchiffre.Print(string_tracker_coordonates,x_track+110, y_track+415);


    Rect EditFine(Vec2D(track_aera_x+20,track_aera_y+415),Vec2D(60,25));
    EditFine.SetRoundness(7.5);
    EditFine.SetLineWidth(epaisseur_ligne_fader);

    if(window_focus_id==W_MOVER && mouse_x>track_aera_x+20 && mouse_x< track_aera_x+80 && mouse_y>track_aera_y+415 && mouse_y<track_aera_y+440)
    {
        EditFine.Draw(CouleurSurvol);
        if(mouse_button==1 && mouse_released==0  && index_mouse_is_tracking==0 && tracker_mode==1)
        {
            tracker_16b_edit=toggle(tracker_16b_edit);
            mouse_released=1;
        }
    }
    if (tracker_16b_edit==1)
    {
        EditFine.Draw(CouleurFader);
    }
    petitchiffre.Print("Edit 16b",x_track+45, y_track+450);
    EditFine.DrawOutline(Rgba::WHITE);

    Rect LockX(Vec2D(track_aera_x+20,track_aera_y+460),Vec2D(60,25));
    LockX.SetRoundness(7.5);
    LockX.SetLineWidth(epaisseur_ligne_fader);
    Rect LockY(Vec2D(track_aera_x+100,track_aera_y+460),Vec2D(60,25));
    LockY.SetRoundness(7.5);
    LockY.SetLineWidth(epaisseur_ligne_fader);

    if(window_focus_id==W_MOVER && mouse_y>track_aera_y+460 && mouse_y<track_aera_y+485)
    {
        if(mouse_x>track_aera_x+20 && mouse_x<track_aera_x+80)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
            {
                lockX_on=toggle(lockX_on);
                mouse_released=1;
            }
        }
        if(mouse_x>track_aera_x+100 && mouse_x<track_aera_x+160)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
            {
                lockY_on=toggle(lockY_on);
                mouse_released=1;
            }
        }
    }
    if(lockX_on==1)
    {
        LockX.Draw(CouleurFader);
    }
    if(lockY_on==1)
    {
        LockY.Draw(CouleurFader);
    }
    petitchiffre.Print("lock X",x_track+50, y_track+495);
    petitchiffre.Print("lock Y",x_track+130, y_track+495);
    LockX.DrawOutline(Rgba::WHITE);
    LockY.DrawOutline(Rgba::WHITE);


    Rect InvX(Vec2D(track_aera_x+20,track_aera_y+500),Vec2D(60,25));
    InvX.SetRoundness(7.5);
    InvX.SetLineWidth(epaisseur_ligne_fader);
    Rect InvY(Vec2D(track_aera_x+100,track_aera_y+500),Vec2D(60,25));
    InvY.SetRoundness(7.5);
    InvY.SetLineWidth(epaisseur_ligne_fader);

    if(window_focus_id==W_MOVER && mouse_y>track_aera_y+500 && mouse_y<track_aera_y+525)
    {
        if(mouse_x>track_aera_x+20 && mouse_x<track_aera_x+80)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
            {
                invX_on=toggle(invX_on);
                mouse_released=1;
            }
        }
        if(mouse_x>track_aera_x+100 && mouse_x<track_aera_x+160)
        {
            if(mouse_button==1 && mouse_released==0 && index_mouse_is_tracking==0 )
            {
                invY_on=toggle(invY_on);
                mouse_released=1;
            }
        }
    }


    if(invX_on==1)
    {
        InvX.Draw(CouleurFader);
    }
    if(invY_on==1)
    {
        InvY.Draw(CouleurFader);
    }

    petitchiffre.Print("Inv X",x_track+50, y_track+535);
    petitchiffre.Print("Inv Y",x_track+130, y_track+535);
    InvX.DrawOutline(Rgba::WHITE);
    InvY.DrawOutline(Rgba::WHITE);


    Rect ZeroPoint(Vec2D(x_track+40,y_track+566),Vec2D(140,25));
    ZeroPoint.SetRoundness(7.5);
    ZeroPoint.SetLineWidth(epaisseur_ligne_fader);

    if(window_focus_id==W_MOVER && mouse_x>x_track+40 && mouse_x<x_track+180 && mouse_y>y_track+566 && mouse_y<y_track+591)
    {
        if(mouse_button==1  && index_do_dock==1 &&  mouse_released==0 && index_mouse_is_tracking==0 )
        {
            position_defaut[0]=mover_params[0][0]-127;
            position_defaut[1]=mover_params[1][0]-127;
            sprintf(string_zero_point_is,"Offset X %d Y %d",position_defaut[0],position_defaut[1]);
            mouse_released=1;
        }
    }

    ZeroPoint.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("Set Offset",x_track+80, y_track+580);
    petitchiffre.Print(string_zero_point_is,x_track+60, y_track+610);


    return(0);
}
