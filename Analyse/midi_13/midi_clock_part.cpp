int midi_clock_part(int _x,int _y)
{
    //midiclock view

    petitchiffre.Print("MIDI CLOCK SIGNAL:", _x,_y);
    Rect Button(Vec2D(_x,_y+15),Vec2D(50,20));
    Button.SetRoundness(4.5);
    Button.DrawOutline(CouleurBlanc);
    petitchiffre.Print("MIDI CLOCK", _x+70,_y+28);
    switch(index_midi_clock_on)
    {
    case 0:
        petitchiffre.Print("/Off", _x+5,_y+28);
        break;
    case 1:
        petitchiffre.Print("/ON", _x+5,_y+28);
        break;
    default:
        break;
    }

    Rect BPm_(Vec2D(_x,_y+45),Vec2D(60,20));
    BPm_.SetRoundness(4.5);
    BPm_.Draw(CouleurFond.WithAlpha(0.5));
    BPm_.DrawOutline(CouleurLigne.WithAlpha(0.3));
    petitchiffre.Print("BPM", _x+70,_y+58);
    petitchiffre.Print(ol::ToString(midi_BPM), _x+5,_y+58);

    clock_wheel (_x+200,_y+20, rayon_wheel_level,angle_correction_wheel);

    Rect BPm_c(Vec2D(_x+120,_y+45),Vec2D(30,20));
    BPm_c.SetRoundness(4.5);
    BPm_c.Draw(CouleurFond.WithAlpha(0.5));
    BPm_c.DrawOutline(CouleurLigne.WithAlpha(0.3));
    petitchiffre.Print("Clock+", _x+160,_y+58);
    petitchiffre.Print(ol::ToString(relativ_encoder_midi_clock_value), _x+125,_y+58);
    if(window_focus_id==W_CFGMENU && mouse_x>_x+120 && mouse_x<_x+150 && mouse_y>_y+45 && mouse_y<_y+65 && mouse_button==1 && mouse_released==0)
    {
        if(numeric_postext>0 && atoi(numeric)>0)
        {
            relativ_encoder_midi_clock_value=atoi(numeric);
            reset_numeric_entry();
        }
        mouse_released=1;
    }


    for(int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            BPm_.MoveTo(Vec2D(_x+(65*j),_y+75+(30*i)));
            BPm_.Draw(CouleurFond.WithAlpha(0.5));
            BPm_.DrawOutline(CouleurLigne.WithAlpha(0.3));
            petitchiffre.Print(ol::ToString(bpm_personnal[j+(i*4)]),_x+5+(65*j),_y+90+(30*i));
            if(Midi_Faders_Affectation_Type!=0 && window_focus_id==W_CFGMENU && mouse_x>_x+(65*j) && mouse_x<_x+(65*j)+60 && mouse_y>_y+75+(30*i) && mouse_y<_y+75+(30*i)+20 )
            {
                BPm_.DrawOutline(CouleurBlind);
            }
            if(window_focus_id==W_CFGMENU && mouse_x>_x+(65*j) && mouse_x<_x+(65*j)+60 && mouse_y>_y+75+(30*i) && mouse_y<_y+75+(30*i)+20 && mouse_button==1 && mouse_released==0)
            {
                //affectation midi
                //AFFECTATION MIDI
                if(Midi_Faders_Affectation_Type!=0)//config midi
                {
                    //midi report
                    BPm_.DrawOutline(CouleurBlind);
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
                    sprintf(string_last_midi_id,"CLOCK LOAD is Ch: %d Pitch: %d Typ: %s", miditable[1][1895+j+(i*4)],miditable[2][1895+j+(i*4)],thetypinfo);

                    if(Midi_Faders_Affectation_Type==1)
                    {
                        attribute_midi_solo_affectation(1895+j+(i*4),Midi_Faders_Affectation_Mode);
                    }
                    else if(Midi_Faders_Affectation_Type==2)
                    {
                        attribute_midi_to_control(1895+j+(i*4), Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    }

                }

                else
                {

                    if(numeric_postext>0 && atoi(numeric)>0)
                    {
                        bpm_personnal[j+(i*4)]=atoi(numeric);
                        reset_numeric_entry();
                    }
                    else
                    {
                        midi_BPM=bpm_personnal[j+(i*4)];
                        ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
                        install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
                        reset_numeric_entry();
                    }
                }
                mouse_released=1;
            }
        }
    }

    if( window_focus_id==W_CFGMENU)
    {
        if( mouse_x>_x && mouse_x<_x+50 && mouse_y>_y+15 && mouse_y<_y+35 && mouse_button==1 && mouse_released==0)
        {
            index_midi_clock_on=toggle(index_midi_clock_on);
            mouse_released=1;
        }
        if(mouse_x>_x && mouse_x<_x+60 && mouse_y>_y+45 && mouse_y<_y+65 && mouse_button==1 && mouse_released==0)
        {
            BPm_.DrawOutline(CouleurLigne);
            if(atoi(numeric)>0)
            {
                midi_BPM= atoi(numeric);
                ticker_midi_clock_rate=BPM_TO_TIMER(24 * midi_BPM);
                install_int_ex(ticker_midi_clock, ticker_midi_clock_rate);
                reset_numeric_entry();
                mouse_released=1;
            }
        }
    }

    return(0);
}
