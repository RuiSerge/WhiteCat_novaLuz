int unselect_all_shapes()
{
 for(int i=0;i<nbre_symbol_per_layer-1;i++)
 {
  shape_selected[i]=0;
 }
 return(0);
}
