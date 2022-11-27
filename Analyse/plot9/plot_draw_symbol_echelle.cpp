int plot_draw_symbol_echelle(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
float taille_x=60.0*size_symbol;
float taille_y=240.0*size_symbol;
Poly tourelle;
tourelle.Add(Vec2D(plotx-(taille_x/2)-(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
tourelle.Add(Vec2D(plotx+(taille_x/2)+(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
tourelle.Add(Vec2D(plotx+(taille_x/2)+(4*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
tourelle.Add(Vec2D(plotx-(taille_x/2)-(4*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
tourelle.SetPivot(Vec2D(plotx,ploty));
tourelle.RotateBy(angle_pc*(6.5));
Poly carcasse1;
carcasse1.Add(Vec2D(plotx-(4*size_symbol)+(taille_x/2),ploty-(taille_y/2)));
carcasse1.Add(Vec2D(plotx+(4*size_symbol)+(taille_x/2),ploty-(taille_y/2)));
carcasse1.Add(Vec2D(plotx+(4*size_symbol)+(taille_x/2),ploty+(taille_y/2)));
carcasse1.Add(Vec2D(plotx-(4*size_symbol)+(taille_x/2),ploty+(taille_y/2)));
carcasse1.SetPivot(Vec2D(plotx,ploty));
carcasse1.RotateBy(angle_pc*(6.5));

Poly carcasse2;
carcasse2.Add(Vec2D(plotx-(4*size_symbol)-(taille_x/2),ploty-(taille_y/2)));
carcasse2.Add(Vec2D(plotx+(4*size_symbol)-(taille_x/2),ploty-(taille_y/2)));
carcasse2.Add(Vec2D(plotx+(4*size_symbol)-(taille_x/2),ploty+(taille_y/2)));
carcasse2.Add(Vec2D(plotx-(4*size_symbol)-(taille_x/2),ploty+(taille_y/2)));
carcasse2.SetPivot(Vec2D(plotx,ploty));
carcasse2.RotateBy(angle_pc*(6.5));

Poly carcasse3;
carcasse3.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/6)-(4*size_symbol)));
carcasse3.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/6)-(4*size_symbol)));
carcasse3.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/6)+(4*size_symbol)));
carcasse3.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/6)+(4*size_symbol)));
carcasse3.SetPivot(Vec2D(plotx,ploty));
carcasse3.RotateBy(angle_pc*(6.5));

Poly carcasse4;
carcasse4.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/5)-(4*size_symbol)));
carcasse4.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/5)-(4*size_symbol)));
carcasse4.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/5)+(4*size_symbol)));
carcasse4.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/5)+(4*size_symbol)));
carcasse4.SetPivot(Vec2D(plotx,ploty));
carcasse4.RotateBy(angle_pc*(6.5));

tourelle.Draw(CouleurPlotLine);
carcasse1.Draw(CouleurPlotLine);
carcasse2.Draw(CouleurPlotLine);
carcasse3.Draw(CouleurPlotLine);
carcasse4.Draw(CouleurPlotLine);

if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
tourelle.Draw(CouleurFader);
carcasse1.Draw(CouleurFader);
carcasse2.Draw(CouleurFader);
carcasse3.Draw(CouleurFader);
carcasse4.Draw(CouleurFader);
}

 return(0);
}
