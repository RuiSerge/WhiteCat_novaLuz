int reset_channel_first_dimmer_list()
{
    for (int ch=1; ch<513; ch++)
    {
        for(int d=0; d<4; d++)
        {
            show_first_dim_array[ch][d]=0;
        }
        show_more_than_one_dim[ch]=0;
    }
    return(0);
}
