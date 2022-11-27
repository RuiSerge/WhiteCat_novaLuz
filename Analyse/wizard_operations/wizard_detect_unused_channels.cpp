int wizard_detect_unused_channels(int wizard_from_mem, int wizard_to_mem)
{
    bool used_channel[514];
    for(int look=wizard_from_mem; look<=wizard_to_mem; look++)
    {
        if(MemoiresExistantes[look]==1)
        {
            for (int l=1; l<514; l++)
            {
                if(Memoires[look][l]>0)
                {
                    used_channel[l]=1;
                }
            }
        }
    }
    for(int l=1; l<514; l++)
    {
        Selected_Channel[l]=1-used_channel[l];
    }

    return(0);
}
