int clear_draw_preset(int p)
{
    draw_preset_parameters[p][0]=6;
    draw_preset_parameters[p][1]=4;
    recalculate_draw_sizes(p);
    draw_level_to_do[p]=0.1;
    draw_damper_decay_factor[p]=0.1;
    draw_ghost_to_do[p]=0.01;

    draw_mode[p]=0;

    for(int ch=0; ch<500; ch++)
    {
        draw_preset_levels[p][ch]=0.0;
        draw_preset_channel_routing[p][ch]=0;
    }


    index_case[p]=0;
    draw_centre_x[p]=0;
    draw_centre_y[p]=0;


    draw_get_gpl[p]=4;
    draw_offset_gpl[p]=1;


    sprintf(string_Last_Order,"Cleared DRAW Preset %d",p+1);
    return(0);
}
