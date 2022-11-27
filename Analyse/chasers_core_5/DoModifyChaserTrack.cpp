int DoModifyChaserTrack(int numchaser, int numtrack)
{


    TrackTypeIs[numchaser][numtrack]=0;//le type est 0, circuits normaux
    if(index_blind==0)
    {
        for (int dc=1; dc<514; dc++)
        {
            if(Selected_Channel[dc]==1)
            {
                TrackContains[numchaser][numtrack][dc]=bufferSequenciel[dc];
                Selected_Channel[dc]=0;
            }
        }
        index_do_modify=0;
        sprintf(string_Last_Order,">>n Modified Chaser %d Track %d",numchaser+1, numtrack+1);
    }

    else if(index_blind==1)
    {
        for (int dc=1; dc<514; dc++)
        {
            if(Selected_Channel[dc]==1)
            {
                TrackContains[numchaser][numtrack][dc]=bufferBlind[dc];
            }
        }
        index_do_modify=0;
        sprintf(string_Last_Order,">> Modified from Preset Chaser %d Track %d",numchaser+1, numtrack+1);
    }

    return(0);
}
