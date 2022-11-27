int do_logical_Draw_Channel_Preset_Title(int xchan, int ychan, int prst_v)
{


 if(window_focus_id==0 && mouse_button==1  && mouse_released==0 && prst_v!=0 )
 {
 if(mouse_y>ychan && mouse_y<ychan+20  )
 {
 //TITRE VIEW
 if(mouse_x> xchan+40 && mouse_x<xchan+40+210)
 {
 if(prst_v>0 && index_type==1 )
 {
 sprintf( channel_view_Name[prst_v],numeric);
 reset_numeric_entry();
 numeric_postext=0;
 mouse_released=1;
 }
 }
 // Mem sel
 else if(mouse_x>  xchan+435 && mouse_x<xchan+435+20)
 {
 if(channel_view_type_of_behaviour[prst_v]!=1){channel_view_type_of_behaviour[prst_v]=1;}
 else{channel_view_type_of_behaviour[prst_v]=0;}
 mouse_released=1;
 }
 // fader sel
 else if(mouse_x>  xchan+460 && mouse_x<xchan+460+20 )
 {
 if(channel_view_type_of_behaviour[prst_v]!=2){channel_view_type_of_behaviour[prst_v]=2;}
 else{channel_view_type_of_behaviour[prst_v]=0;}
 mouse_released=1;
 }

 //All sel
  else if(mouse_x>  xchan+485 && mouse_x<xchan+485+30  )
 {
 channel_view_mode_builder[prst_v]=toggle(channel_view_mode_builder[prst_v]);
 mouse_released=1;
 }

 //do build logique sortie car plantage grave à la reconstruction. il faut garder ca dans la boucle affichage
 } */


 }

 }
