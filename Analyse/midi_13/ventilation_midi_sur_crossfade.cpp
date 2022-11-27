int ventilation_midi_sur_crossfade()
{
    if(index_get_back_faders_need_to_be_done==0)
    {
        midi_levels[491]=niveauX1/2;
        midi_levels[492]=127-(niveauX2/2);
        midi_levels[493]=crossfade_speed;
    }
    return(0);
}
