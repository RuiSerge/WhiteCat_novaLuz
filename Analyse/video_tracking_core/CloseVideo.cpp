int CloseVideo()
{
    if(g_capture!=0)
    {
        cvReleaseCapture(&g_capture);
    }
    sprintf(string_Last_Order,">>Camera Closed");
    camera_is_on=0;
    return(0);
}
