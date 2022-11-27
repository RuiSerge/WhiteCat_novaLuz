int load_arduino_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("arduino.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!arduino.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! arduino.txt");
        }

        fscanf( cfg_file, "%d / %d / %d / %d / %d /\n",  &arduino_com0, &arduino_baud_rate0, &ARDUINO_RATE, &arduino_max_digital,  &arduino_max_analog );
        fclose( cfg_file );
    }
    return(0);
}
