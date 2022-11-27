int shape_edition(int plotx, int ploty)
{
    Rect PlotShEd(Vec2D(plotx,ploty),Vec2D(200,400));
    PlotShEd.SetRoundness(15);
    PlotShEd.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    PlotShEd.DrawOutline(CouleurPlotLine.WithAlpha(0.4));
    petitchiffrenoir.Print("SELECTED SHAPES:",plotx+10,ploty+15);
    Line(Vec2D(plotx+10,ploty+20),Vec2D(plotx+130,ploty+20)).Draw(CouleurPlotLine);

    petitchiffrenoir.Print("Rotate",plotx+10,ploty+33);
    petitchiffrenoir.Print(ol::ToString(angle_shape_selected),plotx+80,ploty+33);
    Rect RotateFrame(Vec2D(plotx+10,ploty+40),Vec2D(100,10));
    Rect RotateLevel(Vec2D(plotx+10,ploty+40),Vec2D((angle_shape_selected*100),10));
    RotateLevel.Draw(CouleurGreen);
    RotateFrame.DrawOutline(CouleurPlotLine);

    if(window_focus_id==W_PLOT && mouse_x>plotx+10 && mouse_x<plotx+110 && mouse_y>ploty+40 && mouse_y<ploty+50
            && Midi_Faders_Affectation_Type!=0)
    {
        RotateFrame.DrawOutline(CouleurBlind);
        show_type_midi(1601,"Plot Rotate");
    }

    Rect OverRot(Vec2D(plotx+76,ploty+22),Vec2D(60,15));
    OverRot.SetRoundness(4);
    OverRot.DrawOutline(CouleurPlotLine.WithAlpha(0.5));


    Rect AnglePos(Vec2D(-10,-10),Vec2D(10,10));

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            AnglePos.MoveTo(Vec2D(plotx+140+(c*15),ploty+10+(l*15)));
            AnglePos.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
            if(window_focus_id==W_PLOT && mouse_x>plotx+140+(c*15) && mouse_x<plotx+150+(c*15) && mouse_y>ploty+10+(l*15) && mouse_y<ploty+20+(l*15) )
            {
                AnglePos.Draw(CouleurFader);
            }
        }
    }
    AnglePos.MoveTo(Vec2D(plotx+155,ploty+25));
    AnglePos.Draw(CouleurPlotFill);
    AnglePos.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    AnglePos.DrawOutline(CouleurPlotFill);
    AnglePos.DrawOutline(CouleurBleuProcedure.WithAlpha(0.4));


    Rect MySymbAction(Vec2D(plotx, ploty+60),Vec2D(60,18));
    MySymbAction.SetRoundness(5);

    for(int c=0; c<3; c++)
    {

        for(int l=0; l<2; l++)
        {
            MySymbAction.MoveTo(Vec2D(plotx+5+(c*65),ploty+60+(l*20)));
            MySymbAction.Draw(CouleurPlotLine.WithAlpha(0.5));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && index_click_inside_relativ_xy==0
                    && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60+(l*20) && mouse_y<ploty+78+(l*20))
            {
                MySymbAction.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            switch(c+(l*3))
            {
            case 0:
                if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60+(l*20) && mouse_y<ploty+78+(l*20)
                        && Midi_Faders_Affectation_Type!=0)
                {
                    MySymbAction.DrawOutline(CouleurBlind);
                    show_type_midi(1602,"Plot Dub");
                }
                petitchiffre.Print("Dub",plotx+20+(c*65),ploty+72+(l*20));
                break;
            case 1:
                if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60+(l*20) && mouse_y<ploty+78+(l*20)
                        && Midi_Faders_Affectation_Type!=0)
                {
                    MySymbAction.DrawOutline(CouleurBlind);
                    show_type_midi(1603,"Plot Delete");
                }
                petitchiffre.Print("Delete",plotx+10+(c*65),ploty+72+(l*20));
                break;
            case 2:
                if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60+(l*20) && mouse_y<ploty+(l*20)+78
                        && Midi_Faders_Affectation_Type!=0)
                {
                    MySymbAction.DrawOutline(CouleurBlind);
                    show_type_midi(1604,"Plot Unselect");
                }
                petitchiffre.Print("UnSelect",plotx+7+(c*65),ploty+72+(l*20));
                break;
            case 3:
                petitchiffre.Print("Down",plotx+15+(c*65),ploty+72+(l*20));
                break;
            case 4:
                petitchiffre.Print("Top",plotx+22+(c*65),ploty+72+(l*20));
                break;
            case 5:
                petitchiffre.Print("Grp/unGr.",plotx+7+(c*65),ploty+72+(l*20));
                break;
            default:
                break;
            }
        }
    }

    Rect MySymbAlign(Vec2D(plotx+5,ploty+80),Vec2D(40,18));
    MySymbAlign.SetRoundness(5);
    for(int c=0; c<4; c++)
    {
        MySymbAlign.MoveTo(Vec2D(plotx+10+(c*45),ploty+110));
        MySymbAlign.Draw(CouleurBleuProcedure.WithAlpha(0.5));
        switch(c)
        {
        case 0:
            petitchiffre.Print("AlignX",plotx+10+(c*45),ploty+122);
            break;
        case 1:
            petitchiffre.Print("AlignY",plotx+10+(c*45),ploty+122);
            break;
        case 2:
            petitchiffre.Print("<-X->",plotx+15+(c*45),ploty+122);
            break;
        case 3:
            petitchiffre.Print("<-Y->",plotx+15+(c*45),ploty+122);
            break;
        default:
            break;
        }
    }

    petitchiffrenoir.Print("Shape General Size",plotx+10,ploty+147);
    petitchiffrenoir.Print(ol::ToString( general_shape_size_to_apply ),plotx+130,ploty+147);
    Rect symbol_sizer_frame(Vec2D(plotx+10,ploty+155),Vec2D(100,10));
    Rect symbol_sizer_level(Vec2D(plotx+10,ploty+155),Vec2D(general_shape_size_to_apply,10));

    Rect OverSize(Vec2D(plotx+126,ploty+136),Vec2D(70,15));
    OverSize.SetRoundness(4);
    OverSize.DrawOutline(CouleurPlotLine.WithAlpha(0.5));

    Rect OpeningFrame(Vec2D(plotx+10,ploty+240),Vec2D(180,10));
    Rect OpeningLevel(Vec2D(plotx+10,ploty+240),Vec2D(( opening_angle_selected*180),10));


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

    Rect MySHBox(Vec2D(0,0),Vec2D(45,20));
    MySHBox.SetRoundness(5);
    if(shape_selected_type>=0 && shape_selected_type<7)
    {
        petitchiffrenoir.Print("Color Pattern",plotx+10,ploty+185);
        petitchiffrenoir.Print(ol::ToString(color_pattern_selected),plotx+100,ploty+185);
        MySHBox.MoveTo(Vec2D(plotx+10,ploty+190));
        switch(color_pattern_selected)
        {
        case 0:
            MySHBox.Draw(CouleurPlotLine);
            break;
        case 1://yellow
            MySHBox.Draw(CouleurYellowFgroup);
            break;
        case 2://red
            MySHBox.Draw(CouleurRed);
            break;
        case 3: //green
            MySHBox.Draw(CouleurGreen);
            break;
        case 4: //blue
            MySHBox.Draw(CouleurBleuProcedure);
            break;
        default:
            break;
        }
    }
    else
    {
        switch(shape_selected_type)
        {
        case 7://Rectangle
            petitchiffrenoir.Print("Color Pattern",plotx+10,ploty+185);
            petitchiffrenoir.Print(ol::ToString(color_pattern_selected),plotx+100,ploty+185);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+190));
            switch(color_pattern_selected)
            {
            case 0://Outlined + Fill
                MySHBox.Draw(CouleurPlotFill);
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 1://Outlined only
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 2: //filled Outline color
                MySHBox.Draw(CouleurPlotLine);
                break;
            case 3: //filled PlotFill color
                MySHBox.Draw(CouleurPlotFill);
                break;
            default:
                break;
            }
            petitchiffrenoir.Print("Size X",plotx+10,ploty+225);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+230));
            MySHBox.Draw(CouleurPlotLine.WithAlpha(0.4));
            MySHBox.Draw(CouleurFader.WithAlpha(index_adjusting_shape_x));
            petitchiffrenoir.Print(ol::ToString(shape_rect_size_x),plotx+15,ploty+242);
            petitchiffrenoir.Print("Size Y",plotx+100,ploty+225);
            MySHBox.MoveTo(Vec2D(plotx+100,ploty+230));
            MySHBox.Draw(CouleurPlotLine.WithAlpha(0.4));
            MySHBox.Draw(CouleurFader.WithAlpha(index_adjusting_shape_y));
            petitchiffrenoir.Print(ol::ToString(shape_rect_size_y),plotx+105,ploty+242);
            break;
        case 8://circle
            petitchiffrenoir.Print("Color Pattern",plotx+10,ploty+185);
            petitchiffrenoir.Print(ol::ToString(color_pattern_selected),plotx+100,ploty+185);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+190));
            switch(color_pattern_selected)
            {
            case 0://Outlined + Fill
                MySHBox.Draw(CouleurPlotFill);
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 1://Outlined only
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 2: //filled Outline color
                MySHBox.Draw(CouleurPlotLine);
                break;
            case 3: //filled PlotFill color
                MySHBox.Draw(CouleurPlotFill);
                break;
            default:
                break;
            }
            break;
        case 9://arc
            petitchiffrenoir.Print("Color Pattern",plotx+10,ploty+185);
            petitchiffrenoir.Print(ol::ToString(color_pattern_selected),plotx+100,ploty+185);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+190));
            switch(color_pattern_selected)
            {
            case 0://Outlined + Fill
                MySHBox.Draw(CouleurPlotFill);
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 1://Outlined only
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 2: //filled Outline color
                MySHBox.Draw(CouleurPlotLine);
                MySHBox.DrawOutline(CouleurPlotFill);
                break;
            case 3: //filled PlotFill color
                MySHBox.Draw(CouleurPlotFill);
                break;
            default:
                break;
            }
            petitchiffrenoir.Print("Opening angle:",plotx+10,ploty+225);
            petitchiffrenoir.Print(ol::ToString( opening_angle_selected),plotx+120,ploty+225);
            OpeningLevel.Draw(CouleurGreen);
            OpeningFrame.DrawOutline(CouleurPlotLine);
            break;
        case 10://polygon
            petitchiffrenoir.Print("Color Pattern",plotx+10,ploty+185);
            petitchiffrenoir.Print(ol::ToString(color_pattern_selected),plotx+100,ploty+185);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+190));
            switch(color_pattern_selected)
            {
            case 0://Outlined + Fill
                MySHBox.Draw(CouleurPlotFill);
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 1://Outlined only
                MySHBox.DrawOutline(CouleurPlotLine);
                break;
            case 2: //filled Outline color
                MySHBox.Draw(CouleurPlotLine);
                MySHBox.DrawOutline(CouleurPlotFill);
                break;
            case 3: //filled PlotFill color
                MySHBox.Draw(CouleurPlotFill);
                break;
            default:
                break;
            }
            petitchiffrenoir.Print("Polygon Number of Points",plotx+10,ploty+225);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+230));
            MySHBox.Draw(CouleurPlotLine.WithAlpha(0.4));
            petitchiffrenoir.Print(ol::ToString(nbre_branches_polygon),plotx+15,ploty+242);
            break;
        case 11:
            petitchiffrenoir.Print("Font Number",plotx+10,ploty+225);
            MySHBox.MoveTo(Vec2D(plotx+10,ploty+230));
            MySHBox.Draw(CouleurPlotLine.WithAlpha(0.4));
            petitchiffrenoir.Print(ol::ToString(fonttype_selected),plotx+15,ploty+242);
            break;
        default:
            break;
        }
    }
    Rect PlotOptionView(Vec2D(plotx+5,ploty+260),Vec2D(10,10));
    PlotOptionView.DrawOutline(CouleurPlotLine);
    PlotOptionView.Draw(CouleurPlotLine.WithAlpha(index_show_shape_id));
    petitchiffrenoir.Print("SHOW SYMBOL ID",plotx+25,ploty+268);
    petitchiffrenoir.Print(ol::ToString(index_last_shape_selected),plotx+135,ploty+268);

    Rect PlotOptionsEdit_Long(Vec2D(plotx+10,ploty+275),Vec2D(175,18));
    PlotOptionsEdit_Long.SetRoundness(3);
    PlotOptionsEdit_Long.Draw(CouleurPlotFill.WithAlpha(0.3));
    PlotOptionsEdit_Long.DrawOutline(CouleurPlotLine);

    if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+10 && mouse_x<plotx+185 && mouse_y>ploty+275 && mouse_y<ploty+293)
    {
        PlotOptionsEdit_Long.DrawOutline(CouleurPlotFill.WithAlpha(0.9));
    }
    petitchiffrenoir.Print(shape_legend_name[index_last_shape_selected],plotx+15,ploty+287);

    char TextPlot[25];
    Rect AeraDrawAdjust(Vec2D(plotx+110,ploty+300),Vec2D(70,70));
    AeraDrawAdjust.DrawOutline(CouleurPlotLine.WithAlpha(0.3));

    if(index_click_inside_relativ_xy==1 )
    {
        AeraDrawAdjust.SetLineWidth(2.0);
        AeraDrawAdjust.DrawOutline(CouleurFader);
        AeraDrawAdjust.Draw(CouleurBlind.WithAlpha(0.3));
        sprintf(TextPlot,"%d . %d",rlativ_xm,rlativ_ym);
        petitchiffrenoir.Print(TextPlot,plotx+130,ploty+340);
    }


    petitchiffrenoir.Print("ALPHA SHAPES",plotx+5,ploty+370);
    petitchiffrenoir.Print(ol::ToString(general_alpha_for_shape),plotx+115,ploty+390);
    Rect ShapeFrame(Vec2D(plotx+5,ploty+380),Vec2D(100,10));
    Rect ShapeLevel(Vec2D(plotx+5,ploty+380),Vec2D((general_alpha_for_shape*100),10));
    ShapeLevel.Draw(CouleurPlotLine);
    ShapeFrame.DrawOutline(CouleurPlotLine);

    return(0);
}
