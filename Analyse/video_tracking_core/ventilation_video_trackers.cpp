int ventilation_video_trackers()
{
for(int aff_ch_trt=0;aff_ch_trt<512;aff_ch_trt++)
{
for (int Tr=0;Tr<12;Tr++)
{
if(tracking_spaces_on_off[tracking_dock_selected][Tr]==1)
{
if( tracking_contents[tracking_dock_selected][Tr][aff_ch_trt]==1)
{
buffer_tracker[aff_ch_trt]=tracker_level[tracking_dock_selected][Tr];}
}
}
}
 return(0);
}
