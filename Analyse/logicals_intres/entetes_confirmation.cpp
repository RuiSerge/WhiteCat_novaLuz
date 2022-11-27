int entetes_confirmation()
{
  //logicals strings
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
     sprintf(string_confirmation,"Delete Mem %d.%d?", mem_to_delete/10,mem_to_delete%10);
 }

 else if(index_do_create_mem==1)
 {
 int mem_to_create=0;
 if(numeric_postext>0)
   {
   mem_to_create=(int)(atof(numeric)*10.0001);
   }
 else
 {
   for(int l=position_preset/10;l<1000;l++)
   {
   if(MemoiresExistantes[l*10]==0)
   {
    mem_to_create=l*10;
    break;
   }
   }
 }


 if(MemoiresExistantes[mem_to_create]==0)
 {
 if(numeric_postext>0)
   {
 sprintf(string_confirmation,"Create Mem %d.%d ?", mem_to_create/10,mem_to_create%10);
   }
 else  {
 sprintf(string_confirmation,"Add a Memory to CueList  ?");
   }
 }
 else if(MemoiresExistantes[mem_to_create]==1)
{
 sprintf(string_confirmation,"Sure to Over-Record Mem %d.%d ?", mem_to_create/10,mem_to_create%10);
 }
 }

 else if(index_do_create_mem_plus_faders==1)
 {
         int mem_to_create=0;
         if(numeric_postext>0)
           {
           mem_to_create=(int)(atof(numeric)*10.0001);
           }
         else
         {
           for(int l=position_preset/10;l<1000;l++)
           {
           if(MemoiresExistantes[l*10]==0)
           {
            mem_to_create=l*10;
            break;
           }
           }
         }
         if(MemoiresExistantes[mem_to_create]==0)
         {
          if(numeric_postext>0)
           {
         sprintf(string_confirmation,"Create Mem %d.%d ?", mem_to_create/10,mem_to_create%10);
            }
         else  {
         sprintf(string_confirmation,"Add a Memory to CueList  ?");
           }
         }
         else if(MemoiresExistantes[mem_to_create]==1)
         {
         sprintf(string_confirmation,"Sure to Over-Record Mem %d.%d ?", mem_to_create/10,mem_to_create%10);
         }
 }

  else if(index_do_overecord_mem_plus_faders==1)//CTRL F3
 {
     int mem_to_create=0;



     switch(index_blind)
     {
     case 0:
          mem_to_create=position_onstage;
     break;
     case 1:
          mem_to_create=position_preset;
     break;
     default: break;
     }
     sprintf(string_confirmation,"OverRecord Mem %d.%d plus faders ?", mem_to_create/10,mem_to_create%10);
 }

