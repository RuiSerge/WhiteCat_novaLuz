int load_core_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_core.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_core.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file, "%d / %d / %d / %d / %d / %d / %d /\n", &core_user_define_nb_faders, &core_user_define_nb_docks, &core_user_define_nb_chasers, &core_user_define_nb_tracks_per_chasers, &core_user_define_nb_gridplayers, &core_user_define_nb_bangers, &core_user_define_nb_echo);
        }
        //deuxieme ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file, "%d / %d / %d / %d / %d / %d / %d / %d / %d /\n",&core_do_calculations[0],&core_do_calculations[1],&core_do_calculations[2],
                    &core_do_calculations[3],&core_do_calculations[4],&core_do_calculations[5],&core_do_calculations[6],&core_do_calculations[7],&core_do_calculations[8]  );
        }
        //troisieme ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_core.txt");
        }
        else
        {
            fscanf( cfg_file, "%d / %d /\n",&BPS_RATE,&dmxINrate);
        }

        fclose( cfg_file );
    }
    return(0);
}
