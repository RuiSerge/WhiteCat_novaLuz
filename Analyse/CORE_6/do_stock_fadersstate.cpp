int do_stock_fadersstate(bool fads, bool speeds, bool locks, bool lfos, bool loops)
{
    stockage_all_at_zero_state[0]=fads;
    stockage_all_at_zero_state[1]=speeds;
    stockage_all_at_zero_state[2]=locks;
    stockage_all_at_zero_state[3]=lfos;
    stockage_all_at_zero_state[4]=loops;
    for (int pe=0; pe<core_user_define_nb_faders; pe++)
    {
        SnapFader[pe]=0;
        Snaplfo_speed[pe]=64;
        SnapFaderLocked[pe]=0;
        Snaplfo_mode_is[pe]=0;//no lfo
        Snaplfo_cycle_is_on[pe]=0;//saw
        Snaplfo_cycle_steps[pe]=0;
        Snaplfo_do_next_step[pe][0]=0;
        Snaplfo_do_next_step[pe][1]=0;
        for(int d=0; d<core_user_define_nb_docks; d++)
        {
            Snapis_dock_for_lfo_selected[pe][d]=0;
        }
    }

    for (int p=0; p<core_user_define_nb_faders; p++)
    {
        if(fads==1)
        {
            SnapFader[p]=Fader[p];
        }
        if(speeds==1)
        {
            Snaplfo_speed[p]=lfo_speed[p];
        }
        if(locks==1)
        {
            SnapFaderLocked[p]=FaderLocked[p];
        }
        if(lfos==1)
        {
            Snaplfo_mode_is[p]=lfo_mode_is[p];//no lfo
            Snaplfo_cycle_is_on[p]=lfo_cycle_is_on[p];//saw
            Snaplfo_cycle_is_on[p]=lfo_cycle_steps[p];
            Snaplfo_do_next_step[p][0]=lfo_do_next_step[p][0];
            Snaplfo_do_next_step[p][1]=lfo_do_next_step[p][1];
        }
        //sab 02/03/2014 ATTENTION CHANGE COMPORTEMENT - COMMENT TESTER ? if(loops=1)
        if(loops==1)
        {
            for(int d=0; d<core_user_define_nb_docks; d++)
            {
                Snapis_dock_for_lfo_selected[p][d]=is_dock_for_lfo_selected[p][d];
            }
        }
    }
    sprintf(string_Last_Order,">>All at Zero: pasted previous state");
    reset_midi_receiver_array();
    return(0);
}
