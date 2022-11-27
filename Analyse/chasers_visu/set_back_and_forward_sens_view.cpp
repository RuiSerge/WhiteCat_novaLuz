int set_back_and_forward_sens_view(int xp, int yp, bool state)
{

Rect BckFwdSens(Vec2D(xp,yp),Vec2D(20,20));
BckFwdSens.SetRoundness(4);

if(state==1){BckFwdSens.Draw(CouleurFader);}
BckFwdSens.DrawOutline(CouleurLigne);

Line(Vec2D(xp+2,yp+10),Vec2D(xp+18,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+15,yp+7),Vec2D(xp+18,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+15,yp+13),Vec2D(xp+18,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+7),Vec2D(xp+2,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+13),Vec2D(xp+2,yp+10)).Draw(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
BckFwdSens.DrawOutline(CouleurBlind);
}
}
 return(0);
}
