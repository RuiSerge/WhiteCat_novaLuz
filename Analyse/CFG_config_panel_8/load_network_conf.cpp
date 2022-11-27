int load_network_conf()
{
FILE *cfg_file = NULL ;
char read_buff[ 512 ] ;

    //sab 02/03/2014 unused var char motcleinterfaceis[24];
    //sab 02/03/2014 unused var int it=0;
	cfg_file = fopen("user\\config_network.txt", "rt" );
	if( !cfg_file )
	{
	  sprintf(string_save_load_report[idf],"! config_network.txt\n");
	}

    //premiere ligne les args
	if( !fgets( read_buff , sizeof( read_buff ) ,cfg_file ) )
	{
     sprintf(string_save_load_report[idf],"! config_network.txt");
	}
	//sab 02/03/2014 fscanf( cfg_file , "%s\n" ,  &IP_artnet_IN );
	fscanf( cfg_file , "%s\n" ,  IP_artnet_IN );

	fgets( read_buff , sizeof( read_buff ) ,cfg_file );

	//sab 02/03/2014 fscanf( cfg_file , "%s\n" ,  &IP_artnet_OUT );
	fscanf( cfg_file , "%s\n" ,  IP_artnet_OUT );

	fgets( read_buff , sizeof( read_buff ) ,cfg_file );

	fscanf( cfg_file , "%d / %d /\n" ,  &serveurport_artnet, &clientport_artnet );

	fgets( read_buff , sizeof( read_buff ) ,cfg_file );

	//sab 02/03/2014 fscanf( cfg_file , "%s\n" ,  &IP_fantastick );
	fscanf( cfg_file , "%s\n" ,  IP_fantastick );

	fgets( read_buff , sizeof( read_buff ) ,cfg_file );

	//sab 02/03/2014 fscanf( cfg_file , "%s\n" ,  &specified_fs_ip );
	fscanf( cfg_file , "%s\n" ,  specified_fs_ip );

	fgets( read_buff , sizeof( read_buff ) ,cfg_file );

	fscanf( cfg_file , "%d / %d / %d /\n" ,  &serveurport_iCat, &clientport_iCat, &nbre_d_envois_de_l_info );

	fclose( cfg_file );


return(0);
}
