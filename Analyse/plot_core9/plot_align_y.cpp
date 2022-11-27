int plot_align_y(int calc)
{

int the_value=9999;
for(int i=0;i<= nbre_symbols_on_plot[calc];i++)
{
if(symbol_is_selected[calc][i]==1)
{
if(pos_symbol[calc][i][1]<the_value)
{
the_value=pos_symbol[calc][i][1];
}
}
}

for(int i=0;i<= nbre_symbols_on_plot[calc];i++)
{
if(symbol_is_selected[calc][i]==1)
{
pos_symbol[calc][i][1]=the_value;
}
}
 return(0);
}
