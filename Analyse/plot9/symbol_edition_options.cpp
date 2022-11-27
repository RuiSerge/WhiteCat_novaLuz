int symbol_edition_options(int plotx, int ploty)
{
    char TextPlot[25];

    Rect PlotOptionsEdit_Little(Vec2D(plotx,ploty),Vec2D(50,18));
    PlotOptionsEdit_Little.SetRoundness(3);
    Rect PlotOptionsEdit_Middle(Vec2D(plotx,ploty),Vec2D(100,18));
    PlotOptionsEdit_Middle.SetRoundness(3);
    Rect PlotOptionsEdit_Long(Vec2D(plotx,ploty),Vec2D(175,18));
    PlotOptionsEdit_Long.SetRoundness(3);
    Rect PlotOptionView(Vec2D(plotx,ploty+70), Vec2D(10,10));

    char gelat_marque[25];

    for (int l=0; l<8; l++)
    {
        PlotOptionView.MoveTo(Vec2D(plotx+5,ploty+70+(20*l)));
        PlotOptionView.DrawOutline(CouleurPlotLine);
        switch(l)
        {
        case 0:
            sprintf(TextPlot,"CHANNEL");
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+100,ploty+65+(20*l)));
            PlotOptionsEdit_Little.Draw(CouleurPlotLine.WithAlpha(0.2));
            petitchiffrenoir.Print(ol::ToString(symbol_channel_is[view_plot_calc_number_is][last_selected_symbol_is]),plotx+105,ploty+78+(20*l));

            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+100 && mouse_x<plotx+150 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l) )
            {
                PlotOptionsEdit_Little.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            break;
        case 1:
            strcpy(TextPlot,"");
            PlotOptionsEdit_Long.MoveTo(Vec2D(plotx+20,ploty+65+(20*l)));
            PlotOptionsEdit_Long.Draw(CouleurPlotLine.WithAlpha(0.2));
            petitchiffrenoir.Print( descriptif_projecteurs[(symbol_channel_is[view_plot_calc_number_is][last_selected_symbol_is])],plotx+25,ploty+78+(20*l));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+20 && mouse_x<plotx+195 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l) )
            {
                PlotOptionsEdit_Long.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            break;
        case 2:
            sprintf(TextPlot,"GEL 1:");
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+70,ploty+65+(20*l)));
            PlotOptionsEdit_Little.Draw(CouleurPlotLine.WithAlpha(0.2));
            petitchiffrenoir.Print(ol::ToString(gelat[view_plot_calc_number_is][last_selected_symbol_is][0]),plotx+75,ploty+78+(20*l));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+70 && mouse_x<plotx+120 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l) )
            {
                PlotOptionsEdit_Little.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+130,ploty+65+(20*l)));
            switch(gelat_family[view_plot_calc_number_is][last_selected_symbol_is][0])
            {
            case 0:
                sprintf(gelat_marque,"Lee");
                PlotOptionsEdit_Little.Draw(CouleurBleuProcedure.WithAlpha(0.5));
                break;
            case 1:
                sprintf(gelat_marque,"Rosco");
                PlotOptionsEdit_Little.Draw(CouleurBlind.WithAlpha(0.5));
                break;
            case 2:
                sprintf(gelat_marque,"GamCol.");
                PlotOptionsEdit_Little.Draw(CouleurGreen.WithAlpha(0.5));
                break;
            case 3:
                sprintf(gelat_marque,"Apollo");
                PlotOptionsEdit_Little.Draw(CouleurSelection.WithAlpha(0.5));
                break;
            default:
                break;
            }
            petitchiffrenoir.Print(gelat_marque,plotx+135,ploty+78+(20*l));
            break;
        case 3:
            sprintf(TextPlot,"GEL 2:");
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+70,ploty+65+(20*l)));
            PlotOptionsEdit_Little.Draw(CouleurPlotLine.WithAlpha(0.2));
            petitchiffrenoir.Print(ol::ToString(gelat[view_plot_calc_number_is][last_selected_symbol_is][1]),plotx+75,ploty+78+(20*l));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+70 && mouse_x<plotx+120 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l) )
            {
                PlotOptionsEdit_Little.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+130,ploty+65+(20*l)));
            switch(gelat_family[view_plot_calc_number_is][last_selected_symbol_is][1])
            {
            case 0:
                sprintf(gelat_marque,"Lee");
                PlotOptionsEdit_Little.Draw(CouleurBleuProcedure.WithAlpha(0.5));
                break;
            case 1:
                sprintf(gelat_marque,"Rosco");
                PlotOptionsEdit_Little.Draw(CouleurBlind.WithAlpha(0.5));
                break;
            case 2:
                sprintf(gelat_marque,"GamCol.");
                PlotOptionsEdit_Little.Draw(CouleurGreen.WithAlpha(0.5));
                break;
            case 3:
                sprintf(gelat_marque,"Apollo");
                PlotOptionsEdit_Little.Draw(CouleurSelection.WithAlpha(0.5));
                break;
            default:
                break;
            }
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+130,ploty+65+(20*l)));
            petitchiffrenoir.Print(gelat_marque,plotx+135,ploty+78+(20*l));
            break;
        case 4:
            sprintf(TextPlot,"GEL 3:");
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+70,ploty+65+(20*l)));
            PlotOptionsEdit_Little.Draw(CouleurPlotLine.WithAlpha(0.2));
            petitchiffrenoir.Print(ol::ToString(gelat[view_plot_calc_number_is][last_selected_symbol_is][2]),plotx+75,ploty+78+(20*l));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+70 && mouse_x<plotx+120 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l) )
            {
                PlotOptionsEdit_Little.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+130,ploty+65+(20*l)));
            switch(gelat_family[view_plot_calc_number_is][last_selected_symbol_is][2])
            {
            case 0:
                sprintf(gelat_marque,"Lee");
                PlotOptionsEdit_Little.Draw(CouleurBleuProcedure.WithAlpha(0.5));
                break;
            case 1:
                sprintf(gelat_marque,"Rosco");
                PlotOptionsEdit_Little.Draw(CouleurBlind.WithAlpha(0.5));
                break;
            case 2:
                sprintf(gelat_marque,"GamCol.");
                PlotOptionsEdit_Little.Draw(CouleurGreen.WithAlpha(0.5));
                break;
            case 3:
                sprintf(gelat_marque,"Apollo");
                PlotOptionsEdit_Little.Draw(CouleurSelection.WithAlpha(0.5));
                break;
            default:
                break;
            }
            petitchiffrenoir.Print(gelat_marque,plotx+135,ploty+78+(20*l));
            break;
        case 5:
            sprintf(TextPlot,"DIMMER:");
            PlotOptionsEdit_Little.MoveTo(Vec2D(plotx+100,ploty+65+(20*l)));
            PlotOptionsEdit_Little.Draw(CouleurPlotLine.WithAlpha(0.2));
            if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>plotx+100 && mouse_x<plotx+150 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+83+(20*l))
            {
                PlotOptionsEdit_Little.DrawOutline(CouleurLigne.WithAlpha(0.5));
            }
            petitchiffrenoir.Print(ol::ToString(symbol_dimmer_is[view_plot_calc_number_is][last_selected_symbol_is]),plotx+105,ploty+78+(20*l));
            break;
        case 6:
            sprintf(TextPlot,"SHOW SYMBOL ID");
            break;
        case 7:
            sprintf(TextPlot,"NOTES");
            break;
        default:
            sprintf(TextPlot,"-");
            break;
        }
        PlotOptionView.Draw(CouleurPlotLine.WithAlpha(plot_show_options[l]));
        petitchiffrenoir.Print(TextPlot,plotx+25,ploty+78+(20*l));
    }


    for(int n=0; n<4; n++)
    {
        Rect Not(Vec2D(plotx+5,ploty+225+(n*20)),Vec2D(195,18));
        Not.SetRoundness(4);
        Not.Draw(CouleurPlotLine.WithAlpha(0.3));
        petitchiffrenoir.Print(symbol_note[view_plot_calc_number_is][last_selected_symbol_is][n],plotx+8,ploty+238+(n*20));
        if(window_focus_id==W_PLOT && mouse_x>plotx+5 && mouse_x<plotx+200 && mouse_y>ploty+225+(n*20) && mouse_y<ploty+243+(n*20))
        {
            Not.DrawOutline(CouleurPlotLine.WithAlpha(0.6));
        }
    }

    Rect SizeNot(Vec2D(plotx+150,ploty+210),Vec2D(30,10));
    SizeNot.Draw(CouleurPlotLine.WithAlpha(plot_name_text_size));
    SizeNot.DrawOutline(CouleurPlotLine);

    petitchiffrenoir.Print("Size",plotx+115,ploty+218);

    index_edit_relativ_xy=0;
    for(int i=0; i<5; i++)
    {
        if(adjust_xy_type[i]==1)
        {
            index_edit_relativ_xy=1;
            break;
        }
    }

    Rect SoloMode(Vec2D(plotx+75,ploty+350),Vec2D(10,10));
    SoloMode.Draw(CouleurBlind.WithAlpha(mode_relatif_xy_solo));
    SoloMode.DrawOutline(CouleurPlotLine.WithAlpha(0.5));

    petitchiffrenoir.Print("Adjust XY",plotx+115,ploty+315);
    for(int i=0; i<5; i++)
    {
        PlotOptionView.MoveTo(Vec2D(plotx+5,ploty+320+(20*i)));
        PlotOptionView.Draw(CouleurPlotLine.WithAlpha(adjust_xy_type[i]));

        PlotOptionView.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
        switch(i)
        {
        case 0:
            sprintf(TextPlot,"Channel");
            break;
        case 1:
            sprintf(TextPlot,"Name");
            break;
        case 2:
            sprintf(TextPlot,"Gels");
            break;
        case 3:
            sprintf(TextPlot,"Dimmer");
            break;
        case 4:
            sprintf(TextPlot,"Notes");
            break;
        default:
            sprintf(TextPlot,"-");
            break;
        }
        if( window_focus_id==W_PLOT && mouse_x>plotx+5 && mouse_x<plotx+15 && mouse_y>ploty+320+(20*i) && mouse_y<ploty+330+(20*i) &&
                Midi_Faders_Affectation_Type!=0)
        {
            PlotOptionView.DrawOutline(CouleurBlind);

            show_type_midi(1610+i, TextPlot);
        }
        petitchiffrenoir.Print(TextPlot,plotx+25,ploty+328+(20*i));
    }

    Rect AeraDrawAdjust(Vec2D(plotx+110,ploty+320),Vec2D(70,70));
    AeraDrawAdjust.DrawOutline(CouleurPlotLine.WithAlpha(0.3));

    if(index_click_inside_relativ_xy==1 )
    {
        AeraDrawAdjust.SetLineWidth(2.0);
        AeraDrawAdjust.DrawOutline(CouleurFader);

    }
    if(index_edit_relativ_xy==1)
    {
        AeraDrawAdjust.Draw(CouleurBlind.WithAlpha(0.3));
        sprintf(TextPlot,"%d . %d",rlativ_xm,rlativ_ym);
        petitchiffrenoir.Print(TextPlot,plotx+130,ploty+360);
    }

    petitchiffrenoir.Print("AdjustXY Presets",plotx+45,ploty+425);
    Rect PresetBox(Vec2D(0,0),Vec2D(10,10));
    for(int pr=0; pr<8; pr++)
    {
        PresetBox.MoveTo(Vec2D(plotx+30+(20*pr),ploty+430));
        PresetBox.Draw(CouleurFader.WithAlpha(plot_light_preset_on_click[pr]));     //visu de la sélection du preset
        if(last_xyrelativ_preset==pr)
        {
            if(plot_light_preset_on_click[pr]>0.0)
            {
                plot_light_preset_on_click[pr]-=0.2;
            }
        }
        PresetBox.DrawOutline(CouleurPlotLine.WithAlpha(0.5));

        if(window_focus_id==W_PLOT &&  mouse_x>plotx+30+(20*pr) && mouse_x<plotx+40+(20*pr) && mouse_y>ploty+430 && mouse_y<ploty+440
                && Midi_Faders_Affectation_Type!=0)
        {
            PresetBox.DrawOutline(CouleurBlind);
            char tmppp[24];
            sprintf(tmppp,"Plot Preset %d",pr+1);
            show_type_midi(1615+pr,tmppp);
        }


    }


    PlotOptionsEdit_Middle.MoveTo(Vec2D(plotx+5,ploty+450));
    PlotOptionsEdit_Middle.Draw(CouleurPlotLine.WithAlpha(0.5));
    PlotOptionsEdit_Middle.Draw(CouleurBlind.WithAlpha(index_build_patch_from_plot));
    petitchiffrenoir.Print("Link To Patch",plotx+15,ploty+463);

    Rect PlotOptionsEdit_LittleM(Vec2D(plotx+110,ploty+450),Vec2D(85,18));
    PlotOptionsEdit_LittleM.SetRoundness(3);
    PlotOptionsEdit_LittleM.Draw(CouleurPlotLine.WithAlpha(0.5));
    petitchiffrenoir.Print("Clear Patch !",plotx+115,ploty+463);

    return(0);
}
