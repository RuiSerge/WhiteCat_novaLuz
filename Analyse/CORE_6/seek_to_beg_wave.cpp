int seek_to_beg_wave()
{
    clear_wave_slots();
    waver_control=0;
    set_new_values_in_wave();
    previous_waver_control=waver_control;
    return(0);
}
