int set_to_default_my_trackers()
{
    for (int dokTr=0; dokTr<6; dokTr++)
    {
        set_to_default_my_roi(dokTr,dokTr);
        set_to_default_my_roi(dokTr,dokTr+6);
    }
    return(0);
}
