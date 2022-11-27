int do_logical_fenetre_chasers(int xcha,int ycha)
{





    if( mouse_x>xcha+220-12 && mouse_x<xcha+220+12 && mouse_y>ycha+25-12 && mouse_y<ycha+25+12  )
    {
        show_type_midi(974, "Previous CHASER");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(974,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_selected--;
            if(chaser_selected<0)
            {
                chaser_selected=core_user_define_nb_chasers-1;
            }
            refresh_chaser_midi_out();
        }
        mouse_released=1;
    }
    if(mouse_x>xcha+300-12 && mouse_x<xcha+300+12 && mouse_y>ycha+25-12 && mouse_y<ycha+25+12 )
    {
        show_type_midi(975, "Next CHASER");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(975,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_selected++;
            if(chaser_selected>core_user_define_nb_chasers-1)
            {
                chaser_selected=0;
            }
            refresh_chaser_midi_out();
        }
        mouse_released=1;
    }


    if(index_enable_edit_chaser==1 && index_type==1 && mouse_x>xcha+330 && mouse_x<xcha+330+185 && mouse_y>ycha+10 && mouse_y<ycha+10+30)
    {
        sprintf(chaser_name[chaser_selected],numeric);
        reset_numeric_entry();
        if(index_text_auto_close==1)
        {
            index_type=0;
        }
        mouse_released=1;
    }
    if(mouse_x>xcha+560 && mouse_x<xcha+560+50 && mouse_y>ycha+10 && mouse_y<ycha+10+20 )
    {
        if(mouse_button==1 && mouse_released==0)
        {
            index_enable_edit_chaser=toggle(index_enable_edit_chaser);
            mouse_released=1;
        }
    }

    if(mouse_x>xcha+10 && mouse_x<xcha+10+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20  && mouse_released==0)
    {
        show_type_midi(978, "Play Selected CHASER");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(978,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_is_playing[chaser_selected]=toggle(chaser_is_playing[chaser_selected]);
            if(chaser_is_playing[chaser_selected]==1)//snap du temps at beg
            {
                chaser_start_time[chaser_selected]=actual_time;
                if(chaser_step_is[chaser_selected]<0)
                {
                    chaser_step_is[chaser_selected]=0;
                }
                else if(chaser_step_is[chaser_selected]>35)
                {
                    chaser_step_is[chaser_selected]=35;
                }
            }
        }
        mouse_released=1;
    }
    if(mouse_x>xcha+40 && mouse_x<xcha+40+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20  && mouse_button==1 && mouse_released==0)
    {
        show_type_midi(979, "Seek to Beg Selected CHASER");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(979,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_seek_at_beg(chaser_selected);
        }
        mouse_released=1;
    }

    if(mouse_x>xcha+70 && mouse_x<xcha+70+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20  && mouse_button==1 && mouse_released==0)
    {
        show_type_midi(980, "Loop Selected CHASER");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(980,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_is_in_loop[chaser_selected]=toggle(chaser_is_in_loop[chaser_selected]);
            switch(chaser_is_in_loop[chaser_selected])
            {
            case 0:
                sprintf(string_Last_Order,">> LOOP OFF Chaser %d",chaser_selected+1);
                break;
            case 1:
                sprintf(string_Last_Order,">> LOOP ON Chaser %d",chaser_selected+1);
                break;
            default:
                break;
            }
        }
        mouse_released=1;
    }





    if(mouse_x>xcha+110 && mouse_x<xcha+110+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20 && mouse_released==0)
    {
        show_type_midi(981, "Chaser Forward WAY");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(981,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_way[chaser_selected]=0;
            sprintf(string_Last_Order,">> FORWARD WAY Chaser %d",chaser_selected+1);
        }
        mouse_released=1;
    }


    if(mouse_x>xcha+140 && mouse_x<xcha+140+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20&& mouse_released==0)
    {
        show_type_midi(982, "Chaser Backward WAY");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(982,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_way[chaser_selected]=1;
            sprintf(string_Last_Order,">> BACKWARD WAY Chaser %d",chaser_selected+1);
        }
        mouse_released=1;
    }


    if(mouse_x>xcha+170 && mouse_x<xcha+170+20 && mouse_y>ycha+50 && mouse_y<ycha+50+20 && mouse_released==0)
    {
        show_type_midi(983, "Chaser ALLER-RETOUR WAY");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(983,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_aller_retour[chaser_selected]=toggle(chaser_aller_retour[chaser_selected]);
            sprintf(string_Last_Order,">> ALLER-RETOUR WAY Chaser %d",chaser_selected+1);
        }
        mouse_released=1;
    }


    if(mouse_x>xcha+430 && mouse_x<xcha+430+110 && mouse_y>ycha+80 && mouse_y<ycha+80+20  && mouse_released==0)
    {
        if(index_affect_chaser_to_dock==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_affect_chaser_to_dock=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_affect_chaser_to_dock;
        mouse_released=1;
    }


    if(mouse_x>xcha+10 && mouse_x<xcha+10+20 && mouse_y>ycha+80 && mouse_y<ycha+80+20 )
    {
        show_type_midi(984, "Chaser ON/OFF ALL tracks");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(984,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_select_all_track(chaser_selected);
        }
        mouse_released=1;
    }


    if(mouse_x>xcha+40 && mouse_x<xcha+40+20 && mouse_y>ycha+80 && mouse_y<ycha+80+20 )
    {
        show_type_midi(985, "Chaser ON/OFF Inversed Tracks");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(985,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_select_inv_track(chaser_selected);
        }
        mouse_released=1;
    }

    if(mouse_x>xcha+70 && mouse_x<xcha+70+20 && mouse_y>ycha+80 && mouse_y<ycha+80+20 )
    {
        show_type_midi(986, "Chaser ALL OFF Tracks");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(986,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_select_off_all_track(chaser_selected);
        }
        mouse_released=1;
    }





    for(int po=0; po<4; po++)
    {
        if(mouse_x>xcha+110+(po*30) && mouse_x<xcha+110+(po*30)+20 && mouse_y>ycha+80 && mouse_y<ycha+80+20 )
        {
            char tlp_str[64];
            sprintf(tlp_str,"Chaser Track Preset %d in Chaser %d", po+1, chaser_selected+1);
            show_type_midi(987+po,tlp_str );
            if( Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(987+po,Midi_Faders_Affectation_Mode);
            }
            else
            {
                if(index_do_dock==0 && index_main_clear==0)
                {
                    chaser_load_from_preset(chaser_selected,po);
                    mouse_released=1;
                }
                if(index_enable_edit_chaser==1)
                {
                    if(index_do_dock==1 && index_main_clear==0)
                    {
                        chaser_selected_for_record=chaser_selected;
                        chaser_preset_selected_for_record=po;
                        index_do_store_chaser_preset=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                    else if( index_main_clear==1 && index_do_dock==0 )
                    {
                        chaser_selected_for_record=chaser_selected;
                        chaser_preset_selected_for_record=po;
                        index_do_clear_chaser_preset=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                }
            }

        }
    }


    ////////////////////Time unit////////////////////////////////////////
    if(mouse_x>xcha+245 && mouse_x<xcha+245+50 && mouse_y>ycha+50 && mouse_y<ycha+50+20)
    {
        time_unit[chaser_selected]=atof(numeric);
        if(time_unit[chaser_selected]<=0.0001)
        {
            time_unit[chaser_selected]=0.0001;
        }
        reset_numeric_entry();
        mouse_released=1;
    }

    if(mouse_x>xcha+305 && mouse_x<xcha+305+30 && mouse_y>ycha+50 && mouse_y<ycha+50+20)
    {
        show_type_midi(994,"Chaser Time TYPE" );
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(994,Midi_Faders_Affectation_Mode);
        }
        else
        {
            chaser_time_mode[chaser_selected]=toggle(chaser_time_mode[chaser_selected]);
        }
        mouse_released=1;
    }

    ////////////////////CHASER OPERATOR/////////////////////////////////////
    if(mouse_x>xcha+245 && mouse_x<xcha+245+40 && mouse_y>ycha+80 && mouse_y<ycha+80+20)
    {
        show_type_midi(991, "Chaser Set Position FADE IN");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(991,Midi_Faders_Affectation_Mode);
        }
        else
        {
            if(chaser_operator_is!=1)
            {
                chaser_operator_is=1;
            }
            else
            {
                chaser_operator_is=0;
            }
        }
        mouse_released=1;
    }
    if(mouse_x>xcha+295 && mouse_x<xcha+295+40 && mouse_y>ycha+80 && mouse_y<ycha+80+20)
    {
        show_type_midi(992, "Chaser Set Position STAY");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(992,Midi_Faders_Affectation_Mode);
        }
        else
        {
            if(chaser_operator_is!=2)
            {
                chaser_operator_is=2;
            }
            else
            {
                chaser_operator_is=0;
            }
        }
        mouse_released=1;
    }
    if(mouse_x>xcha+345 && mouse_x<xcha+345+40 && mouse_y>ycha+80 && mouse_y<ycha+80+20)
    {
        show_type_midi(993, "Chaser Set Position FADE OUT");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(993,Midi_Faders_Affectation_Mode);
        }
        else
        {
            if(chaser_operator_is!=3)
            {
                chaser_operator_is=3;
            }
            else
            {
                chaser_operator_is=0;
            }
        }
        mouse_released=1;
    }

    ///TIMELINE
    if(mouse_x>xcha+175 && mouse_x<xcha+175+(nbre_de_cases_par_track*12) && mouse_y>ycha+115 && mouse_y<ycha+115+12)
    {
        show_type_midi(995, "Chaser Set BEGIN POINT");
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(995,Midi_Faders_Affectation_Mode);
        }
        else
        {
            set_mouse_range(xcha+175,ycha+115,xcha+175+(nbre_de_cases_par_track*12), ycha+115+12); //pour pas deborder
            chaser_begin_step_is[chaser_selected]=(int)(((float)(mouse_x- (xcha+175)))/12);
            if(chaser_begin_step_is[chaser_selected]>=chaser_end_step_is[chaser_selected])
            {
                chaser_begin_step_is[chaser_selected]=chaser_end_step_is[chaser_selected]-1;
            }
            if(chaser_begin_step_is[chaser_selected]<0)
            {
                chaser_begin_step_is[chaser_selected]=0;
            }
            midi_levels[995]=(int)(((float)(chaser_begin_step_is[chaser_selected])/36)*127);
            index_send_midi_out[995]=1;
        }
    }
    if(mouse_x>xcha+175 && mouse_x<xcha+175+(nbre_de_cases_par_track*12) && mouse_y>ycha+127 && mouse_y<ycha+127+12)
    {
        show_type_midi(996, "Chaser Set END POINT");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(996,Midi_Faders_Affectation_Mode);
        }
        else
        {
            set_mouse_range(xcha+175,ycha+127,xcha+175+(nbre_de_cases_par_track*12), ycha+127+12); //pour pas deborder
            chaser_end_step_is[chaser_selected]=(int)(((float)(mouse_x- (xcha+175)))/12);
            if(chaser_end_step_is[chaser_selected]<=chaser_begin_step_is[chaser_selected])
            {
                chaser_end_step_is[chaser_selected]=chaser_begin_step_is[chaser_selected]+1;
            }
            if(chaser_end_step_is[chaser_selected]>nbre_de_cases_par_track)
            {
                chaser_end_step_is[chaser_selected]=nbre_de_cases_par_track;
            }
            midi_levels[996]=(int)(((float)(chaser_end_step_is[chaser_selected])/36)*127);
            index_send_midi_out[996]=1;
        }
    }


    if(mouse_x>xcha+175 && mouse_x<xcha+175+(nbre_de_cases_par_track*12) && mouse_y>ycha+145 && mouse_y<ycha+145+10)
    {
        show_type_midi(997, "Chaser Set TIMELINE POSITION");
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(997,Midi_Faders_Affectation_Mode);
        }
        else
        {
            set_mouse_range(xcha+175,ycha+145,xcha+175+(nbre_de_cases_par_track*12), ycha+145+10); //pour pas deborder
            chaser_step_is[chaser_selected]=(int)((mouse_x-( Xchasers+175))/12);
            chaser_calcul_step(chaser_selected,12.0/(float)((mouse_x-( Xchasers+175))/12));
            chaser_calcul_time_joint(chaser_selected);
            midi_levels[997]=(int)(((float)(chaser_step_is[chaser_selected])/36)*127);
            index_send_midi_out[997]=1;
            sprintf(string_Last_Order,"Chaser %d Time Line move to step %d",chaser_selected+1,chaser_step_is[chaser_selected]+1);
        }
    }
    bouton_view_track_downup_core(xcha+580, ycha+35,0);

    for(int track_num=0; track_num<nbre_track_visualisables; track_num++)
    {
        Track_draw_logical(xcha+5,ycha+165+(track_num*40),position_affichage_track_num[chaser_selected]+track_num);
    }

    if(mouse_x>xcha+345 && mouse_x<xcha+345+40 && mouse_y>ycha+50 && mouse_y<ycha+50+20)
    {
        index_slave_chaser_to_accelerometre[chaser_selected]=toggle(index_slave_chaser_to_accelerometre[chaser_selected]);
        mouse_released=1;
    }
    if(mouse_x>xcha+410 && mouse_x<xcha+410+40 && mouse_y>ycha+50 && mouse_y<ycha+50+20)
    {
        launchpad_chaser_mode=toggle(launchpad_chaser_mode);
        mouse_released=1;
    }
    if(launchpad_chaser_mode==1)
    {
        bouton_view_launchpad_pos_core(xcha+450, ycha+35,0);
    }


    if(mouse_x>xcha+520 && mouse_x<xcha+520+40 && mouse_y>ycha+50 && mouse_y<ycha+50+20 && mouse_released==0)
    {
        refresh_midi_chasers=toggle( refresh_midi_chasers);
        set_refresh_mode_for_chaser(refresh_midi_chasers);
        mouse_released=1;
    }

    return(0);
}
