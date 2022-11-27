int Commandes_faders_generales(int xf, int yf)
{
    neuro.Print("All At Zero",xf-10,yf-30);
    Rect Commande(Vec2D(xf,yf),Vec2D(72,25));
    Commande.SetRoundness(7.5);
    Commande.SetLineWidth(epaisseur_ligne_fader);

    for (int u=0; u<8; u++)
    {
        Commande.MoveTo(Vec2D(xf,yf+(50*u)));
        Commande.DrawOutline(CouleurLigne);
        switch(u)
        {
        case 0:
            petitchiffre.Print("Faders",xf+5,yf+15+(50*u));
            break;
        case 1:
            petitchiffre.Print("Speed",xf+5,yf+15+(50*u));
            break;
        case 2:
            petitchiffre.Print("Lock",xf+5,yf+15+(50*u));
            break;
        case 3:
            petitchiffre.Print("LFO",xf+5,yf+15+(50*u));
            break;
        case 4:
            petitchiffre.Print("Loop",xf+5,yf+15+(50*u));
            break;
        case 5:
            petitchiffre.Print("ALL",xf+5,yf+15+(50*u));
            break;
        case 6:
            petitchiffre.Print("MidiOut",xf+5,yf+15+(50*u));
            break;
        case 7:
            petitchiffre.Print("RECALL",xf+5,yf+15+(50*u));
            break;
        default: break;
        }

        if(window_focus_id==W_MINIFADERS && Midi_Faders_Affectation_Type!=0 && mouse_x>xf && mouse_x<xf+72 && mouse_y>yf+(50*u) && mouse_y<yf+(50*u)+25)
        {
            Commande.DrawOutline(CouleurBlind);
        }


    }

    return(0);
}
