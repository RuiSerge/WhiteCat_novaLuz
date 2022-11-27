int draw_pdf_icat_preset(int prst)
{
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
HPDF_Page_SetFontAndSize (page, def_font,10);
HPDF_Page_SetRGBStroke (page, 0.0,0.6,0.8);//couleur ligne
sprintf(header_export,"iCAT preset %d", prst+1);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

switch(surface_type)
{
case 0://iPOD
   if(iCat_preset_orientation[prst]==0)
   {
    L_tablier_iCat=160;H_tablier_iCat=240;
   }
   else {L_tablier_iCat=240;H_tablier_iCat=160;}
break;
case 1://iPAD
   if(iCat_preset_orientation[prst]==0)
   {
    L_tablier_iCat=384;H_tablier_iCat=512;
   }
   else {
   L_tablier_iCat=512;H_tablier_iCat=384;
   }
break;
default:
break;
}

HPDF_REAL xx=40;
HPDF_REAL yy=debut_lignes -(position_ligne1+(cmptline_pdf*12))-H_tablier_iCat;


HPDF_Page_SetRGBFill (page, 1.0, 1.0, 1.0);//couleur remplissage
HPDF_Page_SetRGBStroke (page, 1.0, 0.0, 0.0);//couleur ligne
HPDF_Page_Rectangle  (page, xx,yy,L_tablier_iCat,H_tablier_iCat);
HPDF_Page_FillStroke (page);
HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne

HPDF_Page_SetFontAndSize (page, def_font,6);
HPDF_Page_SetRGBFill (page, 1.0, 1.0, 1.0);//couleur remplissage
if(iCat_nbre_de_sliders[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_sliders[prst]+1;sl++)
{
          if(iCat_orientation_slider[prst][sl]==0)
                          {l_sl=iCatSlidersizeX; h_sl=iCatSlidersizeY;}
                          //horizontal
          else
                 { l_sl=iCatSlidersizeY;h_sl=iCatSlidersizeX;}
if(iCat_pos_slider[prst][sl][0]<L_tablier_iCat &&  iCat_pos_slider[prst][sl][1]<H_tablier_iCat)
{

HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_Rectangle  (page,
                      xx+iCat_pos_slider[prst][sl][0],
                      yy+( H_tablier_iCat - (iCat_pos_slider[prst][sl][1]+ ((h_sl*ratio_iCat_slider[prst][sl])/2) )),
                      (l_sl*ratio_iCat_slider[prst][sl])/2,
                      (h_sl*ratio_iCat_slider[prst][sl])/2);//la size est divisee par 2
HPDF_Page_Stroke (page);
HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
sprintf(header_export,"Sld.%d",sl);
draw_info(page,xx+iCat_pos_slider[prst][sl][0],yy+15+( H_tablier_iCat - (iCat_pos_slider[prst][sl][1]+ ((h_sl*ratio_iCat_slider[prst][sl])/2) )),header_export);
}

}
}

if(iCat_nbre_de_boutons[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_boutons[prst]+1;sl++)
{
if(iCat_pos_bouton[prst][sl][0]<L_tablier_iCat &&  iCat_pos_bouton[prst][sl][1]<H_tablier_iCat)
{

HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_Rectangle  (page,
                      xx+iCat_pos_bouton[prst][sl][0],
                      yy+( H_tablier_iCat - (iCat_pos_bouton[prst][sl][1]+ (largueur_bouton*ratio_iCat_button[prst][sl])/2) ),
                      (largueur_bouton*ratio_iCat_button[prst][sl])/2,
                      ((largueur_bouton*ratio_iCat_button[prst][sl])/2));
HPDF_Page_Stroke (page);
HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
sprintf(header_export,"Bt.%d",sl);
draw_info(page,xx+iCat_pos_bouton[prst][sl][0],yy+15+( H_tablier_iCat - (iCat_pos_bouton[prst][sl][1]+ ((largueur_bouton*ratio_iCat_button[prst][sl])/2) )),header_export);
}

}
}


if(iCat_nbre_de_strings[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_strings[prst]+1;sl++)
{
if(iCat_pos_string[prst][sl][0]<L_tablier_iCat &&  iCat_pos_string[prst][sl][1]<H_tablier_iCat)
{

HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_Rectangle  (page,
                      xx+iCat_pos_string[prst][sl][0],
                      yy+( H_tablier_iCat - (iCat_pos_string[prst][sl][1]+ (hauteur_string*ratio_iCat_string[prst][sl])/2) ),
                      (largeur_string*ratio_iCat_string[prst][sl])/2,
                      ((hauteur_string*ratio_iCat_string[prst][sl])/2));
HPDF_Page_Stroke (page);
HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
sprintf(header_export,"Str.%d",sl);
draw_info(page,xx+iCat_pos_string[prst][sl][0],yy+15+( H_tablier_iCat - (iCat_pos_string[prst][sl][1]+ ((hauteur_string*ratio_iCat_string[prst][sl])/2) )),header_export);
}

}
}

if(iCat_nbre_de_tracking_zone[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_tracking_zone[prst]+1;sl++)
{
if(iCat_pos_trackzone[prst][sl][0]<L_tablier_iCat &&  iCat_pos_trackzone[prst][sl][1]<H_tablier_iCat)
{

HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_Rectangle  (page,
                      xx+iCat_pos_trackzone[prst][sl][0],
                      yy+( H_tablier_iCat - (iCat_pos_trackzone[prst][sl][1]+ (largeur_trackzone*ratio_iCat_trackzone[prst][sl])/2) ),
                      (largeur_trackzone*ratio_iCat_trackzone[prst][sl])/2,
                      ((largeur_trackzone*ratio_iCat_trackzone[prst][sl])/2));
HPDF_Page_Stroke (page);
HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
sprintf(header_export,"TrckZ.%d",sl);
draw_info(page,xx+iCat_pos_trackzone[prst][sl][0],yy+15+( H_tablier_iCat - (iCat_pos_trackzone[prst][sl][1]+ ((largeur_trackzone*ratio_iCat_trackzone[prst][sl])/2) )),header_export);
}

}
}





cmptline_pdf+=(( H_tablier_iCat/12)+2);
cmptline_pdf++;
if(iCat_nbre_de_sliders[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_sliders[prst]+1;sl++)
{
sprintf(header_export,"Slider %d = ",sl);
char tmpf[34];
switch(iCat_affectation_slider_type_is[prst][sl])
{
case 0://desafected
sprintf(tmpf,"-");
break;
case 1: //faders  lvl
sprintf(tmpf,"Fader Level: %d",iCat_affectation_slider_value_is[prst][sl]);
break;
case 2://faders speeed
sprintf(tmpf,"Fader Speed: %d",iCat_affectation_slider_value_is[prst][sl]);
break;
case 3://sequenciel
sprintf(tmpf,"Sequences: %d",iCat_affectation_slider_value_is[prst][sl]);
break;
case 4://grand master
sprintf(tmpf,"GrandMaster");
break;
case 5://level wheel
sprintf(tmpf,"Level Wheel");
break;
case 6://mover
sprintf(tmpf,"Mover Params %d",iCat_affectation_slider_value_is[prst][sl]);
break;
default:
sprintf(tmpf,"-");
break;
}
strcat(header_export,tmpf);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
HPDF_Page_SetFontAndSize (page, def_font,10);
verification_fin_de_page();
HPDF_Page_SetFontAndSize (page, def_font,6);
}
}



if(iCat_nbre_de_boutons[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_boutons[prst]+1;sl++)
{
sprintf(header_export,"Button %d = ",sl);
char tmpf[34];
switch(iCat_affectation_bouton_type_is[prst][sl])
{
case 0://desafected
sprintf(tmpf,"-");
break;
case 1: //faders
sprintf(tmpf,"Faders: ");
break;
case 2://mini faders
sprintf(tmpf,"MiniFaders: ");
break;
case 3://sequenciel
sprintf(tmpf,"Sequences: ");
break;
case 4://emulate
sprintf(tmpf,"Emulate Kbd: ");
break;
case 5: //Bangers
sprintf(tmpf,"Bangers:");
break;
case 6: //iCat menus
sprintf(tmpf,"iCat navigation: ");
break;
default:
break;
}
strcat(header_export,tmpf);


switch(iCat_affectation_bouton_type_is[prst][sl])
{
case 1: //faders
switch(iCat_affectation_bouton_action_is[prst][sl])
     {

      case 1: //fader up
      sprintf(tmpf,"UP %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 2://fader down
      sprintf(tmpf,"DOWN %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 3://Fader saw
      sprintf(tmpf,"SAW %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 4:
      sprintf(tmpf,"ToPREVDock %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 5:
      sprintf(tmpf,"ToNEXTDock %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 6:
      sprintf(tmpf,"Up/Down %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 7:
      sprintf(tmpf,"LOCK %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 8:
      sprintf(tmpf,"FLASH %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;

      case 9:
      sprintf(tmpf,"L/Unloop dock %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 10:
      sprintf(tmpf,"L/Unloop all %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 11:
      sprintf(tmpf,"Play embedded %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 12:
      sprintf(tmpf,"Seek embedded %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 13:
      sprintf(tmpf,"Loop embedded %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      default:
      sprintf(tmpf,"-");
      break;
      }
      //fin faders
break;
case 2://minifaders

     switch(iCat_affectation_bouton_action_is[prst][sl])
     {
     case 0://desafected
      sprintf(tmpf,"-");
      break;
      case 1: //fader up
      sprintf(tmpf,"UP");
      break;
      case 2://fader down
      sprintf(tmpf,"DOWN");
      break;
      case 3://Fader saw
      sprintf(tmpf,"SAW");
      break;
      case 4:
      sprintf(tmpf,"ToPREVDock");
      break;
      case 5:
      sprintf(tmpf,"ToNEXTDock");
      break;
      case 6:
      sprintf(tmpf,"Up/Down");
      break;
      case 7:
      sprintf(tmpf,"LOCK");
      break;
      case 8:
      sprintf(tmpf,"FLASH");
      break;
      case 9:
      sprintf(tmpf,"L/Unloop dock");
      break;
      case 10:
      sprintf(tmpf,"L/Unloop all");
      break;
      case 11:
      sprintf(tmpf,"Dock -");
      break;
      case 12:
      sprintf(tmpf,"Dock +");
      break;
      case 13:
      sprintf(tmpf,"Play embedded");
      break;
      case 14:
      sprintf(tmpf,"All at 0");
      break;
      case 15:
      sprintf(tmpf,"SetPos");
      break;
      case 16:
      sprintf(tmpf,"Select MF %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 17:
      sprintf(tmpf,"UnSelect All MF");
      break;
      case 18:
      sprintf(tmpf,"Select All MF");
      break;
      case 19:
      sprintf(tmpf,"Select MF Pst %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 20:
      sprintf(tmpf,"Select Lock %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      default:
      break;
      }//fin minifaders
break;

case 3://sequences
switch(iCat_affectation_bouton_action_is[prst][sl])
     {
     case 0://desafected
      sprintf(tmpf,"-");
      break;
      case 1:
      sprintf(tmpf,"GO");
      break;
      case 2:
      sprintf(tmpf,"GO BACK");
      break;
      case 3://Fader saw
      sprintf(tmpf,"JUMP");
      break;
      case 4:
      sprintf(tmpf,"STAGE -");
      break;
      case 5:
      sprintf(tmpf,"STAGE +");
      break;
      case 6:
      sprintf(tmpf,"PRESET -");
      break;
      case 7:
      sprintf(tmpf,"PRESET +");
      break;
      case 8:
      sprintf(tmpf,"GOTO");
      break;

default:
sprintf(tmpf,"-");
break;
}
break;
case 4://emulate
     switch(iCat_affectation_bouton_action_is[prst][sl])
     {
      case 0:
      sprintf(tmpf,"0");
      break;
      case 1:
      sprintf(tmpf,"1");
      break;
      case 2:
      sprintf(tmpf,"2");
      break;
      case 3:
      sprintf(tmpf,"3");
      break;
      case 4:
      sprintf(tmpf,"4");
      break;
      case 5:
      sprintf(tmpf,"5");
      break;
      case 6:
      sprintf(tmpf,"6");
      break;
      case 7:
      sprintf(tmpf,"7");
      break;
      case 8:
      sprintf(tmpf,"8");
      break;
      case 9:
      sprintf(tmpf,"9");
      break;
      case 10:
      sprintf(tmpf,".");
      break;
      case 11:
      sprintf(tmpf,"PLUS");
      break;
      case 12:
      sprintf(tmpf,"MINUS");
      break;
      case 13:
      sprintf(tmpf,"ALL");
      break;
      case 14:
      sprintf(tmpf,"INV");
      break;
      case 15:
      sprintf(tmpf,"TAB");
      break;
      case 16:
      sprintf(tmpf,"ESC");
      break;
      case 17:
      sprintf(tmpf,"ENT");
      break;
      case 18://FULL
      sprintf(tmpf,"/100");
      break;
      case 19://a ZERO
      sprintf(tmpf,"/0");
      break;
      case 20://backspace
      sprintf(tmpf,"BCKSP");
      break;
      case 21://DEL
      sprintf(tmpf,"DEL");
      break;
      case 22://arrow Up
      sprintf(tmpf,"UP");
      break;
      case 23://arrow down
      sprintf(tmpf,"DOWN");
      break;
      case 24://arrow left
      sprintf(tmpf,"LEFT");
      break;
      case 25://arrow right
      sprintf(tmpf,"RIGHT");
      break;
      case 26:
      sprintf(tmpf,"F1");
      break;
      case 27:
      sprintf(tmpf,"F2");
      break;
      case 28:
      sprintf(tmpf,"F3");
      break;
      case 29:
      sprintf(tmpf,"F4");
      break;
      case 30:
      sprintf(tmpf,"F11");
      break;
      case 31:
      sprintf(tmpf,"F12");
      break;
      case 32:
      sprintf(tmpf,"SHFT");
      break;
      case 33:
      sprintf(tmpf,"CTRL");
      break;
      default:
      sprintf(tmpf,"-");
      break;
     }

break;
case 5://banger
switch(iCat_affectation_bouton_action_is[prst][sl])
     {
      case 0:
      sprintf(tmpf,"-");
      break;
      case 1:
      sprintf(tmpf,"Bang Solo %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      default: break;
      }
break;
case 6://icat commandes
      switch(iCat_affectation_bouton_action_is[prst][sl])
     {
      case 0:
      sprintf(tmpf,"-");
      break;
      case 1:
      sprintf(tmpf,"Page -");
      break;
      case 2:
      sprintf(tmpf,"Page +");
      break;
      case 3:
      sprintf(tmpf,"Page Num: %d",iCat_affectation_bouton_value_is[prst][sl]);
      break;
      case 4:
      sprintf(tmpf,"Refresh Page");
      break;
      case 5:
      sprintf(tmpf,"Page Orientation");
      break;
      default:
      sprintf(tmpf,"-");
      break;
      }
break;
default:
sprintf(tmpf,"-");
break;
}

strcat(header_export,tmpf);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
HPDF_Page_SetFontAndSize (page, def_font,10);
verification_fin_de_page();
HPDF_Page_SetFontAndSize (page, def_font,6);
}
}

cmptline_pdf++;
if(iCat_nbre_de_strings[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_strings[prst]+1;sl++)
{
sprintf(header_export,"String %d = ",sl);
char tmpf[34];

switch(iCat_affectation_string_type_is[prst][sl])
{
case 0://desafected
sprintf(tmpf,"-");
break;
case 1: //Feedback
sprintf(tmpf,"Feedback:");
break;
case 2: //sequenciel
sprintf(tmpf,"Sequences:");
break;
default:
  sprintf(tmpf,"-");
break;
}
strcat(header_export,tmpf);

switch(iCat_affectation_string_type_is[prst][sl])
{
case 0://desafected
sprintf(tmpf,"-");
break;
case 1: //Feedback

     switch(iCat_affectation_string_action_is[prst][sl])
     {
     case 0://desafected
      sprintf(tmpf,"-");
      break;
      case 1: //input
      sprintf(tmpf,"Input");
      break;
      case 2://last ch
      sprintf(tmpf,"Last CH.");
      break;
      case 3://dimmers
      sprintf(tmpf,"DIM.");
      break;
      case 4://last order
      sprintf(tmpf,"Last Order");
      break;
      case 5:
      sprintf(tmpf,"Confirm");
      break;
      default:
      sprintf(tmpf,"-");
      break;
      }

break;

case 2://sequences
    switch(iCat_affectation_string_action_is[prst][sl])
     {
     case 0://desafected
      sprintf(tmpf,"-");
      break;
      case 1: //X1
      sprintf(tmpf,"Stage");
      break;
      case 2://X2
      sprintf(tmpf,"Preset");
      break;
      case 3://Before 1
      sprintf(tmpf,"Mem. Before 1");
      break;
      case 4://Mem +
      sprintf(tmpf,"Mem. After 1");
      break;
      default:
      sprintf(tmpf,"-");
      break;
      }
break; //fin  stringsequences
default:
      sprintf(tmpf,"-");
break;
}

strcat(header_export,tmpf);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
HPDF_Page_SetFontAndSize (page, def_font,10);
verification_fin_de_page();
HPDF_Page_SetFontAndSize (page, def_font,6);
}
}
cmptline_pdf++;
if(iCat_nbre_de_tracking_zone[prst]>0)
{
for(int sl=1;sl<iCat_nbre_de_tracking_zone[prst]+1;sl++)
{
sprintf(header_export,"TrackingZone %d = ",sl);
char tmpf[34];

switch(iCat_trackzone_type_is[prst][sl] )//mover
{
case 0://desafected
sprintf(tmpf,"-");
break;
case 1://mover
sprintf(tmpf,"Mover %d",iCat_trackzone_affectation_is[prst][sl]);
break;
default:
sprintf(tmpf,"-");
break;
}
strcat(header_export,tmpf);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
HPDF_Page_SetFontAndSize (page, def_font,10);
verification_fin_de_page();
HPDF_Page_SetFontAndSize (page, def_font,6);
}
}
saut_de_page();




return(0);
}
