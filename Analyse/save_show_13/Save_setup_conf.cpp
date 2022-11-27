int Save_setup_conf()
{
FILE *fpi;
if((fpi=fopen("user/general_set_up.txt","w")))//etait wb
{
fprintf(fpi,"#arguments: default step level / level wheel absolute mode / channel check level / dimmer check level / blink on mem change /  midi auto desaffect / dmx view / preloaded sounds / bang stay time\n");
fprintf(fpi,"%d / %d / %d / %d / %d / %d / %d / %d / %.1f /\n",default_step_level, wheellevel_absolutemode, check_channel_level, dimmer_check_level,
                                                             index_blink_change_memories, index_midi_auto_desaffect, dmx_view, index_preloaded_sounds,  default_time_of_the_bang);
fprintf(fpi,"#arguments: autosave time in sec / nbr audioplayers / fader space width /\n");
fprintf(fpi,"%d / %d / %d /\n",automatic_time_for_save, index_nbre_players_visibles, LargeurEspaceFaderSize);
fclose(fpi);
}

sprintf(string_save_load_report[idf],"Saved /general_set_up.txt");
return(0);
}
