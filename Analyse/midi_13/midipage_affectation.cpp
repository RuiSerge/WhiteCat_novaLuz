int midipage_affectation(int cfg_midiX,int cfg_midiY, int largeurCFGmidi,int hauteurCFGmidi)
{



    Rect MidiChBox( Vec2D(cfg_midiX+80,cfg_midiY+150), Vec2D ( 70,30));
    MidiChBox.SetRoundness(7.5);
    MidiChBox.SetLineWidth(epaisseur_ligne_fader);
    MidiChBox.Draw(CouleurFond.WithAlpha(0.7));


    Rect MidiPitchBox( Vec2D(cfg_midiX+160,cfg_midiY+150), Vec2D ( 100,30));
    MidiPitchBox.SetRoundness(7.5);
    MidiPitchBox.SetLineWidth(epaisseur_ligne_fader);
    MidiPitchBox.Draw(CouleurFond.WithAlpha(0.7));

    Rect MidiTypeBox( Vec2D(cfg_midiX+160,cfg_midiY+190), Vec2D ( 100,30));
    MidiTypeBox.SetRoundness(7.5);
    MidiTypeBox.SetLineWidth(epaisseur_ligne_fader);
    MidiTypeBox.Draw(CouleurFond.WithAlpha(0.7));
    if(mouse_x> cfg_midiX+80 && mouse_x< cfg_midiX+150 && mouse_y> cfg_midiY+150 && mouse_y<cfg_midiY+150+30  && window_focus_id==920)
    {
        MidiChBox.DrawOutline(CouleurLigne);
        if(mouse_button==1 &&  mouse_released==0 )
        {
            MidiChBox.Draw(CouleurFader);
            fakemidichan=atol(numeric);
            if(fakemidichan>15 || fakemidichan<0)
            {
                fakemidichan=0;
                sprintf(string_Last_Order,"A midi channel is from 0 to 15");
            }
            numeric_postext=0;
            reset_numeric_entry();
            mouse_released=1;
        }
    }
    if(mouse_x> cfg_midiX+160 && mouse_x< cfg_midiX+260 && mouse_y> cfg_midiY+150 && mouse_y<cfg_midiY+180  && window_focus_id==920)
    {
        MidiPitchBox.DrawOutline(CouleurLigne);
        if(mouse_button==1 &&  mouse_released==0 )
        {
            MidiPitchBox.Draw(CouleurFader);
            fakemidipitch=atol(numeric);
            if(fakemidipitch>127 || fakemidipitch<0)
            {
                fakemidipitch=1;
                sprintf(string_Last_Order,"A midi pitch is from 0 to 127");
            }
            numeric_postext=0;
            reset_numeric_entry();
        }
        mouse_released=1;
    }
    if(mouse_x> cfg_midiX+160 && mouse_x< cfg_midiX+260 && mouse_y> cfg_midiY+190 && mouse_y<cfg_midiY+190+30  && window_focus_id==920)
    {
        MidiTypeBox.DrawOutline(CouleurLigne);
        if(mouse_button==1 &&  mouse_released==0 )
        {
            MidiTypeBox.Draw(CouleurFader);
            if(fakemiditype==1)
            {
                fakemiditype=2;
            }
            else if(fakemiditype==2)
            {
                fakemiditype=4;
            }
            else if(fakemiditype==4)
            {
                fakemiditype=1;
            }
            mouse_released=1;
        }
    }

    petitchiffre.Print("CH:",cfg_midiX+90,cfg_midiY+170);
    petitchiffre.Print(ol::ToString(fakemidichan),cfg_midiX+115,cfg_midiY+170);
    petitchiffre.Print("PITCH:",cfg_midiX+170,cfg_midiY+170);
    petitchiffre.Print(ol::ToString(fakemidipitch),cfg_midiX+230,cfg_midiY+170);
    petitchiffre.Print("TYPE:",cfg_midiX+90,cfg_midiY+210);
    if(fakemiditype==1)
    {
        petitchiffre.Print("Key On",cfg_midiX+175,cfg_midiY+210);
    }
    else if(fakemiditype==2)
    {
        petitchiffre.Print("Key Off",cfg_midiX+175,cfg_midiY+210);
    }
    else if(fakemiditype==4)
    {
        petitchiffre.Print("Ctrl Change",cfg_midiX+175,cfg_midiY+210);
    }




    for (int i=1; i<4; i++)
    {
        Rect MidiModeBox( Vec2D(cfg_midiX+10,cfg_midiY+50+(i*25)), Vec2D ( 60,15));
        MidiModeBox.SetRoundness(7.5);
        MidiModeBox.SetLineWidth(epaisseur_ligne_fader);
        MidiModeBox.Draw(CouleurFond.WithAlpha(0.5));

        switch(i)
        {
        case 1://autoclose affectation
            petitchiffre.Print("Midi Affectation Auto-Close (recommanded)",cfg_midiX+90,cfg_midiY+60+(i*25));
            MidiModeBox.Draw(CouleurFader.WithAlpha(index_midi_affectation_autoclose));
            if(mouse_x>cfg_midiX+10 && mouse_x<cfg_midiX+70 && mouse_y>cfg_midiY+50+(i*25) && mouse_y<cfg_midiY+50+(i*25)+15  && window_focus_id==920)
            {
                if(mouse_button==1 &&  mouse_released==0 )
                {
                    index_midi_affectation_autoclose=toggle(index_midi_affectation_autoclose);
                    mouse_released=1;
                }
            }
            break;
        case 2://clear mode
            petitchiffre.Print("Clear !",cfg_midiX+90,cfg_midiY+60+(i*25));
            if(Midi_Faders_Affectation_Mode==1)
            {
                MidiModeBox.Draw(CouleurFader);
            }
            if(mouse_x>cfg_midiX+10 && mouse_x<cfg_midiX+70 && mouse_y>cfg_midiY+50+(i*25) && mouse_y<cfg_midiY+50+(i*25)+15  && window_focus_id==920)
            {
                if(mouse_button==1 &&  mouse_released==0 )
                {
                    if(Midi_Faders_Affectation_Mode!=0 )
                    {
                        Midi_Faders_Affectation_Mode=0;
                    }
                    else
                    {
                        Midi_Faders_Affectation_Mode=1;
                    }
                    mouse_released=1;
                }
            }
            break;
        case 3://midi cheat
            petitchiffre.Print("Fake Midi Input:",cfg_midiX+90,cfg_midiY+60+(i*25));
            if(Midi_Faders_Affectation_Mode==2)
            {
                MidiModeBox.Draw(CouleurFader);
            }
            if(mouse_x>cfg_midiX+10 && mouse_x<cfg_midiX+70 && mouse_y>cfg_midiY+50+(i*25) && mouse_y<cfg_midiY+50+(i*25)+15  && window_focus_id==920)
            {
                if(mouse_button==1 &&  mouse_released==0 )
                {
                    if(Midi_Faders_Affectation_Mode==2 )
                    {
                        Midi_Faders_Affectation_Mode=0;
                    }
                    else
                    {
                        Midi_Faders_Affectation_Mode=2;
                    }
                    mouse_released=1;
                }
            }
            break;
        default:
            break;
        }
        /*
        if(mouse_x>cfg_midiX+10 && mouse_x<cfg_midiX+70 && mouse_y>cfg_midiY+50+(i*25) && mouse_y<cfg_midiY+50+(i*25)+15  && window_focus_id==920)
        {
        MidiModeBox.Draw(CouleurFond);
        if(mouse_button==1 &&  mouse_released==0 )
        {
        MidiModeBox.Draw(CouleurSurvol);
        if(Midi_Faders_Affectation_Mode==i){Midi_Faders_Affectation_Mode=0;}
        else{Midi_Faders_Affectation_Mode=i;}
        mouse_released=1;
        }
        }
        if(i==1)
        {
        petitchiffre.Print("Clear !",cfg_midiX+90,cfg_midiY+60+(i*25));
        }
        if(i==3)
        {
        petitchiffre.Print("Fake Midi Input:",cfg_midiX+90,cfg_midiY+60+(i*25));
        }

        if(Midi_Faders_Affectation_Mode==i)
        {
        MidiModeBox.Draw(CouleurFader);
        }
        */
    }


    Rect MidiTogBox( Vec2D(cfg_midiX+10,cfg_midiY+40), Vec2D ( 60,25));
    MidiTogBox.SetRoundness(7.5);
    MidiTogBox.SetLineWidth(epaisseur_ligne_fader);
    MidiTogBox.Draw(CouleurFond.WithAlpha(0.5));

    if(mouse_x>cfg_midiX+10 && mouse_x<cfg_midiX+70 && mouse_y>cfg_midiY+40 && mouse_y<cfg_midiY+40+25  && window_focus_id==920)
    {
        MidiTogBox.DrawOutline(CouleurFader);
        if(mouse_button==1 &&  mouse_released==0 )
        {
            if(toggle_numerical_midi_way==0)
            {
                toggle_numerical_midi_way=1;
            }
            else if(toggle_numerical_midi_way==1)
            {
                toggle_numerical_midi_way=0;
            }
            mouse_released=1;
        }
    }
    if(toggle_numerical_midi_way==1)
    {
        MidiTogBox.Draw(CouleurSurvol);
        petitchiffre.Print("Chan.",cfg_midiX+20,cfg_midiY+55);
    }
    else if(toggle_numerical_midi_way==0)
    {
        petitchiffre.Print("Pitch",cfg_midiX+20,cfg_midiY+55);
    }

    petitchiffre.Print("Numerical Serial Way",cfg_midiX+90,cfg_midiY+55);


    petitchiffre.Print("MIDI AFFECT Button:",cfg_midiX+20,cfg_midiY+255);

    MidiTypeBox.MoveTo(Vec2D(cfg_midiX+160,cfg_midiY+235));
    MidiTypeBox.Draw(CouleurFond.WithAlpha(0.7));
    switch(miditable[0][1625])
    {
    case 0:
        petitchiffre.Print("Note",cfg_midiX+170,cfg_midiY+255);
        break;
    case 1:
        petitchiffre.Print("Key On",cfg_midiX+170,cfg_midiY+255);
        break;
    case 2:
        petitchiffre.Print("Key Off",cfg_midiX+170,cfg_midiY+255);
        break;
    case 4:
        petitchiffre.Print("Ctrl Change",cfg_midiX+170,cfg_midiY+255);
        break;
    default:
        petitchiffre.Print("-",cfg_midiX+170,cfg_midiY+255);
        break;
    }

    MidiChBox.MoveTo(Vec2D(cfg_midiX+290,cfg_midiY+235));
    MidiChBox.Draw(CouleurFond.WithAlpha(0.7));
    petitchiffre.Print("CH.:",cfg_midiX+300,cfg_midiY+255);
    petitchiffre.Print(ol::ToString(miditable[1][1625]),cfg_midiX+330,cfg_midiY+255);

    MidiPitchBox.MoveTo(Vec2D(cfg_midiX+380,cfg_midiY+235));
    MidiPitchBox.Draw(CouleurFond.WithAlpha(0.7));
    petitchiffre.Print("Pitch:",cfg_midiX+390,cfg_midiY+255);
    petitchiffre.Print(ol::ToString(miditable[2][1625]),cfg_midiX+430,cfg_midiY+255);

    if(window_focus_id==W_CFGMENU && mouse_y>cfg_midiY+235 && mouse_y<cfg_midiY+265 && mouse_button==1 && mouse_released==0)
    {
        if(mouse_x>cfg_midiX+160 && mouse_x<cfg_midiX+260)//Type
        {
            MidiTypeBox.DrawOutline(CouleurLigne.WithAlpha(0.5));
            switch(miditable[0][1625])
            {
            case 0:
                miditable[0][1625]=1;
                break;
            case 1:
                miditable[0][1625]=2;
                break;
            case 2:
                miditable[0][1625]=4;
                break;
            case 4:
                miditable[0][1625]=0;
                break;
            default:
                miditable[0][1625]=0;
                break;
            }
        }
        else if(mouse_x>cfg_midiX+290 && mouse_x<cfg_midiX+350 && numeric_postext>0)//CH
        {
            MidiChBox.DrawOutline(CouleurLigne.WithAlpha(0.5));
            if(atoi(numeric)<16)
            {
                miditable[1][1625]=atoi(numeric);
                reset_numeric_entry();
            }
        }
        else if(mouse_x>cfg_midiX+380 && mouse_x<cfg_midiX+480 && numeric_postext>0)//PITCH
        {
            MidiPitchBox.DrawOutline(CouleurLigne.WithAlpha(0.5));
            if(atoi(numeric)<128)
            {
                miditable[2][1625]=atoi(numeric);
                reset_numeric_entry();
            }
        }
        mouse_released=1;
    }


    petitpetitchiffre.Print(string_last_midi_id,cfg_midiX+250, cfg_midiY+55);//midi in


    midi_historic_part(cfg_midiX+575, cfg_midiY+10);//monitoring input
    return(0);
}
