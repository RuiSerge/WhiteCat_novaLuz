int TheGrid_divers( int xb, int yb, int num_grid_player)
{
    Rect AffectToDocB(Vec2D(xb+60,yb),Vec2D(50,30));
    AffectToDocB.SetRoundness(5);
    AffectToDocB.SetLineWidth(tiers_epaisseur_ligne_fader);
    if(num_grid_player==gridplayer_to_affect_is)
    {
        AffectToDocB.Draw(CouleurFader);
    }
    AffectToDocB.DrawOutline(CouleurLigne.WithAlpha(0.3));

    petitpetitchiffre.Print("Affect",xb+65,yb+12);
    petitpetitchiffre.Print("ToDock",xb+65,yb+22);


    ////////EDITING MODE/////////////////////////

    Rect ToStepMB(Vec2D(xb,yb+45),Vec2D(10,10));
    ToStepMB.Draw(CouleurBlind.WithAlpha(alpha_blinker*to_step_editing_mode[num_grid_player]));
    ToStepMB.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitpetitchiffre.Print("ToStep",xb+15,yb+48);
    petitpetitchiffre.Print(" Mode",xb+15,yb+58);
    minichiffre.Print("Step",xb+65,yb+40);
    Rect StepToB(Vec2D(xb+60,yb+45),Vec2D(40,15));
    StepToB.SetRoundness(0.5);
    StepToB.DrawOutline(CouleurLigne.WithAlpha(0.2));
    petitpetitchiffre.Print(ol::ToString(index_StepTo[num_grid_player]+1),xb+65,yb+55);


    Line(Vec2D(xb,yb+68),Vec2D(xb+110,yb+68)).Draw(CouleurLigne.WithAlpha(0.5));



    Rect CopyB(Vec2D(xb,yb+75),Vec2D(50,15));
    CopyB.SetRoundness(4.0);
    CopyB.Draw(CouleurSurvol.WithAlpha(0.5));

    petitpetitchiffre.Print("CopyTo",xb+5,yb+85);

    Rect InsB(Vec2D(xb+55,yb+75),Vec2D(50,15));
    InsB.SetRoundness(4.0);
    InsB.Draw(CouleurSurvol.WithAlpha(0.5));
    petitpetitchiffre.Print("Insert",xb+60,yb+85);


    Rect GridCopyB(Vec2D(xb,yb+95),Vec2D(30,15));
    GridCopyB.SetRoundness(0.5);
    GridCopyB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    Rect StepCopyB(Vec2D(xb+45,yb+95),Vec2D(40,15));
    StepCopyB.SetRoundness(0.5);
    StepCopyB.DrawOutline(CouleurLigne.WithAlpha(0.2));

    petitpetitchiffre.Print(ol::ToString( index_Grid_copyto[num_grid_player][0]+1),xb+5,yb+105);
    petitpetitchiffre.Print(ol::ToString( index_Grid_copyto[num_grid_player][1]+1),xb+50,yb+105);





    if(window_focus_id==W_GRID && index_enable_edit_Grider==1 )
    {
        if( mouse_x>xb && mouse_x<xb+100 && mouse_y>yb+45 && mouse_y<yb+55)
        {
            ToStepMB.DrawOutline(CouleurLigne);
        }
        if( mouse_x>xb+60 && mouse_x<xb+100 && mouse_y>yb+45 && mouse_y<yb+60)
        {
            StepToB.DrawOutline(CouleurLigne);
        }
        if(mouse_x>xb && mouse_x<xb+50 && mouse_y>yb+75 && mouse_y<yb+90 )
        {
            CopyB.DrawOutline(CouleurFader);
        }
        if(mouse_x>xb+55 && mouse_x<xb+105 && mouse_y>yb+75 && mouse_y<yb+90 )
        {
            InsB.DrawOutline(CouleurFader);
        }
        if(mouse_x>xb && mouse_x<xb+30 && mouse_y>yb+95 && mouse_y<yb+105 )
        {
            GridCopyB.DrawOutline(CouleurLigne);
        }
        if(mouse_x>xb+45 && mouse_x<xb+85 && mouse_y>yb+95 && mouse_y<yb+105 )
        {
            StepCopyB.DrawOutline(CouleurLigne);
        }
    }
    char sttmp[24];

    if(num_grid_player==0 )
    {
        Rect BoxLink(Vec2D(xb, yb+115),Vec2D(105,15));
        BoxLink.Draw(CouleurFader.WithAlpha(index_link_speed_crossfade_to_gpl1));
        BoxLink.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitchiffre.Print("Speed is CueList",xb+2,yb+125);
        if(window_focus_id==W_GRID && mouse_x>xb && mouse_x<xb+105 && mouse_y>yb+115 && mouse_y<yb+130)
        {
            if( Midi_Faders_Affectation_Type!=0)
            {

                sprintf(sttmp,"Speed is CueList GPl.1");
                show_type_midi(1540,sttmp );
                BoxLink.DrawOutline(CouleurBlind);
            }

        }
    }

    Rect GetDraw(Vec2D(xb, yb+135),Vec2D(105,15));
    GetDraw.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitchiffre.Print("Snap Fader",xb+7,yb+145);
    neuromoyen.Print(ol::ToString(GplSnapFader[num_grid_player]+1),xb+80,yb+146);


    if(window_focus_id==W_GRID && index_enable_edit_Grider==1 )
    {
        if( mouse_x>xb && mouse_x<xb+105 && mouse_y>yb+135 && mouse_y<yb+150)
        {
            GetDraw.DrawOutline(CouleurLigne);
        }
    }
    return(0);
}
