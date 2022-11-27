int midipage_devices(int cfg_midiX,int cfg_midiY, int largeurCFGmidi,int hauteurCFGmidi)
{

    char string_midi_device_in[64];
    char string_midi_device_out[64];


    midi_list_and_choose_devices();

    Rect MidiInDev( Vec2D(cfg_midiX+15,cfg_midiY+40), Vec2D ( 400,240));
    MidiInDev.SetRoundness(5);
    MidiInDev.Draw(CouleurFond);


    Rect MidiOutDev( Vec2D(cfg_midiX+420,cfg_midiY+40), Vec2D ( 400,240));
    MidiOutDev.SetRoundness(5);
    MidiOutDev.Draw(CouleurFond);

    //midi INPUT
    for (int i=1; i<=compt_midi_in; i++)
    {
        if(compt_midi_in<=16)
        {
            if (i<=8)
            {

                Rect MidiDeviceBox( Vec2D(cfg_midiX+20,cfg_midiY+15+(i*30)), Vec2D ( 190,25));
                MidiDeviceBox.SetRoundness(7.5);
                MidiDeviceBox.SetLineWidth(epaisseur_ligne_fader);
                if( window_focus_id==920)
                {
                    if(mouse_x>cfg_midiX+20 && mouse_x<cfg_midiX+220 && mouse_y>cfg_midiY+15+(i*30) && mouse_y<cfg_midiY+45+(i*30))
                    {
                        MidiDeviceBox.Draw(CouleurBleuProcedure);
                        if(mouse_button==1 &&  mouse_released==0 )
                        {
                            MidiDeviceBox.Draw(CouleurFader);
                            if( do_connect_in[i]==0)
                            {
                                do_connect_in[i]=1;
                            }
                            mouse_released=1;
                        }
                    }
                }
                if(midi_in_is_connected[i]==1)
                {
                    MidiDeviceBox.DrawOutline(CouleurLevel);
                }
                sprintf(string_midi_device_in,"%s",tableau_peripheriques_in[i]);
                petitpetitchiffre.Print(string_midi_device_in,cfg_midiX+25,cfg_midiY+30+(i*30));
            }
            else if(i>8)//deuxieme colonne
            {
                Rect MidiDeviceBox( Vec2D(cfg_midiX+220,cfg_midiY+15+((i-8)*30)), Vec2D ( 190,25));
                MidiDeviceBox.SetRoundness(7.5);
                MidiDeviceBox.SetLineWidth(epaisseur_ligne_fader);
                if( window_focus_id==920)
                {
                    if(mouse_x>cfg_midiX+230 && mouse_x<cfg_midiX+380 && mouse_y>cfg_midiY+15+((i-8)*30) && mouse_y<cfg_midiY+45+((i-8)*30))
                    {
                        MidiDeviceBox.Draw(CouleurBleuProcedure);

                        if(mouse_button==1 &&  mouse_released==0 )
                        {
                            MidiDeviceBox.Draw(CouleurFader);
                            do_connect_in[i]=1;
                            mouse_released=1;
                        }
                    }
                }
                if(midi_in_is_connected[i]==1)
                {
                    MidiDeviceBox.DrawOutline(CouleurLevel);
                }
                sprintf(string_midi_device_in,tableau_peripheriques_in[i]);
                petitpetitchiffre.Print(string_midi_device_in,cfg_midiX+225,cfg_midiY+30+((i-8)*30));
            }
        }
    }

    // MIDI OUTPUT
    for (int j=1; j<=compt_midi_out; j++)
    {

        if(compt_midi_out<=16)
        {
            if(j<=8)
            {
                Rect MidiDeviceBox( Vec2D(cfg_midiX+420,cfg_midiY+15+(j*30)), Vec2D ( 190,25));
                MidiDeviceBox.SetRoundness(7.5);
                MidiDeviceBox.SetLineWidth(epaisseur_ligne_fader);
                if( window_focus_id==920)
                {
                    if(mouse_x>cfg_midiX+420 && mouse_x<cfg_midiX+620 && mouse_y>cfg_midiY+15+(j*30) && mouse_y<cfg_midiY+45+(j*30))
                    {
                        MidiDeviceBox.Draw(CouleurBlind.WithAlpha(0.5));
                        if(mouse_button==1 &&  mouse_released==0 )
                        {
                            MidiDeviceBox.Draw(CouleurFader);
                            if( do_connect_out[j+compt_midi_in]==0)
                            {
                                do_connect_out[j+compt_midi_in]=1;
                            }
                            mouse_released=1;
                        }
                    }
                }
                if (midi_out_is_connected[j+compt_midi_in]== 1)
                {
                    MidiDeviceBox.DrawOutline(CouleurBlind);
                }

                sprintf(string_midi_device_out,"%s",tableau_peripheriques_out[j]);
                petitpetitchiffre.Print(string_midi_device_out,cfg_midiX+425,cfg_midiY+30+(j*30));
            }

            else if(j>8)//deuxieme colonne
            {
                Rect MidiDeviceBox( Vec2D(cfg_midiX+620,cfg_midiY+15+((j-8)*30)), Vec2D ( 190,25));
                MidiDeviceBox.SetRoundness(7.5);
                MidiDeviceBox.SetLineWidth(epaisseur_ligne_fader);
                if( window_focus_id==920)
                {
                    if(mouse_x>cfg_midiX+620 && mouse_x<cfg_midiX+820 && mouse_y>cfg_midiY+15+((j-8)*30) && mouse_y<cfg_midiY+45+((j-8)*30))
                    {
                        MidiDeviceBox.Draw(CouleurBlind.WithAlpha(0.5));
                        if(mouse_button==1 &&  mouse_released==0 )
                        {
                            MidiDeviceBox.Draw(CouleurFader);
                            if( do_connect_out[j+compt_midi_in]==0)
                            {
                                do_connect_out[j+compt_midi_in]=1;
                            }
                            mouse_released=1;
                        }
                    }
                }
                if (midi_out_is_connected[j+compt_midi_in]== 1)
                {
                    MidiDeviceBox.DrawOutline(CouleurBlind);
                }

                sprintf(string_midi_device_out,tableau_peripheriques_out[j]);
                petitpetitchiffre.Print(string_midi_device_out,cfg_midiX+625,cfg_midiY+30+((j-8)*30));
            }
        }
    }



    Rect LabelIn(Vec2D(cfg_midiX+372,cfg_midiY+30),Vec2D(40,20));
    LabelIn.Draw(CouleurBleuProcedure);
    petitchiffre.Print("INPUT",cfg_midiX+375,cfg_midiY+43);

    Rect LabelOut(Vec2D(cfg_midiX+768,cfg_midiY+30),Vec2D(50,20));
    LabelOut.Draw(CouleurBlind.WithAlpha(0.5));
    petitchiffre.Print("OUTPUT",cfg_midiX+770,cfg_midiY+43);




    Rect MidiRescanDriver( Vec2D(cfg_midiX+720,cfg_midiY), Vec2D ( 70,25));
    MidiRescanDriver.SetRoundness(7.5);
    MidiRescanDriver.Draw(CouleurFond.WithAlpha(0.7));
    if( window_focus_id==920)
    {
        if(mouse_x>cfg_midiX+720 && mouse_x<cfg_midiX+720+70 && mouse_y>cfg_midiY && mouse_y<cfg_midiY+25)
        {
            MidiRescanDriver.Draw(CouleurSurvol);
            if(mouse_button==1 && mouse_released==0)
            {
                MidiRescanDriver.Draw(CouleurFader);
                QuitMidi() ;

                InitMidi();//init pose souci . au chargement de white cat init pause souci des que ouv de fichiers
                mouse_released=1;
            }
        }
    }
    petitchiffre.Print("Rescan",cfg_midiX+730,cfg_midiY+15);
    MidiRescanDriver.DrawOutline(CouleurLigne);

    return(0);
}
