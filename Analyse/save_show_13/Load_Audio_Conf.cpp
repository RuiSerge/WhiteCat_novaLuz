int Load_Audio_Conf()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
	cfg_file = fopen("audio_conf.txt", "rt" );
	if( !cfg_file )
	{	 sprintf(string_save_load_report[idf],"Error on opening Sequenciel.txt"); b_report_error[idf]=1;	}
	else {
    sprintf(string_save_load_report[idf],"audio_conf.txt opened");
	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{     sprintf(string_save_load_report[idf],"Error on reading audio_conf.txt");b_report_error[idf]=1; 	}
    else {sprintf(string_save_load_report[idf],"audio_conf.txt readed");}
	fscanf( cfg_file , "%s\n" ,  audio_folder);
	fclose( cfg_file );
    }


return(0);
}
