int patch_to_default_selected()
{
    for(int i=0; i<513; i++)
    {
        if(Dimmers_selected[i]==1)
        {
            Patch[i]=i;
            curves[i]=0;
        }
    }
    if(index_build_patch_from_plot==1)
    {
        reconstruct_plot_dimmer_list_from_patch();
    }
    return(0);
}
