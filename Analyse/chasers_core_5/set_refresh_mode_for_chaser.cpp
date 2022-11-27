int set_refresh_mode_for_chaser(bool value)
{
midi_send_out[995]=value;
midi_send_out[996]=value;
midi_send_out[997]=value;
for(int num_track=0;num_track<23;num_track++)//on off hors launchpad
{
midi_send_out[998+num_track]=1;
}
return(0);
}
