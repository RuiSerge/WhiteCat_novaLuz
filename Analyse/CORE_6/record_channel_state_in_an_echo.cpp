int record_channel_state_in_an_echo(int ech)
{
    for(int i=0; i<512; i++)
    {
        snap_echo_to_recall[ech][i]=echo_levels[ech][0][i];
    }
    sprintf(string_Last_Order,"Snaped and stored channel state in Echo %d",ech+1);
    return(0);
}
