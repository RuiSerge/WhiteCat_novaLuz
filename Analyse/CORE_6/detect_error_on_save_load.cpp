int detect_error_on_save_load()
{
    for (int f=0; f<256; f++)
    {
        if( b_report_error[f]==1)
        {
            there_is_an_error_on_save_load=1;
            break;
        }
    }
    return(0);
}
