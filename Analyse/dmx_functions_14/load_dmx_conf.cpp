int load_dmx_conf()
{
for(int i=0;i<NB_INTERFACES;i++)
{
    do_DMX_out[i]=0;
}
FILE *cfg_file = NULL ;
char read_buff[ 512 ] ;

	cfg_file = fopen("user\\config_dmx.txt", "rt" );
	if( !cfg_file )
	{
	 printf("\nPb à ouverture de config_dmx.txt\n");
     return 1;
	}

    //premiere ligne les args
	if( !fgets( read_buff , sizeof( read_buff ) ,cfg_file ) )
	{
     sprintf(string_save_load_report[idf],"! config_dmx.txt");
     return 1;
	}

	fscanf( cfg_file , "%d / %d / %d / %d / %d / %d /\n" ,  &do_DMX_out[0],&do_DMX_out[1],&do_DMX_out[2],&do_DMX_out[3],&do_DMX_out[4],&do_DMX_out[5] );

	fclose( cfg_file );


return(0);
}
