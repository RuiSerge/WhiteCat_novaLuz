int sound_core_processing()
{

for(int lect=0;lect<4;lect++)
{
if(player_ignited[lect]==1)
{

switch(lect)
 {
 case 0:
 position_of_file_in_player[lect]=(player1->getPosition());
 show_pitch_value[lect]=(player1->getPitchShift());
 show_pan_value[lect]=(player1->getPan());
 show_player_niveauson[lect]=(player1->getVolume());
 player_is_playing[lect]=(player1->isPlaying());
 break;
 case 1:
 position_of_file_in_player[lect]=(player2->getPosition());
 show_pitch_value[lect]=(player2->getPitchShift());
 show_pan_value[lect]=(player2->getPan());
 show_player_niveauson[lect]=(player2->getVolume());
 player_is_playing[lect]=(player2->isPlaying());
 break;
 case 2:
 position_of_file_in_player[lect]=(player3->getPosition());
 show_pitch_value[lect]=(player3->getPitchShift());
 show_pan_value[lect]=(player3->getPan());
 show_player_niveauson[lect]=(player3->getVolume());
 player_is_playing[lect]=(player3->isPlaying());
 break;
 case 3:
 position_of_file_in_player[lect]=(player4->getPosition());
 show_pitch_value[lect]=(player4->getPitchShift());
 show_pan_value[lect]=(player4->getPan());
 show_player_niveauson[lect]=(player4->getVolume());
 player_is_playing[lect]=(player4->isPlaying());
 break;
 default:
 break;
}

if( player_is_onloop[lect]==1 && player_is_playing[lect]==1 )
{
 if(player_is_onloopCue[lect]==0  && position_of_file_in_player[lect]>=length_of_file_in_player[lect] )
 {//loop  GENERAL
 switch(lect)
 {
 case 0:
 player1->setPosition(0);
 break;
  case 1:
 player2->setPosition(0);
 break;
 case 2:
 player3->setPosition(0);
 break;
 case 3:
 player4->setPosition(0);
 break;
 default:
 break;
 }
 }
 else if( player_is_onloopCue[lect]==1 && position_of_file_in_player[lect]>=player_loop_out_position[lect])
 {//loop out point to inpoint
 switch(lect)
 {
 case 0:
 player1->setPosition(player_seek_position[lect]);
 break;
 case 1:
 player2->setPosition(player_seek_position[lect]);
 break;
 case 2:
 player3->setPosition(player_seek_position[lect]);
 break;
 case 3:
 player4->setPosition(player_seek_position[lect]);
 break;
 default:
 break;
 }
 }
 }

if( player_is_onloop[lect]==0)
{
if(position_of_file_in_player[lect]>=length_of_file_in_player[lect])
{
if(audio_autoload[lect]==0 && audio_autopause[lect]==0)//comportement normal
{
 switch(lect)
 {
 case 0:
 player1_do_stop();
 break;
 case 1:
 player2_do_stop();
 break;
 case 2:
 player3_do_stop();
 break;
 case 3:
 player4_do_stop();
 break;
 default:
 break;
 }
 if(player_is_onloopCue[lect]==0 )
 {//loop  GENERAL
                 switch(lect)
                  {
                  case 0:
                  player1->setPosition(0);
                  break;
                  case 1:
                  player2->setPosition(0);
                  break;
                  case 2:
                  player3->setPosition(0);
                  break;
                  case 3:
                  player4->setPosition(0);
                  break;
                  default:
                  break;
                  }
                }
                else if( player_is_onloopCue[lect]==1 )
                {
                //loop out point to inpoint
                switch(lect)
                {
                case 0:
                player1->setPosition(player_seek_position[lect]);
                break;
                case 1:
                player2->setPosition(player_seek_position[lect]);
                break;
                case 2:
                player3->setPosition(player_seek_position[lect]);
                break;
                case 3:
                player4->setPosition(player_seek_position[lect]);
                break;
                default:
                break;
                }
                }
}
else if(audio_autopause[lect]==1)//autostop
{
 switch(lect)
 {
 case 0:
 player1_do_stop();
 break;
 case 1:
 player2_do_stop();
 break;
 case 2:
 player3_do_stop();
 break;
 case 3:
 player4_do_stop();
 break;
 default:
 break;
 }
}

if(audio_autoload[lect]==1)//chargement auto
{
 switch(lect)
 {
 case 0:
 player1_do_stop();
 break;
 case 1:
 player2_do_stop();
 break;
 case 2:
 player3_do_stop();
 break;
 case 3:
 player4_do_stop();
 break;
 default:
 break;
 }
audiofile_selected=player_has_file_coming_from_pos[lect]+1;
if(audiofile_selected>=127){audiofile_selected=126;}
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(lect);
if(audio_autopause[lect]==0)//autostop
{
 switch(lect)
 {
 case 0:
 player1->play();
 break;
 case 1:
 player2->play();
 break;
 case 2:
 player3->play();
 break;
 case 3:
 player4->play();
 break;
 default:
 break;
 }
}
else//autostop
{
 switch(lect)
 {
 case 0:
 //player1->stop();
 player1_do_stop();
 break;
 case 1:
 //player2->stop();
 player2_do_stop();
 break;
 case 2:
 //player3->stop();
 player3_do_stop();
 break;
 case 3:
 //player4->stop();
 player4_do_stop();
 break;
 default:
 break;
 }
}
}

}

}
}
}
}

 return(0);
}
