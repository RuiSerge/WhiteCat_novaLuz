int call_mem_onstage()
{
int mem_to_call=(int)(atof(numeric)*10.0001);
if (mem_to_call>10000)
{sprintf(string_Last_Order,"a Mem can't be > to 1000");}
else
{
if(MemoiresExistantes[mem_to_call]==0)
{
sprintf(string_Last_Order,"Mem %d.%d doesn't exist", mem_to_call/10,mem_to_call%10);
}
if (MemoiresExistantes[mem_to_call]==1 && mem_to_call!=0)//eviter cherger mem 0 en clickant vide
{
sprintf(string_Last_Order,"Loaded %d.%d on Stage", mem_to_call/10,mem_to_call%10);
position_onstage=mem_to_call;
refresh_mem_onstage(position_onstage);
detect_mem_before_one();
detect_mem_preset();
refresh_mem_onpreset(position_preset);
}
if (MemoiresExistantes[mem_to_call]==1 && mem_to_call==0)//eviter cherger mem 0 en clickant vide
{
sprintf(string_Last_Order,"Mem 0.0 can't be loaded on Stage");
}
}
reset_numeric_entry();
someone_changed_in_sequences=1;//icat
return(0);
}
