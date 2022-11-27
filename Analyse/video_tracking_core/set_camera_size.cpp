int set_camera_size()
{
    manipulating_camera=1;
    mouse_released=1;
    video_size_x=camera_size_array[camera_size_settings_is][0];
    video_size_y=camera_size_array[camera_size_settings_is][1];

    cvSetCaptureProperty( g_capture, CV_CAP_PROP_FRAME_WIDTH,video_size_x);
    cvSetCaptureProperty( g_capture, CV_CAP_PROP_FRAME_HEIGHT,video_size_y);

    rest(1000);
    manipulating_camera=0;

    return(0);
}
