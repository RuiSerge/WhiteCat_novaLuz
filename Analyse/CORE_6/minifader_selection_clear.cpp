int minifader_selection_clear(int mf_preset_is)
{
    for(int olp=0; olp<core_user_define_nb_faders; olp++)
    {
        minifaders_preset_selection[mf_preset_is][olp]=0;
    }
    index_main_clear=0;
    sprintf(string_Last_Order,"Cleared Fader Selection in Preset %d", mf_preset_is+1);
    return(0);
}
