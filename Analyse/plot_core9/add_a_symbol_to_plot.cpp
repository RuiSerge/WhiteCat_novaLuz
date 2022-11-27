int add_a_symbol_to_plot(int plot_calc_number_is)
{

nbre_symbols_on_plot[plot_calc_number_is]++;
clear_symbol_slot(plot_calc_number_is,nbre_symbols_on_plot[plot_calc_number_is]);
if(nbre_symbols_on_plot[plot_calc_number_is]>126){nbre_symbols_on_plot[plot_calc_number_is]=126;}
pos_symbol[plot_calc_number_is][nbre_symbols_on_plot[plot_calc_number_is]][0]=
((plot_window_x_size-position_plan_x)/2)-plot_view_port_x;
pos_symbol[plot_calc_number_is][nbre_symbols_on_plot[plot_calc_number_is]][1]=
((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
symbol_type[plot_calc_number_is][(nbre_symbols_on_plot[plot_calc_number_is])]=symbol_selected_type;
angle_symbol[plot_calc_number_is][(nbre_symbols_on_plot[plot_calc_number_is])]=angle_projo_selectionne;
reset_symbols_selected(view_plot_calc_number_is);
symbol_is_selected[plot_calc_number_is][(nbre_symbols_on_plot[plot_calc_number_is])]=1;
last_selected_symbol_is=nbre_symbols_on_plot[plot_calc_number_is];
plot_generate_appareils_list();
return(0);
}
