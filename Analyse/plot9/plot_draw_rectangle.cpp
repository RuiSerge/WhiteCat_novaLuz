int plot_draw_rectangle(int plotx1, int ploty1, float shapesizex, float shapesizey, float shaperotation, float alphashape, int colorpattern, bool isselected)
{
    Poly ShapeRect;
    ShapeRect.Add(Vec2D(plotx1-(shapesizex/2),ploty1-(shapesizey/2)));
    ShapeRect.Add(Vec2D(plotx1-(shapesizex/2),ploty1+(shapesizey/2)));
    ShapeRect.Add(Vec2D(plotx1+(shapesizex/2),ploty1+(shapesizey/2)));
    ShapeRect.Add(Vec2D(plotx1+(shapesizex/2),ploty1-(shapesizey/2)));

    ShapeRect.SetPivot(Vec2D(plotx1,ploty1));
    ShapeRect.RotateBy(shaperotation);

    if(isselected==1)
    {
        ShapeRect.DrawOutline(CouleurFader);
    }
    else
    {
        switch(colorpattern)
        {
        case 0://Outlined + Fill
            ShapeRect.Draw(CouleurPlotFill.WithAlpha(alphashape));
            ShapeRect.DrawOutline(CouleurPlotLine);
            break;
        case 1://Outlined only
            ShapeRect.DrawOutline(CouleurPlotLine.WithAlpha(alphashape));
            break;
        case 2: //filled Outline color
            ShapeRect.Draw(CouleurPlotLine.WithAlpha(alphashape));
            break;
        case 3: //filled PlotFill color
            ShapeRect.Draw(CouleurPlotFill.WithAlpha(alphashape));
            break;
        default:
            break;
        }
    }
    if(index_edit_light_plot==1)//visualition du centre projo
    {
        Line(Vec2D(plotx1-5,ploty1-5),Vec2D(plotx1+5,ploty1+5)).Draw(CouleurBlind);
        Line(Vec2D(plotx1+5,ploty1-5),Vec2D(plotx1-5,ploty1+5)).Draw(CouleurBlind);
    }

    return(0);
}
