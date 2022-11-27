int clear_calc(int calc)
{
    for(int i=0; i<nbre_symbol_per_layer; i++)
    {
        clear_symbol_slot(calc,i);
    }
    recount_symbols_on_calc( calc);
    plot_generate_appareils_list();
    return(0);
}
