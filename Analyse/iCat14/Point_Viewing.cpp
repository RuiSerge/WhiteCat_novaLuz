int Point_Viewing(int macx,int macy)
{

    char info_point[64];
    sprintf(info_point,"Accelerometer: %.3f %.3f %.3f",fs_accelerometer[0],fs_accelerometer[1],fs_accelerometer[2]);
    petitpetitchiffre.Print(info_point,macx,macy);

    petitchiffrerouge.Print("Points:",macx,macy+10);
    for(int poin=0; poin<fs_max_points; poin++)
    {
        sprintf(info_point,"%d/B:%d-%d M:%d-%d E:%d-%d",(poin+1),
                FS_touch_point_begin[0][poin],FS_touch_point_begin[1][poin],
                FS_touch_point_move[0][poin],FS_touch_point_move[1][poin],
                FS_touch_point_end[0][poin],FS_touch_point_end[0][poin]);
        petitpetitchiffre.Print(info_point,macx,macy+20+(poin*12));
    }
    return(0);
}
