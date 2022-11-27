int constrain_data_to_midi_range(int valeur)
{
    if(valeur<0)
    {
        valeur=0;
    }
    if(valeur>127)
    {
        valeur=127;
    }
    return(valeur);
}
