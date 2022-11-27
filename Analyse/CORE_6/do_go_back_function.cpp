int do_go_back_function()
{
    if(index_go_back==0 && index_go==0 && index_pause==0)
    {
        for (int op=1; op<514; op++)
        {
            bufferSaisie[op]=bufferSequenciel[op];
        }
        niveauX1=255;
        niveauX2=0;
        position_preset=mem_before_one;
        refresh_mem_onpreset(position_preset);
        prepare_crossfade();
        floatX1=niveauX1;
        floatX2=niveauX2;
        index_go=1;
        if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 )
        {
            grid_in_preset[0][0]=index_grider_selected[0];
            grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_onstage]-1;
            if(grider_is_playing[0]==0 && set_from_seq_gridplayer1_next_step[position_preset]!=-1 )
            {
                gridder_prepare_cross(0,index_grider_selected[0],set_from_seq_gridplayer1_next_step[position_preset]-1);
                grider_is_playing[0]=1;
                grid_crossfade_start_time[0]=actual_time;
            }
        }
    }
    else if(index_go_back==0 && index_go==1)
    {
        index_go_back=1;
        index_go=0;
        index_pause=0;
    }
    else if(index_go_back==1 && index_pause==0)
    {
        index_pause=1;
    }
    else if(index_go_back==1 && index_pause==1)
    {
        index_pause=0;
    }
    return(0);
}
