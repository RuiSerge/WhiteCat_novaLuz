int chaser_select_off_all_track(int numchase)
{
for (int co=0;co<core_user_define_nb_tracks_per_chasers;co++)
{
track_is_on[numchase][co]=0;
}
sprintf(string_Last_Order,">> ALL tracks OFF in Chaser %d",numchase+1);
 return(0);
}
