int do_logical_lecteur_audio( int xp, int yp, int numero)
{

if(mouse_x>xp && mouse_x<xp+200 && mouse_y>yp && mouse_y<yp+20)
{
AffectSoundFile(numero);
mouse_released=1;
}


if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp+30 && mouse_y<yp+30+20)
{

  if (miditable[0][628+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][628+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][628+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][628+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"Play Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][628+numero],miditable[2][628+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(628+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {

if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 switch(player1->isPlaying())
 {
 case 0:
 player1->play();
 break;
 case 1:
 //player1->stop();
 player1_do_stop();
 break;
 default: break;
 }
break;
case 1://PLAYER 2
 switch(player2->isPlaying())
 {
 case 0:
 player2->play();
 break;
 case 1:
 //player2->stop();
 player2_do_stop();
 break;
 default: break;
 }
break;
case 2://PLAYER 3
 switch(player3->isPlaying())
 {
 case 0:
 player3->play();
 break;
 case 1:
 //player3->stop();
 player3_do_stop();
 break;
 default: break;
 }
break;
case 3://PLAYER 4
 switch(player4->isPlaying())
 {
 case 0:
 player4->play();
 break;
 case 1:
 //player4->stop();
 player4_do_stop();
 break;
 default: break;
 }
break;
default: break;
}
}
 mouse_released=1;
}
}




if(mouse_x>xp+25 && mouse_x<xp+45 && mouse_y>yp+30 && mouse_y<yp+30+20)
{

  if (miditable[0][628+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][628+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][628+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][628+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"Play Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][632+numero],miditable[2][632+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(632+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 player1->setPosition(0);
break;
case 1://PLAYER 2
 player2->setPosition(0);
break;
case 2://PLAYER 3
 player3->setPosition(0);
break;
case 3://PLAYER 4
 player4->setPosition(0);
break;
default: break;
}
}
 mouse_released=1;
}
}





if(mouse_x>xp+50 && mouse_x<xp+70 && mouse_y>yp+30 && mouse_y<yp+30+20)
{

  if (miditable[0][636+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][636+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][636+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][636+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"Loop Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][636+numero],miditable[2][636+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(636+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else {

if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 switch(player1-> getRepeat())
 {
 case 0:
 player1->setRepeat(true);
 player_is_onloop[numero]=1;
 break;
 case 1:
 player1->setRepeat(false);
 player_is_onloop[numero]=0;
 break;
 default: break;
 }
break;
case 1://PLAYER 2
 switch(player2-> getRepeat())
 {
 case 0:
 player2->setRepeat(true);
 player_is_onloop[numero]=1;
 break;
 case 1:
 player2->setRepeat(false);
 player_is_onloop[numero]=0;
 break;
 default: break;
 }
break;
case 2://PLAYER 3
 switch(player3-> getRepeat())
 {
 case 0:
 player3->setRepeat(true);
 player_is_onloop[numero]=1;
 break;
 case 1:
 player3->setRepeat(false);
 player_is_onloop[numero]=0;
 break;
 default: break;
 }
break;
case 3://PLAYER 4
 switch(player4-> getRepeat())
 {
 case 0:
 player4->setRepeat(true);
 player_is_onloop[numero]=1;
 break;
 case 1:
 player4->setRepeat(false);
 player_is_onloop[numero]=0;
 break;
 default: break;
 }
break;
default: break;
}
mouse_released=1;
}
}
}



