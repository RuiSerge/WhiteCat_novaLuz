int load_Fader_state_to_midi_array()
{
    for(int i=0; i<core_user_define_nb_faders; i++)
    {
        midi_levels[i]=(Fader[i]/2);
        midi_levels[i+196]=(lfo_speed[i]);
    }


    return(0);
}
