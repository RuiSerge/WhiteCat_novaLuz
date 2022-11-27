int plot_draw_symbol_slideprojector(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

float taille_x=40.0*size_symbol;
float taille_y=40.0*size_symbol;

Poly carcasse;
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
carcasse.SetPivot(Vec2D(plotx,ploty));
carcasse.RotateBy(angle_pc*(6.5));


Poly objectif;
objectif.Add(Vec2D(plotx+(5*size_symbol),ploty-(taille_y/2)));
objectif.Add(Vec2D(plotx+(15*size_symbol),ploty-(taille_y/2)));
objectif.Add(Vec2D(plotx+(15*size_symbol),ploty-(taille_y/2)-(8*size_symbol)));
objectif.Add(Vec2D(plotx+(5*size_symbol),ploty-(taille_y/2)-(8*size_symbol)));

objectif.SetPivot(Vec2D(plotx,ploty));
objectif.RotateBy(angle_pc*(6.5));

Circle Panier(Vec2D(plotx,ploty),(taille_x/2)-(5*size_symbol));

carcasse.Draw(CouleurPlotFill);
objectif.Draw(CouleurPlotFill);
if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
carcasse.Draw(CouleurFader);
objectif.Draw(CouleurFader);
}
objectif.DrawOutline(CouleurPlotLine);
carcasse.DrawOutline(CouleurPlotLine);
Panier.DrawOutline(CouleurPlotLine);


return(0);
}
