int build_preset_view_from_fader( int f, int view_is)
{
    clear_selection_in( view_is) ;
    int pos=0;
    for (int l=1; l<512; l++)
    {
        if((int)(FaderDockContains[f-1][(dock_used_by_fader_is[f-1])][l])>0)
        {
            Channel_View_ROUTING[view_is][pos]=l;
            pos++;
        }
    }

    count_number_of_channels_in_view(view_is);
    sprintf(channel_view_Name[view_is],"Fader %d", f);
    return(0);
}
