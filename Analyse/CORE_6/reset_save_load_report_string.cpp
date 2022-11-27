int reset_save_load_report_string()
{
    for (int o=0; o<255; o++)
    {
        sprintf(string_save_load_report[o],"-");
        b_report_error[o]=0;
    }
    return(0);
}
