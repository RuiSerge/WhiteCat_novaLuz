int Box_IP_routing ( int macx, int macy)
{

    Rect Rescan(Vec2D(macx+130,macy-67),Vec2D(60,20));
    Rescan.SetRoundness(4);
    Rescan.Draw(CouleurFond.WithAlpha(0.4));
    Rescan.DrawOutline(CouleurLigne.WithAlpha(0.5));
    petitchiffre.Print("Rescan",macx+135,macy-55);

    if(window_focus_id==W_CFGMENU && mouse_x>macx+130 && mouse_x<macx+130+60 && mouse_y>macy-67 && mouse_y<macy-47)
    {
     Rescan.DrawOutline(CouleurLigne);
     if(mouse_button==1 && mouse_released==0)
     {
     //adresse locale et nom de machine
     gethostname(hostnamebuffer, sizeof(hostnamebuffer));
     phe = gethostbyname(hostnamebuffer);

     int Ipsearch = 0;
     while((phe->h_addr_list[Ipsearch+1])!=NULL)
     {
      Ipsearch++;
     }
     detection_reseaux();
     mouse_released=1;
     }
    }

    Rect IPAdapt(Vec2D(macx-10,macy-40),Vec2D(200,200));
    IPAdapt.SetRoundness(7.5);
    IPAdapt.Draw(CouleurFond.WithAlpha(0.2));


   petitchiffre.Print("IP ROUTING",macx,macy-30);
    petitchiffre.Print("Art-Net",macx+100,macy-30);
    petitchiffre.Print("in",macx+100,macy-15);
    petitchiffre.Print("out",macx+125,macy-15);

    petitchiffre.Print("iCat",macx+155,macy-25);

   Rect ArtnetBIn(Vec2D(macx+200,macy-25),Vec2D(10,10));
   Rect ArtnetBOut(Vec2D(macx+200,macy-25),Vec2D(10,10));
   Rect FS(Vec2D(macx+200,macy-25),Vec2D(10,10));

    for (int u=0;u<8;u++)
    {
    Rect NetworkSelect(Vec2D(macx,macy-15+(u*20)),Vec2D(90,20));
    NetworkSelect.SetRoundness(7.5);

    ArtnetBIn.MoveTo(Vec2D(macx+100,macy+(u*20)-10));
    ArtnetBIn.DrawOutline(CouleurLigne.WithAlpha(0.3));


    ArtnetBOut.MoveTo(Vec2D(macx+130,macy+(u*20)-10));
    ArtnetBOut.DrawOutline(CouleurLigne.WithAlpha(0.3));

    FS.MoveTo(Vec2D(macx+165,macy+(u*20)-10));
    FS.DrawOutline(CouleurLigne.WithAlpha(0.3));

     if(strcmp(IP_artnet_IN,IP_detected_dmxOUT[u])==0)
    {
     ArtnetBIn.Draw(CouleurFader);
    }

    if(strcmp(IP_artnet_OUT,IP_detected_dmxOUT[u])==0)
    {
     ArtnetBOut.Draw(CouleurGreen);
    }

    if(strcmp(IP_fantastick,IP_detected_dmxOUT[u])==0)
    {
     FS.Draw(CouleurBlind);
    }
    if(mouse_y>  macy-10+(u*20)&& mouse_y<macy+(u*20)  && window_focus_id==W_CFGMENU)
    {

    if(mouse_x>macx+100 && mouse_x<macx+110 )
    {
    if(mouse_button==1 && mouse_released==0 && strcmp(IP_detected_dmxOUT[u],"-")==1)
    {
    sprintf(IP_artnet_IN,IP_detected_dmxOUT[u]);
    index_re_init_serveur_artnet=1;
    mouse_released=1;
    }
    }


    else if(mouse_x>macx+130 && mouse_x<macx+140 )
    {
    if(mouse_button==1 && mouse_released==0 && strcmp(IP_detected_dmxOUT[u],"-")==1)
    {
    sprintf(IP_artnet_OUT,IP_detected_dmxOUT[u]);
    index_re_init_client_artnet=1;
    index_ask_confirm=1;
    mouse_released=1;
    }
    }

    else if(mouse_x>macx+165 && mouse_x<macx+175 )
    {
    if(mouse_button==1 && mouse_released==0 && strcmp(IP_detected_dmxOUT[u],"-")==1)
    {
    sprintf(IP_fantastick,IP_detected_dmxOUT[u]);
    index_ask_reinit_FS_client=1;
    index_ask_confirm=1;
    mouse_released=1;
    }
    }

    }




   petitchiffre.Print(IP_detected_dmxOUT[u],macx,macy+(20*u));
   }

return(0);
}
