int send_symbols_from_calc_to_calc(int calc_source,int calc_dest)
{
snapshot_calc(calc_source);

delete_selected_symbols(calc_source);
add_selected_symbols_to_calc(calc_dest);

reset_symbols_selected(calc_dest);
return(0);
}
