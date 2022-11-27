int plot_draw_symbol_Svoboda( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
float taille_x=120.0*size_symbol;
float taille_y=60.0*size_symbol;

Poly svobe;
svobe.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
svobe.Add(Vec2D(plotx-(taille_x/2),ploty));
svobe.Add(Vec2D(plotx-(taille_x/2.5),ploty+(taille_y/5)));
svobe.Add(Vec2D(plotx+(taille_x/2.5),ploty+(taille_y/5)));
svobe.Add(Vec2D(plotx+(taille_x/2),ploty));
svobe.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));

svobe.SetPivot(Vec2D(plotx,ploty));
svobe.RotateBy(angle_pc*(6.5));
svobe.Draw(CouleurPlotLine);

Poly svobe2;

svobe2.Add(Vec2D(plotx-(taille_x/2.5),ploty));
svobe2.Add(Vec2D(plotx-(taille_x/2.5),ploty+(taille_y/2)));
svobe2.Add(Vec2D(plotx+(taille_x/2.5),ploty+(taille_y/2)));
svobe2.Add(Vec2D(plotx+(taille_x/2.5),ploty));
svobe2.SetPivot(Vec2D(plotx,ploty));
svobe2.RotateBy(angle_pc*(6.5));
svobe2.Draw(CouleurPlotLine);

if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
svobe.DrawOutline(CouleurPlotLine);
svobe2.DrawOutline(CouleurPlotLine);
svobe.Draw(CouleurFader);
svobe2.Draw(CouleurFader);
}



return(0);
}
