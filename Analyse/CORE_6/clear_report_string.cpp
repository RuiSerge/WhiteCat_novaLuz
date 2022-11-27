int clear_report_string()
{
    for(int i=0; i<256 ; i++)
    {
        sprintf(string_save_load_report[i],"-");
    }
    reset_error_on_save_load();
    return(0);
}
