int detect_next_preset()
{
    bool turn=0;
    for (int p=(position_preset+1); p<10000; p++)
    {
        if(p>=9999 && turn==0)
        {
            p=0;
            turn=1;
        }
        if (MemoiresExistantes[p]==1 && MemoiresExclues[p]==0)
        {
            position_preset=p;
            break;
        }
    }
    return(0);
}
