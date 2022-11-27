int store_plot_position_of_shapes()
{
    for(int i=1; i<= nbre_shapes_on_plot; i++)
    {
        stored_plot_shape_position[i][0]=shape_position[i][0];
        stored_plot_shape_position[i][1]=shape_position[i][1];
        stored_plot_shape_position[i][2]=shape_position[i][2];
        stored_plot_shape_position[i][3]=shape_position[i][3];
    }
    return(0);
}
