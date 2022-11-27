int reset_error_on_save_load()
{
    for (int f=0; f<256; f++)
    {
        b_report_error[f]=0;
    }
    there_is_an_error_on_save_load=0;
    return(0);
}
