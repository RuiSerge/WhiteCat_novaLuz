int plot_shape_list(int plotx,int ploty)
{

    Rect PlotSymbList(Vec2D(plotx,ploty),Vec2D(205,140));
    PlotSymbList.SetRoundness(15);
    PlotSymbList.Draw(CouleurBleuProcedure.WithAlpha(0.3));
    PlotSymbList.DrawOutline(CouleurPlotLine.WithAlpha(0.4));

    Rect UnderName(Vec2D(plotx+10,ploty+5),Vec2D(185,20));
    UnderName.SetRoundness(5);
    switch(index_edit_symbol_plot)
    {
    case 0:
        UnderName.Draw(CouleurPlotLine.WithAlpha(0.4));
        break;
    case 1:
        UnderName.Draw(CouleurSurvol);
        break;
    default:
        break;
    }
    UnderName.DrawOutline(CouleurPlotLine.WithAlpha(0.4));
    petitchiffrenoir.Print(shape_nickname[shape_selected_type],plotx+12,ploty+18);
    Line(Vec2D(plotx+12,ploty+50),Vec2D(plotx+28,ploty+50)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+12,ploty+50),Vec2D(plotx+20,ploty+36)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+28,ploty+50),Vec2D(plotx+20,ploty+36)).Draw(CouleurPlotLine);

    if(window_focus_id==W_PLOT && mouse_x>plotx+12 && mouse_x<plotx+28 && mouse_y>ploty+36 && mouse_y<ploty+50
            && Midi_Faders_Affectation_Type!=0)
    {
        Line(Vec2D(plotx+12,ploty+50),Vec2D(plotx+28,ploty+50)).Draw(CouleurBlind);
        Line(Vec2D(plotx+12,ploty+50),Vec2D(plotx+20,ploty+36)).Draw(CouleurBlind);
        Line(Vec2D(plotx+28,ploty+50),Vec2D(plotx+20,ploty+36)).Draw(CouleurBlind);
        show_type_midi(1596,"Plot List Up");
    }


    Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+28,ploty+69)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+28,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurPlotLine);
    petitchiffrenoir.Print(ol::ToString(shape_selected_type),plotx+13,ploty+62);

    if(window_focus_id==W_PLOT && mouse_x>plotx+12 && mouse_x<plotx+28 && mouse_y>ploty+69 && mouse_y<ploty+83
            && Midi_Faders_Affectation_Type!=0)
    {
        Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+28,ploty+69)).Draw(CouleurBlind);
        Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurBlind);
        Line(Vec2D(plotx+28,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurBlind);
        show_type_midi(1597,"Plot List Down");
    }


    Rect SliderSel(Vec2D(plotx+3,ploty+30),Vec2D(5,64));
    Rect SliderVel(Vec2D(plotx+3,ploty+30+(64-(shape_selected_type*6))),Vec2D(5,(shape_selected_type*6)));
    SliderSel.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
    SliderVel.Draw(CouleurBleuProcedure);

    if(window_focus_id==W_PLOT && mouse_x>plotx+3 && mouse_x<plotx+8 && mouse_y>ploty+30 && mouse_y<ploty+94
            &&  Midi_Faders_Affectation_Type!=0)
    {
        SliderSel.DrawOutline(CouleurBlind);
        show_type_midi(1598,"Plot List CC");
    }

    Rect add_symbol_frame(Vec2D(plotx+40,ploty+110),Vec2D(80,20));
    add_symbol_frame.SetRoundness(5);
    add_symbol_frame.DrawOutline(CouleurPlotLine);
    petitchiffrenoir.Print("Add To Plot",plotx+45,ploty+122);
    petitchiffrenoir.Print(ol::ToString(nbre_shapes_on_plot),plotx+15,ploty+122);
    if(window_focus_id==W_PLOT && mouse_x>plotx+40 && mouse_x<plotx+40+80 && mouse_y>ploty+110 && mouse_y<ploty+110+20
            &&  Midi_Faders_Affectation_Type!=0)
    {
        add_symbol_frame.DrawOutline(CouleurBlind);
        show_type_midi(1600,"Plot Add Symbol");
    }

    switch(shape_selected_type)
    {
    case 0:    //curtain
        plot_draw_shape_curtain(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/5,  1.0,color_pattern_selected, 0);
        break;
    case 1:     //ligne  plain
        plot_draw_shape_line(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,  1.0, color_pattern_selected, 0);
        break;
    case 2:     //stripline 1               int plotx1, int ploty1, int plotx2, int ploty2, float sizeshape,  float alphag, short typeofline,col pattern, bool isselected, bool edit extrem)
        plot_draw_shape_stripline(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,1.0, 0,  color_pattern_selected,0, 1);
        break;
    case 3:     //stripline 2
        plot_draw_shape_stripline(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,1.0, 1,  color_pattern_selected,0, 1);
        break;
    case 4:     //stripline 3
        plot_draw_shape_stripline(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,1.0, 2,  color_pattern_selected,0, 1);
        break;
    case 5:     //stripline 4
        plot_draw_shape_stripline(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,1.0, 3, color_pattern_selected, 0, 1);
        break;
    case 6:     //stripline 5
        plot_draw_shape_stripline(plotx+50, ploty+55, plotx+200, ploty+55, general_shape_size_to_apply/10,1.0, 4,  color_pattern_selected,0, 1);
        break;
    case 7://plot_draw_rectangle(int plotx1, int ploty1, int shapesizex, int shapesizey, float shaperotation, float alphashape,  int colorpattern, bool isselected)
        plot_draw_rectangle(plotx+120,ploty+60, 40, 20, angle_shape_selected, 1.0, color_pattern_selected, 0);
        break;
    case 8://plot_draw_circle(int plotx1, int ploty1, float sizeshape,  float alphashape,   int colorpattern, bool isselected)
        plot_draw_circle(plotx+120,ploty+60, 20, 1.0, color_pattern_selected, 0);
        break;
    case 9://plot_draw_slice(int plotx1, int ploty1, float sizeshape, float opening_angle, float shaperotation, float alphashape,   int colorpattern, bool isselected)
        plot_draw_slice(plotx+120,ploty+60, 40,opening_angle_selected*6.5, angle_shape_selected,1.0, color_pattern_selected,0);
        break;
    case 10://polygon int plotx1, int ploty1, float sizeshape, float shaperotation,int numPoints,  float alphashape,   int colorpattern, bool isselected)
        plot_draw_polygon(plotx+120,ploty+60, 40,angle_shape_selected,nbre_branches_polygon, 1.0, color_pattern_selected,0);
        break;
    case 11://(int plotx,int ploty, float fontsize,int fonttype,  char *text,float alphatext, bool isselected)
        plot_draw_text(plotx+120,ploty+60,(int)general_shape_size_to_apply,fonttype_selected,"TEXT",1.0, 0);
        break;
    default:
        break;
    }

    Rect BSel(Vec2D(plotx+130, ploty+105),Vec2D(65,28));
    BSel.SetRoundness(4);
    BSel.DrawOutline(CouleurPlotLine);
    if(window_focus_id==W_PLOT && mouse_x>plotx+130 && mouse_x<plotx+195 && mouse_y>ploty+105 && mouse_y<ploty+133)
    {
        BSel.DrawOutline(CouleurPlotFill.WithAlpha(0.5));
    }
    petitchiffrenoir.Print("Select ID",plotx+135,ploty+115);
    petitchiffrenoir.Print(ol::ToString(shape_id_to_select),plotx+150,ploty+127);

    return(0);
}
