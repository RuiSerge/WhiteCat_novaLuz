int arduino_do_analog_in_whitecat()
{
    int vfader=0;
    int temp_ardniveauX1=0;
    int temp_ardniveauX2=0;

    for(int p=0; p<=arduino_max_analog; p++) //06/03/2016
    {
        if(ventilate_analog_data[p]==1)//activation de la reception
        {

            if(analog_data_from_arduino[p]!=previous_analog_data_from_arduino[p])
            {
                switch(arduino_analog_function_input[p])
                {
                case 1://affectation � un fader

                    vfader=arduino_analog_attribution_input[p];
                    fader_set_level(vfader,analog_data_from_arduino[p]);

                    if(lfo_mode_is[vfader]==1 || lfo_mode_is[vfader]==2 || lfo_cycle_is_on[vfader]==1)
                    {
                        lfo_mode_is[vfader]=0;
                        lfo_mode_is[vfader]=0;
                        lfo_cycle_is_on[vfader]=0;
                    }
                    break;
                case 2://affectation au speed d un fader
                    vfader=arduino_analog_attribution_input[p];
                    lfo_speed[vfader]=analog_data_from_arduino[p]/2;
                    if(lfo_speed[vfader]<0)
                    {
                        lfo_speed[vfader]=0;
                    }
                    if(lfo_speed[vfader]>127)
                    {
                        lfo_speed[vfader]=127;
                    }
                    midi_levels[196+vfader]=lfo_speed[vfader];
                    index_send_midi_out[196+vfader]=1;
                    break;
                case 3://Damper decay
                    vfader=arduino_analog_attribution_input[p];
                    Fader_dampered[vfader].set_damper_decay(((float)(analog_data_from_arduino[p]))/255);
                    midi_levels[1960+vfader]=127-(analog_data_from_arduino[p]/2);
                    index_send_midi_out[1960+vfader]=1;
                    break;
                case 4://damper delta
                    vfader=arduino_analog_attribution_input[p];
                    Fader_dampered[vfader].set_damper_dt((((float)(analog_data_from_arduino[p]))/255)/10);
                    midi_levels[2056+vfader]=127-(analog_data_from_arduino[p]/2);
                    index_send_midi_out[2056+vfader]=1;
                    break;
                case 5://grand master
                    if(index_allow_grand_master==1)
                    {
                        niveauGMaster=analog_data_from_arduino[p];
                        midi_levels[615]=(niveauGMaster/2);
                        if(midi_send_out[615]==1)
                        {
                            index_send_midi_out[615]=1;
                        }
                    }
                    break;
                case 6://sequenciel : Val 1 stage  Val 2 preset Val 3 speed
                    if(arduino_analog_attribution_input[p]==0 || arduino_analog_attribution_input[p]==1 )//traitement du crossfade manuel
                    {
                        if(arduino_analog_attribution_input[p]==0 )
                        {
                            temp_ardniveauX1=analog_data_from_arduino[p];
                            if(index_get_back_faders_need_to_be_done==0)
                            {
                                index_go=0;
                                index_go_back=0;
                                index_pause=0;
                                niveauX1=analog_data_from_arduino[p];
                                midi_levels[491]=niveauX1/2;
                                if(midi_send_out[491]==1)
                                {
                                    index_send_midi_out[491]=1;
                                }
                            }
                        }
                        if(arduino_analog_attribution_input[p]==1 )
                        {
                            temp_ardniveauX2=255-analog_data_from_arduino[p];
                            if(index_get_back_faders_need_to_be_done==0)
                            {
                                index_go=0;
                                index_go_back=0;
                                index_pause=0;
                                niveauX2=255-analog_data_from_arduino[p];
                                midi_levels[492]=analog_data_from_arduino[p]/2;//inversion faite dans le midi
                                if(midi_send_out[492]==1)
                                {
                                    index_send_midi_out[492]=1;
                                }
                            }
                        }

                        if(temp_ardniveauX1==0 && temp_ardniveauX2==255)
                        {
                            index_go=0;
                            index_go_back=0;
                            index_pause=0;
                            next_mem_crossfade_finished(position_preset);
                            index_x1_x2_together=1;
                            index_get_back_faders_need_to_be_done=1;
                            refresh_integrated_gridplayer1();
                        }
                        if(temp_ardniveauX1==255 && temp_ardniveauX2==0)
                        {
                            index_get_back_faders_need_to_be_done=0;
                        }
                    }
                    if(arduino_analog_attribution_input[p]==2)
                    {
                        crossfade_speed=analog_data_from_arduino[p]/2;
                        prepare_crossfade();
                        someone_changed_in_time_sequences=1;//icat
                    }
                    break;
                case 7:
                    draw_arduino_xy[0]=analog_data_from_arduino[p];
                    do_arduino_draw_input();
                    break;
                case 8:
                    draw_arduino_xy[1]=analog_data_from_arduino[p];
                    do_arduino_draw_input();
                    break;
                case 9:
                    draw_arduino_xy[2]=analog_data_from_arduino[p];
                    do_arduino_draw_input();
                    break;
                case 10:
                    draw_arduino_xy[3]=analog_data_from_arduino[p];
                    do_arduino_draw_input();
                    break;
                case 11://chaser track
                    vfader=arduino_analog_attribution_input[p];
                    if(vfader>=0 && vfader<24)
                    {
                        track_level[chaser_selected][vfader]=analog_data_from_arduino[p]/2;
                        midi_levels[1023+vfader]=analog_data_from_arduino[p]/2;
                        midi_levels[998+vfader]=127*track_is_on[chaser_selected][vfader];
                        index_send_midi_out[1023+vfader]=1;
                        index_send_midi_out[998+vfader]=1;
                    }
                    break;
                case 12://MIDI CH0
                    simulate_midi(4,0,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 13://MIDI CH1
                    simulate_midi(4,1,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 14://MIDI CH2
                    simulate_midi(4,2,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 15://MIDI CH3
                    simulate_midi(4,3,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 16://MIDI CH4
                    simulate_midi(4,4,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 17://MIDI CH5
                    simulate_midi(4,5,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 18://MIDI CH6
                    simulate_midi(4,6,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 19://MIDI CH7
                    simulate_midi(4,7,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 20://MIDI CH8
                    simulate_midi(4,8,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 21://MIDI CH9
                    simulate_midi(4,9,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 22://MIDI CH10
                    simulate_midi(4,10,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 23://MIDI CH11
                    simulate_midi(4,11,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 24://MIDI CH12
                    simulate_midi(4,12,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 25://MIDI CH13
                    simulate_midi(4,13,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 26://MIDI CH14
                    simulate_midi(4,14,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 27://MIDI CH15
                    simulate_midi(4,15,arduino_digital_function_input[p][1],analog_data_from_arduino[p]/2);
                    sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Ctrl-Chge");
                    break;
                case 28://WAVE
                    waver_control=analog_data_from_arduino[p]/10 ;
                    wave_calculations();
                    break;
                default:
                    break;

                }

            }
            previous_analog_data_from_arduino[p]=analog_data_from_arduino[p];
        }

    }

    return(0);
}
