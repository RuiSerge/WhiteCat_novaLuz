int set_cue_in_view(int xp, int yp, bool state)
{
Rect SetLoopIN(Vec2D(xp,yp),Vec2D(20,20));
SetLoopIN.SetRoundness(4);

if(state==1){SetLoopIN.Draw(CouleurBlind);}

SetLoopIN.DrawOutline(CouleurLigne);
Line(Vec2D(xp,yp),Vec2D(xp+10,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+20,yp),Vec2D(xp+10,yp+10)).Draw(CouleurLigne);
petitpetitchiffre.Print("in",xp+6,yp+17);

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
SetLoopIN.DrawOutline(CouleurBlind);
}
}
return(0);
}
