int plot_draw_shape_line(int plotx1, int ploty1, int plotx2, int ploty2, float sizeshape,  float alphashape, int colorpattern, bool isselected)
{
Rgba TmpColor;

switch(isselected)
{
case 0:
switch(colorpattern)
{
case 1://jaune
TmpColor=CouleurYellowFgroup;
break;
case 2: //Rouge
TmpColor=CouleurRed;
break;
case 3: //Vert
TmpColor=CouleurGreen;
break;
case 4: //blue
TmpColor=CouleurBleuProcedure;
break;
default:
TmpColor=CouleurPlotLine;
break;
}

Line(Vec2D(plotx1,ploty1),Vec2D(plotx2,ploty2),sizeshape).Draw(TmpColor.WithAlpha(alphashape));

break;
case 1:
Line(Vec2D(plotx1,ploty1),Vec2D(plotx2,ploty2),sizeshape).Draw(CouleurFader);
break;
default: break;
}
if(index_edit_light_plot==1 && index_menus_lighting_plot==1)//visualition du centre projo
{
Line(Vec2D(plotx1-5,ploty1-5),Vec2D(plotx1+5,ploty1+5)).Draw(CouleurBlind);
Line(Vec2D(plotx1+5,ploty1-5),Vec2D(plotx1-5,ploty1+5)).Draw(CouleurBlind);
Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).Draw(CouleurPlotLine.WithAlpha(handle_selected_for_line_editing*isselected));
Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).DrawOutline(CouleurPlotLine);
Line(Vec2D(plotx2-5,ploty2-5),Vec2D(plotx2+5,ploty2+5)).Draw(CouleurBlind);
Line(Vec2D(plotx2+5,ploty2-5),Vec2D(plotx2-5,ploty2+5)).Draw(CouleurBlind);
}



 return(0);
}
