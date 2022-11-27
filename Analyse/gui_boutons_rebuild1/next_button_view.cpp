int next_button_view(int xp, int yp, bool state)
{
Rect NeXtbutt(Vec2D(xp,yp),Vec2D(20,20));
NeXtbutt.SetRoundness(4);

NeXtbutt.Draw(CouleurFond.WithAlpha(0.4));
if(state==1){NeXtbutt.Draw(CouleurBlind);}
Line(Vec2D(xp+6,yp+4),Vec2D(xp+6,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+4),Vec2D(xp+16,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+16),Vec2D(xp+16,yp+10)).Draw(CouleurLigne);

return(0);
}
