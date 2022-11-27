int clear_completely_the_patch()
{
    for(int i=0; i<514; i++)
    {
        Patch[i]=0;
        curves[i]=0;
        dimmer_type[i]=0;
    }
    //modif 18/12/14 merci rui serge
    for(int pl=0; pl<128; pl++)
    {
        snapshot_symbol_dimmer_is[pl]=0;
        for(int c=0; c<4; c++)
        {
            symbol_dimmer_is[c][pl]=0;
        }
    }
    return(0);
}
