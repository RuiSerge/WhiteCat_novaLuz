int snapshot_shapes()
{
    for(int i=1; i<nbre_symbol_per_layer; i++)
    {
        snap_shape_selected[i]=shape_selected[i];
        snap_shape_type[i]=shape_type[i];
        snap_shape_attributes[i][0]=shape_attributes[i][0];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
        snap_shape_attributes[i][1]=shape_attributes[i][1];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
        snap_shape_attributes[i][2]=shape_attributes[i][2];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
        snap_shape_attributes[i][3]=shape_attributes[i][3];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
        snap_shape_attributes[i][4]=shape_attributes[i][4];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
        snap_shape_position[i][0]=shape_position[i][0];//pour les lignes
        snap_shape_position[i][1]=shape_position[i][1];
        snap_shape_position[i][2]=shape_position[i][2];
        snap_shape_position[i][3]=shape_position[i][3];
        sprintf(snap_shape_legend_name[i],shape_legend_name[i]);
        snap_shape_relativ_position_legend_name[i][0]=shape_relativ_position_legend_name[i][0];
        snap_shape_relativ_position_legend_name[i][1]=shape_relativ_position_legend_name[i][1];
        snap_shape_color_type[i]=shape_color_type[i];
        snap_shape_groups[i]=shape_groups[i];
    }

    return(0);
}
