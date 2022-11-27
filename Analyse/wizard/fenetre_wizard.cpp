int fenetre_wizard(int xb,int yb)
{

Rect wiz_backg(Vec2D(xb,yb), Vec2D( 480,420));
wiz_backg.SetRoundness(15);
wiz_backg.SetLineWidth(triple_epaisseur_ligne_fader);
wiz_backg.Draw(CouleurBleuProcedure);
if(window_focus_id==921)
{
wiz_backg.DrawOutline(CouleurFader);
}
else
{
 wiz_backg.DrawOutline(CouleurLigne);
}

Rect wiz_ch2(Vec2D(xb+10,(yb+270)), Vec2D( 460,100));
wiz_ch2.SetRoundness(15);
wiz_ch2.Draw(CouleurFond.WithAlpha(0.5));
petitpetitchiffrerouge.Print(ol::ToString(position_ligne_wizard_out+1),(xb+450), (yb+320));
Circle LineUp(Vec2D(xb+450,yb+290),12);
LineUp.Draw(CouleurFond);
Circle LineDown(Vec2D(xb+450,yb+350),12);
LineDown.Draw(CouleurFond);
if(window_focus_id==W_WIZARD && mouse_x>xb+438 && mouse_x<xb+462)
{
if(mouse_y>yb+278 && mouse_y<yb+302)
{
LineUp.Draw(CouleurSurvol);
if(mouse_button==1)
{
LineUp.Draw(CouleurFader);
if(position_ligne_wizard_out>0){position_ligne_wizard_out--;}
}
}
else if(mouse_y>yb+338 && mouse_y<yb+362)
{
LineDown.Draw(CouleurSurvol);
if(mouse_button==1)
{
LineDown.Draw(CouleurFader);
if(position_ligne_wizard_out<36){position_ligne_wizard_out++;}
}
}
}
petitchiffre.Print("-",xb+447,yb+293);
petitchiffre.Print("+",xb+446,yb+353);
LineUp.DrawOutline(CouleurLigne);
LineDown.DrawOutline(CouleurLigne);

Rect wiz_mode(Vec2D(xb+105,yb+3), Vec2D( 130,30));
wiz_mode.SetRoundness(15);
wiz_mode.SetLineWidth(epaisseur_ligne_fader);

if(window_focus_id==W_WIZARD && mouse_x>xb+105 && mouse_x<xb+235 && mouse_y>yb+3 && mouse_y<yb+33)
{
 wiz_mode.Draw(CouleurFader);
if(mouse_button==1 && mouse_released==0)
{
 index_wizard_ch_mode=toggle(index_wizard_ch_mode);
 mouse_released=1;
}
}
wiz_mode.DrawOutline(CouleurLigne);

if(index_wizard_ch_mode==0)
{
neuro.Print( "Wizard MEM",(xb+110), (yb+25));
Box_mem_to_mem(xb,yb-110);
char templim[32];

for (int li=0;li<7;li++)
{
    Rect domact(Vec2D((xb+20),(yb+60+(li*30))), Vec2D( 50,20));
    domact.SetRoundness(7.5);
    domact.Draw(CouleurFond.WithAlpha(0.5));
    if(window_focus_id==W_WIZARD && mouse_x>xb+20 && mouse_x<xb+70 && mouse_y>yb+60+(li*30) && mouse_y<yb+80+(li*30) )
    {
                     if(mouse_button==1 && mouse_released==0)
                     {
                     wizard_action_mem=li;
                     mouse_released=1;
                     }
    }
if(wizard_action_mem==li){domact.Draw(CouleurFader); }

switch (li)
{
case 0:
     sprintf(templim,"Rebuild Numerical Order ");
break;
case 1:
     sprintf(templim,"Insert Memories");
break;
case 2:
     sprintf(templim,"Delete Memories");
break;
case 3:
     sprintf(templim,"Move memories");
break;
case 4:
     sprintf(templim,"Inspect a deleted Memory");
break;
case 5:
     sprintf(templim,"Restore deleted Memories");
break;
case 6:
     sprintf(templim,"Reset to default Time");
break;
default: break;
}
petitchiffre.Print(templim,xb+80,yb+75+(li*30));
}


char tmp_str_m[36];
sprintf(tmp_str_m,"Number of memories: %d",nbre_de_mems_manipulees);
petitchiffre.Print(tmp_str_m,xb+270,yb+30);


switch(wizard_action_mem)
{
case 0://REBUILD
     petitchiffre.Print("Rebuild Mode:", xb+270 , yb+180);
     Line(Vec2D( xb+270 , yb+190),Vec2D( xb+370 , yb+190)).Draw(CouleurLigne);
     for(int mod=0;mod<3;mod++)
     {
     Rect choose_mode_rebuild(Vec2D((xb+300),(yb+200+(wizard_action_mem*30)+(mod*20))), Vec2D( 30,15));
     choose_mode_rebuild.SetRoundness(5);
     choose_mode_rebuild.SetLineWidth(epaisseur_ligne_fader);
     choose_mode_rebuild.Draw(CouleurFond.WithAlpha(0.5));
     switch (mod)
     {
     case 0:
     petitchiffre.Print("0.2 /0.3 / 0.4 ...", xb+360 , yb+210+(wizard_action_mem*30)+(mod*20));
     break;
     case 1:
     petitchiffre.Print("2 /3 /4 ...", xb+360 , yb+210+(wizard_action_mem*30)+(mod*20));
     break;
     case 2:
     petitchiffre.Print("20 /30 /40 ...", xb+360 , yb+210+(wizard_action_mem*30)+(mod*20));
     break;
     default: break;
     }
     if(mod==mode_rebuild){choose_mode_rebuild.DrawOutline(CouleurLevel); }
     if(window_focus_id==W_WIZARD &&mouse_x>xb+300 && mouse_x<xb+330 && mouse_y> yb+200+(wizard_action_mem*30)+(mod*20) && mouse_y<yb+215+(wizard_action_mem*30)+(mod*20))
     {
     //sab 02/03/2014 IMPACT if(mouse_button=1 && mouse_released==0)
     if(mouse_button==1 && mouse_released==0)
     {
     mode_rebuild=mod;
     mouse_released=1;
     }
     }
     }
break;
case 1://INSERT MEMS
petitchiffre.Print("Number of Memories to insert", xb+270 , yb+180);
     Line(Vec2D( xb+270 , yb+190),Vec2D( xb+370 , yb+190)).Draw(CouleurLigne);
break;
case 3://deplacer
petitchiffre.Print("Move to place:", xb+270 , yb+180);
Line(Vec2D( xb+270 , yb+190),Vec2D( xb+370 , yb+190)).Draw(CouleurLigne);
break;
case 4://inspection
petitchiffre.Print("Mem to inspekt:", xb+270 , yb+180);
Line(Vec2D( xb+270 , yb+190),Vec2D( xb+370 , yb+190)).Draw(CouleurLigne);
petitchiffre.Print("Mem contains  :",(xb+20), (yb+285));
for(int ly=0;ly<5;ly++)
{
petitpetitchiffre.Print(show_buff_wizOUT[ly+position_ligne_wizard_out],(xb+30), (yb+300)+(ly*15));
}
break;
default:
break;
}
if(wizard_action_mem==1 || wizard_action_mem==3 || wizard_action_mem==4)
{
     Rect act_mem(Vec2D((xb+410),(yb+190)), Vec2D( 60,30));
     act_mem.SetRoundness(5);
     act_mem.SetLineWidth(epaisseur_ligne_fader);
     act_mem.Draw(CouleurFond.WithAlpha(0.5));

     if(window_focus_id==W_WIZARD && mouse_x> xb+410 && mouse_x<xb+470 && mouse_y> yb+190 && mouse_y<yb+210)
     {
     act_mem.DrawOutline(CouleurLevel);
     if(mouse_button==1 && mouse_released==0)
     {
     variable_wizard_mem=(int)(atof(numeric)*10);
     reset_numeric_entry();
     mouse_released=1;
     }
     }
     char tmp_sh_m[8];
     sprintf(tmp_sh_m,"%d.%d",variable_wizard_mem/10,variable_wizard_mem%10);
     petitchiffre.Print(tmp_sh_m,  xb+430, yb+ 210);
}

}

else if(index_wizard_ch_mode==1)
{
neuro.Print( " Wizard  CH",(xb+110), (yb+25));
Rect detect_ch(Vec2D(xb+415,yb+10), Vec2D( 50,20));
detect_ch.SetRoundness(6);
detect_ch.Draw(CouleurFond.WithAlpha(0.5));
detect_ch.DrawOutline(CouleurBlanc.WithAlpha(0.5));
petitchiffre.Print("Select unused Channels",(xb+260), (yb+25));
if(window_focus_id==W_WIZARD  && mouse_x>xb+415 && mouse_x<xb+465 && mouse_y>yb+10 && mouse_y<yb+30 && mouse_released==0)
{
detect_ch.Draw(CouleurFader);
if(mouse_button==1 && mouse_released==0)
{
for (int l=1; l<514; l++)
{
     Selected_Channel[l]=0;
}

wizard_detect_unused_channels(wizard_from_mem, wizard_to_mem);
mouse_released=1;
}
}


Box_mem_to_mem(xb,yb);
Rect wiz_ch(Vec2D(xb+10,yb+40), Vec2D( 460,100));
wiz_ch.SetRoundness(15);
wiz_ch.Draw(CouleurFond.WithAlpha(0.5));
petitchiffre.Print("Selected Channels:   /",(xb+20), (yb+55));
petitchiffre.Print(ol::ToString(number_inchannels),(xb+170), (yb+55));
for(int ly=0;ly<5;ly++)
{
petitpetitchiffre.Print(show_buff_wizIN[ly+position_ligne_wizard_in],(xb+30), (yb+75)+(ly*15));
}
if(window_focus_id==W_WIZARD &&(index_do_dock==1 || index_main_clear==1 ) && mouse_x>xb+10 && mouse_x<xb+470 && mouse_y>yb+40 && mouse_y<yb+140 )
{
wiz_ch.DrawOutline(CouleurBlind);
if(mouse_button==1 && mouse_released==0)
{
if(index_do_dock==1)
{
wizard_store_channel_in();
}
else if(index_main_clear==1)
{
clear_wizard_store_ch_in();   index_main_clear=0;
}
mouse_released=1;
}
}
Circle LineUpO(Vec2D(xb+450,yb+60),12);
LineUpO.Draw(CouleurFond);
Circle LineDownO(Vec2D(xb+450,yb+120),12);
LineDownO.Draw(CouleurFond);
petitpetitchiffrerouge.Print(ol::ToString(position_ligne_wizard_in+1),(xb+450), (yb+110));
if(window_focus_id==W_WIZARD && mouse_x>xb+438 && mouse_x<xb+462)
{
if(mouse_y>yb+48 && mouse_y<yb+72)
{
LineUpO.Draw(CouleurSurvol);
if(mouse_button==1)
{
LineUpO.Draw(CouleurFader);
if(position_ligne_wizard_in>0){position_ligne_wizard_in--;}
}
}
else if(mouse_y>yb+108 && mouse_y<yb+132)
{
LineDownO.Draw(CouleurSurvol);
if(mouse_button==1)
{
LineDownO.Draw(CouleurFader);
if(position_ligne_wizard_in<36){position_ligne_wizard_in++;}
}
}
}
petitchiffre.Print("-",xb+447,yb+63);
petitchiffre.Print("+",xb+446,yb+123);
LineUpO.DrawOutline(CouleurLigne);
LineDownO.DrawOutline(CouleurLigne);

if(wizard_action==3 || wizard_action==4)
{

petitchiffre.Print("To Channels:   /",(xb+20), (yb+285));
petitchiffre.Print(ol::ToString(number_outchannels),(xb+170), (yb+285));
for(int ly=0;ly<5;ly++)
{
petitpetitchiffre.Print(show_buff_wizOUT[ly+position_ligne_wizard_out],(xb+30), (yb+300)+(ly*15));
}
if(window_focus_id==W_WIZARD && (index_do_dock==1 || index_main_clear==1) && mouse_x>xb+10 && mouse_x<xb+470 && mouse_y>yb+270 && mouse_y<yb+370 )
{
wiz_ch2.DrawOutline(CouleurBlind);
if(mouse_button==1 && mouse_released==0)
{
 if(index_do_dock==1)
{
wizard_store_channel_out();
}
else if(index_main_clear==1)
{
 clear_wizard_store_ch_out();    index_main_clear=0;
}
mouse_released=1;
}
}


if(wizard_action==3 && number_inchannels!=number_outchannels && number_outchannels!=0 && number_inchannels!=0  )
{
 Rect avertissement(Vec2D((xb+180), yb),Vec2D(300,40));
 avertissement.SetRoundness(7.5);
 avertissement.Draw(CouleurBlind.WithAlpha(alpha_blinker));
 petitpetitchiffre.Print("Number of channels are different: all exchanged chan. ",(xb+185), (yb+15));
 petitpetitchiffre.Print("will be set at last chan. level in selection !",(xb+185),(yb+35));

}
}





char templi[24];
for (int li=0;li<4;li++)
{
Rect doact(Vec2D((xb+20),(yb+150+(li*30))), Vec2D( 50,20));
doact.SetRoundness(7.5);
doact.Draw(CouleurFond.WithAlpha(0.5));
if(window_focus_id==W_WIZARD && mouse_x>xb+20 && mouse_x<xb+70 && mouse_y>yb+150+(li*30) && mouse_y<yb+170+(li*30) )
{
if(mouse_button==1 && mouse_released==0)
{
wizard_action=li;
mouse_released=1;
}
}
if(wizard_action==li){doact.Draw(CouleurFader); }
switch (li)
{
case 0:
sprintf(templi,"Set at");
break;
case 1:
sprintf(templi,"Add from");
break;
case 2:
sprintf(templi,"Reduce from");
break;
case 3:
sprintf(templi,"Replace");
break;
default: break;
}
petitchiffre.Print(templi,xb+80,yb+165+(li*30));
}

Line(Vec2D(xb+150,yb+165),Vec2D(xb+220,yb+165)).Draw(CouleurLigne);
Line(Vec2D(xb+160,yb+195),Vec2D(xb+190,yb+195)).Draw(CouleurLigne);
Line(Vec2D(xb+180,yb+225),Vec2D(xb+220,yb+225)).Draw(CouleurLigne);
Line(Vec2D(xb+220,yb+165),Vec2D(xb+220,yb+180)).Draw(CouleurLigne);
Line(Vec2D(xb+220,yb+225),Vec2D(xb+220,yb+210)).Draw(CouleurLigne);



Rect levlTo(Vec2D((xb+190),(yb+180)), Vec2D( 60,30));
levlTo.SetRoundness(7.5);
levlTo.Draw(CouleurFond.WithAlpha(0.5));

if(window_focus_id==W_WIZARD && mouse_x>xb+190 && mouse_x<xb+250 && mouse_y>yb+180 && mouse_y<yb+210)
{
levlTo.DrawOutline(CouleurLigne);
if(mouse_button==1 && mouse_released==0)
{
wizard_level_is=atoi(numeric);
mouse_released=1;
reset_numeric_entry();
switch(dmx_view)
{
case 0:
if(wizard_level_is>100){wizard_level_is=100;}
else if (wizard_level_is<0){wizard_level_is=0;}
break;
case 1:
if(wizard_level_is>255){wizard_level_is=255;}
else if (wizard_level_is<0){wizard_level_is=0;}
break;
default: break;
}
}
}
petitchiffre.Print(ol::ToString(wizard_level_is),xb+213,yb+199);






Rect swap(Vec2D((xb+170),(yb+240)), Vec2D( 50,20));
swap.SetRoundness(7.5);
swap.Draw(CouleurFond.WithAlpha(0.5));
if(wizard_action==4){swap.Draw(CouleurFader); }
petitchiffre.Print("Swap",xb+230,yb+255);

if(window_focus_id==W_WIZARD && mouse_x>xb+170 && mouse_x<xb+220 && mouse_y>yb+240 && mouse_y<yb+260)
{
if(mouse_button==1 && mouse_released==0)
{
wizard_action=4;
mouse_released=1;
}
}

}


Rect cancelit(Vec2D((xb+85),(yb+380)), Vec2D( 110,30));
cancelit.SetRoundness(15);
cancelit.SetLineWidth(epaisseur_ligne_fader);

if(window_focus_id==W_WIZARD && mouse_x>xb+85 && mouse_x<xb+195 && mouse_y>yb+380 && mouse_y<yb+410 )
{
cancelit.Draw(CouleurFond.WithAlpha(0.5));
if(mouse_button==1 && mouse_released==0)
{
reset_indexs_confirmation();
index_wizard_do_reload_from_disk=1;
index_ask_confirm=1;
}
}

cancelit.DrawOutline(CouleurLigne);

petitchiffre.Print("Reload from disk",xb+90,yb+400);
Rect doit(Vec2D((xb+285),(yb+380)), Vec2D( 110,30));
doit.SetRoundness(15);
doit.SetLineWidth(epaisseur_ligne_fader);

if(window_focus_id==W_WIZARD && mouse_x>xb+285 && mouse_x<xb+395 && mouse_y>yb+380 && mouse_y<yb+410 )
{
doit.Draw(CouleurFond.WithAlpha(0.5));
if(mouse_button==1 && mouse_released==0)
{
reset_indexs_confirmation();
switch(index_wizard_ch_mode)
{
case 0:
index_do_wizard_mem=1;
break;
case 1:
index_do_wizard_ch=1;
break;
default: break;
}
index_ask_confirm=1;

}
}
doit.DrawOutline(CouleurLigne);

petitchiffre.Print("DO IT !",xb+320,yb+400);



return(0);
}
