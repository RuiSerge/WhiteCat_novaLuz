int autolaunch_button_view(int xp,int yp, bool state)
{
Rect Autolch(Vec2D(xp,yp),Vec2D(20,20));
Autolch.SetRoundness(4);
if(state==1){Autolch.Draw(CouleurFader);}

Autolch.DrawOutline(CouleurLigne);

Line(Vec2D(xp+5,yp+15),Vec2D(xp+15,yp+5)).Draw(CouleurLigne);
Line(Vec2D(xp+15,yp+5),Vec2D(xp+10,yp+5)).Draw(CouleurLigne);
Line(Vec2D(xp+15,yp+5),Vec2D(xp+15,yp+10)).Draw(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
Autolch.DrawOutline(CouleurBlind);
}
}
return(0);
}
