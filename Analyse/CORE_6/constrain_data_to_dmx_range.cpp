int constrain_data_to_dmx_range(int valeur)
{
    if(valeur<0)
    {
        valeur=0;
    }
    if(valeur>255)
    {
        valeur=255;
    }
    return(valeur);
}
