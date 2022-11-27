int ShowTrackers()
{
char num_tr[4];
 for (int Tr=0;Tr<12;Tr++)
{
if(tracking_spaces_on_off[tracking_dock_selected][Tr]==1)
{
Rect Tracker(Vec2D (videoX+tracking_coordonates[tracking_dock_selected][Tr][0]+15, videoY+tracking_coordonates[tracking_dock_selected][Tr][1]+61 ),
             Vec2D (tracking_coordonates[tracking_dock_selected][Tr][2],tracking_coordonates[tracking_dock_selected][Tr][3]));
sprintf(num_tr,"%d",Tr+1);
circuitlevel.Print(num_tr,videoX+tracking_coordonates[tracking_dock_selected][Tr][0]+20,videoY+tracking_coordonates[tracking_dock_selected][Tr][1]+75);
Tracker.DrawOutline(CouleurFader);

if(tracker_to_edit==Tr && (edit_tracker==1 || move_tracker==1))
{
Tracker.DrawOutline(CouleurBlind);
petitchiffrerouge.Print(num_tr,videoX+tracking_coordonates[tracking_dock_selected][Tr][0]+10,videoY+tracking_coordonates[tracking_dock_selected][Tr][1]+55);
Rect Background_Editor(Vec2D(videoX+15, videoY+70),Vec2D(video_size_x,40));
Background_Editor.SetRoundness(7.5);
Background_Editor.Draw(CouleurFond.WithAlpha(0.4));
petitchiffrerouge.Print(string_tracker_edited_dat,videoX+20,videoY+90);
}
}
}

return(0);
}
