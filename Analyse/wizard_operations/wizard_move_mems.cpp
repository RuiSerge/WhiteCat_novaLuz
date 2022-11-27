int wizard_move_mems()
{
    wizard_clear_transfert_array();

    for(int pm=0; pm<10000; pm++)
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

    for(int pm=wizard_from_mem; pm<=wizard_to_mem; pm++)
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

    int index_mem=0;
    int fin_des_memoires=0;
    for(int look=wizard_from_mem; look<=wizard_to_mem; look++)
    {
        if((variable_wizard_mem+index_mem)<10000)
        {
            MemoiresExistantes[variable_wizard_mem+index_mem]=Wiz_MemoiresExistantes[look];
            for(int cho=0; cho<513; cho++)
            {
                Memoires[variable_wizard_mem+index_mem][cho]=Wiz_Memoires[look][cho];
            }
            for(int t=0; t<4; t++)
            {
                Times_Memoires[variable_wizard_mem+index_mem][t]=Wiz_Times_Memoires[look][t];
            }
            Links_Memoires[variable_wizard_mem+index_mem]=Wiz_Links_Memoires[look];
            Banger_Memoire[variable_wizard_mem+index_mem]=Wiz_Banger_Memoire[look];
            sprintf(descriptif_memoires[variable_wizard_mem+index_mem],Wiz_descriptif_memoires[look]);
            sprintf(annotation_memoires[variable_wizard_mem+index_mem],Wiz_annotation_memoires[look]);
            index_mem++;
            fin_des_memoires=variable_wizard_mem+index_mem;
        }
    }
    index_mem/=10;
    index_mem+=1;
    index_mem*=10;
    for(int look=fin_des_memoires; look<10000; look++)
    {
        if((look-index_mem)>0)
        {
            MemoiresExistantes[look]=Wiz_MemoiresExistantes[look-index_mem];
            for(int cho=0; cho<513; cho++)
            {
                Memoires[look][cho]=Wiz_Memoires[look-index_mem][cho];
            }
            for(int t=0; t<4; t++)
            {
                Times_Memoires[look][t]=Wiz_Times_Memoires[look-index_mem][t];
            }
            Links_Memoires[look]=Wiz_Links_Memoires[look-index_mem];
            Banger_Memoire[look]=Wiz_Banger_Memoire[look-index_mem];
            sprintf(descriptif_memoires[look],Wiz_descriptif_memoires[look-index_mem]);
            sprintf(annotation_memoires[look],Wiz_annotation_memoires[look-index_mem]);
        }
    }

    position_onstage=variable_wizard_mem;
    refresh_mem_onstage(position_onstage);
    detect_mem_before_one();
    detect_mem_preset();
    refresh_mem_onpreset(position_preset);

    return(0);
}
