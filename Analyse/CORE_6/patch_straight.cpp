int patch_straight()
{
    for(int i=0; i<513; i++)
    {
        Patch[i]=i;
    }
    if(index_build_patch_from_plot==1)
    {
        reconstruct_plot_dimmer_list_from_patch();
    }
    return(0);
}
