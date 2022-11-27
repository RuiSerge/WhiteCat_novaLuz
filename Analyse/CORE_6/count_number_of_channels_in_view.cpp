int count_number_of_channels_in_view(int view_is)
{
    int indexCH=0;
    for(int i=0; i<513; i++)
    {
        if(Channel_View_ROUTING[view_is][i]>0 )
        {
            indexCH++;
        }
    }
    channel_number_in_View[view_is]=indexCH;
    channel_number_of_lines[view_is]=(int)(((float)indexCH)/12);
    if(indexCH%12>0)
    {
        channel_number_of_lines[view_is]+=1;
    }
    return(0);
}
