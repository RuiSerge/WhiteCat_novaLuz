int wizard_restore_mem()
{
    for(int pm=wizard_from_mem; pm<=wizard_to_mem; pm++)
    {
        if(MemoiresDetruites[pm]==1)
        {
            MemoiresExistantes[pm]=1;
            MemoiresDetruites[pm]=0;
        }
    }
    return(0);
}
