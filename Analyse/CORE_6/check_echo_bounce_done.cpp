int check_echo_bounce_done(int ech)
{
    bool someone_bouncing=0;
    for(int i=0; i<512; i++)
    {
        if(echo_levels[ech][0][i]!=echo_levels[ech][1][i] )
        {
            someone_bouncing=1;
            break;
        }
    }
    if(someone_bouncing==0)
    {
        do_bounce[ech]=0;
    }
    return(0);
}
