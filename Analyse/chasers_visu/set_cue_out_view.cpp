int set_cue_out_view(int xp, int yp, bool state)
{
    Rect SetLoopOUT(Vec2D(xp,yp),Vec2D(20,20));
    SetLoopOUT.SetRoundness(4);

    if(state==1)
    {
        SetLoopOUT.Draw(CouleurBlind);
    }

    SetLoopOUT.DrawOutline(CouleurLigne);
    Line(Vec2D(xp,yp),Vec2D(xp+10,yp+10)).Draw(CouleurLigne);
    Line(Vec2D(xp+20,yp),Vec2D(xp+10,yp+10)).Draw(CouleurLigne);
    petitpetitchiffre.Print("out",xp+2,yp+17);

    if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
    {
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            SetLoopOUT.DrawOutline(CouleurBlind);
        }
    }
    return(0);
}
