int Menu_edition_iCat_boutons(int xed, int yed)
{
char title_iCat_menu[16];

Rect Button_M(Vec2D(xed-15,yed-10),Vec2D(105,20));
Button_M.SetRoundness(4);
Button_M.Draw(CouleurFond.WithAlpha(0.4));
if(editing_GUI_type_iCat==2)
{Button_M.Draw(CouleurSurvol);}
petitchiffre.Print("Buttons",xed+10,yed+2);
if(mouse_x>xed-15 && mouse_x<xed+90 && mouse_y>yed-10 && mouse_y<yed+10
   && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
{
if(index_main_clear==1)//clear des sliders selectivement
{
index_ask_iCat_selectiv_clear=1;
index_ask_confirm=1;
}
else
{
if(editing_GUI_type_iCat==2) {editing_GUI_type_iCat=0;}
else editing_GUI_type_iCat=2;
}
mouse_released=1;
}


previous_button_view(xed-15,yed+15,0);
next_button_view(xed+50,yed+15,0);
Rect button_F(Vec2D(xed+10,yed+15),Vec2D(35,20));
button_F.SetRoundness(4);
button_F.Draw(CouleurFond.WithAlpha(0.4));
sprintf(title_iCat_menu,"%d /%d",iCat_select_editing_button, iCat_nbre_de_boutons[iCatPageis]);
petitpetitchiffre.Print(title_iCat_menu,xed+12,yed+27);

if(mouse_y>yed+15 && mouse_y< yed+35)
{
if(mouse_x>xed-15 && mouse_x<xed+5 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
{
editing_GUI_type_iCat=2;
previous_button_view(xed-15,yed+15,1);
if(iCat_select_editing_button>0){iCat_select_editing_button--;}
else{iCat_select_editing_button=iCat_nbre_de_boutons[iCatPageis];}
mouse_released=1;
}
if(mouse_x>xed+50 && mouse_x<xed+70 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
{
editing_GUI_type_iCat=2;
next_button_view(xed+50,yed+15,1);
if(iCat_select_editing_button<iCat_nbre_de_boutons[iCatPageis]){iCat_select_editing_button++;}
else{iCat_select_editing_button=iCat_nbre_de_boutons[iCatPageis];}
mouse_released=1;
}
}

case_moins_view(xed+75,yed+15,0);
case_plus_view(xed+75,yed+35,0);

if(mouse_x>xed+75 && mouse_x<xed+90)
{
if(mouse_y>yed+15 && mouse_y<yed+30 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
{
editing_GUI_type_iCat=2;
case_moins_view(xed+75,yed+15,1);
if(iCat_nbre_de_boutons[iCatPageis]>0){iCat_nbre_de_boutons[iCatPageis]--;
if(iCat_select_editing_button>iCat_nbre_de_boutons[iCatPageis]){iCat_select_editing_button=iCat_nbre_de_boutons[iCatPageis];}
}
mouse_released=1;
}
if(mouse_y>yed+35 && mouse_y<yed+50 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT )
{
editing_GUI_type_iCat=2;
case_plus_view(xed+75,yed+35,1);
if(iCat_nbre_de_boutons[iCatPageis]<max_buttons_icat){iCat_nbre_de_boutons[iCatPageis]++;}
iCat_select_editing_button=iCat_nbre_de_boutons[iCatPageis];
mouse_released=1;
}
}


char str_type_iCat[16];
sprintf(str_type_iCat,"X: %d Y: %d",iCat_pos_bouton[iCatPageis][iCat_select_editing_button][0],iCat_pos_bouton[iCatPageis][iCat_select_editing_button][1]);
petitpetitchiffre.Print(str_type_iCat,xed-10,yed+47);


switch(ratio_iCat_button[iCatPageis][iCat_select_editing_button])
{
case 1:
sprintf(str_type_iCat,"small");
break;
case 2:
sprintf(str_type_iCat,"med.");
break;
case 3:
sprintf(str_type_iCat,"big");
break;
default:
sprintf(str_type_iCat,"-");
break;
}
pulse_bar_view(xed-12,yed+55, str_type_iCat);
if(mouse_x>xed-12 && mouse_x<xed+18 && mouse_y>yed+55 && mouse_y<yed+75 &&
   mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && iCat_select_editing_button!=0)
{
editing_GUI_type_iCat=2;
ratio_iCat_button[iCatPageis][iCat_select_editing_button]++;
if(ratio_iCat_button[iCatPageis][iCat_select_editing_button]>3){ratio_iCat_button[iCatPageis][iCat_select_editing_button]=1;}
mouse_released=1;
}



char string_temp_familly[25];
petitpetitchiffre.Print("Type:",xed-15,yed+90);
Rect AffectTyp(Vec2D(xed-15,yed+95),Vec2D(100,20));
AffectTyp.SetRoundness(4);
AffectTyp.Draw(CouleurFond.WithAlpha(0.4));
switch(iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button])
{
case 0://desafected
sprintf(string_temp_familly,"-");
break;
case 1: //faders
sprintf(string_temp_familly,"Faders:");
break;
case 2://mini faders
sprintf(string_temp_familly,"MiniFaders:");
break;
case 3://sequenciel
sprintf(string_temp_familly,"Sequences:");
break;
case 4://emulate
sprintf(string_temp_familly,"Emulate Kbd:");
break;
case 5: //Bangers
sprintf(string_temp_familly,"Bangers");
break;
case 6: //iCat menus
sprintf(string_temp_familly,"iCat navigation:");
break;
case 7: //draw
sprintf(string_temp_familly,"Draw:");
break;
default:
break;
}
petitpetitchiffre.Print(string_temp_familly,xed-7,yed+107);

if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+95 && mouse_y<yed+115 &&
   mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && iCat_select_editing_button!=0)
{
editing_GUI_type_iCat=2;
iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button]++;
if(iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button]>7){iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button]=0;}
iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button]=0;
iCat_affectation_bouton_value_is[iCatPageis][iCat_select_editing_button]=0;
mouse_released=1;
}




