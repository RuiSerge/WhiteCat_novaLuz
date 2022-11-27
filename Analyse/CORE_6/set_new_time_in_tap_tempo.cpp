int set_new_time_in_tap_tempo()
{
    if(index_recording_tap_tempo==1)
    {
        nbr_steps_tempo++;

        if(nbr_steps_tempo>max_temp_tempo)
        {
            start_tempo_ticks=actual_time-ticks_tap_tempo[max_temp_tempo];
            nbr_steps_tempo=1;
            tempo_interm=0;
        }

        ticks_tap_tempo[nbr_steps_tempo]=actual_time-start_tempo_ticks;

        start_tempo_ticks=actual_time;//report de l'actuel temps

        tempo_interm+=ticks_tap_tempo[nbr_steps_tempo];

        tap_tempo_average=(((float)(tempo_interm))/nbr_steps_tempo) /BPS_RATE;

        sprintf(string_tap_tempo_average,"Step: %d  Global: %.2f",nbr_steps_tempo,tap_tempo_average);
        sprintf(string_actual_tap_tempo,"Last:%.2f",((float)ticks_tap_tempo[nbr_steps_tempo])/BPS_RATE);
        do_light_tap_tempo=1;
    }
    return(0);
}
