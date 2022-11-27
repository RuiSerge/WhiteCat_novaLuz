int affect_to_tracker(int dock_selected,int tracker_selected)
{
    if(index_do_dock==1)
    {
        for(int affe=1; affe<512; affe++)
        {
            tracking_contents[dock_selected][tracker_selected][affe]=Selected_Channel[affe];
        }
        index_do_dock=0;
    }

    else if(index_do_modify==1)
    {
        for(int affe=1; affe<512; affe++)
        {
            if(Selected_Channel[affe]==1)
            {
                if(tracking_contents[dock_selected][tracker_selected][affe]==1)
                {
                    tracking_contents[dock_selected][tracker_selected][affe]=0;
                }
                else if(tracking_contents[dock_selected][tracker_selected][affe]==0)
                {
                    tracking_contents[dock_selected][tracker_selected][affe]=1;
                }

            }
        }
        Unselect_all_channels();
        index_do_modify=0;
    }

    else if(index_do_report==1)
    {
        for(int affe=1; affe<512; affe++)
        {
            tracking_contents[dock_selected][tracker_selected][affe]=0;
            if(bufferSaisie[affe]>0 || bufferFaders[affe]>0)
            {
                tracking_contents[dock_selected][tracker_selected][affe]=1;
            }
        }
        Unselect_all_channels();
        index_do_report=0;
    }
    sprintf(string_Last_Order,">>Affected CH to Tracker %d TrackingDock %d",dock_selected,tracker_selected);
    return(0);
}
