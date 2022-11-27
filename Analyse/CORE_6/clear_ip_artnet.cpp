int clear_ip_artnet()
{
    //ip artnet
    for(int u=0; u<8; u++)
    {
        sprintf(IP_detected_dmxOUT[u],"-");
    }

    return(0);
}
