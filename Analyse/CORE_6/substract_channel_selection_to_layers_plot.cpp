int substract_channel_selection_to_layers_plot()
{
int tmp_ch=0;
for(int l=0;l<4;l++)
{
for(int i=0;i<=nbre_symbols_on_plot[l];i++)
{
tmp_ch=symbol_channel_is[l][i];
if(Selected_Channel[tmp_ch]==0)
{
symbol_is_selected[l][i]= 0;
}
}
}
return(0);
}
