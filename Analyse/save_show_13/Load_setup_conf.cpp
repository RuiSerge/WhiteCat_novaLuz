int Load_setup_conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("user/general_set_up.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening user/general_set_up.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"user/general_set_up.txt opened");
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading user/general_set_up.txt");
            b_report_error[idf]=1;
        }
        else
        {
            sprintf(string_save_load_report[idf],"user/general_set_up.txt readed");
        }
        fscanf( cfg_file, "%d / %d / %d / %d / %d / %d / %d / %d / %f /\n", &default_step_level, &wheellevel_absolutemode, &check_channel_level,
                &dimmer_check_level, &index_blink_change_memories, &index_midi_auto_desaffect, &dmx_view, &index_preloaded_sounds, &default_time_of_the_bang);
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading general_set_up.txt");
        }
        fscanf( cfg_file, "%d / %d / %d /\n",&automatic_time_for_save, &index_nbre_players_visibles, &LargeurEspaceFaderSize);

        fclose( cfg_file );
    }

    if(LargeurEspaceFaderSize<1024 )
    {
        LargeurEspaceFaderSize=1024;
    }
    if(LargeurEspaceFaderSize>largeur_ecran)
    {
        LargeurEspaceFaderSize=largeur_ecran;
    }

    return(0);
}
