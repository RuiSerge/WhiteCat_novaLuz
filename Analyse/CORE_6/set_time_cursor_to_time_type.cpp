int set_time_cursor_to_time_type(int the_time_wheel_datatype)
{
    switch(time_wheel_datatype_is)
    {
    case 0://minutes
        angle_timesnap=angle_timesnap_min;
        break;
    case 1://secondes
        angle_timesnap=angle_timesnap_sec;
        break;
    case 2://dixiemes
        angle_timesnap=angle_timesnap_dix;
        break;
     default:break;
    }
    time_angle=angle_timesnap;
    refresh_time_cursor();

    if(time_wheel_datatype_is==0) {}
    if(time_wheel_datatype_is==1)
    {
        angle_timesnap_sec+=(5.980005/60/2);
    }
    return(0);
}
