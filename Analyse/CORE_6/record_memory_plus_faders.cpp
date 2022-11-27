int record_memory_plus_faders(int mem_is)
{
    if(index_blind==0)
    {

        for (int u=1; u<514; u++)
        {
            if(bufferSequenciel[u] >bufferFaders[u])
            {
                Memoires[mem_is][u]=bufferSequenciel[u];
            }
            if(bufferSequenciel[u] <=bufferFaders[u])
            {
                Memoires[mem_is][u]=bufferFaders[u];
            }
        }
        //christoph 18/07/2015
        unselect_ch_and_symbols();
        refresh_mem_onstage(mem_is);


        sprintf(string_Last_Order,">>Created mem %.1f from faders and stage ", ((float)mem_is)/10);
    }
    else if(index_blind==1)
    {
        sprintf(string_Last_Order,">>[SHIFT-F3] only for on stage recording");
    }
    ratio_cross_manuel[mem_is]=ratio_X1X2_together;



    return(0);
}
