int do_logical_Move_Tracker(int dock_selected,int tracker_selected)
{
    if(mouse_x>videoX+15 && mouse_x<(videoX+15+video_size_x) && mouse_y>videoY+61 && mouse_y<(videoY+video_size_y+61))
    {
        tracking_coordonates[dock_selected][tracker_selected][0]= mouse_x-(videoX+15)-(tracking_coordonates[dock_selected][tracker_selected][2]/2 );
        tracking_coordonates[dock_selected][tracker_selected][1]= mouse_y-(videoY+61)-(tracking_coordonates[dock_selected][tracker_selected][3]/2 ) ;
    }
    sprintf(string_tracker_edited_dat,"X: %d Y: %d Size X: %d Size Y: %d",tracking_coordonates[dock_selected][tracker_selected][0],tracking_coordonates[dock_selected][tracker_selected][1],tracking_coordonates[dock_selected][tracker_selected][2],tracking_coordonates[dock_selected][tracker_selected][3]);
    return(0);
}
