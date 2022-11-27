int FunctionBoxChannel(int fx,int fy, int flarg, int fhaut, int space)
{
    for (int df=0; df<5; df++)
    {
        Rect FunctionChThr(Vec2D(fx, fy + (df*fhaut)+ (space*df)), Vec2D ( flarg,fhaut));
        FunctionChThr.SetRoundness(10);
        FunctionChThr.SetLineWidth(epaisseur_ligne_fader);
        FunctionChThr.DrawOutline(CouleurLigne);
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            if(mouse_x>fx && mouse_x<fx+flarg && mouse_y>fy + (df*fhaut)+ (space*df) && mouse_y<fy + (df*fhaut)+ (space*df)+fhaut)
            {
                FunctionChThr.DrawOutline(CouleurBlind);
            }
        }
        switch(df)
        {
        case 0:
            petitchiffre.Print("  ALL",fx+5, fy+15 + (df*fhaut)+ (space*df));
            petitpetitchiffre.Print(" Y",fx+40, fy+25 + (df*fhaut)+ (space*df));
            break;
        case 1:
            petitchiffre.Print("  INV",fx+5, fy+15 + (df*fhaut)+ (space*df));
            petitpetitchiffre.Print(" U",fx+40, fy+25 + (df*fhaut)+ (space*df));
            break;
        case 2:
            petitchiffre.Print(" THRU",fx+5, fy+15 + (df*fhaut)+ (space*df));
            petitpetitchiffre.Print("Tab",fx+40, fy+25 + (df*fhaut)+ (space*df));
            break;
        case 3:
            petitchiffre.Print("  COPY",fx+5, fy+15 + (df*fhaut)+ (space*df));
            petitpetitchiffre.Print(" Ctrl-C",fx+20, fy+25 + (df*fhaut)+ (space*df));
            break;
        case 4:
            petitchiffre.Print("  PASTE",fx+5, fy+15 + (df*fhaut)+ (space*df));
            petitpetitchiffre.Print(" Ctrl-V",fx+20, fy+25 + (df*fhaut)+ (space*df));
            break;
        default:
            break;
        }
    }
    return(0);
}
