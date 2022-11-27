int affect_angle_to_symbols(int plot_calc_number_is,float angle_is)
{
    for(int i=1; i<=nbre_symbols_on_plot[view_plot_calc_number_is]; i++)
    {
        if(symbol_is_selected[plot_calc_number_is][i]==1)
        {
            angle_symbol[view_plot_calc_number_is][i]= angle_is;
        }
    }
    return(0);
}
