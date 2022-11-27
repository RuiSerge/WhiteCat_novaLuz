int Plot_window(int plotx, int ploty)
{

Rect PlotPanel(Vec2D(plotx,  ploty), Vec2D( plot_window_x_size,plot_window_y_size));
PlotPanel.SetRoundness(15);
PlotPanel.SetLineWidth(triple_epaisseur_ligne_fader);
PlotPanel.Draw(CouleurPlotFill);
Rect PlotBehindMove(Vec2D(plotx+3,ploty+5),Vec2D(220,40));
PlotBehindMove.SetRoundness(15);
PlotBehindMove.Draw(CouleurFond.WithAlpha(0.5));
if(window_focus_id==W_PLOT)
{
PlotPanel.DrawOutline(CouleurFader);
}
else {PlotPanel.DrawOutline(CouleurLigne); }
neuro.Print("LIGHT PLOT",plotx+100,ploty+30);

petitchiffrenoir.SetColor( CouleurPlotLine );
minichiffre.SetColor( CouleurPlotLine );

plot_menu_bar(plotx+230,ploty+10);//menus generaux de plot

Canvas::SetClipping( plotx,ploty,plot_window_x_size,plot_window_y_size);


switch(index_menus_lighting_plot)
{
case 0://plan
menu_plan(plotx+10, ploty+50);
logical_deroule_repertoire_plans(plotx+5,ploty+130); //a garder pour rafraichir le plan correctement
break;
case 1://shapes
plot_shape_list(plotx+10, ploty+50);
shape_edition(plotx+10, ploty+200);//editeur des props du shape
break;
case 2://symbols
plot_symbol_list(plotx+10, ploty+50);//selecteur symbol
plot_symbol_edition(plotx+10, ploty+200);//editeur de symbol
symbol_edition_options(plotx+10,ploty+275);
break;
case 3://légende
plot_legend_menu(plotx+10,ploty+50);
break;
default:
break;
}
Canvas::DisableClipping();

Canvas::SetClipping( plotx+position_plan_x,ploty+position_plan_y,plot_window_x_size-position_plan_x,plot_window_y_size-position_plan_y);

if(index_menus_lighting_plot!=3 )
{
plot_draw_plan_bitmap(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y, alpha_plan);
if(index_menus_lighting_plot!=4 ){plot_draw_plan_grid_for_view_point(plotx+position_plan_x,ploty+position_plan_y,plotx+plot_view_port_x,ploty+plot_view_port_y);}
plot_draw_shapes(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y);
for(int i=0;i<4;i++)
{
if(show_calc_number[i]==1)
{
plot_draw_plan(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y,i);
}
}
for(int j=0;j<4;j++)
{
if(show_calc_number[j]==1)
{
plot_draw_levels(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y,j);
}
}
}
else
{
plot_draw_legend(plotx+position_plan_x+plot_view_port_x-plot_correcteur_portx,ploty+position_plan_y+plot_view_port_y-plot_correcteur_porty);
}

Canvas::DisableClipping();


petitchiffrenoir.SetColor( Rgba::BLACK );
minichiffre.SetColor( Rgba::WHITE );
return(0);
}
