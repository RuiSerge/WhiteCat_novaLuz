int affect_polygon_nbr_of_corners(int brches)
{
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            shape_attributes[i][2]=(float)brches;
        }
    }

    return(0);
}
