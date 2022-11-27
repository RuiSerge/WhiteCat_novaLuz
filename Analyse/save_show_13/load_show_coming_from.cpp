int load_show_coming_from()
{

    FILE *cfg_file = NULL ;
    //sab 02/03/2014 unused var char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
	cfg_file = fopen("user/show_coming_from.txt", "rt" );
	if( !cfg_file )
	{	 sprintf(string_save_load_report[idf],"Error on opening user/show_coming_from.txt"); b_report_error[idf]=1;	}
	else {
    sprintf(string_save_load_report[idf],"user/show_coming_from.txt opened");}
	fgets( my_show_is_coming_from , sizeof( my_show_is_coming_from ) ,cfg_file ) ;
	fclose( cfg_file );
    sprintf(string_save_load_report[idf],"loaded show_coming_from.txt");

 return(0);
}
