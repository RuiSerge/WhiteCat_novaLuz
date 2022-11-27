int reset_banger_event( int banger_selected, int event)
{
    bangers_action[banger_selected][ event]=0;
    reset_banger_params(banger_selected,event);
    return(0);
}
