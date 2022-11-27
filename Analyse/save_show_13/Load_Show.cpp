int Load_Show()
{
sprintf(rep,"");
rest(10);
sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
chdir (rep);
FILE *fp;
reset_error_on_save_load();
reset_all_bangers();
clear_report_string();
idf=0;

GlobInit();
Load_Window_Conf();

if(specify_who_to_save_load[0]==1)//MEMOIRES/////////////////////////////////
{

save_load_print_to_screen("Loading Memories");
if ((fp=fopen( file_mem_existantes, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_existantes);  b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mem_existantes);
if (fread(MemoiresExistantes, sizeof(bool),mem_existantes_size, fp) !=mem_existantes_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mem_existantes);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mem_existantes);
fclose(fp);
}

idf++;
if ((fp=fopen( file_memories, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_memories);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_memories);
if (fread(Memoires, sizeof(unsigned char), memories_size, fp) != memories_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_memories);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_memories);
fclose(fp);
}
idf++;
if ((fp=fopen(  file_text_mems, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_text_mems);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_text_mems);
if (fread(descriptif_memoires, sizeof(char), text_mems_size, fp) != text_mems_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_text_mems);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_text_mems);
fclose(fp);
}
idf++;
if ((fp=fopen(  file_text_annots, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_text_annots);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_text_annots);
if (fread(annotation_memoires, sizeof(char), text_annots_size, fp) != text_annots_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_text_annots);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_text_annots);
fclose(fp);
}
idf++;

if ((fp=fopen(  file_mem_detruites, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_detruites);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_mem_detruites);
if (fread(MemoiresDetruites, sizeof(bool), mem_deleted_size, fp) != mem_deleted_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mem_detruites);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_mem_detruites);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_mem_exclues, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_exclues);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_mem_exclues);
if (fread(MemoiresExclues, sizeof(bool), mem_exclues_size, fp) != mem_exclues_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mem_exclues);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_mem_exclues);
 fclose(fp);
}
idf++;

Load_Sequenciel_Conf();
idf++;


index_send_midi_out[491]=1;
index_send_midi_out[492]=1;
index_send_midi_out[493]=1;
emit_midi_out();
rest(10);
}


if(specify_who_to_save_load[1]==1)///////MEMOIRES TIMES/////////////////////////
{
if ((fp=fopen(  file_times_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_times_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_times_mem);
if (fread(Times_Memoires, sizeof(float), times_mems_size, fp) != times_mems_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_times_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_times_mem);
 fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[2]==1)/////MEMOIRES LINKS///////////////////////////
{
if ((fp=fopen(  file_link_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_link_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_link_mem);
if (fread(Links_Memoires, sizeof(bool), link_mem_size, fp) != link_mem_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_link_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_link_mem);
 fclose(fp);
}
idf++;
}

if(specify_who_to_save_load[3]==1)/////MEMOIRES BANGER///////////////////////////
{
if ((fp=fopen(  file_banger_call_in_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_banger_call_in_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_banger_call_in_mem);
if (fread( Banger_Memoire, sizeof(int), bang_mem_size, fp) != bang_mem_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_banger_call_in_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_banger_call_in_mem);
 fclose(fp);
}
idf++;
}

if(specify_who_to_save_load[4]==1)/////MEMOIRES ratio manuel////////////////////
{
if ((fp=fopen(  file_manual_ratio_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_manual_ratio_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_manual_ratio_mem);
if (fread(ratio_cross_manuel, sizeof(int), ratio_mem_size, fp) != ratio_mem_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_manual_ratio_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_manual_ratio_mem);
 fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[5]==1)//channels LIST////////////////////
{
if ((fp=fopen(  file_spotlist, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_spotlist);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_spotlist);
if (fread(descriptif_projecteurs, sizeof(char), spotlist_size, fp) !=spotlist_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_spotlist);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_spotlist);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chan_macro_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chan_macro_on);
if (fread(macro_channel_on, sizeof(bool), chan_macro_on_size, fp) !=chan_macro_on_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chan_macro_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chan_macro_on);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chan_macro_reaction, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_reaction);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chan_macro_reaction);
if (fread(channel_macro_reaction, sizeof(int), chan_macro_reaction_size, fp) !=chan_macro_reaction_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chan_macro_reaction);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chan_macro_reaction);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chan_macro_action, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_action);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chan_macro_reaction);
if (fread(channel_macro_action, sizeof(int), chan_macro_action_size, fp) !=chan_macro_action_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chan_macro_action);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chan_macro_action);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chan_macro_val, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_val);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chan_macro_val);
if (fread(channel_macro_val, sizeof(int), chan_macro_val_size, fp) !=chan_macro_val_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chan_macro_val);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chan_macro_val);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chview_ch, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_ch);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chview_ch);
if (fread(Channel_View_ROUTING, sizeof(int), chview_ch_size, fp) !=chview_ch_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chview_ch);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chview_ch);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chview_name, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_name);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chview_name);
if (fread( channel_view_Name, sizeof(char), chview_name_size, fp) !=chview_name_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chview_name);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chview_name);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chview_linktype, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_linktype);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chview_linktype);
if (fread( channel_view_link_type, sizeof(int), chview_linktype_size, fp) !=chview_linktype_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chview_linktype);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chview_linktype);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chview_linkref, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_linkref);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chview_linkref);
if (fread( channel_view_link_ref, sizeof(int), chview_linkref_size, fp) !=chview_linkref_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chview_linkref);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chview_linkref);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chview_view, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_view);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chview_view);
if (fread( Channel_View_MODE, sizeof(bool), chview_view_size, fp) !=chview_view_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chview_view);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chview_view);
 fclose(fp);
}
idf++;


for(int i=0;i<nbre_de_vues_circuits;i++)
{
count_number_of_channels_in_view(i);
}

}

if(specify_who_to_save_load[6]==1)/////Channels Direct Channels/////////////////
{
if ((fp=fopen(  file_direct_channel, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_direct_channel);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",    file_direct_channel);
if (fread(FaderDirectChan, sizeof(int), fader_direct_chan_size, fp) != fader_direct_chan_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_direct_channel);b_report_error[idf]=1;}
else {sprintf(string_save_load_report[idf],"Loaded file %s", file_direct_channel);}
 fclose(fp);
for(int i=0;i<48;i++)
{
for (int j=0;j<6;j++)
{
if(FaderDirectChan[i][j]<1){FaderDirectChan[i][j]=1;}
if(FaderDirectChan[i][j]>512){FaderDirectChan[i][j]=512;}
}
}
}
idf++;
}


if(specify_who_to_save_load[7]==1)/////Channels Freeze/////////////////////////
{
if ((fp=fopen(  file_dofreeze, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dofreeze);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_dofreeze);
if (fread(freeze_array, sizeof(bool), dofreeze_size, fp) !=dofreeze_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dofreeze);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_dofreeze);
 fclose(fp);
}
idf++;
if ((fp=fopen(  file_freeze_state, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_freeze_state);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_freeze_state);
if (fread(freeze_state, sizeof(unsigned char), freezestate_size, fp) !=freezestate_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_freeze_state);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_freeze_state);
 fclose(fp);
}
idf++;
if ((fp=fopen(  file_excluded_chan, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_excluded_chan);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_excluded_chan);
if (fread(Channels_excluded_from_grand_master, sizeof(bool), excluded_chan_size, fp) !=excluded_chan_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_excluded_chan);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_excluded_chan);
 fclose(fp);
}
idf++;

}

