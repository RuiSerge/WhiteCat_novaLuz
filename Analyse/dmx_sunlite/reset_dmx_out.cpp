int reset_dmx_out()
{
    dasusbcommand(DHC_DMXOUTOFF,0,0);
    return(0);
}
