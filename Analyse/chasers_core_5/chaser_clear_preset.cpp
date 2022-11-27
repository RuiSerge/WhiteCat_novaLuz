int chaser_clear_preset(int numchaser, int presettrk)
{
    for(int tr=0; tr<core_user_define_nb_tracks_per_chasers; tr++)
    {
        chaser_preset[numchaser][presettrk][tr] =0;    //bool chaser_preset[128][4][24];
    }
    return(0);
}
