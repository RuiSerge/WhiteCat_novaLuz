int midi_historic_part(int _x,int _y)
{
    Rect BackV(Vec2D(_x-30,_y),Vec2D(275,275));
    BackV.SetRoundness(7.5);
    BackV.Draw(CouleurFond.WithAlpha(0.5));
    petitchiffrerouge.Print(">>", _x-25,_y+20);
    petitchiffrerouge.Print(midi_historic[position_midi_historic], _x,_y+20);
    for(int i=1; i<24; i++)
    {
        if(position_midi_historic-i>0)
        {


            if(window_focus_id==W_CFGMENU && mouse_x>_x-25 && mouse_x<_x-25+200 && mouse_y>_y+20+(10*i) && mouse_y<_y+30+(10*i))
            {
                Rect OverHist(Vec2D(_x-25,_y+20+(10*i)),Vec2D(200,10));
                OverHist.Draw(CouleurBlind);
                if(mouse_button==1 && mouse_released==0)
                {
                    istyp=midi_historic_data[position_midi_historic-i][0];
                    ischan=midi_historic_data[position_midi_historic-i][1];
                    ispitch=midi_historic_data[position_midi_historic-i][2];
                    sprintf(typ,TblLibEv[istyp]);
                    sprintf (my_midi_string, "%s Ch:%-2d P:%-2d Vel:%-2d ",typ,ischan,ispitch,isvel);

                    mouse_released=1;
                }
            }

            petitchiffre.Print(ol::ToString(position_midi_historic-i), _x-25,_y+30+(10*i));
            petitchiffre.Print(midi_historic[position_midi_historic-i], _x,_y+30+(10*i));
        }
    }

    Circle LineUp(Vec2D(_x+220,_y+100),12);
    LineUp.Draw(CouleurFond);
    Circle LineDown(Vec2D(_x+220,_y+210),12);
    LineDown.Draw(CouleurFond);
    if(window_focus_id==W_CFGMENU && mouse_x>_x+208 && mouse_x<_x+232)
    {
        if(mouse_y>_y+88 && mouse_y<_y+112)
        {
            LineUp.Draw(CouleurSurvol);
            if(mouse_button==1 && mouse_released==0)
            {
                if(position_midi_historic<255)
                {
                    position_midi_historic++;
                }
                mouse_released=1;
            }
        }
        else if(mouse_y>_y+198 && mouse_y<_y+222)
        {
            LineDown.Draw(CouleurSurvol);
            if(mouse_button==1 && mouse_released==0)
            {
                if(position_midi_historic>0)
                {
                    position_midi_historic--;
                }
                mouse_released=1;
            }
        }
    }
    petitchiffre.Print("+",_x+216,_y+105);
    petitchiffre.Print("-",_x+216,_y+215);
    LineUp.DrawOutline(CouleurLigne);
    LineDown.DrawOutline(CouleurLigne);

    return(0);
}
