int FaderSpace(int x, int y, int espacement,int nbr_fader)
{
    Rect BackgroundFaderSpace(Vec2D(-20,y-80),Vec2D(LargeurEspaceFaderSize+20,hauteur_ecran));

    BackgroundFaderSpace.SetLineWidth(5.0);
    BackgroundFaderSpace.SetRoundness(15);
    BackgroundFaderSpace.Draw(CouleurFond);
    if(LargeurEspaceFaderSize!=largeur_ecran)
    {
        if(window_focus_id==W_FADERS)
        {
            BackgroundFaderSpace.DrawOutline(CouleurFader);
        }
        else
        {
            BackgroundFaderSpace.DrawOutline(CouleurLigne);
        }
    }

    Canvas::SetClipping(0,y-80,LargeurEspaceFaderSize,hauteur_ecran);

    for (int cmptfader=0; cmptfader<core_user_define_nb_faders; cmptfader++)
    {
        if(((x+(cmptfader*espacement)+espacement)>0)&& ((x+(cmptfader*espacement))<LargeurEspaceFaderSize))
        {
            int niveau=(int)Fader[cmptfader];
            myalpha=((float)niveau/255);
            switch(dmx_view)
            {
            case 0:
                if(FaderLocked[cmptfader]==1)
                {
                    petitchiffrerouge.Print(ol::ToString((int)((float)(StateOfFaderBeforeLock[cmptfader])/2.55)),x+(cmptfader*espacement)+12,y+273);
                }
                sprintf(string_niveau, "%d",(int)(((float)niveau)/2.55));
                break;
            case 1:
                sprintf(string_niveau,"%d", niveau);
                if(FaderLocked[cmptfader]==1)
                {
                    petitchiffrerouge.Print(ol::ToString((int)StateOfFaderBeforeLock[cmptfader]),x+(cmptfader*espacement)+12,y+273);
                }
                break;
            default:
                break;
            }
            sprintf(string_channel,"%d", cmptfader+1);

            Rect RouteMdeFx(Vec2D(x+(cmptfader*espacement)+60, y-30),Vec2D(10,10));
            switch(fader_fx_route[cmptfader])
            {
            case 0://espace faders
                RouteMdeFx.Draw(CouleurFader);
                break;
            case 1://espace séquenciel
                RouteMdeFx.Draw(CouleurNiveau.WithAlpha(0.5));
                break;
            default:
                break;
            }
            RouteMdeFx.DrawOutline(CouleurLigne.WithAlpha(0.5));

            Rect Mode_buffer_data(Vec2D(x+(cmptfader*espacement)+75, y-30),Vec2D(40,10));
            Mode_buffer_data.SetRoundness(0.2);
            switch(fader_mode_with_buffers[cmptfader])
            {
            case 0://normal HTP
                Mode_buffer_data.Draw(CouleurFader);
                petitpetitchiffre.Print("",x+(cmptfader*espacement)+70, y-10);
                break;
            case 1://off
                Mode_buffer_data.Draw(CouleurFond);
                petitpetitchiffre.Print("     off",x+(cmptfader*espacement)+70, y-10);
                break;
            case 2://minus
                Mode_buffer_data.Draw(CouleurRougePur);
                petitpetitchiffre.Print("subtract",x+(cmptfader*espacement)+70, y-10);
                break;
            case 3://add
                Mode_buffer_data.Draw(CouleurLigne);
                petitpetitchiffre.Print("    add",x+(cmptfader*espacement)+70, y-10);
                break;
            case 4://screen
                Mode_buffer_data.Draw(CouleurLevel);
                petitpetitchiffre.Print("  screen",x+(cmptfader*espacement)+70, y-10);
                break;
            case 5://exclusion
                Mode_buffer_data.Draw(CouleurBleuProcedure);
                petitpetitchiffre.Print(" exclusion",x+(cmptfader*espacement)+70, y-10);
                break;
            default:
                break;
            }
            Mode_buffer_data.DrawOutline(CouleurLigne.WithAlpha(0.3));



            Rect FaderB( Vec2D( x+(cmptfader*espacement),y+2), Vec2D ( 40,255));//box du fader
            FaderB.SetRoundness(15);
            FaderB.SetLineWidth(epaisseur_ligne_fader);

            Rect FaderNiveau( Vec2D(  x+(cmptfader*espacement),(y+255) - niveau), Vec2D ( 40,niveau+2));//niveau fader
            FaderNiveau.SetRoundness(15);
            Line(Vec2D(x+(cmptfader*espacement)-20,y-50),Vec2D(x+(cmptfader*espacement)-20,y+400)).Draw(CouleurLigne);
            if(FaderLocked[cmptfader]==0)
            {
                switch(DockTypeIs[cmptfader][(dock_used_by_fader_is[cmptfader])])
                {
                default:
                    FaderNiveau.Draw(CouleurFader.WithAlpha(myalpha));
                    break;
                case 11://Fx
                    if(chaser_is_playing[ChaserAffectedToDck[cmptfader][dock_used_by_fader_is[cmptfader]]]==0)FaderNiveau.Draw(CouleurGreen);
                    else FaderNiveau.Draw(CouleurGreen.WithAlpha(alpha_blinker));
                    break;
                case 12://Grid
                    if(grider_is_playing[faders_dock_grid_affectation[cmptfader][dock_used_by_fader_is[cmptfader]]]==0)  FaderNiveau.Draw(CouleurBlind);
                    else FaderNiveau.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                    break;
                case 13://Fgroup
                    FaderNiveau.Draw(CouleurYellowFgroup);
                    break;
                case 14://mover
                    FaderNiveau.Draw( CouleurSelection);
                    break;
                case 15://draw
                    FaderNiveau.Draw(CouleurLevel);
                    break;
                case 16://echo
                    FaderNiveau.Draw(Discrete8);
                    break;
                case 17://wave
                    FaderNiveau.Draw(CouleurBleu2);
                    break;
                }
            }
            else//fader locké
            {
                FaderNiveau.Draw(CouleurLock.WithAlpha(myalpha*2));//couleur en vert emeraude
                if(LockFader_is_FullLevel[cmptfader]==1 && actual_master_lock==cmptfader)
                {
                    //marker rouge rouge du niveau at full lors lockage
                    doomrouge.Print("m",x+11+(cmptfader*espacement), y+35);
                }
            }
            FaderB.DrawOutline(CouleurLigne);


            Rect Midireceive( Vec2D( x+(cmptfader*espacement)+135,y-35), Vec2D ( 15,15));//box du boutton assignation rapide
            Midireceive.SetRoundness(4);
            Midireceive.SetLineWidth(epaisseur_ligne_fader);

            Midireceive.Draw(CouleurFader.WithAlpha(light_midi_do_order[cmptfader]));//quand midi allumé
            if(light_midi_do_order[cmptfader]>0.0)
            {
                light_midi_do_order[cmptfader]-=0.2;
            }
            petitpetitchiffre.Print("V",x+(cmptfader*espacement)+138,y-25);

            Midireceive.DrawOutline(CouleurLigne);


            Rect Dock(Vec2D(x, y ), Vec2D ( 50,20));
            Dock.SetRoundness(8);
            Dock.SetLineWidth(sizefader_epaisseur_ligne_fader);
            for (int dd=0; dd<core_user_define_nb_docks; dd++)
            {
                Dock.MoveTo(Vec2D(x+((cmptfader*espacement)+70), y + (dd*40)));
                petitpetitchiffre.Print(ol::ToString(dd+1),x+(cmptfader*espacement)+55, y + 15+(dd*40));
                if(window_focus_id==W_FADERS && mouse_x>=(x+(cmptfader*espacement)+70) && mouse_x<=(x+(cmptfader*espacement)+120)
                        && mouse_y>=(y + (dd*40)) && mouse_y<=(y + (dd*40)+20)
                        && index_over_function_call==0 )
                {
                    show_who_is_in_dock(cmptfader,dd);  //mise en affichage sélection de qui est dans le dock
                }
                if (DockIsSelected[cmptfader][dd]==1)
                {
                    if(FaderLocked[cmptfader]==0)
                    {
                        Dock.Draw(CouleurFader);
                    }
                    else if(FaderLocked[cmptfader]==1)
                    {
                        Dock.Draw(CouleurLock);
                    }
                    if(DockTypeIs[cmptfader][dd]==5)
                    {
                        for(int tt=0; tt<24; tt++)
                        {
                            DockName[cmptfader][dd][tt]=descriptif_memoires[(DockHasMem[cmptfader][dd])][tt] ;
                        }
                        DockName[cmptfader][dd][24]='\0';
                    }
                    else if(DockTypeIs[cmptfader][dd]==6 || DockTypeIs[cmptfader][dd]==7 || DockTypeIs[cmptfader][dd]==8)
                    {
                        Dock.Draw(CouleurNiveau);
                        FaderNiveau.Draw(CouleurNiveau);
                        switch(FaderLocked[cmptfader])
                        {
                        case 0:
                            FaderB.DrawOutline(CouleurLigne);
                            break;
                        case 1:
                            FaderB.DrawOutline(CouleurLock);
                            break;
                        default:
                            break;
                        }
                    }
                    else if(DockTypeIs[cmptfader][dd]==11)//chaser
                    {
                        for(int tt=0; tt<24; tt++)
                        {
                            DockName[cmptfader][dd][tt]=chaser_name[(ChaserAffectedToDck[cmptfader][dd])][tt] ;
                        }
                        DockName[cmptfader][dd][24]='\0';
                        Dock.Draw(CouleurGreen);
                    }
                    else if(DockTypeIs[cmptfader][dd]==12)//Grid
                    {
                        for(int tt=0; tt<24; tt++)
                        {
                            DockName[cmptfader][dd][tt]=grider_name[index_grider_selected[faders_dock_grid_affectation[cmptfader][dd]]][tt] ;
                        }
                        DockName[cmptfader][dd][24]='\0';
                        Dock.Draw(CouleurBlind);
                    }
                    else if(DockTypeIs[cmptfader][dd]==13)//Fgroup
                    {
                        Dock.Draw(CouleurYellowFgroup);
                    }
                    else if(DockTypeIs[cmptfader][dd]==14)//mover
                    {
                        Dock.Draw(CouleurSelection);
                    }
                    else if(DockTypeIs[cmptfader][dd]==15)//draw
                    {
                        Dock.Draw(CouleurLevel);
                    }

                    else if(DockTypeIs[cmptfader][dd]==16)//echo
                    {
                        Dock.Draw( Discrete8);
                    }

                    else if(DockTypeIs[cmptfader][dd]==17)//echo
                    {
                        Dock.Draw(CouleurBleu2);
                    }

                    petitpetitchiffre.Print( DockName[cmptfader][dd],x+(cmptfader*espacement)-5,y-10 ) ;
                }



                switch(DockTypeIs[cmptfader][dd])
                {
                case 1://si le doc est relié aux trichro
                    petitchiffre.Print("Color",x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 2://si le doc est relié à un artnet
                    sprintf( string_docktypnet,"Art-%d",DockNetIs[cmptfader][dd]);
                    petitchiffre.Print(string_docktypnet,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 3://si le doc recoit le dmxIN
                    sprintf( string_docktypnet,"Dmx-In");
                    petitchiffre.Print(string_docktypnet,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 4://si le doc recoit le tracking video
                    sprintf( string_docktypvideo,"Video");
                    petitchiffre.Print(string_docktypvideo,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 5://si le doc contient une memoire
                    sprintf( string_docktypmem,"%.1f",(((float)(DockHasMem[cmptfader][dd]))/10));
                    petitchiffre.Print(string_docktypmem,x+((cmptfader*espacement)+92),  y +15+ (dd*40));
                    if(MemoiresExistantes[DockHasMem[cmptfader][dd]] ==0)//si mem detruite plus tard affichage d un pb d affcetation
                    {
                        Dock.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                    }
                    break;
                case 6://audio Player Volume
                    sprintf( string_docktypaudiovol,"Vol.%d",(DockHasAudioVolume[cmptfader][dd]));
                    petitchiffre.Print(string_docktypaudiovol,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 7://audio Player Pan
                    sprintf( string_docktypaudiopan,"Pan.%d",(DockHasAudioPan[cmptfader][dd]));
                    petitchiffre.Print(string_docktypaudiopan,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 8:
                    sprintf( string_docktypaudiopicth,"Pitch.%d",(DockHasAudioPitch[cmptfader][dd]));
                    petitchiffre.Print(string_docktypaudiopicth,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 9://no content
                    petitchiffre.Print("-",x+((cmptfader*espacement)+92),  y +15+ (dd*40));
                    break;
                case 10://direct chan
                    sprintf( string_docktypdchan,"DC.%d",(FaderDirectChan[cmptfader][dd]));
                    petitchiffre.Print(string_docktypdchan,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 11://fx
                    sprintf( string_docktypfx,"FX.%d",(ChaserAffectedToDck[cmptfader][dd]+1));
                    petitchiffre.Print(string_docktypfx,x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 12://grid
                    sprintf( string_docktypfx,"Grid P.%d",(faders_dock_grid_affectation[cmptfader][dd]+1));
                    petitchiffre.Print(string_docktypfx,x+((cmptfader*espacement)+75),  y +15+ (dd*40));
                    break;
                case 13://fgroup
                    petitchiffrerouge.Print("Fgroup",x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 14://mover
                    petitchiffre.Print("Mover",x+((cmptfader*espacement)+77),  y +15+ (dd*40));
                    break;
                case 15://draw
                    sprintf( string_docktypfx,"Draw %d",(DrawAffectedToDck[cmptfader][dd]+1));
                    petitchiffre.Print(string_docktypfx,x+((cmptfader*espacement)+75),  y +15+ (dd*40));
                    break;
                case 16://echo
                    sprintf( string_docktypfx,"Echo %d",(echo_affected_to_dock[cmptfader][dd]+1));
                    petitchiffre.Print(string_docktypfx,x+((cmptfader*espacement)+75),  y +15+ (dd*40));
                    break;
                case 17://WaVE
                    petitchiffre.Print("WAVE",x+((cmptfader*espacement)+75),  y +15+ (dd*40));
                    break;
                default:
                    break;
                }

                Dock.DrawOutline(CouleurLigne);
                if(window_focus_id==W_FADERS && Midi_Faders_Affectation_Type!=0 && mouse_x>=(x+(cmptfader*espacement)+70) && mouse_x<=(x+(cmptfader*espacement)+120)
                        && mouse_y>=(y + (dd*40)) && mouse_y<=(y + (dd*40)+20) && (dd==0 || dd==1))
                {
                    Dock.DrawOutline(CouleurBlind);
                }


            }


            if(StopPosOn[cmptfader]==1)
            {
                int niv=0;
                switch(dmx_view)
                {
                case 0:
                    niv= (int) (((float)LevelStopPos[cmptfader])/2.55);
                    break;
                case 1:
                    niv=LevelStopPos[cmptfader];
                    break;
                default:
                    break;
                }
                switch(ActionnateStopOn[cmptfader])
                {
                case 0:
                    Line(Vec2D(x+(cmptfader*espacement),(y+255) - LevelStopPos[cmptfader]),Vec2D(x+(cmptfader*espacement)+40,(y+255) - LevelStopPos[cmptfader])).Draw(CouleurLigne);
                    petitpetitchiffre.Print(ol::ToString(niv),x+(cmptfader*espacement)+20,(y+255) - LevelStopPos[cmptfader]);
                    break;
                case 1:
                    Line(Vec2D(x+(cmptfader*espacement),(y+255) - LevelStopPos[cmptfader]),Vec2D(x+(cmptfader*espacement)+40,(y+255) - LevelStopPos[cmptfader])).Draw(CouleurBlind);
                    petitpetitchiffrerouge.Print(ol::ToString(niv),x+(cmptfader*espacement)+20,(y+255) - LevelStopPos[cmptfader]);
                    break;
                default:
                    break;
                }
            }
            neuro.Print(string_niveau,x+(cmptfader*espacement), y-25);  //niveau du fader

            doom.Print(string_channel,x+(cmptfader*espacement)+70, y-40);

            Rect LockButton( Vec2D( x+(cmptfader*espacement),y+280), Vec2D ( 40,25));//box du lock button
            LockButton.SetRoundness(6);
            LockButton.SetLineWidth(epaisseur_ligne_fader);

            LockButton.Draw(CouleurLock.WithAlpha(FaderLocked[cmptfader]));






            Circle BMidiOut( x+((cmptfader*espacement)+70),y+250, 10);//box du fader
            BMidiOut.SetLineWidth(epaisseur_ligne_fader);
            BMidiOut.Draw(CouleurBlind.WithAlpha(midi_send_out[cmptfader]));
            BMidiOut.DrawOutline(CouleurLigne);
            raccrochage_midi_visuel_vertical_dmx ( x+(cmptfader*espacement), y, cmptfader,40,255);




            Line (Vec2D( x+(cmptfader*espacement)+40,y+240),Vec2D( x+(cmptfader*espacement)+55,y+240)).Draw(CouleurLigne);
            Line (Vec2D( x+(cmptfader*espacement)+55,y+240),Vec2D( x+(cmptfader*espacement)+65,y+245)).Draw(CouleurLigne);
            petitchiffre.Print("Lock",x+8+(cmptfader*espacement), y+295);
            LockButton.DrawOutline(CouleurLigne);




            lfo_fader_functions(cmptfader, x-8, y,espacement);

            petitpetitchiffre.Print( string_time_is_in_the_dock[cmptfader],x+(cmptfader*espacement)-20,y+365);


            Rect CurveOn (Vec2D(x+(cmptfader*espacement)-10,y+410),Vec2D(20,20));

            CurveOn.SetRoundness(4);
            CurveOn.SetLineWidth(demi_epaisseur_ligne_fader);
            CurveOn.DrawOutline(CouleurLigne);
            petitpetitchiffre.Print( "C.",x+(cmptfader*espacement)-10,y+420);
            petitpetitchiffre.Print( ol::ToString(FaderCurves[cmptfader]+1),x+(cmptfader*espacement),y+425);

            if(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==11 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==12
                    || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==6 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==7 || DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==8  )
            {
                switch(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]])
                {
                case 6://VOLUME
                    play_button_view(x+(cmptfader*espacement)+20,y+410,
                                     player_is_playing[ DockHasAudioVolume[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+70 && mouse_y>y+410 && mouse_y<y+430 && mouse_button==1 && mouse_released==0)
                    {
                        seek_button_view(x+(cmptfader*espacement)+45,y+410,1);//seek , affichage avant le bouton
                        mouse_released=1;
                    }
                    seek_button_view(x+(cmptfader*espacement)+45,y+410,0);
                    loop_button_view(x+(cmptfader*espacement)+70,y+410,player_is_onloop[ DockHasAudioVolume[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    autolaunch_button_view(x+(cmptfader*espacement)+95,y+410,autolaunch[cmptfader]);
                    break;
                case 7://PAN
                    play_button_view(x+(cmptfader*espacement)+20,y+410,
                                     player_is_playing[ DockHasAudioPan[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+70 && mouse_y>y+410 && mouse_y<y+430 && mouse_button==1 && mouse_released==0)
                    {
                        seek_button_view(x+(cmptfader*espacement)+45,y+410,1);//seek , affichage avant le bouton
                        mouse_released=1;
                    }
                    seek_button_view(x+(cmptfader*espacement)+45,y+410,0);
                    loop_button_view(x+(cmptfader*espacement)+70,y+410,player_is_onloop[ DockHasAudioPan[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    autolaunch_button_view(x+(cmptfader*espacement)+95,y+410,autolaunch[cmptfader]);
                    break;
                case 8://PITCH
                    play_button_view(x+(cmptfader*espacement)+20,y+410,
                                     player_is_playing[ DockHasAudioPitch[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+70 && mouse_y>y+410 && mouse_y<y+410+20 && mouse_button==1 && mouse_released==0)
                    {
                        seek_button_view(x+(cmptfader*espacement)+45,y+410,1);//seek , affichage avant le bouton
                        mouse_released=1;
                    }
                    seek_button_view(x+(cmptfader*espacement)+45,y+410,0);
                    loop_button_view(x+(cmptfader*espacement)+70,y+410,player_is_onloop[ DockHasAudioPitch[cmptfader][dock_used_by_fader_is[cmptfader]]-1] );
                    autolaunch_button_view(x+(cmptfader*espacement)+95,y+410,autolaunch[cmptfader]);
                    break;
                case 11://CHASERS
                    play_button_view(x+(cmptfader*espacement)+20,y+410,
                                     chaser_is_playing[ChaserAffectedToDck[cmptfader][dock_used_by_fader_is[cmptfader]]]);
                    if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+70 && mouse_y>y+410 && mouse_y<y+430 && mouse_button==1 && mouse_released==0)
                    {
                        seek_button_view(x+(cmptfader*espacement)+45,y+410,1);//seek , affichage avant le bouton
                        mouse_released=1;
                    }
                    seek_button_view(x+(cmptfader*espacement)+45,y+410,0);
                    loop_button_view(x+(cmptfader*espacement)+70,y+410,chaser_is_in_loop[ChaserAffectedToDck[cmptfader][dock_used_by_fader_is[cmptfader]]]);
                    autolaunch_button_view(x+(cmptfader*espacement)+95,y+410,autolaunch[cmptfader]);
                    break;
                case 12://GRIDPLAYER
                    play_button_view(x+(cmptfader*espacement)+20,y+410,
                                     grider_is_playing[faders_dock_grid_affectation[cmptfader][dock_used_by_fader_is[cmptfader]]]);
                    if(mouse_x>x+(cmptfader*espacement)+45 && mouse_x<x+(cmptfader*espacement)+70 && mouse_y>y+410 && mouse_y<y+410+20 && mouse_button==1 && mouse_released==0)
                    {
                        seek_button_view(x+(cmptfader*espacement)+45,y+410,1);//seek , affichage avant le bouton
                        mouse_released=1;
                    }
                    seek_button_view(x+(cmptfader*espacement)+45,y+410,0);
                    playstop_button_view(x+(cmptfader*espacement)+70,y+410,grider_autostopmode[faders_dock_grid_affectation[cmptfader][dock_used_by_fader_is[cmptfader]]]);
                    autolaunch_button_view(x+(cmptfader*espacement)+95,y+410,autolaunch[cmptfader]);
                    break;
                default:
                    break;
                }
            }//fin si chaser embeded


            if(window_focus_id==W_FADERS && Midi_Faders_Affectation_Type!=0 )
            {
                if(mouse_x>x+(cmptfader*espacement)+75 && mouse_x<x+(cmptfader*espacement)+115 && mouse_y> y-30 && mouse_y<y-20 )
                {
                    char temp_str_tr[72];
                    sprintf(temp_str_tr,"Fx mode on fader %d",cmptfader+1);
                    show_type_midi(1543+cmptfader,temp_str_tr );
                    Mode_buffer_data.DrawOutline(CouleurBlind);
                }
                else if( mouse_x>x+(cmptfader*espacement)+135 && mouse_x<x+(cmptfader*espacement)+150 &&
                         mouse_y>y-35 && mouse_y<y-20 )
                {
                    Midireceive.DrawOutline(CouleurBlind);
                }
                else if( mouse_x>x+(cmptfader*espacement) && mouse_x<x+(cmptfader*espacement)+40
                         && mouse_y>y+2 && mouse_y<y+257)
                {
                    FaderB.DrawOutline(CouleurBlind);
                }
                else if( mouse_y>(y+280) && mouse_y<(y+300) && mouse_x>x+(cmptfader*espacement) && mouse_x<(x+40+(cmptfader*espacement)))
                {
                    LockButton.DrawOutline(CouleurBlind);
                }

            }

            fader_damper_commands(x+(cmptfader*espacement)-10,y+440, cmptfader );
        }
    }




    MoveFaderSpace(y-70);// fonction pour se deplacer sur les 48 masters

    Canvas::DisableClipping();
    return(0);
}
