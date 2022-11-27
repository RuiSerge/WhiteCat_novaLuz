int copy_symbol_to_emply_slot(int calc, int empty, int filled)
{

symbol_type[calc][empty]=snapshot_symbol_type[filled];
symbol_is_selected[calc][empty]=snapshot_symbol_is_selected[filled];
angle_symbol[calc][empty]=snapshot_angle_symbol[filled];
pos_symbol[calc][empty][0]=snapshot_pos_symbol[filled][0];
pos_symbol[calc][empty][1]=snapshot_pos_symbol[filled][1];
symbol_channel_is[calc][empty]=snapshot_symbol_channel_is[filled];
symbol_dimmer_is[calc][empty]=snapshot_symbol_dimmer_is[filled];

if(snapshot_symbol_is_linked_to[filled]!=0)
{
symbol_is_linked_to[calc][empty]=snapshot_symbol_is_linked_to[filled]-(filled-empty);
}

for(int ge=0;ge<3;ge++)
{
gelat[calc][empty][ge]=snapshot_gelat[filled][ge];
gelat_family[calc][empty][ge]=snapshot_gelat_family[filled][ge];
}
for(int opt=0;opt<5;opt++)
{
relatif_plot_xy[calc][empty][opt][0]=snapshot_relatif_plot_xy[filled][opt][0];
relatif_plot_xy[calc][empty][opt][1]=snapshot_relatif_plot_xy[filled][opt][1];
}
symbol_channel_is[calc][empty]=snapshot_symbol_channel_is[filled];
for(int n=0;n<4;n++)
{
sprintf(symbol_note[calc][empty][n],snapshot_symbol_note[filled][n]);
}
return(0);
}
