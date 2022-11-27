void bouton_text_view(int xp, int yp,const std::string dex, bool state)
{
    Rect Texn(Vec2D(xp,yp),Vec2D(20,20));
    Texn.SetRoundness(4);
    if(state==1)
    {
        Texn.Draw(CouleurFader);
    }
    Texn.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print(dex,xp+3,yp+14);
    if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
    {
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            Texn.DrawOutline(CouleurBlind);
        }
    }
}
