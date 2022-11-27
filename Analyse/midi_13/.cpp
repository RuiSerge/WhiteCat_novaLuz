int clock_wheel (int xw,int yw, int rayon_k, float angle_correction)
{
    Circle (Vec2D(xw,yw), rayon_k+5).DrawOutline(CouleurLigne);
    Circle (Vec2D(xw,yw), rayon_k-5).DrawOutline(CouleurLigne);

    Circle(Vec2D(position_curseur_clock_x,position_curseur_clock_y),5).Draw(CouleurBlind);


    petitpetitchiffre.Print(ol::ToString(midi_levels[1894]),xw-5,yw+12);

    if( Midi_Faders_Affectation_Type!=0)//config midi
    {
        if(mouse_x>xw-rayon_k-5 && mouse_x<xw+rayon_k+5 && mouse_y>yw-rayon_k-5 && mouse_y<yw+rayon_k+5)
        {
            Circle (Vec2D(xw,yw), rayon_k+5).DrawOutline(CouleurBlind);
            if(mouse_button==1 && mouse_released==0)
            {
                Circle (Vec2D(xw,yw), rayon_k+5).Draw(CouleurBlind);
            }
        }
    }

    Rect WheelMode(Vec2D(xw+rayon_k+10,yw-rayon_k),Vec2D(15,15));
    WheelMode.SetRoundness(3);

    switch(clocklevel_absolutemode)
    {
    case 0:
        WheelMode.Draw(CouleurLock);
        petitchiffre.Print("R",xw+rayon_k+13,yw-rayon_k+12);
        break;
    case 1:
        WheelMode.Draw(CouleurSurvol);
        petitchiffre.Print("A",xw+rayon_k+13,yw-rayon_k+12);
        break;
    default:
        break;
    }
    WheelMode.DrawOutline(CouleurLigne);

    Line (Vec2D(xw+rayon_k,yw+rayon_k-3),Vec2D(xw+rayon_k+7,yw+rayon_k+7)).Draw(CouleurLigne);
    Circle MidiOutW(Vec2D(xw+rayon_k+10,yw+rayon_k+10),7);
    if(midi_send_out[1894]==1)
    {
        MidiOutW.Draw(CouleurBlind);
    }

    MidiOutW.DrawOutline(CouleurLigne);


    if(window_focus_id==W_CFGMENU && mouse_button==1 && mouse_released==0)
    {
        for( float clock_angle = 0.0+angle_correction ; clock_angle <(PIknob*2)+angle_correction  ; clock_angle+=0.01)//radians
        {
            clock_vx = cos(clock_angle)* rayon_k;
            clock_vy = sin(clock_angle)* rayon_k;
            if(mouse_x>xw+clock_vx-5  && mouse_x<xw+clock_vx+5 && mouse_y>yw+clock_vy-5 && mouse_y<yw+clock_vy+5 )
            {
                angle_snap_clock=clock_angle;//angle rotation niveaux
                position_curseur_clock_x= xw+clock_vx;
                position_curseur_clock_y=yw+clock_vy ;
                midi_levels[1894]=(int)(((angle_snap_clock-angle_correction)/(PIknob*2))*128);
                do_clock_level_modification(midi_levels[1894]);
                if(midi_send_out[1894]==1)
                {
                    index_send_midi_out[1894]=1;
                }

            }
        }


        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            //midi report
            switch(miditable[0][1894])
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
            sprintf(string_last_midi_id,"CLOCK LEVEL WHEEL is Ch: %d Pitch: %d Typ: %s", miditable[1][1894],miditable[2][1894],thetypinfo);

            if(mouse_x>xw-rayon_k-5 && mouse_x<xw+rayon_k+5 && mouse_y>yw-rayon_k-5 && mouse_y<yw+rayon_k+5)
            {

                attribute_midi_solo_affectation(1894,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }

        }


        if(mouse_x>xw+rayon_k+10 && mouse_x<xw+rayon_k+10+15 && mouse_y>yw-rayon_k && mouse_y<yw-rayon_k+15)
        {
            clocklevel_absolutemode=toggle(clocklevel_absolutemode);
            mouse_released=1;
        }

        if(mouse_x>xw+rayon_k+10-7 && mouse_x<xw+rayon_k+10+7 && mouse_y>yw+rayon_k+10-7 && mouse_y<yw+rayon_k+10+7)
        {
            midi_send_out[1894]=toggle(midi_send_out[1894]);
            mouse_released=1;
        }
    }
    return(0);
}
