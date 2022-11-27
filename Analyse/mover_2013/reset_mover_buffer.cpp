int reset_mover_buffer()
{
    for(int i=0; i<512; i++)
    {
        buffer_moving_head[i]=0;
    }
    return(0);
}
