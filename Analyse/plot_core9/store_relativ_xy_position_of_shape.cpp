int store_relativ_xy_position_of_shape()
{
    for(int i=1; i<nbre_shapes_on_plot; i++)
    {
        temp_shape_relativ_position_legend_name[i][0]=shape_relativ_position_legend_name[i][0];
        temp_shape_relativ_position_legend_name[i][1]=shape_relativ_position_legend_name[i][1];
    }
    return(0);
}
