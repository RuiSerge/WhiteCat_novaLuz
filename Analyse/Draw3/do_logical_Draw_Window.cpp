int do_logical_Draw_Window(int xw,int yw)
{
Rect DrawBrush(Vec2D(xw+180,  yw+12), Vec2D( 50,20));
if(window_focus_id==W_DRAW && dragging_draw==0 && mouse_button==1 && mouse_released==0 && mouse_x> xw+180 && mouse_x<xw+180+50 && mouse_y>yw+12 && mouse_y<yw+12+20)
{
show_type_midi(1658, "Draw Brush Type");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1658,Midi_Faders_Affectation_Mode);
}
else
{
draw_brush_type[draw_preset_selected]=toggle(draw_brush_type[draw_preset_selected]);

switch(draw_brush_type[draw_preset_selected])
{
case 0:
sprintf(string_Last_Order,"DOT brush selected");
break;
case 1:
sprintf(string_Last_Order,"GridPlayer selected");
break;
default:
break;
}
}
mouse_released=1;
}
for(int pr=0;pr<6;pr++)
{
if(window_focus_id==W_DRAW && dragging_draw==0 && mouse_button==1 && mouse_released==0 && mouse_x> xw+240+(pr*58) && mouse_x<xw+240+(pr*58)+50 && mouse_y>yw+12 && mouse_y<yw+12+20)
{
char temp[24];
sprintf(temp,"Draw Preset %d ",pr+1);
show_type_midi(1646+pr, temp);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1646+pr,Midi_Faders_Affectation_Mode);
}
else
{
if(index_main_clear==0)
{
draw_preset_selected=pr;
recalculate_draw_sizes(draw_preset_selected);
}
else
{
if(index_enable_edit_Draw==1)
{
draw_prst_to_clear=pr;
index_ask_confirm=1;
ask_clear_draw_preset=1;
}
}
}
mouse_released=1;
}
}

if(window_focus_id==W_DRAW && mouse_button==1 && mouse_released==0 && mouse_x>xw+20 && mouse_x<xw+20+60 && mouse_y>yw+60 && mouse_y<yw+60+20)
{
show_type_midi(1652, "Draw Mode");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1652,Midi_Faders_Affectation_Mode);
}
else
{
draw_mode[draw_preset_selected]++;
if(draw_mode[draw_preset_selected]>3){draw_mode[draw_preset_selected]=0;}
mouse_released=1;
}
}
if(window_focus_id==W_DRAW && mouse_button==1 && dragging_draw==0)
{
for(int i=0;i<3;i++)
{

if(mouse_released==0 && mouse_x>=xw+311 && mouse_x<=xw+321 && mouse_y>=yw+57+(i*25) && mouse_y<=yw+67+(i*25))
{
midi_send_out[1653+i]=toggle(midi_send_out[1653+i]);
mouse_released=1;
}

if(mouse_x>=xw+175 && mouse_x<=xw+315 && mouse_y>=yw+45+(i*25) && mouse_y<=yw+45+(i*25)+10)
{
char temp[24];
sprintf(temp,"Draw Param %d ",i+1);
show_type_midi(1653+i, temp);
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1653+i,Midi_Faders_Affectation_Mode);
}
else
{
float po=constrain_data_to_midi_range(mouse_x-(xw+175));
 switch(i)
 {
 case 0:
 draw_level_to_do[draw_preset_selected]=po/127;
 break;
 case 1:
 draw_damper_decay_factor[draw_preset_selected]=po/127;
 break;
 case 2:
 draw_ghost_to_do[draw_preset_selected]=po/127;
 break;
 default:
 break;
 }
}
}
}

}

