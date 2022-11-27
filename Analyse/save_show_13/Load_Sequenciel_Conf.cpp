int Load_Sequenciel_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("sequenciel.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening Sequenciel.txt");
        b_report_error[idf]=1;
    }
    else
    {
        sprintf(string_save_load_report[idf],"Sequenciel.txt opened");
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading Sequenciel.txt");
            b_report_error[idf]=1;
        }
        else
        {
            sprintf(string_save_load_report[idf],"Sequenciel.txt readed");
        }
        fscanf( cfg_file, "%d / %d / %d / %d / %d /\n",  &position_onstage, &position_preset, &niveauX1, &niveauX2, &crossfade_speed);
        fscanf( cfg_file, "%f /\n",  &default_time);
        fscanf( cfg_file, "%d %d /\n",  &go_channel_is, &pause_channel_is);
        fclose( cfg_file );
    }
    midi_levels[491]=niveauX1/2;
    midi_levels[492]=127-(niveauX2/2);
    midi_levels[493]=crossfade_speed;
    if(go_channel_is<1 || ( go_channel_is> 512))
    {
        go_channel_is=0;
    }
    if(pause_channel_is<1 || ( pause_channel_is> 512))
    {
        pause_channel_is=0;
    }
    return(0);
}
