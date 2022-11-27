int Unselect_all_channels()
{
    for (int ci=1; ci<514; ci++)
    {
        Selected_Channel[ci]=0;
    }
    return(0);
}
