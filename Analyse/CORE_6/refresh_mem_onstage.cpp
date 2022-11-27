int refresh_mem_onstage(int mem_is)
{
    for (int u=1; u<514; u++)
    {
        bufferSaisie[u]=Memoires[mem_is][u];
    }
    return(0);
}
