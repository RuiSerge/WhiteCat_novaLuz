int plot_draw_symbol_fresnel( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol , int plot_calc_number_is)
{
float taille_x=40.0*size_symbol;
float taille_y=40.0*size_symbol;

Poly carcasse;
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty));
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(5.0*size_symbol),ploty-(5*size_symbol)));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(10.0*size_symbol),ploty));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(15.0*size_symbol),ploty-(5*size_symbol)));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(20.0*size_symbol),ploty));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(25.0*size_symbol),ploty-(5*size_symbol)));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(30.0*size_symbol),ploty));
carcasse.Add(Vec2D(plotx+(taille_x/2)-(35.0*size_symbol),ploty-(5*size_symbol)));

carcasse.SetPivot(Vec2D(plotx,ploty));
carcasse.RotateBy(angle_pc*(6.5));
carcasse.Draw(CouleurPlotFill);
carcasse.DrawOutline(CouleurPlotLine);

if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
carcasse.Draw(CouleurFader);
}

return(0);
}
