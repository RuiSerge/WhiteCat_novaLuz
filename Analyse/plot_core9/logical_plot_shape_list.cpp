int logical_plot_shape_list(int plotx, int ploty)
{


if(window_focus_id==W_PLOT && mouse_button==1 && mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0)
{

if( mouse_x>plotx+12 && mouse_x<plotx+28)
{
 if(mouse_y>ploty+36 && mouse_y<ploty+50) //UP
 {
 if( Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1597,Midi_Faders_Affectation_Mode);
 }
 else
 {
 shape_selected_type++;
 if(shape_selected_type>max_shape_type){shape_selected_type=0;}
    if(index_edit_light_plot==1){change_shape_type(shape_selected_type);}
    refresh_shape_factors(shape_selected_type);
 }
   mouse_released=1;
 }
 else if(  mouse_y>ploty+69 && mouse_y<ploty+83) //DOWN
 {
 if(Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1598,Midi_Faders_Affectation_Mode);
 }
 else
 {
  shape_selected_type--;
  if(shape_selected_type<0){shape_selected_type=max_shape_type;}
   if(index_edit_light_plot==1){change_shape_type(shape_selected_type);}
   refresh_shape_factors(shape_selected_type);
  }
  mouse_released=1;
 }
}


if( mouse_x>=plotx+3 && mouse_x<=plotx+8 && mouse_y>=ploty+26 && mouse_y<ploty+30+70)
{

if(Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1599,Midi_Faders_Affectation_Mode);
 mouse_released=1;
 }
 else
 {
set_mouse_range(plotx+3,ploty+26 , plotx+8, ploty+30+70);//pour pas deborder
shape_selected_type= (64-(mouse_y-(ploty+30)))/6;
if(shape_selected_type<0){shape_selected_type=0;}
else if(shape_selected_type>max_shape_type){shape_selected_type=max_shape_type;}
 }
}

if( mouse_x>plotx+40 && mouse_x<plotx+40+80 && mouse_y>ploty+110 && mouse_y<ploty+110+20)
{

 if(Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1600,Midi_Faders_Affectation_Mode);
 }
 else
 {
 add_shape_to_plot(shape_selected_type);
 }
mouse_released=1;
}
if(mouse_x>plotx+130 && mouse_x<plotx+130+65 && mouse_y>ploty+105 && mouse_y<ploty+105+28)
{
shape_id_to_select=atoi(numeric);
if(shape_id_to_select>nbre_shapes_on_plot){shape_id_to_select=nbre_shapes_on_plot;}
reset_numeric_entry();
numeric_postext=0;
if(shape_id_to_select>0)
{
shape_selected[shape_id_to_select]=1;
index_last_shape_selected=shape_id_to_select;
if(shape_groups[index_last_shape_selected]!=0)
{
for(int gr=0;gr<nbre_shapes_on_plot+1 ;gr++)
{
if(shape_groups[gr]==shape_groups[index_last_shape_selected])
{shape_selected[gr]=shape_selected[index_last_shape_selected];}
}
}



}
mouse_released=1;
}


}
 return(0);
}
