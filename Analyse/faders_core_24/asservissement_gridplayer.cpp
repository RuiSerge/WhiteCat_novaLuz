int asservissement_gridplayer(int cmptfader, int dk)
{
    int the_gr= faders_dock_grid_affectation[cmptfader][dk];
    if(grid_player_slave[the_gr]==1)
    {
        grid_crossfade_speed[the_gr]=lfo_speed[cmptfader];
        gridder_prepare_cross(the_gr, index_grider_selected[the_gr], index_grider_step_is[the_gr]);
    }
    return(0);
}
