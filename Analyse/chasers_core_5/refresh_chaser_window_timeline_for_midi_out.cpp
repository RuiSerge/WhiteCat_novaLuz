int refresh_chaser_window_timeline_for_midi_out()
{
if( refresh_midi_chasers==1 && (int)(((float)(chaser_step_is[chaser_selected])/36)*127)!=midi_levels[997])
{
midi_levels[997]=(int)(((float)(chaser_step_is[chaser_selected])/36)*127);
index_send_midi_out[997]=1;
}
 return(0);
}
