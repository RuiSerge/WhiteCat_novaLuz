int do_logical_Edit_Tracker_Size(int dock_selected, int tracker_selected)
{
    if(mouse_x>videoX+tracking_coordonates[dock_selected][tracker_selected][0] && mouse_x<(videoX+15+video_size_x) && mouse_y>videoY+61+tracking_coordonates[dock_selected][tracker_selected][1] && mouse_y<(videoY+video_size_y+61))
    {
        tracking_coordonates[dock_selected][tracker_selected][2]= mouse_x-((videoX+15)+tracking_coordonates[dock_selected][tracker_selected][0]) ;
        tracking_coordonates[dock_selected][tracker_selected][3]= mouse_y-((videoY+61)+tracking_coordonates[dock_selected][tracker_selected][1]) ;
        if( tracking_coordonates[dock_selected][tracker_selected][2]<1)
        {
            tracking_coordonates[dock_selected][tracker_selected][2]=1;
        }
        if( tracking_coordonates[dock_selected][tracker_selected][3]<1)
        {
            tracking_coordonates[dock_selected][tracker_selected][3]=1;
        }
    }
    sprintf(string_tracker_edited_dat,"X: %d Y: %d Size X: %d Size Y: %d",tracking_coordonates[dock_selected][tracker_selected][0],tracking_coordonates[dock_selected][tracker_selected][1],tracking_coordonates[dock_selected][tracker_selected][2],tracking_coordonates[dock_selected][tracker_selected][3]);
    return(0);
}