if(specify_who_to_save_load[8]==1)/////Patch circuits/////////////////////////////////
{
save_load_print_to_screen("Loading Patch");
if ((fp=fopen( file_patch_channels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_channels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_patch_channels);
if (fread(Patch, sizeof(int),patch_channels_size, fp) !=patch_channels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_patch_channels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_patch_channels);
 fclose(fp);
}
generate_channel_view_list_from_patched_circuits();
idf++;
}


if(specify_who_to_save_load[9]==1)/////Patch LTP-HTP/////////////////////////////////
{
if ((fp=fopen(file_patch_ltp, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_ltp);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_patch_ltp);
if (fread(dimmer_type, sizeof(bool),patch_ltp_size, fp) !=patch_ltp_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_patch_ltp);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_patch_ltp);
 fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[10]==1)/////Patch curves///////////////////////////
{
if ((fp=fopen(file_patch_curves, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_curves);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_patch_curves);
if (fread(curves, sizeof(int),patch_curves_size, fp) !=patch_curves_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_patch_curves);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_patch_curves);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_curve_ctrl_pt, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_curve_ctrl_pt);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_curve_ctrl_pt);
if (fread(curve_ctrl_pt, sizeof(int),curve_ctrl_size, fp) !=curve_ctrl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_curve_ctrl_pt);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_curve_ctrl_pt);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_curve_spline_level, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_curve_spline_level);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_curve_spline_level);
if (fread(the_curve_spline_level, sizeof(int),curve_spline_level_size, fp) !=curve_spline_level_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_curve_spline_level);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_curve_spline_level);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_curve_matrix, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_curve_matrix);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_curve_matrix);
if (fread(curve_report, sizeof(int),curve_matrix_size, fp) !=curve_matrix_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_curve_matrix);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_curve_matrix);
 fclose(fp);
}
index_curve_spline_level=the_curve_spline_level[curve_selected];
idf++;
rest(10);
}




if(specify_who_to_save_load[11]==1)/////Banger//////////////////////////////////
{
if ((fp=fopen( file_bangers_names, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_names);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_names);
if (fread(bangers_name, sizeof(char), banger_name_size, fp) !=banger_name_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_names);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_names);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_bangers_types, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_types);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_types);
if (fread(bangers_type, sizeof(int), banger_types_size, fp) !=banger_types_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_types);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_types);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_bangers_actions, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_actions);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_actions);
if (fread(bangers_action, sizeof(int), banger_actions_size, fp) !=banger_actions_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_actions);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_actions);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_bangers_values, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_values);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_values);
if (fread(bangers_params, sizeof(int), banger_values_size, fp) !=banger_values_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_values);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_values);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_bangers_times, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_values);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_times);
if (fread(bangers_delay, sizeof(float), banger_times_size, fp) !=banger_times_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_times);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_times);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_bangers_alarms, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_alarms);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_alarms);
if (fread(string_alarm, sizeof(char), banger_alarm_size, fp) !=banger_alarm_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_alarms);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_alarms);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_bangers_loop, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_loop);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_loop);
if (fread(do_loop_banger, sizeof(bool), banger_loop_size, fp) !=banger_loop_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_loop);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_loop);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_bangers_looptime, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_looptime);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_bangers_looptime);
if (fread(time_loop_banger, sizeof(float), banger_looptime_size, fp) !=banger_looptime_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_bangers_looptime);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_bangers_looptime);
 fclose(fp);
}
idf++;

}


if(specify_who_to_save_load[12]==1) ////FADERS CONTENT//////////////////////////
{
save_load_print_to_screen("Loading Faders");



if ((fp=fopen(file_dock_selected, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_selected);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_dock_selected);
if (fread(DockIsSelected, sizeof(bool),dock_selected_size, fp) !=dock_selected_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_selected);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_selected);
 fclose(fp);
}

idf++;
if ((fp=fopen(file_dock_type, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_dock_type);
if (fread(DockTypeIs, sizeof(unsigned char),dock_type_size, fp) !=dock_type_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_type);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_dock_net, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_net);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_dock_net);
if (fread(DockNetIs, sizeof(unsigned char),dock_net_size, fp) !=dock_net_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_net);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_net);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_dock_name, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_name);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_dock_name);
if (fread(DockName, sizeof(char),dock_name_size, fp) !=dock_name_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_name);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_name);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_dock_channels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_channels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_dock_channels);
if (fread(FaderDockContains, sizeof(unsigned char),dock_channels_size, fp) !=dock_channels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_channels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_channels);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_fader_locked, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_locked);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_locked);
if (fread(FaderLocked, sizeof(bool),fader_locked_size, fp) !=fader_locked_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_locked);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_locked);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_fader_locked_full, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_locked_full);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_locked_full);
if (fread(LockFader_is_FullLevel, sizeof(bool),fader_locked_full_size, fp) !=fader_locked_full_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_locked_full);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_locked_full);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_fader_before_lock, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_before_lock);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_before_lock);
if (fread(StateOfFaderBeforeLock, sizeof(unsigned char),fader_before_lock_size, fp) !=fader_before_lock_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_before_lock);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_before_lock);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_color_to_dock, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_color_to_dock);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_color_to_dock);
if (fread(colorpreset_linked_to_dock, sizeof(int),fader_color_to_dock_size, fp) !=fader_color_to_dock_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_color_to_dock);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_color_to_dock);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_fader_audio, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_audio);b_report_error[idf]=1;}
else
{
int temp_array_audio[48*3][6];
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_audio);
if (fread(temp_array_audio, sizeof(int),fader_audio_size, fp) !=fader_audio_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_fader_audio);b_report_error[idf]=1;}
else
{sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_audio);
for(int u=0;u<48;u++)
{
for(int l=0;l<6;l++)
{
DockHasAudioVolume[u][l]=temp_array_audio[u][l];
DockHasAudioPan[u][l]=temp_array_audio[u+48][l];
DockHasAudioPitch[u][l]=temp_array_audio[u+96][l];
}
}
}
 fclose(fp);
}
idf++;

if ((fp=fopen( file_chaser_to_fader, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_to_fader);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_to_fader);
if (fread(ChaserAffectedToDck, sizeof(int),fader_chaser_to_fader_size, fp) !=fader_chaser_to_fader_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_to_fader);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_to_fader);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_mem_to_dock, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mem_to_dock);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mem_to_dock);
if (fread(DockHasMem, sizeof(int),fader_mem_to_dock_size, fp) !=fader_mem_to_dock_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mem_to_dock);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mem_to_dock);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_fader_grid_affect, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_grid_affect);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_grid_affect);
if (fread(faders_dock_grid_affectation, sizeof(int),fader_grid_affect_size, fp) !=fader_grid_affect_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_grid_affect);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_grid_affect);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_fader_fx, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_fx);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_fx);
if (fread(fader_mode_with_buffers, sizeof(int),fader_fx_size, fp) !=fader_fx_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_fx);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_fx);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_fader_route_fx, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_route_fx);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_route_fx);
if (fread(fader_fx_route, sizeof(bool),fader_route_fx_size, fp) !=fader_route_fx_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_route_fx);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_fader_route_fx);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_fader_fgroup, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_fgroup);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_fgroup);
if (fread(fgroup, sizeof(bool),fader_fgroup_size, fp) !=fader_fgroup_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_fgroup);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_fgroup);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_fader_draw, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_draw);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_draw);
if (fread(DrawAffectedToDck, sizeof(int),fader_draw_size, fp) !=fader_draw_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_draw);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_draw);
 fclose(fp);
}
idf++;
recalculate_draw_sizes(draw_preset_selected);

if ((fp=fopen(file_fader_echo, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_echo);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_echo);
if (fread(echo_affected_to_dock, sizeof(int),fader_echo_size, fp) !=fader_echo_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_echo);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_echo);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_fader_damper_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_damper_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_damper_on);
if (fread(fader_damper_is_on, sizeof(bool),fader_damper_on_size, fp) !=fader_damper_on_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_damper_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_damper_on);
 fclose(fp);
}
idf++;

int tmp_typ[48];
if ((fp=fopen(file_fader_damper_typ, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_damper_typ);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_damper_typ);
if (fread(tmp_typ, sizeof(int),fader_damper_typ_size, fp) !=fader_damper_typ_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_damper_typ);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_damper_typ);
 fclose(fp);
}
idf++;
for(int i=0;i<48;i++)
{
Fader_dampered[i].set_damper_mode(tmp_typ[i]);
}

