int seek_cue_in_view(int xp,int yp, bool state)
{
    Rect SeekCue(Vec2D(xp,yp),Vec2D(20,20));
    SeekCue.SetRoundness(4);
    SeekCue.DrawOutline(CouleurLigne);
    if(state==1)
    {
        SeekCue.Draw(CouleurBlind);
    }
    Line(Vec2D(xp+16,yp+4),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);
    Line(Vec2D(xp+16,yp+4),Vec2D(xp+6,yp+10)).Draw(CouleurLigne);
    Line(Vec2D(xp+6,yp+10),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);
    Line(Vec2D(xp+4,yp+4),Vec2D(xp+4,yp+16)).Draw(CouleurLigne);

    if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
    {
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            SeekCue.DrawOutline(CouleurBlind);
        }
    }
    return(0);
}
