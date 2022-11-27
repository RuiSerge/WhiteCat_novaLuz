int wizard_clear_transfert_array()
{
    for(int pm=wizard_from_mem; pm<=wizard_to_mem; pm++)
    {
        Wiz_MemoiresExistantes[pm]=0;
        for(int cho=0; cho<513; cho++)
        {
            Wiz_Memoires[pm][cho]=0;
        }
        Wiz_Times_Memoires[pm][0]=0.0;
        Wiz_Times_Memoires[pm][1]=0.0;
        Wiz_Times_Memoires[pm][2]=0.0;
        Wiz_Times_Memoires[pm][3]=0.0;
        Wiz_Links_Memoires[pm]=0;
        Wiz_Banger_Memoire[pm]=0;
        strcpy(Wiz_descriptif_memoires[pm],"");
        strcpy(Wiz_annotation_memoires[pm],"");
        Wiz_descriptif_memoires[pm][24]='\0';
        Wiz_annotation_memoires[pm][24]='\0';
    }
    return(0);
}