float tmp_data[96];
if ((fp=fopen(file_fader_damper_levels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_damper_levels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_fader_damper_levels);
if (fread(tmp_data, sizeof(float),fader_damper_levels_size, fp) !=fader_damper_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_fader_damper_levels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_damper_levels);
 fclose(fp);
}
idf++;
for(int i=0;i<48;i++)
{
Fader_dampered[i].set_damper_decay(tmp_data[i]);
midi_levels[1960+i]=(int)(tmp_data[i]*127);
Fader_dampered[i].set_damper_dt(tmp_data[i+48]);
midi_levels[2056+i]=(int)(tmp_data[i+48]*127);
}
int fader_damper_levels=96;//2x48 tmp 2 tableaux pour set decay et set dt en valeur 0 - 127*/

if ((fp=fopen(file_faders_state, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_faders_state);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_faders_state);
if (fread(Fader, sizeof(unsigned char),faders_saving_size, fp) !=faders_saving_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_faders_state);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_faders_state);
 fclose(fp);
}

for(int i=0; i<48;i++)//maj des faders
{
     Fader_dampered[i].fix_all_damper_state_value(Fader[i]);
     Fader_dampered[i].set_target_val(Fader[i]);
     fader_set_level(i,Fader[i]);
}

idf++;


}


if(specify_who_to_save_load[13]==1) ////FADERS LFOs//////////////////////////
{
save_load_print_to_screen("Loading LFO's");

if ((fp=fopen(file_dock_times, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_dock_times);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_dock_times);
if (fread(time_per_dock, sizeof(float),dock_times_size, fp) !=dock_times_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_dock_times);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_dock_times);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_is_for_loop_selected, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_is_for_loop_selected);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_is_for_loop_selected);
if (fread(is_dock_for_lfo_selected, sizeof(bool),size_is_for_loop_selected, fp) !=size_is_for_loop_selected)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_is_for_loop_selected);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_is_for_loop_selected);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_lfo_speed, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lfo_speed);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lfo_speed);
if (fread(lfo_speed, sizeof(int),size_lfo_speed, fp) != size_lfo_speed)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_lfo_speed);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lfo_speed);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_lfo_mode_is, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lfo_mode_is);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_lfo_mode_is);
if (fread(lfo_mode_is, sizeof(int),size_lfo_mode_is, fp) !=size_lfo_mode_is)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_lfo_mode_is);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lfo_mode_is);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_lfo_cycle_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lfo_cycle_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_lfo_cycle_on);
if (fread(lfo_cycle_is_on, sizeof(bool),size_lfo_cycle_on, fp) !=size_lfo_cycle_on)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_lfo_cycle_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lfo_cycle_on);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_lfo_do_next_step, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lfo_do_next_step);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lfo_do_next_step);
if (fread(lfo_do_next_step, sizeof(bool),size_lfo_do_next_step, fp) !=size_lfo_do_next_step)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_lfo_do_next_step);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_lfo_do_next_step);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_lfo_loop_step, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lfo_loop_step);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lfo_loop_step);
if (fread(lfo_cycle_steps, sizeof(bool),size_lfo_loop_step, fp) !=size_lfo_loop_step)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_lfo_loop_step);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_lfo_loop_step);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_fader_stoppos_levels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_stoppos_levels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_stoppos_levels);
if (fread(LevelStopPos, sizeof(unsigned char),fader_stoppos_size, fp) !=fader_stoppos_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_stoppos_levels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_stoppos_levels);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_fader_stoppos_is, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_stoppos_is);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_stoppos_is);
if (fread(ActionnateStopOn, sizeof(bool),fader_stopposB_size, fp) !=fader_stopposB_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_stoppos_is);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_stoppos_is);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_fader_ston_is, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_ston_is);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_ston_is);
if (fread(StopPosOn, sizeof(bool),fader_ston_size, fp) !=fader_ston_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_ston_is);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_ston_is);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_fader_chas_autolaunch, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_chas_autolaunch);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_chas_autolaunch);
if (fread( autolaunch, sizeof(bool),fader_chas_autolaucnh_size, fp) !=fader_chas_autolaucnh_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_chas_autolaunch);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_chas_autolaunch);
 fclose(fp);
}
idf++;


}

if(specify_who_to_save_load[14]==1) ////FADERS Curves/////////////////////////
{
if ((fp=fopen(file_fader_curve, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_curve);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_curve);
if (fread(FaderCurves, sizeof(int),fader_curve_size, fp) !=fader_curve_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_curve);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_curve);
 fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[15]==1) ////FADERS Preset and LOCK PST//////////////////////////
{
if ((fp=fopen( file_lock_preset_is, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_is);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_lock_preset_is);
if (fread(lock_preset, sizeof(bool),fader_lock_preset_is_size, fp) !=fader_lock_preset_is_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_lock_preset_is);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_lock_preset_is);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_lock_preset_state, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_state);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_lock_preset_state);
if (fread(FaderLocked_Preset, sizeof(bool),fader_lock_preset_state_size, fp) !=fader_lock_preset_state_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_lock_preset_state);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_lock_preset_state);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_lock_preset_masteris, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_masteris);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_lock_preset_masteris);
if (fread(LockFader_is_FullLevel_Preset, sizeof(bool),fader_lock_preset_masteris_size, fp) !=fader_lock_preset_masteris_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_lock_preset_masteris);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lock_preset_masteris);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_lock_preset_levels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_levels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lock_preset_levels);
if (fread(StateOfFaderBeforeLock_Preset, sizeof(unsigned char),fader_lock_preset_levels_size, fp) !=fader_lock_preset_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_lock_preset_levels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lock_preset_levels);
 fclose(fp);
}
idf++;

for(int d=0;d<8;d++)//detect preset and load state
{
if(lock_preset[d]==1)
{
do_lock_preset(d); break;
}
}
if ((fp=fopen(file_fader_preset_selection, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_fader_preset_selection);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_fader_preset_selection);
if (fread(minifaders_preset_selection, sizeof(bool),fader_prst_sel_size, fp) !=fader_prst_sel_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_fader_preset_selection);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_fader_preset_selection);
 fclose(fp);
}

idf++;
rest(10);
}




if(specify_who_to_save_load[16]==1)/////////////CHASERS/////////////////////////
{
if ((fp=fopen(  file_chaser_name, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_name);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chaser_name);
if (fread(chaser_name, sizeof(char), chaser_name_size, fp) !=chaser_name_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_name);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_name);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chaser_timeunit, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_timeunit);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chaser_timeunit);
if (fread(time_unit, sizeof(float), chaser_timeunit_size, fp) !=chaser_timeunit_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_timeunit);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_timeunit);
 fclose(fp);
}
idf++;


if ((fp=fopen(  file_chaser_stepop, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_stepop);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_chaser_stepop);
if (fread(chaser_step_operation, sizeof(int),chaser_stepop_size, fp) !=chaser_stepop_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_stepop);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_stepop);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chaser_play, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_play);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_play);
if (fread(chaser_is_playing, sizeof(bool),chaser_isplaying_size, fp) !=chaser_isplaying_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_play);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_play);
 fclose(fp);
}
idf++;


if ((fp=fopen(  file_chaser_loop, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_loop);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_loop);
if (fread(chaser_is_in_loop, sizeof(bool),chaser_loop_size, fp) !=chaser_loop_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_loop);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_loop);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chaser_way, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_way);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_way);
if (fread(chaser_way, sizeof(bool), chaser_way_size, fp) != chaser_way_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_way);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_way);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_chaser_allerretour, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_allerretour);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_allerretour);
if (fread(chaser_aller_retour, sizeof(bool),chaser_allerretour_size, fp) != chaser_allerretour_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_chaser_allerretour);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_allerretour);
 fclose(fp);
}
idf++;






