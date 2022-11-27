int key_right()
{
    if (key_shifts & KB_CTRL_FLAG || index_false_control==1)
    {
        check_channel_plus();
        add_channel_selection_to_layers_plot();
        substract_channel_selection_to_layers_plot();
    }
    else if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
    {
        check_dimmer_plus_override();
    }
    else
    {
        select_channel_plus();
    }
    return(0);
}
