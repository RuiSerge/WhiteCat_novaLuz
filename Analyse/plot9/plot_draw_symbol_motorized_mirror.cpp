int plot_draw_symbol_motorized_mirror(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=40.0*size_symbol;
    float taille_y=50.0*size_symbol;

    Poly carcasse;
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)));
    carcasse.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));

    carcasse.SetPivot(Vec2D(plotx,ploty));
    carcasse.RotateBy(angle_pc*(6.5));


    Poly carcasse2;
    carcasse2.Add(Vec2D(plotx-(taille_x/4),ploty-(taille_y/3)));
    carcasse2.Add(Vec2D(plotx+(taille_x/4),ploty-(taille_y/3)));
    carcasse2.Add(Vec2D(plotx+(taille_x/3)-(size_symbol*6),ploty));
    carcasse2.Add(Vec2D(plotx-(taille_x/3)+(size_symbol*6),ploty));

    carcasse2.SetPivot(Vec2D(plotx,ploty));
    carcasse2.RotateBy(angle_pc*(6.5));


    Poly carcasse3;
    carcasse3.Add(Vec2D(plotx-(taille_x/2)-(size_symbol*6),ploty+(taille_y/2)+(size_symbol*4)));
    carcasse3.Add(Vec2D(plotx+(taille_x/2)+(size_symbol*6),ploty+(taille_y/2)+(size_symbol*4)));
    carcasse3.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)));
    carcasse3.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)));

    carcasse3.SetPivot(Vec2D(plotx,ploty));
    carcasse3.RotateBy(angle_pc*(6.5));



    carcasse.Draw(CouleurPlotLine);
    carcasse2.Draw(CouleurPlotFill);
    carcasse3.Draw(CouleurPlotFill);

    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        carcasse.Draw(CouleurFader);
        carcasse2.Draw(CouleurFader);
        carcasse3.Draw(CouleurFader);
    }
    carcasse.DrawOutline(CouleurPlotLine);
    carcasse2.DrawOutline(CouleurPlotLine);
    carcasse3.DrawOutline(CouleurPlotLine);
    return(0);
}
