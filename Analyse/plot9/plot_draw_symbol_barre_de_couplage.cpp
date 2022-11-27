int  plot_draw_symbol_barre_de_couplage(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
float taille_x=200.0*size_symbol;
Poly tourelle;
tourelle.Add(Vec2D(plotx-(taille_x/2),ploty-(10*size_symbol)));
tourelle.Add(Vec2D(plotx+(taille_x/2),ploty-(10*size_symbol)));
tourelle.Add(Vec2D(plotx+(taille_x/2),ploty));
tourelle.Add(Vec2D(plotx-(taille_x/2),ploty));
tourelle.SetPivot(Vec2D(plotx,ploty));
tourelle.RotateBy(angle_pc*(6.5));

tourelle.Draw(CouleurPlotLine);

if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
tourelle.Draw(CouleurFader);
tourelle.DrawOutline(CouleurPlotLine);
}


 return(0);
}
