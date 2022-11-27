int lfo_fader_functions (int cmptfader, int x, int y, int espacement)
{
    Rect GlobalBut(Vec2D(x, y),Vec2D( 25,25 ));//une seule décla pour un bouton // plus rapide !
    GlobalBut.SetRoundness(5);
    GlobalBut.SetLineWidth(epaisseur_ligne_fader);

    for (int dd=0; dd<core_user_define_nb_docks; dd++)
    {
        Circle SelectedOnLFO( x+(cmptfader*espacement)+150,y+10+(dd*40), 6);

        if (is_dock_for_lfo_selected[cmptfader][dd]==1)
        {
            SelectedOnLFO.Draw(CouleurFader);
        }
        SelectedOnLFO.DrawOutline(CouleurLigne);

    }

    Rect LFOSpeedFrame(Vec2D(x+(cmptfader*espacement)-5, y+375),Vec2D( 137, 25) );
    LFOSpeedFrame.SetLineWidth(epaisseur_ligne_fader);
    LFOSpeedFrame.SetRoundness(5);
    LFOSpeedFrame.DrawOutline(CouleurLigne.WithAlpha(0.4));
    Rect LFOSpeed(Vec2D(x+(cmptfader*espacement)-5+lfo_speed[cmptfader], y+375),Vec2D( 10, 25) );
    LFOSpeed.SetLineWidth(tiers_epaisseur_ligne_fader);
    LFOSpeed.SetRoundness(5);
    Line (Vec2D(x+(cmptfader*espacement)+64,y+370),Vec2D(x+(cmptfader*espacement)+64,y+400)).Draw(CouleurLigne);
    petitchiffre.Print(ol::ToString(lfo_speed[cmptfader]-64),x+(cmptfader*espacement)+145,y+380);
    LFOSpeed.Draw(CouleurFader);
    LFOSpeed.DrawOutline(CouleurLigne);


    Circle BMidiOut( x+((cmptfader*espacement)+150),y+397, 10);//box du fader
    BMidiOut.SetLineWidth(epaisseur_ligne_fader);
    BMidiOut.Draw(CouleurBlind.WithAlpha(midi_send_out[cmptfader+196]));
    BMidiOut.DrawOutline(CouleurGrisMoyen);

    raccrochage_midi_visuel_horizontal ( x+(cmptfader*espacement), y+375, 196+cmptfader,127,25);

    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)-6, y+320));
    if(do_light_setpos[cmptfader]==1)
    {
        GlobalBut.Draw(CouleurBlind);
        do_light_setpos[cmptfader]=0;
    }
    GlobalBut.Draw(CouleurSurvol.WithAlpha(ActionnateStopOn[cmptfader]));
    GlobalBut.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print("Stop",x+(cmptfader*espacement)-5,y+330);
    petitpetitchiffre.Print("Pos",x+(cmptfader*espacement-3),y+340);



    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+240));
    GlobalBut.DrawOutline(CouleurLigne);
    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+280) );
    GlobalBut.DrawOutline(CouleurLigne);
    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+320) );
    GlobalBut.DrawOutline(CouleurLigne);


    switch(lfo_mode_is[cmptfader])
    {
    case 1:
        GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+240));
        GlobalBut.Draw(CouleurFader);
        break;
    case 2:
        GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+280) );
        GlobalBut.Draw(CouleurFader);
        break;
    default:
        break;
    }
    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+320) );
    GlobalBut.Draw(CouleurFader.WithAlpha(lfo_cycle_is_on[cmptfader]));

    Line(Vec2D(x+(cmptfader*espacement)+117,y+245),Vec2D(Vec2D(x+(cmptfader*espacement)+117,y+260))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+117,y+245),Vec2D(Vec2D(x+(cmptfader*espacement)+110,y+250))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+117,y+245),Vec2D(Vec2D(x+(cmptfader*espacement)+124,y+250))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+110,y+245),Vec2D(Vec2D(x+(cmptfader*espacement)+125,y+245))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+117,y+285),Vec2D(Vec2D(x+(cmptfader*espacement)+117,y+300))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+110,y+295),Vec2D(Vec2D(x+(cmptfader*espacement)+117,y+300))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+124,y+295),Vec2D(Vec2D(x+(cmptfader*espacement)+117,y+300))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+110,y+300),Vec2D(Vec2D(x+(cmptfader*espacement)+125,y+300))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+110,y+325),Vec2D(Vec2D(x+(cmptfader*espacement)+115,y+340))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+115,y+340),Vec2D(Vec2D(x+(cmptfader*espacement)+120,y+325))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+120,y+325),Vec2D(Vec2D(x+(cmptfader*espacement)+125,y+340))).Draw(CouleurLigne);


    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+35, y+320));
    GlobalBut.Draw(CouleurFader.WithAlpha(lfo_cycle_steps[cmptfader]));
    GlobalBut.DrawOutline(CouleurLigne);
    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+70, y+280));
    GlobalBut.Draw(CouleurFader.WithAlpha(lfo_do_next_step[cmptfader][0]));
    GlobalBut.DrawOutline(CouleurLigne);
    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+70, y+320));
    GlobalBut.Draw(CouleurFader.WithAlpha(lfo_do_next_step[cmptfader][1]));
    GlobalBut.DrawOutline(CouleurLigne);



    Line(Vec2D(x+(cmptfader*espacement)+75,y+330),Vec2D(Vec2D(x+(cmptfader*espacement)+87,y+330))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+330),Vec2D(Vec2D(x+(cmptfader*espacement)+87,y+340))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+340),Vec2D(Vec2D(x+(cmptfader*espacement)+84,y+335))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+340),Vec2D(Vec2D(x+(cmptfader*espacement)+90,y+335))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+75,y+295),Vec2D(Vec2D(x+(cmptfader*espacement)+87,y+295))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+295),Vec2D(Vec2D(x+(cmptfader*espacement)+87,y+285))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+285),Vec2D(Vec2D(x+(cmptfader*espacement)+84,y+290))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+87,y+285),Vec2D(Vec2D(x+(cmptfader*espacement)+90,y+290))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+83,y+305),Vec2D(Vec2D(x+(cmptfader*espacement)+83,y+320))).Draw(CouleurLigne);

    Line(Vec2D(x+(cmptfader*espacement)+47,y+330),Vec2D(Vec2D(x+(cmptfader*espacement)+47,y+340))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+47,y+340),Vec2D(Vec2D(x+(cmptfader*espacement)+44,y+335))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+47,y+340),Vec2D(Vec2D(x+(cmptfader*espacement)+50,y+335))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+47,y+330),Vec2D(Vec2D(x+(cmptfader*espacement)+47,y+325))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+47,y+325),Vec2D(Vec2D(x+(cmptfader*espacement)+44,y+330))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+47,y+325),Vec2D(Vec2D(x+(cmptfader*espacement)+50,y+330))).Draw(CouleurLigne);
    Line(Vec2D(x+(cmptfader*espacement)+60,y+332),Vec2D(Vec2D(x+(cmptfader*espacement)+70,y+332))).Draw(CouleurLigne);


    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+240));
    GlobalBut.Draw(CouleurFader.WithAlpha(is_dock_for_lfo_selected[cmptfader][dock_used_by_fader_is[cmptfader]]));
    GlobalBut.DrawOutline(CouleurLigne);

    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+280));
    GlobalBut.DrawOutline(CouleurLigne);

    GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+320));
    GlobalBut.Draw(CouleurFader.WithAlpha(FaderIsFlash[cmptfader]));
    GlobalBut.DrawOutline(CouleurLigne);



    if( window_focus_id==W_FADERS && mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+163
            && mouse_y> y+320 && mouse_y< y+345)
    {
        if(mouse_button==1 &&  mouse_released==0)
        {
            if( Midi_Faders_Affectation_Type==0)
            {
                if(FaderIsFlash[cmptfader]==0)
                {
                    FaderIsFlash[cmptfader]=1;
                }
            }
            else
            {
                attribute_midi_to_control(900+cmptfader,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }
        }
        else if(mouse_released==1 && FaderIsFlash[cmptfader]==1 && Midi_Faders_Affectation_Type==0)
        {
            fader_set_level(cmptfader,0);
            FaderIsFlash[cmptfader]=0;
            midi_levels[900+cmptfader]=0;
        }


    }

    Circle SelectedOneLFO(x+(cmptfader*espacement)+150,y+253,4);
    SelectedOneLFO.DrawOutline(CouleurLigne);

    Circle SelectedAllLFOOneA(x+(cmptfader*espacement)+150,y+286,3);
    Circle SelectedAllLFOOneB(x+(cmptfader*espacement)+150,y+293,3);
    Circle SelectedAllLFOOneC(x+(cmptfader*espacement)+150,y+300,3);

    SelectedAllLFOOneA.DrawOutline(CouleurLigne);
    SelectedAllLFOOneB.DrawOutline(CouleurLigne);
    SelectedAllLFOOneC.DrawOutline(CouleurLigne);
    neuromoyen.Print("FL",x+(cmptfader*espacement)+142,y+337);


    if(window_focus_id==W_FADERS)
    {

        if( Midi_Faders_Affectation_Type!=0)
        {
            if( mouse_x>x+(cmptfader*espacement)-5 && mouse_x<x+(cmptfader*espacement)+132 && mouse_y>y+375 && mouse_y<y+400)
            {
                LFOSpeedFrame.DrawOutline(CouleurBlind);
                LFOSpeed.Draw(CouleurBlind);
            }
            else if(mouse_x> (x+(cmptfader*espacement)-6) && mouse_x<(x+(cmptfader*espacement)+19) && mouse_y>(y+320) && mouse_y<(y+345) )
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)-6, y+320));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+130 && mouse_y> y+240 && mouse_y< y+265)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+240));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+130 && mouse_y> y+280 && mouse_y< y+305)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+280) );
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+130 && mouse_y> y+320 && mouse_y< y+345)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+105, y+320) );
                GlobalBut.DrawOutline(CouleurBlind);
            }

            else if(mouse_x>x+(cmptfader*espacement)+70 && mouse_x<x+(cmptfader*espacement)+95 && mouse_y>y+280 && mouse_y<y+305)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+70, y+280));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+70 && mouse_x<x+(cmptfader*espacement)+95 && mouse_y>y+320 && mouse_y<y+345)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+70, y+320));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+35 && mouse_x<x+(cmptfader*espacement)+60 && mouse_y>y+320 && mouse_y<y+345)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+35, y+320));
                GlobalBut.DrawOutline(CouleurBlind);
            }


            else if(mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+153 && mouse_y> y+240 && mouse_y< y+265)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+240));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+153 && mouse_y> y+280 && mouse_y< y+305)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+280));
                GlobalBut.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+153 && mouse_y> y+320 && mouse_y< y+345)
            {
                GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)+138, y+320));
                GlobalBut.DrawOutline(CouleurBlind);
            }
        }//fin affect midi

        if(mouse_x> (x+(cmptfader*espacement)-6) && mouse_x<(x+(cmptfader*espacement)+19) && mouse_y>(y+320) && mouse_y<(y+345)
                && (index_do_dock==1 || index_main_clear==1) )
        {
            GlobalBut.MoveTo(Vec2D(x+(cmptfader*espacement)-6, y+320));
            GlobalBut.Draw(CouleurBlind.WithAlpha(alpha_blinker));
        }

    }




    return(0);
}
