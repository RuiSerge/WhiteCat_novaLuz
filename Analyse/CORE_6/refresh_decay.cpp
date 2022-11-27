int refresh_decay()
{
    if(index_decay_tracker<0)
    {
        index_decay_tracker=0;
    }
    else if(index_decay_tracker>127)
    {
        index_decay_tracker=127;
    }
    tracker_decay_constant=(float)(index_decay_tracker)/127;
    return(0);
}
