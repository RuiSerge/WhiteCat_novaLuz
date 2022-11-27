int detect_last_activ_channel_in_activ_view(int v)
{
    int id=Channel_View_ROUTING[v][(channel_number_in_View[v]-1)];

    return(id);
}
