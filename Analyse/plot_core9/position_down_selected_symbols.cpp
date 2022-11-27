int position_down_selected_symbols(int calc)
{
    snapshot_calc(calc);
    for(int i=1; i<nbre_symbol_per_layer; i++)
    {
        if(symbol_is_selected[calc][i]==1 && i>1)
        {
            exchange_symbol_position(calc,i, i-1);
            symbol_is_linked_to[calc][i]=0;
        }
    }

    return(0);
}
