int Load_Launchpad_RetroLight()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
	cfg_file = fopen("user/launchpad_lighting.txt", "rt" );
	if( !cfg_file )
	{
	 sprintf(string_save_load_report[idf],"! launchpad_lighting.txt");
	}
	else
	{
    //premiere ligne les args
	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{
     sprintf(string_save_load_report[idf],"! launchpad_lighting.txt");
	}

	fscanf( cfg_file ,  "%d / %d / %d / %d / %d / %d /\n" ,  &lch_orange, &lch_green, &lch_yellow, &lch_red, &lch_ambre, &lch_orange_fonce);

	fclose( cfg_file );
    }

    launchpad_color[0]=lch_orange;//63;
    launchpad_color[1]=lch_green;//60;
    launchpad_color[2]=lch_yellow;//62;
    launchpad_color[3]=lch_red;//15;
    launchpad_color[4]=lch_ambre;//31;
    launchpad_color[5]=lch_orange_fonce;//30;
return(0);
}