if(mouse_x>xp+75 && mouse_x<xp+75+20 && mouse_y>yp+30 && mouse_y<yp+30+20)
{

  if (miditable[0][1821+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][1821+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][1821+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][1821+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"SeekToEnd %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][1821+numero],miditable[2][1821+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(1821+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(player_ignited[numero]==1 && index_loading_a_sound_file==0)
{
switch(numero)
{
case 0://PLAYER 1
player1->setPosition(length_of_file_in_player[numero]-1000);
break;
case 1://PLAYER 2
 player2->setPosition(length_of_file_in_player[numero]-1000);
break;
case 2://PLAYER 3
 player3->setPosition(length_of_file_in_player[numero]-1000);
break;
case 3://PLAYER 4
 player4->setPosition(length_of_file_in_player[numero]-1000);
break;
default:
break;
}
}
 mouse_released=1;
}
}




if(mouse_x>xp && mouse_x<xp+28 && mouse_y>yp+60 && mouse_y<yp+60+16)
{

  if (miditable[0][640+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][640+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][640+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][640+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"Backward Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][640+numero],miditable[2][640+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(640+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {

   if(player_ignited[numero]==1 && position_of_file_in_player[numero]-100000>0)
   {
   switch(numero)
   {
   case 0://PLAYER 1
    player1->setPosition(position_of_file_in_player[numero]-100000);
    break;
    case 1://PLAYER 2
    player2->setPosition(position_of_file_in_player[numero]-100000);
    break;
    case 2://PLAYER 3
    player3->setPosition(position_of_file_in_player[numero]-1000000);
    break;
    case 3://PLAYER 4
    player4->setPosition(position_of_file_in_player[numero]-100000);
    break;
    default: break;
   }
   mouse_released=1;
   }

}
}

if(mouse_x>xp+35 && mouse_x<xp+35+28 && mouse_y>yp+60 && mouse_y<yp+60+16)
{

  if (miditable[0][644+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][644+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][644+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][644+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"Forward Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][644+numero],miditable[2][644+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{

attribute_midi_solo_affectation(644+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {

   if(player_ignited[numero]==1 && position_of_file_in_player[numero]+100000<length_of_file_in_player[numero])
   {
   switch(numero)
   {
   case 0://PLAYER 1
    player1->setPosition(position_of_file_in_player[numero]+100000);
    break;
    case 1://PLAYER 2
    player2->setPosition(position_of_file_in_player[numero]+100000);
    break;
    case 2://PLAYER 3
    player3->setPosition(position_of_file_in_player[numero]+100000);
    break;
    case 3://PLAYER 4
    player4->setPosition(position_of_file_in_player[numero]+100000);
    break;
    default: break;
   }
   mouse_released=1;
   }

}
}


if(mouse_x>xp && mouse_x<xp+45 && mouse_y>yp+85 && mouse_y<yp+85+16)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1813+numero,Midi_Faders_Affectation_Mode);
}
else
{
audiofile_selected=player_has_file_coming_from_pos[numero]-1;
if(audiofile_selected<1){audiofile_selected=1;}
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(numero);
}
}
mouse_released=1;
}


if(mouse_x>xp+50 && mouse_x<xp+50+45 && mouse_y>yp+85 && mouse_y<yp+85+16)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1817+numero,Midi_Faders_Affectation_Mode);
}
else
{
audiofile_selected=player_has_file_coming_from_pos[numero]+1;
if(audiofile_selected>=127){audiofile_selected=126;}
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(numero);
}
}
mouse_released=1;
}


if(mouse_x>xp+70 && mouse_x<xp+70+40 && mouse_y>yp+55 && mouse_y<yp+55+25)
{
 if (miditable[0][1809+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][1809+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][1809+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][1809+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"LOAD FILE Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][1809+numero],miditable[2][1809+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1809+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(numeric_postext==0)
{
audiofile_selected=player_has_file_coming_from_pos[numero]+1;
if(audiofile_selected>=127){audiofile_selected=126;}
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(numero);
}
}
else if(numeric_postext>0)
{
int nu=atoi(numeric);
if(nu<127  && nu>0)
{
audiofile_selected=nu;
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(numero);
}
reset_numeric_entry();numeric_postext=0;
}
}
}
mouse_released=1;
}







