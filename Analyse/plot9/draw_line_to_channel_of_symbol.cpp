int draw_line_to_channel_of_symbol(int x1, int y1, int x2, int y2, int way)//way= 0 left to right 1= Right to left 2= up to down 3= down to up
{

switch(way)
{
case 0:
Line(Vec2D(x1,y1),Vec2D(x1,y2)).Draw(CouleurPlotLine.WithAlpha(0.5));
Line(Vec2D(x1,y2),Vec2D(x2,y2)).Draw(CouleurPlotLine.WithAlpha(0.5));
break;
case 1:
Line(Vec2D(x2,y2),Vec2D(x1,y2)).Draw(CouleurPlotLine.WithAlpha(0.5));
Line(Vec2D(x1,y2),Vec2D(x1,y1)).Draw(CouleurPlotLine.WithAlpha(0.5));
break;
case 2:
Line(Vec2D(x1,y1),Vec2D(x2,y1)).Draw(CouleurPlotLine.WithAlpha(0.5));
Line(Vec2D(x2,y1),Vec2D(x2,y2)).Draw(CouleurPlotLine.WithAlpha(0.5));
break;
case 3:
Line(Vec2D(x2,y2),Vec2D(x2,y1)).Draw(CouleurPlotLine.WithAlpha(0.5));
Line(Vec2D(x2,y1),Vec2D(x1,y1)).Draw(CouleurPlotLine.WithAlpha(0.5));
break;
default:
break;
}
 return(0);
}
