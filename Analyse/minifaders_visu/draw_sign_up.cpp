int draw_sign_up(int xs,int ys)
{
    Line(Vec2D(xs+12,ys+5),Vec2D(xs+12,ys+20)).Draw(CouleurLigne);//barre milieu vert
    Line(Vec2D(xs+12,ys+5),Vec2D(xs+5,ys+10)).Draw(CouleurLigne);
    Line(Vec2D(xs+12,ys+5),Vec2D(xs+19,ys+10)).Draw(CouleurLigne);
    Line(Vec2D(xs+5,ys+5),Vec2D(xs+20,ys+5)).Draw(CouleurLigne);//barre d arret
    return(0);
}
