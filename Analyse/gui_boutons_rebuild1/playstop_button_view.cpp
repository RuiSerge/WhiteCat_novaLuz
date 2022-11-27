int playstop_button_view(int xp, int yp, bool state)
{
Rect Play(Vec2D(xp,yp),Vec2D(20,20));
Play.SetRoundness(4);
if(state==1){Play.Draw(CouleurBlind);}
Play.DrawOutline(CouleurLigne);
Line(Vec2D(xp+4,yp+4),Vec2D(xp+4,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+4),Vec2D(xp+6,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+8,yp+4),Vec2D(xp+8,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+10,yp+4),Vec2D(xp+10,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+10,yp+4),Vec2D(xp+20,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+10,yp+16),Vec2D(xp+20,yp+10)).Draw(CouleurLigne);
if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
Play.DrawOutline(CouleurBlind);
}
}

return(0);
}
