int  patch_clear_selected()
{
    for(int i=0; i<513; i++)
    {
        if(Dimmers_selected[i]==1)
        {
            Patch[i]=0;
            curves[i]=0;
            if(index_build_patch_from_plot==1)
            {
                for(int c=0; c<4; c++)
                {
                    for(int s=1; s<=nbre_symbols_on_plot[c]; s++)
                    {
                        if(symbol_dimmer_is[c][s]==i)
                        {
                            symbol_dimmer_is[c][s]=0;
                        }
                    }
                }
            }
        }
    }

    return(0);
}
