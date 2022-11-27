int modify_selection_in(int view_is)//groupes de vues
{
    bool temp_selv[514];

    for(int i=0; i<514; i++)
    {
        temp_selv[i]=0;
    }

    for(int i=0; i<514; i++)
    {
        if(Channel_View_ROUTING[view_is][i]>0)
        {
            temp_selv[(Channel_View_ROUTING[view_is][i])]=1;
        }
    }

    for(int i=1; i<514; i++)
    {
        if(Selected_Channel[i]==1)
        {
            temp_selv[i]=toggle(temp_selv[i]);
        }
    }

    clear_selection_in(view_is);

    int index_ch=0;
    for(int i=1; i<514; i++)
    {
        if(temp_selv[i]==1)
        {
            Channel_View_ROUTING[view_is][index_ch]=i;
            index_ch++;
        }
    }


    count_number_of_channels_in_view(view_is);


    return(0);
}
