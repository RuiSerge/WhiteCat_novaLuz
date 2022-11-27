int load_indexes()
{
    auto_reset_crossfade_speed_on_link=index_report_customs[0];
    nbre_memoires_visualisables_en_preset=index_report_customs[1];
    index_midi_global_thruth=index_report_customs[2];
    refresh_midi_chasers=index_report_customs[3];
    view_plot_calc_number_is=index_report_customs[4];
    index_menus_lighting_plot=index_report_customs[5];
    symbol_selected_type=index_report_customs[6];
    shape_selected_type=index_report_customs[7];
    legend_view=index_report_customs[8];
    ClassicalChannelView=index_report_customs[9];
    index_config_dmx=index_report_customs[10];
    index_config_midi=index_report_customs[11];
    index_config_arduino=index_report_customs[12];
    midi_page=index_report_customs[13];
    config_color_style_is=index_report_customs[14];
    index_link_is_on=index_report_customs[15];
    index_decay_tracker=index_report_customs[16];
    adapater_is_selected=index_report_customs[17];
    index_build_patch_from_plot=index_report_customs[18];
    index_menu_curve=index_report_customs[19];
    index_show_first_dim=index_report_customs[20];
    cheat_key_off=index_report_customs[21];
    scroll_faderspace=index_report_customs[22];
    draw_preset_selected=index_report_customs[23];
    index_banger_is_on=index_report_customs[24];
    index_banger_selected=index_report_customs[25];
    index_save_mode_export_or_binary=index_report_customs[26];
    index_allow_sunlite_dmxIN=index_report_customs[27];//sunlite
    index_config_general=index_report_customs[28];
    niveauGMaster=index_report_customs[29];//grand master
    cheat_key_off_to_key_on=index_report_customs[30];
    clocklevel_absolutemode=index_report_customs[31];//midiclock midi mode
    echo_selected=index_report_customs[32];
    index_allow_multicore=index_report_customs[33];
    allow_artnet_in=index_report_customs[34];
    window_focus_id=index_report_customs[35];
    recall_windows_focus_id=index_report_customs[36];
    index_config_network=index_report_customs[37];
    index_setup_gfx=index_report_customs[38];
    core_to_assign=index_report_customs[39];
    index_midi_clock_on=index_report_customs[40];
    midi_BPM=index_report_customs[41];
    show_global_view_grider=index_report_customs[42];
    enable_launchpad=index_report_customs[43];
    relativ_encoder_midi_clock_value=index_report_customs[44];
    config_page_is=index_report_customs[45];
    index_midi_affectation_autoclose=index_report_customs[46];
    index_show_chrono=index_report_customs[47];
    nbre_track_visualisables=index_report_customs[48];
    chaser_operator_is=index_report_customs[49];
    chaser_selected=index_report_customs[50];
    index_affichage_digit_time_unit=index_report_customs[51];
    launchpad_chaser_mode=index_report_customs[52];
    index_enable_edit_chaser=index_report_customs[53];
    chaser_midi_rows=index_report_customs[54];
    line_list_is=index_report_customs[55];
    waver_control=constrain_int_data_to_this_range(index_report_customs[56],0,26);
    wave_channel_preset_selected=constrain_int_data_to_this_range(index_report_customs[57],0,26);
    brush_selected=constrain_int_data_to_this_range(index_report_customs[58],0,26);
    iCatPageis=index_report_customs[59];
    surface_type=index_report_customs[60];
    grid_icat_modulo=index_report_customs[61];
    index_midi_auto_demute=index_report_customs[62];
    index_midi_mute_on_lfo=index_report_customs[63];
    index_text_auto_close=index_report_customs[64];
    index_config_core=index_report_customs[65];
    show_gridplayer_in_seq=index_report_customs[66];
    index_auto_mute_cuelist_speed=index_report_customs[67];
    Midi_Force_Go=index_report_customs[68];
    BPM_WAVE_RATE=constrain_int_data_to_this_range(index_report_customs[69],1,6000);
    index_config_tab_hotkeys=index_report_customs[70]; // sab 12/08/2016 Fenêtre des config - onglet des hot keys

    if(surface_type==0)
    {
        L_tablier_iCat=240;
        H_tablier_iCat=160;
    }
    else
    {
        L_tablier_iCat=512;
        H_tablier_iCat=384;
    }
    if(grid_icat_modulo<1)
    {
        grid_icat_modulo=1;
    }

    if(niveauGMaster<255)
    {
        midi_levels[615]=(niveauGMaster/2);
    }
    else if(niveauGMaster==255)
    {
        midi_levels[615]=127;
    }



    if(index_allow_multicore==1 && core_to_assign>0 && core_to_assign<9)
    {
        process_assign_to_core(core_to_assign);
    }

    switch(config_page_is)
    {
    case 0:
        break;
    case 1:
        index_config_dmx=1;
        break;
    case 2:
        index_config_midi=1;
        break;
    case 3:
        index_config_network=1;
        break;
    case 4:
        index_setup_gfx=1;
        break;
    case 5:
        index_config_arduino=1;
        break;
    case 6:
        index_config_general=1;
        break;
    case 7:
        index_config_core=1;
        break;
    }

    if(nbre_memoires_visualisables_en_preset<5)
    {
        nbre_memoires_visualisables_en_preset=5;
    }
    hauteur_globale_sequenciel=180+(35*(nbre_memoires_visualisables_en_preset+1))+35;

    set_refresh_mode_for_chaser(refresh_midi_chasers);

    midi_levels[498]=index_decay_tracker;
    index_send_midi_out[498]=1;

    if(midi_BPM<=0)
    {
        midi_BPM=120;
    }
    ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
    install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
    if(relativ_encoder_midi_clock_value<=0)
    {
        relativ_encoder_midi_clock_value=1;
    }

    return(0);
}
