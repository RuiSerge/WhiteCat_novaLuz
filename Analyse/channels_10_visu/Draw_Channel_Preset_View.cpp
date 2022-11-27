int Draw_Channel_Preset_View(int xchan, int ychan,  int prst_v)
{


    int num_circ=0;
    char chan_is[6];
    int xposch=0;
    int ypos_ch=0;
    int showisup=0;//0 = equal 1= is up 2=is down

    float myalpha_channel=0.0;
    int maxchan_per_ligne=12;
    int nbre_lignes=channel_number_of_lines[prst_v];



    Rect ChannelRect(Vec2D(xchan, ypos_ch),Vec2D(40,65));
    ChannelRect.SetRoundness(10);
    ChannelRect.SetLineWidth(epaisseur_ligne_fader);
    Rect LevelOverdock(Vec2D(xchan, ypos_ch),Vec2D(35,13));
    Rect LevelOverTrack(Vec2D(xchan,ypos_ch),Vec2D(35,13));
    Rect LevelModified(Vec2D(xchan,ypos_ch),Vec2D(20,13));


    for (int l=0; l<=nbre_lignes; l++)
    {
        if (l==nbre_lignes)
        {
            maxchan_per_ligne=channel_number_in_View[prst_v]%12;
        }

        for (int c=1; c<=maxchan_per_ligne; c++)
        {

            num_circ=Channel_View_ROUTING[prst_v][c+(l*12)-1];

            if(num_circ!=0 && num_circ<513)
            {

                xposch=45*c;
                ypos_ch=ychan+(l*(70));

                if(ypos_ch>-30 && ypos_ch<hauteur_ecran)//condition affichage
                {

                    ChannelRect.MoveTo(Vec2D(((xchan-5) + (xposch)), ypos_ch));

                    unsigned char circuittoshow=bufferSequenciel[num_circ] ;
                    showisup=0;

                    if  (bufferSequenciel[num_circ] < bufferBlind[num_circ])
                    {
                        showisup=1;
                    }
                    else if  (bufferSequenciel[num_circ] > bufferBlind[num_circ])
                    {
                        showisup=2;
                    }

                    if(circuittoshow>0) // FORMULE MAGIQUE
                    {
                        myalpha_channel=((float)circuittoshow/255);
                        ChannelRect.Draw(CouleurNiveau.WithAlpha(myalpha_channel/2));
                    }

                    if(bufferFaders[num_circ]>0) // FORMULE MAGIQUE
                    {
                        myalpha_channel=((float)bufferFaders[num_circ]/255);
                        ChannelRect.Draw(CouleurFader.WithAlpha(myalpha_channel/2));
                    }

                    switch(index_blind)//differencec avec mem enregistr�e
                    {
                    case 0:
                        if(bufferSaisie[num_circ]!=Memoires[position_onstage][num_circ] && index_blink_change_memories==1)
                        {
                            ChannelRect.Draw(CouleurNiveau.WithAlpha(alpha_blinker));
                        }
                        break;
                    case 1:
                        if(bufferBlind[num_circ]!=Memoires[position_preset][num_circ]  && index_blink_change_memories==1)
                        {
                            ChannelRect.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                        }
                        break;
                    default:
                        break;
                    }



                    if(c<100)
                    {
                        sprintf(chan_is," %d",num_circ);
                        petitchiffre.Print(chan_is,(xchan + (xposch)),ypos_ch +10,CENTER);
                    }
                    else if(c>=100)
                    {
                        sprintf(chan_is,"%d",num_circ);
                        petitchiffre.Print(chan_is,((xchan + (xposch))-5),ypos_ch +10,CENTER);
                    }


                    switch(showisup)
                    {
                    case 1:
                        petitpetitchiffre.Print("+", (xchan + 15+(xposch)),ypos_ch+30,RIGHT );
                        break;
                    case 2:
                        petitpetitchiffre.Print("-", (xchan + 15+(xposch)),ypos_ch+30,RIGHT );
                        break;
                    default:
                        break;
                    }

                    if(index_inspekt==1)
                    {
                        if (show_who_is_in_FADER_DOCK[num_circ]==1 )
                        {
                            ChannelRect.DrawOutline(CouleurFader);
                            LevelOverdock.MoveTo(Vec2D(((xchan-5) + (xposch))+15, ypos_ch+52));
                            LevelOverdock.Draw(CouleurFader);
                        }
                        if(highest_level_comes_from_fader[num_circ]>0)//si le highest level exist : valeur faders de 1 � 48 quand attribu�
                        {
                            petitdoomInspekt.Print(ol::ToString(highest_level_comes_from_fader[num_circ]),((xchan + (xposch))+15),ypos_ch+32,CENTER);
                        }
                        if(i_m_over_a_track==1 && over_track_show_channel[num_circ]>0)
                        {
                            ChannelRect.DrawOutline(CouleurGreen);
                            LevelOverTrack.MoveTo(Vec2D(((xchan-5) + (xposch))-15,ypos_ch+52));
                            LevelOverTrack.Draw(CouleurGreen);
                        }
                    }


                    switch (dmx_view)
                    {
                    case 0:
                        if(circuittoshow>0)
                        {
                            circuitlevel.Print(ol::ToString((int) (((float)(circuittoshow) /2.55))),(xchan + (xposch)), ypos_ch+40,CENTER );
                        }
                        if(bufferFaders[num_circ]>0)
                        {
                            circuitfaderlevel.Print(ol::ToString((int) (((float)(bufferFaders[num_circ]) /2.55))),(xchan + (xposch)),ypos_ch+50,CENTER );
                        }
                        if( index_blind==1 && bufferBlind[num_circ]>0)
                        {
                            circuitblindlevel.Print(ol::ToString((int) (((float)(bufferBlind[num_circ]) /2.55))),(xchan + (xposch)),ypos_ch+60,CENTER );
                        }
                        if(index_inspekt==1 && show_who_is_in_FADER_DOCK[num_circ]==1)
                        {
                            petitpetitchiffre.Print(ol::ToString((int)(((float)(FaderDockContains[over_fader][over_dock][num_circ]) /2.55))),(xchan + (xposch))+15,ypos_ch+60,CENTER );
                        }
                        if(index_inspekt==1 && i_m_over_a_track==1 && over_track_show_channel[num_circ]>0)
                        {
                            petitpetitchiffre.Print(ol::ToString((int)(float(over_track_show_channel[num_circ]) /2.55)),(xchan + (xposch))-15,ypos_ch+60,CENTER );
                        }


                        if(freeze_array[num_circ]==1)
                        {
                            ChannelRect.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                            petitchiffre.Print(ol::ToString((int) (((float)(freeze_state[num_circ]) /2.55))),(xchan + (xposch))+10, ypos_ch+30,CENTER );
                        }

                        break;

                    case 1:
                        if(circuittoshow>0)
                        {
                            circuitlevel.Print(ol::ToString((int)circuittoshow),(xchan + (xposch)),ypos_ch+40,CENTER );
                        }
                        if(bufferFaders[num_circ]>0)
                        {
                            circuitfaderlevel.Print(ol::ToString((int)(bufferFaders[num_circ])),(xchan + (xposch)),ypos_ch+50,CENTER );
                        }
                        if(index_blind==1 && bufferBlind[num_circ]>0 )
                        {
                            circuitblindlevel.Print(ol::ToString((int)(bufferBlind[num_circ])),(xchan + (xposch)), ypos_ch+60,CENTER );
                        }
                        if(index_inspekt==1 && show_who_is_in_FADER_DOCK[num_circ]==1)
                        {
                            petitpetitchiffre.Print(ol::ToString((int)(FaderDockContains[over_fader][over_dock][num_circ])),(xchan + (xposch))+15,ypos_ch+60,CENTER );
                        }
                        if(index_inspekt==1 && i_m_over_a_track==1)
                        {
                            petitpetitchiffre.Print(ol::ToString(over_track_show_channel[num_circ]),(xchan + (xposch))-15,ypos_ch+60,CENTER );
                        }


                        if(freeze_array[num_circ]==1)
                        {
                            ChannelRect.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                            petitchiffre.Print(ol::ToString((int)(freeze_state[num_circ])),(xchan + (xposch))+10,ypos_ch+30,CENTER );
                        }
                        break;
                    default:
                        break;
                    }

                    if(num_circ==go_channel_is && index_go==1 && index_pause==0)
                    {
                        ChannelRect.Draw(CouleurGreen.WithAlpha(alpha_blinker));
                        minidoomblanc.Print("GO",(xchan + (xposch)),ypos_ch+40,CENTER );
                    }

                    if(num_circ==pause_channel_is && index_go==1 && index_pause==1)
                    {
                        ChannelRect.Draw(CouleurYellow.WithAlpha(alpha_blinker));
                        minidoomblanc.Print("PAUSE",(xchan + (xposch))-10,ypos_ch+40,CENTER );
                    }

                    if(Channels_excluded_from_grand_master[num_circ]==1)
                    {
                        Circle CircleExcluded(xchan + xposch+26, ypos_ch +11, 3);
                        CircleExcluded.DrawOutline(CouleurBlind);
                    }

                    if(channel_is_touched_by_fader_fx[num_circ]==1)
                    {
                        Circle CircleTouchedbyFx(xchan + xposch+26, ypos_ch +20, 3);
                        switch(channel_is_touched_by_fader_type_fx[num_circ])
                        {
                        case 0://normal HTP
                            CircleTouchedbyFx.Draw(CouleurFader);
                            break;
                        case 1://off
                            CircleTouchedbyFx.Draw(CouleurFond);
                            break;
                        case 2://minus
                            CircleTouchedbyFx.Draw(CouleurRougePur);
                            break;
                        case 3://add
                            CircleTouchedbyFx.Draw(CouleurLigne);
                            break;
                        case 4://screen
                            CircleTouchedbyFx.Draw(CouleurLevel);
                            break;
                        case 5://exclusion
                            CircleTouchedbyFx.Draw(CouleurBleuProcedure);
                            break;
                        default:
                            break;
                        }
                        minichiffre.Print(ol::ToString(channel_is_touched_by_fader_number[num_circ]+1),xchan + xposch+30,ypos_ch+20 );
                        CircleTouchedbyFx.DrawOutline(CouleurLigne);
                    }

                    if (Selected_Channel[num_circ]==1)
                    {
                        ChannelRect.DrawOutline(CouleurLigne);
                    }


                    if(channel_level_mofification_while_crossfade[num_circ]!=0)
                    {
                        LevelModified.MoveTo(Vec2D(xchan+xposch+20,ypos_ch+30));
                        LevelModified.Draw(CouleurBlind);
                        switch (dmx_view)
                        {
                        case 0:
                            petitpetitchiffre.Print(ol::ToString((int) (((float)(channel_level_mofification_while_crossfade[num_circ]) /2.55))),(xchan + xposch+25),ypos_ch+40,RIGHT );
                            break;
                        case 1:
                            petitpetitchiffre.Print(ol::ToString(channel_level_mofification_while_crossfade[num_circ]),(xchan + xposch+25),ypos_ch+40,RIGHT );
                            break;
                        default:
                            break;
                        }
                    }

                    if(index_show_first_dim==1)
                    {
                        for(int llo=0; llo<4; llo++)
                        {
                            if(show_first_dim_array[num_circ][llo]!=0)
                            {
                                petitdoomrouge.Print(ol::ToString(show_first_dim_array[num_circ][llo]),(xchan + xposch +5), ypos_ch+35+(llo*10));
                            }
                        }
                        if(show_more_than_one_dim[num_circ]==1)
                        {
                            petitdoomrouge.Print("+",(xchan + xposch +20), ypos_ch+23);
                        }
                    }

                }//fin condition affichage

            }
        }
    }


    return(0);
}
