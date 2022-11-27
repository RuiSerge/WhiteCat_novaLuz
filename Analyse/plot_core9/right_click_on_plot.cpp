int right_click_on_plot()
{
if(mouse_R_button==1 && mouse_R_released==0)
{

if(index_click_inside_plot==0 && index_move_plot_view_port==1    )
{
plot_original_mouse_x=mouse_x;
plot_original_mouse_y=mouse_y;
previous_plot_view_port_x=plot_view_port_x;
previous_plot_view_port_y=plot_view_port_y;
index_click_inside_plot=1;
}
else if (index_click_inside_plot==1 && index_move_plot_view_port==1 )
{
plot_facteur_move_x=mouse_x-plot_original_mouse_x;
plot_facteur_move_y=mouse_y-plot_original_mouse_y;
plot_view_port_x=previous_plot_view_port_x+plot_facteur_move_x;
plot_view_port_y=previous_plot_view_port_y+plot_facteur_move_y;
}

}
 return(0);
}
