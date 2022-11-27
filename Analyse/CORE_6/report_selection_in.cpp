int report_selection_in(int view_is)
{

    for (int v=1; v<nbre_de_vues_circuits; v++)
    {
        for(int ch=0; ch<512; ch++)
        {
            if( Selected_Channel[(Channel_View_ROUTING[v][ch])]==1)
            {
                Channel_View_ROUTING[v][ch]=0;
            }
        }
    }




    clear_selection_in( view_is) ;
    int pos=0;
    for (int l=1; l<514; l++)
    {
        if(Selected_Channel[l]==1)
        {
            Channel_View_ROUTING[view_is][pos]=l;
            pos++;
        }
    }
    sprintf(channel_view_Name[view_is],"Reported View");

    for (int vf=1; vf<nbre_de_vues_circuits; vf++)
    {
        count_number_of_channels_in_view(vf);
        reorder_channel_view_list_of_channels(vf);
    }
    return(0);
}
