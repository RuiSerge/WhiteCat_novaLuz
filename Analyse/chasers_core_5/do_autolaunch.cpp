int do_autolaunch()
{
for (int cmptfader=0;cmptfader<48;cmptfader++)
{
  //autolaunch embedded
  if(autolaunch[cmptfader]==1   )
  {

    if(( Fader[cmptfader]!=Fader_previous[cmptfader]) || ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] ) )
   {


   //commande embeded
   int the_chaser;
   int the_grid_player;
   int the_audio_player;
        switch(DockTypeIs[cmptfader][dock_used_by_fader_is[cmptfader]])
        {
        case 6://vol
        the_audio_player=DockHasAudioVolume[cmptfader][dock_used_by_fader_is[cmptfader]]-1;

if(player_ignited[the_audio_player]==1)
{
switch(the_audio_player)
{
case 0://PLAYER 1
if  (Fader[cmptfader]==0)
{
player1->stop();
if(player_is_onloopCue[0]==0  ){player1->setPosition(0);}
else
{player1->setPosition(player_seek_position[0]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] ))  player1->play();
break;
case 1://player 2
if  (Fader[cmptfader]==0)
{
player2->stop();
if(player_is_onloopCue[1]==0  ){player2->setPosition(0);}
else
{player2->setPosition(player_seek_position[1]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player2->play();
break;
case 2://player 3
if  (Fader[cmptfader]==0)
{
player3->stop();
if(player_is_onloopCue[2]==0  ){player1->setPosition(0);}
else
{player3->setPosition(player_seek_position[2]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player3->play();
break;
case 3://PLAYER 4
if  (Fader[cmptfader]==0)
{
player4->stop();
if(player_is_onloopCue[3]==0  ){player4->setPosition(0);}
else
{player4->setPosition(player_seek_position[3]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player4->play();
break;
default: break;
}
}
break;
case 7://pan
the_audio_player=DockHasAudioPan[cmptfader][dock_used_by_fader_is[cmptfader]]-1;
if(player_ignited[the_audio_player]==1)
{
switch(the_audio_player)
{
case 0://PLAYER 1
if  (Fader[cmptfader]==0)
{
player1->stop();
if(player_is_onloopCue[0]==0  ){player1->setPosition(0);}
else
{player1->setPosition(player_seek_position[0]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] ))  player1->play();
break;
case 1://player 2
if  (Fader[cmptfader]==0)
{
player2->stop();
if(player_is_onloopCue[1]==0  ){player2->setPosition(0);}
else
{player2->setPosition(player_seek_position[1]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player2->play();
break;
case 2://player 3
if  (Fader[cmptfader]==0)
{
player3->stop();
if(player_is_onloopCue[2]==0  ){player1->setPosition(0);}
else
{player3->setPosition(player_seek_position[2]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player3->play();
break;
case 3://PLAYER 4
if  (Fader[cmptfader]==0)
{
player4->stop();
if(player_is_onloopCue[3]==0  ){player4->setPosition(0);}
else
{player4->setPosition(player_seek_position[3]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player4->play();
break;
default: break;
}
}
        break;
        case 8://pitch
        the_audio_player=DockHasAudioPitch[cmptfader][dock_used_by_fader_is[cmptfader]]-1;

if(player_ignited[the_audio_player]==1)
{
switch(the_audio_player)
{
case 0://PLAYER 1
if  (Fader[cmptfader]==0)
{
player1->stop();
if(player_is_onloopCue[0]==0  ){player1->setPosition(0);}
else
{player1->setPosition(player_seek_position[0]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] ))  player1->play();
break;
case 1://player 2
if  (Fader[cmptfader]==0)
{
player2->stop();
if(player_is_onloopCue[1]==0  ){player2->setPosition(0);}
else
{player2->setPosition(player_seek_position[1]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player2->play();
break;
case 2://player 3
if  (Fader[cmptfader]==0)
{
player3->stop();
if(player_is_onloopCue[2]==0  ){player1->setPosition(0);}
else
{player3->setPosition(player_seek_position[2]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player3->play();
break;
case 3://PLAYER 4
if  (Fader[cmptfader]==0)
{
player4->stop();
if(player_is_onloopCue[3]==0  ){player4->setPosition(0);}
else
{player4->setPosition(player_seek_position[3]);}
}
if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )) player4->play();
break;
default: break;
}
}
        break;
case 11://chasers
        the_chaser=ChaserAffectedToDck[cmptfader][dock_used_by_fader_is[cmptfader]];
        if  (Fader[cmptfader]==0) {chaser_is_playing[the_chaser]=0; chaser_seek_at_beg(the_chaser); }
        if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 ) || ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] )){chaser_is_playing[the_chaser]=1; }
break;
case 12://gridplayer
the_grid_player=faders_dock_grid_affectation[cmptfader][dock_used_by_fader_is[cmptfader]];
 if  (Fader[cmptfader]==0)
 {
 grider_is_playing[the_grid_player]=0;
 gridplayer_seek(the_grid_player);
 }
 if((Fader_previous[cmptfader]==0 && Fader[cmptfader]>0 )|| ( previous_dock_used[cmptfader]!=dock_used_by_fader_is[cmptfader] ))
 {grider_is_playing[the_grid_player]=1;grid_crossfade_start_time[the_grid_player]=actual_time;}
break;
default:
break;
       }
   }
   }

Fader_previous[cmptfader]=Fader[cmptfader];
previous_dock_used[cmptfader]=dock_used_by_fader_is[cmptfader];
}

 return(0);
}
