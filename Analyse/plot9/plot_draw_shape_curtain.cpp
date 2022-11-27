int plot_draw_shape_curtain(int plotx1, int ploty1, int plotx2, int ploty2, float sizeshape,  float alphashape,int colorpattern, bool isselected)
{
    float distance_x=plotx2-plotx1;
    float distance_y=ploty2-ploty1;
    int nbre_de_cercles=(int)(sqrt(distance_x*distance_x+distance_y*distance_y)/(sizeshape*2)); //get diagonal distance and divide by the diameter of a circle.
    float correctionx=(distance_x/nbre_de_cercles);
    float correctiony=(distance_y/nbre_de_cercles);
    double angle_ligne= atan2(ploty2 - ploty1, plotx2 - plotx1);
    bool inversion=0;

    for(int i=0; i<nbre_de_cercles; i++)
    {
        inversion=toggle(inversion);
        Circle ourlet(0, 0, sizeshape);
        ourlet.MoveTo(Vec2D(plotx1+cos(angle_ligne)*sizeshape+(correctionx*i),ploty1+sin(angle_ligne)*sizeshape+(correctiony*i)));
        ourlet.RotateBy(angle_ligne + PI*inversion);
        Rgba TmpColor;

        switch(isselected)
        {
        case 0:
            switch(colorpattern)
            {
            case 1://jaune
                TmpColor=CouleurYellowFgroup;
                break;
            case 2: //Rouge
                TmpColor=CouleurRed;
                break;
            case 3: //Vert
                TmpColor=CouleurGreen;
                break;
            case 4: //blue
                TmpColor=CouleurBleuProcedure;
                break;
            default:
                TmpColor=CouleurPlotLine;
                break;
            }
            ourlet.DrawSlice(TmpColor.WithAlpha(general_alpha_for_shape),0, PI);
            break;
        case 1:
            ourlet.DrawSlice(CouleurFader,0, PI);
            break;
        default:
            break;
        }
    }
    if( index_edit_light_plot==1 && index_menus_lighting_plot==1)//visualition du centre projo
    {
        Line(Vec2D(plotx1-5,ploty1-5),Vec2D(plotx1+5,ploty1+5)).Draw(CouleurBlind);
        Line(Vec2D(plotx1+5,ploty1-5),Vec2D(plotx1-5,ploty1+5)).Draw(CouleurBlind);
        Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).Draw(CouleurPlotLine.WithAlpha(handle_selected_for_line_editing*isselected));
        Rect(Vec2D(plotx2-5,ploty2-5),Vec2D(10,10)).DrawOutline(CouleurPlotLine);
        Line(Vec2D(plotx2-5,ploty2-5),Vec2D(plotx2+5,ploty2+5)).Draw(CouleurBlind);
        Line(Vec2D(plotx2+5,ploty2-5),Vec2D(plotx2-5,ploty2+5)).Draw(CouleurBlind);
    }
    return(0);
}
