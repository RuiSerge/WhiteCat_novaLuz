int midi_send_faders_button_logical(int Xb, int Yb, int id_window)
{
if(window_focus_id==id_window)
{
if(mouse_x>Xb && mouse_x<Xb+60 && mouse_y>Yb && mouse_y<Yb+20 && mouse_released==0)
   {
    //config midi
 if(Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1593,Midi_Faders_Affectation_Type);
 mouse_released=1;
 }
 else
 {
 index_global_midi_send_on_faders=toggle(index_global_midi_send_on_faders);
 set_all_faders_midi_out(index_global_midi_send_on_faders);
 do_light_midi_send_on_faders=1;
 mouse_released=1;
 }
}
}
return(0);
}
