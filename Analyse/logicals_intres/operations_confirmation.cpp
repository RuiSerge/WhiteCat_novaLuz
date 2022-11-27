int operations_confirmation()
{
   if(index_do_delete_mem==1)
   {
   int mem_to_delete=0;
   if(numeric_postext>0)
   {
   mem_to_delete=(int)(atof(numeric)*10.0001);
   }
   else if(numeric_postext==0)
   {
   switch(index_blind)
   {
   case 0:
   mem_to_delete=position_onstage;
   break;
   case 1:
   mem_to_delete=position_preset;
   break;
   default: break;
   }
   }
   delete_memory(mem_to_delete);
   }

   else if(index_do_create_mem==1)
   {
   int mem_to_rec=0;
   if(numeric_postext>0)
   {
   mem_to_rec=(int)(atof(numeric)*10.0001);
   }
   else
   {
   for(int l=position_preset/10;l<1000;l++)
   {
   if(MemoiresExistantes[l*10]==0)
   {
    mem_to_rec=l*10;
    break;
   }
   }
   }
   create_memory(mem_to_rec);
   }

   else if(index_do_create_mem_plus_faders==1)
   {
   int mem_to_rec=0;
   if(numeric_postext>0)
   {
   mem_to_rec=(int)(atof(numeric)*10.0001);
   }
   else
   {
   for(int l=position_preset/10;l<1000;l++)
   {
   if(MemoiresExistantes[l*10]==0)
   {
    mem_to_rec=l*10;
    break;
   }
   }
   }
   create_memory_plus_faders(mem_to_rec);
   }

   else if(index_copy_mem_in==1)//CTRL c v avec num de mem
   {
    int mem_to_rec=(int)(atof(numeric)*10.0001);
    if(mem_to_rec>0 && mem_to_rec<9999)
    {
     copy_mem_in(mem_to_rec);
     strcpy(numeric,"");
     numeric_postext=0;
    }
    refresh_mem_onpreset(position_preset);someone_changed_in_sequences=1;//icat
   }


   else if(index_do_overecord_mem_plus_faders==1)//CTRL F3
   {
    int mem_to_overrec=0;
    switch(index_blind)
    {
    case 0:
      mem_to_overrec=position_onstage;
    break;
     case 1:
      mem_to_overrec=position_preset;
     break;
     default: break;
     }
   overrecord_memory_plus_faders(mem_to_overrec);
   }

   else if(index_do_link_memonstage==1)
   {
   Links_Memoires[position_onstage]=toggle(Links_Memoires[position_onstage]);
   someone_changed_in_sequences=1;//icat
   }

   else if(index_do_link_memonpreset==1)
   {
   Links_Memoires[position_preset]=toggle(Links_Memoires[position_preset]);
   someone_changed_in_sequences=1;//icat
   }

    else if(index_do_link_membefore==1)
   {
   Links_Memoires[mem_before_one]=toggle(Links_Memoires[mem_before_one]);
   someone_changed_in_sequences=1;//icat
   }

   else if(index_do_link_memother==1)
   {
   Links_Memoires[other_mem_in_loop]=toggle(Links_Memoires[other_mem_in_loop]);
   if(other_mem_in_loop==mem_after_one)
   {
    someone_changed_in_sequences=1;//icat
   }
   }

   else if(index_do_record_on_faders==1)
   {
   DoDock(fader_selected_for_record,dock_selected_for_record);
   }

   else if(index_do_modify_on_faders==1)
   {
   DoModify(fader_selected_for_record,dock_selected_for_record);
   }

   else if(index_do_report_on_faders==1)
   {
   DoReport(fader_selected_for_record,dock_selected_for_record);
   }

   else if(index_do_affect_color_on_faders==1)
   {
   ClearDock(fader_selected_for_record,dock_selected_for_record);
   affect_color_to_dock(fader_selected_for_record,dock_selected_for_record)  ;
   index_affect_color_to_dock=0;
   }

   else if(index_do_dmx_to_dock==1)
   {
    affect_dmxIN_to_dock(fader_selected_for_record,dock_selected_for_record)  ;
    index_affect_dmxin=0;
   }

   else if(index_do_artnet_to_dock==1)
   {
   affect_network_to_dock(fader_selected_for_record,dock_selected_for_record);
   index_do_affect_net_to_dock=0;
   select_artnet_to_listen=0;
   }

   else if(index_do_video_to_dock==1)
   {
   affect_video_tracking_to_dock(fader_selected_for_record,dock_selected_for_record);
   index_affect_video_tracking_to_dock=0;
   }

   else if(index_do_affect_color_trichro==1)
   {
   affect_color_to(dock_color_selected,couleur_to_affect);
   }

   else if(index_do_affect_roi==1)
   {
   affect_to_tracker(tracking_dock_selected,dock_roi_selected);
   }

   else if(index_do_clear_my_roi==1)
   {
   set_to_default_my_roi(tracking_dock_selected,dock_roi_selected);tracker_clearmode=0;
   }

   else if(index_do_clear_my_video_preset==1)
   {
   set_to_default_this_tracker(tracking_dock_to_clean);
   tracker_clearmode=0;
   }

    else if(index_do_overrecord_mem==1)
   {
   if(index_blind==0)
   {record_memory(position_onstage);}
   else if (index_blind==1)
   {record_memory(position_preset);}
   }

   else if(index_do_clear_dock==1)
   {
   ClearDock(fader_selected_for_record,dock_selected_for_record);
   }

   else if(index_do_clear_on_faders==1)
   {
   ClearFader(fader_selected_for_record);
   }

   else if (index_do_reload_mem==1)
   {
   if(index_blind==0){refresh_mem_onstage(position_onstage); }
   else if(index_blind==1){refresh_mem_onpreset(position_preset);}
   }
   else if (index_do_resurrect_mem==1)
   {
   MemoiresExistantes[mem_to_resurrect]=1;
   detect_mem_before_one();
   detect_mem_preset();
   refresh_mem_onpreset(position_preset);
   }
   else if(index_do_jump_while_cross==1)
   {
   do_load_mem_preset_while_crossfade((int)(atof(numeric)*10.0001));//panic jump preset
   }


 else if( index_do_export==1)
 {
 switch(index_export_choice)
 {
 case 0://ASCII
 if(isASCII==1)
 {

 do_ASCII_export();
 scan_importfolder("ascii");
 strcpy(importfile_name,"");
 strcpy(string_typeexport_view,"");
 index_menu_save=0;
 sprintf(string_Last_Order,">>ASCII export done");
 isASCII=0; isPdf=0;  isSchwz=0;isAlq=0;
 }
  else {sprintf(string_Last_Order,">>This file is not an ASCII type file (.ASC) !");}
 break;

 case 3://PDF
 if(isPdf==1)
 {
 do_pdf_export();
 scan_importfolder("pdf");
 strcpy(importfile_name,"");
 strcpy(string_typeexport_view,"");
 sprintf(string_Last_Order,">>PDF export done");
 index_menu_save=0;
 isASCII=0; isPdf=0;  isSchwz=0;isAlq=0;
 }
 else {sprintf(string_Last_Order,">>This file is not a pdf type file (.PDF) !");}
 break;
 default: break;
 }
 }

 else if( index_do_import==1)
 {
 switch(index_export_choice)
 {
 case 0://ASCII
 if(isASCII==1)
 {
 reset_save_load_report_string();
 reset_show();
 do_ASCII_import();
 sprintf(my_show_is_coming_from,"Loaded from ASCII %s",importfile_name);//pour retracer d ou vient la conduite
 strcpy(importfile_name,"");
 strcpy(string_typeexport_view,"");
 sprintf(string_Last_Order,">>ASCII import done");
 index_menu_save=0;   isASCII=0; isPdf=0;  isSchwz=0;
 isAlq=0;

 index_show_save_load_report=1;there_is_change_on_show_save_state=1;
 }
 else {sprintf(string_Last_Order,">>This file is not an ASCII type file (.ASC) !");}
 break;
 case 1://Schwz
 if(isSchwz==1)
 {
 reset_save_load_report_string();
 reset_show();
 do_Schwartzpeter_import();
 sprintf(my_show_is_coming_from,"Loaded from SCHWZ %s",importfile_name);//pour retracer d ou vient la conduite
 strcpy(importfile_name,"");
 strcpy(string_typeexport_view,"");
 sprintf(string_Last_Order,">>SCHARTZPETER import done");
 index_menu_save=0;   isASCII=0; isPdf=0; isSchwz=0;
 isAlq=0;
 index_show_save_load_report=1;there_is_change_on_show_save_state=1;
 }
 else {sprintf(string_Last_Order,">>This file is not a schwartzpeter FOLDER !");}
 break;
 case 2://Alq
 if(isAlq==1)
 {
 reset_save_load_report_string();
 reset_show();
 do_Alq_import();
 sprintf(my_show_is_coming_from,"Loaded from ASCII ALQ %s",importfile_name);//pour retracer d ou vient la conduite
 strcpy(importfile_name,"");
 strcpy(string_typeexport_view,"");
 sprintf(string_Last_Order,">>Alq import done");
 index_menu_save=0;
 isASCII=0; isPdf=0; isSchwz=0; isAlq=0;
  index_show_save_load_report=1;there_is_change_on_show_save_state=1;
 }
 else {sprintf(string_Last_Order,">>This file is not a Strand ASCII type file (.ALQ) !");}
 break;
 default: break;
 }
}

 else if( index_do_saveshow==1)
 {
 reset_save_load_report_string();
 save_the_show(savefile_name);
 strcpy(savefile_name,"");
 index_type=0; index_menu_save=0;   isASCII=0; isPdf=0; isSchwz=0;isAlq=0;
 substract_a_window(W_SAVE);
 }

 else if( index_do_loadshow==1)
 {
 reset_save_load_report_string();
 load_the_show(savefile_name); index_menu_save=0;   index_type=0;
 isASCII=0; isPdf=0; isSchwz=0;isAlq=0;
 strcpy(string_typeexport_view,"");
 substract_a_window(W_SAVE);
 }

 else if(index_do_resetshow==1)
 {
 GlobInit();
 strcpy(string_typeexport_view,"");
 sprintf(string_Last_Order,">>Reset of show in memory done");

 }


 else if(index_do_freeze==1)
 {
 for (int fz=1;fz<514;fz++)
 {
 if(Selected_Channel[fz]==1)
 {
 if(freeze_array[fz]==0)
 {
     if(bufferSequenciel[fz]>=bufferFaders[fz])
    {
      freeze_state[fz]=bufferSequenciel[fz];
    }
    if(bufferFaders[fz]>bufferSequenciel[fz])
    {
      freeze_state[fz]=bufferFaders[fz];
    }
}
 else {bufferSaisie[fz]=freeze_state[fz];}
 freeze_array[fz]=toggle(freeze_array[fz]);
 }

 }
 }



 else if( index_do_clear_patch==1)
 {
 patch_clear_selected();
 patch_unselect_all_dimmers();
 generate_channel_view_list_from_patched_circuits();
 }
 else if( index_do_default_patch==1)
 {
 patch_to_default_selected();
 patch_unselect_all_dimmers();
 generate_channel_view_list_from_patched_circuits();
 }
 else if( index_do_quit_with_save==1)
 {
 index_quit=1;
 }
 else if(index_do_quit_without_save==1)
 {
 set_all_saves_indexes_at(0);
 reset_save_load_report_string();
 index_please_do_not_save=1;
 index_quit=1;
 }

else if( index_do_ask_call_audio_folder==1)
{
sprintf(audio_folder,"                        ");
for(int p=0;p<24;p++)
{
        if(numeric[p]==' '){audio_folder[p]='\0';break;}
        else {audio_folder[p]=numeric[p];}
}

reset_numeric_entry();
index_type=0;
sprintf(rep,"%s\\",mondirectory);
chdir (rep);
scan_audiofolder();
}

else if(index_do_audio_to_dock==1)
{
affect_audio_control_to_dock(fader_selected_for_record,dock_selected_for_record);
}



else if(index_do_clear_lock_preset==1)
{
for(int f=0;f<48;f++)
 {
 FaderLocked_Preset[lock_preset_selected_for_record][f]=0;
 StateOfFaderBeforeLock_Preset[lock_preset_selected_for_record][f]=0;
 LockFader_is_FullLevel_Preset[lock_preset_selected_for_record][f]=0;
 }
 master_lock_preset[lock_preset_selected_for_record]=0;
 index_main_clear=0;
}


else if( index_do_banger_memonstage==1)
{
Banger_Memoire[position_onstage]=affect_banger_number;
reset_numeric_entry();
sprintf(string_Last_Order,">> Attributed banger %d to memory %d.%d", affect_banger_number, position_onstage/10,position_onstage%10 );
}
else if( index_do_banger_memonpreset==1)
{
Banger_Memoire[position_preset]=affect_banger_number;
reset_numeric_entry();
sprintf(string_Last_Order,">> Attributed banger %d to memory %d.%d", affect_banger_number, position_preset/10,position_preset%10 );
}
else if( index_do_banger_membeforeone==1)
{
Banger_Memoire[mem_before_one]=affect_banger_number;
reset_numeric_entry();
sprintf(string_Last_Order,">> Attributed banger %d to memory %d.%d", affect_banger_number, mem_before_one/10,mem_before_one%10 );
}
else if(index_do_banger_memother==1)
{
Banger_Memoire[other_mem_in_loop]=affect_banger_number;
reset_numeric_entry();
sprintf(string_Last_Order,">> Attributed banger %d to memory %d.%d", affect_banger_number, other_mem_in_loop/10,other_mem_in_loop%10 );

}

else if(index_do_wizard_ch==1)
{
do_wizard_ch();
sprintf(string_Last_Order,">> Wizard CH done");
}

else if(index_do_wizard_mem==1)
{
do_wizard_mem();
sprintf(string_Last_Order,">> Wizard MEM done");
}

else if(index_wizard_do_reload_from_disk==1)
{
do_wizard_reload_from_disk();
sprintf(string_Last_Order,">> Show reloaded from disk");
}




else if(index_do_record_direct_ch==1)
{
do_direct_channel(fader_selected_for_record,dock_selected_for_record);
}


else if(index_ask_curv_to_fader==1)
{
FaderCurves[fader_selected_for_record]=curve_asked_for_fader-1;
sprintf(string_Last_Order,">> Affected curve %d to Fader %d",curve_asked_for_fader, fader_selected_for_record+1);
}


else if(index_re_init_client_artnet==1)
{
fermeture_client_artnet();
initialisation_client_artnet();
}

else if (index_re_init_serveur_artnet==1)
{
fermeture_serveur_artnet();
initialisation_serveur_artnet();
}


else if(index_do_affect_fx==1)
{
affect_chaser_to_dock(chaser_selected,   fader_selected_for_record, dock_selected_for_record  );
}


else if( index_do_dock_track==1)
{
DoDockChaserTrack(chaser_selected_for_record,track_selected_for_record);
}
else if( index_do_report_track==1)
{
DoReportChaserTrack(chaser_selected_for_record,track_selected_for_record);
}

else if( index_do_modify_track==1)
{
DoModifyChaserTrack(chaser_selected_for_record,track_selected_for_record);
}

else if( index_do_clear_track==1)
{
DoClearChaserTrack(chaser_selected_for_record,track_selected_for_record);
}
else if( index_do_clear_chaser==1)
{
DoClearAChaser(chaser_selected_for_record);
}

else if(index_do_store_chaser_preset==1)
{
chaser_store_in_preset(chaser_selected_for_record ,chaser_preset_selected_for_record);
}

else if(index_do_clear_chaser_preset==1)
{
chaser_clear_preset(chaser_selected_for_record ,chaser_preset_selected_for_record);
}

else if(index_record_minifader_preset==1)
{
minifader_selection_record(minifader_preset_is);
}

else if(index_clear_minifader_preset==1)
{
minifader_selection_clear(minifader_preset_is);
}


else if(index_record_minifader_lockpreset==1)
{
minifader_lockselection_record(minifader_lockpreset_is);
}

else if(index_ask_clear_iCatpage==1)
{
clear_iCat_page(iCatPageis);
}

else if(index_ask_icat_copyPage==1)
{
copy_iCatPage(iCatPageis,iCatPageToCopyIn);
}

else if(index_ask_clear_img_icat==1)
{
reset_and_recall_iCat_images();
}

else if(index_ask_iCat_selectiv_clear==1)
{
switch (editing_GUI_type_iCat)
{
case 1:
clear_iCat_sliders(iCatPageis);
break;
case 2:
clear_iCat_buttons(iCatPageis);
break;
case 3:
clear_iCat_strings(iCatPageis);
break;
default:
break;
}
}//fin selectiv clean

else if(index_clear_a_grid_step==1)
{
clear_a_grid_step(grid_to_clear,step_grid_to_clear);
}

else if(index_clear_a_grid==1)
{
clear_a_grid(grid_to_clear);
}

else if(index_clear_a_grid_serie_step==1)
{
clear_part_of_a_grid(grid_to_clear,step_grid_to_clear , index_for_grid_stepto);
}

else if(index_for_copy_grid==1)
{
switch(index_grid_tostep_or_not)
{
case 0:
copy_step_to_step(grid_to_clear,step_grid_to_clear,destination_grid_for_copy,destination_step_for_copy);
break;
case 1:
copy_grid_partially(grid_to_clear,step_grid_to_clear,from_gridstep_to,destination_grid_for_copy,destination_step_for_copy);
break;
default: break;
}
}

else if(index_for_insert_grid==1)
{
insert_steps(grid_to_clear,step_grid_to_clear,destination_step_for_copy);
}

else if(index_do_affect_grid_to_fader==1)
{
DockTypeIs[fader_selected_for_record][dock_selected_for_record]=12;
faders_dock_grid_affectation[fader_selected_for_record][dock_selected_for_record]=gridplayer_to_affect_is;
}


else if(index_do_affect_step_gridplayer_to_mem==1)
{
set_from_seq_gridplayer1_next_step[index_mem_to_be_affected_by_gpl]= gpl1_affect_step_to_mem-1;
gpl1_affect_step_to_mem=0;
}




else if(index_do_exclude==1)
{
exclude_reinclude_channels_from_grand_master_action();
}

else if( index_do_affect_fgroup==1)
{
affect_selected_faders_to_fgroup(fader_selected_for_record,dock_selected_for_record);
}


else if( index_do_affect_mover==1)
{
affect_mover_to_fader(fader_selected_for_record,dock_selected_for_record);
index_affect_to_dock_mover=0;
index_do_affect_mover=0;
}

else if (  index_ask_delete_symbols_on_calc==1)
{
clear_calc(plot_layer_selected);
plot_layer_selected=0;
index_main_clear=0;
}

else if(index_ask_general_clear_on_plot==1)//clear general
{

switch (index_menus_lighting_plot)
{
case 0://bkgd
set_plot_background_to_default();
break;
case 1://shapes
for(int i=0;i<nbre_symbol_per_layer;i++)
{
clear_shape_slot(i);
}
nbre_shapes_on_plot=0;
number_of_shapes_groups=0;
break;
case 2://symbol
for(int i=0;i<3;i++)
{
clear_calc(i);
}
break;
case 3://legend
break;
default:
break;
}

}

else if(index_do_clear_all_the_patch==1)
{
 clear_completely_the_patch();
 generate_channel_view_list_from_patched_circuits();
}

else if(index_ask_clear_preset_relativ==1)
{
 clear_xyrelativ_preset(xyrelativ_preset)  ;
}

else if(index_ask_record_selection_of_view==1)
{
record_selection_in(channel_view_is);
Channel_View_MODE[channel_view_is]=1;
index_ask_record_selection_of_view=0;
}


else if(index_ask_modify_selection_of_view==1)
{
modify_selection_in(channel_view_is);
Channel_View_MODE[channel_view_is]=1;
index_ask_modify_selection_of_view=0;
}

else if(index_ask_report_selection_of_view==1)
{
report_selection_in(channel_view_is);
index_ask_report_selection_of_view=0;
}

else if(index_ask_clear_selection_of_view==1)
{
clear_selection_in(channel_view_is);
Channel_View_MODE[channel_view_is]=0;
index_ask_clear_selection_of_view=0;
}


else if(index_ask_build_view==1)
{

int nummem=(int)(atof(numeric)*10);

switch(channel_view_mode_builder[channel_view_is])//all ou solo
{
case 0:
      // 1 mem // 2 fader
     if(channel_view_type_of_behaviour[channel_view_is]==1)//mem
     {
     build_preset_view_from_mem(nummem,channel_view_is);
     }
     else if(channel_view_type_of_behaviour[channel_view_is]==2)//fader
     {
     fader_selected_for_record=nummem/10;
     if(fader_selected_for_record>0 && fader_selected_for_record<49)
     {
     build_preset_view_from_fader(fader_selected_for_record,channel_view_is);
     }
     }
break;
case 1:
      if(channel_view_type_of_behaviour[channel_view_is]==0)//mem + faders
      {
      build_preset_view_from_all_existing_mems_and_faders(channel_view_is);
      }
      else if(channel_view_type_of_behaviour[channel_view_is]==1)//mem
     {
      build_preset_view_from_all_existing_mems(channel_view_is);
      }
     else if(channel_view_type_of_behaviour[channel_view_is]==2)//fader
     {
     build_preset_view_from_all_faders(channel_view_is);
     }
break;
default: break;
}
channel_view_type_of_behaviour[channel_view_is]=0;
channel_view_mode_builder[channel_view_is]=0;
}


else if(index_ask_clear_a_move==1)
{
    Clear_the_Move(move_to_clear);
}

else if(index_ask_reinit_FS_client==1)
{
   index_re_init_clientserveur_icat=1;
}


else if (ask_clear_draw_preset==1)
{
  clear_draw_preset(draw_prst_to_clear);
}


else  if( index_do_draw_affect_to_dock==1)
{
  affect_draw_preset_to_dock(draw_preset_selected_for_order,fader_selected_for_record, dock_selected_for_record);
}



else  if( index_ask_clear_echo_preset==1)
{
   clear_echo_preset(index_selected_echo_for_manipulation);
}


else  if(index_do_affect_echo_to_dock==1)
{
   affect_echo_to_dock(echo_selected,fader_selected_for_record, dock_selected_for_record);
}

else  if( index_ask_copy_banger==1)
{
    copy_banger(index_banger_selected,index_banger_to_copy_in);
}


else if(index_ask_clear_banger==1)
{
     clear_banger(index_banger_to_copy_in);
     sprintf(string_Last_Order,"Cleared Banger %d", index_banger_to_copy_in+1);
}

else if(index_affect_wave_to_dock==1)
{
    affect_wave_to_dock(fader_selected_for_record, dock_selected_for_record);
    sprintf(string_Last_Order,"Affected WAVE buffer to F % Dock %d", fader_selected_for_record, dock_selected_for_record);
}

   reset_indexs_confirmation();
   reset_numeric_entry();


 return(0);
}
