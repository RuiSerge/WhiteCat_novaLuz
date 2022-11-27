int do_midi_config(int cfg_midiX,int cfg_midiY, int largeurCFGmidi,int hauteurCFGmidi)
{

    for(int pp=0; pp<3; pp++)
    {
        Rect MidiMenu( Vec2D(cfg_midiX+20+(pp*150),cfg_midiY+1), Vec2D ( 140,35));
        MidiMenu.SetRoundness(7.5);
        MidiMenu.SetLineWidth(epaisseur_ligne_fader/2);
        MidiMenu.Draw(CouleurFond.WithAlpha(0.2));
        if( window_focus_id==920)
        {
            if(mouse_y>cfg_midiY+1 && mouse_y<cfg_midiY+35)
            {
                if(mouse_x>cfg_midiX+20+(pp*150) && mouse_x<cfg_midiX+20+(pp*150)+140)
                {
                    MidiMenu.Draw(CouleurFond.WithAlpha(0.5));
                    if(mouse_button==1 &&  mouse_released==0 )
                    {
                        midi_page=pp;
                        mouse_released=1;
                    }
                }
            }
        }
        if(pp==0)
        {
            petitchiffre.Print("MIDI DEVICES",cfg_midiX+30+(pp*150),cfg_midiY+20);
        }

        else if(pp==1)
        {
            petitchiffre.Print("OPTIONS / PRESETS",cfg_midiX+30+(pp*150),cfg_midiY+20);
        }
        else if(pp==2)
        {
            petitchiffre.Print("MIDI AFFECT",cfg_midiX+30+(pp*150),cfg_midiY+20);
        }

        if(midi_page==pp)
        {
            MidiMenu.DrawOutline(CouleurLigne);
        }
    }




    if(midi_page==0)
    {
        midipage_devices(cfg_midiX,cfg_midiY+10,largeurCFGmidi,hauteurCFGmidi);
    }

    if(midi_page==1)
    {
        midipage_preset_and_options(cfg_midiX,cfg_midiY,largeurCFGmidi,hauteurCFGmidi);
    }

    if(midi_page==2)
    {
        midipage_affectation(cfg_midiX,cfg_midiY,largeurCFGmidi,hauteurCFGmidi);
    }

    return(0);
}
