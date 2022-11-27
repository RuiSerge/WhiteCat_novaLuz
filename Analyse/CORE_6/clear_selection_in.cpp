int clear_selection_in(int view_is)//groupes de vues
{
    for(int i=0; i<513; i++)
    {
        Channel_View_ROUTING[view_is][i]=0;
    }
    count_number_of_channels_in_view(view_is);
    return(0);
}
