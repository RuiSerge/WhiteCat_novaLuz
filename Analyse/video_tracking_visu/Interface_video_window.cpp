int Interface_video_window(int WindowVideoX,int WindowVideoY)
{
if(video_size_x>320 && video_size_y>240)//taille de l image video grab�e
{
frame_video_x=video_size_x; frame_video_y=video_size_y;
}
else {frame_video_x=345; frame_video_y=240;}

Rect VideoBackground(Vec2D ( WindowVideoX, WindowVideoY ), Vec2D ( frame_video_x+35,frame_video_y+460));
VideoBackground.SetRoundness(15);
VideoBackground.SetLineWidth(triple_epaisseur_ligne_fader);
VideoBackground.Draw(CouleurFond);
if(window_focus_id==904)
{
VideoBackground.DrawOutline(CouleurFader);
}
else
{
VideoBackground.DrawOutline(CouleurLigne);
}


Rect FrameT(Vec2D(WindowVideoX, WindowVideoY), Vec2D (50,15));

char stmp[16];
for (int i=0;i<2;i++)
{
FrameT.MoveTo(Vec2D(WindowVideoX+90+(i*60), WindowVideoY+10));
if(i==camera_size_settings_is){FrameT.DrawOutline(CouleurFader);}
FrameT.DrawOutline(CouleurLigne.WithAlpha(0.5));
sprintf(stmp,"%dx%d", camera_size_array[i][0],camera_size_array[i][1]);
minichiffre.Print(stmp, WindowVideoX+95+(i*60),WindowVideoY+20);
}

sprintf(stmp,"FPS: %d",fps_video_rate);
petitchiffre.Print(stmp,WindowVideoX+300,WindowVideoY+20);

if(manipulating_camera==0)
{
tracking_print_to_screen();
ShowTrackers();
}
char chif_ttr[4];
for(int trZ=0;trZ<6;trZ++)
{
sprintf(chif_ttr,"%d",tracker_level[tracking_dock_selected][trZ]);
petitchiffre.Print(chif_ttr,videoX+30+(trZ*60),videoY+61+video_size_y+15);
sprintf(chif_ttr,"%d",tracker_level[tracking_dock_selected][trZ+6]);
petitchiffre.Print(chif_ttr,videoX+30+(trZ*60),videoY+61+video_size_y+35);
}


for (int ct=0;ct<6;ct++)
{
Rect Tracker(Vec2D(WindowVideoX+20+(ct*60), WindowVideoY+frame_video_y+200), Vec2D ( 50,30));
Tracker.SetRoundness(10);
Tracker.SetLineWidth(epaisseur_ligne_fader);
Tracker.DrawOutline(CouleurLigne);
if(tracking_spaces_on_off[tracking_dock_selected][ct]==1)
{
Tracker.Draw(CouleurFader);
 if(tracker_to_edit==ct && (edit_tracker==1 || move_tracker==1))
 {Tracker.Draw(CouleurBlind);}
 Tracker.DrawOutline(CouleurFader);
}

Rect TrackerTwo(Vec2D(WindowVideoX+20+(ct*60), WindowVideoY+frame_video_y+250), Vec2D ( 50,30));
TrackerTwo.SetRoundness(10);
TrackerTwo.SetLineWidth(epaisseur_ligne_fader);
TrackerTwo.DrawOutline(CouleurLigne);
if(tracking_spaces_on_off[tracking_dock_selected][ct+6]==1)
{
TrackerTwo.Draw(CouleurFader);
 if(tracker_to_edit==(ct+6) && (edit_tracker==1 || move_tracker==1) )
 {TrackerTwo.Draw(CouleurBlind);}
 TrackerTwo.DrawOutline(CouleurFader);
}
sprintf(chif_ttr,"%d",ct+1);
petitchiffre.Print(chif_ttr,WindowVideoX+35+(ct*60),WindowVideoY+frame_video_y+220);
sprintf(chif_ttr,"%d",ct+7);
petitchiffre.Print(chif_ttr,WindowVideoX+35+(ct*60),WindowVideoY+frame_video_y+270);

if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_x> WindowVideoX+20+(ct*60) && mouse_x< WindowVideoX+70+(ct*60))
{
        if(mouse_y>WindowVideoY+frame_video_y+200 && mouse_y<WindowVideoY+frame_video_y+230)
        {
        Tracker.DrawOutline(CouleurBlind);
        }
        else if(mouse_y>WindowVideoY+frame_video_y+250 && mouse_y<WindowVideoY+frame_video_y+280)
        {TrackerTwo.DrawOutline(CouleurBlind);}
}
}
}

