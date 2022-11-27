void write_text_to_log_file( const std::string &text )
{
    std::ofstream log_file(
        "log_file.txt", std::ios_base::out | std::ios_base::app );

    log_file << text ;
    log_file << "\n";
}
