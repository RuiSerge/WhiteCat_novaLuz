int recount_symbols_on_calc(int calc)
{

int index=0;

for(int st=0;st<nbre_symbol_per_layer;st++)
{
if(symbol_type[calc][st]!=999)
{
index++;
}
}
nbre_symbols_on_plot[calc]=index;
 return(0);
}
