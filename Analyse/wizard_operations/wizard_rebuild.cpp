int wizard_rebuild(int facteur_memoires)
{
int mem_p=wizard_from_mem;

for(int look=wizard_from_mem;look<=wizard_to_mem;look++)
{
if(Wiz_MemoiresExistantes[look]==1)
{
MemoiresExistantes[mem_p]=Wiz_MemoiresExistantes[look];
for(int cho=0;cho<513;cho++)
{Memoires[mem_p][cho]=Wiz_Memoires[look][cho];}
for(int t=0;t<4;t++)
{Times_Memoires[mem_p][t]=Wiz_Times_Memoires[look][t];}
Links_Memoires[mem_p]=Wiz_Links_Memoires[look];
Banger_Memoire[mem_p]=Wiz_Banger_Memoire[look];
sprintf(descriptif_memoires[mem_p],Wiz_descriptif_memoires[look]);
sprintf(annotation_memoires[mem_p],Wiz_annotation_memoires[look]);

Wiz_MemoiresExistantes[look]=0;
mem_p+=facteur_memoires;
}

}
position_onstage=wizard_from_mem;
refresh_mem_onstage(position_onstage);
detect_mem_before_one();
detect_mem_preset();
refresh_mem_onpreset(position_preset);

 return(0);
}
