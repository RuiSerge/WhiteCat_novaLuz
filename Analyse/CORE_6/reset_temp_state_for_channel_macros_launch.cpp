int reset_temp_state_for_channel_macros_launch()
{
    for(int i=0; i<514; i++)
    {
        previous_state_of_outputted_channels[i]=-1;
    }
    return(0);
}
