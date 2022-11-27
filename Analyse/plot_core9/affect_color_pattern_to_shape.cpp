int affect_color_pattern_to_shape(int colorpattern)
{
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1){shape_color_type[i]=colorpattern;}
}
 return(0);
}
