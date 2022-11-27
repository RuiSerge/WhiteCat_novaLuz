int tracking_print_to_screen()
{
Rect backim(Vec2D(videoX+15,videoY+61),Vec2D(video_size_x,video_size_y));
backim.DrawOutline(CouleurLigne);
if(g_capture!=0 && camera_is_on==1 && manipulating_camera==0  )
{
                   frame = cvQueryFrame(g_capture);

                   if(flip_image==1)
                   {cvConvertImage(frame,frame,CV_CVTIMG_FLIP);}
                   cvCvtColor(frame,onech_temoin,CV_BGR2GRAY);//recup dans un grayscale du actual frame

                   Trackers();

                   cvAddWeighted(onech_temoin,1.0,onech_difference,1.0,0.0,onech_temoin);
                   cvCopy(onech_temoin,affichage);//opencv2.0


Point::StartFastDrawing();

                   for(int pix_x=0; pix_x<video_size_x;pix_x++)
                   {
                   for(int pix_y=0;pix_y<video_size_y;pix_y++)
                   {
                   recup_val_pix_video=(int)cvGetReal1D(affichage,pix_x+(pix_y*video_size_x));
                   Rgba CouleurPixel(recup_val_pix_video,recup_val_pix_video,recup_val_pix_video);
                   Point( Vec2D(videoX+15+pix_x,videoY+61+pix_y)).DrawFast(CouleurPixel);
                   }
                   }
Point::FinishFastDrawing();
}
 return(0);
}
