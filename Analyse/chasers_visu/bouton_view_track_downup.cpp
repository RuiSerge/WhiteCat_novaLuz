int bouton_view_track_downup(int xcha, int ycha, bool state)
{

    Circle tChazeMinus(Vec2D(xcha+20,ycha+25),12);
    Circle tChazePlus(Vec2D(xcha+20,ycha+55),12);
    Line(Vec2D(xcha+12,ycha+30),Vec2D(xcha+28,ycha+30)).Draw(CouleurLigne);
    Line(Vec2D(xcha+12,ycha+30),Vec2D(xcha+20,ycha+16)).Draw(CouleurLigne);
    Line(Vec2D(xcha+28,ycha+30),Vec2D(xcha+20,ycha+16)).Draw(CouleurLigne);

    Line(Vec2D(xcha+12,ycha+49),Vec2D(xcha+28,ycha+49)).Draw(CouleurLigne);
    Line(Vec2D(xcha+12,ycha+49),Vec2D(xcha+20,ycha+63)).Draw(CouleurLigne);
    Line(Vec2D(xcha+28,ycha+49),Vec2D(xcha+20,ycha+63)).Draw(CouleurLigne);


    tChazePlus.DrawOutline(CouleurLigne);
    tChazeMinus.DrawOutline(CouleurLigne);
    if( Midi_Faders_Affectation_Type!=0  && window_focus_id==923)//config midi
    {
        if( mouse_x>xcha+8 && mouse_x<xcha+32 && mouse_y>ycha+13 && mouse_y<ycha+37)
        {
            tChazeMinus.DrawOutline(CouleurBlind);
        }
        if(mouse_x>xcha+8 && mouse_x<xcha+32 && mouse_y>ycha+43 && mouse_y<ycha+67)
        {
            tChazePlus.DrawOutline(CouleurBlind);
        }
    }

    return(0);
}