petitpetitchiffre.Print("Action:",xed-15,yed+122);
Rect AffectAct(Vec2D(xed-15,yed+125),Vec2D(100,20));
AffectAct.SetRoundness(4);
AffectAct.Draw(CouleurFond.WithAlpha(0.4));
switch(iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button])
{
case 1: //faders
switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {

      case 1: //fader up
      sprintf(string_temp_familly,"UP");
      break;
      case 2://fader down
      sprintf(string_temp_familly,"DOWN");
      break;
      case 3://Fader saw
      sprintf(string_temp_familly,"SAW");
      break;
      case 4:
      sprintf(string_temp_familly,"ToPREVDock");
      break;
      case 5:
      sprintf(string_temp_familly,"ToNEXTDock");
      break;
      case 6:
      sprintf(string_temp_familly,"Up/Down");
      break;
      case 7:
      sprintf(string_temp_familly,"LOCK");
      break;
      case 8:
      sprintf(string_temp_familly,"FLASH");
      break;

      case 9:
      sprintf(string_temp_familly,"L/Unloop dock");
      break;
      case 10:
      sprintf(string_temp_familly,"L/Unloop all");
      break;
      case 11:
      sprintf(string_temp_familly,"Play embedded");
      break;
      case 12:
      sprintf(string_temp_familly,"Seek embedded");
      break;
      case 13:
      sprintf(string_temp_familly,"Loop embedded");
      break;
      default:
      sprintf(string_temp_familly,"-");
      break;
      }
      //fin faders
break;
case 2://minifaders

     switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
     case 0://desafected
      sprintf(string_temp_familly,"-");
      break;
      case 1: //fader up
      sprintf(string_temp_familly,"UP");
      break;
      case 2://fader down
      sprintf(string_temp_familly,"DOWN");
      break;
      case 3://Fader saw
      sprintf(string_temp_familly,"SAW");
      break;
      case 4:
      sprintf(string_temp_familly,"ToPREVDock");
      break;
      case 5:
      sprintf(string_temp_familly,"ToNEXTDock");
      break;
      case 6:
      sprintf(string_temp_familly,"Up/Down");
      break;
      case 7:
      sprintf(string_temp_familly,"LOCK");
      break;
      case 8:
      sprintf(string_temp_familly,"FLASH");
      break;
      case 9:
      sprintf(string_temp_familly,"L/Unloop dock");
      break;
      case 10:
      sprintf(string_temp_familly,"L/Unloop all");
      break;
      case 11:
      sprintf(string_temp_familly,"Dock -");
      break;
      case 12:
      sprintf(string_temp_familly,"Dock +");
      break;
      case 13:
      sprintf(string_temp_familly,"Play embedded");
      break;
      case 14:
      sprintf(string_temp_familly,"All at 0");
      break;
      case 15:
      sprintf(string_temp_familly,"SetPos");
      break;
      case 16:
      sprintf(string_temp_familly,"Select MF");
      break;
      case 17:
      sprintf(string_temp_familly,"UnSelect All MF");
      break;
      case 18:
      sprintf(string_temp_familly,"Select All MF");
      break;
      case 19:
      sprintf(string_temp_familly,"Select MF Pst");
      break;
      case 20:
      sprintf(string_temp_familly,"Select Lock Pst");
      break;
      default:
      break;
      }//fin minifaders
