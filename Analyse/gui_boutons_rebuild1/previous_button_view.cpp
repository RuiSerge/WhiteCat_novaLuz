int previous_button_view(int xp,int yp, bool state)
{
Rect PreVbutt(Vec2D(xp,yp),Vec2D(20,20));
PreVbutt.SetRoundness(4);

PreVbutt.Draw(CouleurFond.WithAlpha(0.4));
if(state==1){PreVbutt.Draw(CouleurBlind);}
Line(Vec2D(xp+16,yp+4),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);
Line(Vec2D(xp+16,yp+4),Vec2D(xp+6,yp+10)).Draw(CouleurLigne);
Line(Vec2D(xp+6,yp+10),Vec2D(xp+16,yp+16)).Draw(CouleurLigne);


return(0);
}
