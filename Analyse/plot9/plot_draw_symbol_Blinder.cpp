int plot_draw_symbol_Blinder( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=80.0*size_symbol;
    float taille_y=40.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));
    carcasse.Draw(CouleurPlotLine);


    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
    }

    double txcl=0;
    double tycl=0;
    float rayon=taille_x/8;

    txcl= cos(angle_pc*-6.5)*(rayon);
    tycl = sin(angle_pc*-6.5)*(rayon);
    Circle ourlet(0, 0, rayon);

    ourlet.MoveTo(Vec2D(plotx+(txcl),ploty+(tycl)));
    ourlet.Draw(CouleurPlotFill);
    ourlet.MoveTo(Vec2D(plotx-(txcl),ploty-(tycl)));
    ourlet.Draw(CouleurPlotFill);

    return(0);
}
