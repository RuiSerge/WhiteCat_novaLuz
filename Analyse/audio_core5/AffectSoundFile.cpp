int AffectSoundFile(int player)
{
index_loading_a_sound_file=1;
sprintf(sound_files[player],audiofile_name);
player_has_file_coming_from_pos[player]=audiofile_selected;

switch(player)
{
case 0:
if(player_is_playing[player]==1){player_ignited[player]=1;player1_do_stop();}
player1=0;
sprintf(soundfile_temp_loader,"audio\\%s\\%s",audio_folder,sound_files[player]);
player1=OpenSound(device,soundfile_temp_loader, index_preloaded_sounds);
if (!player1)
{
sprintf (string_Last_Order,"Can't load Sound %s  !",sound_files[player]);
player_ignited[player]=0; player_is_playing[player]=0;//christoph 11/12/14 bug d.guesdon
}
else
{
player_ignited[player]=1;
if(player_is_playing[player]==1)
{
player1->setPosition(0);player1->play(); }
length_of_file_in_player[player]=(player1->getLength());
player_loop_out_position[player]=length_of_file_in_player[player];
player1->setVolume(((float)player_niveauson[player])/127);
switch(player_is_onloop[player])
 {
 case 0:
 player1->setRepeat(false);
 break;
 case 1:
 player1->setRepeat(true);
 break;
 default: break;
 }
}
break;
case 1:
if(player_is_playing[player]==1){player_ignited[player]=1;player2_do_stop();}
player2=0;
sprintf(soundfile_temp_loader,"audio\\%s\\%s",audio_folder,sound_files[player]);
player2=OpenSound(device,soundfile_temp_loader, index_preloaded_sounds);
if (!player2)
{
sprintf (string_Last_Order,"Can't load Sound %s  !",sound_files[player]);
player_ignited[player]=0;player_is_playing[player]=0;//christoph 11/12/14 bug d.guesdon

}
else {
player_ignited[player]=1;
if(player_is_playing[player]==1)
{
player2->setPosition(0);player2->play();
}
length_of_file_in_player[player]=(player2->getLength());
player_loop_out_position[player]=length_of_file_in_player[player];
player2->setVolume(((float)player_niveauson[player])/127);
switch(player_is_onloop[player])
 {
 case 0:
 player2->setRepeat(false);
 break;
 case 1:
 player2->setRepeat(true);
 break;
 default: break;
 }
}
break;
case 2:
if(player_is_playing[player]==1){player_ignited[player]=1;player3_do_stop();}
player3=0;
sprintf(soundfile_temp_loader,"audio\\%s\\%s",audio_folder,sound_files[player]);
player3=OpenSound(device,soundfile_temp_loader, index_preloaded_sounds);
if (!player3)
{
sprintf (string_Last_Order,"Can't load Sound %s  !",sound_files[player]);
player_ignited[player]=0;player_is_playing[player]=0;//christoph 11/12/14 bug d.guesdon
}
else {
player_ignited[player]=1;
if(player_is_playing[player]==1)
    {
player3->setPosition(0);player3->play();
}
length_of_file_in_player[player]=(player3->getLength());
player_loop_out_position[player]=length_of_file_in_player[player];
player3->setVolume(((float)player_niveauson[player])/127);
switch(player_is_onloop[player])
 {
 case 0:
 player3->setRepeat(false);
 break;
 case 1:
 player3->setRepeat(true);
 break;
 default: break;
 }
}
break;
case 3:
if(player_is_playing[player]==1){player_ignited[player]=1;player4_do_stop();}
player4=0;
sprintf(soundfile_temp_loader,"audio\\%s\\%s",audio_folder,sound_files[player]);
player4=OpenSound(device,soundfile_temp_loader, index_preloaded_sounds);
if (!player4)
{
sprintf (string_Last_Order,"Can't load Sound %s  !",sound_files[player]);
player_ignited[player]=0;player_is_playing[player]=0;//christoph 11/12/14 bug d.guesdon
}
else {
player_ignited[player]=1;
if(player_is_playing[player]==1)
{
player4->setPosition(0);player4->play();
}
length_of_file_in_player[player]=(player4->getLength());
player_loop_out_position[player]=length_of_file_in_player[player];
player4->setVolume(((float)player_niveauson[player])/127);
switch(player_is_onloop[player])
 {
 case 0:
 player4->setRepeat(false);
 break;
 case 1:
 player4->setRepeat(true);
 break;
 default: break;
 }
}
break;
default:
break;
}
if(player_ignited[player]==1)
{
if(audiofile_cue_in_out_pos[audiofile_selected][0]<length_of_file_in_player[player])
{
player_seek_position[player]=audiofile_cue_in_out_pos[audiofile_selected][0];
 if(audiofile_cue_in_out_pos[audiofile_selected][1]>audiofile_cue_in_out_pos[audiofile_selected][0])
 {
 player_loop_out_position[player]=audiofile_cue_in_out_pos[audiofile_selected][1];
        if(player_loop_out_position[player]>length_of_file_in_player[player])
        {
        player_loop_out_position[player]=length_of_file_in_player[player];
        }
  }
}
}
index_loading_a_sound_file=0;//permet le rafraichissement des dixièmes

return(0);
}
