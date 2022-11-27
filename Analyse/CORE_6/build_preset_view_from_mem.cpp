int  build_preset_view_from_mem( int me, int view_is)
{
    if(MemoiresExistantes[me]==1)
    {
        clear_selection_in( view_is) ;
        int pos=0;
        for (int l=1; l<512; l++)
        {
            if(Memoires[me][l]>0)
            {
                Channel_View_ROUTING[view_is][pos]=l;
                pos++;
            }
        }
        count_number_of_channels_in_view(view_is);
        sprintf(channel_view_Name[view_is],"Mem %d.%d", me/10,me%10);
    }
    return(0);
}
