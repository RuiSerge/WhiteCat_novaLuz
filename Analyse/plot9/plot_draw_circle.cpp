int plot_draw_circle(int plotx1, int ploty1, float sizeshape,  float alphashape,   int colorpattern, bool isselected)
{
Circle ShapeCirc(plotx1, ploty1,sizeshape);

if(isselected==1)
{
ShapeCirc.DrawOutline(CouleurFader);
}
else
{

switch(colorpattern)
{
case 0://Outlined + Fill
ShapeCirc.Draw(CouleurPlotFill.WithAlpha(alphashape));
ShapeCirc.DrawOutline(CouleurPlotLine.WithAlpha(alphashape));
break;
case 1://Outlined only
ShapeCirc.DrawOutline(CouleurPlotLine.WithAlpha(alphashape));
break;
case 2: //filled Outline color
ShapeCirc.Draw(CouleurPlotLine.WithAlpha(alphashape));
break;
case 3: //filled PlotFill color
ShapeCirc.Draw(CouleurPlotFill.WithAlpha(alphashape));
break;
default: break;
}
}
if( index_edit_light_plot==1 && index_menus_lighting_plot==1)//visualition du centre projo
{
Line(Vec2D(plotx1-5,ploty1-5),Vec2D(plotx1+5,ploty1+5)).Draw(CouleurBlind);
Line(Vec2D(plotx1+5,ploty1-5),Vec2D(plotx1-5,ploty1+5)).Draw(CouleurBlind);
}
 return(0);
}
