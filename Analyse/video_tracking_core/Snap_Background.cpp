int Snap_Background()
{
    cvCvtColor(frame,onech_snap_background,CV_BGR2GRAY);
    index_snap_background=0;
    return(0);
}
