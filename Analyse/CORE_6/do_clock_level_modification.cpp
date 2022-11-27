int do_clock_level_modification(int level)
{
    switch(clocklevel_absolutemode)
    {
    case 0://relatif
        if(level<64)
        {
            midi_BPM+=relativ_encoder_midi_clock_value;
            ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
            install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
        }
        else if(level>64)
        {
            midi_BPM-=relativ_encoder_midi_clock_value;
            if(midi_BPM<=0)
            {
                midi_BPM=relativ_encoder_midi_clock_value;
            }
            ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
            install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
        }
        break;
    case 1://absolute , on r�cup�re de toute facon le niveau midi comme base
        midi_BPM=relativ_encoder_midi_clock_value*level;
        if(midi_BPM<=0)
        {
            midi_BPM=relativ_encoder_midi_clock_value;
        }
        ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
        install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
        break;
    default:
        break;
    }

    return(0);
}
