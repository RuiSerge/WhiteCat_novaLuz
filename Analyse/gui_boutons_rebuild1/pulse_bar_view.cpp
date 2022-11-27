int pulse_bar_view(int xp,int yp, char *titre)
{
Rect pulse_B(Vec2D(xp,yp),Vec2D(30,20));
pulse_B.SetRoundness(4);
pulse_B.Draw(CouleurFond.WithAlpha(0.4));
petitpetitchiffre.Print(titre,xp,yp+12);

return(0);
}
