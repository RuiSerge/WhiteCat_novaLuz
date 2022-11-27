int logical_plot_symbol_list(int plotx, int ploty)
{


if(window_focus_id==W_PLOT && mouse_button==1 && mouse_released==0 && index_click_inside_relativ_xy==0)
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
 symbol_selected_type++;
 if(symbol_selected_type>max_symbol_type){symbol_selected_type=0;}
 if(index_edit_light_plot==1){change_symbol_type(view_plot_calc_number_is,symbol_selected_type);}
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
  symbol_selected_type--;
  if(symbol_selected_type<0){symbol_selected_type=max_symbol_type;}
  if(index_edit_light_plot==1){change_symbol_type(view_plot_calc_number_is,symbol_selected_type);}
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
symbol_selected_type= 127-((mouse_y-(ploty+30))*2);
if(symbol_selected_type<0){symbol_selected_type=0;}
else if(symbol_selected_type>126){symbol_selected_type=126;}
}
}

if(mouse_x>plotx+40 && mouse_x<plotx+40+105 && mouse_y>ploty+80 && mouse_y<ploty+80+20)
{
index_edit_symbol_plot=toggle(index_edit_symbol_plot);
mouse_released=1;
}
if(mouse_x>plotx+40 && mouse_x<plotx+40+80 && mouse_y>ploty+110 && mouse_y<ploty+110+20)
{
 if(Midi_Faders_Affectation_Type!=0)
 {
 attribute_midi_solo_affectation(1600,Midi_Faders_Affectation_Mode);
 }
 else
 {
 add_a_symbol_to_plot(view_plot_calc_number_is);
 }
 mouse_released=1;
}



if(index_edit_symbol_plot==1 )
{

if( mouse_x>=plotx+10 && mouse_x<=plotx+10+185 && mouse_y>ploty+5 && mouse_y<ploty+5+20 && index_type==1)
{
edit_symbol_name();
plot_generate_appareils_list();
mouse_released=1;
}
else if( mouse_x>=plotx+50 && mouse_x<=plotx+50+50+5 && mouse_y>ploty+40 && mouse_y<ploty+40+10)
{
global_symbol_size=((float)(mouse_x-(plotx+50)))/25;
if(global_symbol_size<0.1){global_symbol_size=0.1;}
if (global_symbol_size>2.0){global_symbol_size=2.0;}
}
else if( mouse_x>=plotx+50 && mouse_x<=plotx+50+50+5 && mouse_y>ploty+65 && mouse_y<ploty+65+10)
{
size_symbol[symbol_selected_type]=((float)(mouse_x-(plotx+50)))/50;
if(size_symbol[symbol_selected_type]<0.1){size_symbol[symbol_selected_type]=0.2;}
if (size_symbol[symbol_selected_type]>1.0){size_symbol[symbol_selected_type]=1.0;}
}
}


if(mouse_x>plotx+130 && mouse_x<plotx+130+65 && mouse_y>ploty+105 && mouse_y<ploty+105+28)
{
symbol_id_to_select=atoi(numeric);
if(symbol_id_to_select>nbre_symbols_on_plot[view_plot_calc_number_is]){symbol_id_to_select=nbre_symbols_on_plot[view_plot_calc_number_is];}
reset_numeric_entry();
numeric_postext=0;
if(symbol_id_to_select>0)
{
symbol_is_selected[view_plot_calc_number_is][symbol_id_to_select]=1;
}
mouse_released=1;
}
}
 return(0);
}
