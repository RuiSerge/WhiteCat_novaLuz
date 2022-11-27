int chaser_window(int xcha,int ycha)
{


    Rect ChaserPanel(Vec2D(xcha,  ycha), Vec2D( 620,(160+(nbre_track_visualisables*40))));
    ChaserPanel.SetRoundness(15);
    ChaserPanel.SetLineWidth(triple_epaisseur_ligne_fader);
    ChaserPanel.Draw(CouleurFond);
    if(window_focus_id==W_CHASERS)
    {
        ChaserPanel.DrawOutline(CouleurFader);
    }
    else
    {
        ChaserPanel.DrawOutline(CouleurLigne);
    }
    neuro.Print("CHASERS",xcha+100,ycha+30);




    Circle ChazePlus(Vec2D(xcha+300,ycha+25),12);
    Circle ChazeMinus(Vec2D(xcha+220,ycha+25),12);

    petitchiffre.Print("-",xcha+217,ycha+28);
    petitchiffre.Print("+",xcha+295,ycha+28);
    neuro.Print(ol::ToString(chaser_selected+1),xcha+250,ycha+32);
    ChazePlus.DrawOutline(CouleurLigne);
    ChazeMinus.DrawOutline(CouleurLigne);
    if( Midi_Faders_Affectation_Type!=0  && window_focus_id==923)//config midi
    {
        if( mouse_x>xcha+208 && mouse_x<xcha+232 && mouse_y>ycha+13 && mouse_y<ycha+37)
        {
            ChazeMinus.DrawOutline(CouleurBlind);
        }
        if(mouse_x>xcha+288 && mouse_x<xcha+312 && mouse_y>ycha+13 && mouse_y<ycha+37)
        {
            ChazePlus.DrawOutline(CouleurBlind);
        }
    }



    Rect GiveNameOfchaser(Vec2D(xcha+330,ycha+10), Vec2D( 185,30));
    GiveNameOfchaser.SetRoundness(7.5);
    GiveNameOfchaser.Draw(CouleurSurvol);

    petitchiffre.Print( chaser_name[chaser_selected],(xcha+335), (ycha+30));


    Rect ChazeEditEnable( Vec2D((xcha+560),(ycha+10)),Vec2D(50,20));
    ChazeEditEnable.SetRoundness(7.5);
    if(index_enable_edit_chaser==1)
    {
        ChazeEditEnable.Draw(CouleurFader);
    }
    ChazeEditEnable.DrawOutline(CouleurLigne);
    petitchiffre.Print("edit",xcha+570,ycha+22);




    play_button_view(xcha+10,ycha+50,chaser_is_playing[chaser_selected]);

    if(mouse_x>xcha+40 && mouse_x<xcha+60 && mouse_y>ycha+50 && mouse_y<ycha+70 && window_focus_id==923 && mouse_button==1 && mouse_released==0)
    {
        seek_button_view(xcha+40,ycha+50,1);//seek , affichage avant le bouton
        mouse_released=1;
    }
    seek_button_view(xcha+40,ycha+50,0);


    loop_button_view(xcha+70,ycha+50,chaser_is_in_loop[chaser_selected]);




    if(chaser_way[chaser_selected]==0)
    {
        set_forward_sens_view(xcha+110,ycha+50,1);
    }
    else
    {
        set_forward_sens_view(xcha+110,ycha+50,0);
    }


    if(chaser_way[chaser_selected]==1)
    {
        set_backward_sens_view(xcha+140,ycha+50,1);
    }
    else
    {
        set_backward_sens_view(xcha+140,ycha+50,0);
    }



    if(chaser_aller_retour[chaser_selected]==1)
    {
        set_back_and_forward_sens_view(xcha+170,ycha+50,1);
    }
    else
    {
        set_back_and_forward_sens_view(xcha+170,ycha+50,0);
    }



    char temp_str_chi[36];
    sprintf(temp_str_chi,"Last Affect: Fader %d Dock %d",view_chaser_affected_to_fader[chaser_selected][0]+1,view_chaser_affected_to_fader[chaser_selected][1]+1);
    petitpetitchiffregris.Print(temp_str_chi,xcha+5,ycha+120);
    sprintf(temp_str_chi,"Step Is: %d   Evolution: %.2f",chaser_step_is[chaser_selected]+1,index_progression_chaser_step[chaser_selected]);
    petitpetitchiffregris.Print(temp_str_chi,xcha+5,ycha+137);
    sprintf(temp_str_chi,"Chaser LFO Slaviness: %.2f",chaser_slaviness[chaser_selected]);
    petitpetitchiffregris.Print(temp_str_chi,xcha+5,ycha+150);

    Rect Affectchaser(Vec2D(xcha+430,ycha+80), Vec2D(110,20));
    Affectchaser.SetRoundness(7.5);
    if(index_affect_chaser_to_dock==1)
    {
        Affectchaser.Draw(CouleurFader);
    }
    Affectchaser.DrawOutline(CouleurLigne);

    petitchiffre.Print( "Affect To Dock",(xcha+440), (ycha+95));



    if(mouse_x>xcha+10 && mouse_x<xcha+30 && mouse_y>ycha+80 && mouse_y<ycha+100 && window_focus_id==923)
    {
        if(mouse_button==1 && mouse_released==0)
        {
            bouton_text_view(xcha+10, ycha+80,"all", 1);
        }
    }
    bouton_text_view(xcha+10, ycha+80,"all", 0);


    if(mouse_x>xcha+40 && mouse_x<xcha+60 && mouse_y>ycha+80 && mouse_y<ycha+100 && window_focus_id==923)
    {
        if(mouse_button==1 && mouse_released==0)
        {
            bouton_text_view(xcha+40, ycha+80,"inv", 1);
        }
    }
    bouton_text_view(xcha+40, ycha+80,"inv", 0);


    if(mouse_x>xcha+70 && mouse_x<xcha+90 && mouse_y>ycha+80 && mouse_y<ycha+100 && window_focus_id==923)
    {
        if(mouse_button==1 && mouse_released==0)
        {
            bouton_text_view(xcha+70, ycha+80,"off", 1);
        }
    }
    bouton_text_view(xcha+70, ycha+80,"off", 0);





    char tl[8];
    for(int po=0; po<4; po++)
    {
        sprintf(tl,"P%d",po+1);
        if(mouse_x>xcha+110+(po*30) && mouse_x<xcha+150+(po*30) && mouse_y>ycha+80 && mouse_y<ycha+100 && window_focus_id==923)
        {
            if(mouse_button==1 && mouse_released==0)
            {
                bouton_text_view(xcha+110+(po*30), ycha+80,tl, 1);
            }
        }
        bouton_text_view(xcha+110+(po*30), ycha+80,tl, 0);
    }

    Rect RelyToFaderMode(Vec2D(xcha+345,ycha+50),Vec2D(40,20));
    RelyToFaderMode.SetRoundness(5);
    if(index_slave_chaser_to_accelerometre[chaser_selected]==1)
    {
        RelyToFaderMode.Draw(CouleurFader);
    }
    RelyToFaderMode.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print("Slave",xcha+350,ycha+65);


    char temp_tunit[24];
    Rect Tunit(Vec2D(xcha+245,ycha+50),Vec2D(50,20));
    Tunit.SetRoundness(5);
    if(mouse_x>xcha+245 && mouse_x<xcha+295 && mouse_y>ycha+50 && mouse_y<ycha+70)
    {
        Tunit.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    }
    Tunit.DrawOutline(CouleurLigne);


    switch(index_affichage_digit_time_unit)
    {
    case 0:
        sprintf(temp_tunit,"T.Unit:       %.1f",time_unit[chaser_selected]*chaser_slaviness[chaser_selected]);
        break;
    case 1:
        sprintf(temp_tunit,"T.Unit:      %.2f",time_unit[chaser_selected]*chaser_slaviness[chaser_selected]);
        break;
    case 2:
        sprintf(temp_tunit,"T.Unit:     %.3f",time_unit[chaser_selected]*chaser_slaviness[chaser_selected]);
        break;
    case 3:
        sprintf(temp_tunit,"T.Unit:    %.4f",time_unit[chaser_selected]*chaser_slaviness[chaser_selected]);
        break;
    default:
        break;
    }

    petitpetitchiffre.Print(temp_tunit,xcha+200,ycha+64);


    Rect TMode(Vec2D(xcha+305,ycha+50),Vec2D(30,20));
    TMode.SetRoundness(5);
    if(chaser_time_mode[chaser_selected]==1)
    {
        TMode.Draw(CouleurFader);
        petitpetitchiffre.Print("TJoin",xcha+306,ycha+65);
    }
    else
    {
        petitpetitchiffre.Print("T.Std",xcha+305,ycha+65);
    }
    TMode.DrawOutline(CouleurLigne);

    switch (chaser_operator_is)
    {
    case 1://up
        bouton_track_up(xcha+245, ycha+80, 1);
        bouton_track_stay(xcha+295, ycha+80, 0);
        bouton_track_down(xcha+345, ycha+80, 0);
        break;
    case 2://stay
        bouton_track_up(xcha+245, ycha+80, 0);
        bouton_track_stay(xcha+295, ycha+80, 1);
        bouton_track_down(xcha+345, ycha+80, 0);
        break;
    case 3: //down
        bouton_track_up(xcha+245, ycha+80, 0);
        bouton_track_stay(xcha+295, ycha+80, 0);
        bouton_track_down(xcha+345, ycha+80, 1);
        break;
    default:
        bouton_track_up(xcha+245, ycha+80, 0);
        bouton_track_stay(xcha+295, ycha+80, 0);
        bouton_track_down(xcha+345, ycha+80, 0);
        break;
    }



    Rect CurseurBeginPoint(Vec2D(xcha+175+(chaser_begin_step_is[chaser_selected]*12),ycha+115),Vec2D(12,12));
    CurseurBeginPoint.Draw(CouleurFader);
    if( Midi_Faders_Affectation_Type!=0 && mouse_x>xcha+175+(chaser_begin_step_is[chaser_selected]*12) && mouse_x<xcha+187+(chaser_begin_step_is[chaser_selected]*12)
            && mouse_y>ycha+115 && mouse_y<ycha+127)//config midi
    {
        CurseurBeginPoint.SetLineWidth(2);
        CurseurBeginPoint.DrawOutline(CouleurRed);
    }
    Rect CurseurEndPoint(Vec2D(xcha+175+(chaser_end_step_is[chaser_selected]*12),ycha+127),Vec2D(12,12));
    CurseurEndPoint.Draw(CouleurRed);
    if( Midi_Faders_Affectation_Type!=0 && mouse_x>xcha+175+(chaser_end_step_is[chaser_selected]*12) && mouse_x<xcha+187+(chaser_end_step_is[chaser_selected]*12)
            && mouse_y>ycha+127 && mouse_y<ycha+139)//config midi
    {
        CurseurEndPoint.SetLineWidth(2);
        CurseurEndPoint.Draw(CouleurFond);
        CurseurEndPoint.DrawOutline(CouleurRed);
    }

    bouton_view_track_downup(xcha+580, ycha+35, 0);
    int upsidedown=1;

    for(int chcase=0; chcase<nbre_de_cases_par_track; chcase++)
    {
        upsidedown=toggle(upsidedown);
        Line(Vec2D(xcha+175+(chcase*12),ycha+115),Vec2D(xcha+175+(chcase*12),ycha+135)).Draw(CouleurLigne.WithAlpha(0.2));
        petitpetitchiffre.Print(ol::ToString(chcase+1),xcha+175+(chcase*12),ycha+123+(upsidedown*12));
    }
    Line(Vec2D(xcha+10,ycha+125),Vec2D(xcha+590,ycha+125)).Draw(CouleurLigne.WithAlpha(0.3));






    for(int track_num=0; track_num<nbre_track_visualisables; track_num++)
    {
        Track_draw(xcha+5,ycha+165+(track_num*40),position_affichage_track_num[chaser_selected]+track_num);
    }


    Rect TimelineChaser(Vec2D(xcha+175,ycha+145),Vec2D(36*12,10));
    TimelineChaser.Draw(CouleurLigne.WithAlpha(0.2));
    if( Midi_Faders_Affectation_Type!=0)//config midi
    {
        if(mouse_x>xcha+175 && mouse_x<xcha+175+(nbre_de_cases_par_track*12) && mouse_y>ycha+145 && mouse_y<ycha+155)
        {
            TimelineChaser.DrawOutline(CouleurBlind);

        }
    }



    int id_way=0;
    switch(chaser_way[chaser_selected])
    {
    case 0://FORWARD
        id_way=1;
        Line(Vec2D(xcha+175+(chaser_step_is[chaser_selected]*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+115),Vec2D(xcha+175+(chaser_step_is[chaser_selected]*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+145+(nbre_track_visualisables*40))).Draw(CouleurFader);
        Line(Vec2D(xcha+176+(chaser_step_is[chaser_selected]*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+115),Vec2D(xcha+176+(chaser_step_is[chaser_selected]*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+145+(nbre_track_visualisables*40))).Draw(CouleurFader);

        break;
    case 1://BACKWARD
        id_way=-1;
        Line(Vec2D(xcha+175+((chaser_step_is[chaser_selected]+1)*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+115),Vec2D(xcha+175+((chaser_step_is[chaser_selected]+1)*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+145+(nbre_track_visualisables*40))).Draw(CouleurFader);
        Line(Vec2D(xcha+176+((chaser_step_is[chaser_selected]+1)*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+115),Vec2D(xcha+176+((chaser_step_is[chaser_selected]+1)*12)+(index_progression_chaser_step[chaser_selected]*12*id_way),ycha+145+(nbre_track_visualisables*40))).Draw(CouleurFader);
        break;
    default:
        break;
    }


    Rect PosCurseur(Vec2D(xcha+175+(chaser_step_is[chaser_selected]*12)+(12*index_progression_chaser_step[chaser_selected]*id_way),ycha+145),Vec2D(12,10));
    PosCurseur.Draw(CouleurLigne.WithAlpha(0.3));




    Rect LaunchpadAllowB(Vec2D(xcha+410,ycha+50),Vec2D(40,20));
    LaunchpadAllowB.SetRoundness(5);
    if( launchpad_chaser_mode==1)
    {
        LaunchpadAllowB.Draw(CouleurFader);
        bouton_view_launchpad_pos(xcha+450, ycha+35,0);
    }
    LaunchpadAllowB.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print("LchPad",xcha+411,ycha+65);


    Rect refreshMidiB(Vec2D(xcha+520,ycha+50),Vec2D(40,20));
    refreshMidiB.SetRoundness(5);
    refreshMidiB.Draw(CouleurSurvol.WithAlpha( refresh_midi_chasers));
    refreshMidiB.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print("Refresh",xcha+520,ycha+58);
    petitpetitchiffre.Print("Midi",xcha+527,ycha+67);

    return(0);
}