Rect OcvMode(Vec2D(WindowVideoX+30, WindowVideoY+frame_video_y+150),Vec2D(60,30));
OcvMode.SetRoundness(7.5);
OcvMode.SetLineWidth(epaisseur_ligne_fader);
OcvMode.Draw(CouleurFond);
switch (ocv_calcul_mode)
{
case 0:
OcvMode.Draw(CouleurFader);
sprintf(string_ocv_mode,"SUPPR.");
break;
case 1:
sprintf(string_ocv_mode," NONE");
break;
default: break;
}
petitchiffre.Print(string_ocv_mode,WindowVideoX+35,WindowVideoY+frame_video_y+170);
OcvMode.DrawOutline(CouleurLigne);

Rect TakeSnap(Vec2D (WindowVideoX+100, WindowVideoY+frame_video_y+150 ), Vec2D (60,30));
TakeSnap.SetRoundness(7.5);
TakeSnap.SetLineWidth(epaisseur_ligne_fader);
TakeSnap.DrawOutline(CouleurLigne);
petitchiffre.Print("SNAP",WindowVideoX+110,WindowVideoY+frame_video_y+170);

Rect FilteringOn(Vec2D(WindowVideoX+180, WindowVideoY+frame_video_y+150), Vec2D ( 100,30));
FilteringOn.SetRoundness(10);
FilteringOn.SetLineWidth(epaisseur_ligne_fader);
if(ocvfilter_is_on==1)
{
FilteringOn.Draw(CouleurFader);
Set_Filtering_Image();
}
petitchiffre.Print("IMAGE FILTER",WindowVideoX+190,WindowVideoY+frame_video_y+170);
FilteringOn.DrawOutline(CouleurLigne);
Rect ClearMode(Vec2D(WindowVideoX+300, WindowVideoY+frame_video_y+150),Vec2D(60,30));
 ClearMode.SetRoundness(7.5);
 ClearMode.SetLineWidth(epaisseur_ligne_fader);
 ClearMode.Draw(CouleurFond);

if(tracker_clearmode==1){ClearMode.Draw(CouleurFader);}

ClearMode.DrawOutline(CouleurLigne);
petitchiffre.Print("CLEAR",WindowVideoX+310,WindowVideoY+frame_video_y+170);

petitchiffre.Print("PRESETS:",WindowVideoX+30,WindowVideoY+frame_video_y+360);
for (int ct=0;ct<5;ct++)
{
Rect DockingTracker(Vec2D(WindowVideoX+20+(ct*70), WindowVideoY+frame_video_y+370), Vec2D ( 60,30));
DockingTracker.SetRoundness(10);
DockingTracker.SetLineWidth(epaisseur_ligne_fader);

if(tracking_dock_selected==ct)
{
DockingTracker.Draw(CouleurFader);
}
DockingTracker.DrawOutline(CouleurLigne);
if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_x>WindowVideoX+20+(ct*70) && mouse_x<WindowVideoX+80+(ct*70) && mouse_y>WindowVideoY+frame_video_y+370 && mouse_y<WindowVideoY+frame_video_y+400)
{
DockingTracker.DrawOutline(CouleurBlind);
}
}

sprintf(chif_ttr,"%d",ct+1);
petitchiffre.Print(chif_ttr,WindowVideoX+40+(ct*70),WindowVideoY+frame_video_y+385);

}
petitchiffre.Print("ROI editing:",WindowVideoX+30,WindowVideoY+frame_video_y+300);

