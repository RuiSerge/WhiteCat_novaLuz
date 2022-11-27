int channel_copy()
{
    for(int ck=1; ck<513; ck++)
    {
        bufferCopyPaste[ck]=0;
        SelectedForCopyPaste[ck]=0;
        if(index_blind==0)
        {
            if(Selected_Channel[ck]==1)
            {
                SelectedForCopyPaste[ck]=1;
                bufferCopyPaste[ck]=Tmax (bufferSequenciel[ck],bufferFaders[ck]);
            }
        }
        else
        {
            if(Selected_Channel[ck]==1)
            {
                SelectedForCopyPaste[ck]=1;
                bufferCopyPaste[ck]=bufferBlind[ck];
            }
        }
    }
    sprintf(string_Last_Order,">> Pasted selected channels in memory");
    return(0);
}
