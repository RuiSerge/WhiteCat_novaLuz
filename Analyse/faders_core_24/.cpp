int do_logical_lfo_fader_functions (int cmptfader, int x, int y,int largeur, int espacement)
{

for (int dd=0;dd<core_user_define_nb_docks;dd++)
{

if(mouse_x>x+(cmptfader*espacement)+(largeur*size_faders)+100+10-6 && mouse_x<x+(cmptfader*espacement)+(largeur*size_faders)+100+10+6
&& mouse_y>y+10-6+(dd*40) && mouse_y<y+10+6+(dd*40))
{

if(is_dock_for_lfo_selected[cmptfader][dd]==0)
{is_dock_for_lfo_selected[cmptfader][dd]=1; }
else if (is_dock_for_lfo_selected[cmptfader][dd]==1)
{is_dock_for_lfo_selected[cmptfader][dd]=0;}
mouse_released=1;

}


if(mouse_x>x+(cmptfader*espacement)-5 && mouse_x<x+(cmptfader*espacement)+127+5
&& mouse_y>y+375 && mouse_y<y+375+ (largeur/2))
{
switch (miditable[0][196+cmptfader])
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
sprintf(string_last_midi_id,"LFO SPEED is Ch: %d Pitch: %d Typ: %s" , miditable[1][196+cmptfader],miditable[2][196+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0)

{
attribute_midi_to_control(196+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else {
set_mouse_range(x+(cmptfader*espacement), y+375, x+(cmptfader*espacement)+127+5, y+375+ (largeur/2));//pour pas deborder
lfo_speed[cmptfader]=mouse_x-(x+(cmptfader*espacement));
if(lfo_speed[cmptfader]<0){lfo_speed[cmptfader]=0;}
if(lfo_speed[cmptfader]>127){lfo_speed[cmptfader]=127;}



if(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]]==12)//enchassement Grid si slave
{
asservissement_gridplayer(cmptfader,dock_used_by_fader_is[cmptfader]);
}
midi_levels[196+cmptfader]=lfo_speed[cmptfader];
index_send_midi_out[196+cmptfader]=1;
}
}


raccrochage_midi_logical_horizontal ( x+(cmptfader*espacement), y+375, 196+cmptfader,127,largeur/2);

if(mouse_x> (x+(cmptfader*espacement)+140 )&& (mouse_x<x+(cmptfader*espacement)+160) && mouse_y>(y+397-10) && mouse_y< (y+397+10))
{
if(mouse_button==1 && mouse_released==0)
{
midi_send_out[cmptfader+196]=toggle(midi_send_out[cmptfader+196]);
mouse_released=1;
}
}
if(mouse_x> (x+(cmptfader*espacement)-6) && mouse_x<(x+(cmptfader*espacement)-6 + (largeur/2)) && mouse_y>(y+320) && mouse_y<(y+320 + (largeur/2))
&& mouse_released==0)
{
switch (miditable[0][685+cmptfader])
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
sprintf(string_last_midi_id,"StopPos is Ch: %d Pitch: %d Typ: %s" , miditable[1][685+cmptfader],miditable[2][685+cmptfader],thetypinfo);


if(Midi_Faders_Affectation_Type!=0)
{
attribute_midi_to_control(685+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(index_do_dock==0 && index_main_clear==0)
{
ActionnateStopOn[cmptfader]=toggle(ActionnateStopOn[cmptfader]);mouse_released=1;
}

else if(index_do_dock==1 && index_main_clear==0 )
{
if(numeric_postext>0 )//affectation stop pos par chaine de carcatere
{
int lStopPos=999;
    switch(dmx_view)
    {
    case 0:
    lStopPos=(int)((atof(numeric) *2.55) +1);//+1 pour arrondir le %
    break;
    case 1:
    lStopPos=atol(numeric);
    break;
    default: break;
    }
reset_numeric_entry();
if (lStopPos>=0 && lStopPos<=255)
   {
   StopPosOn[cmptfader]=1;LevelStopPos[cmptfader]=lStopPos;
   index_do_dock=0;
   do_light_setpos[cmptfader]=1;
   }
}
else if (numeric_postext==0) //affectation stop pos depuis le cursuer fader
{
StopPosOn[cmptfader]=1;LevelStopPos[cmptfader]=Fader[cmptfader];
index_do_dock=0;
do_light_setpos[cmptfader]=1;
}
}

else if(index_main_clear==1 && index_do_dock==0)//clear
{
StopPosOn[cmptfader]=0;
LevelStopPos[cmptfader]=999;
index_main_clear=0;
do_light_setpos[cmptfader]=1;
}
}
mouse_released=1;
}

if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+105+(largeur/2)
&& mouse_y> y+240 && mouse_y< y+240+(largeur/2) )
{
switch (miditable[0][245+cmptfader])
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
  sprintf(string_last_midi_id,"LFO UP is Ch: %d Pitch: %d Typ: %s" , miditable[1][245+cmptfader],miditable[2][245+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_to_control(245+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else{
if(mouse_released==0 && (FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1))//rajout lock 0.7.6
{
start_time_for_delays[cmptfader]=actual_time;
if(lfo_mode_is[cmptfader]!=1)//up
{
lfo_mode_is[cmptfader]=1;
faders_in_float[cmptfader]=Fader[cmptfader];
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[cmptfader]=1;}
}
else {lfo_mode_is[cmptfader]=0;}
lfo_cycle_is_on[cmptfader]=0;
}
mouse_released=1;
}
}
if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+105+(largeur/2)
&& mouse_y> y+280 && mouse_y< y+280+(largeur/2))
{
switch (miditable[0][294+cmptfader])
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
  sprintf(string_last_midi_id,"LFO DOWN is Ch: %d Pitch: %d Typ: %s" , miditable[1][294+cmptfader],miditable[2][294+cmptfader],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{
attribute_midi_to_control(294+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else{
if( mouse_released==0 && (FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1))//rajout lock 0.7.6
{
start_time_for_delays[cmptfader]=actual_time;
if(lfo_mode_is[cmptfader]!=2)//down
{
lfo_mode_is[cmptfader]=2;
faders_in_float[cmptfader]=Fader[cmptfader];
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[cmptfader]=1;}
}
else {lfo_mode_is[cmptfader]=0;}
lfo_cycle_is_on[cmptfader]=0;
mouse_released=1;
}
}
}
if(mouse_x>x+(cmptfader*espacement)+105 && mouse_x<x+(cmptfader*espacement)+105+(largeur/2)
&& mouse_y> y+320 && mouse_y< y+320+(largeur/2)&& window_focus_id==906)
{
switch (miditable[0][343+cmptfader])
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
  sprintf(string_last_midi_id,"LFO SAW is Ch: %d Pitch: %d Typ: %s" , miditable[1][343+cmptfader],miditable[2][343+cmptfader],thetypinfo);

if(Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{
attribute_midi_to_control(343+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else{
if(mouse_released==0 && (FaderLocked[cmptfader]==0 || LockFader_is_FullLevel[cmptfader]==1))//rajout lock 0.7.6
{
start_time_for_delays[cmptfader]=actual_time;
faders_in_float[cmptfader]=Fader[cmptfader];
if(lfo_cycle_is_on[cmptfader]==0)//
{
lfo_cycle_is_on[cmptfader]=1;
lfo_mode_is[cmptfader]=0;
lfo_running_is_upward[cmptfader]=1;
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[cmptfader]=1;}
}
else if(lfo_cycle_is_on[cmptfader]==1)
{
lfo_cycle_is_on[cmptfader]=0;
}
mouse_released=1;
}
}
}
if(mouse_x>x+(cmptfader*espacement)+70 && mouse_x<x+(cmptfader*espacement)+70+(largeur/2) &&
mouse_y>y+280 && mouse_y<y+280+(largeur/2))
{
 switch (miditable[0][392+cmptfader])
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
  sprintf(string_last_midi_id,"LFO DOCK MINUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][392+cmptfader],miditable[2][392+cmptfader],thetypinfo);

if(Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{
attribute_midi_to_control(392+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else{
if(mouse_released==0 )
{
if (lfo_do_next_step[cmptfader][0]==0) {lfo_do_next_step[cmptfader][0]=1;lfo_do_next_step[cmptfader][1]=0;}
else if (lfo_do_next_step[cmptfader][0]==1) {lfo_do_next_step[cmptfader][0]=0; }
mouse_released=1;
}
}
}


if(mouse_x>x+(cmptfader*espacement)+70 && mouse_x<x+(cmptfader*espacement)+70+(largeur/2) &&
mouse_y>y+320 && mouse_y<y+320+(largeur/2))
{
switch (miditable[0][441+cmptfader])
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
  sprintf(string_last_midi_id,"LFO DOCK PLUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][441+cmptfader],miditable[2][441+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{

attribute_midi_to_control(441+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else{
if(mouse_released==0 )
{
if (lfo_do_next_step[cmptfader][1]==0) {lfo_do_next_step[cmptfader][1]=1;lfo_do_next_step[cmptfader][0]=0; ;}
else if (lfo_do_next_step[cmptfader][1]==1) {lfo_do_next_step[cmptfader][1]=0; }
mouse_released=1;
}
}
}


if(mouse_x>x+(cmptfader*espacement)+35 && mouse_x<x+(cmptfader*espacement)+35+(largeur/2) && mouse_y>y+320 && mouse_y<y+320+(largeur/2))
{
switch (miditable[0][499+cmptfader])
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
  sprintf(string_last_midi_id,"LFO LOOP STEPS is Ch: %d Pitch: %d Typ: %s" , miditable[1][499+cmptfader],miditable[2][499+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{
attribute_midi_to_control(499+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else{
if(mouse_released==0)
{
lfo_cycle_steps[cmptfader]= toggle(lfo_cycle_steps[cmptfader]);
mouse_released=1;
}
}
}

if(mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+138+(largeur/2) && mouse_y> y+240 && mouse_y< y+240+(largeur/2))
{
switch (miditable[0][802+cmptfader])
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
sprintf(string_last_midi_id,"LFO LOOP ONE is Ch: %d Pitch: %d Typ: %s" , miditable[1][802+cmptfader],miditable[2][802+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0 )
{
if(mouse_released==0 )
{
attribute_midi_to_control(802+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else
{
if(mouse_released==0 )
{
int docktotouch=(dock_used_by_fader_is[cmptfader]);
is_dock_for_lfo_selected[cmptfader][docktotouch]=toggle(is_dock_for_lfo_selected[cmptfader][docktotouch]);
mouse_released=1;
}
}
}
if(mouse_x>x+(cmptfader*espacement)+138 && mouse_x<x+(cmptfader*espacement)+138+(largeur/2)&& mouse_y> y+280 && mouse_y< y+280+(largeur/2))
{
switch (miditable[0][851+cmptfader])
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
sprintf(string_last_midi_id,"LFO LOOP ALL is Ch: %d Pitch: %d Typ: %s" , miditable[1][851+cmptfader],miditable[2][851+cmptfader],thetypinfo);

if( Midi_Faders_Affectation_Type!=0)
{
if(mouse_released==0 )
{
attribute_midi_to_control(851+cmptfader, Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
}
else
{
if(mouse_released==0)
{
bool index_choose_mode_dkloop=0;//0 toggle tt le monde / 1 copie l etat du dck selctionné dans tt le monde

for (int ck=0;ck<core_user_define_nb_docks-1;ck++)
{
if(is_dock_for_lfo_selected[cmptfader][ck]!=is_dock_for_lfo_selected[cmptfader][ck+1])
{index_choose_mode_dkloop=1;break;}
}
switch(index_choose_mode_dkloop)
{
case 0:
for(int op=0;op<core_user_define_nb_docks;op++)
{
 is_dock_for_lfo_selected[cmptfader][op]=toggle(is_dock_for_lfo_selected[cmptfader][op]);
}
break;
case 1:
for(int j=0;j<core_user_define_nb_docks;j++)
{
if(DockIsSelected[cmptfader][j]==1)
{
int tempval_dockloop=toggle(is_dock_for_lfo_selected[cmptfader][j]);
for(int k=0;k<core_user_define_nb_docks;k++)
{
is_dock_for_lfo_selected[cmptfader][k]=toggle(tempval_dockloop);
}
break;
}
}
break;
default: break;
}
mouse_released=1;
}
}
}




}
return(0);
}
