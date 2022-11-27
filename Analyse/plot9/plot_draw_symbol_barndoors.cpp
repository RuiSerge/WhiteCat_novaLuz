int plot_draw_symbol_barndoors(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=60.0*size_symbol;
    float taille_y=30.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/3),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/3),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));

    Poly Side1;
    Side1.Add(Vec2D(plotx-(taille_x/1.6),ploty-(taille_y/2)));
    Side1.Add(Vec2D(plotx-(taille_x/3),ploty+(taille_y/2)));
    Side1.Add(Vec2D(plotx-(taille_x/3)-(5*size_symbol),ploty+(taille_y/2)));
    Side1.Add(Vec2D(plotx-(taille_x/1.6)-(5*size_symbol),ploty-(taille_y/2)));
    Side1.SetPivot(Vec2D(plotx,ploty));
    Side1.RotateBy(angle_pc*(6.5));

    Poly Side2;
    Side2.Add(Vec2D(plotx+(taille_x/1.6),ploty-(taille_y/2)));
    Side2.Add(Vec2D(plotx+(taille_x/3),ploty+(taille_y/2)));
    Side2.Add(Vec2D(plotx+(taille_x/3)+(5*size_symbol),ploty+(taille_y/2)));
    Side2.Add(Vec2D(plotx+(taille_x/1.6)+(5*size_symbol),ploty-(taille_y/2)));
    Side2.SetPivot(Vec2D(plotx,ploty));
    Side2.RotateBy(angle_pc*(6.5));

    carcasse.Draw(CouleurPlotFill);
    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
    }
    carcasse.DrawOutline(CouleurPlotLine);
    Side1.Draw(CouleurPlotLine);
    Side2.Draw(CouleurPlotLine);

    return(0);
}
