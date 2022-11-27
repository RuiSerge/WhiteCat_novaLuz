int plot_draw_symbol_Par_4( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
float taille_x=40.0*size_symbol;
float taille_y=40.0*size_symbol;

Circle lentille(Vec2D(plotx,ploty),taille_x);
lentille.RotateBy(-angle_pc*6.5);
lentille.SetRadius(taille_x/2);
lentille.DrawSlice(CouleurPlotLine,0, PI);

Poly carcasse;
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty));
carcasse.Add(Vec2D(plotx,ploty+(taille_y)));
carcasse.SetPivot(Vec2D(plotx,ploty));
carcasse.RotateBy(angle_pc*(6.5));
carcasse.Draw(CouleurPlotLine);

if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
lentille.DrawSlice(CouleurFader,0, PI);
}

 return(0);
}
