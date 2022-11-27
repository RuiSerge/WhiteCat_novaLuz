int change_symbol_type(int calc, int typ)
{
    for (int i=0; i<nbre_symbol_per_layer; i++)
    {
        if(symbol_is_selected[calc][i]==1)
        {
            symbol_type[calc][i]=typ;
        }
    }

    return(0);
}
