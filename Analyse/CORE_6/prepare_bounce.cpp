int prepare_bounce(int ech)
{

    for(int i=0; i<512; i++)
    {
        tmp_echo[ech][i]=0.0;
        tmp_falling_from_level[ech][i]=echo_levels[ech][0][i];
        echo_way[ech][i]=0;
    }
    bounce_is_prepared[ech]=1;
    return(0);
}