if ((fp=fopen(   file_chaser_trackon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_trackon);
if (fread(track_is_on, sizeof(bool), chaser_trackon_size, fp) != chaser_trackon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_trackon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_trackon);
 fclose(fp);
}
idf++;


if ((fp=fopen(   file_chaser_tracklevel, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_tracklevel);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_tracklevel);
if (fread(track_level, sizeof(int), chaser_track_level_size, fp) != chaser_track_level_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_tracklevel);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_tracklevel);
 fclose(fp);
}
idf++;

if ((fp=fopen(   file_chaser_trackview, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackview);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_trackview);
if (fread( position_affichage_track_num, sizeof(int),chaser_trackview_size, fp) != chaser_trackview_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_trackview);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_trackview);
 fclose(fp);
}
idf++;


if ((fp=fopen(   file_chaser_tracktype, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_tracktype);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_tracktype);
if (fread(TrackTypeIs, sizeof(int),chaser_tracktype_size, fp) !=chaser_tracktype_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_tracktype);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_tracktype);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_chaser_trackcontent, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackcontent);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_trackcontent);
if (fread( TrackContains, sizeof(int), chaser_trackcontent_size, fp) != chaser_trackcontent_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_chaser_trackcontent);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_trackcontent);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_chaser_stepis, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_stepis);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_stepis);
if (fread(chaser_step_is, sizeof(int), chaser_stepis_size, fp) != chaser_stepis_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_stepis);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_stepis);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_chaser_beginstep, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_beginstep);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_beginstep);
if (fread(chaser_begin_step_is, sizeof(int),chaser_stepbeg_size, fp) != chaser_stepbeg_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_beginstep);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_beginstep);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_chaser_endstep, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_endstep);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_endstep);
if (fread(chaser_end_step_is, sizeof(int),chaser_stepend_size, fp) !=chaser_stepend_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_endstep);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_endstep);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_chaser_timemode, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_timemode);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_timemode);
if (fread(chaser_time_mode, sizeof(bool),chaser_timemode_size, fp) !=chaser_timemode_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_timemode);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_timemode);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_chaser_lastaffect, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_lastaffect);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_lastaffect);
if (fread(view_chaser_affected_to_fader, sizeof(int), chaser_lastaffect_size, fp) != chaser_lastaffect_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_lastaffect);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_lastaffect);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_chaser_trrackname, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_trrackname);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_trrackname);
if (fread(chaser_track_name, sizeof(char), chaser_tracksname_size, fp) != chaser_tracksname_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_trrackname);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_trrackname);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_chaser_presets, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_presets);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_chaser_presets);
if (fread(chaser_preset, sizeof(bool), chaser_presets_size, fp) != chaser_presets_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_chaser_presets);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_chaser_presets);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_chaser_lchpad_pos, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_lchpad_pos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_chaser_lchpad_pos);
if (fread( chaser_step_launchpad, sizeof(int), chaser_lchpad_pos_size, fp) != chaser_lchpad_pos_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_lchpad_pos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_chaser_lchpad_pos);
 fclose(fp);
}
idf++;


if ((fp=fopen(  file_chaser_acceleroslave, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_chaser_acceleroslave);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_acceleroslave);
if (fread(index_slave_chaser_to_accelerometre, sizeof(bool), chaser_acceleroslave_size, fp) != chaser_acceleroslave_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_acceleroslave);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_chaser_acceleroslave);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_chaser_has_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_chaser_has_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_chaser_has_mem);
if (fread(TrackHasMem, sizeof(int), chaser_has_mem_size, fp) != chaser_has_mem_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_chaser_has_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_chaser_has_mem);
 fclose(fp);
}
idf++;

}


if(specify_who_to_save_load[17]==1) /////////////MIDI AFFECTATION///////////////
{

save_load_print_to_screen("Loading Midi Config");
if ((fp=fopen(file_midi_affectation, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_midi_affectation);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_midi_affectation);
if (fread(miditable, sizeof(int),midi_affectation_size, fp) !=midi_affectation_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_midi_affectation);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_midi_affectation);
 fclose(fp);
}
idf++;
if ((fp=fopen(file_midi_send_out, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_midi_send_out);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_midi_send_out);
if (fread(midi_send_out, sizeof(bool),midi_send_out_size, fp) !=midi_send_out_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_midi_send_out);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_midi_send_out);
 fclose(fp);
}
idf++;
load_Fader_state_to_midi_array();//report des valeurs Faders dans le tableau midi_levels
}


if(specify_who_to_save_load[18]==1) /////////////MIDI cheat///////////////
{
if ((fp=fopen(file_midi_properties, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_midi_properties);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_midi_properties);
if (fread( midi_change_vel_type, sizeof(int),midi_properties_size, fp) !=midi_properties_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_midi_properties);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_midi_properties);
 fclose(fp);
}

if ((fp=fopen(file_midi_clock, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_midi_clock);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_midi_clock);
if (fread( bpm_personnal, sizeof(int),midi_clock_size, fp) !=midi_clock_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",   file_midi_clock);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_midi_clock);
 fclose(fp);
}



idf++;

rest(10);
}

if(specify_who_to_save_load[19]==1)//////////TRICHRO////////////////////////////
{
save_load_print_to_screen("Loading Trichromy");

if ((fp=fopen( file_dock_color_type, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_type);
if (fread(dock_color_type, sizeof(bool), dock_color_type_size, fp) != dock_color_type_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_type);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_dock_color_xy, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_xy);
if (fread(x_y_picker_par_colordock, sizeof(int), dock_color_xy_size, fp) != dock_color_xy_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_xy);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_dock_color_angle, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_angle);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_angle);
if (fread(angle_hue_par_colordock, sizeof(float), dock_color_angle_size, fp) != dock_color_angle_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_angle);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_angle);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_dock_color_picker, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_picker);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_picker);
if (fread(picker_trichro, sizeof(int), dock_color_picker_size, fp) != dock_color_picker_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_picker);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_picker);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_dock_color_ch, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_ch);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_dock_color_ch);
if (fread(dock_color_channels, sizeof(bool), dock_color_ch_size, fp) != dock_color_ch_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_ch);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_ch);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_dock_color_buffer, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_buffer);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_dock_color_buffer);
if (fread(dock_color_buffer_C, sizeof(unsigned char), dock_color_buffer_size, fp) != dock_color_buffer_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_dock_color_buffer);b_report_error[idf]=1;}
else  sprintf(string_save_load_report[idf],"Loaded file %s", file_dock_color_buffer);
 fclose(fp);
}
idf++;
 load_etat_picker_dans_dockcolor(0);//rafraichissement du premier dock color
  //puis mise à l afihage ok du curseur hue
  vx = cos(angle_snap)*125;
  vy = sin(angle_snap)*125;
  position_curseur_hue_x= xtrichro_window+vx;
  position_curseur_hue_y=ytrichro_window+vy ;
 rest(10);
}
if(specify_who_to_save_load[20]==1)/////////////TRACKING VIDEO//////////////////
{
save_load_print_to_screen("Loading Video Tracking");

if ((fp=fopen( file_video_channels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_channels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_video_channels);
if (fread( tracking_contents, sizeof(bool),video_channels_size, fp) !=video_channels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_video_channels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_video_channels);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_video_xy, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_video_xy);
if (fread( tracking_coordonates, sizeof(int),video_xy_size, fp) !=video_xy_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_video_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_video_xy);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_video_spaces_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_spaces_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_video_spaces_on);
if (fread(tracking_spaces_on_off, sizeof(bool),video_spaces_on_size, fp) !=video_spaces_on_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_video_spaces_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_video_spaces_on);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_camera_modes, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_camera_modes);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_camera_modes);
if (fread(camera_modes_and_settings, sizeof(int),camera_modes_size, fp) !=camera_modes_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_camera_modes);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_camera_modes);
 fclose(fp);
}
idf++;
refresh_ocv_settings();

}

