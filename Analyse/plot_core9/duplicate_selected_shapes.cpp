int duplicate_selected_shapes()
{

int compteur=0;
int new_position=0;
for(int i=0;i<=nbre_shapes_on_plot;i++)
{
if( shape_selected[i]==1)
{
 compteur++;
 new_position=nbre_shapes_on_plot+compteur;
 if(new_position<127)
 {
shape_selected[new_position]=shape_selected[i];
shape_type[new_position]=shape_type[i];
shape_attributes[new_position][0]=shape_attributes[i][0];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[new_position][1]=shape_attributes[i][1];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[new_position][2]=shape_attributes[i][2];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[new_position][3]=shape_attributes[i][3];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_attributes[new_position][4]=shape_attributes[i][4];//size angle et accessoires 0= general size 1= rotation 2 size x 3 size y 4 oepning angle
shape_position[new_position][0]=shape_position[i][0]+2;//pour les lignes
shape_position[new_position][1]=shape_position[i][1]+2;
shape_position[new_position][2]=shape_position[i][2]+2;
shape_position[new_position][3]=shape_position[i][3]+2;
sprintf(shape_legend_name[new_position],shape_legend_name[i]);
shape_legend_name[nbre_shapes_on_plot][24]='\0';
shape_relativ_position_legend_name[new_position][0]=shape_relativ_position_legend_name[i][0];
shape_relativ_position_legend_name[new_position][1]=shape_relativ_position_legend_name[i][1];
shape_color_type[new_position]=shape_color_type[i];
 }
 else {break;}
 shape_selected[i]=0;
}
}
nbre_shapes_on_plot+=compteur;
return(0);
}
