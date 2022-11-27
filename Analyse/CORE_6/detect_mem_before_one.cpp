int detect_mem_before_one()
{
    bool turn=0;
    for (int k=position_onstage-1; k>=0; k--)
    {
        if(k==0  && turn==0)
        {
            k=9999;
            turn=1;
        }
        if(MemoiresExistantes[k]==1 && MemoiresExclues[k]==0)
        {
            mem_before_one=k;
            break;
        }
    }
    return(0);
}
