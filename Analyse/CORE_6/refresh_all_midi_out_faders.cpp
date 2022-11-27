int refresh_all_midi_out_faders()
{

    for(int i=0; i<48; i++) //faders
    {
            index_send_midi_out[i]=1;
    }

    for(int i=196; i<(196+48); i++) //LFO
    {
            index_send_midi_out[i]=1;
    }

    for (int i=1960; i<2007;i++ )//decay
    {
            index_send_midi_out[i]=1;
    }

    for (int i=2056 ; i <2113; i++)//dt
    {
            index_send_midi_out[i]=1;
    }


    //trichro wheel
    index_send_midi_out[497]=1;

    //tracking video decay
    index_send_midi_out[498]=1;

    return(0);
}
