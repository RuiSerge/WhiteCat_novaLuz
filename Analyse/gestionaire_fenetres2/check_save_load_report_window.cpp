int check_save_load_report_window()
{
    switch(index_show_save_load_report)
    {
    case 0:
        substract_a_window(W_SAVEREPORT);
        break;
    case 1:
        add_a_window(W_SAVEREPORT);
        break;
    default:
        break;
    }
    return(0);
}
