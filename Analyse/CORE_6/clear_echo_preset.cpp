int clear_echo_preset(int ech)
{
    echo_pointing_fader_num[ech]=1;

    echo_is_echo_mode[ech]=0;

    echo_global_params[ech][0]=0.5;//gravity
    echo_global_params[ech][1]=1.0;//mass
    echo_global_params[ech][2]=0.2;//energy
    echo_channel_manipulate_mode[ech]=0;// 0 level up, 1 mass , 2 ground
    echo_grid_channel_position[ech]=0;

    for(int i=0; i<512; i++)
    {
        echo_levels[ech][0][i]=0.0;
        echo_levels[ech][1][i]=0.0;
        tmp_echo[ech][i]=0.0;
        echo_way[ech][i]=0;
        tmp_falling_from_level[ech][i]=0.0;
        snap_echo_to_recall[ech][i]=0.0;
    }
    do_bounce[ech]=0;//d�clencheur

    for (int f=0; f<48; f++)
    {
        fader_before_bounce[f]=Fader[f];
    }




    return(0);
}