else if(index_copy_mem_in==1)//CTRL c v avec num de mem
   {
        int mem_to_rec=(int)(atof(numeric)*10.0001);
        if(MemoiresExistantes[mem_to_rec]==0)
        {
         sprintf(string_confirmation,"Create Mem %d.%d from Mem %d.%d ?", mem_to_rec/10,mem_to_rec%10,CTRLC_mem_to_copy/10,CTRLC_mem_to_copy%10);
        }
        else
        {
          sprintf(string_confirmation,"! Replace Mem %d.%d by Mem %d.%d ?", mem_to_rec/10,mem_to_rec%10,CTRLC_mem_to_copy/10,CTRLC_mem_to_copy%10);
        }
   }

 else if(index_do_link_membefore==1)
 {
     if(Links_Memoires[mem_before_one]==0)
     {
     sprintf(string_confirmation,"Link Mem %d.%d ?", mem_before_one/10,mem_before_one%10);
     }
     else {sprintf(string_confirmation,"Unlink Mem %d.%d ?", mem_before_one/10,mem_before_one%10);     }
 }

 else if(index_do_link_memonstage==1)
 {
     if(Links_Memoires[position_onstage]==0)
     {
     sprintf(string_confirmation,"Link Mem %d.%d ?", position_onstage/10,position_onstage%10);
     }
     else {sprintf(string_confirmation,"Unlink Mem %d.%d ?", position_onstage/10,position_onstage%10);     }
 }
 else if(index_do_link_memonpreset==1)
 {
     if(Links_Memoires[position_preset]==0)
     {
     sprintf(string_confirmation,"Link Mem %d.%d ?", position_preset/10,position_preset%10);
     }
     else {sprintf(string_confirmation,"Unlink Mem %d.%d ?", position_preset/10,position_preset%10);     }
 }
 else if(index_do_link_memother==1)
 {
     if(Links_Memoires[other_mem_in_loop]==0)
     {
     sprintf(string_confirmation,"Link Mem %d.%d ?", other_mem_in_loop/10,other_mem_in_loop%10);
     }
     else {sprintf(string_confirmation,"Unlink Mem %d.%d ?", other_mem_in_loop/10,other_mem_in_loop%10);     }
 }
 else if(index_do_record_on_faders==1)
 {
     if (numeric_postext==0)
     {
     sprintf(string_confirmation,"Record in Fader %d Dock %d ?", (fader_selected_for_record+1),(dock_selected_for_record+1) );
     }
     else if(numeric_postext>0 )
     {
      int mem_to_load= (int)(atof(numeric)*10.0001);
      sprintf(string_confirmation,"Store in Fader %d Dock %d Mem %d.%d ?", (fader_selected_for_record+1),(dock_selected_for_record+1),mem_to_load/10,mem_to_load%10 );
     }
 }
 else if(index_do_modify_on_faders==1)
 {
 sprintf(string_confirmation,"Modify in Fader %d Dock %d  ?", (fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_report_on_faders==1)
 {
 sprintf(string_confirmation,"Report all in Fader %d Dock %d  ?",(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
  else if(index_do_affect_color_on_faders==1)
 {
 sprintf(string_confirmation,"Affect Color Wheel %d in Fader %d Dock %d  ?",(dock_color_selected+1),(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_dmx_to_dock==1)
 {
 sprintf(string_confirmation,"Affect Dmx In in Fader %d Dock %d  ?",(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_artnet_to_dock==1)
 {
 sprintf(string_confirmation,"Affect Art-Net %d in Fader %d Dock %d  ?",select_artnet_to_listen,(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_video_to_dock==1)
 {
 sprintf(string_confirmation,"Affect Video Tracking in Fader %d Dock %d  ?",(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_affect_color_trichro==1)
 {
   if (couleur_to_affect==0){ sprintf(string_confirmation,"Affect As RED for Color Preset %d  ?",dock_color_selected+1); }
   else if (couleur_to_affect==1){ sprintf(string_confirmation,"Affect As GREEN for Color Preset %d  ?",dock_color_selected+1); }
   else if (couleur_to_affect==2){ sprintf(string_confirmation,"Affect As BLUE for Color Preset %d  ?",dock_color_selected+1); }
   else if (couleur_to_affect==3){ sprintf(string_confirmation,"Affect As YELLOW for Color Preset %d  ?",dock_color_selected+1); }
 }
 else if(index_do_affect_roi==1)
 {
  sprintf(string_confirmation,"Affect To ROI   %d  in %d ?",dock_roi_selected+1,tracking_dock_selected+1);
 }
  else if(index_do_clear_my_roi==1)
 {
  sprintf(string_confirmation,"Clear ROI   %d  in %d?",dock_roi_selected+1,tracking_dock_selected+1);
 }
  else if(index_do_clear_my_video_preset==1)
 {
  sprintf(string_confirmation,"Clear All ROI in Video Preset %d  ?",tracking_dock_to_clean+1);
 }
 else if(index_do_overrecord_mem==1)
 {
  if(index_blind==0)
  {
  sprintf(string_confirmation,"Over Record %d.%d ?",position_onstage/10,position_onstage%10);
  }
  else if(index_blind==1)
  {
  sprintf(string_confirmation,"Over Record %d.%d (Blind) ?",position_preset/10,position_preset%10);
  }
 }
 else if(index_do_clear_dock==1)
 {
   sprintf(string_confirmation,"Clear in Fader %d Dock %d  ?",(fader_selected_for_record+1),(dock_selected_for_record+1));
 }
 else if(index_do_reload_mem==1)
 {
 if(index_blind==0)
 {
  sprintf(string_confirmation,"Reload Mem %d.%d ?",position_onstage/10,position_onstage%10);
 }
 else
 {
  sprintf(string_confirmation,"Reload Mem %d.%d (Blind) ?",position_preset/10,position_preset%10);
 }
 }
 else if(index_do_resurrect_mem==1)
 {
 sprintf(string_confirmation,"Resurect Mem %d.%d ?",mem_to_resurrect/10,mem_to_resurrect%10);
 }
 else if(index_do_clear_on_faders==1)
 {
    sprintf(string_confirmation,"Clear completely content of Fader %d ?",(fader_selected_for_record+1));
 }
 else if(index_do_jump_while_cross==1)
 {
  //christoph 19/12/14
  int tmpmp=(atof(numeric)*10.0001)/10;
  int tmpmp2=(int)(atof(numeric)*10.0001)%10;
  //sprintf(string_confirmation,"Panic Jump to mem %d.%d ?",(int)(atof(numeric)*10.0001)/10,(int)(atof(numeric)*10.0001)%10);
  sprintf(string_confirmation,"Panic Jump to mem %d.%d ?",tmpmp,tmpmp2);
 }

 else if( index_do_export==1)
 {
 switch(index_export_choice)
 {
 case 0:
  sprintf(string_confirmation,"Export ASCII as %s ?", importfile_name);
 break;
 case 3:
  sprintf(string_confirmation,"Export pdf as %s ?", importfile_name);
 break;
 default: break;
 }
 }
 else if( index_do_import==1)
 {
 switch(index_export_choice)
 {
 case 0:
 sprintf(string_confirmation,"Import %s as ASCII ?", importfile_name);
 break;
 case 1:
   sprintf(string_confirmation,"Import %s (schwartzpeter folder)?", importfile_name);
 break;
 case 2:
   sprintf(string_confirmation,"Import %s  as ALQ ?", importfile_name);
 break;
 default: break;
 }
 }

 else if( index_do_saveshow==1)
 {
 sprintf(string_confirmation,"Save Show as %s ?", savefile_name);
 }

 else if( index_do_loadshow==1)
 {
 sprintf(string_confirmation,"Load Show as %s ?", savefile_name);
 }
  else if(index_do_resetshow==1)
 {
 sprintf(string_confirmation,"Reset the actual show in memory ?");
 }
  else if( index_do_freeze==1)
 {
 sprintf(string_confirmation,"Freeze / Unfreeze selected channels ?");
 }

 else if( index_do_clear_patch==1)
 {
 sprintf(string_confirmation,"Clear selected dimmers ?");
 }
 else if( index_do_default_patch==1)
 {
 sprintf(string_confirmation,"Set to default selected dimmers ?");
 }
 else if( index_do_quit_with_save==1)
 {
 sprintf(string_confirmation,"Quit WhiteCat and save ?");
 }
 else if( index_do_quit_without_save==1)
 {
 sprintf(string_confirmation,"Quit WhiteCat without save ?");
 }

 else if(index_do_ask_call_audio_folder==1)
 {
 sprintf(string_confirmation,"Use in /audio, folder %s ?", numeric);
 }

 else if(index_do_audio_to_dock==1)
 {
 switch(audio_type_for_dock_affectation_is)
 {
 case 0:
 sprintf(string_confirmation,"Affect PlayerVolume %d to Fader %d Dock%d  ?",(player_to_affect_to_dock+1),(fader_selected_for_record+1),(dock_selected_for_record+1));
 break;
 case 1:
 sprintf(string_confirmation,"Affect PlayerPan %d to Fader %d Dock%d  ?",(player_to_affect_to_dock+1),(fader_selected_for_record+1),(dock_selected_for_record+1));
 break;
 case 2:
 sprintf(string_confirmation,"Affect PlayerPitch %d to Fader %d Dock%d  ?",(player_to_affect_to_dock+1),(fader_selected_for_record+1),(dock_selected_for_record+1));
 break;
 default: break;
 }
 }

 else if( index_do_clear_lock_preset==1)
 {
   sprintf(string_confirmation,"Clear Lock Preset %d  ?",(lock_preset_selected_for_record+1));

 }

 else if( index_do_banger_memonstage==1)
 {
     sprintf(string_confirmation,"Affect banger %d to memory %d.%d ?", affect_banger_number, position_onstage/10,position_onstage%10 );
 }

 else if( index_do_banger_memonpreset==1)
 {
     sprintf(string_confirmation,"Affect banger %d to memory %d.%d ?", affect_banger_number, position_preset/10,position_preset%10 );
 }

else if( index_do_banger_membeforeone==1)
 {
     sprintf(string_confirmation,"Affect banger %d to memory %d.%d ?", affect_banger_number, mem_before_one/10,mem_before_one%10 );
 }

 else if (index_do_banger_memother==1)
 {
 sprintf(string_confirmation,"Affect banger %d to memory %d.%d ?", affect_banger_number , other_mem_in_loop/10,other_mem_in_loop%10 );
 }


  else if(index_do_wizard_ch==1)
 {
 switch(wizard_amplitude_is_global)
 {
 case 0:
 sprintf(string_confirmation,"Do Wizard CH from Mem %d.%d to Mem %d.%d ?",wizard_from_mem/10,wizard_from_mem%10,wizard_to_mem/10,wizard_to_mem%10);
 break;
 case 1:
 sprintf(string_confirmation,"Do Wizard CH Action on ALL memories ?");
 break;
 default: break;
 }
 }

else if(index_do_wizard_mem==1)
{
 switch(wizard_amplitude_is_global)
 {
 case 0:
 sprintf(string_confirmation,"Do Wizard MEM from Mem %d.%d to Mem %d.%d ?",wizard_from_mem/10,wizard_from_mem%10,wizard_to_mem/10,wizard_to_mem%10);
 break;
 case 1:
 sprintf(string_confirmation,"Do Wizard MEM Action on ALL memories ?");
 break;
 default: break;
 }
}
else if(index_wizard_do_reload_from_disk==1)
{
sprintf(string_confirmation,"Reload from disk ALL memories ?");
}

else if(index_do_record_direct_ch==1)//direct channel
{
switch( multiple_direct_chan)
{
case 0:
 sprintf(string_confirmation,"Affect as Direct Channel to Fader %d dock %d ?",fader_selected_for_record+1,dock_selected_for_record+1);
break;
case 1:
 sprintf(string_confirmation,"Affect x12 Direct Channel to Fader %d dock %d ?",fader_selected_for_record+1,dock_selected_for_record+1);
break;
default:
break;
}
}

else if(index_ask_curv_to_fader==1)//attribution de courbe à un fader
{
 sprintf(string_confirmation,"Affect to Fader %d Curve %d ?",fader_selected_for_record+1,curve_asked_for_fader);

}

else if ( index_re_init_client_artnet==1)
{
 sprintf(string_confirmation,"Re-Init Art-Net Client ?");
}
else if (index_re_init_serveur_artnet==1)
{
 sprintf(string_confirmation,"Re-Init Art-Net Server ?");
}

else if(index_do_affect_fx==1)
{
 sprintf(string_confirmation,"Store Chaser %d in Fader %d Dock %d ?",(chaser_selected+1), (fader_selected_for_record+1),(dock_selected_for_record+1) );
}

else if(index_do_dock_track==1)
{
sprintf(string_confirmation,"Record  Track %d Chaser %d ?",track_selected_for_record+1,chaser_selected_for_record+1 );
}
else if(index_do_report_track==1)
{
sprintf(string_confirmation,"Report in Track %d Chaser %d ?",track_selected_for_record+1,chaser_selected_for_record+1 );
}
else if(index_do_modify_track==1)
{
sprintf(string_confirmation,"Modify Track %d Chaser %d ?",track_selected_for_record+1,chaser_selected_for_record+1 );
}
else if(index_do_clear_track==1)
{
sprintf(string_confirmation,"Clear Track %d Chaser %d ?",track_selected_for_record+1,chaser_selected_for_record+1 );
}
else if(index_do_clear_chaser==1)
{
 sprintf(string_confirmation,"Clear completely Chaser %d ?",chaser_selected_for_record+1 );
}


else if(index_do_store_chaser_preset==1)
{
sprintf(string_confirmation,"Store ON Preset %d in Chaser %d ?",chaser_preset_selected_for_record+1,chaser_selected_for_record+1 );
}

else if(index_do_clear_chaser_preset==1)
{
sprintf(string_confirmation,"Clear ON Preset %d in Chaser %d ?",chaser_preset_selected_for_record+1,chaser_selected_for_record+1 );
}

else if(index_record_minifader_preset==1)
{
sprintf(string_confirmation,"Record Selection in MiniFaders Preset %d ?",minifader_preset_is+1 );
}


else if(index_clear_minifader_preset==1)
{
sprintf(string_confirmation,"Clear MiniFaders Preset %d ?",minifader_preset_is+1 );
}

else if(index_record_minifader_lockpreset==1)
{
sprintf(string_confirmation,"Record in MiniFaders LockPreset %d ?",minifader_lockpreset_is+1 );
}

else if(index_ask_clear_iCatpage==1)
{
sprintf(string_confirmation,"Clear completely iCat Page %d ?",iCatPageis+1 );
}

else if(index_ask_icat_copyPage==1)
{
sprintf(string_confirmation,"Copy iCatPage %d in Page %d?",iCatPageis+1,iCatPageToCopyIn+1 );

}

else if( index_ask_clear_img_icat==1)
{
sprintf(string_confirmation,"Reset iCat images ? You need access to internet !" );
}

else if (index_ask_iCat_selectiv_clear==1)
{
switch(editing_GUI_type_iCat)
{
case 0:
sprintf(string_confirmation,"Clear selectively: FAMILY NO EDITABLE !!!" );
break;
case 1://sliders
sprintf(string_confirmation,"Clear selectively Sliders in iCatPage %d?",iCatPageis+1 );
break;
case 2://buttons
sprintf(string_confirmation,"Clear selectively Buttons in iCatPage %d?",iCatPageis+1 );
break;
case 3://strings
sprintf(string_confirmation,"Clear selectively Strings in iCatPage %d?",iCatPageis+1 );
break;
default:
sprintf(string_confirmation,"Wrong case");
break;
}
}//fin icat selectiv

else if(index_clear_a_grid_step==1)
{
	//sab 02/03/2014 impact ajout %d
sprintf(string_confirmation,"Clear Step %d in Grid %d?",step_grid_to_clear+1, grid_to_clear+1 );
}

else if(index_clear_a_grid==1)
{
sprintf(string_confirmation,"Clear completely Grid %d?",grid_to_clear+1);
}

else if(index_clear_a_grid_serie_step==1)
{
sprintf(string_confirmation,"Clear in Grid %d Steps %d to %d?",grid_to_clear+1,step_grid_to_clear+1 , index_for_grid_stepto+1);
}

else if(index_for_copy_grid==1)
{
switch(index_grid_tostep_or_not)//mode un pas ou mode serie de pas
{
case 0:
sprintf(string_confirmation,"Copy Grid %d Step %d in Grid %d Step %d?",grid_to_clear+1,step_grid_to_clear+1 , destination_grid_for_copy+1,destination_step_for_copy+1);
break;
case 1:
sprintf(string_confirmation,"Copy Grid %d from Step %d to %d in Grid %d Step %d?",grid_to_clear+1,step_grid_to_clear+1 ,from_gridstep_to+1 , destination_grid_for_copy+1,destination_step_for_copy+1);
break;
default: break;
}
}

else if (index_for_insert_grid==1)
{
sprintf(string_confirmation,"Insert in Grid %d Step %d: %d Steps ?",grid_to_clear+1,step_grid_to_clear+1 , destination_step_for_copy+1);

}

else if(index_do_affect_grid_to_fader==1)
{
sprintf(string_confirmation,"Affect to Fader %d Dock %d GridPlayer %d?",fader_selected_for_record+1,dock_selected_for_record+1,gridplayer_to_affect_is+1);
}

else if(index_do_affect_step_gridplayer_to_mem==1)
{
sprintf(string_confirmation,"Affect to Mem %d.%d Step %d in GridPl.1?",index_mem_to_be_affected_by_gpl/10, index_mem_to_be_affected_by_gpl%10,gpl1_affect_step_to_mem);
}

else if(index_do_exclude==1)
{
sprintf(string_confirmation,"Exclude/Re-include channels from GM action?");
}

else if( index_do_affect_fgroup==1)
{
sprintf(string_confirmation,"Affect to Fader %d Dock %d selected faders?",fader_selected_for_record+1,dock_selected_for_record+1);
}

else if( index_do_affect_mover==1)
{
sprintf(string_confirmation,"Affect Mover Output to Fader %d Dock %d ?",fader_selected_for_record+1,dock_selected_for_record+1);
}

else if(  index_ask_delete_symbols_on_calc==1)
{
sprintf(string_confirmation,"Clear Plot layer %d? ",plot_layer_selected+1);
}


else if(index_ask_general_clear_on_plot==1)//clear general
{
switch (index_menus_lighting_plot)
{
case 0://bkgd
sprintf(string_confirmation,"Clear Plot BACKGROUND ? ");
break;
case 1://shapes
sprintf(string_confirmation,"Clear Plot SHAPES ? ");
break;
case 2://symbol
sprintf(string_confirmation,"Clear Plot SYMBOLS? ");
break;
case 3://legend
sprintf(string_confirmation,"Clear Plot LEGEND? ");
break;
default:
break;
}
}

else if(index_do_clear_all_the_patch==1)
{
sprintf(string_confirmation,"CLEAR completly the Patch? ");
}

else if(index_ask_clear_preset_relativ==1)
{
sprintf(string_confirmation,"CLEAR this relativ XY preset ? ");
}


else if(index_ask_record_preset_relativ==1)
{
sprintf(string_confirmation,"RECORD this relativ XY preset ? ");
}


else if(index_ask_modify_preset_relativ==1)
{
sprintf(string_confirmation,"MODIFY this relativ XY preset ? ");
}


else if(index_ask_record_selection_of_view==1)
{
sprintf(string_confirmation,"RECORD Channel View %d ? ",channel_view_is+1);
}


else if(index_ask_modify_selection_of_view==1)
{
sprintf(string_confirmation,"MODIFY Channel View %d ? ",channel_view_is+1);
}


else if(index_ask_clear_selection_of_view==1)
{
sprintf(string_confirmation,"CLEAR Channel View %d ? ",channel_view_is+1);
}

else if(index_ask_report_selection_of_view==1)
{
sprintf(string_confirmation,"REPORT Selected CH to Channel View %d ? ",channel_view_is+1);
}
else if(index_ask_build_view==1)
{

int nummem=(int)(atof(numeric)*10);

switch(channel_view_mode_builder[channel_view_is])//solo ou all
{
case 0:
      // 1 mem // 2 fader
     if(channel_view_type_of_behaviour[channel_view_is]==1)//mem
     {

      if(MemoiresExistantes[nummem]==1)
       {
      sprintf(string_confirmation,"Build Channel View %d from Mem %d.%d ? ",channel_view_is+1, nummem/10,nummem%10);
       }
       else {sprintf(string_confirmation,"Mem %d.%d doesn't exist ! ",nummem/10,nummem%10);}
      }
     else if(channel_view_type_of_behaviour[channel_view_is]==2)//fader
     {
     fader_selected_for_record=nummem/10;
     if(fader_selected_for_record>0 && fader_selected_for_record<49)
     {
     sprintf(string_confirmation,"Build Channel View %d from Fader %d ? ",channel_view_is+1,fader_selected_for_record );
     }
     else {   sprintf(string_confirmation,"Fader number must be between 1 and 48 ! "); }
     }
break;
case 1:
       if(channel_view_type_of_behaviour[channel_view_is]==0)//mem + faders
     {
     	//sab 02/03/2014 impact ajout %d
      sprintf(string_confirmation,"Build Channel View %d from ALL mems and faders? ",channel_view_is+1);
      }
      else if(channel_view_type_of_behaviour[channel_view_is]==1)//mem
     {
     	//sab 02/03/2014 impact ajout %d
      sprintf(string_confirmation,"Build Channel View %d from ALL mems ? ",channel_view_is+1);
      }
     else if(channel_view_type_of_behaviour[channel_view_is]==2)//fader
     {
     sprintf(string_confirmation,"Build Channel View %d from ALL Faders ? ",channel_view_is+1 );
     }
break;
default: break;
}
}

else if(index_ask_clear_a_move==1)
{
    sprintf(string_confirmation,"Clear Move %d? ",move_to_clear );
}

else if(index_ask_reinit_FS_client==1)
{
     sprintf(string_confirmation,"Re-init FS-iCat connexion ? " );
}

else if (ask_clear_draw_preset==1)
{
        sprintf(string_confirmation,"Clear Draw Preset %d? ",draw_prst_to_clear+1 );
}

else  if( index_do_draw_affect_to_dock==1)
{
    sprintf(string_confirmation,"Affect Draw Preset %d to Fader %d Dock %d ? ",draw_preset_selected_for_order+1,fader_selected_for_record+1, dock_selected_for_record+1 );
}


else  if( index_ask_clear_echo_preset==1)
{
    sprintf(string_confirmation,"Clear Echo Preset %d ? ",index_selected_echo_for_manipulation+1 );
}


else  if( index_do_affect_echo_to_dock==1)
{
    sprintf(string_confirmation,"Affect Echo Preset %d to Fader %d Dock %d ? ",echo_selected+1,fader_selected_for_record+1, dock_selected_for_record+1 );
}


else  if( index_ask_copy_banger==1)
{
    sprintf(string_confirmation,"Copy Banger %d to Banger %d ? ",index_banger_selected+1,index_banger_to_copy_in+1 );
}

else if(index_ask_clear_banger==1)
{
    sprintf(string_confirmation,"Clear Banger %d ?" ,index_banger_to_copy_in+1);
}


else  if( index_affect_wave_to_dock==1)
{
    sprintf(string_confirmation,"Affect WAVE Buffer to Fader %d Dock %d ? ",fader_selected_for_record+1, dock_selected_for_record+1 );
}


return(0);
}
