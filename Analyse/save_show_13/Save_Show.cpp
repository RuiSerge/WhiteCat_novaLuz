int Save_Show()
{
index_is_saving=1;

save_load_print_to_screen("Saving ...");

sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
mkdir (rep);
chdir (rep);
clear_report_string();
idf=0;
FILE *fpo=NULL;
if((fpo=fopen("whitecat_version.txt","w")))
{

fprintf(fpo,"%s\n",versionis);
sprintf(string_save_load_report[idf],"Saved whitecat_version.txt");
}
else {sprintf(string_save_load_report[idf],"Error on whitecat_version.txt");b_report_error[idf]=1; }
fclose(fpo);

 idf++;
rest(10);

FILE *fp=NULL;








if(specify_who_to_save_load[0]==1) ///MEMOIRES////////////////////////////////////////////////////////////
{
if ((fp=fopen( file_mem_existantes, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_existantes); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_mem_existantes);
if (fwrite(MemoiresExistantes, sizeof(bool),mem_existantes_size, fp) !=  mem_existantes_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_mem_existantes); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mem_existantes);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_memories, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_memories); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_memories);
if (fwrite(Memoires, sizeof(unsigned char),memories_size, fp) !=  memories_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_memories); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_memories);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_text_mems, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_text_mems); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_text_mems);
if (fwrite(descriptif_memoires, sizeof(char),text_mems_size, fp) !=  text_mems_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_text_mems); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_text_mems);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_text_annots, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_text_annots); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_text_annots);
if (fwrite(annotation_memoires, sizeof(char),text_annots_size, fp) !=  text_annots_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_text_annots); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_text_annots);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mem_detruites, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_detruites); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_mem_detruites);
if (fwrite(MemoiresDetruites, sizeof(bool),mem_deleted_size, fp) !=  mem_deleted_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mem_detruites); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_mem_detruites);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mem_exclues, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mem_exclues); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_mem_exclues);
if (fwrite(MemoiresExclues, sizeof(bool),mem_exclues_size, fp) !=  mem_exclues_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mem_exclues); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_mem_exclues);
fclose(fp);
}
 idf++;


Save_Sequenciel_Conf();
 idf++;
}

if(specify_who_to_save_load[1]==1) ///////////MEMOIRES TIMES///////////////////////////////////////////////
{
if ((fp=fopen( file_times_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_times_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_times_mem);
if (fwrite(Times_Memoires, sizeof(float),times_mems_size, fp) !=  times_mems_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_times_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_times_mem);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[2]==1)  ///////////MEMOIRES LINKS //////////////////////////////////////////////
{
if ((fp=fopen( file_link_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_link_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_link_mem);
if (fwrite(Links_Memoires, sizeof(bool),link_mem_size, fp) !=  link_mem_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_link_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_link_mem);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[3]==1) ///////////MEMOIRES: nums de bangers affectés//////////////////////////
{
if ((fp=fopen( file_banger_call_in_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_banger_call_in_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_banger_call_in_mem);
if (fwrite(Banger_Memoire, sizeof(int),bang_mem_size, fp) !=  bang_mem_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_banger_call_in_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_banger_call_in_mem);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[4]==1) /////////////MEMOIRES: manual ratio/////////////////////////////////////
{
if ((fp=fopen( file_manual_ratio_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_manual_ratio_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_manual_ratio_mem);
if (fwrite(ratio_cross_manuel, sizeof(int),ratio_mem_size, fp) !=  ratio_mem_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_manual_ratio_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_manual_ratio_mem);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[5]==1)  ////////////Channels LIST//////////////////////////////////////////////
{
if ((fp=fopen(file_spotlist, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_spotlist); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_spotlist);
if (fwrite( descriptif_projecteurs, sizeof(char),spotlist_size, fp) !=  spotlist_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_spotlist); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_spotlist);
fclose(fp);
}
 idf++;


 if ((fp=fopen(file_chan_macro_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chan_macro_on);
if (fwrite(  macro_channel_on, sizeof(bool),chan_macro_on_size, fp) !=  chan_macro_on_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chan_macro_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chan_macro_on);
fclose(fp);
}
 idf++;


  if ((fp=fopen(file_chan_macro_reaction, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_reaction); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chan_macro_reaction);
if (fwrite(  channel_macro_reaction, sizeof(int),chan_macro_reaction_size, fp) !=  chan_macro_reaction_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chan_macro_reaction); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chan_macro_reaction);
fclose(fp);
}
 idf++;



   if ((fp=fopen(file_chan_macro_action, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_action); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chan_macro_action);
if (fwrite(  channel_macro_action, sizeof(int),chan_macro_action_size, fp) !=  chan_macro_action_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chan_macro_action); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chan_macro_action);
fclose(fp);
}
 idf++;

  if ((fp=fopen(file_chan_macro_val, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chan_macro_val); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chan_macro_val);
if (fwrite(  channel_macro_val, sizeof(int),chan_macro_val_size, fp) !=  chan_macro_val_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chan_macro_val); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chan_macro_val);
fclose(fp);
}
 idf++;

  if ((fp=fopen(file_chview_ch, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_ch); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chview_ch);
if (fwrite(  Channel_View_ROUTING, sizeof(int),chview_ch_size, fp) !=  chview_ch_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chview_ch); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chview_ch);
fclose(fp);
}
 idf++;

  if ((fp=fopen(file_chview_name, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_name); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chview_name);
if (fwrite(  channel_view_Name, sizeof(char),chview_name_size, fp) !=  chview_name_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chview_name); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chview_name);
fclose(fp);
}
 idf++;

   if ((fp=fopen(file_chview_linktype, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_linktype); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chview_linktype);
if (fwrite(  channel_view_link_type, sizeof(int), chview_linktype_size, fp) !=  chview_linktype_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chview_linktype); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chview_linktype);
fclose(fp);
}
 idf++;


    if ((fp=fopen(file_chview_linkref, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_linkref); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chview_linkref);
if (fwrite(  channel_view_link_ref, sizeof(int), chview_linkref_size, fp) !=  chview_linkref_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chview_linkref); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chview_linkref);
fclose(fp);
}
 idf++;


  if ((fp=fopen(file_chview_view, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chview_view); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chview_view);
if (fwrite(  Channel_View_MODE, sizeof(bool), chview_view_size, fp) !=  chview_view_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chview_view); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chview_view);
fclose(fp);
}
 idf++;

 //fin list
}


if(specify_who_to_save_load[6]==1)  ////////////Channels Direct Chan///////////////////////////////////////
{
if ((fp=fopen( file_direct_channel, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_direct_channel); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_direct_channel);
if (fwrite(FaderDirectChan, sizeof(int),fader_direct_chan_size, fp) != fader_direct_chan_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_direct_channel); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_direct_channel);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[7]==1)  ////////////FREEZE STATE//////////////////////////////////////////////////
{
if ((fp=fopen(file_dofreeze, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dofreeze); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_dofreeze);
if (fwrite( freeze_array, sizeof(bool), dofreeze_size, fp) !=   dofreeze_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dofreeze); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dofreeze);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_freeze_state, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_freeze_state); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_freeze_state);
if (fwrite( freeze_state, sizeof(unsigned char), freezestate_size, fp) !=   freezestate_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_freeze_state); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_freeze_state);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_excluded_chan, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_excluded_chan); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_excluded_chan);
if (fwrite(Channels_excluded_from_grand_master, sizeof(bool), excluded_chan_size, fp) !=   excluded_chan_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_excluded_chan); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_excluded_chan);
fclose(fp);
}
 idf++;

}




