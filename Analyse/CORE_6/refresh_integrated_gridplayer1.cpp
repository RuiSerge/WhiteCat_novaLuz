int refresh_integrated_gridplayer1()
{
    if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_onstage]!=-1 )
    {
        index_grider_step_is[0]=set_from_seq_gridplayer1_next_step[position_onstage];
        grider_is_playing[0]=0;
        grid_niveauX1[0]=255;
        grid_niveauX2[0]=0;
        grid_floatX1[0]=255;
        grid_floatX2[0]=0;
        gridder_prepare_cross(0, index_grider_selected[0], index_grider_step_is[0]);
    }
    return(0);
}
