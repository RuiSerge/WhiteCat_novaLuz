int do_logical_Interface_video_window(int WindowVideoX,int WindowVideoY)
{

    for (int i=0; i<2; i++)
    {
        if(mouse_x>WindowVideoX+90+(i*60) && mouse_x<WindowVideoX+140+(i*60)&& mouse_y> WindowVideoY+10 && mouse_y< WindowVideoY+25)//SIZE
        {
            camera_size_settings_is=i;
            if(mouse_released==0)
            {
                set_camera_size();
                set_image_caches();
                mouse_released=1;
            }
        }
    }


    for (int ct=0; ct<6; ct++)
    {
        if(mouse_x> WindowVideoX+20+(ct*60) && mouse_x< WindowVideoX+70+(ct*60))
        {
            if(mouse_y>WindowVideoY+frame_video_y+200 && mouse_y<WindowVideoY+frame_video_y+230)
            {
                if( Midi_Faders_Affectation_Type!=0)
                {
                    if(ct<4 && Midi_Faders_Affectation_Type==2)
                    {
                        attribute_midi_to_control(957+ct,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    }
                    else
                    {
                        attribute_midi_solo_affectation(957+ct,1);
                    }
                }
                else
                {

                    if(index_inspekt==1)
                    {
                        show_who_is_in_ROI_as_channel(tracking_dock_selected,ct);
                    }
                    if(edit_tracker==0 && move_tracker==0 && tracker_clearmode==0 && index_do_dock==0 && index_do_modify==0 && index_do_report==0)
                    {
                        tracking_spaces_on_off[tracking_dock_selected][ct]=toggle(tracking_spaces_on_off[tracking_dock_selected][ct]);
                    }
                    //affectation channels
                    else if(edit_tracker==0 && move_tracker==0 && tracker_clearmode==0 && (  index_do_dock==1 || index_do_modify==1 || index_do_report==1))
                    {
                        dock_roi_selected=ct;
                        index_do_affect_roi=1;
                        index_ask_confirm=1;
                    }

                    else if(tracker_clearmode==0 && (edit_tracker==1 || move_tracker==1))
                    {
                        tracker_to_edit=ct;
                        tracking_spaces_on_off[tracking_dock_selected][tracker_to_edit]=1;
                    }
                    else if(tracker_clearmode==1)
                    {
                        dock_roi_selected=ct;
                        index_do_clear_my_roi=1;
                        index_ask_confirm=1;
                    }
                    mouse_released=1;
                }
            }

            //ligne 2
            if(mouse_y>WindowVideoY+frame_video_y+250 && mouse_y<WindowVideoY+frame_video_y+280)
            {

                if(Midi_Faders_Affectation_Type!=0)
                {
                    attribute_midi_solo_affectation(957+ct+6,1);
                }
                else
                {
                    if(index_inspekt==1)
                    {
                        show_who_is_in_ROI_as_channel(tracking_dock_selected,ct+6);
                    }
                    if(edit_tracker==0 && move_tracker==0 && tracker_clearmode==0 && index_do_dock==0 && index_do_modify==0 && index_do_report==0)
                    {
                        tracking_spaces_on_off[tracking_dock_selected][ct+6]=toggle(tracking_spaces_on_off[tracking_dock_selected][ct+6]);
                    }
                    //affectation channels
                    else if(edit_tracker==0 && move_tracker==0 && tracker_clearmode==0 && (  index_do_dock==1 || index_do_modify==1 || index_do_report==1))
                    {
                        dock_roi_selected=ct+6;
                        index_do_affect_roi=1;
                        index_ask_confirm=1;
                    }

                    else if(tracker_clearmode==0 && (edit_tracker==1 || move_tracker==1))
                    {
                        tracker_to_edit=ct+6;
                        tracking_spaces_on_off[tracking_dock_selected][tracker_to_edit]=1;
                    }
                    else if(tracker_clearmode==1)
                    {
                        dock_roi_selected=ct+6;
                        index_do_clear_my_roi=1;
                        index_ask_confirm=1;
                    }
                    mouse_released=1;
                }
            }
        }
    }


    if(mouse_x>WindowVideoX+30 && mouse_x<WindowVideoX+90 && mouse_y>WindowVideoY+frame_video_y+150 && mouse_y<WindowVideoY+frame_video_y+150+30)
    {
        ocv_calcul_mode++;
        if(ocv_calcul_mode>1)
        {
            ocv_calcul_mode=0;
        }
        refresh_ocv_settings();
        mouse_released=1;
    }

    if(mouse_x>WindowVideoX+100 && mouse_x<WindowVideoX+100+60 && mouse_y>WindowVideoY+frame_video_y+150 && mouse_y<WindowVideoY+frame_video_y+150+30)
    {
        index_snap_background=1;
        Snap_Background();
        mouse_released=1;
    }

    if(ocvfilter_is_on==1)
    {
        do_logical_Set_Filtering_Image();
    }
    if(mouse_x>WindowVideoX+180 && mouse_x<WindowVideoX+280 && mouse_y> WindowVideoY+frame_video_y+140 && mouse_y< WindowVideoY+frame_video_y+180)
    {
        ocvfilter_is_on=toggle(ocvfilter_is_on);
        mouse_released=1;
    }

    if(mouse_x>WindowVideoX+300 && mouse_x<WindowVideoX+360 && mouse_y>WindowVideoY+frame_video_y+150 && mouse_y<WindowVideoY+frame_video_y+150+30)
    {
        if(tracker_clearmode==1)
        {
            tracker_clearmode=0;
        }
        else if(tracker_clearmode==0)
        {
            tracker_clearmode=1;
            move_tracker=0;
            edit_tracker=0;
        }
        mouse_released=1;
    }

    for (int ct=0; ct<5; ct++)
    {
        if(mouse_x>WindowVideoX+20+(ct*70) && mouse_x<WindowVideoX+80+(ct*70) && mouse_y>WindowVideoY+frame_video_y+370 && mouse_y<WindowVideoY+frame_video_y+400)
        {

            if( Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(969+ct,1);
            }
            else
            {
                switch (tracker_clearmode)
                {
                case 0:
                    tracking_dock_selected=ct;
                    break;
                case 1:
                    tracking_dock_to_clean=ct;
                    index_do_clear_my_video_preset=1;
                    index_ask_confirm=1;
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }
    }


    if(mouse_y>WindowVideoY+frame_video_y+300 && mouse_y<WindowVideoY+frame_video_y+330)
    {

        if(mouse_x>WindowVideoX+30 && mouse_x<WindowVideoX+90)
        {
            switch(edit_tracker)
            {
            case 0:
                move_tracker=0;
                edit_tracker=1;
                tracker_clearmode=0;
                break;
            case 1:
                edit_tracker=0;
                break;
            default:
                break;
            }
            mouse_released=1;
        }

        if(mouse_x>WindowVideoX+110 && mouse_x<WindowVideoX+170)
        {
            switch(move_tracker)
            {
            case 0:
                edit_tracker=0;
                move_tracker=1;
                tracker_clearmode=0;
                break;
            case 1:
                move_tracker=0;
                break;
            default:
                break;
            }
            mouse_released=1;
        }
    }

    if(edit_tracker==1)
    {
        ocvfilter_is_on=0;
        do_logical_Edit_Tracker_Size(tracking_dock_selected,tracker_to_edit);
    }


    if(move_tracker==1)
    {
        ocvfilter_is_on=0;
        do_logical_Move_Tracker(tracking_dock_selected,tracker_to_edit);
    }




    if(mouse_x>=videoX+200-20 && mouse_x<=videoX+200+127+20 && mouse_y>videoY+frame_video_y+310 && mouse_y<videoY+frame_video_y+310+30)
    {
        switch(miditable[0][498])
        {
        case 0:
            sprintf(thetypinfo,"Note");
            break;
        case 1:
            sprintf(thetypinfo,"Key On");
            break;
        case 2:
            sprintf(thetypinfo,"Key Off");
            break;
        case 4:
            sprintf(thetypinfo,"Ctrl Change");
            break;
        default:
            break;
        }
        sprintf(string_last_midi_id,"DECAY is Ch: %d Pitch: %d Typ: %s", miditable[1][498],miditable[2][498],thetypinfo);

        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            type_of_midi_button=4;
            attribute_midi_solo_affectation(498,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
        else
        {
            index_decay_tracker=mouse_x-(videoX+200);
            refresh_decay();
            midi_levels[498]=index_decay_tracker;
            if(midi_send_out[498]==1)
            {
                index_send_midi_out[498]=1;
            }
        }
    }

    if(mouse_x> (videoX+365-10) && mouse_x<(videoX+365+10)
            && mouse_y>(videoY+frame_video_y+350-10) && mouse_y<(videoY+frame_video_y+350+10))
    {

        midi_send_out[498]=toggle(midi_send_out[498]);
        mouse_released=1;
    }
    raccrochage_midi_logical_horizontal (videoX+200,videoY+frame_video_y+310, 498,127,30);


    if(mouse_x>videoX+(frame_video_y/2)-25 && mouse_x<videoX+(frame_video_y/2)-25+130 && mouse_y>videoY+frame_video_y+417 && mouse_y< videoY+frame_video_y+447)
    {
        if(index_affect_video_tracking_to_dock==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_affect_video_tracking_to_dock=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_affect_video_tracking_to_dock;
        mouse_released=1;
    }


    return(0);
}
