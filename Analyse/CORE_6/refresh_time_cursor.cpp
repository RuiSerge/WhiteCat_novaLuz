int refresh_time_cursor()
{
    vtimex = cos(time_angle)*100;//timerayon
    vtimey = sin(time_angle)*100;
    position_curseur_time_x= xtime_window+150+vtimex;
    position_curseur_time_y=ytime_window+150+vtimey ;
    return(0);
}
