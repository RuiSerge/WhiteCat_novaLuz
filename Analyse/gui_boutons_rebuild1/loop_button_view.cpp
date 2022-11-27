int loop_button_view(int xp,int yp, bool state)
{
Rect GeneralLoop(Vec2D(xp,yp),Vec2D(20,20));
GeneralLoop.SetRoundness(4);
GeneralLoop.DrawOutline(CouleurLigne);
if(state==1){Circle(Vec2D(xp+10,yp+10),5).Draw(CouleurFader);}
Circle(Vec2D(xp+10,yp+10),5).DrawOutline(CouleurLigne);

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
GeneralLoop.DrawOutline(CouleurBlind);
}
}
return(0);
}
