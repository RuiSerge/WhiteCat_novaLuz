int record_preset_xy_from_symbol(int pr)
{
    for(int i=0; i<5; i++)
    {
        plot_relativxy_preset[pr][i][0]=relatif_plot_xy[view_plot_calc_number_is][last_selected_symbol_is][i][0];
        plot_relativxy_preset[pr][i][1]=relatif_plot_xy[view_plot_calc_number_is][last_selected_symbol_is][i][1];
    }
    return(0);
}
