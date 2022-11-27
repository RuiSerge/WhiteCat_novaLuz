int bouton_on_view(int xp, int yp, bool state)
{
Rect On(Vec2D(xp,yp),Vec2D(20,20));
On.SetRoundness(4);
if(state==1){On.Draw(CouleurFader);}
On.DrawOutline(CouleurLigne);
petitchiffre.Print("ON",xp+1,yp+14);
if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
On.DrawOutline(CouleurBlind);
}
}

return(0);
}
