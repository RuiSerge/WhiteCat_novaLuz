int exclude_reinclude_channels_from_grand_master_action()
{
    for (int i=1; i<513; i++)
    {
        if(Selected_Channel[i]==1)
        {
            Channels_excluded_from_grand_master[i]=toggle(Channels_excluded_from_grand_master[i]);
        }
    }
    return(0);
}
