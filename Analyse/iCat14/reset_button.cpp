int reset_button(int page, int but, int tp)
{
button_is_touched[page][but]=0;
button_is_controlled_by_point[page][but]=0;
FS_touch_point_begin[0][tp]=-999;FS_touch_point_begin[1][tp]=-999;
FS_touch_point_end[0][tp]=-999;FS_touch_point_end[1][tp]=-999;
FS_touch_point_move[0][tp]=-999;FS_touch_point_move[1][tp]=-999;
return(0);
}
