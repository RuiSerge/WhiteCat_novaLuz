int DoClearAChaser(int numchaser)
{
    chaser_operator_is=0;
    time_unit[numchaser]=1.0;
    strcpy(chaser_name[numchaser],"");
    chaser_is_playing[numchaser]=0;
    chaser_is_in_loop[numchaser]=0;
    chaser_way[numchaser]=0;
    chaser_aller_retour[numchaser]=0;
    position_affichage_track_num[numchaser]=0;
    view_chaser_affected_to_fader[numchaser][0]=999;
    view_chaser_affected_to_fader[numchaser][1]=999;
    chaser_step_is[numchaser]=0;
    chaser_begin_step_is[numchaser]=0;
    chaser_end_step_is[numchaser]=nbre_de_cases_par_track;
    chaser_time_mode[numchaser]=0;

    for(int pt=0; pt<4; pt++)
    {
        chaser_clear_preset(numchaser,pt);
    }

    for(int o=0; o<core_user_define_nb_tracks_per_chasers; o++)
    {
        DoClearChaserTrack(numchaser,o);
    }


    sprintf(string_Last_Order,">> Cleared Chaser %d",numchaser+1);
    return(0);
}
