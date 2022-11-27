int set_all_faders_midi_out(bool state)
{
    for(int i=0; i<48; i++) //faders
    {
        midi_send_out[i]=state;
        if(state==1)
        {
            index_send_midi_out[i]=1;
        }
    }
    for(int i=196; i<(196+48); i++) //LFO
    {
        midi_send_out[i]=state;
        if(state==1)
        {
            index_send_midi_out[i]=1;
        }
    }



    return(0);
}
