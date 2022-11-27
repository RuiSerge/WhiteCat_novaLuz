int record_channel_ch_state_in_an_echo(int ech, int cha)//par circuit
{

    snap_echo_to_recall[ech][cha]=echo_levels[ech][0][cha];

    sprintf(string_Last_Order,"Snaped and stored channel %d state in Echo %d",cha+1,ech+1);
    return(0);
}
