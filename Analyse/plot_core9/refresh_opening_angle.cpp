int refresh_opening_angle(float openingangle)//arc case 9
{
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1 && shape_type[i]==9){shape_attributes[i][4]=openingangle;}
}
 return(0);
}
