int load_draw_preset_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
	cfg_file = fopen("draw_presets_states.txt", "rt" );
	if( !cfg_file )
	{
	 sprintf(string_save_load_report[idf],"!draw_presets_states.txt");
	}

	else
	{

	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{ sprintf(string_save_load_report[idf],"! draw_presets_states.txt");}

    for(int i=0;i<6;i++)
    {

	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{ sprintf(string_save_load_report[idf],"! draw_presets_states.txt");}

   	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{ sprintf(string_save_load_report[idf],"! draw_presets_states.txt");}

    fscanf( cfg_file , "M %d / %f / %f / %f / %d /\n" , &draw_mode[i], &draw_level_to_do[i], &draw_damper_decay_factor[i] ,&draw_ghost_to_do[i], &draw_brush_type[i]);

    fscanf( cfg_file , "G %d / %d / %d / %d / %d /\n" ,&draw_get_gpl[i],&draw_offset_gpl[i], &index_case[i], &draw_centre_x[i], &draw_centre_y[i]);

    previous_draw_mode[i]=draw_mode[i];
    draw_get_gpl[i]=constrain_int_data_to_this_range(draw_get_gpl[i],1,4);
    draw_offset_gpl[i]=constrain_int_data_to_this_range(draw_offset_gpl[i],1,512);

    if(draw_level_to_do[i]>1.0){draw_level_to_do[i]=1.0;}
    if(draw_damper_decay_factor[i]>1.0){draw_damper_decay_factor[i]=1.0;}
    if(draw_ghost_to_do[i]>1.0){draw_ghost_to_do[i]=1.0;}

    }
    fclose( cfg_file );
    }

return(0);
}
