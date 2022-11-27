int get_current_time()
{
    time_t timestamp;
    struct tm * t;
    timestamp = time(NULL);
    t = localtime(&timestamp);


    sprintf(tmp_time,"%02uh %02umin %02usec", t->tm_hour, t->tm_min, t->tm_sec);

    return(0);
}
