int clear_wave_slots()
{
    for(int i=0; i<26; i++)
    {
        Wave_Dampered[i].set_target_val(0.0);
    }
    return(0);
}
