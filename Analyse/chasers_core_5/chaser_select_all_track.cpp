int chaser_select_all_track(int numchase)
{
    for (int co=0; co<core_user_define_nb_tracks_per_chasers; co++)
    {
        track_is_on[numchase][co]=1;
    }
    sprintf(string_Last_Order,">> ALL tracks ON in Chaser %d",numchase+1);
    return(0);
}
