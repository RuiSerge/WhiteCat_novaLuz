int draw_sign_next(int xs,int ys)
{
    Line(Vec2D(xs,ys+5),Vec2D(Vec2D(xs+12,ys+5))).Draw(CouleurLigne);
    Line(Vec2D(xs+12,ys+5),Vec2D(Vec2D(xs+12,ys+15))).Draw(CouleurLigne);
    Line(Vec2D(xs+12,ys+15),Vec2D(Vec2D(xs+9,ys+10))).Draw(CouleurLigne);
    Line(Vec2D(xs+12,ys+15),Vec2D(Vec2D(xs+15,ys+10))).Draw(CouleurLigne);
    return(0);
}
