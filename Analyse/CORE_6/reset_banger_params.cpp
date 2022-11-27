int reset_banger_params( int banger_selected, int event)
{
    bangers_params[banger_selected][ event][1]=0;//1 param2
    bangers_delay[banger_selected][ event]=0.0;//delays
    return(0);
}
