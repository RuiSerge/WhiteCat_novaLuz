int do_logical_Plot_window(int plotx, int ploty)
{
if(window_focus_id==W_PLOT && mouse_x> plotx && mouse_x<plotx+plot_window_x_size && mouse_y>ploty && mouse_y<ploty + plot_window_y_size)
{
logical_plot_menu_bare(plotx+230,ploty+10);

switch(index_menus_lighting_plot)
{
case 0://plan
logical_menu_plan(plotx+10, ploty+50);
break;
case 1://shapes
logical_plot_shape_list(plotx+10, ploty+50);
logical_shape_edition(plotx+10, ploty+200);
break;
case 2://symbols
logical_plot_symbol_list(plotx+10, ploty+50);
logical_plot_symbol_edition(plotx+10, ploty+200);//editeur de symbol
logical_symbol_edition_options(plotx+10, ploty+275);
break;
case 3://légende
break;
case 4://plan seul
break;
default:
break;
}

if(index_click_inside_relativ_xy==1 && mouse_button==1 && mouse_released==0)
{
switch(index_menus_lighting_plot)
{
case 1://shapes
rlativ_xm=mouse_x-(plotx+110+35);
rlativ_ym=mouse_y-(ploty+485+35);
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1 )
{
 shape_relativ_position_legend_name[i][0]=temp_shape_relativ_position_legend_name[i][0]+ rlativ_xm;
 shape_relativ_position_legend_name[i][1]=temp_shape_relativ_position_legend_name[i][1]+ rlativ_ym;
}
}
break;
case 2://symbols
rlativ_xm=mouse_x-(plotx+110+35);
rlativ_ym=mouse_y-(ploty+585+35);
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1 )
{
for(int t=0;t<5;t++)
{
if(adjust_xy_type[t]==1)
{
 relatif_plot_xy[view_plot_calc_number_is][i][t][0]=temp_relatif_plot_xy_array[i][t][0]+ rlativ_xm;
 relatif_plot_xy[view_plot_calc_number_is][i][t][1]=temp_relatif_plot_xy_array[i][t][1]+ rlativ_ym;
}
}
}
}
break;
default:
break;
}
}

if(mouse_x> plotx+position_plan_x && mouse_x<plotx+position_plan_x+plot_window_x_size
&& mouse_y> ploty+position_plan_y && mouse_y<ploty+position_plan_y+plot_window_y_size )
{
if(index_click_inside_plot==0 && index_click_inside_relativ_xy==0 && mouse_button==1 && mouse_released==0 )
{
index_click_inside_plot=1;
plot_original_mouse_x=mouse_x;
plot_original_mouse_y=mouse_y;
switch(index_menus_lighting_plot)
{
case 0://bckgd
break;
case 1://shapes
check_select_deselect_shape(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y);
store_plot_position_of_shapes();
break;
case 2://symbols
check_select_deselect_symbol(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y);
store_plot_position_of_activ_calc(view_plot_calc_number_is);
break;
case 3://legend
break;
case 4://PLOT
check_select_deselect_symbol(plotx+position_plan_x+plot_view_port_x,ploty+position_plan_y+plot_view_port_y);
break;
default:
break;
}
previous_plot_view_port_x=plot_view_port_x;
previous_plot_view_port_y=plot_view_port_y;
}
else if (index_click_inside_plot==1 &&  index_click_inside_relativ_xy==0 && mouse_button==1 && mouse_released==0  )
{
plot_facteur_move_x=mouse_x-plot_original_mouse_x;
plot_facteur_move_y=mouse_y-plot_original_mouse_y;



if(index_move_plot_view_port==0 &&  index_edit_light_plot==1)
{
switch(index_menus_lighting_plot)
{
case 1://shapes
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1 )
{
if(handle_selected_for_line_editing==0)
{
shape_position[i][0]=stored_plot_shape_position[i][0]+ plot_facteur_move_x ;
shape_position[i][1]=stored_plot_shape_position[i][1]+ plot_facteur_move_y ;
if(shape_type[i]<7)//lignes
{
shape_position[i][2]=stored_plot_shape_position[i][2]+ plot_facteur_move_x ;
shape_position[i][3]=stored_plot_shape_position[i][3]+ plot_facteur_move_y ;
}
}
else if(handle_selected_for_line_editing==1 && shape_selected[editing_shape_line_number]==1)
{
shape_position[editing_shape_line_number][2]=stored_plot_shape_position[editing_shape_line_number][2]+ plot_facteur_move_x;
shape_position[editing_shape_line_number][3]=stored_plot_shape_position[editing_shape_line_number][3]+ plot_facteur_move_y ;
}
}
}
break;
case 2://symbols
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1 )
{
pos_symbol[view_plot_calc_number_is][i][0]=stored_plot_position[i][0]+ plot_facteur_move_x ;
pos_symbol[view_plot_calc_number_is][i][1]=stored_plot_position[i][1]+ plot_facteur_move_y ;
}
}
break;
case 3://legend

break;
default:
break;
}
}
else if(index_move_plot_view_port==1)
{
plot_view_port_x=previous_plot_view_port_x+plot_facteur_move_x;
plot_view_port_y=previous_plot_view_port_y+plot_facteur_move_y;
}
}
}


}
return(0);
}
