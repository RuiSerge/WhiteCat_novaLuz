int selecteur_PDF_save_solo_global(int xrep, int yrep)
{

    char string_title_sav_spec[48];
    for(int u=0; u<12; u++)
    {
        Rect SavePin(Vec2D(xrep,yrep+(u*15)),Vec2D(10,10));
        if(specify_who_to_save_PDF[u]==1)
        {
            SavePin.Draw(CouleurFader);
        }

        switch (u)
        {
        case 0:
            sprintf(string_title_sav_spec,"MEMORIES");
            break;
        case 1:
            sprintf(string_title_sav_spec,"CHANNEL VIEW");
            break;
        case 2:
            sprintf(string_title_sav_spec,"CHANNELS from Plot and List");
            break;
        case 3:
            sprintf(string_title_sav_spec,"PATCH: per CHANNELS view");
            break;
        case 4:
            sprintf(string_title_sav_spec,"PATCH: per DIMMERS view");
            break;
        case 5:
            sprintf(string_title_sav_spec,"BANGER");
            break;
        case 6:
            sprintf(string_title_sav_spec,"AUDIO LIST OF FILES");
            break;
        case 7:
            sprintf(string_title_sav_spec,"FADERS");
            break;
        case 8:
            sprintf(string_title_sav_spec,"CHASERS");
            break;
        case 9:
            sprintf(string_title_sav_spec,"TRICHROMY");
            break;
        case 10:
            sprintf(string_title_sav_spec,"VIDEOTRACKING");
            break;
        case 11:
            sprintf(string_title_sav_spec,"GRIDPLAYERS");
            break;


        default:
            break;
        }
        petitpetitchiffre.Print(string_title_sav_spec,xrep+20,yrep+(u*15)+10);

        SavePin.DrawOutline(CouleurLigne);
    }


    for(int u=0; u<12; u++)
    {
        Rect SavePin(Vec2D(xrep+190,yrep+(u*15)),Vec2D(10,10));
        if(specify_who_to_save_PDF[u+12]==1)
        {
            SavePin.Draw(CouleurFader);
        }

        switch (u)
        {
        case 0:
            sprintf(string_title_sav_spec,"MOVER");
            break;
        case 1:
            sprintf(string_title_sav_spec,"ECHO");
            break;
        case 2:
            sprintf(string_title_sav_spec,"DRAW");
            break;
        case 9:
            sprintf(string_title_sav_spec,"ARDUINO");
            break;
        case 10:
            sprintf(string_title_sav_spec,"MIDI AFFECTATIONS");
            break;
        case 11:
            sprintf(string_title_sav_spec,"iCAT PRESETS");
            break;
        default:
            sprintf(string_title_sav_spec,"-");
            break;
        }
        petitpetitchiffre.Print(string_title_sav_spec,xrep+210,yrep+(u*15)+10);

        SavePin.DrawOutline(CouleurLigne);
    }

    return(0);
}
