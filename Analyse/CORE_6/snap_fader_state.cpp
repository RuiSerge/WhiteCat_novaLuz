int  snap_fader_state(int echo, int f)
{
    if(f>0 && f<=48 && calculation_on_faders_done==1)
    {
        for(int i=1; i<513; i++)
        {
            if(((float)(FaderDoDmx[f][i]))/255>=echo_levels[echo][1][i-1])//si plancher
            {
                echo_levels[echo][0][i-1]=((float)(FaderDoDmx[f][i]))/255;//((float)(FaderDockContains[f][dock_used_by_fader_is[f]][i]))/255;
                snap_echo_to_recall[echo][i-1]=echo_levels[echo][0][i-1];
            }
        }
        if(Fader[f]!=0)
        {
            fader_before_bounce[f]=Fader[f];
        }
        recall_channel_state_in_an_echo(echo);
        prepare_bounce(echo);
    }
    return(0);
}
