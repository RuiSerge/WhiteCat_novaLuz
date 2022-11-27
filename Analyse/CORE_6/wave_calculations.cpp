int wave_calculations()
{

    if(previous_waver_control!=waver_control)
    {
        set_new_values_in_wave();
        previous_waver_control=waver_control;
    }

    return(0);
}