break;

case 3://sequences
switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
     case 0://desafected
      sprintf(string_temp_familly,"-");
      break;
      case 1:
      sprintf(string_temp_familly,"GO");
      break;
      case 2:
      sprintf(string_temp_familly,"GO BACK");
      break;
      case 3://Fader saw
      sprintf(string_temp_familly,"JUMP");
      break;
      case 4:
      sprintf(string_temp_familly,"STAGE -");
      break;
      case 5:
      sprintf(string_temp_familly,"STAGE +");
      break;
      case 6:
      sprintf(string_temp_familly,"PRESET -");
      break;
      case 7:
      sprintf(string_temp_familly,"PRESET +");
      break;
      case 8:
      sprintf(string_temp_familly,"GOTO");
      break;


default:
sprintf(string_temp_familly,"-");
break;
}
break;
case 4://emulate
     switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
      case 0:
      sprintf(string_temp_familly,"0");
      break;
      case 1:
      sprintf(string_temp_familly,"1");
      break;
      case 2:
      sprintf(string_temp_familly,"2");
      break;
      case 3:
      sprintf(string_temp_familly,"3");
      break;
      case 4:
      sprintf(string_temp_familly,"4");
      break;
      case 5:
      sprintf(string_temp_familly,"5");
      break;
      case 6:
      sprintf(string_temp_familly,"6");
      break;
      case 7:
      sprintf(string_temp_familly,"7");
      break;
      case 8:
      sprintf(string_temp_familly,"8");
      break;
      case 9:
      sprintf(string_temp_familly,"9");
      break;
      case 10:
      sprintf(string_temp_familly,".");
      break;
      case 11:
      sprintf(string_temp_familly,"PLUS");
      break;
      case 12:
      sprintf(string_temp_familly,"MINUS");
      break;
      case 13:
      sprintf(string_temp_familly,"ALL");
      break;
      case 14:
      sprintf(string_temp_familly,"INV");
      break;
      case 15:
      sprintf(string_temp_familly,"TAB");
      break;
      case 16:
      sprintf(string_temp_familly,"ESC");
      break;
      case 17:
      sprintf(string_temp_familly,"ENT");
      break;
      case 18://FULL
      sprintf(string_temp_familly,"/100");
      break;
      case 19://a ZERO
      sprintf(string_temp_familly,"/0");
      break;
      case 20://backspace
      sprintf(string_temp_familly,"BCKSP");
      break;
      case 21://DEL
      sprintf(string_temp_familly,"DEL");
      break;
      case 22://arrow Up
      sprintf(string_temp_familly,"UP");
      break;
      case 23://arrow down
      sprintf(string_temp_familly,"DOWN");
      break;
      case 24://arrow left
      sprintf(string_temp_familly,"LEFT");
      break;
      case 25://arrow right
      sprintf(string_temp_familly,"RIGHT");
      break;
      case 26:
      sprintf(string_temp_familly,"F1");
      break;
      case 27:
      sprintf(string_temp_familly,"F2");
      break;
      case 28:
      sprintf(string_temp_familly,"F3");
      break;
      case 29:
      sprintf(string_temp_familly,"F4");
      break;
      case 30:
      sprintf(string_temp_familly,"F11");
      break;
      case 31:
      sprintf(string_temp_familly,"F12");
      break;
      case 32:
      sprintf(string_temp_familly,"SHFT");
      break;
      case 33:
      sprintf(string_temp_familly,"CTRL");
      break;
      default:
      sprintf(string_temp_familly,"-");
      break;
     }

break;
case 5://banger
switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
      case 0:
      sprintf(string_temp_familly,"-");
      break;
      case 1:
      sprintf(string_temp_familly,"Bang Solo");
      break;
      default:
      sprintf(string_temp_familly,"-");
      break;
      }
break;
case 6://icat commandes
      switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
      case 0:
      sprintf(string_temp_familly,"-");
      break;
      case 1:
      sprintf(string_temp_familly,"Page -");
      break;
      case 2:
      sprintf(string_temp_familly,"Page +");
      break;
      case 3:
      sprintf(string_temp_familly,"Page Num:");
      break;
      case 4:
      sprintf(string_temp_familly,"Refresh Page");
      break;
      case 5:
      sprintf(string_temp_familly,"Page Orientation");
      break;
      default:
      sprintf(string_temp_familly,"-");
      break;
      }
