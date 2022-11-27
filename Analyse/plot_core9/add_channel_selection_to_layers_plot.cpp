int add_channel_selection_to_layers_plot()
{
int tmp_ch=0;
for(int l=0;l<4;l++)
{
for(int i=1;i<=nbre_symbols_on_plot[l];i++)
{
tmp_ch=symbol_channel_is[l][i];
if(Selected_Channel[tmp_ch]==1)
{
symbol_is_selected[l][i]= 1;
}
}
}
return(0);
}
