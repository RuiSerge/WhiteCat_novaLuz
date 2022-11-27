int affect_size_to_shape(float size)
{
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            shape_attributes[i][0]=general_shape_size_to_apply;
        }
    }
    return(0);
}
