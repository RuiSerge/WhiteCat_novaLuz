int Sequenciel_Window(int xseq, int yseq,int largeur_seq,int hauteur_seq)
{
    Rect SeqWindow(Vec2D (xseq, yseq ), Vec2D ( largeur_seq,hauteur_seq));
    SeqWindow.SetRoundness(15);
    SeqWindow.SetLineWidth(triple_epaisseur_ligne_fader);
    SeqWindow.Draw(CouleurFond);
    if(window_focus_id==W_SEQUENCIEL )
    {
        SeqWindow.DrawOutline(CouleurFader);
    }
    else
    {
        SeqWindow.DrawOutline(CouleurLigne);
    }
    neuro.Print("CUELIST",xseq+90, yseq+30);


    petitpetitchiffre.Print("Delay", xseq+20, yseq+60);
    petitpetitchiffre.Print("In/Out", xseq+60, yseq+60);
    neuromoyen.Print("Mem", xseq+115, yseq+60);

    Rect InPositionStage(Vec2D (xseq+10, yseq+80), Vec2D ( 100,40));
    InPositionStage.SetRoundness(4);
    InPositionStage.Draw(CouleurNiveau.WithAlpha(0.5));


    Rect PositionStage(Vec2D (xseq+10, yseq+110), Vec2D ( 460,40));
    PositionStage.Draw(CouleurNiveau.WithAlpha(0.5));

    Rect OutPositionStage(Vec2D (xseq+10, yseq+110), Vec2D ( 100,40));
    OutPositionStage.SetRoundness(4);
    OutPositionStage.Draw(CouleurSurvol);


    Rect PositionPreset(Vec2D (xseq+10, yseq+140), Vec2D ( 460,30));
    PositionPreset.SetRoundness(7.5);
    PositionPreset.Draw(CouleurSurvol);



    refresh_vision_memories(xseq,yseq);
    x1_x2(xseq,yseq-25);

    Rect SeqModL(Vec2D (xseq+185, yseq+50), Vec2D (35,15));
    SeqModL.Draw(CouleurFader.WithAlpha(index_link_is_on));
    SeqModL.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitchiffre.Print("Link",xseq+187,yseq+60);
    Rect SeqMod(Vec2D (xseq+223, yseq+50), Vec2D (45,15));
    SeqMod.Draw(CouleurFader.WithAlpha(index_banger_is_on));
    SeqMod.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitchiffre.Print("Banger",xseq+225,yseq+60);
    Rect GplMod(Vec2D (xseq+275, yseq+50), Vec2D (30,15));
    GplMod.Draw(CouleurFader.WithAlpha(show_gridplayer_in_seq));
    GplMod.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitchiffre.Print("Gpl.1",xseq+277,yseq+60);

    Rect SeqAction(Vec2D (xseq,yseq), Vec2D ( 50,20));
    SeqAction.SetRoundness(7.5);

    for (int op=0; op<7; op++)
    {
        int rangee_y= yseq+180+(35*(nbre_memoires_visualisables_en_preset+1));

        SeqAction.MoveTo(Vec2D (xseq+20+(op*60),rangee_y));
        SeqAction.DrawOutline(CouleurLigne);
        if(window_focus_id==W_SEQUENCIEL &&  Midi_Faders_Affectation_Type!=0 && mouse_x>xseq+20+(op*60) && mouse_x<xseq+70+(op*60) && mouse_y>  rangee_y && mouse_y<  rangee_y+20 )//config midi
        {
            SeqAction.DrawOutline(CouleurBlind);
        }
        switch(op)
        {
        case 0:
            petitchiffre.Print("Create",xseq+23+(op*60),  rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(768,"CREATE MEM");
            break;
        case 1:
            petitchiffre.Print("Delete",xseq+23+(op*60),  rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(769,"DELETE MEM");
            break;
        case 2:
            petitchiffre.Print("Stage-",xseq+23+(op*60),rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(770,"STAGE MINUS");
            break;
        case 3:
            petitchiffre.Print("Stage+",xseq+23+(op*60),  rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(771,"STAGE PLUS");
            break;
        case 4:
            petitchiffre.Print("Preset-",xseq+23+(op*60),  rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(772,"PRESET MINUS");
            break;
        case 5:
            petitchiffre.Print("Preset+",xseq+23+(op*60), rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(773,"PRESET PLUS");
            break;
        case 6:
            petitchiffre.Print("GOTO",xseq+27+(op*60), rangee_y+15);
            if(  Midi_Faders_Affectation_Type!=0) show_type_midi(1645,"GOTO");
            break;
        default:
            break;
        }
    }


    if (index_get_back_faders_need_to_be_done==1)
    {
        Rect FondClignotant(Vec2D(xseq+450,yseq+185),Vec2D(200,30));
        FondClignotant.SetRoundness(15);
        FondClignotant.Draw(CouleurFond);
        FondClignotant.Draw(CouleurBlind.WithAlpha(alpha_blinker));

        petitdoomInspekt.Print("GET UP MIDI FADERS !",xseq+470,yseq+205);
    }



    neuro.Print(string_time_left_is,xseq+380,yseq+30);
    neuromoyen.Print("---",xseq+430,yseq+40);
    neuro.Print(string_total_time_is,xseq+380,yseq+60);
    Line(Vec2D(xseq+170,yseq+80),Vec2D(xseq+170,yseq+hauteur_seq-75)).Draw(CouleurLigne.WithAlpha(0.5));//après mem
    Line(Vec2D(xseq+180,yseq+80),Vec2D(xseq+180,yseq+hauteur_seq-75)).Draw(CouleurLigne.WithAlpha(0.5));//après exclude mem
    Line(Vec2D(xseq+220,yseq+80),Vec2D(xseq+220,yseq+hauteur_seq-75)).Draw(CouleurLigne.WithAlpha(0.5));//apres link
    Line(Vec2D(xseq+270,yseq+80),Vec2D(xseq+270,yseq+hauteur_seq-75)).Draw(CouleurLigne.WithAlpha(0.5));//apres banger
    Line(Vec2D(xseq+310,yseq+80),Vec2D(xseq+310,yseq+hauteur_seq-75)).Draw(CouleurLigne.WithAlpha(0.5));//apres banger


    if(show_gridplayer_in_seq==1)
    {
        neuromoyen.Print("GridPlayer 1 /",xseq+660,yseq+40);
        neuromoyen.Print("Grid ",xseq+760,yseq+40);
        neuromoyen.Print(ol::ToString(index_grider_selected[0]+1),xseq+810,yseq+40);
        Line(Vec2D(xseq+660,yseq+50),Vec2D(xseq+860,yseq+50)).Draw(CouleurLigne);

        Circle GriderPlus(Vec2D(xseq+910,yseq+40),12);
        Circle GriderMinus(Vec2D(xseq+880,yseq+40),12);

        petitchiffre.Print("-",xseq+877,yseq+44);
        petitchiffre.Print("+",xseq+907,yseq+44);

        GriderPlus.DrawOutline(CouleurLigne);
        GriderMinus.DrawOutline(CouleurLigne);

        if(window_focus_id==W_SEQUENCIEL  )
        {

            if(mouse_x>xseq+880-12 && mouse_x<xseq+892 && mouse_y>yseq+28 && mouse_y<yseq+52)
            {
                if( Midi_Faders_Affectation_Type!=0)
                {
                    char sttmp[24];
                    sprintf(sttmp,"Minus Grid in GridPl.1");
                    show_type_midi(1476,sttmp );
                    GriderMinus.DrawOutline(CouleurBlind);
                }
            }

            if( mouse_x>xseq+898 && mouse_x<xseq+922 && mouse_y>yseq+28 && mouse_y<yseq+52)
            {
                if(Midi_Faders_Affectation_Type!=0)
                {
                    char sttmp[24];
                    sprintf(sttmp,"Plus Grid in GridPl.1");
                    show_type_midi(1480,sttmp );
                    GriderPlus.DrawOutline(CouleurBlind);
                }
            }
        }
        petitchiffre.Print(grider_name[index_grider_selected[0]],xseq+660,yseq+70);
        TheStepBox(xseq+660,yseq+90,0);
        ThePlayCommands(xseq+760,yseq+90,0);
        TheGrid_commands(xseq+660,yseq+130,0);//pos x, posy y, num player


        Rect BoxLink(Vec2D(xseq+690, yseq+295),Vec2D(105,15));
        BoxLink.Draw(CouleurFader.WithAlpha(index_link_speed_crossfade_to_gpl1));
        BoxLink.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitchiffre.Print("Speed is CueList",xseq+693,yseq+305);
        if(window_focus_id==W_SEQUENCIEL  &&  mouse_x>xseq+690 && mouse_x<xseq+795 && mouse_y>yseq+295 && mouse_y<yseq+310)
        {
            if( Midi_Faders_Affectation_Type!=0)
            {
                char sttmp[24];
                sprintf(sttmp,"Speed is CueList GPl.1");
                show_type_midi(1540,sttmp );
                BoxLink.DrawOutline(CouleurBlind);
            }

        }
    }

    return(0);
}
