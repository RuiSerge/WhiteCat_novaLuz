int Channel_select_thruth(int fromch, int toch)
{
    if(fromch<toch)
    {
        for (int cit=fromch; cit<=toch; cit++)
        {
            Selected_Channel[cit]=1;
        }
    }
    if (fromch>toch)
    {
        for (int cit=toch; cit<=fromch; cit++)
        {
            Selected_Channel[cit]=1;
        }
    }
    sprintf(string_Last_Order,">> Selected from Ch %d to Ch %d", fromch, toch);
    return(0);
}
