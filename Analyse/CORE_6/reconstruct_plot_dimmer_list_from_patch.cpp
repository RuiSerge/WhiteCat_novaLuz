int reconstruct_plot_dimmer_list_from_patch()
{
    for(int c=0; c<4; c++)
    {

        for(int s=1; s<=nbre_symbols_on_plot[c]; s++)
        {
            for(int p=0; p<513; p++)
            {
                if(Patch[p]==symbol_channel_is[c][s])
                {
                    symbol_dimmer_is[c][s]=p;
                }
            }

        }
    }
    return(0);
}
