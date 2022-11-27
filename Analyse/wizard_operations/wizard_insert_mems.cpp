int wizard_insert_mems()
{
    for(int pm=wizard_from_mem; pm<=wizard_from_mem+variable_wizard_mem; pm++)
    {
        MemoiresExistantes[pm]=0;
        for(int cho=0; cho<513; cho++)
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

    for(int look=wizard_from_mem; look<=wizard_to_mem; look++)
    {
        if(Wiz_MemoiresExistantes[look]==1 && look+variable_wizard_mem<10000)
        {
            MemoiresExistantes[look+variable_wizard_mem]=Wiz_MemoiresExistantes[look];
            for(int cho=0; cho<513; cho++)
            {
                Memoires[look+variable_wizard_mem][cho]=Wiz_Memoires[look][cho];
            }
            for(int t=0; t<4; t++)
            {
                Times_Memoires[look+variable_wizard_mem][t]=Wiz_Times_Memoires[look][t];
            }
            Links_Memoires[look+variable_wizard_mem]=Wiz_Links_Memoires[look];
            Banger_Memoire[look+variable_wizard_mem]=Wiz_Banger_Memoire[look];
            sprintf(descriptif_memoires[look+variable_wizard_mem],Wiz_descriptif_memoires[look]);
            sprintf(annotation_memoires[look+variable_wizard_mem],Wiz_annotation_memoires[look]);
            Wiz_MemoiresExistantes[look]=0;
        }
    }
    position_onstage=wizard_from_mem;
    refresh_mem_onstage(position_onstage);
    detect_mem_before_one();
    detect_mem_preset();
    refresh_mem_onpreset(position_preset);


    return(0);
}