if(window_focus_id==W_DRAW  && mouse_button==1 && mouse_released==0 && mouse_x> xw+400 && mouse_x<xw+400+110 && mouse_y>yw+40 && mouse_y<yw+40+20 )
{
show_type_midi(1657, "Erase Drawing");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1657,Midi_Faders_Affectation_Mode);
}
else
{
draw_erase_drawing(draw_preset_selected);
}
mouse_released=1;
}
if(window_focus_id==W_DRAW  && mouse_button==1 && mouse_released==0 && mouse_x> xw+400 && mouse_x<xw+400+110 && mouse_y>yw+75 && mouse_y<yw+75+20 )
{
draw_channel_recording_mode++;
if(draw_channel_recording_mode>3){draw_channel_recording_mode=0;}
mouse_released=1;
}
if(window_focus_id==W_DRAW && mouse_button==1 && mouse_released==0 && mouse_x>xw+400 && mouse_x<xw+400+110 && mouse_y>yw+100 && mouse_y<yw+100+20  )
{
if(index_affect_draw_to_dock==0)
{
reset_index_actions();
reset_indexs_confirmation();
index_affect_draw_to_dock=1;
}
else
{
reset_index_actions();
}
index_do_dock=index_affect_draw_to_dock;
mouse_released=1;
}




if(window_focus_id==W_DRAW && mouse_button==1 && mouse_released==0 )
{
if( mouse_x> xw+530 && mouse_x<xw+530+50 && mouse_y>yw+40 && mouse_y<yw+40+20)
{
index_enable_edit_Draw=toggle(index_enable_edit_Draw);
mouse_released=1;
}
else if(  index_enable_edit_Draw==1 && mouse_x> xw+550 && mouse_x<xw+550+30 && mouse_y>yw+75 && mouse_y<yw+75+20 )
{
 draw_preset_parameters[draw_preset_selected][0]=atoi(numeric);
 if(draw_preset_parameters[draw_preset_selected][0]<1)
 {draw_preset_parameters[draw_preset_selected][0]=1;}
 else if(draw_preset_parameters[draw_preset_selected][0]>25)
 { draw_preset_parameters[draw_preset_selected][0]=25;}
 recalculate_draw_sizes(draw_preset_selected);
 reset_numeric_entry();
 mouse_released=1;
}
else if( index_enable_edit_Draw==1 && mouse_x> xw+550 && mouse_x<xw+550+30 && mouse_y>yw+100 && mouse_y<yw+100+20 )
{
 draw_preset_parameters[draw_preset_selected][1]=atoi(numeric);
 if(draw_preset_parameters[draw_preset_selected][1]<1)
 {draw_preset_parameters[draw_preset_selected][1]=1;}
 else if(draw_preset_parameters[draw_preset_selected][1]>20)
 { draw_preset_parameters[draw_preset_selected][1]=20;}
 recalculate_draw_sizes(draw_preset_selected);
 reset_numeric_entry();
 mouse_released=1;
}
}


do_logical_Draw_TrackingAera(xw+20,yw+140);

if(window_focus_id==W_DRAW   && mouse_released==0 && mouse_x>= xw+65 && mouse_x<=xw+65+127 && mouse_y>yw+580 && mouse_y<yw+580+10 )
{
show_type_midi(1660, "Sel. TrackingZone X");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1660,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
 midi_levels[1660]=constrain_data_to_midi_range(mouse_x- (xw+65));
}
}

if(window_focus_id==W_DRAW  && mouse_released==0   && mouse_x>= xw+245 && mouse_x<=xw+245+127 && mouse_y>yw+580 && mouse_y<yw+580+10 )
{
show_type_midi(1661, "Sel. TrackingZone Y");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1661,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
 midi_levels[1661]=constrain_data_to_midi_range(mouse_x- (xw+245));
}
}


if(window_focus_id==W_DRAW  && mouse_released==0  && mouse_x>= xw+455 && mouse_x<=xw+455+30 && mouse_y>yw+578 && mouse_y<yw+578+18 )
{
draw_get_gpl[draw_preset_selected]=constrain_int_data_to_this_range(atoi(numeric),1,4);
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}


if(window_focus_id==W_DRAW  && mouse_released==0   && index_enable_edit_Draw==1  && mouse_x>= xw+550 && mouse_x<=xw+550+35 && mouse_y>yw+578 && mouse_y<yw+578+18 && numeric_postext>0)
{
draw_offset_gpl[draw_preset_selected]= constrain_int_data_to_this_range(atoi(numeric),1,512);
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}



  return(0);
}
