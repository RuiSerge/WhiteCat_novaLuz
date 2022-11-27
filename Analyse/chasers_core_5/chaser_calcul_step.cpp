int chaser_calcul_step(int numchaser, float ratio_for_no_reset)
{
    chaser_start_of_step[numchaser]=actual_time+((time_unit[numchaser]*((float)BPS_RATE))*ratio_for_no_reset);
    chaser_end_of_step[numchaser]=actual_time+((time_unit[numchaser]*chaser_slaviness[numchaser])*((float)BPS_RATE));
    chaser_time_position[numchaser]=actual_time;
    refresh_launchpad_on_chaser();
    return(0);
}
