int add_shape_to_plot(int shapetype)
{
    if(nbre_shapes_on_plot<126)
    {
        nbre_shapes_on_plot++;
        clear_shape_slot(nbre_shapes_on_plot);
        unselect_all_shapes();

        shape_position[nbre_shapes_on_plot][0]=
            ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x;
        shape_position[nbre_shapes_on_plot][1]=
            ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;

        shape_attributes[nbre_shapes_on_plot][0]=general_shape_size_to_apply;
        shape_attributes[nbre_shapes_on_plot][1]= angle_shape_selected;

        switch(shapetype)
        {
        case 0://curtain
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 1://line
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 2://stline
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 3://stline
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 4://stline
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 5://stline
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 6://stline
            shape_position[nbre_shapes_on_plot][2]=
                ((plot_window_x_size-position_plan_x)/2)-plot_view_port_x+100;
            shape_position[nbre_shapes_on_plot][3]=
                ((plot_window_y_size-position_plan_y)/2)-plot_view_port_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 7://rectangle
            shape_attributes[nbre_shapes_on_plot][2]= shape_rect_size_x;
            shape_attributes[nbre_shapes_on_plot][3]= shape_rect_size_y;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 8://plot_draw_circle(int plotx1, int ploty1, float sizeshape,  float alphashape,   int colorpattern, bool isselected)
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 9://plot_draw_slice(int plotx1, int ploty1, float sizeshape, float opening_angle, float shaperotation, float alphashape,   int colorpattern, bool isselected)
            shape_attributes[nbre_shapes_on_plot][4]=opening_angle_selected;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 10://polygon
            shape_attributes[nbre_shapes_on_plot][2]=nbre_branches_polygon;
            shape_color_type[nbre_shapes_on_plot]= color_pattern_selected;
            break;
        case 11://(int plotx,int ploty, float fontsize,int fonttype,  char *text,float alphatext, bool isselected)
            shape_attributes[nbre_shapes_on_plot][2]=fonttype_selected;
            sprintf(shape_legend_name[nbre_shapes_on_plot],temp_shape_legend_name);
            shape_legend_name[nbre_shapes_on_plot][24]='\0';
            break;
        default:
            break;
        }

        shape_type[nbre_shapes_on_plot]=shapetype;
        shape_selected[nbre_shapes_on_plot]=1;
        shape_groups[nbre_shapes_on_plot]=0;
        index_last_shape_selected=nbre_shapes_on_plot;
        sprintf(shape_legend_name[nbre_shapes_on_plot],temp_shape_legend_name);

    }
    return(0);
}
