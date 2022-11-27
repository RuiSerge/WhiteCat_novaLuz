int do_dmx_config(int cfgdmx_X, int cfgdmx_Y, int largeurCFGdmxwindow,int hauteurCFGdmxwindow)
{

    Rect DeviceArtNetDevice( Vec2D((cfgdmx_X+10),(cfgdmx_Y+50)),Vec2D(180,30));
    DeviceArtNetDevice.SetRoundness(15);

    Rect DeviceEnttecOpen( Vec2D((cfgdmx_X+10),(cfgdmx_Y+80)),Vec2D(180,30));
    DeviceEnttecOpen.SetRoundness(15);

    Rect DeviceEnttecPro( Vec2D((cfgdmx_X+10),(cfgdmx_Y+110)),Vec2D(180,30));
    DeviceEnttecPro.SetRoundness(15);


    Rect DeviceSunlite ( Vec2D((cfgdmx_X+10),(cfgdmx_Y+170)),Vec2D(180,30));
    DeviceSunlite.SetRoundness(15);


    Rect ArtNetSendUniverse( Vec2D((cfgdmx_X+220),(cfgdmx_Y+50)),Vec2D(70,30));
    ArtNetSendUniverse.SetRoundness(15);

    Rect ArtNetSendAdress( Vec2D((cfgdmx_X+320),(cfgdmx_Y+50)),Vec2D(170,30));
    ArtNetSendAdress.SetRoundness(15);

    Rect ArtNetBroadcastMode( Vec2D((cfgdmx_X+520),(cfgdmx_Y+50)),Vec2D(130,30));
    ArtNetBroadcastMode.SetRoundness(15);

    Rect ArtNetPollforDevices( Vec2D((cfgdmx_X+670),(cfgdmx_Y+50)),Vec2D(100,30));
    ArtNetPollforDevices.SetRoundness(15);

    Rect EnttecProIN( Vec2D((cfgdmx_X+240),(cfgdmx_Y+110)),Vec2D(170,30));
    EnttecProIN.SetRoundness(15);



    Rect SunliteAllowsIN( Vec2D((cfgdmx_X+240),(cfgdmx_Y+170)),Vec2D(150,30));
    SunliteAllowsIN.SetRoundness(15);



    if(window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+20 && mouse_x<cfgdmx_X+200 )
    {
        if( mouse_y>(cfgdmx_Y+60) && mouse_y< (cfgdmx_Y+80)) //artnet
        {
            DeviceArtNetDevice.Draw(CouleurFond.WithAlpha(0.5));
            if(mouse_button==1 && mouse_released==0 )
            {
                SelectDmxDevice(1);
                mouse_released=1;
            }
        }
        else if( mouse_y>(cfgdmx_Y+90) && mouse_y< (cfgdmx_Y+110)) //enttec open
        {
            DeviceEnttecOpen.Draw(CouleurFond.WithAlpha(0.5));
            if(mouse_button==1 && mouse_released==0  )
            {
                SelectDmxDevice(2);
                mouse_released=1;
            }
        }
        else if( mouse_y>(cfgdmx_Y+120) && mouse_y< (cfgdmx_Y+140)) //enttec pro
        {
            DeviceEnttecPro.Draw(CouleurFond.WithAlpha(0.5));
            if(mouse_button==1 && mouse_released==0 )
            {
                SelectDmxDevice(3);
                mouse_released=1;
            }
        }

        else if( mouse_y>(cfgdmx_Y+170) && mouse_y< (cfgdmx_Y+200)) //sunlite
        {
            DeviceSunlite.Draw(CouleurFond.WithAlpha(0.5));
            if(mouse_button==1 && mouse_released==0  )
            {
                SelectDmxDevice(4);
                mouse_released=1;
            }
        }
    }

    if(window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+230 && mouse_x<cfgdmx_X+300 )
    {
        if( mouse_y>(cfgdmx_Y+60) && mouse_y< (cfgdmx_Y+80) && do_DMX_out[1]==1) //artnet
        {
            ArtNetSendUniverse.DrawOutline(CouleurLigne.WithAlpha(0.5));
            if(mouse_button==1 &&  mouse_released==0 )
            {
                Univers=atoi(numeric);
                if(Univers>15)
                {
                    Univers=15;
                }
                reset_numeric_entry();
                numeric_postext=0;

                mouse_released=1;
            }
        }

    }

    if(window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+320 && mouse_x<cfgdmx_X+490 )
    {
        if( mouse_y>(cfgdmx_Y+60) && mouse_y< (cfgdmx_Y+80)  && do_DMX_out[1]==1) //artnet
        {
            ArtNetSendAdress.DrawOutline(CouleurLigne.WithAlpha(0.7));
            if(mouse_button==1 &&  mouse_released==0  && numeric_postext>0)
            {
                Close_A_specific_dmx_interface(1);
                sprintf(ip_artnet,numeric);
                reset_numeric_entry();
                Init_A_specific_dmx_interface(1);
                mouse_released=1;
            }
        }

    }


    if(window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+520 && mouse_x<cfgdmx_X+620 )
    {
        if( mouse_y>(cfgdmx_Y+60) && mouse_y< (cfgdmx_Y+80) && do_DMX_out[1]==1) //artnet BROADCAST MODE   ON OFF
        {
            ArtNetBroadcastMode.DrawOutline(CouleurLigne.WithAlpha(0.7));

            if(mouse_button==1 &&  mouse_released==0 )
            {
                ArtNetBroadcastMode.DrawOutline(CouleurLigne.WithAlpha(0.7));
                Close_A_specific_dmx_interface(1);
                if(index_broadcast==0)
                {
                    index_broadcast=1;
                    Init_A_specific_dmx_interface(1);
                }
                else if(index_broadcast==1)
                {
                    index_broadcast=0;
                    //Init_dmx_interface();
                    Init_A_specific_dmx_interface(1);
                }
                mouse_released=1;
            }
        }
    }

    if(window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+670 && mouse_x<cfgdmx_X+770 )
    {
        if( mouse_y>(cfgdmx_Y+60) && mouse_y< (cfgdmx_Y+80) ) //artpoll for devices
        {
            ArtNetPollforDevices.DrawOutline(CouleurLigne.WithAlpha(0.7));

            if(mouse_button==1 &&  mouse_released==0 )
            {
                if (do_DMX_out[1]==0)//dans le cas d un art poll avec interface usb
                {
                    initialisation_client_artnet();
                    ConstructArtPoll();
                }

                if(index_art_polling==0)
                {
                    reset_poll_list();
                    ticks_poll=0;
                    index_art_polling=1;
                    index_show_artpoll_reply_content=1;
                    nbrbytessended=sendto(sockartnet, ArtPollBuffer,sizeof( ArtPollBuffer),0,(SOCKADDR*)&sinS,sinsize);
                }
                else if(index_art_polling==1)
                {
                    index_art_polling=0;
                    if (do_DMX_out[1]==0)//dans le cas d un art poll avec interface usb
                    {
                        fermeture_client_artnet();
                    }
                }
                mouse_released=1;
            }

        }
    }


    if (window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+270 && mouse_x<cfgdmx_X+420 && mouse_y>cfgdmx_Y+120 && mouse_y<cfgdmx_Y+140 )
    {
        EnttecProIN.Draw(CouleurFond.WithAlpha(0.5));

        if(mouse_button==1 &&  mouse_released==0 )
        {

            if (index_init_EnttecPROIN_ok==0)
            {
                Detect_EnttecProIn() ;
                Open_ProIn();
            }
            else if (index_init_EnttecPROIN_ok==1)
            {
                Close_ProIn() ;
                index_init_EnttecPROIN_ok=0;
            }

        }
        mouse_released=1;
    }

    if (window_focus_id==W_CFGMENU && mouse_x>cfgdmx_X+240 && mouse_x<cfgdmx_X+390 && mouse_y>cfgdmx_Y+180 && mouse_y<cfgdmx_Y+210 && do_DMX_out[4]==1)
    {
        SunliteAllowsIN.Draw(CouleurFond.WithAlpha(0.5));
        if(mouse_button==1 &&  mouse_released==0 &&  window_focus_id==920)
        {
            index_allow_sunlite_dmxIN=toggle(index_allow_sunlite_dmxIN);
            mouse_released=1;
        }
    }





    for(int i=0; i<NB_INTERFACES; i++)
    {
        if(do_DMX_out[i]==1)
        {
            switch(i)
            {
            default:
                break;
            case 1:
                DeviceArtNetDevice.Draw(CouleurBleu10.WithAlpha(index_init_dmx_ok[i]*0.6));
                DeviceArtNetDevice.DrawOutline(CouleurLevel);
                break;
            case 2:
                DeviceEnttecOpen.DrawOutline(CouleurLevel);
                break;
            case 3:
                DeviceEnttecPro.DrawOutline(CouleurLevel);
                break;
            case 4:
                DeviceSunlite.DrawOutline(CouleurLevel);
                petitchiffre.Print("Version:",cfgdmx_X+400, cfgdmx_Y+190);
                petitchiffre.Print(ol::ToString(sunlite_version_number),cfgdmx_X+460, cfgdmx_Y+190);
                petitchiffre.Print("Serial:",cfgdmx_X+500, cfgdmx_Y+190);
                petitchiffre.Print(ol::ToString(sunlite_serial_number),cfgdmx_X+550, cfgdmx_Y+190);
                petitchiffre.Print(string_sunlite_is,cfgdmx_X+670, cfgdmx_Y+190);
                break;
            }
        }
    }




    if(index_art_polling==1)
    {
        ArtNetPollforDevices.DrawOutline(CouleurLevel);
    }



    if (index_init_EnttecPROIN_ok==1)
    {
        EnttecProIN.DrawOutline(CouleurLevel);
    }


    switch(index_allow_sunlite_dmxIN)
    {
    case 0:
        petitchiffre.Print("DMX-IN OFF", cfgdmx_X+250, cfgdmx_Y+190);
        break;
    case 1:
        SunliteAllowsIN.Draw(CouleurSurvol);
        petitchiffre.Print("DMX-IN ON", cfgdmx_X+250, cfgdmx_Y+190);
        break;
    default:
        break;
    }



    sprintf(string_title_panel_config,"DMX CONFIGURATION PANEL");


    petitpetitchiffre.Print("Universe",(cfgdmx_X+220), (cfgdmx_Y+50));
    petitpetitchiffre.Print("To IP",(cfgdmx_X+350), (cfgdmx_Y+50));
    petitpetitchiffre.Print("Mode",(cfgdmx_X+560), (cfgdmx_Y+50));
    petitpetitchiffre.Print("Call",(cfgdmx_X+710), (cfgdmx_Y+50));
    petitchiffre.Print("ART-NET",(cfgdmx_X+20), (cfgdmx_Y+70));
    petitchiffre.Print(ol::ToString(Univers),(cfgdmx_X+240), (cfgdmx_Y+70));
    petitchiffre.Print(ip_artnet,(cfgdmx_X+340), (cfgdmx_Y+70));
    if(index_broadcast==0)
    {
        petitchiffre.Print("UNICAST",(cfgdmx_X+540), (cfgdmx_Y+70));
    }
    else if (index_broadcast==1)
    {
        petitchiffre.Print("BROADCAST",(cfgdmx_X+540), (cfgdmx_Y+70));
    }
    petitchiffre.Print("ART-POLL",(cfgdmx_X+690), (cfgdmx_Y+70));

    petitchiffre.Print("ENTTEC-OPEN-DMX",(cfgdmx_X+20), (cfgdmx_Y+100));
    petitchiffre.Print("ENTTEC-PRO OUT /VCOM",(cfgdmx_X+20), (cfgdmx_Y+130));
    petitchiffre.Print(ol::ToString(istheresomeone_in_enttecpro),(cfgdmx_X+170), (cfgdmx_Y+130));
    petitchiffre.Print("ENTTEC-PRO IN /VCOM",(cfgdmx_X+250), (cfgdmx_Y+130));
    petitchiffre.Print(ol::ToString(vcom_inposition_is),(cfgdmx_X+390), (cfgdmx_Y+130));

    petitchiffre.Print("SUNLITE SIUDI ",(cfgdmx_X+20), (cfgdmx_Y+190));

    Rect DmxFeedbackZone(Vec2D((cfgdmx_X+10), (cfgdmx_Y+265)),Vec2D(560,25));
    DmxFeedbackZone.SetRoundness(5);
    DmxFeedbackZone.Draw(CouleurFond.WithAlpha(0.5));
    petitchiffre.Print("DMX feedback: >>",(cfgdmx_X+20), (cfgdmx_Y+280));
    petitchiffrerouge.Print(string_display_dmx_params,(cfgdmx_X+130), (cfgdmx_Y+280));

    affect_dmx_in(cfgdmx_X+710,cfgdmx_Y+200);

    return(0);
}
