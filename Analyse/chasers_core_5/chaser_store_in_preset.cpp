int chaser_store_in_preset(int numchaser, int presettrk)
{
for(int tr=0;tr<core_user_define_nb_tracks_per_chasers;tr++)
{
chaser_preset[numchaser][presettrk][tr] =track_is_on[numchaser][tr];    //bool chaser_preset[128][4][24];
}
sprintf(string_Last_Order,">> Stored ON Tracks from Chaser %d in Preset %d",numchaser+1,presettrk+1);
 return(0);
}
