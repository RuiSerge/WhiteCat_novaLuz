int level_wheel_core (int xw,int yw, int rayon_k, float angle_correction)
{

    for( float pad_angle = 0.0+angle_correction ; pad_angle <(PIknob*2)+angle_correction  ; pad_angle+=0.01)//radians
    {
        pad_vx = cos(pad_angle)* rayon_k;
        pad_vy = sin(pad_angle)* rayon_k;
        if(mouse_x>xw+pad_vx-5  && mouse_x<xw+pad_vx+5 && mouse_y>yw+pad_vy-5 && mouse_y<yw+pad_vy+5 )
        {
            angle_snap_pad=pad_angle;//angle rotation niveaux
            position_curseur_pad_x= xw+pad_vx;
            position_curseur_pad_y=yw+pad_vy ;
            midi_levels[664]=(int)(((angle_snap_pad-angle_correction)/(PIknob*2))*128);
            do_wheel_level_job(midi_levels[664]);
            if(midi_send_out[664]==1)
            {
                index_send_midi_out[664]=1;
            }

        }
    }

    if(Midi_Faders_Affectation_Type!=0)//config midi
    {
        //midi report
        switch(miditable[0][664])
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
        sprintf(string_last_midi_id,"LEVELWHEEL FADER is Ch: %d Pitch: %d Typ: %s", miditable[1][664],miditable[2][664],thetypinfo);

        if(mouse_x>xw-rayon_k-5 && mouse_x<xw+rayon_k+5 && mouse_y>yw-rayon_k-5 && mouse_y<yw+rayon_k+5)
        {

            attribute_midi_solo_affectation(664,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }

    }


    if(mouse_x>xw+rayon_k+10 && mouse_x<xw+rayon_k+10+15 && mouse_y>yw-rayon_k && mouse_y<yw-rayon_k+15)
    {
        wheellevel_absolutemode=toggle(wheellevel_absolutemode);
        mouse_released=1;
    }

    if(mouse_x>xw+rayon_k+10-7 && mouse_x<xw+rayon_k+10+7 && mouse_y>yw+rayon_k+10-7 && mouse_y<yw+rayon_k+10+7)
    {
        midi_send_out[664]=toggle(midi_send_out[664]);
        mouse_released=1;
    }
    return(0);
}