break;
case 7://draw
      switch(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button])
     {
      case 1:
      sprintf(string_temp_familly,"Activ BrushType");
      break;
      case 2:
      sprintf(string_temp_familly,"Activ Draw Mode");
      break;
      case 3:
      sprintf(string_temp_familly,"Matrix BrushType");
      break;
      case 4:
      sprintf(string_temp_familly,"Matrix Draw Mode");
      break;
      case 5:
      sprintf(string_temp_familly,"Select Matrix Num:");
      break;
      default:
      sprintf(string_temp_familly,"-");
      break;
      }
break;
default:
break;
}
petitpetitchiffre.Print(string_temp_familly,xed-7,yed+137);
if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+125 && mouse_y<yed+145 &&
   mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_button!=0)
{
editing_GUI_type_iCat=2;
iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button]++;
iCat_affectation_bouton_value_is[iCatPageis][iCat_select_editing_button]=0;
int max_menu=0;
switch ( iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button])
{
case 1:
     max_menu=13;//faders
break;
case 2://minifaders
     max_menu=20;//minifaders
break;
case 3://seq
     max_menu=8;
break;
case 4://emulate
max_menu=33;
break;
case 5://banger
max_menu=1;
break;
case 6://icat familly
max_menu=5;
break;
case 7://draw familly
max_menu=5;
break;
default:
break;
}
if(iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button]>max_menu){iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button]=0;}
mouse_released=1;
}


Rect AffectVar(Vec2D(xed+40,yed+150),Vec2D(45,20));
AffectVar.SetRoundness(5);
AffectVar.Draw(CouleurFond.WithAlpha(0.4));
petitpetitchiffre.Print(ol::ToString(iCat_affectation_bouton_value_is[iCatPageis][iCat_select_editing_button]),
                          xed+55,yed+162);

if(mouse_x>xed+40 && mouse_x<xed+85 && mouse_y>yed+150 && mouse_y<yed+170 &&  window_focus_id==W_iCAT )
{
editing_GUI_type_iCat=2;
AffectVar.DrawOutline(CouleurLigne);
if(  mouse_button==1 && mouse_released==0 && iCat_select_editing_button!=0)
{

int temp_number=atoi(numeric);
reset_numeric_entry();
switch(iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button])
{
case 1: //faders
if(temp_number>48){temp_number=48;}
break;
case 2://minifaders
if(temp_number>48){temp_number=48;}
break;
case 4://seq scene et preset et vitesse
if(temp_number>3){temp_number=3;}
break;
case 5://banger
if(temp_number>127){temp_number=127;}
break;
case 7://draw
if(temp_number>6){temp_number=6;}
break;
default:
break;
}
iCat_affectation_bouton_value_is[iCatPageis][iCat_select_editing_button]=temp_number;
mouse_released=1;
}
}


Rect DubB(Vec2D(xed-15,yed+150),Vec2D(30,15));

petitpetitchiffre.Print("Dub",xed-10,yed+160);

DubB.SetRoundness(4);
DubB.Draw(CouleurFond.WithAlpha(0.4));
if(mouse_x>xed-15 && mouse_x<xed+15 && mouse_y>yed+150 && mouse_y<yed+165
   && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
{
editing_GUI_type_iCat=2;
if(iCat_nbre_de_boutons[iCatPageis]<max_buttons_icat)
{
 int iCatrefbutton=iCat_select_editing_button;
 iCat_nbre_de_boutons[iCatPageis]++;
 iCat_select_editing_button=iCat_nbre_de_boutons[iCatPageis];
 iCat_pos_bouton[iCatPageis][iCat_select_editing_button][0]=iCat_pos_bouton[iCatPageis][iCatrefbutton][0]+grid_icat_modulo;
 iCat_pos_bouton[iCatPageis][iCat_select_editing_button][1]=iCat_pos_bouton[iCatPageis][iCatrefbutton][1]+grid_icat_modulo;
 ratio_iCat_button[iCatPageis][iCat_select_editing_button]=ratio_iCat_button[iCatPageis][iCatrefbutton];
 iCat_affectation_bouton_type_is[iCatPageis][iCat_select_editing_button] = iCat_affectation_bouton_type_is[iCatPageis][iCatrefbutton];
 iCat_affectation_bouton_action_is[iCatPageis][iCat_select_editing_button] = iCat_affectation_bouton_action_is[iCatPageis][iCatrefbutton];
 iCat_affectation_bouton_value_is[iCatPageis][iCat_select_editing_button] = iCat_affectation_bouton_value_is[iCatPageis][iCatrefbutton];
 sprintf(string_Last_Order,"Dubbed iCat Button !");
}
 mouse_released=1;
}

 return(0);
}
