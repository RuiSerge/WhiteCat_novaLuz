int affect_angle_to_shapes(float a)
{
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            shape_attributes[i][1]=a*6.5;
        }
    }

    return(0);
}