if(specify_who_to_save_load[8]==1)  /////PATCH CHANNELS ////////////////////////////////////////////////////
{
if ((fp=fopen( file_patch_channels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_channels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_patch_channels);
if (fwrite(Patch, sizeof(int),patch_channels_size, fp) != patch_channels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_patch_channels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_patch_channels);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[9]==1)  /////PATCH LTP / HTP////////////////////////////////////////////////////
{
if ((fp=fopen( file_patch_ltp, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_ltp); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_patch_ltp);
if (fwrite(dimmer_type, sizeof(bool),patch_ltp_size, fp) != patch_ltp_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_patch_ltp); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_patch_ltp);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_patch_curves, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_patch_curves); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_patch_curves);
if (fwrite(curves, sizeof(int),patch_curves_size, fp) != patch_curves_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_patch_curves); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_patch_curves);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[10]==1)  //////PATCH CURVES/////////////////////////////////////////////////////
{
if ((fp=fopen( file_curve_ctrl_pt, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_curve_ctrl_pt); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_curve_ctrl_pt);
if (fwrite(curve_ctrl_pt, sizeof(int),curve_ctrl_size, fp) != curve_ctrl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_curve_ctrl_pt); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_curve_ctrl_pt);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_curve_spline_level, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_curve_spline_level); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_curve_spline_level);
if (fwrite(the_curve_spline_level, sizeof(int),curve_spline_level_size, fp) != curve_spline_level_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_curve_spline_level); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_curve_spline_level);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_curve_matrix, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_curve_matrix); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_curve_matrix);
if (fwrite(curve_report, sizeof(int),curve_matrix_size, fp) != curve_matrix_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_curve_matrix); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_curve_matrix);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[11]==1)  //////////////BANGER///////////////////////////////////////////////////
{
if ((fp=fopen(file_bangers_names, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_names); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_names);
if (fwrite( bangers_name, sizeof(char), banger_name_size, fp) !=   banger_name_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_names); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_bangers_names);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_types, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_types); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_types);
if (fwrite( bangers_type, sizeof(int),banger_types_size, fp) !=   banger_types_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_types); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_bangers_types);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_actions, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_actions); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_actions);
if (fwrite( bangers_action, sizeof(int),banger_actions_size, fp) !=  banger_actions_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_actions); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_bangers_actions);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_values, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_values); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_values);
if (fwrite( bangers_params, sizeof(int), banger_values_size, fp) !=   banger_values_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_values); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_bangers_values);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_times, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_bangers_times); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_times);
if (fwrite( bangers_delay, sizeof(float), banger_times_size, fp) !=  banger_times_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_times); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_bangers_times);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_alarms, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_bangers_alarms); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_alarms);
if (fwrite(string_alarm, sizeof(char), banger_alarm_size, fp) != banger_alarm_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_alarms); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_bangers_alarms);
fclose(fp);
}
 idf++;
if ((fp=fopen(file_bangers_loop, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_bangers_loop); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_loop);
if (fwrite(do_loop_banger, sizeof(bool), banger_loop_size, fp) != banger_loop_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_loop); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_bangers_loop);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_bangers_looptime, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_bangers_looptime); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_bangers_looptime);
if (fwrite(time_loop_banger, sizeof(float), banger_looptime_size, fp) != banger_looptime_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_bangers_looptime); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_bangers_looptime);
fclose(fp);
}
 idf++;

}

if(specify_who_to_save_load[12]==1) /////////////FADERS contents///////////////////////////////////////////
{
if ((fp=fopen( file_faders_state, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_faders_state); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_faders_state);
if (fwrite(Fader, sizeof(unsigned char), faders_saving_size, fp) != faders_saving_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_faders_state); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_faders_state);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_dock_selected, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_selected); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_selected);
if (fwrite(DockIsSelected, sizeof(bool), dock_selected_size, fp) != dock_selected_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_selected); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_selected);
fclose(fp);
}

 idf++;
if ((fp=fopen( file_dock_type, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_type); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_type);
if (fwrite(DockTypeIs, sizeof(unsigned char), dock_type_size, fp) != dock_type_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_type); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_type);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_dock_net, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_net); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_net);
if (fwrite(DockNetIs, sizeof(unsigned char), dock_net_size, fp) != dock_net_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_net); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_net);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_name, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_name); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_name);
if (fwrite(DockName, sizeof(char), dock_name_size, fp) != dock_name_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_name); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_name);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_channels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_channels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_channels);
if (fwrite(FaderDockContains, sizeof(unsigned char), dock_channels_size, fp) != dock_channels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_channels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_channels);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_fader_locked, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_locked); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_locked);
if (fwrite(FaderLocked, sizeof(bool), fader_locked_size, fp) != fader_locked_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_locked); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_fader_locked);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_fader_locked_full, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_locked_full); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_locked_full);
if (fwrite(LockFader_is_FullLevel, sizeof(bool), fader_locked_full_size, fp) != fader_locked_full_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_locked_full); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_fader_locked_full);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_fader_before_lock, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_before_lock); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_before_lock);
if (fwrite(StateOfFaderBeforeLock, sizeof(unsigned char), fader_before_lock_size, fp) != fader_before_lock_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_before_lock); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_fader_before_lock);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_color_to_dock, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_color_to_dock); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_color_to_dock);
if (fwrite(colorpreset_linked_to_dock, sizeof(int), fader_color_to_dock_size, fp) != fader_color_to_dock_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_color_to_dock); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_color_to_dock);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_fader_audio, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_audio); b_report_error[idf]=1;}
else
{
int temp_array_audio[48*3][6];
for(int u=0;u<48;u++)
{
for(int l=0;l<6;l++)
{
temp_array_audio[u][l]=DockHasAudioVolume[u][l];
temp_array_audio[u+48][l]=DockHasAudioPan[u][l];
temp_array_audio[u+96][l]=DockHasAudioPitch[u][l];
}
}
sprintf(string_save_load_report[idf],"Opened file %s",file_fader_audio);
if (fwrite(temp_array_audio, sizeof(int), fader_audio_size, fp) != fader_audio_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_audio); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_audio);
fclose(fp);
}
idf++;


if ((fp=fopen( file_chaser_to_fader, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_to_fader); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chaser_to_fader);
if (fwrite( ChaserAffectedToDck, sizeof(int),fader_chaser_to_fader_size, fp) != fader_chaser_to_fader_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_to_fader); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_to_fader);
fclose(fp);
}
 idf++;


if ((fp=fopen(  file_mem_to_dock, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_mem_to_dock); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mem_to_dock);
if (fwrite(DockHasMem, sizeof(int), fader_mem_to_dock_size, fp) != fader_mem_to_dock_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_mem_to_dock); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_mem_to_dock);
fclose(fp);
}
 idf++;

if ((fp=fopen(  file_fader_fx, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_fx); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_fx);
if (fwrite(fader_mode_with_buffers, sizeof(int), fader_fx_size, fp) != fader_fx_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_fader_fx); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_fx);
fclose(fp);
}
 idf++;


if ((fp=fopen(  file_fader_route_fx, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_route_fx); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_route_fx);
if (fwrite(fader_fx_route, sizeof(bool), fader_route_fx_size, fp) != fader_route_fx_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_fader_route_fx); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_route_fx);
fclose(fp);
}
 idf++;

if ((fp=fopen(  file_fader_fgroup, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_fgroup); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_fgroup);
if (fwrite(fgroup, sizeof(bool),fader_fgroup_size, fp) !=fader_fgroup_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_fgroup); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_fgroup);
fclose(fp);
}
 idf++;

if ((fp=fopen(  file_fader_draw, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_draw); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_draw);
if (fwrite(DrawAffectedToDck, sizeof(int),fader_draw_size, fp) !=fader_draw_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_draw); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_draw);
fclose(fp);
}
 idf++;


if ((fp=fopen(  file_fader_echo, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_echo); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_echo);
if (fwrite(echo_affected_to_dock, sizeof(int),fader_echo_size, fp) !=fader_echo_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_echo); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_echo);
fclose(fp);
}
idf++;

