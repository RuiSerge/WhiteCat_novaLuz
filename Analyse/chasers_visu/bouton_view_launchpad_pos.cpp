int bouton_view_launchpad_pos(int xcha, int ycha, bool state)
{

Circle LchChazeMinus(Vec2D(xcha+20,ycha+25),12);
Circle LchChazePlus(Vec2D(xcha+50,ycha+25),12);
Line(Vec2D(xcha+12,ycha+25),Vec2D(xcha+24,ycha+30)).Draw(CouleurLigne);
Line(Vec2D(xcha+12,ycha+25),Vec2D(xcha+24,ycha+20)).Draw(CouleurLigne);
Line(Vec2D(xcha+24,ycha+20),Vec2D(xcha+24,ycha+30)).Draw(CouleurLigne);
Line(Vec2D(xcha+45,ycha+30),Vec2D(xcha+56,ycha+25)).Draw(CouleurLigne);
Line(Vec2D(xcha+56,ycha+25),Vec2D(xcha+45,ycha+20)).Draw(CouleurLigne);
Line(Vec2D(xcha+45,ycha+20),Vec2D(xcha+45,ycha+30)).Draw(CouleurLigne);

LchChazePlus.DrawOutline(CouleurLigne);
LchChazeMinus.DrawOutline(CouleurLigne);
if( Midi_Faders_Affectation_Type!=0 && window_focus_id==923)//config midi
{
if( mouse_x>xcha+8 && mouse_x<xcha+32 && mouse_y>ycha+13 && mouse_y<ycha+37)
{LchChazeMinus.DrawOutline(CouleurBlind);}
if(mouse_x>xcha+38 && mouse_x<xcha+62 && mouse_y>ycha+13 && mouse_y<ycha+37)
{LchChazePlus.DrawOutline(CouleurBlind);}
}

return(0);
}
