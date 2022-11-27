void toggling_bar_view(int xp,int yp, bool state, const std::string titre)
{
Rect toggling_B(Vec2D(xp,yp),Vec2D(70,20));
toggling_B.SetRoundness(4);
toggling_B.Draw(CouleurFond.WithAlpha(0.4));
petitpetitchiffre.Print(titre,xp,yp+12);

}
