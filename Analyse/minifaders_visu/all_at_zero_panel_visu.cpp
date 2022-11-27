int all_at_zero_panel_visu(int xf, int yf)
{

    char str_titre[15];
    petitpetitchiffre.Print("AtZero",xf+10,yf+5);
    Rect Commande(Vec2D(xf,yf),Vec2D(50,20));
    Commande.SetRoundness(4);

    for (int u=0; u<8; u++)
    {
        Commande.MoveTo(Vec2D(xf,yf+10+(25*u)));
        Commande.DrawOutline(CouleurLigne.WithAlpha(0.5));
        switch(u)
        {
        case 0:
            sprintf(str_titre,"Faders");
            break;
        case 1:
            sprintf(str_titre,"Speed");
            break;
        case 2:
            sprintf(str_titre,"Lock");
            break;
        case 3:
            sprintf(str_titre,"LFO");
            break;
        case 4:
            sprintf(str_titre,"Loop");
            break;
        case 5:
            sprintf(str_titre,"ALL");
            break;
        case 6:
            sprintf(str_titre,"MidiOut");
            break;
        case 7:
            sprintf(str_titre,"RECALL");
            break;
        default:
            break;
        }
        if(window_focus_id==W_MINIFADERS && mouse_x>xf && mouse_x<xf+50 && mouse_y>yf+10+(25*u) && mouse_y<yf+30+(25*u))
        {
            switch(miditable[0][548+u])
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
            sprintf(string_last_midi_id,"AtZero Command %d is Ch: %d Pitch: %d Type: %s",u, miditable[1][548+u],miditable[2][548+u],thetypinfo);
            //config midi

            if( Midi_Faders_Affectation_Type!=0)
            {

                Commande.DrawOutline(CouleurBlind);
            }

        }

        petitchiffre.Print(str_titre,xf+5,yf+23+(25*u));
    }

    return(0);
}
