int key_go()
{
    if (key_shifts & KB_CTRL_FLAG  || index_false_control==1)
    {
        do_go_back_function();
        int banger_back_is=Banger_Memoire[position_preset]-1;
        do_go_back_bang(banger_back_is);
    }
    else if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
    {
        do_double_go_function();
        do_send_bang();
    }
    else
    {
        do_go_function();
        do_send_bang();
    }
    return(0);
}
