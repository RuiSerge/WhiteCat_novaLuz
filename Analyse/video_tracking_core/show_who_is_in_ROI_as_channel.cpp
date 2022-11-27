int show_who_is_in_ROI_as_channel(int roipreset, int dock_tracker_selected)
{
for (int co=1;co<513;co++)
{
show_who_is_in_FADER_DOCK[co]= tracking_contents[roipreset][dock_tracker_selected][co];
}
return(0);
}
