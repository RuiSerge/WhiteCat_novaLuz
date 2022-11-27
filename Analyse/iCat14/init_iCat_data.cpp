int init_iCat_data()
{

    for(int i=0; i<48; i++)
    {
        before_check_button_state[i]=0;
        check_button_state[i]=0;
    }
    for(int tp=0; tp<fs_max_points; tp++)
    {
        FS_touch_point_begin[0][tp]=-999;
        FS_touch_point_begin[1][tp]=-999;
        FS_touch_point_move[0][tp]=-999;
        FS_touch_point_move[1][tp]=-999;
        FS_touch_point_end[0][tp]=-999;
        FS_touch_point_end[1][tp]=-999;
    }



    return(0);
}
