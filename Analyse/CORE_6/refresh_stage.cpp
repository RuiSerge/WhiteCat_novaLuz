int refresh_stage()
{
    for (int l=1; l<512; l++)
    {
        bufferSaisie[l]=Memoires[position_onstage][l];
    }
    return(0);
}
