int build_preset_view_from_all_existing_mems_and_faders(int view_is)
{
    clear_selection_in( view_is) ;

    bool selectio_on[513];

    for (int l=0; l<512; l++)
    {
        selectio_on[l]=0;
    }
    for(int me=0; me<9999; me++)
    {
        if(MemoiresExistantes[me]==1)
        {

            for (int l=1; l<512; l++)
            {
                if((int)(Memoires[me][l])!=0)
                {
                    selectio_on[l]=1;
                }
            }
        }
    }
    for(int f=0; f<48; f++)
    {
        for (int l=1; l<512; l++)
        {
            for(int dd=0; dd<6; dd++)
            {
                if((int)(FaderDockContains[f][dd][l])>0)
                {
                    selectio_on[l]=1;
                }
            }
        }
    }

    int pos=0;
    for (int l=1; l<512; l++)
    {
        if(selectio_on[l]==1)
        {
            Channel_View_ROUTING[view_is][pos]=l;
            pos++;
        }
    }
    count_number_of_channels_in_view(view_is);
    reorder_channel_view_list_of_channels(view_is);
    sprintf(channel_view_Name[view_is],"All Mems and Faders");
    return(0);
}
