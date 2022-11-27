int do_logical_x1_x2(int x_seq,int y_seq)
{


if(mouse_y>=y_seq+60 && mouse_y<=y_seq+100+255)//-20 +20
{
if(mouse_x> x_seq+480 && mouse_x< x_seq+480+45)
{


switch(miditable[0][491])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default: break;
}
sprintf(string_last_midi_id,"STAGE Fader is Ch: %d Pitch: %d Typ: %s" , miditable[1][491],miditable[2][491],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(491,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
set_mouse_range(x_seq+480, y_seq+60, x_seq+480+45, y_seq+100+255);//pour pas deborder
index_go=0; index_go_back=0; index_pause=0;
niveauX1=(y_seq+80+255)-mouse_y;
if(niveauX1<0){niveauX1=0;}
if(niveauX1>255){niveauX1=255;}
if(midi_send_out[491]==1){index_send_midi_out[491]=1;}
if(index_x1_x2_together==1)
{
if(((255.0-ratio_X1X2_together)/255)==1.0){niveauX2=(255-niveauX1);}
else {niveauX2=remapX2[(255-niveauX1)];}
if(niveauX2<0){niveauX2=0;}
if(niveauX2>255){niveauX2=255;}
if(midi_send_out[492]==1){index_send_midi_out[492]=1;}
}
}
}

else if(mouse_x> x_seq+580 && mouse_x< x_seq+580+45)
{


switch(miditable[0][492])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default: break;
}
sprintf(string_last_midi_id,"Preset Fader is Ch: %d Pitch: %d Typ: %s" , miditable[1][492],miditable[2][492],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(492,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
set_mouse_range(x_seq+580, y_seq+60, x_seq+580+45, y_seq+100+255);//pour pas deborder
index_go=0; index_go_back=0; index_pause=0;
niveauX2=(-1)*(mouse_y-(y_seq+80+255));
if(niveauX2<0){niveauX2=0;}
if(niveauX2>255){niveauX2=255;}
if(midi_send_out[492]==1){index_send_midi_out[492]=1;}
if(index_x1_x2_together==1)
{
if(((255.0-ratio_X1X2_together)/255)==1.0){niveauX1=(255-niveauX2);}
else { niveauX1=255-remapX1[niveauX2];     }
if(niveauX1<0){niveauX1=0;}
if(niveauX1>255){niveauX1=255;}
if (niveauX2==255){niveauX1=0;}//report à zero
if(midi_send_out[491]==1){index_send_midi_out[491]=1;}
}
}
}

if(niveauX1==0 && niveauX2==255)
{
index_go=0; index_go_back=0; index_pause=0;
next_mem_crossfade_finished(position_preset);
index_x1_x2_together=1;
mouse_released=1;
}
}


raccrochage_midi_logical_vertical_dmx ( x_seq+480, (y_seq+80), 491, 45, 255);//X1
raccrochage_midi_logical_vertical_dmx ( x_seq+580, (y_seq+80), 492, 45, 255);//X2 séparés car inversés pour l'affichage etc

if(mouse_x> x_seq+540 && mouse_x< x_seq+540+50 && mouse_y>y_seq+50 && mouse_y<y_seq+50+20)
{
if(index_x1_x2_together==0){index_x1_x2_together=1;}
else {index_x1_x2_together=0;}
mouse_released=1;
}
if(mouse_x> x_seq+535 && mouse_x< x_seq+575 && mouse_y>y_seq+80 && mouse_y<y_seq+350)
{
ratio_X1X2_together=(int)((mouse_y)-(y_seq+80+255));
float fract_remplaX1=(255.0-ratio_X1X2_together)/255;
float remapis=255.0;
float fract_remplaX2=(255.0-ratio_X1X2_together)/255;
for(int mop=255;mop>=0;mop--)
{
remapis-=fract_remplaX1;
if (remapis>255){remapX1[mop]=255;}
else if(remapis<0){remapX1[mop]=0;}
else
{
remapX1[mop]=(int)(remapis);
}
}
for(int mop=0;mop<255;mop++)//etait 256 aout 2016
{
remapis+=fract_remplaX2;
if (remapis>255){remapX2[mop]=255;}
else if(remapis<0){remapX2[mop]=0;}
else {remapX2[mop]=(int)(remapis);  }
}
index_go=0;
ratio_cross_manuel[position_preset]=ratio_X1X2_together;
}

if(mouse_x>x_seq+534 && mouse_x<x_seq+574 && mouse_y>y_seq+355 && mouse_y<y_seq+395)
{
 switch(miditable[0][495])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default:
break;
}
sprintf(string_last_midi_id,"GO is Ch: %d Pitch: %d Typ: %s" , miditable[1][495],miditable[2][495],thetypinfo);
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(495,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
do_go_function();
if(index_go==1 && index_pause==0)
{
do_send_bang();
}
mouse_released=1;
}
}



