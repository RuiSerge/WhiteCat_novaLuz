int minifader_selection_record(int mf_preset_is)
{
    for(int olp=0; olp<core_user_define_nb_faders; olp++)
    {
        minifaders_preset_selection[mf_preset_is][olp]=minifaders_selected[olp];
    }
    index_do_dock=0;
    sprintf(string_Last_Order,"Recorded Fader Selection in Preset %d", mf_preset_is+1);
    return(0);
}
