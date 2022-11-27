int rotatif(int xr, int yr, int Rrayon, float valeur)
{
distance= Math.sqrt(px1*px2 + py1*py2);*/
Circle Rot(Vec2D(xr,yr),Rrayon);

Rot.SetRadius(Rrayon);
Rot.RotateBy(1);

Rot.DrawSlice(CouleurFond,0 , ((2*PI)-1) );
Rot.DrawSlice(CouleurLigne.WithAlpha(0.3),0 , ((2*PI)-1) );
Rot.SetRadius(Rrayon/1.5);
Rot.Draw(CouleurFond);
neuromoyen.Print(ol::ToString(valeur),xr-10,yr+10);

double Vx, Vy;
for(double v=-PI ;v<=PI ;v+=(PI/6))
{
 Vx=cos(v)*Rrayon;
 Vy=sin(v)*Rrayon;
 Line(Vec2D(xr,yr),Vec2D(xr+Vx,yr+Vy)).Draw(CouleurFond);
}
Vx=cos(((2*PI)-valeur)-2)*Rrayon;
Vy=sin(((2*PI)-valeur)-2)*Rrayon;
Line Curseur(Vec2D(xr,yr),Vec2D(xr+Vx,yr+Vy));
Curseur.SetLineWidth(Rrayon/5);
Curseur.Draw(CouleurLigne);
 return(0);
}
