int initiate_windows()
{

    for(int i=0; i<63; i++)
    {
        if(window_opened[i]>=900)
        {
            add_a_window(window_opened[i]);
        }
    }
    window_focus_id=window_opened[0];

    return(0);
}
