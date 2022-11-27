int group_symbols_selected(int calc)
{

bool do_ungroup=0;
 for(int i=1;i<= nbre_symbols_on_plot[calc];i++)
{
if(symbol_is_selected[calc][i]==1)
{
if( symbol_is_linked_to[calc][i]>0){ do_ungroup=1;break;}
}
}

 if(do_ungroup==1)
 {
 for(int i=1;i<= nbre_symbols_on_plot[calc];i++)
 {
 if(symbol_is_selected[calc][i]==1)
 {
 symbol_is_linked_to[calc][i]=0;
 }
 }
 }

else
{
int leading_symbol=0;
int leading_channel=0;// le premier symbole trouvé est celui qui permet le groupe
for(int i=1;i<= nbre_symbols_on_plot[calc];i++)
{
if(symbol_is_selected[calc][i]==1 && symbol_channel_is[calc][i]>0)
{
if(leading_channel==0){
leading_symbol=i;
leading_channel=symbol_channel_is[calc][i];
}
break;
}
}
for(int i=leading_symbol+1;i<= nbre_symbols_on_plot[calc];i++)
{
if(symbol_is_selected[calc][i]==1 && symbol_channel_is[calc][i]==leading_channel)
{
symbol_is_linked_to[calc][i]=leading_symbol;
}
}
}
return(0);
}
