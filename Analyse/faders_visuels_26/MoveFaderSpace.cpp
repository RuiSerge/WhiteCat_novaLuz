int MoveFaderSpace(int ydelimitation)
{
    Line myLine( Vec2D( 0, ydelimitation ), Vec2D( largeur_ecran,ydelimitation));
    myLine.SetLineWidth(triple_epaisseur_ligne_fader);
    if(window_focus_id==906)
    {
        myLine.Draw( CouleurFader );
    }
    else
    {
        myLine.Draw( CouleurLigne );
    }

    Rect Curseur_ScrollFader(Vec2D((int)(scroll_faderspace),ydelimitation-5),Vec2D(100,30));
    Curseur_ScrollFader.SetRoundness(10);
    Curseur_ScrollFader.SetLineWidth(double_epaisseur_ligne_fader);
    Line Delimitation(Vec2D(scroll_faderspace+50,ydelimitation-5),Vec2D(scroll_faderspace+50,ydelimitation+25));
    Delimitation.SetLineWidth(double_epaisseur_ligne_fader);

    Curseur_ScrollFader.Draw(CouleurFond);
    Delimitation.Draw( CouleurFader);
    Curseur_ScrollFader.DrawOutline(CouleurFader);

    if(mouse_y>=ydelimitation-5 && mouse_y<=ydelimitation+35 &&  window_focus_id==W_FADERS)
    {

        if(  Midi_Faders_Affectation_Type!=0 )
        {
            Curseur_ScrollFader.DrawOutline(CouleurBlind);

            if(  mouse_x>scroll_faderspace && mouse_x<scroll_faderspace+50  )
            {

                //midi report
                switch(miditable[0][767])
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
                    sprintf(thetypinfo,"-");
                    break;
                }
                sprintf(string_last_midi_id,"MoveFaderSpace LR is Ch: %d Pitch: %d Typ: %s", miditable[1][767],miditable[2][767],thetypinfo);
            }
        }
        if(  mouse_x>scroll_faderspace+50 && mouse_x<scroll_faderspace+100  )
        {
            //midi report
            switch(miditable[0][1635])
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
                sprintf(thetypinfo,"-");
                break;
            }
            sprintf(string_last_midi_id,"MoveFaderSpace UP is Ch: %d Pitch: %d Typ: %s", miditable[1][1635],miditable[2][1635],thetypinfo);
        }
    }


    if(index_moving_x_slide==1)
    {
        Canvas::SetClipping((int)(scroll_faderspace),ydelimitation-5,(int)(scroll_faderspace+50),30);
        Curseur_ScrollFader.Draw(CouleurFader.WithAlpha(index_moving_x_slide));
        Canvas::DisableClipping();
    }
    else if(index_moving_y_slide==1)
    {
        Canvas::SetClipping((int)(scroll_faderspace+50),ydelimitation-5,(int)(scroll_faderspace+100),30);
        Curseur_ScrollFader.Draw(CouleurFader.WithAlpha(index_moving_y_slide));
        Canvas::DisableClipping();
    }
    petitchiffre.Print("<< >>",(int)(scroll_faderspace+10),ydelimitation+15);

    Line( Vec2D( 65, ydelimitation ), Vec2D( 65,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 177, ydelimitation ), Vec2D( 177,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 286, ydelimitation ), Vec2D( 286,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 395, ydelimitation ), Vec2D( 395,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 504, ydelimitation ), Vec2D( 504,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 613, ydelimitation ), Vec2D( 613,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 722, ydelimitation ), Vec2D( 722,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 832, ydelimitation ), Vec2D( 832,ydelimitation+10)).Draw( CouleurLigne );
    Line( Vec2D( 885, ydelimitation ), Vec2D( 885,ydelimitation+10)).Draw( CouleurLigne );

    petitchiffre.Print( "1-6",75,ydelimitation+15 );
    petitchiffre.Print( "7-12",187,ydelimitation+15);
    petitchiffre.Print( "13-18",296,ydelimitation+15);
    petitchiffre.Print( "19-24",405,ydelimitation+15);
    petitchiffre.Print( "25-30",514,ydelimitation+15);
    petitchiffre.Print( "31-36",623,ydelimitation+15);
    petitchiffre.Print( "37-42",732,ydelimitation+15);
    petitchiffre.Print( "43-48",842,ydelimitation+15);





    return(0);
}
