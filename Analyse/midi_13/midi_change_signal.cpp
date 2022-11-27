int midi_change_signal(int xrep, int yrep)
{

    petitchiffre.Print("Change Reaction :",xrep, yrep-15);

    sprintf(string_midichan,"Midi Ch: %d",change_vel_midichan_selected);

    Rect ChangeCh(Vec2D(xrep+110,yrep-30),Vec2D(80,20));
    ChangeCh.SetRoundness(5);
    if(mouse_x>xrep+110 && mouse_x<xrep+110+80 && mouse_y>yrep-30 && mouse_y<yrep-30+20)
    {
        ChangeCh.Draw(CouleurSurvol);
        if(mouse_button==1 && mouse_released==0)
        {
            ChangeCh.Draw(CouleurFader);
            change_vel_midichan_selected++;
            if(change_vel_midichan_selected>15)
            {
                change_vel_midichan_selected=0;
            }
            mouse_released=1;
        }
    }
    petitchiffre.Print(string_midichan,xrep+120,yrep-17);
    ChangeCh.DrawOutline(CouleurLigne);



    Rect BackDeroule(Vec2D(xrep,yrep),Vec2D(190,210));
    BackDeroule.SetRoundness(15);
    BackDeroule.Draw(CouleurFond.WithAlpha(0.3));

    for (int y=0; y<10; y++)
    {
        Rect OverMidi(Vec2D(xrep+5,(yrep+10+(y*20)-10)),Vec2D(140,15));
        OverMidi.SetRoundness(7.5);

        if(mouse_x>xrep+5 && mouse_x<xrep+5+110 && mouse_y>(yrep+10+(y*20)-10) && mouse_y<(yrep+10+(y*20)+5))
        {
            OverMidi.DrawOutline(CouleurLigne);
            if(mouse_button==1 && mouse_released==0)
            {
                midi_change_vel_type[change_vel_midichan_selected][line_midi_changesignal+y]++;
                if(midi_change_vel_type[change_vel_midichan_selected][line_midi_changesignal+y]>6)
                {
                    midi_change_vel_type[change_vel_midichan_selected][line_midi_changesignal+y]=0;
                }
                mouse_released=1;
            }
        }
        if(y+line_midi_changesignal<=127)
        {

            switch(midi_change_vel_type[change_vel_midichan_selected][line_midi_changesignal+y])
            {
            case 0:
                petitpetitchiffre.Print("Normal 0-127",xrep+30,yrep+10+(y*20));
                break;
            case 1:
                OverMidi.Draw(CouleurLock);
                petitpetitchiffre.Print("Inversed 127-0",xrep+30,yrep+10+(y*20));
                break;
            case 2:
                OverMidi.Draw(CouleurSurvol);
                petitpetitchiffre.Print("Toggle mode",xrep+30,yrep+10+(y*20));
                break;
            case 3:
                OverMidi.Draw(CouleurYellow);
                petitpetitchiffre.Print("KOn Vel0 =KOff",xrep+30,yrep+10+(y*20));
                break;
            case 4:
                OverMidi.Draw(CouleurSelection);
                petitpetitchiffre.Print("KOff =KOn Vel0",xrep+30,yrep+10+(y*20));
                break;
            case 5:
                OverMidi.Draw(CouleurBleuProcedure);
                petitpetitchiffre.Print("Pad To Trigger",xrep+30,yrep+10+(y*20));
                break;
            case 6:
                OverMidi.Draw(CouleurBleuProcedure);
                petitpetitchiffre.Print("CC Vel0 =Koff",xrep+30,yrep+10+(y*20));
                break;
            default:
                break;
            }
            petitpetitchiffre.Print(ol::ToString(line_midi_changesignal+y),xrep+10,yrep+10+(y*20));
        }
    }

    Circle LineUp(Vec2D(xrep+170,yrep+25),12);
    LineUp.Draw(CouleurFond);
    Circle LineDown(Vec2D(xrep+170,yrep+185),12);
    LineDown.Draw(CouleurFond);
    if(mouse_x>xrep+170-12 && mouse_x<xrep+170+12)
    {
        if(mouse_y>yrep+25-12 && mouse_y<yrep+25+12)
        {
            LineUp.Draw(CouleurSurvol);
            if(mouse_button==1)
            {
                LineUp.Draw(CouleurFader);
                if(line_midi_changesignal>0)
                {
                    line_midi_changesignal--;
                }
            }
        }
        else if(mouse_y>yrep+185-12 && mouse_y<yrep+185+12)
        {
            LineDown.Draw(CouleurSurvol);
            if(mouse_button==1)
            {
                LineDown.Draw(CouleurFader);
                if(line_midi_changesignal<127)
                {
                    line_midi_changesignal++;
                }
                else (line_midi_changesignal=127);
            }
        }
    }
    petitchiffre.Print("-",xrep+166,yrep+30);
    petitchiffre.Print("+",xrep+166,yrep+190);
    LineUp.DrawOutline(CouleurLigne);
    LineDown.DrawOutline(CouleurLigne);



    return(0);
}
