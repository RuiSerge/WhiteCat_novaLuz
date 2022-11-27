int plot_draw_symbol_pont50_3m(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=50.0*size_symbol;
    float taille_y=292.0*size_symbol;

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
    barreauhaut.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(4*size_symbol)));
    barreauhaut.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(8*size_symbol)));
    barreauhaut.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(8*size_symbol)));
    barreauhaut.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(4*size_symbol)));
    barreauhaut.SetPivot(Vec2D(plotx,ploty));
    barreauhaut.RotateBy(angle_pc*(6.5));

    Poly barreaubas;
    barreaubas.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)-(4*size_symbol)));
    barreaubas.Add(Vec2D(plotx-(taille_x/2),ploty+(taille_y/2)-(8*size_symbol)));
    barreaubas.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)-(8*size_symbol)));
    barreaubas.Add(Vec2D(plotx+(taille_x/2),ploty+(taille_y/2)-(4*size_symbol)));
    barreaubas.SetPivot(Vec2D(plotx,ploty));
    barreaubas.RotateBy(angle_pc*(6.5));

    Poly traverse;
    traverse.Add(Vec2D(plotx-(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
    traverse.Add(Vec2D(plotx-(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+(4*size_symbol)));
    traverse.Add(Vec2D(plotx+(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+((taille_y/3))-(4*size_symbol)));
    traverse.Add(Vec2D(plotx+(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+((taille_y/3))-(4*size_symbol)));
    traverse.SetPivot(Vec2D(plotx,ploty));
    traverse.RotateBy(angle_pc*(6.5));

    Poly traverse1;
    traverse1.Add(Vec2D(plotx+(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*2)+(4*size_symbol)));
    traverse1.Add(Vec2D(plotx+(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*2)+(4*size_symbol)));
    traverse1.Add(Vec2D(plotx-(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+((taille_y/3))-(4*size_symbol)));
    traverse1.Add(Vec2D(plotx-(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+((taille_y/3))-(4*size_symbol)));
    traverse1.SetPivot(Vec2D(plotx,ploty));
    traverse1.RotateBy(angle_pc*(6.5));


    Poly traverse2;
    traverse2.Add(Vec2D(plotx-(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*2)+(4*size_symbol)));
    traverse2.Add(Vec2D(plotx-(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*2)+(4*size_symbol)));
    traverse2.Add(Vec2D(plotx+(taille_x/2)+(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*3)-(4*size_symbol)));
    traverse2.Add(Vec2D(plotx+(taille_x/2)-(3*size_symbol),ploty-(taille_y/2)+((taille_y/3)*3)-(4*size_symbol)));
    traverse2.SetPivot(Vec2D(plotx,ploty));
    traverse2.RotateBy(angle_pc*(6.5));


    Poly barreau1;
    barreau1.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(taille_y/3)-(4*size_symbol)));
    barreau1.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+(taille_y/3)-(8*size_symbol)));
    barreau1.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(taille_y/3)-(8*size_symbol)));
    barreau1.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+(taille_y/3)-(4*size_symbol)));
    barreau1.SetPivot(Vec2D(plotx,ploty));
    barreau1.RotateBy(angle_pc*(6.5));


    Poly barreau2;
    barreau2.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+((taille_y/3)*2)-(4*size_symbol)));
    barreau2.Add(Vec2D(plotx-(taille_x/2),ploty-(taille_y/2)+((taille_y/3)*2)-(8*size_symbol)));
    barreau2.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+((taille_y/3)*2)-(8*size_symbol)));
    barreau2.Add(Vec2D(plotx+(taille_x/2),ploty-(taille_y/2)+((taille_y/3)*2)-(4*size_symbol)));
    barreau2.SetPivot(Vec2D(plotx,ploty));
    barreau2.RotateBy(angle_pc*(6.5));

    barreauhaut.Draw(CouleurPlotLine);
    side1.Draw(CouleurPlotLine);
    side2.Draw(CouleurPlotLine);
    barreaubas.Draw(CouleurPlotLine);
    traverse.Draw(CouleurPlotLine);
    traverse1.Draw(CouleurPlotLine);
    traverse2.Draw(CouleurPlotLine);
    barreau1.Draw(CouleurPlotLine);
    barreau2.Draw(CouleurPlotLine);
    if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
    {
        side1.Draw(CouleurFader);
        side2.Draw(CouleurFader);
        barreauhaut.Draw(CouleurFader);
        barreaubas.Draw(CouleurFader);
        traverse.Draw(CouleurFader);
        traverse1.Draw(CouleurFader);
        traverse2.Draw(CouleurFader);
        barreau1.Draw(CouleurFader);
        barreau2.Draw(CouleurFader);
    }

    return(0);
}
