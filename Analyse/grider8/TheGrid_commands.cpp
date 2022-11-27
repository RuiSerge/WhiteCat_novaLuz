int TheGrid_commands ( int xb, int yb, int num_grid_player)
{

    Rect BackSt(Vec2D(xb,yb-5),Vec2D(63,10));
    Rect BackPreset(Vec2D(xb,yb+10),Vec2D(63,10));
    BackSt.DrawOutline(CouleurLigne.WithAlpha(0.2));
    BackPreset.DrawOutline(CouleurLigne.WithAlpha(0.2));
    Rect ActStage(Vec2D(xb,yb-5),Vec2D(grid_niveauX1[num_grid_player]/4,10));
    ActStage.Draw(CouleurNiveau.WithAlpha(0.7));
    ActStage.Draw(CouleurLigne.WithAlpha(0.5));
    Rect ActPreset(Vec2D(xb,yb+10),Vec2D(grid_niveauX2[num_grid_player]/4,10));
    ActPreset.Draw(CouleurSurvol);
    ActPreset.Draw(CouleurLigne.WithAlpha(0.5));
    if(grider_is_playing[num_grid_player]==1)
    {
        if(actual_time<(grid_crossfade_start_time[num_grid_player]+grid_delay_out[num_grid_player]))
        {
            BackSt.Draw(CouleurBlind.WithAlpha(alpha_blinker));
        }
        if(actual_time<(grid_crossfade_start_time[num_grid_player]+grid_delay_in[num_grid_player]))
        {
            BackPreset.Draw(CouleurBlind.WithAlpha(alpha_blinker));
        }
    }
    Rect AcelGrid(Vec2D(xb,yb+30),Vec2D(127,10));
    AcelGrid.DrawOutline(CouleurLigne.WithAlpha(0.5));
    Rect AccelB(Vec2D(xb+grid_crossfade_speed[num_grid_player]-5,yb+30),Vec2D(10,10));
    AccelB.SetRoundness(2.0);
    AccelB.Draw(CouleurFader);
    Line(Vec2D(xb+64,yb+25),Vec2D(xb+64,yb+45)).DrawOutline(CouleurLigne);
    minichiffre.Print(ol::ToString(grid_crossfade_speed[num_grid_player]),xb+130,yb+35);
    if(window_focus_id==W_GRID)
    {
        if(mouse_x>xb-5 && mouse_x<xb+127+5 && mouse_y>=yb+30 && mouse_y<=yb+40 )
        {
            AcelGrid.DrawOutline(CouleurLigne);
            if( Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"Speed GridPl.%d",num_grid_player+1);
                show_type_midi(1508+num_grid_player,sttmp );
                AcelGrid.DrawOutline(CouleurBlind);
            }
        }
    }
    petitpetitchiffre.Print(string_time_in_grider[num_grid_player],xb+70,yb+1);
    petitpetitchiffrerouge.Print(string_time_in_grider_next_step[num_grid_player],xb+70,yb+12);
    petitpetitchiffrerouge.Print(string_next_step_to[num_grid_player],xb+70,yb+25);


    Rect SlaveB(Vec2D(xb+150,yb+25),Vec2D(40,15));
    SlaveB.SetRoundness(0.5);

    if(window_focus_id==W_GRID )
    {
        if(mouse_x>xb+150 && mouse_x<xb+150+40 && mouse_y>yb+25 && mouse_y<yb+40)
        {
            SlaveB.DrawOutline(CouleurLigne);
            if( Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"Slave in GridPl.%d",num_grid_player+1);
                show_type_midi(1504+num_grid_player,sttmp );
                SlaveB.DrawOutline(CouleurBlind);
            }
        }
    }

    SlaveB.Draw(CouleurFader.WithAlpha(grid_player_slave[num_grid_player]));
    SlaveB.DrawOutline(CouleurLigne.WithAlpha(0.2));
    petitpetitchiffre.Print("Slave",xb+155,yb+35);

    Rect CadreStep(Vec2D(xb+15,yb+50),Vec2D(180,100));
    CadreStep.SetRoundness(5.0);
    CadreStep.Draw(CouleurLigne.WithAlpha(0.1));

    petitpetitchiffre.Print("Step Macros",xb+20, yb+60);
    petitpetitchiffre.Print("Grid",xb+110,yb+60);
    petitpetitchiffre.Print("Step",xb+155,yb+60);
    Rect GridGotoB(Vec2D(xb+105,yb+70),Vec2D(30,15));
    GridGotoB.SetRoundness(0.5);
    GridGotoB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    Rect StepGotoB(Vec2D(xb+150,yb+70),Vec2D(40,15));
    StepGotoB.SetRoundness(0.5);
    StepGotoB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    Rect CountB(Vec2D(xb+150,yb+90),Vec2D(40,15));
    CountB.SetRoundness(0.5);
    CountB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    Rect StepSeekB(Vec2D(xb+150,yb+110),Vec2D(40,15));
    StepSeekB.SetRoundness(0.5);
    StepSeekB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    Rect StopPlayB(Vec2D(xb+100,yb+130),Vec2D(90,15));
    StopPlayB.SetRoundness(0.5);

    char sttmp[24];

    for(int sp=0; sp<4; sp++)
    {
        Rect OnOffSp(Vec2D(xb,yb+70+(sp*20)),Vec2D(10,10));
        OnOffSp.SetRoundness(0.2);
        switch(sp)
        {
        case 0:
            OnOffSp.Draw(CouleurBlind.WithAlpha(grider_goto_mode[num_grid_player]));
            petitpetitchiffre.Print("GoTo",xb+20, yb+80+(sp*20));
            sprintf(sttmp,"GotoMode GridPl.%d",num_grid_player+1);
            petitpetitchiffre.Print(ol::ToString(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]+1),xb+110,yb+80+(sp*20));
            petitpetitchiffre.Print(ol::ToString(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]+1),xb+155,yb+80+(sp*20));
            break;
        case 1:
            OnOffSp.Draw(CouleurBlind.WithAlpha(grider_count_mode[num_grid_player]));
            petitpetitchiffre.Print("Count",xb+20, yb+80+(sp*20));
            sprintf(sttmp,"CountMode GridPl.%d",num_grid_player+1);
            petitpetitchiffre.Print(string_grid_count[num_grid_player],xb+55, yb+80+(sp*20));
            petitpetitchiffre.Print(ol::ToString(grid_count[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]),xb+155,yb+80+(sp*20));
            break;
        case 2:
            OnOffSp.Draw(CouleurBlind.WithAlpha(grider_seekto_mode[num_grid_player]));
            petitpetitchiffre.Print("SeekStep",xb+20, yb+80+(sp*20));
            sprintf(sttmp,"SeekStepMode GridPl.%d",num_grid_player+1);
            petitpetitchiffre.Print(ol::ToString(grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]+1),xb+155,yb+80+(sp*20));
            break;
        case 3:
            OnOffSp.Draw(CouleurBlind.WithAlpha(grider_stoplay_mode[num_grid_player]));
            petitpetitchiffre.Print("StopPlay",xb+20, yb+80+(sp*20));
            sprintf(sttmp,"StopPlayMode GridPl.%d",num_grid_player+1);
            StopPlayB.Draw(CouleurBlind.WithAlpha(grid_stoplay[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]));
            StopPlayB.DrawOutline(CouleurLigne.WithAlpha(0.5));
            break;
        default:
            break;
        }

        OnOffSp.DrawOutline(CouleurLigne.WithAlpha(0.5));

        if((window_focus_id==W_GRID || (num_grid_player==0 && window_focus_id==909)) && mouse_x>xb && mouse_x<xb+10 && mouse_y>yb+70+(sp*20) && mouse_y<yb+80+(sp*20))
        {
            if( Midi_Faders_Affectation_Type!=0)
            {
                show_type_midi(1512+(sp*4)+num_grid_player,sttmp );
                OnOffSp.SetLineWidth(2.0);
                OnOffSp.DrawOutline(CouleurBlind);
            }

        }

    }

    if(window_focus_id==W_GRID  && index_enable_edit_Grider==1)
    {
        if( mouse_x>xb+105 && mouse_x<xb+135 && mouse_y>yb+70 && mouse_y<yb+85 )
        {
            GridGotoB.DrawOutline(CouleurLigne);
        }
        if( mouse_x>xb+150 && mouse_x<xb+190 && mouse_y>yb+70 && mouse_y<yb+85 )
        {
            StepGotoB.DrawOutline(CouleurLigne);
        }
        if( mouse_x>xb+150 && mouse_x<xb+190 && mouse_y>yb+90 && mouse_y<yb+105  )
        {
            CountB.DrawOutline(CouleurLigne);
        }
        if( mouse_x>xb+150 && mouse_x<xb+190 && mouse_y>yb+110 && mouse_y<yb+125  )
        {
            StepSeekB.DrawOutline(CouleurLigne);
        }
        if(mouse_x>xb+100 && mouse_x<xb+190 && mouse_y>yb+130 && mouse_y<yb+145 )
        {
            StopPlayB.DrawOutline(CouleurLigne);
        }
    }
    return(0);
}
