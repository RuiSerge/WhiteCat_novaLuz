int do_recall_fadersstate(bool fads, bool speeds, bool locks, bool lfos, bool loops)
{
    for (int p=0; p<core_user_define_nb_faders; p++)
    {
        if(minifaders_selected[p]==1)
        {
            if(fads==1)
            {
                fader_set_level(p,SnapFader[p]);
                /*Fader[p]=SnapFader[p];
                midi_levels[p]=(int)((float)(SnapFader[p])/2);
                index_send_midi_out[p]=1;*/
            }
            if(speeds==1)
            {
                lfo_speed[p]=Snaplfo_speed[p];
                midi_levels[196+p]=Snaplfo_speed[p];
                index_send_midi_out[196+p]=1;
            }
            if(locks==1)
            {
                FaderLocked[p]=SnapFaderLocked[p];
            }
            if(lfos==1)
            {
                lfo_mode_is[p]=Snaplfo_mode_is[p];//no lfo
                lfo_cycle_is_on[p]=Snaplfo_cycle_is_on[p];//saw
                lfo_cycle_steps[p]=Snaplfo_cycle_is_on[p];
                lfo_do_next_step[p][0]=Snaplfo_do_next_step[p][0];
                lfo_do_next_step[p][1]=Snaplfo_do_next_step[p][1];
            }
            //sab 02/03/2014 ATTENTION CHANGE COMPORTEMENT - COMMENT TESTER ? if(loops=1)
            if(loops==1)
            {
                for(int d=0; d<core_user_define_nb_docks; d++)
                {
                    is_dock_for_lfo_selected[p][d]=Snapis_dock_for_lfo_selected[p][d];
                }
            }
        }
    }
    sprintf(string_Last_Order,">>All at Zero: recall done");

    stockage_all_at_zero_state[0]=0;
    stockage_all_at_zero_state[1]=0;
    stockage_all_at_zero_state[2]=0;
    stockage_all_at_zero_state[3]=0;
    stockage_all_at_zero_state[4]=0;

    return(0);
}
