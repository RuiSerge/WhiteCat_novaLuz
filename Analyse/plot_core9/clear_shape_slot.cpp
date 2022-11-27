int clear_shape_slot(int s)
{
    shape_selected[s]=0;
    shape_type[s]=0;
    shape_attributes[s][0]=10.0;//size G
    shape_attributes[s][1]=0.0;//angle rot
    shape_attributes[s][2]=1.0;//size x
    shape_attributes[s][3]=10.0;//size y
    shape_attributes[s][4]=0.1;//opening angle
    for(int i=0; i<4; i++)
    {
        shape_position[s][i]=0;//pour les lignes
    }
    strcpy(shape_legend_name[s],"");
    shape_legend_name[s][24]='\0';
    shape_relativ_position_legend_name[s][0]=0;
    shape_relativ_position_legend_name[s][1]=0;
    shape_color_type[s]=0;
    shape_selected[s]=0;
    shape_groups[s]=0;

    return(0);
}
