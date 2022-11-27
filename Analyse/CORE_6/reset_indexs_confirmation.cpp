int reset_indexs_confirmation()
{
    index_do_dock=0;
    index_do_modify=0;
    index_do_report=0;
    index_do_delete_mem=0;
    index_do_create_mem=0;
    index_do_create_mem_plus_faders=0;
    index_do_overecord_mem_plus_faders=0;
    index_do_link_memonstage=0;
    index_do_link_memonpreset=0;
    index_do_link_membefore=0;
    index_do_link_memother=0;
    index_do_record_on_faders=0;
    index_do_modify_on_faders=0;
    index_do_report_on_faders=0;
    index_do_affect_color_on_faders=0;
    index_do_dmx_to_dock=0;
    index_do_artnet_to_dock=0;
    index_do_video_to_dock=0;
    index_do_affect_net_to_dock=0;

    index_affect_video_tracking_to_dock=0;
    index_affect_dmxin=0;
    index_affect_color_to_dock=0;

    index_record_minifader_preset=0;
    index_clear_minifader_preset=0;
    index_record_minifader_lockpreset=0;
    index_do_affect_color_trichro=0;
    index_do_affect_roi=0;
    index_do_clear_my_roi=0;
    index_do_clear_my_video_preset=0;
    index_do_overrecord_mem=0;
    index_copy_mem_in=0;
    index_main_clear=0;
    index_do_clear_dock=0;
    index_do_clear_on_faders=0;
    index_do_reload_mem=0;
    index_do_resurrect_mem=0;
    index_do_jump_while_cross=0;

    index_do_export=0;
    index_do_import=0;
    index_do_saveshow=0;
    index_do_loadshow=0;
    index_do_resetshow=0;
    index_do_freeze=0;

    index_do_clear_patch=0;
    index_do_default_patch=0;
    index_do_quit_with_save=0;
    index_do_quit_without_save=0;
    index_do_ask_call_audio_folder=0;
    index_do_audio_to_dock=0;
    index_do_clear_lock_preset=0;
    index_do_banger_memonstage=0;
    index_do_banger_memonpreset=0;
    index_do_banger_membeforeone=0;
    index_do_banger_memother=0;

    //wizard
    index_do_wizard_ch=0;
    index_do_wizard_mem=0;
    index_wizard_do_reload_from_disk=0;
    //direct ch
    index_do_record_direct_ch=0;

    //affectation courbe � un fader
    index_ask_curv_to_fader=0;
    index_re_init_client_artnet=0;
    index_re_init_serveur_artnet=0;

    //affect FX a dock
    index_do_affect_fx=0;

    //chasers
    index_do_dock_track=0;
    index_do_clear_track=0;
    index_do_report_track=0;
    index_do_modify_track=0;
    index_do_clear_chaser=0;
    index_do_store_chaser_preset=0;
    index_do_clear_chaser_preset=0;

    //icat
    index_ask_clear_iCatpage=0;
    index_ask_icat_copyPage=0;
    index_ask_clear_img_icat=0;
    index_ask_iCat_selectiv_clear=0;
    index_false_shift=0;
    index_false_control=0;

    //grider
    index_clear_a_grid_step=0;
    index_clear_a_grid=0;
    grid_to_clear=0;
    step_grid_to_clear=0;
    index_clear_a_grid_serie_step=0;
    index_for_grid_stepto=0;
    index_for_copy_grid=0;
    index_for_insert_grid=0;
    destination_grid_for_copy=0;
    destination_step_for_copy=0;
    index_grid_tostep_or_not=0;
    from_gridstep_to=0;
    gridplayer_to_affect_is=-1;

    index_do_affect_grid_to_fader=0;

    index_do_affect_step_gridplayer_to_mem=0;
    index_mem_to_be_affected_by_gpl=0;

    index_do_exclude=0;
    index_do_affect_fgroup=0;

    index_do_clear_all_the_patch=0;

    index_ask_build_view=0;
    index_do_build_view=0;
    channel_view_is=0;


    index_ask_clear_selection_of_view=0;
    index_ask_record_selection_of_view=0;
    index_ask_modify_selection_of_view=0;
    channel_view_is=0;
    index_ask_report_selection_of_view=0;

    index_ask_clear_a_move=0;
    index_ask_reinit_FS_client=0;

    ask_clear_draw_preset=0;
    index_do_draw_affect_to_dock=0;

    //echo
    index_ask_clear_echo_preset=0;
    index_do_affect_echo_to_dock=0;

    //wave
    index_affect_wave_to_dock=0;

    index_ask_copy_banger=0;
    index_ask_clear_banger=0;

    //sab 02/03/2014 sprintf(string_confirmation,"");
    strcpy(string_confirmation,"");
    return(0);
}
