int plot_legend_menu(int xplot, int yplot)
{
Rect Undernamelist(Vec2D(xplot+10,yplot),Vec2D(185,10+(25*18)));
Undernamelist.SetRoundness(5);
Undernamelist.Draw(CouleurPlotLine.WithAlpha(0.05));
Rect UnderName(Vec2D(xplot+10,yplot+5),Vec2D(185,20));
UnderName.SetRoundness(5);
for(int i=0;i<18;i++)
{
UnderName.MoveTo(Vec2D(xplot+10,yplot+(i*25)));
petitchiffrenoir.Print(plot_renseignements[i],xplot+15,yplot+15+(i*25));
if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>xplot+10 && mouse_x<xplot+195 && mouse_y>yplot+5+(i*25) && mouse_y<yplot+25+(i*25))
{
UnderName.DrawOutline(CouleurPlotLine.WithAlpha(0.6));
if(mouse_b&1 && mouse_released==0)
{
sprintf(plot_renseignements[i],numeric);
reset_numeric_entry();numeric_postext=0;
if(index_text_auto_close==1){index_type=0;}
mouse_released=1;
}
}
}

UnderName.MoveTo(Vec2D(xplot+10,yplot+470));
UnderName.Draw(CouleurPlotLine.WithAlpha(0.05));
Line(Vec2D(xplot+10, yplot+505), Vec2D(xplot+10 + plot_quadrillage_size, yplot+505)).Draw(CouleurPlotLine);
Line(Vec2D(xplot+10, yplot+495), Vec2D(xplot+10 , yplot+515)).Draw(CouleurPlotLine);
Line(Vec2D(xplot+10+ plot_quadrillage_size, yplot+495), Vec2D(xplot+10+ plot_quadrillage_size , yplot+515)).Draw(CouleurPlotLine);
petitchiffrenoir.Print(plot_renseignements[19],xplot+15,yplot+483);
if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_x>xplot+10 && mouse_x<xplot+195 && mouse_y>yplot+470 && mouse_y<yplot+490)
{
UnderName.DrawOutline(CouleurPlotLine.WithAlpha(0.6));
if(mouse_b&1 && mouse_released==0)
{
sprintf(plot_renseignements[19],numeric);
reset_numeric_entry();numeric_postext=0;
if(index_text_auto_close==1){index_type=0;}
mouse_released=1;
}
}

petitchiffrenoir.Print(plot_renseignements[20],xplot+15,yplot+540);
petitchiffrenoir.Print(plot_renseignements[21],xplot+15,yplot+560);


Rect Mode(Vec2D(xplot+10,yplot+580),Vec2D(95,20));
Mode.SetRoundness(5);


switch(legend_view)
{
case 0://liste
Mode.Draw(CouleurPlotLine.WithAlpha(0.3));
petitchiffrenoir.Print(" LIST MODE",xplot+15,yplot+592);
break;
case 1://appareils
Mode.Draw(CouleurFader);
petitchiffrenoir.Print("LEGEND MODE",xplot+15,yplot+592);
break;
default: break;
}

if(window_focus_id==W_PLOT && mouse_x>xplot+10 && mouse_x<xplot+105 && mouse_y>yplot+580 && mouse_y<yplot+600)
{
Mode.DrawOutline(CouleurLigne.WithAlpha(0.6));
if(mouse_button==1 && mouse_released==0)
{
legend_view=toggle(legend_view);
mouse_released=1;
}
}

return(0);
}
