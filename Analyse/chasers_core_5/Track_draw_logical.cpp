int Track_draw_logical(int xp, int yp,int num_track)
{

if(mouse_x>xp && mouse_x<xp+20 && mouse_y>yp && mouse_y<yp+20)
{
char temp_str_tr[72];
sprintf(temp_str_tr,"Chaser Track ON %d",num_track);
show_type_midi(998+num_track,temp_str_tr );
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_to_control(998+num_track, Midi_Faders_Affectation_Type,  Midi_Faders_Affectation_Mode);
}
else
{
if(index_do_dock==0 && index_main_clear==0 && index_do_modify==0 && index_do_report==0 && index_type==0)
{
track_is_on[chaser_selected][num_track]=toggle(track_is_on[chaser_selected][num_track]);

midi_levels[998+num_track]=track_is_on[chaser_selected][num_track]*127;
midi_send_out[998+num_track]=1;
}
if(index_enable_edit_chaser==1)
{
if(index_do_dock==1  && index_main_clear==0 && index_do_modify==0 && index_do_report==0 && index_type==0)
{
chaser_selected_for_record=chaser_selected;
track_selected_for_record=num_track;
index_do_dock_track=1;
index_ask_confirm=1;
}
else if(index_main_clear==0  && index_do_dock==0 && index_do_modify==1 && index_do_report==0 && index_type==0)
{
chaser_selected_for_record=chaser_selected;
track_selected_for_record=num_track;
index_do_modify_track=1;
index_ask_confirm=1;
}
else if(index_main_clear==0  && index_do_dock==0 && index_do_modify==0 && index_do_report==1 && index_type==0)
{
chaser_selected_for_record=chaser_selected;
track_selected_for_record=num_track;
index_do_report_track=1;
index_ask_confirm=1;
}
else if(index_main_clear==1  && index_do_dock==0 && index_do_modify==0 && index_do_report==0 && index_type==0)
{
chaser_selected_for_record=chaser_selected;
track_selected_for_record=num_track;
index_do_clear_track=1;
index_ask_confirm=1;
}
else if(index_main_clear==0  && index_do_dock==0 && index_do_modify==0 && index_do_report==0 && index_type==1)
{
sprintf(chaser_track_name[chaser_selected][num_track],numeric);
reset_numeric_entry();
if(index_text_auto_close==1){index_type=0;}
}
}
mouse_released=1;
}
}



if(mouse_x>=xp+30 && mouse_x<=xp+30+127 && mouse_y>yp && mouse_y<yp+10)
{
char temp_str_tr[72];
sprintf(temp_str_tr,"Chaser Track LEVEL %d",num_track);
show_type_midi(1023+num_track,temp_str_tr );
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_to_control(1023+num_track, Midi_Faders_Affectation_Type,  Midi_Faders_Affectation_Mode);
}
else
{
set_mouse_range(xp+30 ,yp,xp+30 +127 , yp+10);//pour pas deborder
track_level[chaser_selected][num_track]= mouse_x-(Xchasers+30+5);
if(track_level[chaser_selected][num_track]<0){track_level[chaser_selected][num_track]=0;}
if(track_level[chaser_selected][num_track]>127){track_level[chaser_selected][num_track]=127;}
midi_levels[1023+num_track]=track_level[chaser_selected][num_track];
if(midi_send_out[1023+num_track]==1){index_send_midi_out[1023+num_track]=1;}
}
}

if(mouse_x>=xp+180-5 && mouse_x<=xp+180+5 && mouse_y>yp+22-5 && mouse_y<yp+22+5)
{
midi_send_out[1023+num_track]=toggle(midi_send_out[1023+num_track]);
mouse_released=1;
}


raccrochage_midi_logical_horizontal_little (xp+30,yp,1023+num_track, 127, 10);

if(index_enable_edit_chaser==1)
{
for(int chcase=0;chcase<nbre_de_cases_par_track;chcase++)
{
if(mouse_x>xp+170+(chcase*12) && mouse_x<xp+170+(chcase*12)+12 && mouse_y>yp && mouse_y<yp+12)
{
if(chaser_step_operation[chaser_selected][num_track][chcase]!=chaser_operator_is)//si op different on affecte
{chaser_step_operation[chaser_selected][num_track][chcase]=chaser_operator_is;}
else//sinon on toggle on off l operator
{
chaser_step_operation[chaser_selected][num_track][chcase]=0;
}
refresh_launchpad_on_chaser();
mouse_released=1;
}
}
}




if( launchpad_chaser_mode==1)
{
char tmp_str_stp[36];
if(num_track-position_affichage_track_num[chaser_selected]<chaser_midi_rows)
{
for(int chcase=0;chcase<nbre_de_cases_par_track;chcase++)
{
if(mouse_x>xp+170+(chcase*12) && mouse_x<xp+170+(chcase*12)+12 && mouse_y>yp && mouse_y<yp+12)
{
switch(chaser_way[chaser_selected])
{
case 0:
if( chcase>=chaser_step_is[chaser_selected] && chcase<chaser_step_is[chaser_selected]+8 )
{
sprintf(tmp_str_stp,"Step %d Chaser Row %d" ,chcase-chaser_step_is[chaser_selected]+1,num_track-position_affichage_track_num[chaser_selected]+1 );
show_type_midi(1048+(chcase-chaser_step_is[chaser_selected])+((num_track-position_affichage_track_num[chaser_selected])*8), tmp_str_stp);
if(Midi_Faders_Affectation_Type!=0 )//config midi
{
attribute_midi_to_control(1048+(chcase-chaser_step_is[chaser_selected])+((num_track-position_affichage_track_num[chaser_selected])*8), Midi_Faders_Affectation_Type,  Midi_Faders_Affectation_Mode);
}
}
break;
case 1:
if( chcase>chaser_step_is[chaser_selected]-8 && chcase<=chaser_step_is[chaser_selected] )
{
sprintf(tmp_str_stp,"Step %d Chaser Row %d" ,(chcase-(chaser_step_is[chaser_selected]-8)),num_track-position_affichage_track_num[chaser_selected]+1 );
show_type_midi(1048+((chcase-(chaser_step_is[chaser_selected]-8))-1)+((num_track-position_affichage_track_num[chaser_selected])*8), tmp_str_stp);
if(Midi_Faders_Affectation_Type!=0 )//config midi
{
attribute_midi_to_control(1048+((chcase-(chaser_step_is[chaser_selected]-8))-1)+((num_track-position_affichage_track_num[chaser_selected])*8), Midi_Faders_Affectation_Type,  Midi_Faders_Affectation_Mode);
}
}
break;
default: break;
}
}
}
}
}

return(0);
}
