int load_artnet_conf()
{
    //variables chargement config
FILE *cfg_file = NULL ;
char read_buff[ 512 ] ;


    //sab 0/03/2014 unused int it=0;
	cfg_file = fopen("user\\config_artnet.txt", "rt" );
	if( !cfg_file )
	{
	 printf("\nPb à ouverture de config_artnet.txt\n");
     return 1;
	}
	if( !fgets( read_buff , sizeof( read_buff ) , cfg_file ) )
	{
     printf("\nErreur lors de la lecture de la première ligne de commentaires\n");
     return 1;
	}


fscanf( cfg_file , "%d %d /\n" ,  &index_broadcast , &Univers  );
/* on saute la ligne de commentaire */
fgets( read_buff , sizeof( read_buff ) , cfg_file );
fscanf( cfg_file  , "%s\n" , ip_artnet );

fclose( cfg_file );
return(0);
}
