int affect_preset_xy_to_symbols(int pr)
{
    for(int i=0; i<nbre_symbol_per_layer-1 ; i++)
    {
        if(symbol_is_selected[view_plot_calc_number_is][i]==1)
        {
            for(int j=0; j<5; j++)
            {
                relatif_plot_xy[view_plot_calc_number_is][i][j][0]=plot_relativxy_preset[pr][j][0];
                relatif_plot_xy[view_plot_calc_number_is][i][j][1]=plot_relativxy_preset[pr][j][1];
            }
        }
    }

    return(0);
}
