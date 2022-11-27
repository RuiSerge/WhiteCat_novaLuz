int do_audio_midi_function_next_prev_track()//christoph 22/04/14
{
for (int i=0;i<4;i++)
{
if(audio_do_load_midi_prev_file[i]==1)
{
index_loading_a_sound_file=1;
audiofile_selected=player_has_file_coming_from_pos[i]-1;
if(audiofile_selected<1){audiofile_selected=1;}
player_has_file_coming_from_pos[i]=audiofile_selected;
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(i);
}
audio_do_load_midi_prev_file[i]=0;
index_loading_a_sound_file=0;
}
if(audio_do_load_midi_next_file[i]==1)
{
index_loading_a_sound_file=1;
audiofile_selected=player_has_file_coming_from_pos[i]+1;
if(audiofile_selected>=audio_number_total_in_folder){audiofile_selected=audio_number_total_in_folder;}
player_has_file_coming_from_pos[i]=audiofile_selected;
sprintf(audiofile_name,list_audio_files[audiofile_selected]);
if(strcmp (audiofile_name,"")!=0)
{
AffectSoundFile(i);
}
audio_do_load_midi_next_file[i]=0;
index_loading_a_sound_file=0;
}
}


return(0);
}
