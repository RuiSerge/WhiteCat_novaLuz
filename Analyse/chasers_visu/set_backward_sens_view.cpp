int set_backward_sens_view(int xp, int yp, bool state)
{

Rect BckSens(Vec2D(xp,yp),Vec2D(20,20));
BckSens.SetRoundness(4);

if(state==1){BckSens.Draw(CouleurFader);}
BckSens.DrawOutline(CouleurLigne);

Line(Vec2D(xp+4,yp+10),Vec2D(xp+18,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+10,yp+7),Vec2D(xp+4,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+10,yp+13),Vec2D(xp+4,yp+10)).Draw(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
BckSens.DrawOutline(CouleurBlind);
}
}
 return(0);
}
