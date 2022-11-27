int do_logical_fader_damper_commands(int _x,int _y, int fd)
{

    if(window_focus_id==W_FADERS)
    {
        if( mouse_x>_x && mouse_x<_x+20 && mouse_y>_y+20 && mouse_y<_y+40)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                if( Midi_Faders_Affectation_Type!=0 )
                {
                    attribute_midi_to_control((1912+fd), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    if(fader_damper_is_on[fd]==0)
                    {
                        Fader_dampered[fd].fix_all_damper_state_value(Fader[fd]);
                        Fader_dampered[fd].set_target_val(Fader[fd]);

                    }
                    fader_damper_is_on[fd]=toggle(fader_damper_is_on[fd]);

                }
                mouse_released=1;
            }
            if( Midi_Faders_Affectation_Type!=0)
            {
                switch(miditable[0][1912+fd])
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
                sprintf(string_last_midi_id,"Damper ON/OFF is Ch: %d Pitch: %d Type: %s", miditable[1][1912+fd],miditable[2][1912+fd],thetypinfo);
            }
        }

        if( mouse_x>_x+30 && mouse_x<=_x+157 && mouse_y>_y+15 && mouse_y<_y+27)
        {

            if( mouse_button==1 )
            {
                if( Midi_Faders_Affectation_Type!=0 && mouse_released==0)
                {
                    attribute_midi_to_control((1960+fd), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    mouse_released=1;
                }
                else
                {
                    set_mouse_range(_x+30, _y+15, _x+157, _y+27);
                    Fader_dampered[fd].set_damper_decay(1.0-(((float)(_x+157-mouse_x))/127));
                    midi_levels[1960+fd]=127-(_x+157-mouse_x);
                    index_send_midi_out[1960+fd]=1;
                }
            }
            if( Midi_Faders_Affectation_Type!=0)
            {
                switch(miditable[0][1960+fd])
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
                sprintf(string_last_midi_id,"Damper Decay is Ch: %d Pitch: %d Type: %s", miditable[1][1960+fd],miditable[2][1960+fd],thetypinfo);
            }

        }

        if( mouse_x>_x+30 && mouse_x<=_x+157 && mouse_y>_y+35 && mouse_y<_y+47)
        {

            if( mouse_button==1 )
            {
                if( Midi_Faders_Affectation_Type!=0 && mouse_released==0)
                {
                    attribute_midi_to_control((2056+fd), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    mouse_released=1;
                }
                else
                {
                    set_mouse_range(_x+30, _y+35, _x+157, _y+47);
                    Fader_dampered[fd].set_damper_dt((1.0-(((float)(_x+157-mouse_x))/127))/10);
                    midi_levels[2056+fd]=127-(_x+157-mouse_x);
                    index_send_midi_out[2056+fd]=1;
                }
            }
            if( Midi_Faders_Affectation_Type!=0)
            {
                switch(miditable[0][2056+fd])
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
                sprintf(string_last_midi_id,"Damper DT is Ch: %d Pitch: %d Type: %s", miditable[1][2056+fd],miditable[2][2056+fd],thetypinfo);
            }

        }


        if( mouse_x>_x+137 && mouse_x<_x+157 && mouse_y>_y && mouse_y<_y+10)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                if( Midi_Faders_Affectation_Type!=0 )
                {
                    attribute_midi_to_control((2008+fd), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    Fader_dampered[fd].set_damper_mode((Fader_dampered[fd].getdampermode()+1));
                    mouse_released=1;
                }
            }
            if( Midi_Faders_Affectation_Type!=0)
            {
                switch(miditable[0][2008+fd])
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
                sprintf(string_last_midi_id,"Damper Mode is Ch: %d Pitch: %d Type: %s", miditable[1][2008+fd],miditable[2][2008+fd],thetypinfo);
            }
        }

        button_midi_out_core(_x+130,_y+65,(fd+1960));//DECAY
        button_midi_out_core(_x+150,_y+65,(fd+2056));//DT

    }

    /*
    if( mouse_x>_x+147 && mouse_x<_x+160 && mouse_y>_y+55 && mouse_y<_y+65 && mouse_button==1 && mouse_released==0)
    {
    midi_send_out[fd+1960]=toggle(midi_send_out[fd+1960]);
    mouse_released=1;
    }*/
    return(0);
}
