int plot_draw_symbol_smokemachine(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=60.0*size_symbol;
    float taille_y=30.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y)));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(15*size_symbol),ploty-(taille_y)));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(15*size_symbol),ploty-(taille_y)+(10*size_symbol)));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(30*size_symbol),ploty-(taille_y)+(10*size_symbol)));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(30*size_symbol),ploty-(taille_y)+(20*size_symbol)));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(20*size_symbol),ploty));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(15*size_symbol),ploty));
    carcasse.Add(Vec2D(plotx+(taille_x/2)+(15*size_symbol),ploty+(taille_y)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));


    carcasse.Draw(CouleurPlotFill);
    carcasse.DrawOutline(CouleurPlotLine);

    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
        carcasse.DrawOutline(CouleurPlotLine);
    }


    return(0);
}
