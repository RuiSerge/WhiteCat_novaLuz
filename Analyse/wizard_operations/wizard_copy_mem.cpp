int wizard_copy_mem()
{
    wizard_clear_transfert_array();
    for(int pm=wizard_from_mem; pm<=wizard_to_mem; pm++)
    {
        Wiz_MemoiresExistantes[pm]=MemoiresExistantes[pm];
        for(int cho=0; cho<513; cho++)
        {
            Wiz_Memoires[pm][cho]=Memoires[pm][cho];
        }
        for(int t=0; t<4; t++)
        {
            Wiz_Times_Memoires[pm][t]=Times_Memoires[pm][t];
        }
        Wiz_Links_Memoires[pm]=Links_Memoires[pm];
        Wiz_Banger_Memoire[pm]=Banger_Memoire[pm];
        sprintf(Wiz_descriptif_memoires[pm],descriptif_memoires[pm]);
        sprintf(Wiz_annotation_memoires[pm],annotation_memoires[pm]);
    }
    return(0);
}
