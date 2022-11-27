int case_moins_view(int xp,int yp, bool state)
{
Rect MoinsC(Vec2D(xp,yp),Vec2D(15,15));
MoinsC.SetRoundness(2);
MoinsC.Draw(CouleurFond.WithAlpha(0.4));
if(state==1){MoinsC.Draw(CouleurBlind);}
petitchiffre.Print("-",xp+3,yp+10);
 return(0);
}
