int build_preset_view_from_all_faders(int view_is)
{
    clear_selection_in( view_is) ;
    int pos=0;
    for(int f=0; f<48; f++)
    {
        for (int l=1; l<512; l++)
        {
            for(int dd=0; dd<6; dd++)
            {
                if((int)(FaderDockContains[f][dd][l])>0)
                {
                    Channel_View_ROUTING[view_is][pos]=l;
                    pos++;
                }
            }
        }
    }

    count_number_of_channels_in_view(view_is);
    reorder_channel_view_list_of_channels(view_is);
    sprintf(channel_view_Name[view_is],"All Faders");
    return(0);
}