refresh_time_cursor();



if(specify_who_to_save_load[27]==1)/////////////////INDEXES/////////////////////
{
if ((fp=fopen(  file_divers_index, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_divers_index);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_divers_index);
if (fread(index_report_customs, sizeof(int), index_size, fp) != index_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_divers_index);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_divers_index);
 fclose(fp);
}
idf++;
}

if(specify_who_to_save_load[24]==1)/////POS window user////////////////////////////////////////
{
if ((fp=fopen(  file_pos_fenetres, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_pos_fenetres);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_pos_fenetres);
if (fread(windows_position, sizeof(int), index_pos_fenetre_size, fp) !=index_pos_fenetre_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_pos_fenetres);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_pos_fenetres);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_windows, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_windows);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_windows);
if (fread( window_opened, sizeof(int), windows_size, fp) !=windows_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_windows);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_windows);
 fclose(fp);
}
idf++;

write_window_indexes_from_list_of_windows();
rest(10);
}
load_indexes();

refresh_decay();
Load_User_Profile();

if(specify_who_to_save_load[22]==1)//AUDIO CONF//////////////////////////////////
{

Load_Audio_Conf();
idf++;


bool temp_audio_array[8];
if ((fp=fopen(  file_audio_autoloadpause, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_autoloadpause);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_audio_autoloadpause);
if (fread( temp_audio_array, sizeof(bool), audio_autoloadpause_size, fp) !=audio_autoloadpause_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_audio_autoloadpause);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_audio_autoloadpause);
 fclose(fp);
}

for(int i=0;i<4;i++)
{
 audio_autoload[i]=temp_audio_array[i];
 audio_autopause[i]=temp_audio_array[i+4];
}
idf++;

if ((fp=fopen(  file_audio_filenumber, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_filenumber);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_audio_filenumber);
if (fread( player_has_file_coming_from_pos, sizeof(int), audio_filenumber_size, fp) !=audio_filenumber_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_audio_filenumber);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_audio_filenumber);
 fclose(fp);
}


idf++;

if ((fp=fopen(  file_audio_playerposition, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_playerposition);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_audio_playerposition);
if (fread( player_position_on_save, sizeof(int), audio_playerposition_size, fp) !=audio_playerposition_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_audio_playerposition);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_audio_playerposition);
 fclose(fp);
}


idf++;

}

if(specify_who_to_save_load[21]==1)///ARDUINO////////////////////////////////////
{
load_arduino_config();

if ((fp=fopen(  file_arduino_dig_typ, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_dig_typ);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",   file_arduino_dig_typ);
if (fread(arduino_digital_type, sizeof(int), arduino_dig_typ_size, fp) !=arduino_dig_typ_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_dig_typ);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_arduino_dig_typ);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_arduino_dig_affect, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_dig_affect);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_arduino_dig_affect);
if (fread(arduino_digital_function_input, sizeof(int), arduino_dig_aff_size, fp) !=arduino_dig_aff_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_dig_affect);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_arduino_dig_affect);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_arduino_an_typ, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_an_typ);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_an_typ);
if (fread(arduino_analog_function_input, sizeof(int), arduino_an_typ_size, fp) !=arduino_an_typ_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_an_typ);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_arduino_an_typ);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_arduino_an_aff, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_an_aff);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_an_aff);
if (fread(arduino_analog_attribution_input, sizeof(int),arduino_an_aff_size, fp) !=arduino_an_aff_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_an_aff);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_arduino_an_aff);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_arduino_an_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_an_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_an_on);
if (fread(ventilate_analog_data, sizeof(bool),arduino_an_on_size, fp) !=arduino_an_on_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_an_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_arduino_an_on);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_arduino_dig_out, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_dig_out);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_dig_out);
if (fread( arduino_digital_function_output, sizeof(int),arduino_dig_out_size, fp) !=arduino_dig_out_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_dig_out);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_arduino_dig_out);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_arduino_kalman_param, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_kalman_param);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_kalman_param);
if (fread( kalman_params, sizeof(double),arduino_kalman_param_size, fp) !=arduino_kalman_param_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_kalman_param);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_arduino_kalman_param);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_arduino_kalman_on, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_kalman_on);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_arduino_kalman_on);
if (fread( kalman_is_on, sizeof(bool),arduino_kalman_on_size, fp) !=arduino_kalman_on_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_arduino_kalman_on);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_arduino_kalman_on);
 fclose(fp);
}
idf++;


}


if(specify_who_to_save_load[25]==1)  ///USER COLOR PROFILE//////////////////////////////////////////////////
{
if ((fp=fopen( file_color_profile, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_color_profile); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_color_profile);
if (fread( couleurs_user, sizeof(int),color_profile_size, fp) !=  color_profile_size)
{ sprintf(string_save_load_report[idf],"Error reading %s",  file_color_profile); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_color_profile);
 fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[26]==1)//////clavier ascii remaping/////////////////
{
if ((fp=fopen(  file_kbd_ascii_map, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_kbd_ascii_map);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_kbd_ascii_map);
if (fread(mapping_temporaire, sizeof(int),kbd_ascii_map_size, fp) !=kbd_ascii_map_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_kbd_ascii_map);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_kbd_ascii_map);
 fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[23]==1)////////ICAT//////////////////////////////////
{
if ((fp=fopen(  file_icat_nbsliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_nbsliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_icat_nbsliders);
if (fread(iCat_nbre_de_sliders, sizeof(int),icat_nbsliders_size, fp) !=icat_nbsliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_icat_nbsliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_icat_nbsliders);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_icat_posliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_posliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_icat_posliders);
if (fread(iCat_pos_slider, sizeof(int),icat_posliders_size, fp) !=icat_posliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_icat_posliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_icat_posliders);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_icat_orsliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_orsliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_icat_orsliders);
if (fread(iCat_orientation_slider, sizeof(bool),icat_orsliders_size, fp) !=icat_orsliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_icat_orsliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_icat_orsliders);
 fclose(fp);
}
idf++;

if ((fp=fopen(  file_icat_typsliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_typsliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_icat_typsliders);
if (fread(iCat_affectation_slider_type_is  , sizeof(int),icat_typsliders_size, fp) !=icat_typsliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_icat_typsliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_icat_typsliders);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_valsliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_valsliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_icat_valsliders);
if (fread( iCat_affectation_slider_value_is, sizeof(int),icat_valsliders_size, fp) !=icat_valsliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_icat_valsliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_icat_valsliders);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_size_sliders, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_size_sliders);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_size_sliders);
if (fread( ratio_iCat_slider, sizeof(int),icat_sizesliders_size, fp) !=icat_sizesliders_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_size_sliders);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_size_sliders);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_orientpage, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_orientpage);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_orientpage);
if (fread(  iCat_preset_orientation, sizeof(int),icat_orpage_size, fp) !=icat_orpage_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_orientpage);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_orientpage);
 fclose(fp);
}
idf++;

if(iCat_preset_orientation[iCatPageis]==0)
   {
    L_tablier_iCat=160;H_tablier_iCat=240;
   }
   else {L_tablier_iCat=240;H_tablier_iCat=160;}



