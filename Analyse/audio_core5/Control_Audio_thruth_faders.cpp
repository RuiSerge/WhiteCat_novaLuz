int Control_Audio_thruth_faders(int ff, int dd, int typ)//typ 0 vol / 1 pan / 2 pitch
{
    int player_to_remote=0;
    int vol_to_send=(255- curve_report[(FaderCurves[ff])][(Fader[ff])])/2;
    if(vol_to_send>127)
    {
        vol_to_send=127;
    }

    switch(typ)
    {
    case 0://VOLUME
        player_to_remote=DockHasAudioVolume[ff][dd]-1;
        player_niveauson[player_to_remote]=vol_to_send;
        midi_levels[616+player_to_remote]=vol_to_send;
        if(player_ignited[player_to_remote]==1 && index_loading_a_sound_file==0)
        {
            switch(player_to_remote)
            {
            case 0:
                player1->setVolume(((float)player_niveauson[player_to_remote])/127);
                break;
            case 1:
                player2->setVolume(((float)player_niveauson[player_to_remote])/127);
                break;
            case 2:
                player3->setVolume(((float)player_niveauson[player_to_remote])/127);
                break;
            case 3:
                player4->setVolume(((float)player_niveauson[player_to_remote])/127);
                break;
            default:
                break;
            }
        }
        break;
    case 1://PAN
        player_to_remote=DockHasAudioPan[ff][dd]-1;
        player_pan[player_to_remote]=vol_to_send;
        midi_levels[620+player_to_remote]=vol_to_send;
        if(player_ignited[player_to_remote]==1 && index_loading_a_sound_file==0)
        {
            switch(player_to_remote)
            {
            case 0://PLAYER 1
                player1->setPan(((float)(player_pan[player_to_remote]-64))/63); // -64 /63 OK POUR AVOIR -1.00 +1.00 GAUCHE DROITE
                break;
            case 1://PLAYER 2
                player2->setPan(((float)(player_pan[player_to_remote]-64))/63);
                break;
            case 2://PLAYER 3
                player3->setPan(((float)(player_pan[player_to_remote]-64))/63);
                break;
            case 3://PLAYER 4
                player4->setPan(((float)(player_pan[player_to_remote]-64))/63);
                break;
            default:
                break;
            }
        }
        break;
    case 2://PITCH
        player_to_remote=DockHasAudioPitch[ff][dd]-1;
        player_pitch[player_to_remote]=vol_to_send;
        midi_levels[624+player_to_remote]=vol_to_send;
        if(player_ignited[player_to_remote]==1 && index_loading_a_sound_file==0)
        {
            switch(player_to_remote)
            {
            case 0://PLAYER 1
                player1->setPitchShift((((float)player_pitch[player_to_remote])/64));
                break;
            case 1://PLAYER 2
                player2->setPitchShift((((float)player_pitch[player_to_remote])/64));
                break;
            case 2://PLAYER 3
                player3->setPitchShift((((float)player_pitch[player_to_remote])/64));
                break;
            case 3://PLAYER 4
                player4->setPitchShift((((float)player_pitch[player_to_remote])/64));
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }


    return(0);
}
