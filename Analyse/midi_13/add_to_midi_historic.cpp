int add_to_midi_historic()//just a visual monitoring
{

    if( position_midi_historic>254)
    {
        position_midi_historic=0;
        for(int i=0; i<255; i++)
        {
            sprintf(midi_historic[i]," ");
            midi_historic_data[i][0]=999;
            midi_historic_data[i][1]=999;
            midi_historic_data[i][2]=999;
            midi_historic_data[i][3]=999;
        }
    }
    else
    {
        position_midi_historic++;
    }

    midi_historic_data[position_midi_historic][0]=istyp;
    midi_historic_data[position_midi_historic][1]=ischan;
    midi_historic_data[position_midi_historic][2]=ispitch;
    midi_historic_data[position_midi_historic][3]=isvel;
    sprintf(midi_historic[position_midi_historic],my_midi_string);
    return(0);
}
