int snapshot_calc(int calc)
{
for(int s=1;s<=nbre_symbols_on_plot[calc];s++)
{
snapshot_symbol_type[s]=symbol_type[calc][s];
snapshot_symbol_is_selected[s]=symbol_is_selected[calc][s];
snapshot_angle_symbol[s]=angle_symbol[calc][s];
snapshot_pos_symbol[s][0]=pos_symbol[calc][s][0];
snapshot_pos_symbol[s][1]=pos_symbol[calc][s][1];
snapshot_symbol_channel_is[s]=symbol_channel_is[calc][s];
snapshot_symbol_dimmer_is[s]=symbol_dimmer_is[calc][s];
snapshot_symbol_is_linked_to[s]=symbol_is_linked_to[calc][s];
for(int n=0;n<4;n++)
{
sprintf(snapshot_symbol_note[s][n],symbol_note[calc][s][n]);
}
for(int ge=0;ge<3;ge++)
{
snapshot_gelat[s][ge]=gelat[calc][s][ge];
snapshot_gelat_family[s][ge]=gelat_family[calc][s][ge];
}
for(int opt=0;opt<5;opt++)
{
snapshot_relatif_plot_xy[s][opt][0]=relatif_plot_xy[calc][s][opt][0];
snapshot_relatif_plot_xy[s][opt][1]=relatif_plot_xy[calc][s][opt][1];
}
}
return(0);
}
