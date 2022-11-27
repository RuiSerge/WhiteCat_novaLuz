int generate_channel_view_list_from_patched_circuits()
{
    clear_selection_in(0);
    int index=0;
    bool nopatchit=0;
    for(int ch=1; ch<513; ch++)
    {
        for (int i=1; i<513; i++)
        {
            if(Patch[i]==ch)
            {
                for(int u=0; u<513; u++)
                {
                    if(Channel_View_ROUTING[0][u]==ch)
                    {
                        nopatchit=1;
                        break;
                    }
                }
                if(nopatchit==0)
                {
                    Channel_View_ROUTING[0][index]=ch;
                    index++;
                }
            }
        }
        nopatchit=0;
    }
    count_number_of_channels_in_view(0);

    generate_channel_preview_patch_list();
    return(0);
}
