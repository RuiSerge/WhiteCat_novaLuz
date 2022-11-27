int store_relativ_xy_position_of_activ_calc(int calc)
{
for(int i=1;i<nbre_symbol_per_layer;i++)
{
for (int t=0;t<5;t++)
{
temp_relatif_plot_xy_array[i][t][0]=relatif_plot_xy[calc][i][t][0];
temp_relatif_plot_xy_array[i][t][1]=relatif_plot_xy[calc][i][t][1];
}
}
return(0);
}
