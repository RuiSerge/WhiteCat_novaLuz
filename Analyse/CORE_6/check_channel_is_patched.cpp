bool check_channel_is_patched(int ch)
{
    bool the_ch_is_patched=0;
    for (int cpatch=1; cpatch<513; cpatch++)
    {
        if(Patch[cpatch]==ch)
        {
            the_ch_is_patched=1;
        }
    }
    return(the_ch_is_patched);
}
