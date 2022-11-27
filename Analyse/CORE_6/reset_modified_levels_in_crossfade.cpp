int reset_modified_levels_in_crossfade()
{
    for(int i=0; i<513; i++)
    {
        channel_level_mofification_while_crossfade[i]=0;
    }
    return(0);
}
