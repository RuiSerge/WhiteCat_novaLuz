int plot_draw_symbol_jalousie(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{


float taille_x=60.0*size_symbol;
float taille_y=15.0*size_symbol;

Poly carcasse;
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
carcasse.SetPivot(Vec2D(plotx,ploty));
carcasse.RotateBy(angle_pc*(6.5));

Poly Side1;
for(int i=0;i<3;i++)
{
Side1.Add(Vec2D(plotx-((taille_x/4)*i),ploty+(taille_y/2)));
Side1.Add(Vec2D(plotx-((taille_x/4)*i),ploty-(taille_y/2)));
Side1.Add(Vec2D(plotx-((taille_x/4)*i)+(size_symbol*4),ploty-(taille_y/2)));
Side1.Add(Vec2D(plotx-((taille_x/4)*i)+(size_symbol*4),ploty+(taille_y/2)));
}
Poly Side2;
for(int i=0;i<3;i++)
{
Side2.Add(Vec2D(plotx+((taille_x/4)*i),ploty+(taille_y/2)));
Side2.Add(Vec2D(plotx+((taille_x/4)*i),ploty-(taille_y/2)));
Side2.Add(Vec2D(plotx+((taille_x/4)*i)-(size_symbol*4),ploty-(taille_y/2)));
Side2.Add(Vec2D(plotx+((taille_x/4)*i)-(size_symbol*4),ploty+(taille_y/2)));
}

Side1.SetPivot(Vec2D(plotx,ploty));
Side1.RotateBy(angle_pc*(6.5));
Side2.SetPivot(Vec2D(plotx,ploty));
Side2.RotateBy(angle_pc*(6.5));

carcasse.Draw(CouleurPlotFill);
if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
carcasse.Draw(CouleurFader);
}
carcasse.DrawOutline(CouleurPlotLine);
Side1.DrawOutline(CouleurPlotLine);
Side2.DrawOutline(CouleurPlotLine);


return(0);
}
