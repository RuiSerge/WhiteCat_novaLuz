int delete_selected_symbols(int calc)
{


    for(int i=1; i<=nbre_symbols_on_plot[calc]; i++) //garder 0 pour nettoyage des symboles et output gelats ok
    {
        if(symbol_is_selected[calc][i]==1)
        {
            clear_symbol_slot(calc,i);
            if(index_build_patch_from_plot==1)
            {
                Patch[(symbol_dimmer_is[calc][i])]=0;
            }
        }
    }

    reorder_plan(calc);
    recount_symbols_on_calc(calc);
    last_selected_symbol_is=0;

    return(0);
}
