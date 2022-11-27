int clear_ground_levels(int ech)
{
    for(int i=0; i<512; i++)
    {
        echo_levels[ech][1][i]=0.0;
    }


    return(0);
}
