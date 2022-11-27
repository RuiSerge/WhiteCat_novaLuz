int plot_draw_symbol_Horiziode_sym( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=60.0*size_symbol;
    float taille_y=40.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));
    carcasse.Draw(CouleurPlotFill);
    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
    }
    carcasse.DrawOutline(CouleurPlotLine);

    Poly lampe;
    lampe.Add(Vec2D(plotx-(taille_x/2)+(10*size_symbol),ploty));
    lampe.Add(Vec2D(plotx+(taille_x/2)-(10*size_symbol),ploty));

    lampe.Add(Vec2D(plotx+(taille_x/2)-(10*size_symbol),ploty+(2*size_symbol)));
    lampe.Add(Vec2D(plotx-(taille_x/2)+(10*size_symbol),ploty+(2*size_symbol)));
    lampe.SetPivot(Vec2D(plotx,ploty));
    lampe.RotateBy(angle_pc*(6.5));
    lampe.Draw(CouleurPlotLine);

    return(0);
}
