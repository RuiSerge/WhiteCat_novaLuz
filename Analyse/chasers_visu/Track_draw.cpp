int Track_draw(int xp, int yp,int num_track)
{

    Rect Btrack_sel(Vec2D(xp,yp),Vec2D(20,20));
    Btrack_sel.SetRoundness(4);
    Btrack_sel.SetLineWidth(1);


    if( track_is_on[chaser_selected][num_track]==1)
    {
        Btrack_sel.Draw(CouleurGreen);
    }
    Btrack_sel.DrawOutline(CouleurLigne);

    if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
    {
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            Btrack_sel.DrawOutline(CouleurBlind);
        }
        if(index_inspekt==1)//si au dessus de view, inspection
        {
            i_m_over_a_track=1;
            for(int pm=1; pm<513; pm++)
            {
                over_track_show_channel[pm]= TrackContains[chaser_selected][num_track][pm];
            }
        }
    }


    petitchiffre.Print(ol::ToString(num_track+1),xp+5,yp+13);
    petitpetitchiffregris.Print(chaser_track_name[chaser_selected][num_track],xp+30,yp+22);
    if(TrackTypeIs[chaser_selected][num_track]==1)
    {
        char str_ty[16];
        sprintf(str_ty,"Mem. %.1f",(float (TrackHasMem[chaser_selected][num_track])/10));
        petitpetitchiffrerouge.Print(str_ty,xp+30,yp+32);
    }
    Rect track_fader(Vec2D(xp+30,yp),Vec2D(127,10));
    Rect track_levelview(Vec2D(xp+30,yp),Vec2D(track_level[chaser_selected][num_track],10));

    track_levelview.Draw(CouleurFader);

    if(mouse_x>=xp+30 && mouse_x<=xp+157 && mouse_y>yp && mouse_y<yp+10 && Midi_Faders_Affectation_Type!=0)//config midi
    {
        track_fader.DrawOutline(CouleurRed);//midi affect
    }
    else
    {
        track_fader.DrawOutline(CouleurLigne);
    }
    petitpetitchiffre.Print(ol::ToString(track_level[chaser_selected][num_track]),xp+190,yp+25);

    char temp_steppos[32];
    sprintf(temp_steppos,"Time-Joint:B:%d E:%d R:%d", joint_begin_step[chaser_selected][num_track]+1, joint_end_step[chaser_selected][num_track]+1, count_steps_for_fades[chaser_selected][num_track]);
    petitpetitchiffregris.Print(temp_steppos,xp+240,yp+25);


    Circle BMidiOut( xp+180,yp+22, 5);//box du fader
    if(midi_send_out[1023+num_track]==1)
    {
        BMidiOut.Draw(CouleurBlind);
    }
    BMidiOut.DrawOutline(CouleurLigne);


    raccrochage_midi_visuel_horizontal_little (xp+30,yp,1023+num_track, 127, 10);
    for(int chcase=0; chcase<nbre_de_cases_par_track; chcase++)
    {
        Rect TCase(Vec2D(xp+170+(chcase*12),yp),Vec2D(12,12));
        switch(chaser_step_operation[chaser_selected][num_track][chcase])
        {
        case 0:
            TCase.Draw(CouleurLigne.WithAlpha(0.2));
            break;
        case 1:
            TCase.Draw(CouleurFader);
            break;
        case 2:
            TCase.Draw(CouleurGreen);
            break;
        case 3:
            TCase.Draw(CouleurRed);
            break;
        default:
            break;
        }
        TCase.DrawOutline(CouleurFond);


        if( launchpad_chaser_mode==1)
        {
            if(num_track-position_affichage_track_num[chaser_selected]<chaser_midi_rows)
            {
                if( chcase>=chaser_step_launchpad[chaser_selected] && chcase<chaser_step_launchpad[chaser_selected]+8 )
                {
                    if(Midi_Faders_Affectation_Type!=0 )//config midi
                    {
                        TCase.DrawOutline(CouleurBlind);
                    }
                    else
                    {
                        TCase.DrawOutline(CouleurLigne);
                    }
                }


            }
        }
    }
    return(0);
}
