int do_crossfade()
{

if(index_go==0 && index_pause==0 && index_go_back==0)
{
prepare_crossfade();
floatX1=niveauX1;
floatX2=niveauX2;
crossfade_done_time=0;
}

if(index_go==1 && index_pause==0)
{
crossfade_done_time++;
if(actual_time>(crossfade_start_time+crossfade_time_delay_out))
{
floatX1-=fraction_X1_out;
if(floatX1<0){floatX1=0.0;}
niveauX1=(int)floatX1;
crossfade_time_delay_out=0;
}
if(actual_time>(crossfade_start_time+crossfade_time_delay_in))
{
floatX2+=fraction_X2_in;
if(floatX2>255){floatX2=255;}
niveauX2=(int)floatX2;
crossfade_time_delay_in=0;
}
if(niveauX1==0 && niveauX2==255)
{

next_mem_crossfade_finished(position_preset);
refresh_modified_levels_in_crossfade();//modification fleches pdt crossfade
index_go=0;
if(index_auto_mute_cuelist_speed==1 && crossfade_speed!=64)
{is_raccrochage_midi_remote[493]=1; }
if(auto_reset_crossfade_speed_on_link==1 && (Links_Memoires[position_onstage]==0 || index_link_is_on==0 ))
{crossfade_speed=64;}

crossfade_done_time=0;
strcpy(string_time_left_is,"");

if(index_link_speed_crossfade_to_gpl1==1)
{  grid_crossfade_speed[0]=crossfade_speed;
   midi_levels[1508]=crossfade_speed;
}
if(midi_send_out[491]==1){index_send_midi_out[491]=1;}//x1
if(midi_send_out[492]==1){index_send_midi_out[492]=1;}//x2
if(Links_Memoires[position_onstage]==1 && index_link_is_on==1)
{
crossfade_start_time=actual_time;
prepare_crossfade();
floatX1=niveauX1;
floatX2=niveauX2;
index_go=1;
do_send_bang();
if(show_gridplayer_in_seq==1)
{
grid_in_preset[0][0]=index_grider_selected[0];
grid_in_preset[0][1]=set_from_seq_gridplayer1_next_step[position_preset]-1;
if( set_from_seq_gridplayer1_next_step[position_preset]!=-1
&& set_from_seq_gridplayer1_next_step[position_preset]!=index_grider_step_is[0])
{
gridder_prepare_cross(0,index_grider_selected[0],set_from_seq_gridplayer1_next_step[position_preset]-1);
grider_is_playing[0]=1;grid_crossfade_start_time[0]=actual_time;
}
}
}
}
}
if(index_go==1 || index_go_back==1)
{
if(midi_send_out[491]==1){index_send_midi_out[491]=1;}//x1
if(midi_send_out[492]==1){index_send_midi_out[492]=1;}//x2

}


return(0);
}
