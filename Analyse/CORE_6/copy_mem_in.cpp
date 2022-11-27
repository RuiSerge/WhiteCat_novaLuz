int copy_mem_in(int mem_n)//recopie d une memoire dans l autre
{
    MemoiresExistantes[mem_n]=1;
    for(int i=1; i<513; i++)
    {
        Memoires[mem_n][i]=Memoires[CTRLC_mem_to_copy][i];
    }
    sprintf(descriptif_memoires[mem_n],descriptif_memoires[CTRLC_mem_to_copy]);
    sprintf(annotation_memoires[mem_n],annotation_memoires[CTRLC_mem_to_copy]);
    Times_Memoires[mem_n][0]=Times_Memoires[CTRLC_mem_to_copy][0];
    Times_Memoires[mem_n][1]=Times_Memoires[CTRLC_mem_to_copy][1];
    Times_Memoires[mem_n][2]=Times_Memoires[CTRLC_mem_to_copy][2];
    Times_Memoires[mem_n][3]=Times_Memoires[CTRLC_mem_to_copy][3];
    Links_Memoires[mem_n]=Links_Memoires[CTRLC_mem_to_copy];
    Banger_Memoire[mem_n]=Banger_Memoire[CTRLC_mem_to_copy];
    sprintf(string_Last_Order,"Copyed in Mem. %d.%d Mem. %d.%d", mem_n/10,mem_n%10,CTRLC_mem_to_copy/10,CTRLC_mem_to_copy%10);
    strcpy(numeric,"");

    numeric_postext=0;
    return(0);
}