if ((fp=fopen(  file_fader_damper_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_damper_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_damper_on);
if (fwrite(fader_damper_is_on, sizeof(bool),fader_damper_on_size, fp) !=fader_damper_on_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_damper_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_damper_on);
fclose(fp);
}
idf++;

int tmp_typ[48];
for(int i=0;i<48;i++)
{
    tmp_typ[i]=Fader_dampered[i].getdampermode();
}
if ((fp=fopen(  file_fader_damper_typ, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_damper_typ); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_damper_typ);
if (fwrite(tmp_typ, sizeof(int),fader_damper_typ_size, fp) !=fader_damper_typ_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_damper_typ); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_damper_typ);
fclose(fp);
}
idf++;

float tmp_data[96];
for(int i=0;i<48;i++)
{
    tmp_data[i]=Fader_dampered[i].getdecay();
    tmp_data[i+48]=Fader_dampered[i].getdt();
}
if ((fp=fopen(  file_fader_damper_levels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_fader_damper_levels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_fader_damper_levels);
if (fwrite(tmp_data, sizeof(float),fader_damper_levels_size, fp) !=fader_damper_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_damper_levels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_fader_damper_levels);
fclose(fp);
}
idf++;


int fader_damper_levels=96;//2x48 tmp 2 tableaux pour set decay et set dt en valeur 0 - 127*/


for(int i=0;i<48;i++)
{
    if(fader_damper_is_on[i]==1)
    {
     Fader_dampered[i].fix_all_damper_state_value(Fader[i]);
     Fader_dampered[i].set_target_val(Fader[i]);
    }
}

}

if(specify_who_to_save_load[13]==1)  //Faders LFOS//////////////////////////////////////////////////////////////////
{
if ((fp=fopen( file_dock_times, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_dock_times); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_times);
if (fwrite(time_per_dock, sizeof(float),dock_times_size, fp) != dock_times_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_dock_times); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_dock_times);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_is_for_loop_selected, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_is_for_loop_selected); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_is_for_loop_selected);
if (fwrite(is_dock_for_lfo_selected, sizeof(bool),size_is_for_loop_selected, fp) != size_is_for_loop_selected)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_is_for_loop_selected); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_is_for_loop_selected);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lfo_speed, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lfo_speed); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_lfo_speed);
if (fwrite(lfo_speed, sizeof(int),size_lfo_speed, fp) != size_lfo_speed)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_lfo_speed); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_lfo_speed);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lfo_mode_is, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lfo_mode_is); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_lfo_mode_is);
if (fwrite(lfo_mode_is, sizeof(int),size_lfo_mode_is, fp) !=  size_lfo_mode_is)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lfo_mode_is); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lfo_mode_is);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lfo_cycle_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lfo_cycle_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_lfo_cycle_on);
if (fwrite(lfo_cycle_is_on, sizeof(bool),size_lfo_cycle_on, fp) !=  size_lfo_cycle_on)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lfo_cycle_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lfo_cycle_on);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lfo_do_next_step, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lfo_do_next_step); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_lfo_do_next_step);
if (fwrite(lfo_do_next_step, sizeof(bool),size_lfo_do_next_step, fp) !=  size_lfo_do_next_step)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lfo_do_next_step); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lfo_do_next_step);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lfo_loop_step, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lfo_loop_step); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_lfo_loop_step);
if (fwrite(lfo_cycle_steps, sizeof(bool),size_lfo_loop_step, fp) !=  size_lfo_loop_step)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lfo_loop_step); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lfo_loop_step);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_fader_stoppos_levels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_stoppos_levels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_stoppos_levels);
if (fwrite(LevelStopPos, sizeof(unsigned char),fader_stoppos_size, fp) !=  fader_stoppos_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_stoppos_levels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_stoppos_levels);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_fader_stoppos_is, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_stoppos_is); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_stoppos_is);
if (fwrite(ActionnateStopOn, sizeof(bool),fader_stopposB_size, fp) != fader_stopposB_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_stoppos_is); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_stoppos_is);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_fader_ston_is, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_ston_is); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_ston_is);
if (fwrite(StopPosOn, sizeof(bool),fader_ston_size, fp) != fader_ston_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_ston_is); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_ston_is);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_fader_chas_autolaunch, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_chas_autolaunch); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_chas_autolaunch);
if (fwrite(autolaunch, sizeof(bool),fader_chas_autolaucnh_size, fp) !=fader_chas_autolaucnh_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_fader_chas_autolaunch); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_chas_autolaunch);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_fader_grid_affect, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_grid_affect); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_grid_affect);
if (fwrite(faders_dock_grid_affectation, sizeof(int),fader_grid_affect_size, fp) !=fader_grid_affect_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_fader_grid_affect); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_grid_affect);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[14]==1) ////////FADER CURVES///////////////////////////////////////////////////
{
if ((fp=fopen( file_fader_curve, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_curve); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_curve);
if (fwrite(FaderCurves, sizeof(int),fader_curve_size, fp) != fader_curve_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_curve); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_curve);
fclose(fp);
}
 idf++;
}
if(specify_who_to_save_load[15]==1)  ///////Minifaders Presets et LOCKS Presets////////////////////////////////////
{
if ((fp=fopen( file_fader_preset_selection, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_fader_preset_selection); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_fader_preset_selection);
if (fwrite(minifaders_preset_selection, sizeof(bool),fader_prst_sel_size, fp) != fader_prst_sel_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_fader_preset_selection); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_fader_preset_selection);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lock_preset_is, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_is); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_lock_preset_is);
if (fwrite(lock_preset, sizeof(bool), fader_lock_preset_is_size, fp) != fader_lock_preset_is_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lock_preset_is); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lock_preset_is);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lock_preset_state, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_state); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_lock_preset_state);
if (fwrite(FaderLocked_Preset, sizeof(bool), fader_lock_preset_state_size, fp) != fader_lock_preset_state_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lock_preset_state); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lock_preset_state);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lock_preset_masteris, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_masteris); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_lock_preset_masteris);
if (fwrite(LockFader_is_FullLevel_Preset, sizeof(bool), fader_lock_preset_masteris_size, fp) != fader_lock_preset_masteris_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lock_preset_masteris); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_lock_preset_masteris);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_lock_preset_levels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_lock_preset_levels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_lock_preset_levels);
if (fwrite(StateOfFaderBeforeLock_Preset, sizeof(unsigned char), fader_lock_preset_levels_size, fp) != fader_lock_preset_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lock_preset_levels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_lock_preset_levels);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[16]==1) ///////////////////////////////////CHASERS//////////////////////////////
{
if ((fp=fopen( file_chaser_name, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_name); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_name);
if (fwrite(chaser_name, sizeof(char),chaser_name_size, fp) != chaser_name_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_name); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chaser_name);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_timeunit, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_timeunit); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_timeunit);
if (fwrite(time_unit, sizeof(float),chaser_timeunit_size, fp) !=chaser_timeunit_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_timeunit); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chaser_timeunit);
fclose(fp);
}
 idf++;



if ((fp=fopen(file_chaser_stepop, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_stepop); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_stepop);
if (fwrite( chaser_step_operation, sizeof(int),chaser_stepop_size, fp) !=chaser_stepop_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_stepop); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_stepop);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_chaser_play, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_play); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_play);
if (fwrite( chaser_is_playing, sizeof(bool),chaser_isplaying_size, fp) !=chaser_isplaying_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_play); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_play);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_chaser_loop, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_loop); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_loop);
if (fwrite( chaser_is_in_loop, sizeof(bool), chaser_loop_size, fp) != chaser_loop_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_loop); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_loop);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_way, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_way); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_chaser_way);
if (fwrite( chaser_way, sizeof(bool),chaser_way_size, fp) != chaser_way_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chaser_way); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chaser_way);
fclose(fp);
}
 idf++;


