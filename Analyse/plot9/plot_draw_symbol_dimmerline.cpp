int plot_draw_symbol_dimmerline(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

    float taille_x=40.0*size_symbol;

    Circle lentille(Vec2D(plotx,ploty),taille_x);
    lentille.Draw(CouleurPlotLine);
    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        lentille.Draw(CouleurFader);

    }
    Line(Vec2D(plotx-(taille_x/2.5),ploty-(taille_x/2.5)),Vec2D(plotx+(taille_x/2.5),ploty+(taille_x/2.5))).Draw(CouleurPlotFill);
    Line(Vec2D(plotx+(taille_x/2.5),ploty-(taille_x/2.5)),Vec2D(plotx-(taille_x/2.5),ploty+(taille_x/2.5))).Draw(CouleurPlotFill);
    lentille.DrawOutline(CouleurPlotLine);


    return(0);
}
