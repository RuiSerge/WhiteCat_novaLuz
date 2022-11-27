int channel_paste()
{
    for(int ck=1; ck<513; ck++)
    {
        if(index_blind==0)
        {
            if(SelectedForCopyPaste[ck]==1)
            {
                bufferSaisie[ck]=bufferCopyPaste[ck];
            }
            sprintf(string_Last_Order,">> Pasted channels from memory to Stage");
        }
        else
        {
            if(SelectedForCopyPaste[ck]==1)
            {
                bufferBlind[ck]=bufferCopyPaste[ck];
            }
            sprintf(string_Last_Order,">> Pasted channels from memory to Blind");
        }
    }

    return(0);
}
