int do_lock_preset(int num_preset)
{
    lock_preset[num_preset]=toggle(lock_preset[num_preset]);
    if(lock_preset[num_preset]==1)
    {
        for (int ipo=0; ipo<8; ipo++)
        {
            lock_preset[ipo]=0;
        }
        lock_preset[num_preset]=1;
        for (int f=0; f<core_user_define_nb_faders; f++)
        {
            /*ancienne version: le master fader pas mis � full
            FaderLocked[f]=FaderLocked_Preset[ num_preset][f];
            StateOfFaderBeforeLock[f]=StateOfFaderBeforeLock_Preset[num_preset][f];
            LockFader_is_FullLevel[f]=LockFader_is_FullLevel_Preset[num_preset][f];*/
            if(LockFader_is_FullLevel_Preset[num_preset][f]==1)
            {
                Fader[f]=255;
                midi_levels[f]=127;
                if(midi_send_out[f]==1)
                {
                    index_send_midi_out[f]=1;
                }
                StateOfFaderBeforeLock[f]=255;
            }
            else //rajout 0.7.6
            {
                lfo_cycle_is_on[f]=0;
                lfo_mode_is[f]=0;
            }
            FaderLocked[f]=FaderLocked_Preset[ num_preset][f];
            StateOfFaderBeforeLock[f]=Fader[f];
            LockFader_is_FullLevel[f]=LockFader_is_FullLevel_Preset[num_preset][f];
        }
    }
    else  if(lock_preset[num_preset]==0)
    {
        for (int f=0; f<core_user_define_nb_faders; f++)
        {
            FaderLocked[f]=0;
        }
    }
    return(0);
}
