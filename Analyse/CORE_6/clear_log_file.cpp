void clear_log_file()
{
     std::ofstream log_file("log_file.txt", std::ios_base::out | std::ios_base::trunc );

    char buff[20];
    struct tm *sTm;

    time_t now = time (0);
    sTm = localtime (&now);

    strftime (buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
    write_text_to_log_file( buff);

}
