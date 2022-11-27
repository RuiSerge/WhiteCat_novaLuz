int Load_Window_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
    cfg_file = fopen("config_windows.txt", "rt" );
    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"!config_windows.txt");
    }
    else
    {
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"! config_windows.txt");
        }
        fscanf( cfg_file, "%d %d / %d %d / %d %d / %d %d /\n",  &xtrichro_window, &ytrichro_window, &xnum_window,&ynum_window,&videoX,&videoY, &xpatch_window, &ypatch_window);
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file, "%d %d / %d %d / %d %d /\n",  &report_SL_X, &report_SL_Y, &xtime_window, &ytime_window,&xseq_window, &yseq_window);
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file,"%d / %d %d / %d %d /\n",&YFader, &XConfirm, &YConfirm, &xsave_window, &ysave_window );
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file,"%d %d / %d %d / %d %d / %d %d /\n",&XAlarm,&YAlarm,&XAudio,&YAudio, &window_cfgX, &window_cfgY, &X_banger, &Y_banger);
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file,"%d %d / %d %d / %d %d / %d %d / %d %d /\n",&Xwizard,&Ywizard,&xMinifaders,&yMinifaders, &Xlistproj, &Ylistproj, &Xchasers, &Ychasers,&xmover_window, &ymover_window);

        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error reading config_windows.txt");
        }
        fscanf( cfg_file,"%d %d / %d %d / %d %d / %d %d / %d %d / %d %d /\n",&X_gui_iCat,&Y_gui_iCat,&grider_window_x,&grider_window_y, &x_plot, &y_plot, &x_mainmenu, &y_mainmenu, &x_Wdraw, &y_Wdraw, &x_echo, &y_echo);


        fclose( cfg_file );
    }
    return(0);
}
