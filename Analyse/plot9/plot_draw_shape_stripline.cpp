int plot_draw_shape_stripline(float plotx1, float ploty1, float plotx2, float ploty2, float sizeshape,  float alphag,int typeofline,int colorpattern, bool isselected, bool show_handle)
{


glLineWidth (sizeshape);
switch(typeofline)
{
case 0:
glLineStipple (1, 0x0101);  /*  dotted  */
break;
case 1:
glLineStipple (4, 0x0101);
break;
case 2:
glLineStipple (3, 0x1F03);
break;
case 3:
glLineStipple (3, 0x1C47);  /*  dash/dot/dash  */
break;
case 4:
glLineStipple (3, 0x00FF);  /*  dashed  */
break;
default:
break;
}

switch(isselected)
{
case 0:
switch(colorpattern)
{
case 1://jaune
glColor4f(1.0,0.7,0.0,alphag);
break;
case 2: //Rouge
glColor4f(0.6,0.0,0.0,alphag);
break;
case 3: //Vert
glColor4f(0.0,0.6,0.0,alphag);
break;
case 4: //Bleu
glColor4f(0.0,0.2,0.5,alphag);
break;
default:
glColor4f(Color_plotline,Color_plotline,Color_plotline,alphag);
break;
}
break;
case 1:
glColor4f(1.0,0.4,0.0,1.0);
break;
default: break;
}

glEnable (GL_LINE_STIPPLE);
drawStippleLine(plotx1,ploty1,plotx2,ploty2);
glDisable (GL_LINE_STIPPLE);

glColor4f(0.0,0.0, 0.0, 1.0);
if(index_edit_light_plot==1 && index_menus_lighting_plot==1 && show_handle==1)//visualition du centre projo
{

Line(Vec2D(plotx1-5,ploty1-5),Vec2D(plotx1+5,ploty1+5)).Draw(CouleurBlind);
Line(Vec2D(plotx1+5,ploty1-5),Vec2D(plotx1-5,ploty1+5)).Draw(CouleurBlind);
Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).Draw(CouleurPlotLine.WithAlpha(isselected));
Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).DrawOutline(CouleurPlotLine);
Line(Vec2D(plotx2-5,ploty2-5),Vec2D(plotx2+5,ploty2+5)).Draw(CouleurBlind);
Line(Vec2D(plotx2+5,ploty2-5),Vec2D(plotx2-5,ploty2+5)).Draw(CouleurBlind);
}

return(0);
}
