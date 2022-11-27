int bouton_track_up(int xp, int yp,bool state)
{
Rect Btrack_up(Vec2D(xp,yp),Vec2D(40,20));
Btrack_up.SetRoundness(4);
if(state==1){ Btrack_up.Draw(CouleurFader);}
Btrack_up.DrawOutline(CouleurLigne);
Line(Vec2D(xp,yp+20),Vec2D(xp+40,yp+5)).Draw(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+40 && mouse_y>yp && mouse_y<yp+20)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
Btrack_up.DrawOutline(CouleurBlind);
}
}

return(0);
}
