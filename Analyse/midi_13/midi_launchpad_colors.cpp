int midi_launchpad_colors(int cfg_midiX,int cfg_midiY)
{
    char temp_str_lch[36];
    petitchiffre.Print("Launchpad",cfg_midiX,cfg_midiY-2);
    petitchiffre.Print("Colors",cfg_midiX,cfg_midiY+10);
    for(int pm=0; pm<6; pm++)
    {
        sprintf(temp_str_lch,"Col.%d",pm+1);
        petitpetitchiffre.Print(temp_str_lch,cfg_midiX,cfg_midiY+35+(pm*25));
        sprintf(temp_str_lch,"%d",launchpad_color[pm]);
        Rect LaunchCol(Vec2D(cfg_midiX+40,cfg_midiY+20+(pm*25)),Vec2D(40,20));
        LaunchCol.SetRoundness(7.5);
        LaunchCol.Draw(CouleurFond.WithAlpha(0.5));
        petitpetitchiffre.Print(temp_str_lch,cfg_midiX+50,cfg_midiY+35+(pm*25));

        if(mouse_x>cfg_midiX+40 && mouse_x<cfg_midiX+40+40 && mouse_y>cfg_midiY+25+(pm*25) && mouse_y<cfg_midiY+25+(pm*25)+20)
        {
            LaunchCol.DrawOutline(CouleurLigne);
            if(mouse_button==1 && mouse_released==0)
            {
                int temp_collauch=atol(numeric);
                reset_numeric_entry();
                if(temp_collauch>=0 && temp_collauch<=127)
                {
                    launchpad_color[pm]=temp_collauch;
                    refresh_launchpad_color_callibration();
                }
                mouse_released=1;
            }
        }

    }

    petitchiffre.Print("Chaser:",cfg_midiX,cfg_midiY+190);
    petitchiffre.Print("Rows",cfg_midiX,cfg_midiY+205);
    Rect LaunchRows(Vec2D(cfg_midiX+40,cfg_midiY+190),Vec2D(40,20));
    LaunchRows.SetRoundness(7.5);
    LaunchRows.Draw(CouleurFond.WithAlpha(0.5));
    petitpetitchiffre.Print(ol::ToString(chaser_midi_rows),cfg_midiX+55,cfg_midiY+205);

    if(mouse_x>cfg_midiX+40 && mouse_x<cfg_midiX+40+40 && mouse_y>cfg_midiY+190 && mouse_y<cfg_midiY+205)
    {
        LaunchRows.DrawOutline(CouleurLigne);
        if(mouse_button==1 && mouse_released==0)
        {
            chaser_midi_rows=atol(numeric);
            reset_numeric_entry();
            if(chaser_midi_rows<1)
            {
                chaser_midi_rows=1;
            }
            if( chaser_midi_rows>8)
            {
                chaser_midi_rows=8;
            }
            mouse_released=1;
        }
    }
    return(0);
}
