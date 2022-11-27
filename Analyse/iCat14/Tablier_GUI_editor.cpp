int Tablier_GUI_editor( int gx, int gy)
{
   Point_Viewing(gx+10,gy+10);
 //tablier d'�dition
   Rect InterFS(Vec2D(gx,gy),Vec2D(L_tablier_iCat,H_tablier_iCat));
   InterFS.SetRoundness(5);
   InterFS.SetLineWidth(demi_epaisseur_ligne_fader);
   InterFS.Draw(CouleurFond.WithAlpha(0.8));
   InterFS.DrawOutline(CouleurLigne);
   //affichage sliders
   if(iCat_nbre_de_sliders[iCatPageis]>0)
   {
   for(int sl=1;sl<iCat_nbre_de_sliders[iCatPageis]+1;sl++)
   {
          if(iCat_orientation_slider[iCatPageis][sl]==0)
                          {l_sl=iCatSlidersizeX; h_sl=iCatSlidersizeY;}
                          //horizontal
          else
                 { l_sl=iCatSlidersizeY;h_sl=iCatSlidersizeX;}
if(iCat_pos_slider[iCatPageis][sl][0]<L_tablier_iCat &&  iCat_pos_slider[iCatPageis][sl][1]<H_tablier_iCat)
{
            Rect Slider_Big(Vec2D(gx+iCat_pos_slider[iCatPageis][sl][0],gy+iCat_pos_slider[iCatPageis][sl][1]),
             Vec2D((l_sl*ratio_iCat_slider[iCatPageis][sl])/2,(h_sl*ratio_iCat_slider[iCatPageis][sl])/2));//la size est divisee par 2
             //par rapport vision global dasn tablier
           if(slider_is_touched[iCatPageis][sl]==1){Slider_Big.Draw(CouleurFader); }
          Slider_Big.DrawOutline(CouleurLigne);
          petitpetitchiffre.Print(ol::ToString(sl),gx+iCat_pos_slider[iCatPageis][sl][0],gy+iCat_pos_slider[iCatPageis][sl][1]);
          if(editing_GUI_type_iCat==1 && iCat_select_editing_slider==sl)
          {
          Slider_Big.SetLineWidth(4.0);
          Slider_Big.DrawOutline(CouleurSurvol);
          }
}

   }
   }

      //affichage boutons
   if(iCat_nbre_de_boutons[iCatPageis]>0)
   {
   for(int sl=1;sl<iCat_nbre_de_boutons[iCatPageis]+1;sl++)
   {
 if(iCat_pos_bouton[iCatPageis][sl][0]<L_tablier_iCat &&  iCat_pos_bouton[iCatPageis][sl][1]<H_tablier_iCat)
{

            Rect Bouton_Big(
            Vec2D( gx+iCat_pos_bouton[iCatPageis][sl][0],gy+iCat_pos_bouton[iCatPageis][sl][1]),
            Vec2D((largueur_bouton*ratio_iCat_button[iCatPageis][sl])/2,(largueur_bouton*ratio_iCat_button[iCatPageis][sl])/2));//boutons carr�s
          if(button_is_touched[iCatPageis][sl]==1){Bouton_Big.Draw(CouleurFader); }
          Bouton_Big.DrawOutline(CouleurLigne);
          petitpetitchiffre.Print(ol::ToString(sl),gx+iCat_pos_bouton[iCatPageis][sl][0],gy+iCat_pos_bouton[iCatPageis][sl][1]);
          if(editing_GUI_type_iCat==2 && iCat_select_editing_button==sl)
          {
          Bouton_Big.SetLineWidth(4.0);
          Bouton_Big.DrawOutline(CouleurSurvol);
          }
}
   }
   }
     //affichage strings
   if(iCat_nbre_de_strings[iCatPageis]>0)
   {
   for(int sl=1;sl<iCat_nbre_de_strings[iCatPageis]+1;sl++)
   {
 if(iCat_pos_string[iCatPageis][sl][0]<L_tablier_iCat &&  iCat_pos_string[iCatPageis][sl][1]<H_tablier_iCat)
{

            Rect String_Big(
            Vec2D( gx+iCat_pos_string[iCatPageis][sl][0],gy+iCat_pos_string[iCatPageis][sl][1]),
            Vec2D((largeur_string*ratio_iCat_string[iCatPageis][sl])/2,(hauteur_string*ratio_iCat_string[iCatPageis][sl])/2));//boutons carr�s

          String_Big.DrawOutline(CouleurLigne);
          petitpetitchiffre.Print(ol::ToString(sl),gx+iCat_pos_string[iCatPageis][sl][0],gy+iCat_pos_string[iCatPageis][sl][1]);
          if(editing_GUI_type_iCat==3 && iCat_select_editing_string==sl)
          {
          String_Big.SetLineWidth(4.0);
          String_Big.DrawOutline(CouleurSurvol);
          }

}
   }
   }

       //affichage  zone
   if(iCat_nbre_de_tracking_zone[iCatPageis]>0)
   {
   for(int sl=1;sl<iCat_nbre_de_tracking_zone[iCatPageis]+1;sl++)
   {
 if(iCat_pos_trackzone[iCatPageis][sl][0]<L_tablier_iCat &&  iCat_pos_trackzone[iCatPageis][sl][1]<H_tablier_iCat)
{

            Rect Trck_Big(
            Vec2D( gx+iCat_pos_trackzone[iCatPageis][sl][0],gy+iCat_pos_trackzone[iCatPageis][sl][1]),
            Vec2D((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl])/2,(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl])/2));//boutons carr�s

          Trck_Big.DrawOutline(CouleurLigne);
          petitpetitchiffre.Print(ol::ToString(sl),gx+iCat_pos_trackzone[iCatPageis][sl][0],gy+iCat_pos_trackzone[iCatPageis][sl][1]);
          if(editing_GUI_type_iCat==4 && iCat_select_tracking_zone==sl)
          {
          Trck_Big.SetLineWidth(4.0);
          Trck_Big.DrawOutline(CouleurSurvol);
          }
}
   }
   }


   if(mouse_x>gx && mouse_x<gx+L_tablier_iCat && mouse_y>gy && mouse_y<gy+H_tablier_iCat
      && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
   {
   //manipulation
   switch(editing_GUI_type_iCat)
   {
   case 1://s/liders
   if(iCat_select_editing_slider>0)
   {
   iCat_pos_slider[iCatPageis][iCat_select_editing_slider][0]=(mouse_x-gx)-((mouse_x-gx)%grid_icat_modulo);
   iCat_pos_slider[iCatPageis][iCat_select_editing_slider][1]=(mouse_y-gy)-((mouse_y-gy)%grid_icat_modulo);
   }
   break;
   case 2://buttons
   if(iCat_select_editing_button>0)
   {
   iCat_pos_bouton[iCatPageis][iCat_select_editing_button][0]=(mouse_x-gx)-((mouse_x-gx)%grid_icat_modulo);
   iCat_pos_bouton[iCatPageis][iCat_select_editing_button][1]=(mouse_y-gy)-((mouse_y-gy)%grid_icat_modulo);
   }
   break;
   case 3://strings
   if(iCat_select_editing_string>0)
   {
   iCat_pos_string[iCatPageis][iCat_select_editing_string][0]=(mouse_x-gx)-((mouse_x-gx)%grid_icat_modulo);
   iCat_pos_string[iCatPageis][iCat_select_editing_string][1]=(mouse_y-gy)-((mouse_y-gy)%grid_icat_modulo);
   }
   break;
   case 4://tracking zone
   if(iCat_select_tracking_zone>0)
   {
   iCat_pos_trackzone[iCatPageis][iCat_select_tracking_zone][0]=(mouse_x-gx)-((mouse_x-gx)%grid_icat_modulo);
   iCat_pos_trackzone[iCatPageis][iCat_select_tracking_zone][1]=(mouse_y-gy)-((mouse_y-gy)%grid_icat_modulo);
   }
   break;
   default:
   break;
   }
   }



 return(0);
}
