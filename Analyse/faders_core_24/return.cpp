return(0);
{
int calcul_lock=0;

for (int cm=0;cm<2;cm++)
{
 for (int ll=0;ll<4;ll++)
 {

 calcul_lock=cm+(2*ll);

 if(mouse_x>xf+(cm*55)-5 && mouse_x<xf+(cm*55)+40 && mouse_y>yf+(ll*55) && mouse_y<yf+(ll*55)+45)
 {


 //midi report
 switch(miditable[0][605+calcul_lock])
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
  sprintf(string_last_midi_id,"Lock Preset %d is Ch: %d Pitch: %d Type: %s",calcul_lock+1, miditable[1][605+calcul_lock],miditable[2][605+calcul_lock],thetypinfo);

 //config midi
  if( Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_to_control(605+calcul_lock,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
 mouse_released=1;

 }
 else
 {

 if(index_do_dock==1)
 {
 for(int f=0;f<core_user_define_nb_faders;f++)
 {
 FaderLocked_Preset[calcul_lock][f]=0;        //reset des états avant stockage
 StateOfFaderBeforeLock_Preset[calcul_lock][f]=0;
 LockFader_is_FullLevel_Preset[calcul_lock][f]=0;
 if ( FaderLocked[f]==1)
 {
 FaderLocked_Preset[calcul_lock][f]=FaderLocked[f];
 StateOfFaderBeforeLock_Preset[calcul_lock][f]=StateOfFaderBeforeLock[f];
 LockFader_is_FullLevel_Preset[calcul_lock][f]=LockFader_is_FullLevel[f];
 }
 }
 //extinction des autres
 for (int ipo=0;ipo<8;ipo++)
 {lock_preset[ipo]=0;}
 lock_preset[calcul_lock]=1;

 index_do_dock=0;
 sprintf(string_Last_Order,">> Lock State %d recorded",calcul_lock+1);
 }
 else  if(index_main_clear==1)
 {

 reset_indexs_confirmation();
 lock_preset_selected_for_record=calcul_lock;
 index_do_clear_lock_preset=1;
 index_ask_confirm=1;
 sprintf(string_Last_Order,">> Lock State %d cleared",calcul_lock+1);
 }
 else
 {
 do_lock_preset(calcul_lock);
 sprintf(string_Last_Order,">> Lock State %d called ",calcul_lock+1);
 }
 mouse_released=1;
 }
 }


}
}

return(0);
}
