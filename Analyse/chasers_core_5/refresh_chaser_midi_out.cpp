int refresh_chaser_midi_out()
{

midi_levels[995]=(int)(((float)(chaser_begin_step_is[chaser_selected])/36)*127);
index_send_midi_out[995]=1;
midi_levels[996]=(int)(((float)(chaser_end_step_is[chaser_selected])/36)*127);
index_send_midi_out[996]=1;
midi_levels[997]=(int)(((float)(chaser_step_is[chaser_selected])/36)*127);
index_send_midi_out[997]=1;
for(int num_track=0;num_track<23;num_track++)
{
midi_levels[1023+num_track]=track_level[chaser_selected][num_track];
midi_levels[998+num_track]=127*track_is_on[chaser_selected][num_track];
index_send_midi_out[1023+num_track]=1;
index_send_midi_out[998+num_track]=1;
}
midi_levels[980]=chaser_is_in_loop[chaser_selected]*127;

if(chaser_way[chaser_selected]==0)////forward
{midi_levels[981]=127;midi_levels[982]=0;midi_levels[983]=0;}
else if(chaser_way[chaser_selected]==1)//backward
{midi_levels[981]=0;midi_levels[982]=127;midi_levels[983]=0;}

index_send_midi_out[980]=1;
index_send_midi_out[981]=1;
index_send_midi_out[982]=1;
index_send_midi_out[983]=1;
return(0);
}
