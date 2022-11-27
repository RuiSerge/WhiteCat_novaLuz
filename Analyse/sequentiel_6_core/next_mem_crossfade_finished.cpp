int next_mem_crossfade_finished(int mem_is_now_onstage)
{
position_onstage=mem_is_now_onstage;
for (int a=0;a<514;a++)
{
bufferSaisie[a]=bufferBlind[a];
}
detect_mem_preset();
refresh_mem_onpreset(position_preset);
detect_mem_before_one();
niveauX1=255; niveauX2=0;
if(midi_send_out[493]==1){index_send_midi_out[493]=1;}
someone_changed_in_sequences=1;//icat
return(0);
}
