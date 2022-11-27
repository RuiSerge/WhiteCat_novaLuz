int minifader_lockselection_record(int mf_preset_is)
{
    for(int f=0; f<core_user_define_nb_faders; f++)
    {
        FaderLocked_Preset[ mf_preset_is][f]=0;        //reset des �tats avant stockage
        StateOfFaderBeforeLock_Preset[ mf_preset_is][f]=0;
        LockFader_is_FullLevel_Preset[ mf_preset_is][f]=0;
        if ( FaderLocked[f]==1)
        {
            FaderLocked_Preset[ mf_preset_is][f]=FaderLocked[f];
            StateOfFaderBeforeLock_Preset[ mf_preset_is][f]=StateOfFaderBeforeLock[f];
            LockFader_is_FullLevel_Preset[ mf_preset_is][f]=LockFader_is_FullLevel[f];
        }
    }
    for (int ipo=0; ipo<8; ipo++)
    {
        lock_preset[ipo]=0;
    }
    lock_preset[ mf_preset_is]=1;

    index_do_dock=0;
    sprintf(string_Last_Order,">> Lock State %d recorded", mf_preset_is+1);
    return(0);
}
