int position_on_top(int calc)
{
snapshot_calc(calc);
for(int i=1;i<=nbre_symbol_per_layer;i++)
{
if(symbol_is_selected[calc][i]==1 && i<=nbre_symbols_on_plot[calc])
{
exchange_symbol_position(calc,i,nbre_symbols_on_plot[calc]);
symbol_is_linked_to[calc][i]=0;
}
}
return(0);
}
