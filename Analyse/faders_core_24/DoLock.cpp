int DoLock(int masterfader, int locklevel)
{
    for ( int fi=0; fi<core_user_define_nb_faders; fi++)
    {
        OldFaderLockProc[fi]=Fader[fi];
        if(FaderLocked[fi]==1 && fi!=masterfader)
        {
            Fader[fi]=(unsigned char)((((float)(StateOfFaderBeforeLock[fi]))/255)*locklevel);
            midi_levels[fi]=(int)(((float)Fader[fi])/2);
            if( OldFaderLockProc[fi]!=Fader[fi])
            {
                index_send_midi_out[fi]=1;
            }
            if(DockTypeIs[fi][dock_used_by_fader_is[fi]]==10)
            {
                index_fader_is_manipulated[fi]=1;
            }
        }
    }
    return(0);
}
