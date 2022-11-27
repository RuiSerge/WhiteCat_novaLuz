int do_logical_Touche_Midi_Mute(int xmute, int ymute)
{

 if(mouse_x>xmute && mouse_x<xmute+(90*size_faders) && mouse_y>ymute && mouse_y<ymute+25 && mouse_released==0)
 {
 index_midi_mute=toggle(index_midi_mute);
 if(index_midi_mute==1){sprintf(string_Last_Order,">>Midi IN muted");}
 else {sprintf(string_Last_Order,">>Midi IN un-muted");}
 mouse_released=1;
 }

return(0);
}
