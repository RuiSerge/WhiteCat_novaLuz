int snap_state_of_draw_grid(int pr)
{
    for(int i=0; i<500; i++)
    {
        if(draw_preset_levels[pr][i]>0.0)
        {
            draw_snap_preset_levels[pr][i]=1;
        }
        else
        {
            draw_snap_preset_levels[pr][i]=0;
        }
    }
    return(0);
}
