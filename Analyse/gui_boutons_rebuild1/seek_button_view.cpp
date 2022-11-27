int seek_button_view(int xp,int yp, bool state)
{
Rect SeekToZero(Vec2D(xp,yp),Vec2D(20,20));
SeekToZero.SetRoundness(4);
Line(Vec2D(xp+16,yp+4),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+16,yp+4),Vec2D(xp+6,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+10),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+4,yp+4),Vec2D(xp+4,yp+16)).Draw(CouleurLigne);
SeekToZero.DrawOutline(CouleurLigne);
if(state==1){SeekToZero.Draw(CouleurFader);}

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
SeekToZero.DrawOutline(CouleurBlind);
}
}
return(0);
}
