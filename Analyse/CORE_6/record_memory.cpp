int record_memory(int mem_is)
{
    for (int u=1; u<514; u++)
    {
        if(index_blind==0)
        {
            Memoires[mem_is][u]=bufferSequenciel[u];
        }
        else if(index_blind==1)
        {
            Memoires[mem_is][u]=bufferBlind[u];
        }
    }
    //christoph 18/07/2015
    unselect_ch_and_symbols();
    ratio_cross_manuel[mem_is]=ratio_X1X2_together;
    return(0);
}
