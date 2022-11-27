int  search_affect_first_dimmer_to_symbole(int calc, int symb)
{
for(int i=0;i<513;i++)
{
if(Patch[i]==symbol_channel_is[calc][symb])
{
symbol_dimmer_is[calc][symb]=i;
break;
}
}

return(0);
}
