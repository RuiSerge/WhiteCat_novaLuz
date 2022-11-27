int plot_draw_symbol_FollowSpot2(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
float taille_x=45.0*size_symbol;
float taille_y=110.0*size_symbol;

Poly carcasse;
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
carcasse.SetPivot(Vec2D(plotx,ploty));
carcasse.RotateBy(angle_pc*(6.5));

Poly fenetre;
fenetre.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(18*size_symbol)));
fenetre.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(18*size_symbol)));
fenetre.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(22*size_symbol)));
fenetre.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(22*size_symbol)));
fenetre.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(24*size_symbol)));
fenetre.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(24*size_symbol)));
fenetre.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(18*size_symbol)));
fenetre.SetPivot(Vec2D(plotx,ploty));
fenetre.RotateBy(angle_pc*(6.5));

Poly poignee;
poignee.Add(Vec2D(plotx-(12*size_symbol),ploty+(taille_y/2)));
poignee.Add(Vec2D(plotx-(12*size_symbol),ploty+(taille_y/2)+(8*size_symbol)));
poignee.Add(Vec2D(plotx+(12*size_symbol),ploty+(taille_y/2)+(8*size_symbol)));
poignee.Add(Vec2D(plotx+(12*size_symbol),ploty+(taille_y/2)));
poignee.SetPivot(Vec2D(plotx,ploty));
poignee.RotateBy(angle_pc*(6.5));


carcasse.Draw(CouleurPlotFill);
poignee.Draw(CouleurPlotFill);
if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
carcasse.Draw(CouleurFader);
poignee.Draw(CouleurFader);
}
poignee.DrawOutline(CouleurPlotLine);
carcasse.DrawOutline(CouleurPlotLine);
fenetre.DrawOutline(CouleurPlotLine);

return(0);
}