int wizard_reset_to_default_time()
{
    for(int pm=wizard_from_mem; pm<=wizard_to_mem; pm++)
    {
        if(MemoiresExistantes[pm]==1)
        {
            Times_Memoires[pm][0]=0.0;
            Times_Memoires[pm][2]=0.0;
            Times_Memoires[pm][1]=default_time;//0=DIN 1=IN 2=DOUT 3=OUT
            Times_Memoires[pm][3]=default_time;
        }
    }

    return(0);
}
