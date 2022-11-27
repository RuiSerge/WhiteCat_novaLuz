int Channel_select_all()
{
    if(index_blind==0)
    {
        for (int ci=1; ci<514; ci++)
        {
            if(bufferSaisie[ci]==0)
            {
                Selected_Channel[ci]=0;
            }
            else if (bufferSaisie[ci]>0)
            {
                Selected_Channel[ci]=1;
            }
        }
    }
    else if(index_blind==1)
    {
        for (int ci=1; ci<514; ci++)
        {
            if(bufferBlind[ci]==0)
            {
                Selected_Channel[ci]=0;
            }
            else if (bufferBlind[ci]>0)
            {
                Selected_Channel[ci]=1;
            }
        }
    }
    sprintf(string_Last_Order,">> Selected All lighting channels ( ALL )");
    return(0);
}
