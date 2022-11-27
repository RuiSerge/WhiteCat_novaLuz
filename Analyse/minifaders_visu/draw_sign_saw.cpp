int draw_sign_saw(int xs,int ys)
{
    Line(Vec2D(xs+5,ys+5),Vec2D(Vec2D(xs+10,ys+15))).Draw(CouleurLigne);
    Line(Vec2D(xs+10,ys+15),Vec2D(Vec2D(xs+15,ys+5))).Draw(CouleurLigne);
    Line(Vec2D(xs+15,ys+5),Vec2D(Vec2D(xs+20,ys+15))).Draw(CouleurLigne);
    return(0);
}
