int load_screen_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/config_screens.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_screens.txt");
    }
    else
    {
        //premiere ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_screens.txt");
        }

        fscanf( cfg_file, "%d / %d %d / %d %d /\n",  &index_fullscreen, &largeur_ecran, &hauteur_ecran, &posX_mainwindow, &posY_mainwindow);

        fclose( cfg_file );
    }

    return(0);
}
