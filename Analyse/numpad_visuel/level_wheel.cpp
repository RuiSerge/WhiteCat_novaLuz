int level_wheel (int xw,int yw, int rayon_k, float angle_correction)
{
    Circle (Vec2D(xw,yw), rayon_k+5).DrawOutline(CouleurLigne);
    Circle (Vec2D(xw,yw), rayon_k-5).DrawOutline(CouleurLigne);
    Circle(Vec2D(position_curseur_pad_x,position_curseur_pad_y),5).Draw(CouleurBlind);

    int poucentmidi=(int)((((float)midi_levels[664])/127)*100);
    petitpetitchiffrerouge.Print(ol::ToString(poucentmidi),xw-5,yw+2);
    petitpetitchiffre.Print(ol::ToString(midi_levels[664]),xw-5,yw+12);

    if( Midi_Faders_Affectation_Type!=0)//config midi
    {
        if(mouse_x>xw-rayon_k-5 && mouse_x<xw+rayon_k+5 && mouse_y>yw-rayon_k-5 && mouse_y<yw+rayon_k+5)
        {
            Circle (Vec2D(xw,yw), rayon_k+5).DrawOutline(CouleurBlind);
            if(mouse_button==1 && mouse_released==0)
            {
                Circle (Vec2D(xw,yw), rayon_k+5).Draw(CouleurBlind);
            }
        }
    }

    Rect WheelMode(Vec2D(xw+rayon_k+10,yw-rayon_k),Vec2D(15,15));
    WheelMode.SetRoundness(3);

    switch(wheellevel_absolutemode)
    {
    case 0:
        WheelMode.Draw(CouleurLock);
        petitchiffre.Print("R",xw+rayon_k+13,yw-rayon_k+12);
        break;
    case 1:
        WheelMode.Draw(CouleurSurvol);
        petitchiffre.Print("A",xw+rayon_k+13,yw-rayon_k+12);
        break;
    default:
        break;
    }
    WheelMode.DrawOutline(CouleurLigne);

    Line (Vec2D(xw+rayon_k,yw+rayon_k-3),Vec2D(xw+rayon_k+7,yw+rayon_k+7)).Draw(CouleurLigne);
    Circle MidiOutW(Vec2D(xw+rayon_k+10,yw+rayon_k+10),7);
    if(midi_send_out[664]==1)
    {
        MidiOutW.Draw(CouleurBlind);
    }

    MidiOutW.DrawOutline(CouleurLigne);

    return(0);
}
