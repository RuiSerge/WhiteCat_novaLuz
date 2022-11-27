int substract_a_window(int id)
{
    /* christoph 11/04/2014 begin replace */
    int erase_window_opened[64];
    int next_free_pos;
    next_free_pos=0;
    for(int old_pos=0; old_pos<63; old_pos++)
    {
        if((window_opened[old_pos]!=id)  //id has been erase from the deque
                && (window_opened[old_pos]!=0)  //shouldn't hapen
                && (next_free_pos<63))    // don't overflow
        {
            erase_window_opened[next_free_pos]=window_opened[old_pos];
            next_free_pos = next_free_pos+1;
        }
    }
    // Clean last unuse new position
    if ((next_free_pos+1)<63)
    {
        for(int i=(next_free_pos+1); i<63; i++)
        {
            erase_window_opened[i]=0;
        }
    }
    //copy
    for(int i=0; i<63; i++) //both are 72 occurences long
    {
        window_opened[i] = erase_window_opened[i];
    }
    //first window get focus
    window_focus_id=window_opened[0];
    /* sab 05/03/2014 end replace */

    reset_index_actions();

    switch(id)
    {
    case W_SAVEREPORT:
        index_show_save_load_report=0;
        break;
    case W_TRICHROMY:
        index_trichro_window=0;
        index_affect_color_to_dock=0;
        break;
    case W_NUMPAD:
        index_visual_pad=0;
        break;
    case W_TRACKINGVIDEO:
        index_video_window=0;
        index_affect_video_tracking_to_dock=0;
        break;
    case W_ARTPOLLREPLY:
        index_show_artpoll_reply_content=0;
        break;
    case W_FADERS:
        index_show_faders=0;
        break;
    case W_PATCH:
        index_patch_window=0;
        index_enable_curve_editing=0;
        patch_unselect_all_dimmers();
        index_patch_overide=0;
        index_patch_affect_is_done=0;
        reset_check_grada_overide_dimmers();
        break;
    case W_TIME:
        reset_index_actions();
        index_time=0;
        index_affect_time=0;
        break;
    case W_SEQUENCIEL:
        index_window_sequentiel=0;
        break;
    case W_ASKCONFIRM:
        index_ask_confirm=0;
        reset_indexs_confirmation();
        window_focus_id=previous_window_focus_id;
        break;
    case W_PLOT:
        index_plot_window=0;
        index_plot_send_to_mode=0;
        index_editing_theatre_plan=0;
        break;
    case W_DRAW:
        index_draw_window=0;
        break;
    case W_ECHO:
        index_show_echo_window=0;
        break;
    case W_LIST:
        index_list_projecteurs=0;
        break;
    case W_SAVE:
        index_menu_save=0;
        break;
    case W_MAINMENU:
        index_show_main_menu=0;
        break;
    case W_BANGER:
        index_show_banger_window=0;
        over_banger_event=0;
        over_banger_action=0;
        over_family=0;
        position_mouse_z(0);  //reset
        mouse_level_for_event=mouse_z;
        mouse_level_for_banger=mouse_z;
        break;
    case W_ALARM:
        break;
    case W_AUDIO:
        index_show_audio_window=0;
        reset_audio_indexs_to_dock();
        index_affect_audio_to_dock=0;
        break;
    case W_CFGMENU:
        index_show_config_window=0;
        index_affect_dmxin=0;
        Midi_Faders_Affectation_Type=0;//pour ne pas affecter quoi que ce soit en midi
        Midi_Faders_Affectation_Mode=0;

        remember_config_page();
        //do_affectation_on_midi_affect_itself=0;
        break;
    case W_WIZARD:
        index_show_wizard_window=0;
        break;
    case W_MINIFADERS:
        index_show_minifaders=0;
        break;
    case W_CHASERS:
        index_affect_chaser_to_dock=0;
        index_window_chasers=0;
        break;
    case W_MOVER:
        index_show_mover_window=0;
        index_mouse_is_tracking=0;
        break;
    case W_iCAT:
        index_window_gui_iCat=0;
        break;
    case W_GRID:
        index_grider_window=0;
        index_do_affect_grid_to_fader=0;
        for(int i=0; i<4; i++)
        {
            grid_affect_to_dock[i]=0;
        }
        break;
    case W_WAVE:
        index_wave_menu_window=0;
        index_affect_wave_to_dock=0;
        break;
    case W_MY_WINDOW:
        index_my_window=0;
        break;
    default:
        break;
    }

    nbre_fenetre_actives--;

    if (nbre_fenetre_actives<=0)
    {
        nbre_fenetre_actives=0;
        window_focus_id=0;
    }

    return(0);
}
