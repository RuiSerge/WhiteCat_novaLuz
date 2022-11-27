int InitVideo()
{
g_capture= cvCreateCameraCapture(0); //selection manuelle // 0 toutescvCaptureFromCAM(0);

if(g_capture!=0)
{
fps_video_rate=cvGetCaptureProperty( g_capture, CV_CAP_PROP_FPS);
set_camera_size();
set_image_caches();
camera_is_on=1;
sprintf(string_Last_Order,">>Camera %d x %d FPS: %d ", video_size_x,video_size_y,fps_video_rate) ;
}

else {sprintf(string_Last_Order,">>No Camera recognized !");}
save_load_print_to_screen(string_Last_Order);
return(0);
}
