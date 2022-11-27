int reset_poll_list()
{
    for(int rt=0; rt<16; rt++) //etait 17 aout 2016
    {
        strcpy(PollReplyIs[rt],"");
    }
    count_artopoll_received=0;
    return(0);
}
