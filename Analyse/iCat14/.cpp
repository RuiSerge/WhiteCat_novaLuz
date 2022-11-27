int BoxiCat ( int macx, int macy)
{
   petitchiffre.Print("FANTASTICK-iCAT",macx, macy-50);
   petitpetitchiffrerouge.Print(FS_IP,macx,macy-35);
   //message raw
   petitpetitchiffre.Print("RAW data:",macx,macy-25);
   petitpetitchiffre.Print(FS_BUFFER,macx,macy-15);

   petitchiffre.Print("IP:",macx,macy);
   Rect ipFS(Vec2D(macx+20,macy-12),Vec2D(110,25));
   ipFS.SetRoundness(5);
   ipFS.Draw(CouleurFond.WithAlpha(0.5));
   petitchiffre.Print(specified_fs_ip,macx+25,macy);

   if(window_focus_id==W_CFGMENU && mouse_x>macx+20 && mouse_x<macx+130 && mouse_y>macy-12 && mouse_y<macy+13)
   {
    ipFS.DrawOutline(CouleurLigne);
    if(mouse_button==1 && mouse_released==0)
    {
    if(iCat_serveur_is_initialized==1)
    {
    fermeture_clientserveur_iCat();
    }
    for (int i=0;i<17;i++)
    {specified_fs_ip[i]= numeric[i];}
    reset_numeric_entry();
    initialisation_clientserveur_iCat();
    mouse_released=1;
    }
   }

   petitchiffre.Print("Server port:",macx,macy+30);
   Rect pservFS(Vec2D(macx+75,macy+15),Vec2D(50,25));
   pservFS.SetRoundness(5);
   pservFS.Draw(CouleurFond.WithAlpha(0.5));
   petitchiffre.Print(ol::ToString(serveurport_iCat),macx+80,macy+30);

   if(window_focus_id==W_CFGMENU && mouse_x>macx+75 && mouse_x<macx+125 && mouse_y>macy+15 && mouse_y<macy+40)
   {
    pservFS.DrawOutline(CouleurLigne);
    if(mouse_button==1 && mouse_released==0)
    {
    if(iCat_serveur_is_initialized==1)
    {
    fermeture_clientserveur_iCat();
    }
    serveurport_iCat=atoi(numeric);
    reset_numeric_entry();
    initialisation_clientserveur_iCat();
    mouse_released=1;
    }
   }

   petitchiffre.Print("Client port:",macx,macy+60);
   Rect pclFS(Vec2D(macx+75,macy+45),Vec2D(50,25));
   pclFS.SetRoundness(5);
   pclFS.Draw(CouleurFond.WithAlpha(0.5));
   petitchiffre.Print(ol::ToString(clientport_iCat),macx+80,macy+60);

   if(window_focus_id==W_CFGMENU && mouse_x>macx+75 && mouse_x<macx+125  && mouse_y>macy+45 && mouse_y<macy+70)
   {
    pclFS.DrawOutline(CouleurLigne);
    if(mouse_button==1 && mouse_released==0)
    {
    if(iCat_serveur_is_initialized==1)
    {
    fermeture_clientserveur_iCat();
    }
    clientport_iCat=atoi(numeric);
    reset_numeric_entry();
    initialisation_clientserveur_iCat();
    mouse_released=1;
    }
   }


   petitchiffre.Print("Iterations:",macx,macy+90);
   Rect itFS(Vec2D(macx+75,macy+75),Vec2D(50,25));
   itFS.SetRoundness(5);
   itFS.Draw(CouleurFond.WithAlpha(0.5));
   petitchiffre.Print(ol::ToString(nbre_d_envois_de_l_info),macx+80,macy+90);

   if(window_focus_id==W_CFGMENU && mouse_x>macx+75 && mouse_x<macx+125  && mouse_y>macy+75 && mouse_y<macy+100)
   {
    itFS.DrawOutline(CouleurLigne);
    if(mouse_button==1 && mouse_released==0)
    {
    nbre_d_envois_de_l_info=atoi(numeric);
    if(nbre_d_envois_de_l_info<1){nbre_d_envois_de_l_info=1;}
    reset_numeric_entry();
    mouse_released=1;
    }
   }

   //reset FS reload images
   petitchiffre.Print("Reload gfx:",macx,macy+120);
   Rect resFS(Vec2D(macx+75,macy+105),Vec2D(50,20));
   resFS.SetRoundness(5);
   resFS.Draw(CouleurFond.WithAlpha(0.5));

   if(window_focus_id==W_CFGMENU && mouse_x>macx+75 && mouse_x<macx+125  && mouse_y>macy+105 && mouse_y<macy+125)
   {
    resFS.Draw(CouleurBlind.WithAlpha(alpha_blinker));
    if(mouse_button==1 && mouse_released==0)
    {
    index_ask_confirm=1;
    index_ask_clear_img_icat=1;
    mouse_released=1;
    }
   }



   return(0);
}
