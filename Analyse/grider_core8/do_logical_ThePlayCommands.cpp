int do_logical_ThePlayCommands(int xb, int yb, int num_grider)
{
if(mouse_y>yb && mouse_y<yb+20 )
{
 if(mouse_x>xb+10 && mouse_x<xb+10+20 )// PLAY GRID
 {
 if(mouse_released==0)
 {
 if(Midi_Faders_Affectation_Type!=0)//config midi
 {
 attribute_midi_solo_affectation(1492+num_grider,Midi_Faders_Affectation_Mode);
 }
 else
 {
 grider_is_playing[num_grider]=toggle(grider_is_playing[num_grider]);
 if(grider_is_playing[num_grider]==1){grid_crossfade_start_time[num_grider]=actual_time;}
 }
 mouse_released=1;
 }
 }
 else if(mouse_x>xb+40 && mouse_x<xb+40+20 )//SEEK GRID
 {
 if(mouse_released==0)
 {
 if( Midi_Faders_Affectation_Type!=0)//config midi
 {
 attribute_midi_solo_affectation(1496+num_grider,Midi_Faders_Affectation_Mode);
 }
 else
 {
 gridplayer_seek(num_grider);
 }
  mouse_released=1;
 }
}


else if(mouse_x>xb+70 && mouse_x<xb+70+20 )//AUTO STOP PLAY GRID
 {
 if(mouse_released==0)
 {
 if(Midi_Faders_Affectation_Type!=0)//config midi
 {
 attribute_midi_solo_affectation(1500+num_grider,Midi_Faders_Affectation_Mode);
 }
 else
 {
 grider_autostopmode[num_grider]=toggle(grider_autostopmode[num_grider]);
 }
 mouse_released=1;
 }
 }
}//fin check y
return(0);
}
