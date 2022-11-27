int detect_mem_preset()
{
    bool turn=0;
    for (int k=position_onstage+1; k<10000; k++)
    {
        if(k>=9999 && turn==0)
        {
            k=0;
            turn=1;
        }
        if(MemoiresExistantes[k]==1 && MemoiresExclues[k]==0)
        {
            position_preset=k;
            break;
        }
    }
    return(0);
}