if ((fp=fopen(  file_chaser_allerretour, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",  file_chaser_allerretour); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_chaser_allerretour);
if (fwrite( chaser_aller_retour, sizeof(bool),chaser_allerretour_size, fp) != chaser_allerretour_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",   file_chaser_allerretour); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_chaser_allerretour);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_chaser_trackon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_trackon);
if (fwrite( track_is_on, sizeof(bool),chaser_trackon_size, fp) != chaser_trackon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chaser_trackon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_trackon);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_tracklevel, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_tracklevel); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_tracklevel);
if (fwrite( track_level, sizeof(int),chaser_track_level_size, fp) != chaser_track_level_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_chaser_tracklevel); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_tracklevel);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_trackview, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackview); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_trackview);
if (fwrite( position_affichage_track_num, sizeof(int),chaser_trackview_size, fp) != chaser_trackview_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_trackview); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_trackview);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_tracktype, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_tracktype); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_tracktype);
if (fwrite( TrackTypeIs, sizeof(int),chaser_tracktype_size, fp) != chaser_tracktype_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_tracktype); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_tracktype);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_chaser_trackcontent, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_trackcontent); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_trackcontent);
if (fwrite(  TrackContains, sizeof(int),chaser_trackcontent_size, fp) != chaser_trackcontent_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_trackcontent); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_trackcontent);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_stepis, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_stepis); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_stepis);
if (fwrite(  chaser_step_is, sizeof(int),chaser_stepis_size, fp) != chaser_stepis_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_stepis); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_stepis);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_beginstep, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_beginstep); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_beginstep);
if (fwrite( chaser_begin_step_is, sizeof(int),chaser_stepbeg_size, fp) != chaser_stepbeg_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_beginstep); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_beginstep);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_endstep, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_chaser_endstep); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_chaser_endstep);
if (fwrite(chaser_end_step_is, sizeof(int),chaser_stepend_size, fp) !=chaser_stepend_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_endstep); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chaser_endstep);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_chaser_timemode, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_timemode); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_timemode);
if (fwrite(chaser_time_mode, sizeof(bool),chaser_timemode_size, fp) !=chaser_timemode_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_chaser_timemode); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_chaser_timemode);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_chaser_lastaffect, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_lastaffect); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_lastaffect);
if (fwrite( view_chaser_affected_to_fader, sizeof(int),chaser_lastaffect_size, fp) !=chaser_lastaffect_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_lastaffect); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_lastaffect);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_trrackname, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_trrackname); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_trrackname);
if (fwrite( chaser_track_name, sizeof(char),chaser_tracksname_size, fp) !=chaser_tracksname_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_trrackname); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_trrackname);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_chaser_presets, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_presets); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_presets);
if (fwrite( chaser_preset, sizeof(bool),chaser_presets_size, fp) !=chaser_presets_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_presets); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_presets);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_chaser_lchpad_pos, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_lchpad_pos); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_lchpad_pos);
if (fwrite( chaser_step_launchpad, sizeof(int),chaser_lchpad_pos_size, fp) !=chaser_lchpad_pos_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_lchpad_pos); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_lchpad_pos);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_chaser_acceleroslave, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_acceleroslave); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_acceleroslave);
if (fwrite( index_slave_chaser_to_accelerometre, sizeof(bool),chaser_acceleroslave_size, fp) !=chaser_acceleroslave_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_acceleroslave); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_acceleroslave);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_chaser_has_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_chaser_has_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_chaser_has_mem);
if (fwrite( TrackHasMem, sizeof(int),chaser_has_mem_size, fp) !=chaser_has_mem_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_chaser_has_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_chaser_has_mem);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[17]==1)  ///////MIDI AFFECTATION/////////////////////////////////////////////////////////////
{
if ((fp=fopen( file_midi_affectation, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_midi_affectation); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_midi_affectation);
if (fwrite(miditable, sizeof(int),midi_affectation_size, fp) != midi_affectation_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_midi_affectation); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_midi_affectation);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_midi_send_out, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_midi_send_out); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_midi_send_out);
if (fwrite(midi_send_out, sizeof(bool),midi_send_out_size, fp) != midi_send_out_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_midi_send_out); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_midi_send_out);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[18]==1)  ////////////MIDI cheat midi ///////////////////////////////////////////
{
if ((fp=fopen( file_midi_properties, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_midi_properties); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_midi_properties);
if (fwrite(midi_change_vel_type, sizeof(int),midi_properties_size, fp) != midi_properties_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_midi_properties); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_midi_properties);
fclose(fp);
}


if ((fp=fopen( file_midi_clock, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_midi_clock); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_midi_clock);
if(fwrite (bpm_personnal, sizeof(int),midi_clock_size, fp) != midi_clock_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_midi_clock); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_midi_clock);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[19]==1)  ///////////////////TRICHRO////////////////////////////////////////////////
{
if ((fp=fopen( file_dock_color_type, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_type); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_type);
if (fwrite(dock_color_type, sizeof(bool), dock_color_type_size, fp) != dock_color_type_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_type); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_type);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_color_xy, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_xy); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_xy);
if (fwrite(x_y_picker_par_colordock, sizeof(int), dock_color_xy_size, fp) != dock_color_xy_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_xy); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_xy);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_color_angle, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_angle); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_angle);
if (fwrite(angle_hue_par_colordock, sizeof(float), dock_color_angle_size, fp) != dock_color_angle_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_angle); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_angle);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_color_picker, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_picker); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_dock_color_picker);
if (fwrite(picker_trichro, sizeof(int), dock_color_picker_size, fp) != dock_color_picker_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_picker); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_picker);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_color_ch, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_ch); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_dock_color_ch);
if (fwrite(dock_color_channels, sizeof(bool), dock_color_ch_size, fp) != dock_color_ch_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_ch); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_ch);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_dock_color_buffer, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_dock_color_buffer); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_dock_color_buffer);
if (fwrite(dock_color_buffer_C, sizeof(unsigned char), dock_color_buffer_size, fp) != dock_color_buffer_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_dock_color_buffer); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_dock_color_buffer);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[20]==1)  //////////VIDEO TRACKING //////////////////////////////////////////////
{
if ((fp=fopen( file_video_channels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_channels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_video_channels);
if (fwrite(tracking_contents, sizeof(bool), video_channels_size, fp) != video_channels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_video_channels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_video_channels);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_video_xy, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_xy); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_video_xy);
if (fwrite(tracking_coordonates, sizeof(int), video_xy_size, fp) != video_xy_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_video_xy); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_video_xy);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_video_spaces_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_video_spaces_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_video_spaces_on);
if (fwrite(tracking_spaces_on_off, sizeof(bool), video_spaces_on_size, fp) != video_spaces_on_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_video_spaces_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_video_spaces_on);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_camera_modes, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_camera_modes); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",file_camera_modes);
if (fwrite(camera_modes_and_settings, sizeof(int), camera_modes_size, fp) != camera_modes_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_camera_modes); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_camera_modes);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[21]==1)  //ARDUINO//////////////////////////////////////////////////////////
{
if ((fp=fopen( file_arduino_dig_typ, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_dig_typ); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_dig_typ);
if (fwrite(  arduino_digital_type, sizeof(int),arduino_dig_typ_size, fp) !=  arduino_dig_typ_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_arduino_dig_typ); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_arduino_dig_typ);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_arduino_dig_affect, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_dig_affect); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_dig_affect);
if (fwrite(  arduino_digital_function_input, sizeof(int),arduino_dig_aff_size, fp) !=  arduino_dig_aff_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_arduino_dig_affect); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_arduino_dig_affect);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_arduino_an_typ, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_an_typ); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_an_typ);
if (fwrite(  arduino_analog_function_input, sizeof(int),arduino_an_typ_size, fp) !=  arduino_an_typ_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_arduino_an_typ); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_arduino_an_typ);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_arduino_an_aff, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_an_aff); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_an_aff);
if (fwrite( arduino_analog_attribution_input, sizeof(int),arduino_an_aff_size, fp) !=  arduino_an_aff_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_arduino_an_aff); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_arduino_an_aff);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_arduino_an_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_arduino_an_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_an_on);
if (fwrite( ventilate_analog_data, sizeof(bool),arduino_an_on_size, fp) !=  arduino_an_on_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_arduino_an_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_arduino_an_on);
fclose(fp);
}
 idf++;