if ((fp=fopen( file_icat_nbbutton, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbbutton);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_nbbutton);
if (fread( iCat_nbre_de_boutons, sizeof(int),icat_nbbutton_size, fp) !=icat_nbbutton_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_nbbutton);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_nbbutton);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_pobutton, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_pobutton);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_pobutton);
if (fread(  iCat_pos_bouton, sizeof(int),icat_pobutton_size, fp) !=icat_pobutton_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_pobutton);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_pobutton);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_size_buttons, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_size_buttons);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_size_buttons);
if (fread(   ratio_iCat_button, sizeof(int),icat_sizebuttons_size, fp) !=icat_sizebuttons_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_size_buttons);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_size_buttons);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_typbutton, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_typbutton);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_typbutton);
if (fread(   iCat_affectation_bouton_type_is, sizeof(int),icat_typbutton_size, fp) !=icat_typbutton_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_typbutton);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_typbutton);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_actbutton, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_actbutton);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_actbutton);
if (fread(  iCat_affectation_bouton_action_is, sizeof(int),icat_actbutton_size, fp) !=icat_actbutton_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_actbutton);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_actbutton);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_valbutton, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valbutton);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_valbutton);
if (fread(  iCat_affectation_bouton_value_is, sizeof(int),icat_valbutton_size, fp) !=icat_valbutton_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_valbutton);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_valbutton);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_nbstr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbstr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_nbstr);
if (fread(  iCat_nbre_de_strings, sizeof(int),icat_nbstr_size, fp) !=icat_nbstr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_nbstr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_nbstr);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_posstr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_posstr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_posstr);
if (fread(  iCat_pos_string, sizeof(int),icat_posstr_size, fp) !=icat_posstr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_posstr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_posstr);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_sizestr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_sizestr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_sizestr);
if (fread( ratio_iCat_string, sizeof(int),icat_sizestr_size, fp) !=icat_sizestr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_sizestr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_sizestr);
 fclose(fp);
}
idf++;



if ((fp=fopen( file_icat_typstr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_typstr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_typstr);
if (fread( iCat_affectation_string_type_is, sizeof(int),icat_typstr_size, fp) !=icat_typstr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_typstr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_typstr);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_actstr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_actstr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_actstr);
if (fread(  iCat_affectation_string_action_is, sizeof(int),icat_actstr_size, fp) !=icat_actstr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_actstr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_actstr);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_valstr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valstr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_actstr);
if (fread(   iCat_affectation_string_value_is, sizeof(int),icat_valstr_size, fp) !=icat_valstr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_valstr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_valstr);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_nbzon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbzon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_nbzon);
if (fread(  iCat_nbre_de_tracking_zone, sizeof(int),icat_nbzon_size, fp) !=icat_nbzon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_nbzon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_nbzon);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_poszon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_poszon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_poszon);
if (fread(  iCat_pos_trackzone, sizeof(int),icat_poszon_size, fp) !=icat_poszon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_poszon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_poszon);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_sizezon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_sizezon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_sizezon);
if (fread(  ratio_iCat_trackzone, sizeof(int),icat_sizezon_size, fp) !=icat_sizezon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_sizezon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_sizezon);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_icat_typzon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_typzon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_typzon);
if (fread(  iCat_trackzone_type_is, sizeof(int),icat_typzon_size, fp) !=icat_typzon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_typzon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_typzon);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_valzon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valzon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_valzon);
if (fread(  iCat_trackzone_affectation_is, sizeof(int),icat_valzon_size, fp) !=icat_valzon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_valzon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_valzon);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_icat_posTRCKzon, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_posTRCKzon);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_icat_posTRCKzon);
if (fread( pos_iCat_tracker, sizeof(int),icat_posTRCKzon_size, fp) !=icat_posTRCKzon_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",file_icat_posTRCKzon);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",file_icat_posTRCKzon);
 fclose(fp);
}
idf++;



}

if(specify_who_to_save_load[28]==1) //////////MOVER//////////////////////////////
{
if ((fp=fopen( file_mover_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_mem);
if (fread(dock_move_xy, sizeof(int),mover_mem_saving_size, fp) !=mover_mem_saving_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_mover_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_mover_mem);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_mover_mem16b, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_mem16b);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_mem16b);
if (fread(dock_move_xy_16b, sizeof(int),mover_mem_saving_size, fp) !=mover_mem_saving_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s",  file_mover_mem16b);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s",  file_mover_mem16b);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_numbersteps, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_numbersteps);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_numbersteps);
if (fread(dock_moves_contains_steps, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_numbersteps);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_numbersteps);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_stepis, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_stepis);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_stepis);
if (fread(dock_move_actual_step, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_stepis);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_stepis);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_divers, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_divers);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_divers);
if (fread(valeurs_diverses, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_divers);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_divers);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_spline_ratio, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_spline_ratio);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_mover_spline_ratio);
if (fread(spline_ratio, sizeof(float), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_spline_ratio);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_spline_ratio);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_asservis_mem, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_asservis_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_asservis_mem);
if (fread(dock_asservis, sizeof(float), mover_asservis_saving_size, fp) != mover_asservis_saving_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_asservis_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_asservis_mem);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_time, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_time);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mover_time);
if (fread(dock_time, sizeof(float), mover_time_size, fp) != mover_time_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_time);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_time);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_autostop, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_autostop);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mover_autostop);
if (fread(move_auto_stop, sizeof(bool), mover_autostop_size, fp) != mover_autostop_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_autostop);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_autostop);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_goto, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mover_goto);
if (fread(GotoMoves, sizeof(int), mover_goto_size, fp) != mover_goto_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_goto);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_mover_into, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_into);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mover_into);
if (fread(Moves_Inpoint, sizeof(int), mover_little_32file_size, fp) !=mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_into);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_into);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_mover_params, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mover_params);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_mover_params);
if (fread(mover_params_adresses, sizeof(int), mover_param_size, fp) !=mover_param_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_mover_params);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_mover_params);
 fclose(fp);
}
idf++;

xadress=mover_params_adresses[0];
yadress=mover_params_adresses[1];
irisadress=mover_params_adresses[2];
focusadress=mover_params_adresses[3];
zoomadress=mover_params_adresses[4];
invX_on=valeurs_diverses[0];
invY_on=valeurs_diverses[1];
Tracker_speedlevel=valeurs_diverses[2];
dock_move_selected=valeurs_diverses[3];
index_rescale_signal=valeurs_diverses[8];*/
position_defaut[0]=valeurs_diverses[13];
position_defaut[1]=valeurs_diverses[14];
index_spline=valeurs_diverses[15];

Tracker_splinelevel=(int)((spline_ratio[dock_move_selected]+1)*100);
sprintf(string_zero_point_is,"Offset X %d Y %d",position_defaut[0],position_defaut[1]);

mover_params[2][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0];
mover_params[3][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1];
mover_params[4][0]=dock_asservis[dock_move_selected][(dock_move_actual_step[dock_move_selected])][2];


mover_params[0][0]=dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][0];
mover_params[1][0]=dock_move_xy[dock_move_selected][(dock_move_actual_step[dock_move_selected])][1];
rest(10);
}

if(specify_who_to_save_load[29]==1)
{


if ((fp=fopen( file_grid_levels_1, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_levels_1);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_levels_1);
if (fread(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) !=grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_levels_1);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_levels_1);
 fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
grid_levels[i][s][c]=temp_grid_levels_for_save[i][s][c];
}
}
}

if ((fp=fopen( file_grid_levels_2, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_levels_2);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_levels_2);
if (fread(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) !=grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_levels_2);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_levels_2);
 fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
grid_levels[i+32][s][c]=temp_grid_levels_for_save[i][s][c];
}
}
}
if ((fp=fopen( file_grid_levels_3, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_levels_3);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_levels_3);
if (fread(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) !=grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_levels_3);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_levels_3);
 fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
grid_levels[i+64][s][c]=temp_grid_levels_for_save[i][s][c];
}
}
}
if ((fp=fopen( file_grid_levels_4, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_levels_4);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_levels_4);
if (fread(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) !=grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_levels_4);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_levels_4);
 fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
grid_levels[i+96][s][c]=temp_grid_levels_for_save[i][s][c];
}
}
}






