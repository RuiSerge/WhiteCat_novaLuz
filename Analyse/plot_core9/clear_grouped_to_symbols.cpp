int clear_grouped_to_symbols(int calc, int s)
{

    for(int i=0;i<nbre_symbol_per_layer;i++)
    {
    if(symbol_is_linked_to[calc][i]==s)
    {
    symbol_is_linked_to[calc][i]=0;
    }
    }

return(0);
}
