int x1_x2(int x_seq,int y_seq)
{
    Rect FaderX1( Vec2D( x_seq+480,y_seq+80), Vec2D ( 45,255));//box du fader
    FaderX1.SetRoundness(15);
    FaderX1.SetLineWidth(epaisseur_ligne_fader);
    Rect FaderNiveauX1( Vec2D(  x_seq+480,((y_seq+335) - niveauX1)), Vec2D ( 45,niveauX1+2));//niveau fader
    FaderNiveauX1.SetRoundness(15);
    Rect FaderX2( Vec2D( x_seq+580,y_seq+80), Vec2D ( 45,255));//box du fader
    FaderX2.SetRoundness(15);
    FaderX2.SetLineWidth(epaisseur_ligne_fader);
    Rect FaderNiveauX2( Vec2D(  x_seq+580,((y_seq+335-niveauX2))), Vec2D ( 45,niveauX2));//niveau fader
    FaderNiveauX2.SetRoundness(15);
    FaderNiveauX1.Draw(CouleurNiveau.WithAlpha(0.5));
    FaderX1.DrawOutline(CouleurLigne);
    FaderNiveauX2.Draw(CouleurSurvol);
    FaderX2.DrawOutline(CouleurLigne);

    raccrochage_midi_visuel_vertical_dmx ( x_seq+480, (y_seq+80), 491, 45, 255);
    raccrochage_midi_visuel_vertical_dmx_inverted ( x_seq+580, (y_seq+80), 492, 45, 255);

    if(index_go==1 || index_pause==1)
    {
        if(crossfade_time_delay_out>(actual_time-crossfade_start_time) )
        {
            FaderX1.Draw(CouleurBlind.WithAlpha(alpha_blinker));
        }
        if(crossfade_time_delay_in>(actual_time-crossfade_start_time) )
        {
            FaderX2.Draw(CouleurBlind.WithAlpha(alpha_blinker));
        }
    }
    if(dmx_view==1)
    {
        neuro.Print(ol::ToString(niveauX1),x_seq+485,y_seq+70);
        neuro.Print(ol::ToString(niveauX2),x_seq+590,y_seq+70);
    }
    else
    {
        neuro.Print(ol::ToString((int)((float)niveauX1/2.55)),x_seq+485,y_seq+70);
        neuro.Print(ol::ToString((int)((float)niveauX2/2.55)),x_seq+590,y_seq+70);
    }

    Rect X1X2Together( Vec2D( x_seq+530,y_seq+50), Vec2D ( 50,20));//box du fader
    X1X2Together.SetRoundness(7.5);
    X1X2Together.SetLineWidth(demi_epaisseur_ligne_fader);
    X1X2Together.Draw(CouleurFader.WithAlpha(index_x1_x2_together));
    X1X2Together.DrawOutline(CouleurLigne);

    Line(Vec2D( x_seq+540,y_seq+55),Vec2D(x_seq+550,y_seq+55)).Draw(CouleurLigne);
    Line(Vec2D( x_seq+550,y_seq+55),Vec2D(x_seq+560,y_seq+65)).Draw(CouleurLigne);
    Line(Vec2D( x_seq+560,y_seq+65),Vec2D(x_seq+570,y_seq+65)).Draw(CouleurLigne);
    Line(Vec2D( x_seq+540,y_seq+65),Vec2D(x_seq+550,y_seq+65)).Draw(CouleurLigne);
    Line(Vec2D( x_seq+550,y_seq+65),Vec2D(x_seq+560,y_seq+55)).Draw(CouleurLigne);
    Line(Vec2D( x_seq+560,y_seq+55),Vec2D(x_seq+570,y_seq+55)).Draw(CouleurLigne);
    Rect index_together(Vec2D( x_seq+535,y_seq+60+ratio_X1X2_together+255),Vec2D(40,20));
    index_together.SetRoundness(4);
    index_together.SetLineWidth(epaisseur_ligne_fader);


    Line(Vec2D(x_seq+615,y_seq+311),Vec2D(x_seq+625,y_seq+311)).Draw(CouleurLigne);//1.1
    petitpetitchiffrerouge.Print("1.1",x_seq+635,y_seq+311);
    Line(Vec2D(x_seq+615,y_seq+292),Vec2D(x_seq+625,y_seq+292)).Draw(CouleurLigne);//1.2
    petitpetitchiffrerouge.Print("1.2",x_seq+635,y_seq+295);
    Line(Vec2D(x_seq+615,y_seq+275),Vec2D(x_seq+625,y_seq+275)).Draw(CouleurLigne);//1.3
    petitpetitchiffrerouge.Print("1.3",x_seq+635,y_seq+278);
    Line(Vec2D(x_seq+615,y_seq+261),Vec2D(x_seq+625,y_seq+261)).Draw(CouleurLigne);//1.4
    petitpetitchiffrerouge.Print("1.4",x_seq+635,y_seq+264);
    Line(Vec2D(x_seq+615,y_seq+249),Vec2D(x_seq+625,y_seq+249)).Draw(CouleurLigne);//1.5
    petitpetitchiffrerouge.Print("1.5",x_seq+635,y_seq+252);
    Line(Vec2D(x_seq+615,y_seq+239),Vec2D(x_seq+625,y_seq+239)).Draw(CouleurLigne);//1.6
    petitpetitchiffrerouge.Print("1.6",x_seq+635,y_seq+242);
    Line(Vec2D(x_seq+615,y_seq+229),Vec2D(x_seq+625,y_seq+229)).Draw(CouleurLigne);//1.7
    petitpetitchiffrerouge.Print("1.7",x_seq+635,y_seq+232);
    Line(Vec2D(x_seq+615,y_seq+221),Vec2D(x_seq+625,y_seq+221)).Draw(CouleurLigne);//1.8
    petitpetitchiffrerouge.Print("1.8",x_seq+635,y_seq+224);
    Line(Vec2D(x_seq+615,y_seq+213),Vec2D(x_seq+625,y_seq+213)).Draw(CouleurLigne);//1.9
    petitpetitchiffrerouge.Print("1.9",x_seq+635,y_seq+216);
    Line(Vec2D(x_seq+615,y_seq+207),Vec2D(x_seq+625,y_seq+207)).Draw(CouleurLigne);//2.0
    petitpetitchiffrerouge.Print("2",x_seq+635,y_seq+207);

    Line(Vec2D(x_seq+555,y_seq+70),Vec2D(x_seq+555,y_seq+70+255)).Draw(CouleurLigne);//gorge
    Line(Vec2D(x_seq+525,y_seq+90),Vec2D(x_seq+555,y_seq+90)).Draw(CouleurLigne);//vers stage
    Line(Vec2D(x_seq+555,y_seq+70+255),Vec2D(x_seq+580,y_seq+70+255)).Draw(CouleurLigne);//vers stage
    index_together.Draw(CouleurFond);
    index_together.DrawOutline(CouleurLigne);


    petitchiffre.Print(string_ratio_x1x2,x_seq+540,y_seq+330+ratio_X1X2_together);


    Circle GoTouch(Vec2D( x_seq+540+14,y_seq+375),20);
    GoTouch.SetLineWidth(epaisseur_ligne_fader);
    GoTouch.DrawOutline(CouleurLigne);
    GoTouch.DrawOutline(CouleurGreen.WithAlpha(Midi_Force_Go));


    GoTouch.Draw(CouleurFader.WithAlpha(index_go));
    GoTouch.DrawOutline(CouleurLigne);
    GoTouch.Draw(CouleurFond.WithAlpha(alpha_blinker*index_pause));
    GoTouch.DrawOutline(CouleurLigne);


    Line(Vec2D(x_seq+546, y_seq+365), Vec2D(x_seq+566, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+546, y_seq+385), Vec2D(x_seq+566, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+546, y_seq+365), Vec2D(x_seq+546, y_seq+385)).Draw(CouleurLigne);


    Circle GoBackTouch(Vec2D( x_seq+504,y_seq+375),20);
    GoBackTouch.SetLineWidth(epaisseur_ligne_fader);
    GoBackTouch.DrawOutline(CouleurLigne);
    GoBackTouch.Draw(CouleurFader.WithAlpha(index_go_back));
    GoBackTouch.DrawOutline(CouleurLigne);
    GoBackTouch.Draw(CouleurFond.WithAlpha(alpha_blinker*index_pause));
    GoBackTouch.DrawOutline(CouleurLigne);

    Line(Vec2D(x_seq+512, y_seq+365), Vec2D(x_seq+492, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+512, y_seq+385), Vec2D(x_seq+492, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+512, y_seq+365), Vec2D(x_seq+512, y_seq+385)).Draw(CouleurLigne);


    Circle DoubleGoTouch(Vec2D( x_seq+604,y_seq+375),20);
    DoubleGoTouch.SetLineWidth(epaisseur_ligne_fader);
    DoubleGoTouch.DrawOutline(CouleurLigne);


    Line(Vec2D(x_seq+593, y_seq+365), Vec2D(x_seq+613, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+593, y_seq+385), Vec2D(x_seq+613, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+593, y_seq+365), Vec2D(x_seq+593, y_seq+385)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+602, y_seq+365), Vec2D(x_seq+620, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+602, y_seq+385), Vec2D(x_seq+620, y_seq+375)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+602, y_seq+365), Vec2D(x_seq+602, y_seq+368)).Draw(CouleurLigne);
    Line(Vec2D(x_seq+602, y_seq+385), Vec2D(x_seq+602, y_seq+382)).Draw(CouleurLigne);



    Rect SequencielSpeedFrame(Vec2D(x_seq+485, y_seq+405),Vec2D( 127+10, 22) );
    SequencielSpeedFrame.SetLineWidth(epaisseur_ligne_fader);
    SequencielSpeedFrame.SetRoundness(5);
    SequencielSpeedFrame.DrawOutline(CouleurLigne);
    Rect SequencielSpeed(Vec2D(x_seq+485+crossfade_speed, y_seq+405),Vec2D( 10, 22) );
    SequencielSpeed.SetLineWidth(tiers_epaisseur_ligne_fader);
    SequencielSpeed.SetRoundness(5);

    Rect OnLinkReset(Vec2D(x_seq+548, y_seq+435),Vec2D( 15, 15) );
    OnLinkReset.Draw(CouleurBlind.WithAlpha(auto_reset_crossfade_speed_on_link));
    OnLinkReset.DrawOutline(CouleurLigne);



    Line (Vec2D(x_seq+554,y_seq+405),Vec2D(x_seq+554,y_seq+427)).Draw(CouleurLigne);

    petitchiffre.Print(str_crossfade_speed_is,x_seq+465,y_seq+430);
    SequencielSpeed.Draw(CouleurFader);

    Circle BMidiOut( x_seq+655,y_seq+340, 10);//box du fader
    BMidiOut.SetLineWidth(epaisseur_ligne_fader);
    BMidiOut.Draw(CouleurBlind.WithAlpha(midi_send_out[491]));
    BMidiOut.DrawOutline(CouleurLigne);
    Line (Vec2D( x_seq+620,y_seq+330),Vec2D(x_seq+640,y_seq+330)).Draw(CouleurLigne);
    Line (Vec2D(x_seq+640,y_seq+330),Vec2D(x_seq+650,y_seq+335)).Draw(CouleurLigne);



    Circle BSpeedMidiOut( x_seq+655,y_seq+425, 10);//box du fader
    BSpeedMidiOut.SetLineWidth(epaisseur_ligne_fader);
    BSpeedMidiOut.Draw(CouleurBlind.WithAlpha(midi_send_out[493]));
    BSpeedMidiOut.DrawOutline(CouleurLigne);
    Line (Vec2D( x_seq+620,y_seq+415),Vec2D(x_seq+640,y_seq+415)).Draw(CouleurLigne);
    Line (Vec2D(x_seq+620,y_seq+415),Vec2D(x_seq+650,y_seq+415)).Draw(CouleurLigne);

    raccrochage_midi_visuel_horizontal ( x_seq+490, y_seq+405, 493,127,13);



    if(window_focus_id==W_SEQUENCIEL)
    {

        if( Midi_Faders_Affectation_Type!=0 )
        {
            if(mouse_y>=y_seq+60 && mouse_y<=y_seq+355)//-20 +20
            {
                if(mouse_x> x_seq+480 && mouse_x< x_seq+525)
                {
                    FaderX1.DrawOutline(CouleurBlind);
                }
                else if(mouse_x> x_seq+580 && mouse_x< x_seq+625)
                {
                    FaderX2.DrawOutline(CouleurBlind);
                }
            }
            else if(mouse_x>x_seq+534 && mouse_x<x_seq+574 && mouse_y>y_seq+355 && mouse_y<y_seq+395)
            {
                GoTouch.DrawOutline(CouleurBlind);
            }
            else if( mouse_x>x_seq+484 && mouse_x<x_seq+524 && mouse_y>y_seq+355 && mouse_y<y_seq+395)
            {
                GoBackTouch.DrawOutline(CouleurBlind);
            }
            else if( mouse_x>x_seq+584 && mouse_x<x_seq+624 && mouse_y>y_seq+355 && mouse_y<y_seq+395)
            {
                DoubleGoTouch.DrawOutline(CouleurBlind);
            }
            else if( mouse_x> x_seq+548 && mouse_x<  x_seq+563 && mouse_y>y_seq+435 && mouse_y<y_seq+450 && Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"AutoReset Xfade Speed");
                show_type_midi(1591,sttmp );
                OnLinkReset.DrawOutline(CouleurBlind);
            }
            else if(mouse_x>=x_seq+490 && mouse_x<=x_seq+617 && mouse_y>y_seq+405 && mouse_y<y_seq+427)
            {
                switch(miditable[0][493])
                {
                case 0:
                    sprintf(thetypinfo,"Note");
                    break;
                case 1:
                    sprintf(thetypinfo,"Key On");
                    break;
                case 2:
                    sprintf(thetypinfo,"Key Off");
                    break;
                case 4:
                    sprintf(thetypinfo,"Ctrl Change");
                    break;
                default:
                    break;
                }
                sprintf(string_last_midi_id,"Sequenciel SPEED is Ch: %d Pitch: %d Typ: %s", miditable[1][493],miditable[2][493],thetypinfo);
                SequencielSpeedFrame.DrawOutline(CouleurBlind);

            }

        }


    }
    return(0);
}
