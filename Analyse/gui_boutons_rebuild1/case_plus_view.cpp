int case_plus_view(int xp,int yp, bool state)
{
Rect PlusC(Vec2D(xp,yp),Vec2D(15,15));
PlusC.SetRoundness(2);
PlusC.Draw(CouleurFond.WithAlpha(0.4));
if(state==1){PlusC.Draw(CouleurBlind);}
petitchiffre.Print("+",xp+3,yp+10);
 return(0);
}
