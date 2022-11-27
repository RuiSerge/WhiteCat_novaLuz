int midipage_preset_and_options(int cfg_midiX,int cfg_midiY, int largeurCFGmidi,int hauteurCFGmidi)
{
    petitchiffrerouge.Print( my_midi_original_string,cfg_midiX+470,cfg_midiY+17);
    petitchiffre.Print( my_midi_string,cfg_midiX+500,cfg_midiY+32);
    for(int pm=0; pm<8; pm++)
    {
        Rect MidiOption(Vec2D(cfg_midiX+20,cfg_midiY+45+(pm*30)),Vec2D(55,20));
        MidiOption.SetRoundness(7.5);
        MidiOption.Draw(CouleurFond.WithAlpha(0.5));
        if(mouse_x>cfg_midiX+20 && mouse_x<cfg_midiX+20+55 && mouse_y>cfg_midiY+45+(pm*30) && mouse_y<cfg_midiY+45+20+(pm*30)  && window_focus_id==920)
        {
            MidiOption.Draw(CouleurSurvol) ;
            if(mouse_button==1 && mouse_released==0)
            {
                switch(pm)
                {
                case 0:
                    cheat_key_off=toggle(cheat_key_off);
                    break;
                case 1:
                    cheat_key_off_to_key_on=toggle(cheat_key_off_to_key_on);
                    break;
                case 2:
                    index_midi_auto_desaffect=toggle(index_midi_auto_desaffect);
                    break;
                case 3://auto demute
                    index_midi_auto_demute=toggle(index_midi_auto_demute);
                    break;
                case 4://mute on LFO
                    index_midi_mute_on_lfo=toggle(index_midi_mute_on_lfo);
                    break;
                case 5://automute speed midi on cuelist
                    index_auto_mute_cuelist_speed=toggle(index_auto_mute_cuelist_speed);
                    break;
                case 6:
                    enable_launchpad=toggle(enable_launchpad);
                    if(enable_launchpad==1)
                    {
                        reset_launchpad();
                    }
                    break;
                case 7:
                    index_midi_global_thruth=toggle(index_midi_global_thruth);
                    break;
                default:
                    break;
                }
                mouse_released=1;
            }
        }
        switch(pm)
        {
        case 0:
            MidiOption.Draw(CouleurFader.WithAlpha(cheat_key_off)) ;
            petitpetitchiffre.Print("Key-On Vel 0 = Key-Off",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 1:
            MidiOption.Draw(CouleurFader.WithAlpha(cheat_key_off_to_key_on)) ;
            petitpetitchiffre.Print("Key-Off = Key-On Vel 0",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 2:
            MidiOption.Draw(CouleurFader.WithAlpha(index_midi_auto_desaffect)) ;
            petitpetitchiffre.Print("Auto-Desaffectation",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 3://auto demute
            MidiOption.Draw(CouleurFader.WithAlpha(index_midi_auto_demute)) ;
            petitpetitchiffre.Print("Auto-demute",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 4://mute on LFO
            MidiOption.Draw(CouleurFader.WithAlpha(index_midi_mute_on_lfo)) ;
            petitpetitchiffre.Print("Mute on LFO",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 5:
            MidiOption.Draw(CouleurFader.WithAlpha(index_auto_mute_cuelist_speed)) ;
            petitpetitchiffre.Print("Auto-mute Cuelist Speed",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 6:
            MidiOption.Draw(CouleurFader.WithAlpha(enable_launchpad)) ;
            petitpetitchiffre.Print("To LAUNCHPAD",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        case 7:
            MidiOption.Draw(CouleurFader.WithAlpha(index_midi_global_thruth)) ;
            petitpetitchiffre.Print("Midi THRU",cfg_midiX+80,cfg_midiY+57+(pm*30));
            break;
        default:
            break;
        }
    }

    midi_launchpad_colors(cfg_midiX+230,cfg_midiY+60);
    midi_change_signal(cfg_midiX+355, cfg_midiY+70);


    midi_clock_part(cfg_midiX+570, cfg_midiY+55);//on off midi clock and BPM


    return(0);
}
