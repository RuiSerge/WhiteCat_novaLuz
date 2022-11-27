int set_image_caches()
{

frame=cvQueryFrame(g_capture);
frame    = cvCreateImage(cvSize(video_size_x,video_size_y), IPL_DEPTH_8U ,3);// 8 bits 3 couches color
affichage   =  cvCreateImage(cvSize(video_size_x,video_size_y), IPL_DEPTH_8U ,1);// 8 bits 1 couches color AFFICHAGE final
onech_temoin=cvCreateImage(cvSize(video_size_x,video_size_y), IPL_DEPTH_8U ,1);
onech_difference=cvCreateImage(cvSize(video_size_x,video_size_y), IPL_DEPTH_8U ,1);
onech_snap_background=cvCreateImage(cvSize(video_size_x,video_size_y), IPL_DEPTH_8U ,1);


return(0);
}
