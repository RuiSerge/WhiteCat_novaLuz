int refresh_view_shape_params(int sh)
{
    shape_selected_type=shape_type[sh];
    general_shape_size_to_apply=shape_attributes[sh][0];
    angle_shape_selected=shape_attributes[sh][1]/6.5;
    if(shape_type[sh]>=0 && shape_type[sh]<7)
    {
        color_pattern_selected=shape_color_type[sh];
    }
    else if (shape_type[sh]==7)
    {
        shape_rect_size_x=shape_attributes[sh][2];
        shape_rect_size_y=shape_attributes[sh][3];
        color_pattern_selected=shape_color_type[sh];
    }
    else if(shape_type[sh]==8)//cercle
    {
        color_pattern_selected=shape_color_type[sh];
    }
    else if(shape_type[sh]==9)//arc
    {
        opening_angle_selected=shape_attributes[sh][4];
        color_pattern_selected=shape_color_type[sh];
    }
    else if(shape_type[sh]==10)//polygo
    {
        nbre_branches_polygon=(int)shape_attributes[sh][2];
        color_pattern_selected=shape_color_type[sh];
    }
    sprintf(temp_shape_legend_name,shape_legend_name[sh]);
    return(0);
}
