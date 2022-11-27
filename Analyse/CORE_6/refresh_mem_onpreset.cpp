int refresh_mem_onpreset(int mem_is)
{
    for (int u=1; u<514; u++)
    {
        bufferBlind[u]=Memoires[mem_is][u];
    }
    ratio_X1X2_together=ratio_cross_manuel[mem_is];
    return(0);
}
