int reorder_channel_view_list_of_channels(int view_is)
{

    bool presence_of_channel[513];
    for (int l=0; l<=channel_number_in_View[view_is]; l++)
    {
        if(Channel_View_ROUTING[view_is][l]>0)
        {
            presence_of_channel[(Channel_View_ROUTING[view_is][l])]=1;
        }
    }

    int pos=0;
    for (int l=0; l<=channel_number_in_View[view_is]; l++)
    {
        if(presence_of_channel[l]==1)
        {
            Channel_View_ROUTING[view_is][pos]=l;
            pos++;
        }
    }

    return(0);
}
