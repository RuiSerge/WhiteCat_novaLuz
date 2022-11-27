int plot_shapes_align_x()
{
    int the_value=9999;
    for(int i=0; i<= nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            if(shape_position[i][0]<the_value)
            {
                the_value=shape_position[i][0];
            }
        }
    }

    int longueur_trait=0;
    bool way_negativ=0;

    for(int i=0; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            if(shape_type[i]<7)
            {
                if(shape_position[i][0]>shape_position[i][2])
                {
                    longueur_trait=shape_position[i][0]-shape_position[i][2];
                    way_negativ=1;
                }
                else
                {
                    longueur_trait=shape_position[i][2]-shape_position[i][0];
                }
            }

            shape_position[i][0]=the_value;

            if(shape_type[i]<7)
            {
                if(way_negativ==1)
                {
                    shape_position[i][2]=shape_position[i][0]-longueur_trait;
                }
                else
                {
                    shape_position[i][2]=shape_position[i][0]+longueur_trait;
                }
            }
        }
    }

    return(0);
}
