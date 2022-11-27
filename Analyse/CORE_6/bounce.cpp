int bounce(int b)
{

    recall_channel_state_in_an_echo(b);
    do_bounce[b]=1;

    return(0);
}
