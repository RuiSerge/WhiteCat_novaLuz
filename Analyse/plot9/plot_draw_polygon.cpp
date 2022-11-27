int plot_draw_polygon(int plotx1, int ploty1, float sizeshape, float shaperotation,int numPoints,  float alphashape,   int colorpattern, bool isselected)
{
float ployx ;
float ployy ;
Poly mypoly;

for(int i=0;i<numPoints;i++)
{
ployx = plotx1 + sizeshape * sin(2.0*PI*i/numPoints);
ployy = ploty1 + sizeshape * cos(2.0*PI*i/numPoints);
mypoly.Add(Vec2D(ployx,ployy));
}
mypoly.SetPivot(Vec2D(plotx1,ploty1));
mypoly.RotateBy(shaperotation*6.5);

if(isselected==1)
{
mypoly.DrawOutline(CouleurFader);
}
else
{

switch(colorpattern)
{
case 0://Outlined + Fill
mypoly.Draw(CouleurPlotFill.WithAlpha(alphashape));
mypoly.DrawOutline(CouleurPlotLine.WithAlpha(alphashape));
break;
case 1://Outlined only
mypoly.DrawOutline(CouleurPlotLine.WithAlpha(alphashape));
break;
case 2: //filled Outline color
mypoly.Draw(CouleurPlotLine.WithAlpha(alphashape));
break;
case 3: //filled PlotFill color
mypoly.Draw(CouleurPlotFill.WithAlpha(alphashape));
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
