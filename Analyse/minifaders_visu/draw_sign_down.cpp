int draw_sign_down(int xs,int ys)
{
    Line(Vec2D(xs+12,ys+2),Vec2D(xs+12,ys+15)).Draw(CouleurLigne);//barre milieu vert
    Line(Vec2D(xs+12,ys+15),Vec2D(xs+5,ys+10)).Draw(CouleurLigne);
    Line(Vec2D(xs+12,ys+15),Vec2D(xs+19,ys+10)).Draw(CouleurLigne);
    Line(Vec2D(xs+5,ys+15),Vec2D(xs+20,ys+15)).Draw(CouleurLigne);//barre d arret
    return(0);
}
