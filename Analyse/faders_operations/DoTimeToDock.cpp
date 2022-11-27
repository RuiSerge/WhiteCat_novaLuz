int  DoTimeToDock(int faa,int docc)
{
for(int o=0;o<4;o++)
{
if(index_type_of_time_to_affect[o]==1)
{
 time_per_dock[faa][docc][o]=((time_minutes*60) + time_secondes + (((float)time_centiemes)/100));
}
}
return(0);
}
