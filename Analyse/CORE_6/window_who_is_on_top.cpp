int window_who_is_on_top()
{
    int id_on_top=0;
    for(int i=0; i<63; i++)
    {
        if(window_opened[i]>=900)
        {
            id_on_top=i;
            break;
        }
    }
    return(window_opened[id_on_top]);
}
