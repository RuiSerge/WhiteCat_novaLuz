int plot_symbol_list(int plotx,int ploty)
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
    petitchiffrenoir.Print(symbol_nickname[symbol_selected_type],plotx+12,ploty+18);
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

    if(window_focus_id==W_PLOT && mouse_x>plotx+12 && mouse_x<plotx+28 && mouse_y>ploty+69 && mouse_y<ploty+83
            &&  Midi_Faders_Affectation_Type!=0)
    {
        Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+28,ploty+69)).Draw(CouleurBlind);
        Line(Vec2D(plotx+12,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurBlind);
        Line(Vec2D(plotx+28,ploty+69),Vec2D(plotx+20,ploty+83)).Draw(CouleurBlind);
        show_type_midi(1597,"Plot List Up");
    }
    Rect SliderSel(Vec2D(plotx+3,ploty+30),Vec2D(5,64));
    Rect SliderVel(Vec2D(plotx+3,ploty+30+(64-(symbol_selected_type/2))),Vec2D(5,(symbol_selected_type/2)));
    SliderSel.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
    SliderVel.Draw(CouleurFader);
    if(window_focus_id==W_PLOT && mouse_x>plotx+3 && mouse_x<plotx+8 && mouse_y>ploty+30 && mouse_y<ploty+94
            &&  Midi_Faders_Affectation_Type!=0)
    {
        SliderSel.DrawOutline(CouleurBlind);
        show_type_midi(1598,"Plot List CC");
    }

    petitchiffrenoir.Print(ol::ToString(symbol_selected_type),plotx+13,ploty+62);

    plot_print_neutral_symbol(symbol_selected_type, plotx+165, ploty+75 );


    petitchiffrenoir.Print("Global size",plotx+45,ploty+37);
    petitchiffrenoir.Print(ol::ToString(global_symbol_size),plotx+108,ploty+48);
    Rect global_sizer_frame(Vec2D(plotx+50,ploty+40),Vec2D(50,10));
    Rect global_sizer_level(Vec2D(plotx+50,ploty+40),Vec2D(25.0*global_symbol_size,10));
    switch(index_edit_symbol_plot)
    {
    case 0:
        global_sizer_level.Draw(CouleurPlotLine.WithAlpha(0.4));
        break;
    case 1:
        global_sizer_level.Draw(CouleurBlind);
        break;
    default:
        break;
    }
    global_sizer_frame.DrawOutline(CouleurPlotLine);


    petitchiffrenoir.Print("Symbol size",plotx+45,ploty+62);
    petitchiffrenoir.Print(ol::ToString(size_symbol[symbol_selected_type]),plotx+108,ploty+73);
    Rect symbol_sizer_frame(Vec2D(plotx+50,ploty+65),Vec2D(50,10));
    Rect symbol_sizer_level(Vec2D(plotx+50,ploty+65),Vec2D(50.0*size_symbol[symbol_selected_type],10));
    switch(index_edit_symbol_plot)
    {
    case 0:
        symbol_sizer_level.Draw(CouleurPlotLine.WithAlpha(0.4));
        break;
    case 1:
        symbol_sizer_level.Draw(CouleurFader);
        break;
    default:
        break;
    }
    symbol_sizer_frame.DrawOutline(CouleurPlotLine);

    Rect edit_symbol_frame(Vec2D(plotx+40,ploty+80),Vec2D(105,20));
    edit_symbol_frame.SetRoundness(5);
    edit_symbol_frame.Draw(CouleurPlotFill);
    edit_symbol_frame.Draw(CouleurBleuProcedure.WithAlpha(0.3));
    edit_symbol_frame.Draw(CouleurBlind.WithAlpha(index_edit_symbol_plot));
    edit_symbol_frame.DrawOutline(CouleurPlotLine);
    petitchiffrenoir.Print("Edit the Symbol",plotx+45,ploty+92);

    Rect add_symbol_frame(Vec2D(plotx+40,ploty+110),Vec2D(80,20));
    add_symbol_frame.SetRoundness(5);
    add_symbol_frame.Draw(CouleurPlotFill);
    add_symbol_frame.Draw(CouleurBleuProcedure.WithAlpha(0.3));
    add_symbol_frame.DrawOutline(CouleurPlotLine);
    petitchiffrenoir.Print("Add To Plot",plotx+45,ploty+122);
    petitchiffrenoir.Print(ol::ToString(nbre_symbols_on_plot[view_plot_calc_number_is]),plotx+15,ploty+122);

    if(window_focus_id==W_PLOT && mouse_x>plotx+40 && mouse_x<plotx+40+80 && mouse_y>ploty+110 && mouse_y<ploty+110+20
            && Midi_Faders_Affectation_Type!=0)
    {
        add_symbol_frame.DrawOutline(CouleurBlind);
        show_type_midi(1600,"Plot Add Symbol");
    }




    Rect BSel(Vec2D(plotx+130, ploty+105),Vec2D(65,28));
    BSel.SetRoundness(4);
    BSel.Draw(CouleurPlotFill);
    BSel.Draw(CouleurBleuProcedure.WithAlpha(0.3));
    BSel.DrawOutline(CouleurPlotLine);
    if(window_focus_id==W_PLOT && mouse_x>plotx+130 && mouse_x<plotx+130+65 && mouse_y>ploty+105 && mouse_y<ploty+105+28)
    {
        BSel.DrawOutline(CouleurPlotFill.WithAlpha(0.5));
    }
    petitchiffrenoir.Print("Select ID",plotx+135,ploty+115);
    petitchiffrenoir.Print(ol::ToString(symbol_id_to_select),plotx+150,ploty+127);




    return(0);
}
