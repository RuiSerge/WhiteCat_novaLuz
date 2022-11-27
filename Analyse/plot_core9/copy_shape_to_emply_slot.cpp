int copy_shape_to_emply_slot(int empty, int filled)
{
shape_selected[empty]=snap_shape_selected[filled];
shape_type[empty]=snap_shape_type[filled];
shape_attributes[empty][0]=snap_shape_attributes[filled][0];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[empty][1]=snap_shape_attributes[filled][1];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[empty][2]=snap_shape_attributes[filled][2];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[empty][3]=snap_shape_attributes[filled][3];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[empty][4]=snap_shape_attributes[filled][4];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_position[empty][0]=snap_shape_position[filled][0];//pour les lignes
shape_position[empty][1]=snap_shape_position[filled][1];
shape_position[empty][2]=snap_shape_position[filled][2];
shape_position[empty][3]=snap_shape_position[filled][3];
sprintf(shape_legend_name[empty],snap_shape_legend_name[filled]);
shape_relativ_position_legend_name[empty][0]=snap_shape_relativ_position_legend_name[filled][0];
shape_relativ_position_legend_name[empty][1]=snap_shape_relativ_position_legend_name[filled][1];
shape_color_type[empty]=snap_shape_color_type[filled];
shape_groups[empty]=snap_shape_groups[filled];

return(0);
}
