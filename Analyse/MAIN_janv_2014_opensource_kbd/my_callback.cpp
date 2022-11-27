void my_callback(int flags) {
void my_callback(int flags) {




    mousePtr.CollectEvent(mouse_x, mouse_y) ;
    whc_mouseButton::c_CollectEvent(flags, mouse_x, mouse_y); //, mouseClicLeft, mouseClicMiddle, mouseClicRight);
    whc_mouseWheel::c_CollectEvent(flags, mouse_z, mouse_w); //, mouseScroll, mouseRoll);
    //


    if (flags & MOUSE_FLAG_LEFT_DOWN )
        {
        mouse_button=1;
        original_posx=mouse_x;original_posy=mouse_y;
        //sab 29/05/2013 deb ---------------------------------------------------------------
        //window_focus_id=detection_over_window();
        if (wc_askConfirmWindowIsOpen())
		{
			window_focus_id=W_ASKCONFIRM;
		}


        // sab 12/08/2016 hotkey -- DEB -- keep focus while waiting an answer
        else if (hk_manager.waiting_user_confirmation_on_a_choice())
		{
			window_focus_id=W_CFGMENU;
		}
        // sab 12/08/2016 hotkey -- FIN --
        else
		{
			window_focus_id=detection_over_window();
		}
		//sab 29/05/2013 fin ---------------------------------------------------------------
        if(window_focus_id==0 || window_focus_id==W_LIST ){snap_channels_selection_array(); }
        mouse_released=0;
        }

    else if (flags & MOUSE_FLAG_LEFT_UP )//relevage bouton
        {
        mouse_button=0; mouse_released=1;   //liberation du curseur souris
        index_click_move_faderspace=0; im_moving_a_window=0; index_mouse_is_tracking=0;
        index_moving_fader_space=0;index_moving_x_slide=0;index_moving_y_slide=0;
        index_click_inside_plot=0; plot_facteur_move_x=0;plot_facteur_move_y=0;
        index_click_inside_relativ_xy=0; rlativ_xm=0; rlativ_ym=0;
        index_editing_theatre_plan=0;moving_plan_relativ_x=0;moving_plan_relativ_y=0;
        editing_plan_data_type=0; editing_plot_sizey=0; editing_plot_sizex=0;  moving_size_relativ_x=0; moving_size_relativ_y=0;
        plot_editing_color_line=0; plot_editing_color_background=0; index_adjusting_shape_x=0;index_adjusting_shape_y=0;
        handle_selected_for_line_editing=0;  editing_shape_line_number=0;
        index_moving_channel_scroller=0;
        if(dragging_draw==1)
        {draw_point_is_traced[draw_preset_selected]=0;}
        dragging_draw=0; dragging_channel_in_echo=0;

        }

       if (flags & MOUSE_FLAG_RIGHT_DOWN )
        {
        original_posx=mouse_x;original_posy=mouse_y;
        mouse_R_button=1;
        mouse_R_released=0;

        if(window_focus_id==W_PLOT) {
                                    index_move_plot_view_port=1;
                                    reset_symbols_selected(view_plot_calc_number_is);
                                    unselect_all_shapes();
                                    key_unselect_ch();
                                    }
        else {
             if(mouse_R_released==0)
             {
              mouse_R_released=1;
              right_click_for_menu=1; //renvoi vers les procs en 10eme de secondes pour enlever le bug d extinctions fenetres
              }

             }
        }

       else if (flags & MOUSE_FLAG_RIGHT_UP )
        {
        mouse_R_button=0;
        mouse_R_released=1;
        index_move_plot_view_port=0;
        plot_facteur_move_x=0;plot_facteur_move_y=0;
        index_click_inside_plot=0;
        set_mouse_range(0, 0, SCREEN_W-1, SCREEN_H-1);//liberation du curseur souris
        }

        if(mouse_button==0)
        {set_mouse_range(0, 0, SCREEN_W-1, SCREEN_H-1);}

}
