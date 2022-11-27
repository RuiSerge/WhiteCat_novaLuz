int reset_symbols_selected(int calc)
{
    for (int i=0; i<nbre_symbol_per_layer; i++)
    {
        symbol_is_selected[calc][i]=0;
    }
    return(0);
}
