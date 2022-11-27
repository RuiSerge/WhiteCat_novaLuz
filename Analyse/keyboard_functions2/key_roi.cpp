int key_roi(int roi)
{
 //les aires de tracking cam
if( index_video_window==1)
{
tracking_spaces_on_off[tracking_dock_selected][roi]=toggle( tracking_spaces_on_off[tracking_dock_selected][roi]);
}
return(0);
}
