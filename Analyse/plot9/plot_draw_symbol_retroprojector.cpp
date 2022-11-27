int plot_draw_symbol_retroprojector(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=60.0*size_symbol;
    float taille_y=60.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));


    Poly mirroir;
    mirroir.Add(Vec2D(plotx,ploty));
    mirroir.Add(Vec2D(plotx+(25*size_symbol),ploty));
    mirroir.Add(Vec2D(plotx+(25*size_symbol),ploty-(25*size_symbol)));
    mirroir.Add(Vec2D(plotx,ploty-(25*size_symbol)));

    mirroir.SetPivot(Vec2D(plotx,ploty));
    mirroir.RotateBy(angle_pc*(6.5));

    Poly bras;
    bras.Add(Vec2D(plotx,ploty+(5*size_symbol)));
    bras.Add(Vec2D(plotx+(taille_x/2),ploty+(5*size_symbol)));
    bras.Add(Vec2D(plotx+(taille_x/2),ploty));
    bras.Add(Vec2D(plotx,ploty));
    bras.SetPivot(Vec2D(plotx,ploty));
    bras.RotateBy(angle_pc*(6.5));


    angle_pc+=0.125;

    double txcl= cos(angle_pc*-6.5)*(taille_x/3);
    double tycl = sin(angle_pc*-6.5)*(taille_x/3);


    Circle Lentille(Vec2D(plotx+txcl,ploty+tycl),(8*size_symbol));


    carcasse.Draw(CouleurPlotFill);
    mirroir.Draw(CouleurPlotFill);
    bras.Draw(CouleurPlotFill);
    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
        mirroir.Draw(CouleurFader);
        bras.Draw(CouleurFader);
    }
    mirroir.DrawOutline(CouleurPlotLine);
    carcasse.DrawOutline(CouleurPlotLine);
    bras.DrawOutline(CouleurPlotLine);
    Lentille.DrawOutline(CouleurPlotLine);


    return(0);
}
