int Load_Plot_Plan_config()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused var int it=0;
	cfg_file = fopen("plot_plan_config.txt", "rt" );
	if( !cfg_file )
	{	 sprintf(string_save_load_report[idf],"Error on opening plot_plan_config.txt"); b_report_error[idf]=1;	}
	else
    {
    //lecture ouverture fichier ok
    sprintf(string_save_load_report[idf],"plot_plan_config.txt opened");

	if( !fgets( read_buff_winfil , sizeof( read_buff_winfil ) ,cfg_file ) )
	{     sprintf(string_save_load_report[idf],"Error on reading plot_plan_config.txt");b_report_error[idf]=1; 	}
    else {sprintf(string_save_load_report[idf],"plot_plan_config.txt readed");}
	//sab 05/08/2016 deb - nom du plan avec espace mets un bazar dans la lecture des datas de plot ( pb de scanf )
                    //fscanf( cfg_file , "%s\n" , Name_of_plane_is);
                    Name_of_plane_is [0]=0;
                    if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
                    {
                     sprintf(string_save_load_report[idf],"Error plot_plan_config.txt");
                    }
                    else
                    {
                     whc_toolbox tool ;
                     tool.copy_until_eol(Name_of_plane_is,sizeof( Name_of_plane_is ),read_buff_winfil);
                    }
                    //sab 05/08/2016 fin
	if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
	{
     sprintf(string_save_load_report[idf],"Error plot_plan_config.txt");
	}
    fscanf( cfg_file , "%d / %d / %d / %d / %f / %f / %d / %f /\n" ,&position_relative_plan_theatre[0],&position_relative_plan_theatre[1],&taille_relative_plan_theatre[0],&taille_relative_plan_theatre[1],&orientation_plan_theatre,&alpha_plan, &lock_background_proportions, &global_symbol_size);
	if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ) ,cfg_file ) )
	{
     sprintf(string_save_load_report[idf],"Error plot_plan_config.txt");
	}
    fscanf( cfg_file , "%d / %d / %d / %d / %d / %f / %f / %d / %d / %d / %f / %f / %f / %d /\n",&plot_quadrillage_size,&plot_window_x_size,&plot_window_y_size, &plot_view_port_x, &plot_view_port_y, &Color_plotline, &Color_plotfill, &nbre_shapes_on_plot, &index_show_shape_id, &plot_grid_type, &alpha_grille, &general_alpha_for_shape, &ratio_lock_plot_scale, &mode_relatif_xy_solo);

	fclose( cfg_file );
	}

if(plot_window_x_size<840){plot_window_x_size=840;}
if(plot_window_y_size<plot_minimum_y_size){plot_window_y_size=plot_minimum_y_size;}
if(plot_quadrillage_size<0){plot_quadrillage_size=0;}
else if(plot_quadrillage_size>100){plot_quadrillage_size=100;}
Rgba TmpPlotColor (Color_plotline,Color_plotline,Color_plotline);
CouleurPlotLine=TmpPlotColor;
Rgba TmpPlotColor2 (Color_plotfill,Color_plotfill,Color_plotfill);
CouleurPlotFill=TmpPlotColor2;
return(0);
}
