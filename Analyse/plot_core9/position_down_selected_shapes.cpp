int position_down_selected_shapes()
{
snapshot_shapes();
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1 && i>1)
{
exchange_shape_position(i, i-1);
}
}
return(0);
}
