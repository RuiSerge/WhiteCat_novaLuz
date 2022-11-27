int change_shape_type(int shapetype)
{
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1){shape_type[i]=shapetype;}
}
return(0);
}
