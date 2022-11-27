int plot_menu_bar(int plotx, int ploty)
{
Rect edit_frame(Vec2D(plotx,ploty),Vec2D(35,20));
edit_frame.SetRoundness(5);
edit_frame.Draw(CouleurBlind.WithAlpha(index_edit_light_plot));
edit_frame.DrawOutline(CouleurPlotLine);
petitchiffrenoir.Print("Edit",plotx+5,ploty+12);

Rect LayerNum(Vec2D(plotx+45,ploty),Vec2D(10,10));
for(int i=0;i<4;i++)
{
LayerNum.MoveTo(Vec2D(plotx+45+(i*15),ploty-5));
LayerNum.DrawOutline(CouleurPlotLine);
if(show_calc_number[i]==1)
{LayerNum.Draw(CouleurFader);}

if( window_focus_id==W_PLOT && mouse_x>plotx+45+(i*15) && mouse_x<plotx+55+(i*15) && mouse_y>ploty-5 && mouse_y<ploty+5 &&
 Midi_Faders_Affectation_Type!=0)
{
LayerNum.DrawOutline(CouleurBlind);
char tmmppp[24];
sprintf(tmmppp,"Plot Layer %d", i+1);
show_type_midi(1605+i,  tmmppp);
}
LayerNum.MoveTo(Vec2D(plotx+45+(i*15),ploty+10));
if(view_plot_calc_number_is==i)
{LayerNum.Draw(CouleurPlotLine);}
LayerNum.DrawOutline(CouleurLigne.WithAlpha(0.3));

}

LayerNum.MoveTo(Vec2D(plotx+110,ploty+2));
LayerNum.Draw(CouleurBlind.WithAlpha(plot_layer_mode));
LayerNum.DrawOutline(CouleurPlotLine);

if( window_focus_id==W_PLOT && mouse_x>plotx+110 && mouse_x<plotx+120 && mouse_y>ploty+2 && mouse_y<ploty+12 &&
Midi_Faders_Affectation_Type!=0)
{
 LayerNum.DrawOutline(CouleurBlind);
 show_type_midi(1609, "Plot Layer mode");
}


Rect MenuBarIs(Vec2D(plotx+130,ploty-5),Vec2D(100,25));
MenuBarIs.SetRoundness(7.5);

MenuBarIs.Draw(CouleurNoir);
MenuBarIs.Draw(CouleurBleuProcedure.WithAlpha(0.5));

switch(index_menus_lighting_plot)
{
case 0:
     petitchiffre.Print("BACKGROUND",plotx+140,ploty+10);
break;
case 1:
     petitchiffre.Print("SHAPES",plotx+157,ploty+10);
break;
case 2:
     petitchiffre.Print("SYMBOLS",plotx+150,ploty+10);
break;
case 3:
     petitchiffre.Print("LEGEND",plotx+160,ploty+10);
break;
case 4:
     petitchiffre.Print("THE PLOT",plotx+155,ploty+10);
break;
default:
break;
}


Rect OverViewPort(Vec2D(plotx+240,ploty-5),Vec2D(120,25));
OverViewPort.SetRoundness(7.5);
OverViewPort.Draw(CouleurFader.WithAlpha(index_move_plot_view_port));
OverViewPort.DrawOutline(CouleurPlotLine.WithAlpha(0.5));


char temp_h[16];
petitchiffrenoir.Print("ViewPort:", plotx+250,ploty+5);
sprintf(temp_h,"X:%d",plot_view_port_x);
petitchiffrenoir.Print(temp_h, plotx+250,ploty+15);
sprintf(temp_h,"Y:%d",plot_view_port_y);
petitchiffrenoir.Print(temp_h, plotx+300,ploty+15);



command_button_view(plotx+380,ploty-5,plot_index_show_levels,"SeeLevels","",1595);// int x, inty ,bool state, char *textedesc, int midiaffectation

command_button_view(plotx+460,ploty-5,plot_index_show_levels_from_faders,"SeeFaders","",1596);// int x, inty ,bool state, char *textedesc, int midiaffectation


command_button_view(plotx+540,ploty-5,index_blind,"Blind","",754);// int x, inty ,bool state, char *textedesc, int midiaffectation


if(index_menus_lighting_plot!=4)
{
Canvas::SetClipping(plotx,ploty-10,plot_window_x_size-position_plan_x,ploty+50);
Rect Export(Vec2D(plotx+620,ploty-5),Vec2D(100,20));
Export.SetRoundness(5);
if(index_show_button_export>0.0){index_show_button_export-=0.1; if(index_show_button_export<0.0){index_show_button_export=0.0;}}

Export.Draw(CouleurFader.WithAlpha(index_show_button_export));

Export.DrawOutline(CouleurPlotLine);
petitchiffrenoir.Print("Export View As",plotx+625,ploty+8);

Rect NameExport(Vec2D(plotx+730,ploty-5),Vec2D(220,20));
NameExport.SetRoundness(5);
NameExport.Draw(CouleurBleuProcedure.WithAlpha(0.2));
if(window_focus_id==W_PLOT && mouse_x>plotx+730 && mouse_x<plotx+950 && mouse_x<plotx+plot_window_x_size-position_plan_x && mouse_y>ploty-5 && mouse_y<ploty+15)
{
 NameExport.DrawOutline(CouleurLigne.WithAlpha(0.5));
}
petitchiffrenoir.Print( plot_name_of_capture, plotx+730+5,ploty+8);
Canvas::DisableClipping();
}


return(0);
}
