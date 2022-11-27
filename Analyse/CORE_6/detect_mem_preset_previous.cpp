int detect_mem_preset_previous()
{
    bool turn=0;
    for (int p=(position_preset-1); p>=0; p--)
    {
        if(p==0 && turn==0)
        {
            p=9999;
            turn=1;
        }
        if (MemoiresExistantes[p]==1)
        {
            position_preset=p;
            break;
        }
    }
    return(0);
}
