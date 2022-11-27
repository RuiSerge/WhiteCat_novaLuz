int clear_banger(int bg)
{
    bang_is_sended[bg]=1;
    strcpy(bangers_name[bg],"");

    bangers_name[bg][24]='\n';

    do_loop_banger[bg]=0;
    time_loop_banger[bg]=0.0;
    ticker_loop_banger[bg]=0;
    strcpy(string_alarm[bg],"");

    for(int dd=0; dd<6; dd++)
    {
        bangers_type[bg][dd]=0;//127 bangers // 6 events par banger
        bangers_action[bg][dd]=0;//num action demand�e
        bangers_params[bg][dd][0]=0;//0 param1 / 1 param2
        bangers_params[bg][dd][1]=0;
        bangers_delay[bg][dd]=0.0;//delays
    }

    return(0);
}
