int do_goback()
{

if(index_go_back==1 && index_pause==0)
{
crossfade_done_time=0;
crossfade_time_delay_in=0;
crossfade_time_delay_out=0;

floatX1+=fraction_X1_out;
if(floatX1>255){floatX1=255.0;}
niveauX1=(int)floatX1;

floatX2-=fraction_X2_in;
if(floatX2<0){floatX2=0.0;}
niveauX2=(int)floatX2;

if(show_gridplayer_in_seq==1 && set_from_seq_gridplayer1_next_step[position_onstage]!=-1)
{
grider_is_playing[0]=0;
grid_floatX1[0]+=grid_fraction_X1_out[0];
if(grid_floatX1[0]>255.0){grid_floatX1[0]=255.0;}
grid_niveauX1[0]=(int)grid_floatX1[0];
grid_floatX2[0]-=grid_fraction_X2_in[0];
if(grid_floatX2[0]<0.0){grid_floatX2[0]=0.0;}
grid_niveauX2[0]=(int)grid_floatX2[0];
}

if(niveauX1==255 && niveauX2==0)
{
        //crossfade_done_time=0;
        crossfade_done_time--;
        //sab 27/01/2015 fin
strcpy(string_time_left_is,"");

index_go_back=0;
if(index_auto_mute_cuelist_speed==1 && crossfade_speed!=64)
{is_raccrochage_midi_remote[493]=1; }
crossfade_speed=64;
refresh_integrated_gridplayer1();
if(index_link_speed_crossfade_to_gpl1==1)
{  grid_crossfade_speed[0]=crossfade_speed;
   midi_levels[1508]=crossfade_speed;
}
}

}
return(0);
}