if(mouse_x>xp && mouse_x<xp+28 && mouse_y>yp+110 && mouse_y<yp+110+16)
{
 if (miditable[0][1800+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][1800+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][1800+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][1800+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"AUTOLOAD Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][1800+numero],miditable[2][1800+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(1800+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else
{
audio_autoload[numero]=toggle(audio_autoload[numero]);
mouse_released=1;
}
}


if(mouse_x>xp+35 && mouse_x<xp+35+40 && mouse_y>yp+110 && mouse_y<yp+110+16)
{
 if (miditable[0][1805+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][1805+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][1805+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][1805+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"AUTOSTOP Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][1805+numero],miditable[2][1805+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(1805+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
audio_autopause[numero]=toggle(audio_autopause[numero]);
mouse_released=1;
}
}



if(mouse_x>xp+210 && mouse_x<xp+240 && mouse_y>yp && mouse_y<yp+20)
{

  if (miditable[0][648+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][648+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][648+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][648+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"SetCueIn Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][648+numero],miditable[2][648+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(648+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else {
if(index_edit_audio==1 )
{
if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
if(index_main_clear==0)
{
player_seek_position[numero]=(player1->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}

}
else  if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_seek_position[numero]=0;index_main_clear=0;}
break;
case 1://PLAYER 2
if(index_main_clear==0)
{
player_seek_position[numero]=(player2->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else  if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_seek_position[numero]=0;index_main_clear=0;}
break;
case 2://PLAYER 3
if(index_main_clear==0)
{
player_seek_position[numero]=(player3->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else  if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_seek_position[numero]=0;index_main_clear=0;}
break;
case 3://PLAYER 4
if(index_main_clear==0)
{
player_seek_position[numero]=(player4->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else  if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_seek_position[numero]=0;index_main_clear=0;}
break;
default: break;
}
audiofile_cue_in_out_pos[(player_has_file_coming_from_pos[numero])][0]=player_seek_position[numero];
}
 mouse_released=1;
}
}
}


if(mouse_x>xp+235 && mouse_x<xp+255 && mouse_y>yp && mouse_y<yp+20)
{

  if (miditable[0][652+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][652+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][652+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][652+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"SetCueOut Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][652+numero],miditable[2][652+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(652+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {
if(index_edit_audio==1 )
{
if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
if(index_main_clear==0)
{
player_loop_out_position[numero]=(player1->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_loop_out_position[numero]=(player1->getLength());}
break;
case 1://PLAYER 2
if(index_main_clear==0)
{
player_loop_out_position[numero]=(player2->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else if(player_loop_out_position[numero]!=player_seek_position[numero])  {player_loop_out_position[numero]=(player2->getLength());}
break;
case 2://PLAYER 3
if(index_main_clear==0)
{
player_loop_out_position[numero]=(player3->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else if(player_loop_out_position[numero]!=player_seek_position[numero])  {player_loop_out_position[numero]=(player3->getLength());}
break;
case 3://PLAYER 4
if(index_main_clear==0)
{
player_loop_out_position[numero]=(player4->getPosition());
if(player_loop_out_position[numero]<=player_seek_position[numero]){player_loop_out_position[numero]=player_seek_position[numero]+1;}
}
else  if(player_loop_out_position[numero]!=player_seek_position[numero]) {player_loop_out_position[numero]=(player4->getLength());}
break;
default: break;
}
audiofile_cue_in_out_pos[(player_has_file_coming_from_pos[numero])][1]=player_loop_out_position[numero];
}
mouse_released=1;
}
}
}

if(mouse_x>xp+260 && mouse_x<xp+280 && mouse_y>yp && mouse_y<yp+20)
{


  if (miditable[0][656+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][656+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][656+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][656+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"SetCueOut Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][656+numero],miditable[2][656+numero],thetypinfo);
if(Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(656+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else {
if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 switch(player1-> getRepeat())
 {
 case 0:
 player1->setRepeat(true);
 player_is_onloopCue[numero]=1;
 break;
 case 1:
 player1->setRepeat(false);
 player_is_onloopCue[numero]=0;
 break;
 default: break;
 }
break;
case 1://PLAYER 2
 switch(player2-> getRepeat())
 {
 case 0:
 player2->setRepeat(true);
 player_is_onloopCue[numero]=1;
 break;
 case 1:
 player2->setRepeat(false);
 player_is_onloopCue[numero]=0;
 break;
 default: break;
 }
break;
case 2://PLAYER 3
 switch(player3-> getRepeat())
 {
 case 0:
 player3->setRepeat(true);
 player_is_onloopCue[numero]=1;
 break;
 case 1:
 player3->setRepeat(false);
 player_is_onloopCue[numero]=0;
 break;
 default: break;
 }
break;
case 3://PLAYER 4
 switch(player4-> getRepeat())
 {
 case 0:
 player4->setRepeat(true);
 player_is_onloopCue[numero]=1;
 break;
 case 1:
 player4->setRepeat(false);
 player_is_onloopCue[numero]=0;
 break;
 default: break;
 }
break;
default: break;
}
}
 mouse_released=1;
}
}


if(mouse_x>xp+210 && mouse_x<xp+230 && mouse_y>yp+30 && mouse_y<yp+50)
{

  if (miditable[0][660+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][660+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][660+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][660+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"SetCueOut Player %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][660+numero],miditable[2][660+numero],thetypinfo);
if(Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(660+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {

if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 player1->setPosition(player_seek_position[numero]);
break;
case 1://PLAYER 2
 player2->setPosition(player_seek_position[numero]);
break;
case 2://PLAYER 3
 player3->setPosition(player_seek_position[numero]);
break;
case 3://PLAYER 4
 player4->setPosition(player_seek_position[numero]);
break;
default: break;
}
}
 mouse_released=1;
}
}





if(mouse_x>xp+120+player_pitch[numero] && mouse_x<xp+150+player_pitch[numero] && mouse_y>yp+110 && mouse_y<yp+110+10)
{

  if (miditable[0][624+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][624+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][624+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][624+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"PitchPlayer %d  is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][624+numero],miditable[2][624+numero],thetypinfo);
if( Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(624+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else {

if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 player_pitch[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pitch[numero]<1){player_pitch[numero]=1;}
 else if(player_pitch[numero]>127){player_pitch[numero]=127;}
 player1->setPitchShift((((float)player_pitch[numero])/64));
break;
case 1://PLAYER 2
  player_pitch[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pitch[numero]<1){player_pitch[numero]=1;}
 else if(player_pitch[numero]>127){player_pitch[numero]=127;}
 player2->setPitchShift((((float)player_pitch[numero])/64));
break;
case 2://PLAYER 3
  player_pitch[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pitch[numero]<1){player_pitch[numero]=1;}
 else if(player_pitch[numero]>127){player_pitch[numero]=127;}
 player3->setPitchShift((((float)player_pitch[numero])/64));
break;
case 3://PLAYER 4
  player_pitch[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pitch[numero]<1){player_pitch[numero]=1;}
 else if(player_pitch[numero]>127){player_pitch[numero]=127;}
 player4->setPitchShift((((float)player_pitch[numero])/64));
break;
default: break;
}
}
}

midi_levels[624+numero]=player_pitch[numero];
if(midi_send_out[624+numero]==1){ index_send_midi_out[624+numero]=1;}//pitch
}
raccrochage_midi_logical_horizontal_audio (xp+130, yp+100, 620+numero, 127,10);


if(mouse_x>xp+120+player_pan[numero] && mouse_x<xp+150+player_pan[numero] && mouse_y>yp+85 && mouse_y<yp+85+10)
{

  if (miditable[0][620+numero]==0){sprintf(thetypinfo,"Note");}
  if(miditable[0][620+numero]==1){sprintf(thetypinfo,"Key On");}
  if (miditable[0][620+numero]==2){sprintf(thetypinfo,"Key Off");}
  if (miditable[0][620+numero]==4){sprintf(thetypinfo,"Ctrl Change");}
  sprintf(string_last_midi_id,"PanPlayer %d is Ch: %d Pitch: %d Typ: %s" , numero, miditable[1][620+numero],miditable[2][620+numero],thetypinfo);
if(Midi_Faders_Affectation_Type!=0)
{
attribute_midi_solo_affectation(620+numero,Midi_Faders_Affectation_Mode);
mouse_released=1;
}

else {
if(player_ignited[numero]==1)
{
switch(numero)
{
case 0://PLAYER 1
 player_pan[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pan[numero]<1){player_pan[numero]=1;}
 else if(player_pan[numero]>127){player_pan[numero]=127;}
 player1->setPan(((float)(player_pan[numero]-64))/63); // -64 /63 OK POUR AVOIR -1.00 +1.00 GAUCHE DROITE
break;
case 1://PLAYER 2
 player_pan[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pan[numero]<1){player_pan[numero]=1;}
 else if(player_pan[numero]>127){player_pan[numero]=127;}
 player2->setPan(((float)(player_pan[numero]-64))/63);
break;
case 2://PLAYER 3
 player_pan[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pan[numero]<1){player_pan[numero]=1;}
 else if(player_pan[numero]>127){player_pan[numero]=127;}
 player3->setPan(((float)(player_pan[numero]-64))/63);
break;
case 3://PLAYER 4
 player_pan[numero]=(mouse_x- (XAudio+5+120))-10 ;
 if(player_pan[numero]<1){player_pan[numero]=1;}
 else if(player_pan[numero]>127){player_pan[numero]=127;}
 player4->setPan(((float)(player_pan[numero]-64))/63);
break;
default: break;
}
}
}
midi_levels[620+numero]=player_pan[numero];
if(midi_send_out[620+numero]==1){ index_send_midi_out[620+numero]=1;}//pan

}

raccrochage_midi_logical_horizontal_audio (xp+130, yp+80, 624+numero, 127,10);
do_logical_fader_niveau_son(xp+290,yp,numero);
return(0);
}