if ((fp=fopen( file_arduino_dig_out, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_dig_out); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_dig_out);
if (fwrite( arduino_digital_function_output, sizeof(int),arduino_dig_out_size, fp) != arduino_dig_out_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_arduino_dig_out); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_arduino_dig_out);
fclose(fp);
}
idf++;


if ((fp=fopen( file_arduino_kalman_param, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_kalman_param); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_kalman_param);
if (fwrite(  kalman_params, sizeof(double),arduino_kalman_param_size, fp) != arduino_kalman_param_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_arduino_kalman_param); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_arduino_kalman_param);
fclose(fp);
}
idf++;

if ((fp=fopen( file_arduino_kalman_on, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_arduino_kalman_on); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_arduino_kalman_on);
if (fwrite(  kalman_is_on, sizeof(bool),arduino_kalman_on_size, fp) != arduino_kalman_on_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_arduino_kalman_on); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_arduino_kalman_on);
fclose(fp);
}
idf++;

Save_Arduino_Config();
 idf++;
}

if(specify_who_to_save_load[22]==1)  ////////////AUDIO CONF/////////////////////////////////////////////////
{
bool temp_audio_array[8];
for(int i=0;i<4;i++)
{
temp_audio_array[i]=audio_autoload[i];
temp_audio_array[i+4]=audio_autopause[i];
}
if ((fp=fopen( file_audio_autoloadpause, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_autoloadpause); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_audio_autoloadpause);
if (fwrite( temp_audio_array, sizeof(bool),audio_autoloadpause_size, fp) != audio_autoloadpause_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_audio_autoloadpause); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_audio_autoloadpause);
fclose(fp);
}
idf++;

if ((fp=fopen( file_audio_filenumber, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_filenumber); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_audio_filenumber);
if (fwrite( player_has_file_coming_from_pos, sizeof(int),audio_filenumber_size, fp) != audio_filenumber_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_audio_filenumber); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_audio_filenumber);
fclose(fp);
}
idf++;

for(int i=0;i<4;i++)
{
player_position_on_save[i]= position_of_file_in_player[i];
}
if ((fp=fopen( file_audio_playerposition, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_audio_playerposition); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_audio_playerposition);
if (fwrite( player_position_on_save, sizeof(int),audio_playerposition_size, fp) != audio_playerposition_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_audio_playerposition); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_audio_playerposition);
fclose(fp);
}
idf++;




Save_Audio_Conf()  ;
idf++;
}


if(specify_who_to_save_load[23]==1)  //////////iCAT///////////////////////////////////////////////////////
{

if ((fp=fopen( file_icat_nbsliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbsliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_icat_nbsliders);
if (fwrite( iCat_nbre_de_sliders, sizeof(int), icat_nbsliders_size, fp) != icat_nbsliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_nbsliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_icat_nbsliders);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_icat_posliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_posliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_icat_posliders);
if (fwrite(  iCat_pos_slider, sizeof(int),icat_posliders_size, fp) != icat_posliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_icat_posliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_posliders);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_icat_orsliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_orsliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_icat_orsliders);
if (fwrite(  iCat_orientation_slider, sizeof(bool),icat_orsliders_size, fp) !=icat_orsliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_orsliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_orsliders);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_typsliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_typsliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_icat_typsliders);
if (fwrite(  iCat_affectation_slider_type_is, sizeof(int),icat_typsliders_size, fp) !=icat_typsliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_typsliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_typsliders);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_valsliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_valsliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_icat_valsliders);
if (fwrite( iCat_affectation_slider_value_is, sizeof(int),icat_valsliders_size, fp) !=icat_valsliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_valsliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_valsliders);
fclose(fp);
}
 idf++;


if ((fp=fopen(file_icat_size_sliders, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_size_sliders); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_icat_size_sliders);
if (fwrite( ratio_iCat_slider, sizeof(int),icat_sizesliders_size, fp) !=icat_sizesliders_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_size_sliders); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_size_sliders);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_orientpage, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_orientpage); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_icat_orientpage);
if (fwrite( iCat_preset_orientation, sizeof(int),icat_orpage_size, fp) !=icat_orpage_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_orientpage); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_orientpage);
fclose(fp);
}
 idf++;


if ((fp=fopen(file_icat_nbbutton, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbbutton); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_icat_nbbutton);
if (fwrite( iCat_nbre_de_boutons, sizeof(int),icat_nbbutton_size, fp) !=icat_nbbutton_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_nbbutton); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_nbbutton);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_pobutton, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_pobutton); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_pobutton);
if (fwrite( iCat_pos_bouton, sizeof(int),icat_pobutton_size, fp) !=icat_pobutton_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_pobutton); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_icat_pobutton);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_size_buttons, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_size_buttons); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_size_buttons);
if (fwrite( ratio_iCat_button, sizeof(int),icat_sizebuttons_size, fp) !=icat_sizebuttons_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_size_buttons); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_icat_size_buttons);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_icat_typbutton, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_icat_typbutton); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_icat_typbutton);
if (fwrite(  iCat_affectation_bouton_type_is, sizeof(int), icat_typbutton_size, fp) != icat_typbutton_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_typbutton); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_typbutton);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_actbutton, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_actbutton); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_actbutton);
if (fwrite( iCat_affectation_bouton_action_is, sizeof(int),icat_actbutton_size, fp) !=icat_actbutton_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_actbutton); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_icat_actbutton);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_valbutton, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valbutton); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_valbutton);
if (fwrite( iCat_affectation_bouton_value_is, sizeof(int),icat_valbutton_size, fp) !=icat_valbutton_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_valbutton); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_valbutton);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_nbstr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbstr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_nbstr);
if (fwrite( iCat_nbre_de_strings, sizeof(int),icat_nbstr_size, fp) !=icat_nbstr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_nbstr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_nbstr);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_posstr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_posstr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_posstr);
if (fwrite( iCat_pos_string, sizeof(int),icat_posstr_size, fp) !=icat_posstr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_posstr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_posstr);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_sizestr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_sizestr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_sizestr);
if (fwrite( ratio_iCat_string, sizeof(int),icat_sizestr_size, fp) !=icat_sizestr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_sizestr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_sizestr);
fclose(fp);
}
 idf++;


if ((fp=fopen(file_icat_typstr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_typstr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_typstr);
if (fwrite(iCat_affectation_string_type_is, sizeof(int),icat_typstr_size, fp) !=icat_typstr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_typstr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_typstr);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_actstr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_actstr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_actstr);
if (fwrite(iCat_affectation_string_action_is, sizeof(int),icat_actstr_size, fp) !=icat_actstr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_icat_actstr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_actstr);
fclose(fp);
}
 idf++;

