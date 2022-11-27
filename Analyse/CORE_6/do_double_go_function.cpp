int do_double_go_function()
{
    index_go=0;
    index_pause=0;
    index_go_back=0;
    for (int op=1; op<514; op++)
    {
        bufferSaisie[op]=bufferSequenciel[op];
    }
    niveauX1=255;
    niveauX2=0;
    crossfade_speed=64;
    reset_modified_levels_in_crossfade();
    for(int ipo=position_preset+1; ipo<10000; ipo++)
    {
        if(ipo>=9999)
        {
            ipo=0;
        }
        if(MemoiresExistantes[ipo]==1)
        {
            position_preset=ipo;
            break;
        }
    }
    refresh_mem_onpreset(position_preset);
    prepare_crossfade();
    floatX1=niveauX1;
    floatX2=niveauX2;
    index_go=1;
    refresh_integrated_gridplayer1();
    if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 )
    {
        grid_in_preset[0][0]=index_grider_selected[0];
        grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_preset]-1;
        if(grider_is_playing[0]==0 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 )
        {
            gridder_prepare_cross(0,index_grider_selected[0],set_from_seq_gridplayer1_next_step[position_preset]-1);
            grider_is_playing[0]=1;
            grid_crossfade_start_time[0]=actual_time;
        }
    }
    return(0);
}
