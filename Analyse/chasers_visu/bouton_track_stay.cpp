int bouton_track_stay(int xp, int yp,bool state)
{
Rect Btrack_stay(Vec2D(xp,yp),Vec2D(40,20));
Btrack_stay.SetRoundness(4);
if(state==1){ Btrack_stay.Draw(CouleurGreen);}
Btrack_stay.DrawOutline(CouleurLigne);
Line(Vec2D(xp,yp+5),Vec2D(xp+40,yp+5)).Draw(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+40 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
Btrack_stay.DrawOutline(CouleurBlind);
}
}

return(0);
}
