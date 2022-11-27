int TheStepBox(int xb,int yb, int num_grid_player)
{

    previous_button_view(xb,yb,0);
    Rect StepB(Vec2D(xb+22,yb-5),Vec2D(35,30));
    StepB.SetRoundness(4);
    StepB.DrawOutline(CouleurLigne.WithAlpha(0.4));
    Rect Step127(Vec2D(xb+60,yb-6),Vec2D(20,5));
    Step127.SetRoundness(1.0);
    Step127.DrawOutline(CouleurLigne.WithAlpha(0.4));
    minichiffre.Print(ol::ToString(grid_midi_multiple_for_step_call[num_grid_player]),xb+82,yb);

    next_button_view(xb+60,yb,0);
    if(window_focus_id==926 )
    {
        if(window_focus_id==W_GRID &&  mouse_x>xb && mouse_x<xb+20 && mouse_y>yb && mouse_y<yb+20 )
        {
            if(Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"StepMinus in GridPl.%d",num_grid_player+1);
                show_type_midi(1484+num_grid_player,sttmp );
                Rect StepMinus(Vec2D(xb,yb),Vec2D(20,20));
                StepMinus.SetRoundness(4);
                StepMinus.DrawOutline(CouleurBlind);
            }
            if(mouse_b&1 )
            {
                previous_button_view(xb,yb,1);
            }
        }
        if(window_focus_id==W_GRID && mouse_x>xb+60 && mouse_x<xb+80 && mouse_y>yb && mouse_y<yb+20 )
        {
            if(Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"StepPlus in GridPl.%d",num_grid_player+1);
                show_type_midi(1488+num_grid_player,sttmp );
                Rect StepPlus(Vec2D(xb+60,yb),Vec2D(20,20));
                StepPlus.SetRoundness(4);
                StepPlus.DrawOutline(CouleurBlind);
            }
            if(mouse_b&1 )
            {
                next_button_view(xb+60,yb,1);
            }
        }

        if(window_focus_id==W_GRID && mouse_x>xb+60 && mouse_x<xb+80 && mouse_y>yb-6 && mouse_y<yb-1)
        {
            Step127.DrawOutline(CouleurLigne);
            if( Midi_Faders_Affectation_Type!=0)
            {
                Step127.DrawOutline(CouleurBlind);
                char sttmp[24];
                sprintf(sttmp,"CallStep x7 GridPl.%d",num_grid_player+1);
                show_type_midi(1536+num_grid_player,sttmp );
            }
        }
        if(window_focus_id==W_GRID && mouse_x>xb+22 && mouse_x<xb+57 && mouse_y>yb-5 && mouse_y<yb-25 )
        {
            StepB.DrawOutline(CouleurLigne);
            if( Midi_Faders_Affectation_Type!=0)
            {
                StepB.DrawOutline(CouleurBlind);
                char sttmp[24];
                sprintf(sttmp,"CallStep x1 GridPl.%d",num_grid_player+1);
                show_type_midi(1532+num_grid_player,sttmp );
            }
        }
    }
    petitchiffre.Print(ol::ToString(index_grider_step_is[num_grid_player]+1),xb+27,yb+14);

    return(0);
}