if ((fp=fopen( file_grid_times, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_times);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_times);
if (fread(grid_times, sizeof(float), grid_times_size, fp) !=grid_times_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_times);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_times);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_grid_goto, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_goto);
if (fread(grid_goto, sizeof(int), grid_goto_size, fp) !=grid_goto_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_goto);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_grid_seekpos, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_seekpos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_seekpos);
if (fread(grid_seekpos, sizeof(int), grid_seekpos_size, fp) !=grid_seekpos_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_seekpos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_seekpos);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_grid_stoplay, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_stoplay);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_stoplay);
if (fread(grid_stoplay, sizeof(bool), grid_stoplay_size, fp) !=grid_stoplay_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_stoplay);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_stoplay);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_grid_names, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_grid_names);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_names);
if (fread(grider_name, sizeof(char), grid_names_size, fp) !=grid_names_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_names);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_names);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_gridpl_grid, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_grid);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_grid);
if (fread(index_grider_selected, sizeof(int),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_grid);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_grid);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_step, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_step);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_step);
if (fread(index_grider_step_is, sizeof(int),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_step);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_step);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_autost, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_autost);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_autost);
if (fread(grider_autostopmode, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_autost);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_autost);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_goto, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_goto);
if (fread(grider_goto_mode, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_goto);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_seekto, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_seekto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_seekto);
if (fread(grider_seekto_mode, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_seekto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_seekto);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_stpl, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_stpl);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_stpl);
if (fread(grider_stoplay_mode, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_stpl);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_stpl);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_slave, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_slave);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_slave);
if (fread(grid_player_slave, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_slave);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_slave);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_show, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_show);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_show);
if (fread(index_show_grid_player, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_show);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_show);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_accel, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_accel);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_accel);
if (fread(grid_crossfade_speed, sizeof(int),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_accel);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_accel);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_countmod, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_countmod);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_countmod);
if (fread(grider_count_mode, sizeof(bool),gridpl_size, fp) !=gridpl_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_countmod);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_countmod);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_gridpl_snapfader, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_snapfader);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_snapfader);
if (fread(GplSnapFader, sizeof(int),gridpl_snapfader_size, fp) !=gridpl_snapfader_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_snapfader);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_snapfader);
 fclose(fp);
}
idf++;


int grider_conf[3];
if ((fp=fopen( file_grider_conf, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_grider_conf);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grider_conf);
if (fread(grider_conf, sizeof(int),grider_conf_size, fp) !=grider_conf_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grider_conf);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grider_conf);
 fclose(fp);
}
idf++;
grider_begin_channel_is=grider_conf[0];
grider_nb_col=grider_conf[1];
grider_nb_row=grider_conf[2];

if(grider_nb_col>24){grider_nb_col=8;}
if(grider_nb_row>24){grider_nb_row=8;}
if(grider_begin_channel_is>512){grider_begin_channel_is=1;}

int grider_report_cross[8];

if ((fp=fopen( file_gridpl_crosslv, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_gridpl_crosslv);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_gridpl_crosslv);
if (fread(grider_report_cross, sizeof(int),gridpl_croslv_size, fp) !=gridpl_croslv_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_gridpl_crosslv);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_gridpl_crosslv);
 fclose(fp);
}
for(int gr=0;gr<4;gr++)
{
grid_niveauX1[gr]=grider_report_cross[gr];
grid_niveauX2[gr]=grider_report_cross[gr+4];//debug christoph ruiserge sur état crossfade 18/12/14
grid_floatX1[gr]=(float)grid_niveauX1[gr];
grid_floatX2[gr]=(float)grid_niveauX2[gr];
}
idf++;
if ((fp=fopen( file_grid_count, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_grid_count);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_grid_count);
if (fread(grid_count, sizeof(int),grid_count_size, fp) !=grid_count_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_count);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_count);
 fclose(fp);
}
idf++;
if ((fp=fopen( file_grided_count, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_grided_count);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_grided_count);
if (fread(grid_counted_times, sizeof(int),grid_counted_size, fp) !=grid_counted_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grided_count);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grided_count);
 fclose(fp);
}
idf++;

refresh_hauteur_fenetre_grider();
}//fin grid

if(specify_who_to_save_load[30]==1)
{

if ((fp=fopen( file_grid_in_mems, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_grid_in_mems);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_grid_in_mems);
if (fread(set_from_seq_gridplayer1_next_step, sizeof(int),grid_in_mems_size, fp) !=grid_in_mems_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_grid_in_mems);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_grid_in_mems);
 fclose(fp);
}
idf++;
}




if(specify_who_to_save_load[35]==1)
{

if ((fp=fopen( file_save_preset, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_save_preset);  b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_save_preset);
if (fread(preset_specify_who_to_save_load, sizeof(bool),save_preset_size, fp) !=save_preset_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_save_preset);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_save_preset);
fclose(fp);
}

idf++;

if ((fp=fopen( file_save_pdf, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_save_pdf);  b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",  file_save_pdf);
if (fread(specify_who_to_save_PDF, sizeof(bool),save_pdf_size, fp) !=save_pdf_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_save_pdf);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_save_pdf);
fclose(fp);
}

idf++;
}


if(specify_who_to_save_load[32]==1)
{

if ((fp=fopen( file_draw_presetsz, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_presetsz);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_draw_presetsz);
if (fread( draw_preset_parameters, sizeof(int),draw_presetsz_size, fp) !=draw_presetsz_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_draw_presetsz);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_draw_presetsz);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_draw_levels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_levels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_draw_levels);
if (fread( draw_preset_levels, sizeof(float),draw_levels_size, fp) !=draw_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_draw_levels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_draw_levels);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_draw_chrouting, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_chrouting);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_draw_chrouting);
if (fread( draw_preset_channel_routing, sizeof(int),draw_chrouting_size, fp) !=draw_chrouting_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_draw_chrouting);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_draw_chrouting);
fclose(fp);
}
idf++;

load_draw_preset_config();
idf++;
}

if(specify_who_to_save_load[33]==1)
{

if ((fp=fopen( file_echo_pointing_fader, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_pointing_fader);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_pointing_fader);
if (fread( echo_pointing_fader_num, sizeof(int),echo_pointing_fader_size, fp) !=echo_pointing_fader_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_pointing_fader);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_pointing_fader);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_echo_mode, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_echo_mode);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_echo_mode);
if (fread( echo_is_echo_mode, sizeof(bool),echo_echo_mode_size, fp) !=echo_echo_mode_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_echo_mode);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_echo_mode);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_global_param, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_global_param);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_global_param);
if (fread( echo_global_params, sizeof(float),echo_global_param_size, fp) !=echo_global_param_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_global_param);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_global_param);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_channel_man_mode, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_channel_man_mode);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_channel_man_mode);
if (fread( echo_channel_manipulate_mode, sizeof(bool),echo_channel_man_mode_size, fp) !=echo_channel_man_mode_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_channel_man_mode);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_channel_man_mode);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_chan_pos, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_chan_pos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_chan_pos);
if (fread( echo_grid_channel_position, sizeof(int),echo_chan_pos_size, fp) !=echo_chan_pos_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_chan_pos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_chan_pos);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_levels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_levels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_levels);
if (fread( echo_levels, sizeof(float),echo_levels_size, fp) !=echo_levels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_levels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_levels);
 fclose(fp);
}
idf++;


if ((fp=fopen( file_echo_bounce, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_bounce);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_bounce);
if (fread( do_bounce, sizeof(bool),echo_bounce_size, fp) !=echo_bounce_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_bounce);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_bounce);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_presets, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_presets);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_echo_presets);
if (fread( snap_echo_to_recall, sizeof(float),echo_presets_size, fp) !=echo_presets_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_echo_presets);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_echo_presets);
 fclose(fp);
}
idf++;

}


if(specify_who_to_save_load[34]==1)
{

if ((fp=fopen( file_wave_ch_slots, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_ch_slots);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_wave_ch_slots);
if (fread( channel_slots, sizeof(int),wave_ch_slots_size, fp) !=wave_ch_slots_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_wave_ch_slots);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_wave_ch_slots);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_wave_brush_slots, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_brush_slots);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_wave_brush_slots);
if (fread( brush_slots, sizeof(float),wave_brush_slots_size, fp) !=wave_brush_slots_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_wave_brush_slots);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_wave_brush_slots);
 fclose(fp);
}
idf++;

