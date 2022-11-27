int add_selected_symbols_to_calc(int calc)
{
for(int i=1;i<=nbre_symbol_per_layer;i++)
{
if( snapshot_symbol_is_selected[i]==1 )
{
if( nbre_symbols_on_plot[calc]<nbre_symbol_per_layer-1)
{
nbre_symbols_on_plot[calc]++;
copy_symbol_to_emply_slot(calc,nbre_symbols_on_plot[calc],i);
}
}
}
plot_generate_appareils_list();
return(0);
}
