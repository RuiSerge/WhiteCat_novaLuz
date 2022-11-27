int write_window_indexes_from_list_of_windows()
{
    close_all_windows();
    for(int i=0; i<63; i++)
    {
        switch(window_opened[i])
        {
        case W_SAVEREPORT:
            break;
        case W_TRICHROMY:
            index_trichro_window=1;
            break;
        case W_NUMPAD:
            index_visual_pad=1;
            break;
        case W_TRACKINGVIDEO:
            index_video_window=1;
            break;
        case W_ARTPOLLREPLY:
            index_show_artpoll_reply_content=1;
            break;
        case W_FADERS :
            index_show_faders=1;
            break;
        case W_PATCH:
            index_patch_window=1;
            break;
        case W_TIME:
            index_time=1;
            break;
        case W_SEQUENCIEL:
            index_window_sequentiel=1;
            break;
        case W_ASKCONFIRM:
            //nothing
            break;
        case W_PLOT:
            index_plot_window=1;
            break;
        case W_ECHO:
            index_show_echo_window=1;
            break;
        case W_LIST:
            index_list_projecteurs=1;
            break;
        case W_SAVE:
            index_menu_save=1;
            break;
        case W_MAINMENU:
            index_show_main_menu=1;
            break;
        case W_BANGER:
            index_show_banger_window=1;
            break;
        case W_ALARM:
            break;
        case W_AUDIO:
            index_show_audio_window=1;
            break;
        case W_CFGMENU:
            index_show_config_window=1;
            break;
        case W_WIZARD:
            index_show_wizard_window=1;
            break;
        case W_MINIFADERS:
            index_show_minifaders=1;
            break;
        case W_CHASERS:
            index_window_chasers=1;
            break;
        case W_MOVER:
            index_show_mover_window=1;
            break;
        case W_iCAT:
            index_window_gui_iCat=1;
            break;
        case W_GRID:
            index_grider_window=1;
            break;
        case W_MY_WINDOW:
            index_my_window=1;
            break;
        default:
            break;
        }
    }
    return(0);
}
