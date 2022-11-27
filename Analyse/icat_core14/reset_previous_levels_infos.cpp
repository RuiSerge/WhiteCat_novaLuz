int reset_previous_levels_infos()
{
    for(int f=0; f<48; f++)
    {
        Fader_before[f]=255;
        before_dock_used_by_fader_is[f]=-1;
        OldFaderLockProc[f]=255;
        before_is_dock_for_lfo_selected[f]=-1;
        before_lfo_speed[f]=-1;
    }
    before_niveauX1 =-1;
    before_niveauX2=-1;
    before_crossfade_speed=-1;
    previous_niveauGMaster=-1;
    previous_absolute_level_wheel=-1;
    for(int f=0; f<48; f++)
    {
        before_mover_params[f][0]=-1;
        before_mover_params[f][1]=-1;
    }
    for(int pr=0; pr<6; pr++)
    {
        previous_draw_level_to_do[pr]=-1;
        previous_draw_damper_decay_factor[pr]=-1;
        previous_draw_ghost_to_do[pr]=-1;
    }



    return(0);
}
