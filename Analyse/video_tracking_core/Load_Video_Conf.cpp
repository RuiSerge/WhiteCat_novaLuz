int Load_Video_Conf()
{
set_default_image_size();

    FILE *video_file = NULL ;
    char read_buff_vid[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
	video_file = fopen("user\\config_video.txt", "rt" );
	if( !video_file )
	{
	  sprintf(string_save_load_report[idf],"! config_video.txt\n");
	}
	fgets( read_buff_vid , sizeof( read_buff_vid ) ,video_file );
	fscanf( video_file , "%d\n" ,  &camera_size_settings_is);
	//2eme ligne args
    fgets( read_buff_vid , sizeof( read_buff_vid ) ,video_file );
	fscanf( video_file , "%dx%d %dx%d\n",&camera_size_array[0][0],&camera_size_array[0][1],&camera_size_array[1][0],&camera_size_array[1][1]);
    //3eme ligne
	fgets( read_buff_vid , sizeof( read_buff_vid ) ,video_file );
	fscanf( video_file , "%d %d %d %d %d %d %d\n" , &flip_image,&threshold_on, &erode_mode,&blur_on, &threshold_level,&erode_level,&div_facteur);
	//4eme ligne
	fgets( read_buff_vid , sizeof( read_buff_vid ) ,video_file );
	fscanf( video_file , "%d %d" ,&tracking_dock_selected, &ocv_calcul_mode);


   if(ocv_calcul_mode==0){sprintf(string_ocv_mode,"DIV");}
   else if(ocv_calcul_mode==1){sprintf(string_ocv_mode,"SUB");}
   else if(ocv_calcul_mode==2){sprintf(string_ocv_mode,"AbsD");}

    fclose( video_file );

return(0);
}
