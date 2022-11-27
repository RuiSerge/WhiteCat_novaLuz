int menu_plan(int plotx, int ploty)
{

    Rect PlotSymbList(Vec2D(plotx,ploty),Vec2D(205,220));
    PlotSymbList.SetRoundness(15);
    PlotSymbList.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    PlotSymbList.DrawOutline(CouleurPlotLine.WithAlpha(0.4));


    petitchiffrenoir.Print("BACKGROUND:",plotx+10,ploty+15);
    Line(Vec2D(plotx+10,ploty+20),Vec2D(plotx+130,ploty+20)).Draw(CouleurPlotLine);


    petitchiffrenoir.Print("Theatre Picture",plotx+5,ploty+40);
    petitchiffrenoir.Print("Ratio:",plotx+110,ploty+40);
    petitchiffrenoir.Print(ol::ToString(ratio_lock_plot_scale),plotx+150,ploty+40);

    Rect UnderName(Vec2D(plotx+5,ploty+50),Vec2D(190,20));
    UnderName.SetRoundness(5);
    UnderName.Draw(CouleurFond);
    Canvas::SetClipping( plotx+5,ploty+50,plotx+195,ploty+70);
    petitchiffre.Print(Name_of_plane_is,plotx+10,ploty+63);
    Canvas::DisableClipping();

    char coodr[8];
    Rect GridBGSelector(Vec2D(plotx+40,ploty+145),Vec2D(40,20));
    GridBGSelector.SetRoundness(3.0);
    for(int i=0; i<4; i++)
    {

        GridBGSelector.MoveTo(Vec2D(plotx+5+(50*i),ploty+90));
        GridBGSelector.Draw(CouleurPlotLine.WithAlpha(0.3));

        if(window_focus_id==W_PLOT && mouse_x>plotx+5+(50*i) && mouse_x<plotx+50+(50*i) && mouse_y>ploty+90 && mouse_y<ploty+110)
        {
            GridBGSelector.DrawOutline(CouleurLigne.WithAlpha(0.3));
        }

        if(i+1==editing_plan_data_type)
        {
            GridBGSelector.Draw(CouleurFader);
        }
        switch(i)
        {
        case 0:
            petitchiffrenoir.Print("X",plotx+20+(50*i),ploty+85);
            sprintf(coodr,"%d",position_relative_plan_theatre[0]);
            break;
        case 1:
            petitchiffrenoir.Print("Y",plotx+20+(50*i),ploty+85);
            sprintf(coodr,"%d",position_relative_plan_theatre[1]);
            break;
        case 2:
            petitchiffrenoir.Print("Scale X",plotx+5+(50*i),ploty+85);
            sprintf(coodr,"%d",taille_relative_plan_theatre[0]);
            break;
        case 3:
            petitchiffrenoir.Print("Scale Y",plotx+5+(50*i),ploty+85);
            sprintf(coodr,"%d",taille_relative_plan_theatre[1]);
            break;
        default:
            break;
        }
        petitchiffrenoir.Print(coodr, plotx+15+(50*i), ploty+102);
    }

    Line(Vec2D(plotx+130,ploty+110),Vec2D(plotx+130,ploty+115)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+130,ploty+115),Vec2D(plotx+146,ploty+115)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+154,ploty+115),Vec2D(plotx+171,ploty+115)).Draw(CouleurPlotLine);
    Line(Vec2D(plotx+171,ploty+115),Vec2D(plotx+171,ploty+110)).Draw(CouleurPlotLine);
    Rect LockProp(Vec2D(plotx+146,ploty+111),Vec2D(8,8));
    LockProp.Draw(CouleurBlind.WithAlpha(lock_background_proportions));
    LockProp.DrawOutline(CouleurPlotLine);

    petitchiffrenoir.Print("Rotate",plotx+5,ploty+133);
    petitchiffrenoir.Print(ol::ToString(orientation_plan_theatre),plotx+95,ploty+133);
    Rect AlphaFrame(Vec2D(plotx+5,ploty+140),Vec2D(100,10));
    Rect AlphaLevel(Vec2D(plotx+5,ploty+140),Vec2D((orientation_plan_theatre*100),10));
    AlphaLevel.Draw(CouleurGreen);
    AlphaFrame.DrawOutline(CouleurPlotLine);


    Rect AnglePos(Vec2D(-10,-10),Vec2D(10,10));

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            AnglePos.MoveTo(Vec2D(plotx+140+(c*15),ploty+125+(l*15)));
            AnglePos.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
            if(window_focus_id==W_PLOT &&  mouse_x>plotx+140+(c*15) && mouse_x<plotx+150+(c*15) && mouse_y>ploty+125+(l*15) && mouse_y<ploty+135+(l*15) )
            {
                AnglePos.Draw(CouleurFader);
            }
        }
    }
    AnglePos.MoveTo(Vec2D(plotx+155,ploty+140));
    AnglePos.Draw(CouleurPlotFill);
    AnglePos.DrawOutline(CouleurPlotFill);
    AnglePos.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    AnglePos.DrawOutline(CouleurBleuProcedure.WithAlpha(0.4));
    petitchiffrenoir.Print("Alpha Picture",plotx+5,ploty+170);
    petitchiffrenoir.Print(ol::ToString(alpha_plan),plotx+95,ploty+170);
    Rect RotateFrame(Vec2D(plotx+5,ploty+180),Vec2D(100,10));
    Rect RotateLevel(Vec2D(plotx+5,ploty+180),Vec2D((alpha_plan*100),10));
    RotateLevel.Draw(CouleurPlotLine);
    RotateFrame.DrawOutline(CouleurPlotLine);



    petitchiffrenoir.Print("Grid:",plotx+5,ploty+210);
    GridBGSelector.MoveTo(Vec2D(plotx+40,ploty+195));

    GridBGSelector.Draw(CouleurPlotLine.WithAlpha(0.3));
    petitchiffrenoir.Print(ol::ToString(plot_quadrillage_size),plotx+50,ploty+210);

    GridBGSelector.MoveTo(Vec2D(plotx+100,ploty+195));
    GridBGSelector.Draw(CouleurPlotLine.WithAlpha(0.3));
    switch(plot_grid_type)
    {
    case 0:
        petitchiffrenoir.Print("Dots",plotx+105,ploty+210);
        break;
    case 1:
        petitchiffrenoir.Print("Line",plotx+105,ploty+210);
        break;
    default:
        break;
    }

    petitchiffrenoir.Print("Alpha Grid",plotx+145,ploty+195);

    Rect AlphaG(Vec2D(plotx+150,ploty+200),Vec2D(50,10));
    AlphaG.DrawOutline(CouleurPlotLine);
    Rect AlphaLev(Vec2D(plotx+150,ploty+200),Vec2D(50*alpha_grille,10));
    AlphaLev.Draw(CouleurFader);
    deroule_repertoire_plans(plotx-5,ploty+80,"Plans");



    Rect PlotSize(Vec2D(plotx,ploty+450),Vec2D(205,65));
    PlotSize.SetRoundness(7.5);
    PlotSize.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    PlotSize.DrawOutline(CouleurPlotLine.WithAlpha(0.4));

    petitchiffrenoir.Print("Plot Window:",plotx+10,ploty+465);

    GridBGSelector.MoveTo(Vec2D(plotx+5,ploty+480));
    GridBGSelector.Draw(CouleurPlotLine.WithAlpha(0.3));
    petitchiffrenoir.Print("Size X",plotx+7,ploty+478);
    if(window_focus_id==W_PLOT && mouse_x>plotx+5 && mouse_x<plotx+45 && mouse_y>ploty+480 && mouse_y<ploty+500)
    {
        GridBGSelector.DrawOutline(CouleurLigne.WithAlpha(0.5));
    }
    if(editing_plot_sizex==1)
    {
        GridBGSelector.Draw(CouleurFader);
    }
    petitchiffrenoir.Print(ol::ToString(plot_window_x_size),plotx+10,ploty+493);


    GridBGSelector.MoveTo(Vec2D(plotx+55,ploty+480));
    GridBGSelector.Draw(CouleurPlotLine.WithAlpha(0.3));
    petitchiffrenoir.Print("Size Y",plotx+7+50,ploty+478);
    if(window_focus_id==W_PLOT && mouse_x>plotx+55 && mouse_x<plotx+95 && mouse_y>ploty+480 && mouse_y<ploty+500)
    {
        GridBGSelector.DrawOutline(CouleurLigne.WithAlpha(0.5));
    }
    if(editing_plot_sizey==1)
    {
        GridBGSelector.Draw(CouleurFader);
    }
    petitchiffrenoir.Print(ol::ToString(plot_window_y_size),plotx+60,ploty+493);


    GridBGSelector.MoveTo(Vec2D(plotx+105,ploty+480));
    GridBGSelector.Draw(CouleurPlotFill);
    GridBGSelector.DrawOutline(CouleurLigne);
    if(plot_editing_color_background==1)
    {
        GridBGSelector.Draw(CouleurFader);
    }
    petitchiffrenoir.Print("BkgCol",plotx+107,ploty+478);


    GridBGSelector.MoveTo(Vec2D(plotx+155,ploty+480));
    GridBGSelector.Draw(CouleurPlotLine);
    GridBGSelector.DrawOutline(CouleurLigne);
    if(plot_editing_color_line==1)
    {
        GridBGSelector.Draw(CouleurFader);
    }
    petitchiffrenoir.Print("LineCol",plotx+157,ploty+478);

    return(0);
}
