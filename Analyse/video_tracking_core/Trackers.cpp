int Trackers()
{
    index_count_trackers=0;
    float tracker_vel;

    for (int Tr=0; Tr<12; Tr++)
    {
        if(tracking_spaces_on_off[tracking_dock_selected][Tr]==1)
        {
            index_count_trackers++;
            tracker_target_val[tracking_dock_selected][Tr]=Filter_Image(tracking_coordonates[tracking_dock_selected][Tr][0],tracking_coordonates[tracking_dock_selected][Tr][1], tracking_coordonates[tracking_dock_selected][Tr][2], tracking_coordonates[tracking_dock_selected][Tr][3]+1) ;
            tracker_vel = (tracker_target_val[tracking_dock_selected][Tr] - tracker_val[tracking_dock_selected][Tr])*tracker_decay_constant;
            if(tracker_decay_constant<1)
            {
                tracker_val[tracking_dock_selected][Tr] += ((tracker_vel*tracker_dt)*0.1);
            }
            else
            {
                tracker_val[tracking_dock_selected][Tr] += (tracker_vel*tracker_dt);
            }
            tracker_level[tracking_dock_selected][Tr]=(int)(tracker_val[tracking_dock_selected][Tr]);
        }
    }
    return(0);
}