if ((fp=fopen(file_icat_valstr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valstr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_valstr);
if (fwrite(iCat_affectation_string_value_is, sizeof(int),icat_valstr_size, fp) !=icat_valstr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_valstr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_valstr);
fclose(fp);
}
 idf++;

 if ((fp=fopen(file_icat_nbzon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_nbzon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_nbzon);
if (fwrite(iCat_nbre_de_tracking_zone, sizeof(int),icat_nbzon_size, fp) !=icat_nbzon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_nbzon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_nbzon);
fclose(fp);
}
 idf++;

  if ((fp=fopen(file_icat_poszon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_poszon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_poszon);
if (fwrite(iCat_pos_trackzone, sizeof(int),icat_poszon_size, fp) !=icat_poszon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_poszon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_poszon);
fclose(fp);
}
 idf++;

 if ((fp=fopen(file_icat_sizezon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_sizezon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_sizezon);
if (fwrite(ratio_iCat_trackzone, sizeof(int),icat_sizezon_size, fp) !=icat_sizezon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_sizezon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_sizezon);
fclose(fp);
}
 idf++;

  if ((fp=fopen(file_icat_typzon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_typzon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_typzon);
if (fwrite(iCat_trackzone_type_is, sizeof(int),icat_typzon_size, fp) !=icat_typzon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_typzon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_typzon);
fclose(fp);
}
 idf++;


   if ((fp=fopen(file_icat_valzon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_valzon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_valzon);
if (fwrite(iCat_trackzone_affectation_is, sizeof(int),icat_valzon_size, fp) !=icat_valzon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_valzon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_valzon);
fclose(fp);
}
 idf++;



   if ((fp=fopen(file_icat_posTRCKzon, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_icat_posTRCKzon); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_icat_posTRCKzon);
if (fwrite( pos_iCat_tracker, sizeof(int),icat_posTRCKzon_size, fp) !=icat_posTRCKzon_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",file_icat_posTRCKzon); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_icat_posTRCKzon);
fclose(fp);
}
 idf++;


}

if(specify_who_to_save_load[24]==1)  //POS WINDOWS USER/////////////////////////////////////////////////////
{
if ((fp=fopen( file_pos_fenetres, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_pos_fenetres); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_pos_fenetres);
if (fwrite(windows_position, sizeof(int),index_pos_fenetre_size, fp) !=  index_pos_fenetre_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_pos_fenetres); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_pos_fenetres);
fclose(fp);
}
 idf++;
Save_Window_Conf();//position

 idf++;
 //window conf
 if ((fp=fopen( file_windows, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_windows); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_windows);
if (fwrite(window_opened, sizeof(int),windows_size, fp) != windows_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_windows); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_windows);
fclose(fp);
}
idf++;

}

if(specify_who_to_save_load[25]==1)  //USER COLOR PROFILE//////////////////////////////////////////////////
{
if ((fp=fopen( file_color_profile, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_color_profile); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_color_profile);
if (fwrite( couleurs_user, sizeof(float),color_profile_size, fp) !=  color_profile_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_color_profile); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_color_profile);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[26]==1)  //KBD ASCII MAPING/////////////////////////////////////////////////////
{
if ((fp=fopen( file_kbd_ascii_map, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_kbd_ascii_map); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_kbd_ascii_map);
if (fwrite( mapping_temporaire, sizeof(int),kbd_ascii_map_size, fp) !=kbd_ascii_map_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_kbd_ascii_map); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",file_kbd_ascii_map);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[27]==1)   //////////INDEXES/////////////////////////////////////////////////////
{
write_indexes();//preparation du tableau

if ((fp=fopen( file_divers_index, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_divers_index); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",   file_divers_index);
if (fwrite(index_report_customs, sizeof(int),index_size, fp) !=  index_size)
{ sprintf(string_save_load_report[idf],"Error writting %s",  file_divers_index); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s",  file_divers_index);
fclose(fp);
}
 idf++;
}

if(specify_who_to_save_load[28]==1)  ////////////MOVER////////////////////////////////////////////////////////
{
if ((fp=fopen( file_mover_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mover_mem); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_mem);
if (fwrite(dock_move_xy, sizeof(int), mover_mem_saving_size, fp) != mover_mem_saving_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_mem); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_mem);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_mem16b, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mover_mem16b);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_mem16b);
if (fwrite(dock_move_xy_16b, sizeof(int), mover_mem_saving_size, fp) != mover_mem_saving_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_mem16b);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_mem16b);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_numbersteps, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mover_numbersteps);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_numbersteps);
if (fwrite(dock_moves_contains_steps, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_numbersteps);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_numbersteps);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_stepis, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mover_stepis);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_stepis);
if (fwrite(dock_move_actual_step, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_stepis);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_stepis);
fclose(fp);
}
 idf++;


valeurs_diverses[0]=invX_on;
valeurs_diverses[1]=invY_on;
valeurs_diverses[2]=Tracker_speedlevel;
valeurs_diverses[3]=dock_move_selected;
valeurs_diverses[9]=joy_sensitivity;*/
valeurs_diverses[13]=position_defaut[0];
valeurs_diverses[14]=position_defaut[1];
valeurs_diverses[15]=index_spline;

if ((fp=fopen( file_mover_divers, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_mover_divers);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_divers);
if (fwrite(valeurs_diverses, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_divers);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_divers);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_spline_ratio, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_spline_ratio);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_spline_ratio);
if (fwrite(spline_ratio, sizeof(float), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_spline_ratio);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_spline_ratio);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_asservis_mem, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_asservis_mem);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_asservis_mem);
if (fwrite(dock_asservis, sizeof(int), mover_asservis_saving_size, fp) != mover_asservis_saving_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_asservis_mem);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_asservis_mem);
fclose(fp);
}
 idf++;


if ((fp=fopen( file_mover_time, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_time);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_time);
if (fwrite(dock_time, sizeof(int), mover_time_size, fp) != mover_time_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_time);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_time);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_autostop, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_autostop);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_autostop);
if (fwrite(move_auto_stop, sizeof(bool), mover_autostop_size, fp) != mover_autostop_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_autostop);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_autostop);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_goto, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_goto);
if (fwrite(GotoMoves, sizeof(int), mover_goto_size, fp) != mover_goto_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_goto);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_mover_into, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_into);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_into);
if (fwrite(Moves_Inpoint, sizeof(int), mover_little_32file_size, fp) != mover_little_32file_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_into);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_into);
fclose(fp);
}
 idf++;

 if ((fp=fopen( file_mover_params, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_mover_params);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_mover_params);
if (fwrite(mover_params_adresses, sizeof(int), mover_param_size, fp) != mover_param_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_mover_params);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_mover_params);
fclose(fp);
}
 idf++;



}


if(specify_who_to_save_load[29]==1)
{
idf++; */


for(int iu=0;iu<32;iu++)
{
for (int st=0;st<1024;st++)
{
for (int ct=0;ct<513;ct++)
{
temp_grid_levels_for_save[iu][st][ct]=grid_levels[iu][st][ct];
}
}
}

if ((fp=fopen( file_grid_levels_1, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_levels_1);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_levels_1);
if (fwrite(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) != grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_levels_1);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_levels_1);
fclose(fp);
}
idf++;

for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
temp_grid_levels_for_save[i][s][c]=grid_levels[32+i][s][c];
}
}
}
if ((fp=fopen( file_grid_levels_2, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_levels_2);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_levels_2);
if (fwrite(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) != grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_levels_2);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_levels_2);
fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
temp_grid_levels_for_save[i][s][c]=grid_levels[64+i][s][c];
}
}
}
if ((fp=fopen( file_grid_levels_3, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_levels_3);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_levels_3);
if (fwrite(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) != grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_levels_3);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_levels_3);
fclose(fp);
}
idf++;
for(int i=0;i<32;i++)
{
for (int s=0;s<1024;s++)
{
for (int c=0;c<513;c++)
{
temp_grid_levels_for_save[i][s][c]=grid_levels[96+i][s][c];
}
}
}
if ((fp=fopen( file_grid_levels_4, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_levels_4);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_levels_4);
if (fwrite(temp_grid_levels_for_save, sizeof(unsigned char), grid_levels_size, fp) != grid_levels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_levels_4);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_levels_4);
fclose(fp);
}
idf++;

