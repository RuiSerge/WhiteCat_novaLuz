int detect_next_mem(int mem_to_detect)//pour import ascii Anton 4 avril 2015
{
    for (int k=mem_to_detect+1; k<10000; ++k)
    {
        if(k>=9999)
        {
    return(0);
        }
        if(MemoiresExistantes[k]==1)
        {
            return k;
        }
    }
    return(0);
}
