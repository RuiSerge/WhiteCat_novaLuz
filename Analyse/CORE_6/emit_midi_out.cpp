int emit_midi_out()
{


    for(int i=0; i<3072; i++)
    {
        if(midi_send_out[i]==1 && index_send_midi_out[i]==1 )
        {
            if(miditable[0][i]<128 && miditable[1][i]<128 && miditable[2][i]<128)
            {
                send_immidiateley_my_midi_cc(miditable[0][i],miditable[1][i],miditable[2][i],midi_levels[i]);
                index_send_midi_out[i]=0;
            }
        }
    }

    return(0);
}
