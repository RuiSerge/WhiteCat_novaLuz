int do_midi_call_order(int control)
{

    fader_selected_for_record=control;
    dock_selected_for_record=detect_dock_used(control) ;
    if(index_do_dock==1  && index_direct_chan==0   && index_affect_chaser_to_dock==0  && index_affect_time==0 && index_affect_color_to_dock==0 && index_do_affect_net_to_dock==0
            && index_affect_dmxin==0 && index_affect_video_tracking_to_dock==0 && index_affect_audio_to_dock==0 && gridplayer_to_affect_is==-1
            && index_do_fgroup==0 && index_affect_to_dock_mover==0 )
    {
        index_do_record_on_faders=1;
        index_ask_confirm=1;
    }

    //store direct CH
    else if(index_do_dock==1 && index_direct_chan==1)
    {
        index_do_record_direct_ch=1;
        index_ask_confirm=1;
    }


    else if (  index_do_dock==1 && index_do_fgroup==1)
    {
        index_do_affect_fgroup=1;
        index_ask_confirm=1;
    }

    else if( index_do_dock==1 && index_affect_time==1)
    {
        show_im_recording_a_time=1;
        DoTimeToDock(fader_selected_for_record,dock_selected_for_record);
        sprintf(string_Last_Order,">>Time affected to Master %d Dock %d", fader_selected_for_record,dock_selected_for_record);
        index_affect_time=0;
        index_ask_confirm=1;
    }
    else if(index_do_dock==1 && index_affect_color_to_dock==1)
    {
        index_do_affect_color_on_faders=1;
        index_ask_confirm=1;
    }
    //Store Chaser dans dock
    else if (index_do_dock==1 && index_affect_chaser_to_dock==1 )
    {
        index_do_affect_fx=1;
        index_ask_confirm=1;
    }
    //Store Grid dans dock
    else if ( index_do_dock==1 &&  gridplayer_to_affect_is>=0 )
    {
        index_do_affect_grid_to_fader=1;
        index_ask_confirm=1;
    }

    else if( index_do_dock==1 && index_affect_video_tracking_to_dock==1)
    {
        index_do_video_to_dock=1;
        index_ask_confirm=1;
    }
    else if( index_do_dock==1 && index_affect_audio_to_dock==1)
    {
        if(player_to_affect_to_dock>=0 && player_to_affect_to_dock<4 )
        {
            index_do_audio_to_dock=1;
            index_ask_confirm=1;
        }
    }
    //Store Mover dans dock
    else if (  index_do_dock==1 && index_affect_to_dock_mover==1)
    {
        index_do_affect_mover=1;
        index_ask_confirm=1;
    }

    //Store Draw dans dock
    else if (  index_do_dock==1 && index_affect_draw_to_dock==1)
    {
        index_do_draw_affect_to_dock=1;
        index_ask_confirm=1;
    }

    else if( index_do_dock==1 && index_affect_dmxin==1)
    {
        index_do_dmx_to_dock=1;
        index_ask_confirm=1;
    }
    else if(index_do_dock==1 && index_do_affect_net_to_dock==1 )
    {
        index_do_artnet_to_dock=1;
        index_ask_confirm=1;
    }



    else if( index_do_modify==1 )
    {
        index_do_modify_on_faders=1;
        index_ask_confirm=1;
    }
    else if( index_do_report==1 )
    {
        index_do_report_on_faders=1;
        index_ask_confirm=1;
    }
    //clear
    else if( index_main_clear==1 )
    {
        index_do_clear_dock=1;
        index_ask_confirm=1;
    }
    else if( index_type==1 )
    {
        for(int tt=0; tt<24; tt++)
        {
            DockName[fader_selected_for_record][dock_selected_for_record ][tt]=numeric[tt];
        }
        DockName[fader_selected_for_record][dock_selected_for_record ][24]='\0';
        index_type=0;
        reset_numeric_entry();
        numeric_postext=0;
        sprintf(string_Last_Order,">>On Master %d GIVED A NAME FOR DOCK %d ",fader_selected_for_record,dock_selected_for_record );
        index_ask_confirm=1;
    }

    light_midi_do_order[control]=1.0;
    minifaders_selected[control]=toggle(minifaders_selected[control]);
    return(0);
}
