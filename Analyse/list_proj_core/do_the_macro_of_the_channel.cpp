int do_the_macro_of_the_channel(int the_chan, int num_macro)
{
    int the_Abanger_num=0;

    switch(channel_macro_action[the_chan][num_macro])
    {
    case 0://-
        break;
    case 1://Bang Banger
        the_Abanger_num=channel_macro_val[the_chan][num_macro][1]-1;
        start_time_for_banger[the_Abanger_num]=actual_time;
        end_time_for_banger[the_Abanger_num]=default_time_of_the_bang;
        for (int o=0; o<6; o++) //reset des �v�nements
        {
            event_sended[the_Abanger_num][o]=0;
            if(bangers_delay[the_Abanger_num][o]>end_time_for_banger[the_Abanger_num])
            {
                end_time_for_banger[the_Abanger_num]=bangers_delay[the_Abanger_num][o];
            }
        }
        bang_is_sended[the_Abanger_num]=0;//reset du bang sended is
        break;
    case 2://Load Audio
        if(channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8 )//follow pur
        {
            switch(dmx_view)
            {
            case 0:
                audiofile_selected=(int)(((float)MergerArray[the_chan])/2.55);
                if(channel_macro_reaction[the_chan][num_macro]==8)
                {
                    audiofile_selected=100-(int)(((float)MergerArray[the_chan])/2.55);
                }
                if(audiofile_selected<0)
                {
                    audiofile_selected=0;
                }
                if(audiofile_selected>100)
                {
                    audiofile_selected=100;
                }
                break;
            case 1:
                audiofile_selected=MergerArray[the_chan];
                if(channel_macro_reaction[the_chan][num_macro]==8)
                {
                    audiofile_selected=127-audiofile_selected;
                }
                if(audiofile_selected<0)
                {
                    audiofile_selected=0;
                }
                if(audiofile_selected>127)
                {
                    audiofile_selected=127;
                }
                break;
            default:
                break;
            }
            sprintf(audiofile_name,list_audio_files[audiofile_selected]);
            AffectSoundFile(channel_macro_val[the_chan][num_macro][1]-1);
        }


        break;
    case 3://Play A.Pl
        if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1)
        {
            switch(channel_macro_val[the_chan][num_macro][1]-1)
            {
            case 0://PLAYER 1
                player1->play();
                break;
            case 1://PLAYER 2
                player2->play();
                break;
            case 2://PLAYER 3
                player3->play();
                break;
            case 3://PLAYER 4
                player4->play();
                break;
            default:
                break;
            }
        }
        break;
    case 4://Stop A.Pl
        if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1)
        {
            switch(channel_macro_val[the_chan][num_macro][1]-1)
            {
            case 0://PLAYER 1
                player1->stop();
                break;
            case 1://PLAYER 2
                player2->stop();
                break;
            case 2://PLAYER 3
                player3->stop();
                break;
            case 3://PLAYER 4
                player4->stop();
                break;
            default:
                break;
            }
        }
        break;
    case 5://Seek A.Pl
        if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1)
        {
            switch(channel_macro_val[the_chan][num_macro][1]-1)
            {
            case 0://PLAYER 1
                player1->setPosition(0);
                break;
            case 1://PLAYER 2
                player2->setPosition(0);
                break;
            case 2://PLAYER 3
                player3->setPosition(0);
                break;
            case 3://PLAYER 4
                player4->setPosition(0);
                break;
            default:
                break;
            }
        }
        break;
    case 6://Loop ON A.Pl
        if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1)
        {
            switch(channel_macro_val[the_chan][num_macro][1]-1)
            {
            case 0://PLAYER 1
                player1->setRepeat(true);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=1;
                break;
            case 1://PLAYER 2
                player2->setRepeat(true);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=1;
                break;
            case 2://PLAYER 3
                player3->setRepeat(true);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=1;
                break;
            case 3://PLAYER 4
                player4->setRepeat(true);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=1;
                break;
            default:
                break;
            }
        }
        break;
    case 7://Loop Off A.Pl
        if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1)
        {
            switch(channel_macro_val[the_chan][num_macro][1]-1)
            {
            case 0://PLAYER 1
                player1->setRepeat(false);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=0;
                break;
            case 1://PLAYER 2
                player2->setRepeat(false);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=0;
                break;
            case 2://PLAYER 3
                player3->setRepeat(false);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=0;
                break;
            case 3://PLAYER 4
                player4->setRepeat(false);
                player_is_onloop[channel_macro_val[the_chan][num_macro][1]-1]=0;
                break;
            default:
                break;
            }
        }
        break;
    case 8://Volume A.Pl
        if(channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8 )//follow pur
        {
            float lev_to_do=((float)MergerArray[the_chan])/255.0;

            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                lev_to_do=127.0-lev_to_do;
            }
            if(lev_to_do>1.0)
            {
                lev_to_do=1.0;
            }
            else if(lev_to_do<0.0)
            {
                lev_to_do=0.0;
            }

            if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1 && index_loading_a_sound_file==0)
            {
                switch(channel_macro_val[the_chan][num_macro][1]-1)
                {
                case 0:
                    player1->setVolume(lev_to_do);
                    break;
                case 1:
                    player2->setVolume(lev_to_do);
                    break;
                case 2:
                    player3->setVolume(lev_to_do);
                    break;
                case 3:
                    player4->setVolume(lev_to_do);
                    break;
                default:
                    break;
                }
                player_niveauson[channel_macro_val[the_chan][num_macro][1]-1]=(int)(lev_to_do*127);
                midi_levels[616+channel_macro_val[the_chan][num_macro][1]-1]=(int)(lev_to_do*127);
                if(midi_send_out[616+channel_macro_val[the_chan][num_macro][1]-1]==1)
                {
                    index_send_midi_out[616+channel_macro_val[the_chan][num_macro][1]-1]=1;   //vol
                }
            }
        }
        break;
    case 9://Pan A.Pl
        if(channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8  )//follow pur
        {
            float pitc_to_do=(((float)MergerArray[the_chan])/255.0)*127.0;

            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                pitc_to_do=127.0-pitc_to_do;
            }

            if(pitc_to_do>127.0)
            {
                pitc_to_do=127.0;
            }
            else if(pitc_to_do<0.0)
            {
                pitc_to_do=0.0;
            }

            if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1 && index_loading_a_sound_file==0)
            {
                switch(channel_macro_val[the_chan][num_macro][1]-1)
                {
                case 0:
                    player1->setPan((pitc_to_do-64)/64);

                    break;
                case 1:
                    player2->setPan((pitc_to_do-64)/64);
                    break;
                case 2:
                    player3->setPan((pitc_to_do-64)/64);
                    break;
                case 3:
                    player4->setPan((pitc_to_do-64)/64);
                    break;
                default:
                    break;
                }
                player_pan[channel_macro_val[the_chan][num_macro][1]-1]=(int)(pitc_to_do);
                midi_levels[620+channel_macro_val[the_chan][num_macro][1]-1]=(int)(pitc_to_do);
                if(midi_send_out[620+channel_macro_val[the_chan][num_macro][1]-1]==1)
                {
                    index_send_midi_out[620+channel_macro_val[the_chan][num_macro][1]-1]=1;   //vol
                }
            }
        }
        break;
    case 10://Pitch A.Pl
        if(channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8 )//follow pur
        {
            float pitc_to_do=0.0;

            pitc_to_do=(((float)MergerArray[the_chan])/255.0)*127.0;

            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                pitc_to_do=127.0-pitc_to_do;
            }


            if(pitc_to_do>127.0)
            {
                pitc_to_do=127.0;
            }
            else if(pitc_to_do<0.0)
            {
                pitc_to_do=0.0;
            }

            if(player_ignited[channel_macro_val[the_chan][num_macro][1]-1]==1 && index_loading_a_sound_file==0)
            {
                switch(channel_macro_val[the_chan][num_macro][1]-1)
                {
                case 0:
                    player1->setPitchShift(pitc_to_do/64);

                    break;
                case 1:
                    player2->setPitchShift(pitc_to_do/64);
                    break;
                case 2:
                    player3->setPitchShift(pitc_to_do/64);
                    break;
                case 3:
                    player4->setPitchShift(pitc_to_do/64);
                    break;
                default:
                    break;
                }
                player_pitch[channel_macro_val[the_chan][num_macro][1]-1]=(int)(pitc_to_do);
                midi_levels[624+channel_macro_val[the_chan][num_macro][1]-1]=(int)(pitc_to_do);
                if(midi_send_out[624+channel_macro_val[the_chan][num_macro][1]-1]==1)
                {
                    index_send_midi_out[624+channel_macro_val[the_chan][num_macro][1]-1]=1;   //vol
                }
            }

        }
        break;
    case 11://Midi Ch15 CC
        if(channel_macro_reaction[the_chan][num_macro]==8)
        {
            send_immidiateley_my_midi_cc(4,15,channel_macro_val[the_chan][num_macro][1],(127-(int)((float)MergerArray[the_chan])/2));
        }
        else
        {
            send_immidiateley_my_midi_cc(4,15,channel_macro_val[the_chan][num_macro][1],((int)((float)MergerArray[the_chan])/2));
        }
        break;
    case 12://Midi Ch15 KOn
        if(channel_macro_reaction[the_chan][num_macro]==8)
        {
            send_my_midi_note(1, 15, channel_macro_val[the_chan][num_macro][1], (127-(int)((float)MergerArray[the_chan])/2), 10);
        }
        else
        {
            send_my_midi_note(1, 15, channel_macro_val[the_chan][num_macro][1], ((int)((float)MergerArray[the_chan])/2), 10);
        }
        break;
    case 13://Midi Ch15 KOff
        if(channel_macro_reaction[the_chan][num_macro]==8)
        {
            send_my_midi_note(2, 15, channel_macro_val[the_chan][num_macro][1], (127-(int)((float)MergerArray[the_chan])/2), 10);
        }
        else
        {
            send_my_midi_note(2, 15, channel_macro_val[the_chan][num_macro][1], ((int)((float)MergerArray[the_chan])/2), 10);
        }
        break;
    case 14://FADER LEVEL
        if((channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8) && channel_macro_val[the_chan][num_macro][1]>0 && channel_macro_val[the_chan][num_macro][1]<49 )//follow pur
        {
            int num_f=(channel_macro_val[the_chan][num_macro][1]-1);
            fader_set_level(num_f,MergerArray[the_chan]);
            midi_levels[ num_f]=(int)(MergerArray[the_chan]/2);
            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                fader_set_level(num_f,255-Fader[ num_f]);
                midi_levels[ num_f]=127-midi_levels[ num_f];
            }

            if(midi_send_out[num_f]==1)
            {
                index_send_midi_out[num_f]=1;
            }
        }
        break;
    case 15://FADER SPEED
        if((channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8) && channel_macro_val[the_chan][num_macro][1]>0 && channel_macro_val[the_chan][num_macro][1]<49 )//follow pur
        {
            int num_f=(channel_macro_val[the_chan][num_macro][1]-1);
            lfo_speed[ num_f]=(int)(MergerArray[the_chan]/2);
            midi_levels[196+ num_f]=(int)(MergerArray[the_chan]/2);
            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                lfo_speed[ num_f]=127-lfo_speed[ num_f];
                midi_levels[ num_f]=127-midi_levels[ num_f];
            }

            if(midi_send_out[196+num_f]==1)
            {
                index_send_midi_out[196+num_f]=1;
            }
        }
        break;
    case 16:// Follow Channel
        chan_to_manipulate=channel_macro_val[the_chan][num_macro][0];
        if((channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8)
                && channel_macro_val[the_chan][num_macro][0]>0 && channel_macro_val[the_chan][num_macro][0]<512
                && channel_macro_val[the_chan][num_macro][1]>0 && channel_macro_val[the_chan][num_macro][1]<49 )//follow pur
        {
            int num_f=(channel_macro_val[the_chan][num_macro][1]-1);
            FaderDockContains[num_f][(dock_used_by_fader_is[num_f])][chan_to_manipulate] = MergerArray[the_chan];
            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                FaderDockContains[num_f][(dock_used_by_fader_is[num_f])][chan_to_manipulate] = 255-MergerArray[the_chan];
            }
        }
        break;
    case 17://follow on seq  with ratio
        chan_to_manipulate=channel_macro_val[the_chan][num_macro][0];
        if((channel_macro_reaction[the_chan][num_macro]==7 || channel_macro_reaction[the_chan][num_macro]==8)
                && channel_macro_val[the_chan][num_macro][0]>0 && channel_macro_val[the_chan][num_macro][0]<512
          )//follow pur
        {
            bufferSaisie[chan_to_manipulate] =(unsigned char) (((float)(MergerArray[the_chan])/100) * channel_macro_val[the_chan][num_macro][1]) ;
            if(channel_macro_reaction[the_chan][num_macro]==8)
            {
                bufferSaisie[chan_to_manipulate] = (unsigned char) (255-((float)(MergerArray[the_chan])/100) * channel_macro_val[the_chan][num_macro][1]) ;
            }
        }
        break;
    default:
        break;
    }

    return(0);
}
