int set_chaser_tempo_unit( int the_chas)
{
    time_unit[the_chas]=tap_tempo_average;
    if(time_unit[the_chas]<=0.0001)
    {
        time_unit[the_chas]=0.0001;
    }
    sprintf(string_Last_Order,"Received Tap Tempo in Chaser %d", the_chas+1);
    return(0);
}
