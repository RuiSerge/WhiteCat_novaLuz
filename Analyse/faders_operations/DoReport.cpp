int DoReport(int fad, int dk)
{


    DockTypeIs[fad][dk]=0;//le type est 0, circuits normaux
    for (int u=1; u<514; u++)
    {
        FaderDockContains[fad][dk][u]=bufferSaisie[u];
        if(bufferFaders[u]>FaderDockContains[fad][dk][u])
        {
            FaderDockContains[fad][dk][u]=bufferFaders[u];
        }
    }
    for (int x=1; x<514; x++)
    {
        bufferSaisie[x]=0;
        bufferBlind[x]=0;
        Selected_Channel[x]=0;
    }

    for (int fder=0; fder<core_user_define_nb_faders; fder++)
    {
        Fader[fder]=0;
    }
    Unselect_other_docks(fad,dk);
    DockIsSelected[fad][dk]=1;
    Fader[fad]=255;
    index_do_report=0;
    return(0);
}
