int patch_select_all_dimmers()
{
    for(int i=0; i<513; i++)
    {
        Dimmers_selected[i]=1;
    }
    return(0);
}
