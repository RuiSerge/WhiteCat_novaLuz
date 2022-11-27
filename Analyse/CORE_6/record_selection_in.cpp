int record_selection_in(int view_is)//groupes de vues
{
    clear_selection_in(view_is);

    int index=0;
    for(int i=1; i<514; i++)
    {
        if(Selected_Channel[i]==1)
        {
            Channel_View_ROUTING[view_is][index]=i;
            index++;
            Selected_Channel[i]=0;
        }
    }
    count_number_of_channels_in_view(view_is);
    return(0);
}
