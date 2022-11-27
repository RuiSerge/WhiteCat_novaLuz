int plot_draw_slice(int plotx1, int ploty1, float sizeshape, float opening_angle, float shaperotation, float alphashape,   int colorpattern, bool isselected)
{

Circle arcdecercle(Vec2D(plotx1,ploty1),sizeshape);
arcdecercle.RotateBy(shaperotation*6.5);
arcdecercle.SetRadius(sizeshape/2);

if(isselected==1)
{
arcdecercle.DrawSlice(CouleurFader,0,opening_angle);
}
else
{

switch(colorpattern)
{
case 0://Outlined + Fill
arcdecercle.DrawSlice(CouleurPlotFill.WithAlpha(alphashape),CouleurPlotLine.WithAlpha(alphashape),0,opening_angle);
break;
case 1://Outlined only
arcdecercle.DrawSlice(CouleurPlotLine.WithAlpha(alphashape),CouleurPlotFill.WithAlpha(alphashape),0,opening_angle);
break;
case 2: //filled Outline color
arcdecercle.DrawSlice(CouleurPlotLine.WithAlpha(alphashape),0,opening_angle);
break;
case 3: //filled PlotFill color
arcdecercle.DrawSlice(CouleurPlotFill.WithAlpha(alphashape),0,opening_angle);
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
