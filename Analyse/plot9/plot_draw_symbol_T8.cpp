int plot_draw_symbol_T8( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=120.0*size_symbol;
    float taille_y=20.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));
    carcasse.Draw(CouleurPlotFill);
    carcasse.DrawOutline(CouleurPlotLine);

    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
    }

    double txcl=0;
    double tycl=0;
    float rayon=taille_x/16;
    for (int r=-3; r<5; r++)
    {
        txcl= cos(angle_pc*-6.5)*(rayon+(18*size_symbol));
        tycl = sin(angle_pc*-6.5)*(rayon+(18*size_symbol));
        Circle ourlet(0, 0, rayon);
        ourlet.MoveTo(Vec2D(plotx+(txcl*r/2),ploty+(tycl*r/2)));
        ourlet.DrawOutline(CouleurPlotLine);
    }


    return(0);
}
