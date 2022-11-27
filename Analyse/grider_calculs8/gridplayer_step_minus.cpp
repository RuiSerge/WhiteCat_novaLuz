int gridplayer_step_minus(int num_grid_player)
{
    index_grider_step_is[num_grid_player]--;
    if(index_grider_step_is[num_grid_player]<0)
    {
        index_grider_step_is[num_grid_player]=0;
    }
    grid_niveauX1[num_grid_player]=255;
    grid_niveauX2[num_grid_player]=0;
    grid_floatX1[num_grid_player]=grid_niveauX1[num_grid_player];
    grid_floatX2[num_grid_player]=grid_niveauX2[num_grid_player];
    gridder_prepare_cross(num_grid_player, index_grider_selected[num_grid_player], index_grider_step_is[num_grid_player]);
    if(grider_seekto_mode[num_grid_player]==1 && grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]>0 )//seek position
    {
        index_grider_seek_pos[num_grid_player]=grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]];
    }
    grid_counted_times[index_grider_selected[num_grid_player]] [index_grider_step_is[num_grid_player]]=0;
    return(0);
}
