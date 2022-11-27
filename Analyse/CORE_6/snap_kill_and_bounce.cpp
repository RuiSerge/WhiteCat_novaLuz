int snap_kill_and_bounce(int echo, int f)
{
    if(f>0 && f<=48 )
    {
        snap_fader_state(echo, f) ;

        //si le fader est en train de jouer en LFO, christoph 19/12/14
        if( lfo_mode_is[f]!=0)
        {
            lfo_mode_is[f]=0;
        }
        if ( lfo_cycle_is_on[f]!=0)
        {
            lfo_cycle_is_on[f]=0;
        }

        Fader[f]=0;
        do_bounce[echo]=0;
        bounce_is_prepared[echo]=0;
        prepare_bounce(echo);
        do_bounce[echo]=1;
    }
    return(0);
}
