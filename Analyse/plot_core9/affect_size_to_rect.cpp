int affect_size_to_rect(float sizex, float sizey)
{

    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            shape_attributes[i][2]=sizex;
            shape_attributes[i][3]=sizey;
        }
    }


    return(0);
}
