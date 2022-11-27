int Save_Plot_Plan_config()
{
    FILE *fpp;
    if((fpp=fopen("plot_plan_config.txt","w")))//etait wb
    {
        fprintf(fpp,"#arguments: Name_of_the_plan.jpg\n");
        fprintf(fpp, "%s\n", Name_of_plane_is);
        fprintf(fpp,"#arguments: position X / position Y / size X / size Y / Orientation / Alpha / Lock proportions / Global Library Size /\n");
        fprintf(fpp, "%d / %d / %d / %d / %f / %f / %d / %f /\n",position_relative_plan_theatre[0],position_relative_plan_theatre[1],taille_relative_plan_theatre[0],taille_relative_plan_theatre[1],orientation_plan_theatre,alpha_plan,lock_background_proportions, global_symbol_size);
        fprintf(fpp,"#arguments: Grid Scale / Plot Window size X / Plot Window size X / Plot Viewport X / Plot Viewport Y / Line Color / Background Color / Number of shapes present / Show shapes id / Grid Type / Alpha Grid / Alpha Shapes / Plan ratio / SoloMode xy relativs /\n");
        fprintf(fpp, "%d / %d / %d / %d / %d / %f / %f / %d / %d / %d / %f / %f / %f / %d /\n",plot_quadrillage_size,plot_window_x_size,plot_window_y_size, plot_view_port_x, plot_view_port_y, Color_plotline, Color_plotfill, nbre_shapes_on_plot, index_show_shape_id, plot_grid_type,alpha_grille, general_alpha_for_shape, ratio_lock_plot_scale, mode_relatif_xy_solo);
        fclose(fpp);
        sprintf(string_save_load_report[idf],"plot_plan_config.txt.txt");
    }


    if( !fpp )
    {
        sprintf(string_save_load_report[idf],"!plot_plan_config.txt");
    }
    return(0);
}
