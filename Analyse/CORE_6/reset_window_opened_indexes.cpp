int reset_window_opened_indexes()
{
    for(int i=0; i<63; i++)
    {
        temp_report_window[i]=0;
        window_opened[i]=0;
    }
    return(0);
}
