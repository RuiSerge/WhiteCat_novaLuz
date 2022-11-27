int DoModify(int fad, int dk)
{
    if(index_blind==0)
    {
        for (int dc=1; dc<514; dc++)
        {
            if(Selected_Channel[dc]==1)
            {
                FaderDockContains[fad][dk][dc]=bufferSaisie[dc];
                bufferSaisie[dc]=0;
                Selected_Channel[dc]=0;
            }
        }
        index_do_modify=0;
    }

    else if(index_blind==1)
    {
        for (int dc=1; dc<514; dc++)
        {
            if(Selected_Channel[dc]==1)
            {
                FaderDockContains[fad][dk][dc]=bufferBlind[dc];
            }
        }
        index_do_modify=0;
    }
    DockTypeIs[fad][dk]=0;


    return(0);
}