if(mouse_x>x_seq+490+14-20 && mouse_x<x_seq+490+14+20 && mouse_y>y_seq+80+255+40-20 && mouse_y<y_seq+80+255+40+20)
{

switch(miditable[0][494])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default: break;
}
  sprintf(string_last_midi_id,"GO BACK is Ch: %d Pitch: %d Typ: %s" , miditable[1][494],miditable[2][494],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(494,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else
{
do_go_back_function();
int banger_back_is=Banger_Memoire[position_preset]-1;
do_go_back_bang(banger_back_is);
mouse_released=1;
}
}



if(mouse_x>x_seq+590+14-20 && mouse_x<x_seq+590+14+20 && mouse_y>y_seq+80+255+40-20 && mouse_y<y_seq+80+255+40+20)
{


switch(miditable[0][496])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default: break;
}
  sprintf(string_last_midi_id,"GO BACK is Ch: %d Pitch: %d Typ: %s" , miditable[1][496],miditable[2][496],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(496,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else
{
do_double_go_function();
if(index_go==1 && index_pause==0)
{
do_send_bang();
}
mouse_released=1;
}
}


if(mouse_x>=x_seq+490 && mouse_x<=x_seq+490+127 && mouse_y>y_seq+405 && mouse_y<y_seq+405+(45/2))
{



switch(miditable[0][493])
{
case 0:
sprintf(thetypinfo,"Note");
break;
case 1:
sprintf(thetypinfo,"Key On");
break;
case 2:
sprintf(thetypinfo,"Key Off");
break;
case 4:
sprintf(thetypinfo,"Ctrl Change");
break;
default: break;
}
sprintf(string_last_midi_id,"SpeedFader is Ch: %d Pitch: %d Typ: %s" , miditable[1][493],miditable[2][493],thetypinfo);

if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(493,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
set_mouse_range(x_seq+490, y_seq+405, x_seq+490+127, y_seq+405+(45/2));//pour pas deborder
crossfade_speed=mouse_x-(x_seq+490);
if(crossfade_speed<0){crossfade_speed=0;}
if(crossfade_speed>127){crossfade_speed=127;}
if(index_link_speed_crossfade_to_gpl1==1)
{
grid_crossfade_speed[0]=crossfade_speed;
midi_levels[1508]=crossfade_speed;
gridder_prepare_cross(0,index_grider_selected[0],index_grider_step_is[0]);
}

if(midi_send_out[493]==1){index_send_midi_out[493]=1;}
prepare_crossfade();
someone_changed_in_time_sequences=1;//icat
}
}


if(mouse_x> x_seq+655-10 && mouse_x<  x_seq+655+10 && mouse_y>y_seq+340-10 && mouse_y<y_seq+340+10)
{

  if(midi_send_out[491]==0){midi_send_out[491]=1; }
  else if(midi_send_out[491]==1){midi_send_out[491]=0; }
  //report pour x2 et speed crossfade
  midi_send_out[492]=midi_send_out[491];
  mouse_released=1;
}



if(mouse_x> x_seq+655-10 && mouse_x<  x_seq+655+10 && mouse_y>y_seq+340-10+85 && mouse_y<y_seq+340+10+85)
{
  if(midi_send_out[493]==0){midi_send_out[493]=1; }
  else if(midi_send_out[493]==1){midi_send_out[493]=0; }
  mouse_released=1;
}

raccrochage_midi_logical_horizontal ( x_seq+490, y_seq+405, 493,127,13);

if(mouse_x> x_seq+548 && mouse_x<  x_seq+548+15 && mouse_y>y_seq+435 && mouse_y<y_seq+435+15)
{
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(1591,Midi_Faders_Affectation_Mode);
}
else
{
auto_reset_crossfade_speed_on_link=toggle(auto_reset_crossfade_speed_on_link);
}
mouse_released=1;
}
return(0);
}