if ((fp=fopen( file_grid_times, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_times);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_times);
if (fwrite(grid_times, sizeof(float), grid_times_size, fp) != grid_times_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_times);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_times);
fclose(fp);
}
idf++;
if ((fp=fopen( file_grid_goto, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_goto);
if (fwrite(grid_goto, sizeof(int), grid_goto_size, fp) != grid_goto_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_goto);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_grid_seekpos, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_seekpos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_seekpos);
if (fwrite(grid_seekpos, sizeof(int), grid_seekpos_size, fp) != grid_seekpos_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_seekpos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_seekpos);
fclose(fp);
}
 idf++;
 if ((fp=fopen( file_grid_stoplay, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_stoplay);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_stoplay);
if (fwrite(grid_stoplay, sizeof(bool), grid_stoplay_size, fp) != grid_stoplay_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_stoplay);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_stoplay);
fclose(fp);
}
 idf++;
  if ((fp=fopen( file_grid_names, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_names);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_names);
if (fwrite(grider_name, sizeof(char), grid_names_size, fp) != grid_names_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_names);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_names);
fclose(fp);
}
 idf++;

if ((fp=fopen( file_gridpl_grid, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_grid);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_grid);
if (fwrite(index_grider_selected, sizeof(int), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_grid);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_grid);
fclose(fp);
}
 idf++;
if ((fp=fopen( file_gridpl_step, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_step);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_step);
if (fwrite(index_grider_step_is, sizeof(int), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_step);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_step);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_autost, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_autost);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_autost);
if (fwrite(grider_autostopmode, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_autost);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_autost);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_goto, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_goto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_goto);
if (fwrite(grider_goto_mode, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_goto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_goto);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_seekto, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_seekto);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_seekto);
if (fwrite(grider_seekto_mode, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_seekto);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_seekto);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_stpl, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_stpl);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_stpl);
if (fwrite(grider_stoplay_mode, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_stpl);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_stpl);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_slave, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_slave);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_slave);
if (fwrite(grid_player_slave, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_slave);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_slave);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_show, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_show);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_show);
if (fwrite( index_show_grid_player, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_show);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_show);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_accel, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_accel);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_accel);
if (fwrite( grid_crossfade_speed, sizeof(int), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_accel);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_accel);
fclose(fp);
}
idf++;
if ((fp=fopen( file_gridpl_countmod, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_countmod);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_countmod);
if (fwrite( grider_count_mode, sizeof(bool), gridpl_size, fp) != gridpl_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_countmod);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_countmod);
fclose(fp);
}
idf++;

if ((fp=fopen( file_gridpl_snapfader, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_snapfader);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_snapfader);
if (fwrite( GplSnapFader, sizeof(int), gridpl_snapfader_size, fp) != gridpl_snapfader_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_snapfader);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_snapfader);
fclose(fp);
}
idf++;

int grider_conf[3];
grider_conf[0]=grider_begin_channel_is;
grider_conf[1]=grider_nb_col;
grider_conf[2]=grider_nb_row;
if ((fp=fopen( file_grider_conf, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grider_conf);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grider_conf);
if (fwrite( grider_conf, sizeof(int), grider_conf_size, fp) != grider_conf_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grider_conf);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grider_conf);
fclose(fp);
}
idf++;

int grider_report_cross[8];
for(int gr=0;gr<4;gr++)
{
grider_report_cross[gr]=grid_niveauX1[gr];
grider_report_cross[gr+4]=grid_niveauX2[gr];
}
if ((fp=fopen(file_gridpl_crosslv, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_gridpl_crosslv);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_gridpl_crosslv);
if (fwrite( grider_report_cross, sizeof(int), gridpl_croslv_size, fp) != gridpl_croslv_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_gridpl_crosslv);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_gridpl_crosslv);
fclose(fp);
}
idf++;


if ((fp=fopen(file_grid_count, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_count);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_count);
if (fwrite( grid_count, sizeof(int), grid_count_size, fp) !=grid_count_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_count);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_count);
fclose(fp);
}
idf++;

if ((fp=fopen(file_grided_count, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grided_count);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grided_count);
if (fwrite( grid_counted_times, sizeof(int), grid_counted_size, fp) !=grid_counted_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grided_count);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grided_count);
fclose(fp);
}
idf++;


}//fin grid


if(specify_who_to_save_load[30]==1)
{
if ((fp=fopen(file_grid_in_mems, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_grid_in_mems);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_grid_in_mems);
if (fwrite( set_from_seq_gridplayer1_next_step, sizeof(int),grid_in_mems_size, fp) !=grid_in_mems_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_grid_in_mems);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_grid_in_mems);
fclose(fp);
}
idf++;
}
rest(10);


if(specify_who_to_save_load[31]==1)
{
if ((fp=fopen(file_lib_sizes_symbol, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lib_sizes_symbol);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_lib_sizes_symbol);
if (fwrite(  size_symbol, sizeof(float),lib_sizes_symbol_size, fp) !=lib_sizes_symbol_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lib_sizes_symbol);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lib_sizes_symbol);
fclose(fp);
}
idf++;
if ((fp=fopen(file_lib_names_symbol, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_lib_names_symbol);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_lib_names_symbol);
if (fwrite(  symbol_nickname, sizeof(char),lib_names_symbol_size, fp) !=lib_names_symbol_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_lib_names_symbol);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_lib_names_symbol);
fclose(fp);
}
idf++;
if ((fp=fopen(file_plot_angles, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_angles);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_angles);
if (fwrite(  angle_symbol, sizeof(float),plot_angle_size, fp) !=plot_angle_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_angles);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_angles);
fclose(fp);
}
idf++;
if ((fp=fopen(file_plot_positions, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_positions);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_positions);
if (fwrite(  pos_symbol, sizeof(int),plot_positions_size, fp) !=plot_positions_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_positions);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_positions);
fclose(fp);
}
idf++;
if ((fp=fopen(file_plot_nbr_symbols, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_nbr_symbols);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_angles);
if (fwrite(  nbre_symbols_on_plot, sizeof(int),plot_nbr_symbols_size, fp) !=plot_nbr_symbols_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_nbr_symbols);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_nbr_symbols);
fclose(fp);
}
idf++;
if ((fp=fopen(file_plot_typ, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_typ);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_typ);
if (fwrite(  symbol_type, sizeof(int),plot_typ_size, fp) !=plot_typ_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_typ);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_typ);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_chan, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_chan);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_chan);
if (fwrite(  symbol_channel_is, sizeof(int),plot_chan_size, fp) !=plot_chan_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_chan);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_chan);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_dim, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_dim);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_dim);
if (fwrite(  symbol_dimmer_is, sizeof(int),plot_dim_size, fp) !=plot_dim_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_dim);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_dim);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_gels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_gels);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_gels);
if (fwrite(  gelat, sizeof(int),plot_gels_size, fp) !=plot_gels_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_gels);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_gels);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_gels_t, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_gels_t);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_gels_t);
if (fwrite(  gelat_family, sizeof(int),plot_gels_t_size, fp) !=plot_gels_t_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_gels_t);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_gels_t);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_view, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_view);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_view);
if (fwrite(  show_calc_number, sizeof(bool),plot_view_size, fp) !=plot_view_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_view);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_view);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_options_view, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_options_view);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_options_view);
if (fwrite(  plot_show_options, sizeof(bool),plot_view_options_size, fp) !=plot_view_options_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_options_view);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_options_view);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_opt_xy, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_opt_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_opt_xy);
if (fwrite( relatif_plot_xy, sizeof(int),plot_opt_xy_size, fp) !=plot_opt_xy_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_opt_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_opt_xy);
fclose(fp);
}
idf++;


