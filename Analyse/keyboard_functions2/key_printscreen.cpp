int key_printscreen()
{
    if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
    {
        snapshot_windows();
        close_all_windows();
    }
    else if (key_shifts & KB_CTRL_FLAG  || index_false_control==1)
    {
        recall_windows();
    }
    return(0);
}
