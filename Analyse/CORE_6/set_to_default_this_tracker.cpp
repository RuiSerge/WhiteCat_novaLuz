int set_to_default_this_tracker(int Tcker)
{
    for (int dokTr=0; dokTr<6; dokTr++)
    {
        set_to_default_my_roi(Tcker,dokTr);
        set_to_default_my_roi(Tcker,dokTr+6);
    }
    return(0);
}
