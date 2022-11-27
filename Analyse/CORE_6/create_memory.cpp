int create_memory(int mem_to_create)
{
    if ( mem_to_create>10000)
    {
        sprintf(string_Last_Order,"a Mem can't be > to 1000");
    }

    else
    {
        MemoiresExistantes[mem_to_create]=1;
        sprintf(string_Last_Order,"Mem %d.%d created", mem_to_create/10, mem_to_create%10);
        Times_Memoires[mem_to_create][0]=0.0;
        Times_Memoires[mem_to_create][2]=0.0;
        Times_Memoires[mem_to_create][1]=default_time;
        Times_Memoires[mem_to_create][3]=default_time;
        ratio_cross_manuel[mem_to_create]=0;
        strcpy(descriptif_memoires[mem_to_create],"");
        strcpy(annotation_memoires[mem_to_create],"");

        Links_Memoires[mem_to_create]=0;
        Banger_Memoire[mem_to_create]=0;
        MemoiresExclues[mem_to_create]=0;
        record_memory(mem_to_create);

        if(index_blind==0)
        {
            position_onstage=mem_to_create;
            detect_mem_before_one();
            detect_mem_preset();
            refresh_mem_onpreset(position_preset);
        }
        else if (index_blind==1)
        {
            position_preset=mem_to_create;
        }

    }

    ratio_X1X2_together=0;
    return(0);
}
