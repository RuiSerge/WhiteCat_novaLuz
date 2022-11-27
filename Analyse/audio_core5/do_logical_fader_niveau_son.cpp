int do_logical_fader_niveau_son(int xp, int yp, int numero)
{

    if(mouse_x>xp && mouse_x<xp+20 && mouse_y>=yp && mouse_y<=yp+127)
    {
        if (miditable[0][616+numero]==0)
        {
            sprintf(thetypinfo,"Note");
        }
        if(miditable[0][616+numero]==1)
        {
            sprintf(thetypinfo,"Key On");
        }
        if (miditable[0][616+numero]==2)
        {
            sprintf(thetypinfo,"Key Off");
        }
        if (miditable[0][616+numero]==4)
        {
            sprintf(thetypinfo,"Ctrl Change");
        }
        sprintf(string_last_midi_id,"VolumePlayer %d is Ch: %d Pitch: %d Typ: %s", numero, miditable[1][616+numero],miditable[2][616+numero],thetypinfo);
        if( Midi_Faders_Affectation_Type!=0)
        {
            attribute_midi_solo_affectation(616+numero,Midi_Faders_Affectation_Mode);
        }
        else
        {
            player_niveauson[numero]=(YAudio+70+(numero*140)+127)-mouse_y;
            if(player_ignited[numero]==1)
            {
                switch(numero)
                {
                case 0:
                    player1->setVolume(((float)player_niveauson[numero])/127);
                    break;
                case 1:
                    player2->setVolume(((float)player_niveauson[numero])/127);
                    break;
                case 2:
                    player3->setVolume(((float)player_niveauson[numero])/127);
                    break;
                case 3:
                    player4->setVolume(((float)player_niveauson[numero])/127);
                    break;
                default:
                    break;
                }
                midi_levels[616+numero]=player_niveauson[numero];
                if(midi_send_out[616+numero]==1)
                {
                    index_send_midi_out[616+numero]=1;   //vol
                }
            }
        }
    }


    if(mouse_x>xp+30 && mouse_x<xp+42 && mouse_y> yp+112 && mouse_y<yp+126)
    {
        midi_send_out[616+numero]=toggle(midi_send_out[616+numero]);
        midi_send_out[620+numero]=midi_send_out[616+numero];
        midi_send_out[624+numero]=midi_send_out[616+numero];
        mouse_released=1;
    }


    raccrochage_midi_logical_vertical(xp,yp,616+numero,20,127);
    return(0);
}