Rect EditTrack(Vec2D (WindowVideoX+30, WindowVideoY+frame_video_y+310 ), Vec2D (60,30));
EditTrack.SetRoundness(7.5);
EditTrack.SetLineWidth(epaisseur_ligne_fader);
Rect MoveTrack(Vec2D (WindowVideoX+110, WindowVideoY+frame_video_y+310 ), Vec2D (60,30));
MoveTrack.SetRoundness(7.5);
MoveTrack.SetLineWidth(epaisseur_ligne_fader);

EditTrack.DrawOutline(CouleurLigne);
MoveTrack.DrawOutline(CouleurLigne);


EditTrack.DrawOutline(CouleurLigne);
if(edit_tracker==1)
{
ocvfilter_is_on=0;
EditTrack.Draw(CouleurBlind);
EditTrack.DrawOutline(CouleurFader);
}

MoveTrack.DrawOutline(CouleurLigne);
if(move_tracker==1)
{
ocvfilter_is_on=0;
MoveTrack.Draw(CouleurFader);
MoveTrack.DrawOutline(CouleurBlind);
}

petitchiffre.Print("SIZE",videoX+45,videoY+frame_video_y+327);
petitchiffre.Print("MOVE",videoX+120,videoY+frame_video_y+327);



Rect DecaySlider( Vec2D(videoX+190+index_decay_tracker,videoY+frame_video_y+310),Vec2D(20,30));
DecaySlider.SetRoundness(5);

Rect BackSliderDecay( Vec2D(videoX+190,videoY+frame_video_y+310),Vec2D(147,30));
BackSliderDecay.SetRoundness(7.5);
BackSliderDecay.DrawOutline(CouleurLigne.WithAlpha(0.5));

Line(Vec2D(videoX+200,videoY+frame_video_y+325),Vec2D(videoX+327,videoY+frame_video_y+325)).Draw(CouleurLigne);
DecaySlider.Draw(CouleurFond);

if(mouse_x>=videoX+180 && mouse_x<=videoX+347 && mouse_y>videoY+frame_video_y+310 && mouse_y<videoY+frame_video_y+340)
{

if( Midi_Faders_Affectation_Type!=0)//config midi
{
BackSliderDecay.DrawOutline(CouleurBlind);
}
}
petitchiffre.Print("DECAY",videoX+200,videoY+frame_video_y+300);
petitchiffre.Print(ol::ToString(index_decay_tracker),videoX+250,videoY+frame_video_y+300);
DecaySlider.DrawOutline(CouleurLigne);

Circle DMidiOut(videoX+365,videoY+frame_video_y+350, 10);//box du fader
DMidiOut.SetLineWidth(epaisseur_ligne_fader);
Line (Vec2D(videoX+337,videoY+frame_video_y+330),Vec2D( videoX+352,videoY+frame_video_y+330)).Draw(CouleurLigne);
Line (Vec2D( videoX+352,videoY+frame_video_y+330),Vec2D( videoX+367,videoY+frame_video_y+350)).Draw(CouleurLigne);

DMidiOut.Draw(CouleurFond);
if(midi_send_out[498]==1)
{
DMidiOut.Draw(CouleurBlind);
}
DMidiOut.DrawOutline(CouleurLigne);

raccrochage_midi_visuel_horizontal (videoX+200,videoY+frame_video_y+310, 498,127,30);

Rect AffectVideoTo( Vec2D(videoX+(frame_video_y/2)-25,videoY+frame_video_y+417),Vec2D(130,30));
AffectVideoTo.SetRoundness(15);
AffectVideoTo.SetLineWidth(epaisseur_ligne_fader);

 if (index_affect_video_tracking_to_dock==1){AffectVideoTo.Draw(CouleurFader);}
AffectVideoTo.DrawOutline(CouleurLigne);

petitchiffre.Print("AFFECT TO DOCK",videoX+(frame_video_y/2)-10, videoY+frame_video_y+437);


return(0);
}