if ((fp=fopen(file_plot_shape_type, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_type);
if (fwrite( shape_type, sizeof(int),plot_shape_type_size, fp) !=plot_shape_type_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_type);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_attr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_attr);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_attr);
if (fwrite( shape_attributes, sizeof(float),plot_shape_attr_size, fp) !=plot_shape_attr_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_attr);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_attr);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_pos, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_pos);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_pos);
if (fwrite( shape_position, sizeof(int),plot_shape_pos_size, fp) !=plot_shape_pos_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_pos);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_pos);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_legend_name, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_legend_name);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_legend_name);
if (fwrite( shape_legend_name, sizeof(char),plot_shape_legend_name_size, fp) !=plot_shape_legend_name_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_legend_name);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_legend_name);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_relativ_xy, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_relativ_xy);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_relativ_xy);
if (fwrite( shape_relativ_position_legend_name, sizeof(int),plot_shape_relativ_xy_size, fp) !=plot_shape_relativ_xy_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_relativ_xy);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_relativ_xy);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_color_type, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_color_type);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_color_type);
if (fwrite( shape_color_type, sizeof(int),plot_shape_color_type_size, fp) !=plot_shape_color_type_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_color_type);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_color_type);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_shape_groups, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_shape_groups);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_shape_groups);
if (fwrite( shape_groups, sizeof(int),plot_shape_groups_size, fp) !=plot_shape_groups_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_shape_groups);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_shape_groups);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_symbols_relativgroups, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symbols_relativgroups);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_symbols_relativgroups);
if (fwrite( plot_relativxy_preset, sizeof(int),plot_symbols_relativgroups_size, fp) !=plot_symbols_relativgroups_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_symbols_relativgroups);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_symbols_relativgroups);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_symbols_notes, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symbols_notes);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_symbols_notes);
if (fwrite( symbol_note, sizeof(char),plot_symbols_notes_size, fp) !=plot_symbols_notes_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_symbols_notes);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_symbols_notes);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_legend, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_legend);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_legend);
if (fwrite( plot_renseignements, sizeof(char),plot_legend_size, fp) !=plot_legend_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_legend);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_legend);
fclose(fp);
}
idf++;

if ((fp=fopen(file_plot_symb_linked, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s",file_plot_symb_linked);b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s", file_plot_symb_linked);
if (fwrite( symbol_is_linked_to, sizeof(int),plot_symb_linked_size, fp) !=plot_symb_linked_size)
{ sprintf(string_save_load_report[idf],"Error writting %s", file_plot_symb_linked);b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_plot_symb_linked);
fclose(fp);
}
idf++;

Save_Plot_Plan_config();
idf++;
}

if(specify_who_to_save_load[32]==1)
{
if ((fp=fopen( file_draw_presetsz, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_presetsz); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_draw_presetsz);
if (fwrite(draw_preset_parameters, sizeof(int),draw_presetsz_size, fp) !=  draw_presetsz_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_draw_presetsz); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_draw_presetsz);
fclose(fp);
}
idf++;

if ((fp=fopen( file_draw_levels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_levels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_draw_levels);
if (fwrite(draw_preset_levels, sizeof(float),draw_levels_size, fp) !=  draw_levels_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_draw_levels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_draw_levels);
fclose(fp);
}
idf++;

if ((fp=fopen( file_draw_chrouting, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_draw_chrouting); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_draw_chrouting);
if (fwrite(draw_preset_channel_routing, sizeof(int),draw_chrouting_size, fp) !=  draw_chrouting_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_draw_chrouting); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_draw_chrouting);
fclose(fp);
}
idf++;


save_draw_preset_config();
idf++;

}


if(specify_who_to_save_load[33]==1)
{
if ((fp=fopen( file_echo_pointing_fader, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_pointing_fader); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_pointing_fader);
if (fwrite(echo_pointing_fader_num, sizeof(int),echo_pointing_fader_size, fp) !=  echo_pointing_fader_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_pointing_fader); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_pointing_fader);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_echo_mode, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_echo_mode); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_echo_mode);
if (fwrite(echo_is_echo_mode, sizeof(bool),echo_echo_mode_size, fp) !=  echo_echo_mode_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_echo_mode); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_echo_mode);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_global_param, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_global_param); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_global_param);
if (fwrite(echo_global_params, sizeof(float),echo_global_param_size, fp) !=  echo_global_param_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_global_param); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_global_param);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_channel_man_mode, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_channel_man_mode); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_channel_man_mode);
if (fwrite(echo_channel_manipulate_mode, sizeof(bool),echo_channel_man_mode_size, fp) !=  echo_channel_man_mode_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_channel_man_mode); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_channel_man_mode);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_chan_pos, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_chan_pos); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_chan_pos);
if (fwrite(echo_grid_channel_position, sizeof(int),echo_chan_pos_size, fp) !=  echo_chan_pos_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_chan_pos); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_chan_pos);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_levels, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_levels); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_levels);
if (fwrite(echo_levels, sizeof(float),echo_levels_size, fp) !=  echo_levels_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_levels); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_levels);
fclose(fp);
}
idf++;


if ((fp=fopen( file_echo_bounce, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_bounce); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_bounce);
if (fwrite(do_bounce, sizeof(bool),echo_bounce_size, fp) !=  echo_bounce_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_bounce); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_bounce);
fclose(fp);
}
idf++;

if ((fp=fopen( file_echo_presets, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_echo_presets); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_echo_presets);
if (fwrite(snap_echo_to_recall, sizeof(float),echo_presets_size, fp) !=  echo_presets_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_echo_presets); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_echo_presets);
fclose(fp);
}
idf++;
}


if(specify_who_to_save_load[34]==1)
{
if ((fp=fopen( file_wave_ch_slots, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_ch_slots); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_wave_ch_slots);
if (fwrite(channel_slots, sizeof(int),wave_ch_slots_size, fp) !=  wave_ch_slots_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_wave_ch_slots); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_wave_ch_slots);
fclose(fp);
}
idf++;

if ((fp=fopen( file_wave_brush_slots, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_brush_slots); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_wave_brush_slots);
if (fwrite(brush_slots, sizeof(float),wave_brush_slots_size, fp) !=  wave_brush_slots_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_wave_brush_slots); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_wave_brush_slots);
fclose(fp);
}
idf++;

if ((fp=fopen( file_wave_brush_pr, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_brush_pr); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_wave_brush_pr);
if (fwrite(lead_brush_reading, sizeof(int),wave_brush_pr_size, fp) !=  wave_brush_pr_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_wave_brush_pr); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_wave_brush_pr);
fclose(fp);
}
idf++;

float tmp_fl[2];
tmp_fl[0]=Wave_Dampered[0].getdecay();
tmp_fl[1]=Wave_Dampered[0].getdt();


if ((fp=fopen( file_wave_damp_decay, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_wave_damp_decay); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_wave_damp_decay);
if (fwrite(tmp_fl, sizeof(float),wave_damp_decay_size, fp) !=  wave_damp_decay_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_wave_damp_decay); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_wave_damp_decay);
fclose(fp);
}


}


if(specify_who_to_save_load[35]==1)
{

if ((fp=fopen( file_save_preset, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_save_preset); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_save_preset);
if (fwrite(preset_specify_who_to_save_load, sizeof(bool),save_preset_size, fp) !=  save_preset_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_save_preset); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_save_preset);
fclose(fp);
}
idf++;

if ((fp=fopen( file_save_pdf, "wb"))==NULL)
{ sprintf(string_save_load_report[idf],"Error opening file %s", file_save_pdf); b_report_error[idf]=1;}
else
{
sprintf(string_save_load_report[idf],"Opened file %s",  file_save_pdf);
if (fwrite(specify_who_to_save_PDF, sizeof(bool),save_pdf_size, fp) !=  save_pdf_size)
{
sprintf(string_save_load_report[idf],"Error writting %s", file_save_pdf); b_report_error[idf]=1;}
else sprintf(string_save_load_report[idf],"Saved file %s", file_save_pdf);
fclose(fp);
}
idf++;

}


strcpy(rep,"");
sprintf(rep,"%s",mondirectory);
chdir (rep);

Save_Launchpad_RetroLight();

if(specify_who_to_save_load[22]==1)
{Save_audiofiles_cues(); idf++; }
strcpy(rep,"");
sprintf(rep,"%s",mondirectory);
chdir (rep);
detect_error_on_save_load();
if(there_is_an_error_on_save_load==1){index_show_save_load_report=1;} else {index_show_save_load_report=0;}

index_is_saving=0;
return(0);
}
