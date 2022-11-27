int store_plot_position_of_activ_calc(int calc)
{
    for(int i=1; i<= nbre_symbols_on_plot[calc]; i++)
    {
        stored_plot_position[i][0]=pos_symbol[calc][i][0];
        stored_plot_position[i][1]=pos_symbol[calc][i][1];
    }
    return(0);
}
