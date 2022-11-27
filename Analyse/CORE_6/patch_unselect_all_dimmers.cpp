int patch_unselect_all_dimmers()
{
    for(int i=0; i<513; i++)
    {
        Dimmers_selected[i]=0;
    }
    return(0);
}
