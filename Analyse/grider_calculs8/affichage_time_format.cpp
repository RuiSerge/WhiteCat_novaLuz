int affichage_time_format(float time_in_sec)
{
    float time_in_min = time_in_sec / 60.0 ;
    int   time_minutes  = trunc(time_in_min) ;
    float time_secondes = time_in_sec - (time_minutes * 60.0) ;

    sprintf(string_conversion_timeis, "%d..%.2f", time_minutes, time_secondes);

    return(0);
}
