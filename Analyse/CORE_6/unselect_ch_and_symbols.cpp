int unselect_ch_and_symbols()
{
    for (int ci=1; ci<514; ci++)
    {
        Selected_Channel[ci]=0;
        for(int calc=0; calc<4; calc++)
        {
            for (int i=0; i<nbre_symbol_per_layer; i++)
            {
                symbol_is_selected[calc][i]=0;
            }
        }
    }
    last_ch_selected=0;
    index_type=0;
    index_level_attribue=0;



    return(0);
}
