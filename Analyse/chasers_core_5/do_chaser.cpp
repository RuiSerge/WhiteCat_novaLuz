int do_chaser()
{
    for(int nch=0; nch<core_user_define_nb_chasers; nch++)
    {

        if(index_slave_chaser_to_accelerometre[nch]==1)
        {
            chaser_slaviness[nch]=((127-(float)lfo_speed[(view_chaser_affected_to_fader[nch][0])])/127.0);

            if(chaser_slaviness[nch]==0.0)
            {
                chaser_slaviness[nch]=0.01;
            }

        }
        else
        {
            chaser_slaviness[nch]=1.0;
        }


        for(int io=1; io<513; io++)
        {
            MergerBufferChasers[nch][io]=0;
        }
        if(chaser_is_playing[nch]==1)
        {
            switch(chaser_way[nch])
            {
            case 0://avant
                chaser_time_position[nch]++;

                if(chaser_time_position[nch]>=chaser_end_of_step[nch])
                {
                    chaser_calcul_step(nch,0.0);
                    chaser_step_is[nch]++;
                    if(chaser_step_is[nch]>chaser_end_step_is[nch] )
                    {
                        switch(chaser_is_in_loop[nch])
                        {
                        case 0:
                            chaser_is_playing[nch]=0;
                            break;
                        case 1:
                            switch( chaser_aller_retour[nch])
                            {
                            case 0:
                                chaser_step_is[nch]=chaser_begin_step_is[nch];
                                break;
                            case 1:
                                chaser_step_is[nch]--;
                                chaser_way[nch]=toggle(chaser_way[nch]);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    chaser_calcul_time_joint(nch);
                }
                index_progression_chaser_step[nch]=((chaser_time_position[nch]-chaser_start_of_step[nch])/((chaser_end_of_step[nch]-chaser_start_of_step[nch])/chaser_slaviness[nch]));
                break;
            case 1://arrière
                chaser_time_position[nch]++;
                if(chaser_time_position[nch]>=chaser_end_of_step[nch])
                {
                    chaser_calcul_step(nch,0.0);
                    chaser_step_is[nch]--;
                    if(chaser_step_is[nch]<chaser_begin_step_is[nch])
                    {
                        switch(chaser_is_in_loop[nch])
                        {
                        case 0:
                            chaser_is_playing[nch]=0;
                            break;
                        case 1:
                            switch( chaser_aller_retour[nch])
                            {
                            case 0:
                                chaser_step_is[nch]=chaser_end_step_is[nch];
                                break;
                            case 1:
                                chaser_step_is[nch]++;
                                chaser_way[nch]=toggle(chaser_way[nch]);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }

                    chaser_calcul_time_joint(nch);
                }
                index_progression_chaser_step[nch]=((chaser_time_position[nch]-chaser_start_of_step[nch])/((chaser_end_of_step[nch]-chaser_start_of_step[nch])/chaser_slaviness[nch]));
                break;
            default:
                break;
            }
        }//fin if track is on



        for(int trkis=0; trkis<core_user_define_nb_tracks_per_chasers; trkis++)
        {
            if(TrackTypeIs[nch][trkis]==1)//si une mémoire embarquée
            {
                for(int u=1; u<513; u++)
                {
                    TrackContains[nch][trkis][u]= Memoires[(TrackHasMem[nch][trkis])][u];
                    for(int ui=0; ui<core_user_define_nb_tracks_per_chasers; ui++)
                    {
                        TracksBuffer[nch][trkis][ui]=0;
                    }
                }
            }

            if(track_is_on[nch][trkis]==1)
            {
                switch(chaser_step_operation[nch][trkis][(chaser_step_is[nch])])
                {
                case 0://rien
                    for(int io=1; io<513; io++)
                    {
                        TracksBuffer[nch][trkis][io]=0;
                    }
                    break;
                case 1://up
                    switch(chaser_time_mode[nch])
                    {
                    case 0://mode solo
                        for(int io=1; io<513; io++)
                        {
                            TracksBuffer[nch][trkis][io]=(int)((((float) TrackContains[nch][trkis][io])/127*track_level[nch][trkis])*index_progression_chaser_step[nch]);
                        }
                        break;
                    case 1://mode joint
                        for(int io=1; io<513; io++)
                        {
                            TracksBuffer[nch][trkis][io]=(int)(((((float) TrackContains[nch][trkis][io])/127*track_level[nch][trkis])
                                                                *((1.0/joint_nbr_step[nch][trkis]) * (joint_nbr_step[nch][trkis]-count_steps_for_fades[nch][trkis])) ))//calcul de la base des steps
                                                         +(int)(((((float) TrackContains[nch][trkis][io])/127*track_level[nch][trkis])/joint_nbr_step[nch][trkis])*index_progression_chaser_step[nch]);
                            ;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case 2://stay
                    for(int io=1; io<513; io++)
                    {
                        TracksBuffer[nch][trkis][io]= (int)((((float)TrackContains[nch][trkis][io])/127)*track_level[nch][trkis]);
                    }
                    break;
                case 3://down
                    switch(chaser_time_mode[nch])
                    {
                    case 0://mode solo
                        for(int io=1; io<513; io++)
                        {
                            TracksBuffer[nch][trkis][io]=(int)((((float) TrackContains[nch][trkis][io])/127)*track_level[nch][trkis]*(1-index_progression_chaser_step[nch]));
                        }
                        break;
                    case 1://mode joint
                        for(int io=1; io<513; io++)
                        {
                            TracksBuffer[nch][trkis][io]=(int)(((((float) TrackContains[nch][trkis][io])/127*track_level[nch][trkis])
                                                                *(1-(((1.0/joint_nbr_step[nch][trkis]) * (joint_nbr_step[nch][trkis]-count_steps_for_fades[nch][trkis])) ))//calcul de la base des steps
                                                                -(int)(((((float) TrackContains[nch][trkis][io])/127*track_level[nch][trkis])/joint_nbr_step[nch][trkis])*index_progression_chaser_step[nch])));
                            ;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }

                for (int j=1; j<513; j++)
                {
                    MergerBufferChasers[nch][j]=Tmax(MergerBufferChasers[nch][j],TracksBuffer[nch][trkis][j]);
                }
            }
        }

    }


    return(0);
}
