int plot_draw_symbol_iris(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=60.0*size_symbol;
    Circle Fenetre(plotx,ploty, size_symbol*(taille_x/3));

    Fenetre.Draw(CouleurPlotLine);

    Poly iris;
    iris.Add(Vec2D(plotx,ploty));
    iris.Add(Vec2D(plotx+(6*size_symbol),ploty));
    iris.Add(Vec2D(plotx+(taille_x/3)+(6*size_symbol),ploty-(taille_x/3)));
    iris.Add(Vec2D(plotx+(taille_x/3),ploty-(taille_x/3)));
    iris.SetPivot(Vec2D(plotx,ploty));
    iris.RotateBy(angle_pc*(6.5));
    iris.Draw(CouleurPlotLine);

    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        Fenetre.Draw(CouleurFader);
        Fenetre.DrawOutline(CouleurPlotLine);
        iris.Draw(CouleurFader);
        iris.DrawOutline(CouleurPlotLine);
    }

    Fenetre.SetRadius(taille_x/6);
    Fenetre.Draw(CouleurPlotFill);
    Fenetre.DrawOutline(CouleurPlotLine);

    return(0);
}