if ((fp=fopen( file_wave_brush_pr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_brush_pr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_wave_brush_pr);
if (fread( lead_brush_reading, sizeof(int),wave_brush_pr_size, fp) !=wave_brush_pr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_wave_brush_pr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_wave_brush_pr);
 fclose(fp);
}
idf++;


float tmp_fl[2];
if ((fp=fopen( file_wave_damp_decay, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_damp_decay);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_wave_damp_decay);
if (fread( tmp_fl, sizeof(float),wave_damp_decay_size, fp) !=wave_damp_decay_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_wave_damp_decay);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_wave_damp_decay);
 fclose(fp);
}

for(int i=0;i<26;i++)
    {
    Wave_Dampered[i].set_damper_decay(tmp_fl[0]);
    Wave_Dampered[i].set_damper_dt(tmp_fl[1]);
    }
set_new_values_in_wave();
idf++;
}
if(specify_who_to_save_load[31]==1)
{

if ((fp=fopen( file_lib_sizes_symbol, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lib_sizes_symbol);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lib_sizes_symbol);
if (fread( size_symbol, sizeof(float),lib_sizes_symbol_size, fp) !=lib_sizes_symbol_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_lib_sizes_symbol);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lib_sizes_symbol);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_lib_names_symbol, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lib_names_symbol);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s", file_lib_names_symbol);
if (fread( symbol_nickname, sizeof(char),lib_names_symbol_size, fp) !=lib_names_symbol_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_lib_names_symbol);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_lib_names_symbol);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_angles, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_angles);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_angles);
if (fread( angle_symbol, sizeof(float),plot_angle_size, fp) !=plot_angle_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_angles);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_angles);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_positions, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_positions);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_positions);
if (fread( pos_symbol, sizeof(int),plot_positions_size, fp) !=plot_positions_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_positions);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_positions);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_plot_nbr_symbols, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_nbr_symbols);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_nbr_symbols);
if (fread(nbre_symbols_on_plot, sizeof(int),plot_nbr_symbols_size, fp) !=plot_nbr_symbols_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_nbr_symbols);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_nbr_symbols);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_typ, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_typ);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_typ);
if (fread(symbol_type, sizeof(int),plot_typ_size, fp) !=plot_typ_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_typ);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_typ);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_chan, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_chan);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_chan);
if (fread(symbol_channel_is, sizeof(int),plot_chan_size, fp) !=plot_chan_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_chan);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_chan);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_dim, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_dim);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_dim);
if (fread(symbol_dimmer_is, sizeof(int),plot_dim_size, fp) !=plot_dim_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_dim);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_dim);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_gels, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_gels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_gels);
if (fread(gelat, sizeof(int),plot_gels_size, fp) !=plot_gels_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_gels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_gels);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_gels_t, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_gels_t);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_gels_t);
if (fread(gelat_family, sizeof(int),plot_gels_t_size, fp) !=plot_gels_t_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_gels_t);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_gels_t);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_view, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_view);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_gels_t);
if (fread(show_calc_number, sizeof(bool),plot_view_size, fp) !=plot_view_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_view);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_view);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_options_view, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_options_view);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_options_view);
if (fread( plot_show_options, sizeof(bool),plot_view_options_size, fp) !=plot_view_options_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_options_view);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_options_view);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_opt_xy, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_opt_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_options_view);
if (fread( relatif_plot_xy, sizeof(int),plot_opt_xy_size, fp) !=plot_opt_xy_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_opt_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_opt_xy);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_type, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_type);
if (fread( shape_type, sizeof(int),plot_shape_type_size, fp) !=plot_shape_type_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_type);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_attr, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_attr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_attr);
if (fread( shape_attributes, sizeof(float),plot_shape_attr_size, fp) !=plot_shape_attr_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_attr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_attr);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_pos, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_pos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_pos);
if (fread( shape_position, sizeof(int),plot_shape_pos_size, fp) !=plot_shape_pos_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_pos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_pos);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_legend_name, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_legend_name);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_legend_name);
if (fread( shape_legend_name, sizeof(char),plot_shape_legend_name_size, fp) !=plot_shape_legend_name_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_legend_name);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_legend_name);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_relativ_xy, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_relativ_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_relativ_xy);
if (fread( shape_relativ_position_legend_name, sizeof(int),plot_shape_relativ_xy_size, fp) !=plot_shape_relativ_xy_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_relativ_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_relativ_xy);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_color_type, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_color_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_color_type);
if (fread( shape_color_type, sizeof(int),plot_shape_color_type_size, fp) !=plot_shape_color_type_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_color_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_color_type);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_groups, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_groups);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_shape_groups);
if (fread( shape_groups, sizeof(int),plot_shape_groups_size, fp) !=plot_shape_groups_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_shape_groups);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_shape_groups);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_symbols_relativgroups, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symbols_relativgroups);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_symbols_relativgroups);
if (fread(  plot_relativxy_preset, sizeof(int),plot_symbols_relativgroups_size, fp) !=plot_symbols_relativgroups_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_symbols_relativgroups);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_symbols_relativgroups);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_plot_symbols_notes, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symbols_notes);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_symbols_notes);
if (fread( symbol_note, sizeof(char),plot_symbols_notes_size, fp) !=plot_symbols_notes_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_symbols_notes);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_symbols_notes);
 fclose(fp);
}
idf++;


if ((fp=fopen(file_plot_legend, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_legend);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_legend);
if (fread(plot_renseignements, sizeof(char),plot_legend_size, fp) !=plot_legend_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_legend);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_legend);
 fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_symb_linked, "rb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symb_linked);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opening file %s",file_plot_symb_linked);
if (fread(symbol_is_linked_to, sizeof(int),plot_symb_linked_size, fp) !=plot_symb_linked_size)
{ sprintf(string_save_load_report[idf],"Error Loaded %s", file_plot_symb_linked);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Loaded file %s", file_plot_legend);
 fclose(fp);
}
idf++;


plot_generate_appareils_list();
    midi_send_out[2115]=midi_send_out[2114];
    midi_send_out[2117]=midi_send_out[2114];
refresh_all_midi_out_faders();


sprintf(rep,"%s",mondirectory);
chdir (rep);
scan_planfolder();
sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
chdir (rep);


Load_Plot_Plan_config();
if(index_menus_lighting_plot==4 )
{position_plan_x=0;}
idf++;

load_plan_of_theatre(Name_of_plane_is, 0);


if(view_plot_calc_number_is>3){view_plot_calc_number_is=3;}
show_calc_number[view_plot_calc_number_is]=1;
}




LoadWhiteCatColorProfil();// pas de fichiers, juste raffraichissement
rest(10);

sprintf(rep,"%s",mondirectory);
chdir (rep);

Load_Launchpad_RetroLight();

if(specify_who_to_save_load[22]==1)
{
scan_audiofolder();
Load_audiofiles_cues();
sprintf(rep,"%s",mondirectory);
chdir (rep);

for(int i=0;i<4;i++)
{
 audiofile_selected=player_has_file_coming_from_pos[i];
 sprintf(audiofile_name,list_audio_files[audiofile_selected]);
 if(strcmp (audiofile_name,"")!=0)
 {
 AffectSoundFile(i);
 }

rest(10);
}

}

refresh_mem_onstage(position_onstage);
refresh_mem_onpreset(position_preset);
detect_mem_before_one();
detect_error_on_save_load();
Show_report_save_load();


initiate_windows();


if(there_is_an_error_on_save_load==1){index_show_save_load_report=1;there_is_change_on_show_save_state=1;    } else {index_show_save_load_report=0;there_is_change_on_show_save_state=0;    }


return(0);
}
