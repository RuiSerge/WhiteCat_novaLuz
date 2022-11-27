int do_logical_Echo_Aera(int xe, int ye)
{
if(window_focus_id==W_ECHO)
{

int echochanis=0;
float mouse_y_level=0.0;

for (int sh=0;sh<15;sh++)
{
if( mouse_x>xe+25+(sh*30) && mouse_x<xe+55+(sh*30) && mouse_y>=ye-5 && mouse_y<=ye+135)
{
echochanis=echo_grid_channel_position[echo_selected]+sh;
if(index_enable_edit_echo==1 )
{
dragging_channel_in_echo=1;
mouse_y_level=1.0-((float)constrain_data_to_midi_range(mouse_y-ye))/127.0;
echo_levels[echo_selected][(echo_channel_manipulate_mode[echo_selected])][echochanis]=mouse_y_level;
if(echo_channel_manipulate_mode[echo_selected]==0)
{
tmp_falling_from_level[echo_selected][echochanis]=echo_levels[echo_selected][0][echochanis];
}
record_channel_ch_state_in_an_echo(echo_selected,echochanis);
}
}
}

if(dragging_channel_in_echo==0)
{
if( mouse_x>xe && mouse_x<xe+25 && mouse_y>ye && mouse_y<ye+127 && mouse_released==0 )
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1691,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(echo_grid_channel_position[echo_selected]>0)
{
echo_grid_channel_position[echo_selected]--;
mouse_released=1;
}
}
}
else if( mouse_x>xe+475 && mouse_x<xe+475+25 && mouse_y>ye && mouse_y<ye+127 && mouse_released==0 )
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1692,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(echo_grid_channel_position[echo_selected]<(511-14))
{
echo_grid_channel_position[echo_selected]++;
mouse_released=1;
}
}
}


}
}
return(0);
}
