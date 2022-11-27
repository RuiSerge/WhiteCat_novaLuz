int wizard_clear_mem_original()
{
for(int pm=wizard_from_mem;pm<=wizard_to_mem;pm++)
{
MemoiresExistantes[pm]=0;
for(int cho=0;cho<513;cho++)
{
Memoires[pm][cho]=0;
}
Times_Memoires[pm][0]=0.0;
Times_Memoires[pm][1]=0.0;
Times_Memoires[pm][2]=0.0;
Times_Memoires[pm][3]=0.0;
Links_Memoires[pm]=0;
Banger_Memoire[pm]=0;
strcpy(descriptif_memoires[pm],"");
descriptif_memoires[pm][24]='\0';
strcpy(annotation_memoires[pm],"");
annotation_memoires[pm][24]='\0';
}
 return(0);
}
