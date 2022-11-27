int plot_draw_symbol_pont50_jonction(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=42.0*size_symbol;
    float taille_y=42.0*size_symbol;

    Poly side1;
    side1.Add(Vec2D(plotx-(taille_x/2)-(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
    side1.Add(Vec2D(plotx-(taille_x/2)+(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
    side1.Add(Vec2D(plotx-(taille_x/2)+(4*size_symbol),ploty+(taille_y/2)+(4*size_symbol)));
    side1.Add(Vec2D(plotx-(taille_x/2)-(4*size_symbol),ploty+(taille_y/2)+(4*size_symbol)));
    side1.SetPivot(Vec2D(plotx,ploty));
    side1.RotateBy(angle_pc*(6.5));

    Poly side2;
    side2.Add(Vec2D(plotx+(taille_x/2)-(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
    side2.Add(Vec2D(plotx+(taille_x/2)+(4*size_symbol),ploty-(taille_y/2)-(4*size_symbol)));
    side2.Add(Vec2D(plotx+(taille_x/2)+(4*size_symbol),ploty+(taille_y/2)+(4*size_symbol)));
    side2.Add(Vec2D(plotx+(taille_x/2)-(4*size_symbol),ploty+(taille_y/2)+(4*size_symbol)));
    side2.SetPivot(Vec2D(plotx,ploty));
    side2.RotateBy(angle_pc*(6.5));

    Poly barreauhaut;
    barreauhaut.Add(Vec2D(plotx-(taille_x/2)-(8*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
    barreauhaut.Add(Vec2D(plotx-(taille_x/2)-(8*size_symbol),ploty-(taille_y/2)+(8*size_symbol)));
    barreauhaut.Add(Vec2D(plotx+(taille_x/2)+(8*size_symbol),ploty-(taille_y/2)+(8*size_symbol)));
    barreauhaut.Add(Vec2D(plotx+(taille_x/2)+(8*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
    barreauhaut.SetPivot(Vec2D(plotx,ploty));
    barreauhaut.RotateBy(angle_pc*(6.5));

    Poly barreaubas;
    barreaubas.Add(Vec2D(plotx-(taille_x/2)-(8*size_symbol),ploty+(taille_y/2)-(4*size_symbol)));
    barreaubas.Add(Vec2D(plotx-(taille_x/2)-(8*size_symbol),ploty+(taille_y/2)-(8*size_symbol)));
    barreaubas.Add(Vec2D(plotx+(taille_x/2)+(8*size_symbol),ploty+(taille_y/2)-(8*size_symbol)));
    barreaubas.Add(Vec2D(plotx+(taille_x/2)+(8*size_symbol),ploty+(taille_y/2)-(4*size_symbol)));
    barreaubas.SetPivot(Vec2D(plotx,ploty));
    barreaubas.RotateBy(angle_pc*(6.5));

    barreauhaut.Draw(CouleurPlotLine);
    side1.Draw(CouleurPlotLine);
    side2.Draw(CouleurPlotLine);
    barreaubas.Draw(CouleurPlotLine);

    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        side1.Draw(CouleurFader);
        side2.Draw(CouleurFader);
        barreauhaut.Draw(CouleurFader);
        barreaubas.Draw(CouleurFader);
    }

    return(0);
}
