int chaser_seek_at_beg(int numchase)
{
    switch(chaser_way[numchase])
    {
    case 0:
        chaser_step_is[numchase]=chaser_begin_step_is[numchase];
        break;
    case 1:
        chaser_step_is[numchase]=chaser_end_step_is[numchase];
        break;
    default:
        break;
    }
    index_progression_chaser_step[numchase]=0.0;
    chaser_calcul_step(numchase,0.0);
    chaser_calcul_time_joint(numchase);
    sprintf(string_Last_Order,">> SEEK to Begin Position Chaser %d",numchase+1);
    return(0);
}
