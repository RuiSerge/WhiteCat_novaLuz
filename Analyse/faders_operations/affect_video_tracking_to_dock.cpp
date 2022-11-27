int  affect_video_tracking_to_dock(int faa, int docc)
{
ClearDock(faa,docc);
DockTypeIs[faa][docc]=4;
return(0);
}
