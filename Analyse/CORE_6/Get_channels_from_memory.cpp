int Get_channels_from_memory(int the_mem)
{
    for(int p=1; p<513; p++)
    {
        if (Selected_Channel[p]==1)
        {
            switch(index_blind)
            {
            case 0:
                bufferSaisie[p]=Memoires[the_mem][p];
                break;
            case 1:
                bufferBlind[p]=Memoires[the_mem][p];
                break;
            default:
            break;
            }
        }
    }
    strcpy(numeric,"");
    numeric_postext=0;
    sprintf(string_Last_Order,"Got selected channel from %d.%d",the_mem/10,the_mem%10);
    return(0);
}
