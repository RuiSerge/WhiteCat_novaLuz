int plot_draw_symbol_goboholder(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=60.0*size_symbol;
    float taille_y=70.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/4),ploty-(taille_y/2)-(taille_y/3)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/4),ploty-(taille_y/2)-(taille_y/3)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));

    carcasse.Draw(CouleurPlotLine);

    Circle Fenetre(plotx,ploty, taille_x/3);


    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
        carcasse.DrawOutline(CouleurPlotLine);
    }

    Fenetre.Draw(CouleurPlotFill);
    Fenetre.DrawOutline(CouleurPlotLine);
    return(0);
}
