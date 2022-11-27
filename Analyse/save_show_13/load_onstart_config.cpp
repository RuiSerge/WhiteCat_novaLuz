int load_onstart_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_onstart.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_onstart.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_onstart.txt");
        }

        fscanf( cfg_file, "%d / %d / %d / %d /\n",  &camera_on_open, &open_arduino_on_open, &enable_iCat, &expert_mode);

        fclose( cfg_file );
    }
    return(0);
}
