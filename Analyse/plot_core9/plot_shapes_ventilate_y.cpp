int plot_shapes_ventilate_y()
{
    int the_highest_value=0;
    int the_lowest_value=0;
    int the_value=0;
    int the_count=0;

    int longueur_trait=0;
    bool way_negativ=0;

    for(int i=1; i<= nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            if(the_count==0)
            {
                the_highest_value=shape_position[1][1];
                the_lowest_value=shape_position[1][1];
            }
            the_count++;
            the_value=shape_position[i][1];

            if(the_value>= the_highest_value)
            {
                the_highest_value=the_value;
            }
            else if(the_value<=the_lowest_value)
            {
                the_lowest_value=the_value;
            }
        }
    }

    int the_frac=(int)(((float)(the_highest_value-the_lowest_value))/the_count);
    the_count=0;
    for(int i=0; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {

            if(shape_type[i]<7)
            {
                if(shape_position[i][1]>shape_position[i][3])
                {
                    longueur_trait=shape_position[i][1]-shape_position[i][3];
                    way_negativ=1;
                }
                else
                {
                    longueur_trait=shape_position[i][3]-shape_position[i][1];
                }
            }

            the_count++;
            shape_position[i][1]=the_lowest_value+(the_frac*the_count);


            if(shape_type[i]<7)
            {
                if(way_negativ==1)
                {
                    shape_position[i][3]=shape_position[i][1]-longueur_trait;
                }
                else
                {
                    shape_position[i][3]=shape_position[i][1]+longueur_trait;
                }
            }



        }
    }


    return(0);
}
