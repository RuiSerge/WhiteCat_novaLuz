int repatch_from_plot(int calc)
{
    for(int i=1; i<=nbre_symbols_on_plot[calc]; i++)
    {
        if(symbol_channel_is[calc][i]>0)
        {
            Patch[(symbol_dimmer_is[calc][i])]=symbol_channel_is[calc][i];
        }
    }
    generate_channel_view_list_from_patched_circuits();
    return(0);
}
