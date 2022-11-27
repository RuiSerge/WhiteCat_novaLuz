int chaser_select_inv_track(int numchase)
{
for (int co=0;co<core_user_define_nb_tracks_per_chasers;co++)
{
track_is_on[numchase][co]=toggle(track_is_on[numchase][co]);
}
sprintf(string_Last_Order,">> INVERSE ON-OFF tracks in Chaser %d",numchase+1);
return(0);
}
