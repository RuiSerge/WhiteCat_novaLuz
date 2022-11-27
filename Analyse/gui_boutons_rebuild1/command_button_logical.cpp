void command_button_logical( int xcom, int ycom, int isstate, const std::string desc, const std::string raccourci, int IDmidi, int thecommand)
{
if((window_focus_id==0 || window_focus_id==W_MAINMENU || window_focus_id==W_PLOT )
   && mouse_x>xcom && mouse_x<xcom+65 && mouse_y>ycom && mouse_y<ycom+20  && mouse_released==0
   && index_moving_channel_scroller==0 && dragging_draw==0
   )
{


if( IDmidi==1625)
{
Midi_Faders_Affectation_Type++;
if(Midi_Faders_Affectation_Type>2){Midi_Faders_Affectation_Type=0;}
index_midi_mute=0;
reset_index_actions();
}

else
{
    if( Midi_Faders_Affectation_Type>0)
    {
    attribute_midi_solo_affectation(IDmidi,1);
    }
    else
{
switch (thecommand)//permet de faire un toggle du bon index
{
case 0://sequenciel
          if(index_window_sequentiel==0){;add_a_window(W_SEQUENCIEL);substract_a_window(W_MAINMENU);}
          else {substract_a_window(W_SEQUENCIEL);}

break;
case 1://time
          if(index_time==0){add_a_window(W_TIME);substract_a_window(W_MAINMENU);  }
           else {   substract_a_window(W_TIME); }
break;
case 2://banger
          if(index_show_banger_window==0)
          {add_a_window(W_BANGER);mouse_level_for_event=mouse_z;mouse_level_for_banger=mouse_z;substract_a_window(W_MAINMENU);}
          else {substract_a_window(W_BANGER);}
break;
case 3://wizard
if(index_show_wizard_window==0){add_a_window(W_WIZARD);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_WIZARD);}
break;
case 4://save

 if(index_menu_save==0){add_a_window(W_SAVE);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_SAVE);}
break;

case 10://patch
 if(index_patch_window==0){add_a_window(W_PATCH);substract_a_window(W_MAINMENU);}
     else {substract_a_window(W_PATCH);}
break;
case 11://list
if(index_list_projecteurs==0){add_a_window(W_LIST);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_LIST);}
break;
case 12://plot
if(index_plot_window==0){add_a_window(W_PLOT);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_PLOT);}
break;
case 13://freeze
 index_do_freeze=1;
 index_ask_confirm=1;
break;
case 14://do excude channels from GM
 index_do_exclude=1;
 index_ask_confirm=1;
break;
case 15://MY_WINDOW
if(index_my_window==0){add_a_window(W_MY_WINDOW);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_MY_WINDOW);}
break;

case 20://Faders
if(index_show_faders==0){add_a_window(W_FADERS);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_FADERS);}
break;
case 21://minifaders
if(index_show_minifaders==0){add_a_window(W_MINIFADERS);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_MINIFADERS);}
break;
case 22://trichromy
if(index_trichro_window==0){add_a_window(W_TRICHROMY);substract_a_window(W_MAINMENU);}
else  { substract_a_window(W_TRICHROMY);  }
break;
case 23://chasers
if(index_window_chasers==0){add_a_window(W_CHASERS);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_CHASERS);}
break;
case 24://grider
 if(index_grider_window==0){add_a_window(W_GRID);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_GRID);}
break;
case 25:
     if(index_wave_menu_window==0){add_a_window(W_WAVE);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_WAVE);}
break;



case 30://tracking
 if(index_video_window==0){ add_a_window(W_TRACKINGVIDEO);substract_a_window(W_MAINMENU); }
 else{ substract_a_window(W_TRACKINGVIDEO);}
break;

case 31://mover
 if(index_show_mover_window==0){add_a_window(W_MOVER);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_MOVER);}
break;
case 32://echo
 if(index_show_echo_window==0){add_a_window(W_ECHO);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_ECHO);}
break;
case 33://audioplayers
if(index_show_audio_window==0){add_a_window(W_AUDIO);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_AUDIO);}
reset_audio_indexs_to_dock();
break;
case 34://name
index_type=toggle(index_type);
strcpy(numeric,"");
numeric_postext=0;
break;
case 35://draw
if(index_draw_window==0){add_a_window(W_DRAW);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_DRAW);}
break;

case 40://CFG MENU
if(index_show_config_window==0){add_a_window(W_CFGMENU);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_CFGMENU);}
break;
case 41://iCat
if(index_window_gui_iCat==0){add_a_window(W_iCAT);substract_a_window(W_MAINMENU);}
else {substract_a_window(W_iCAT);}
break;
case 42: //npad
  if(index_visual_pad==0){add_a_window(W_NUMPAD);substract_a_window(W_MAINMENU);}
 else {substract_a_window(W_NUMPAD);}
break;
case 43://help
index_call_help=toggle(index_call_help);
if(index_call_help==1)
{
char txtsp[1024];
sprintf(txtsp,"iexplore www.le-chat-noir-numerique.fr/whitecat/dokuwiki/doku.php");
system(txtsp);
index_call_help=0;substract_a_window(W_MAINMENU);
}
break;
case 44://quit
index_ask_confirm=1;index_do_quit_with_save=1;
break;
case 100:
     plot_index_show_levels=toggle(plot_index_show_levels);
break;
case 101:
     plot_index_show_levels_from_faders=toggle(plot_index_show_levels_from_faders);
break;

case 102: //dock
if(index_do_dock==0){reset_index_actions();}
index_do_dock=toggle(index_do_dock);

switch (window_focus_id)
{
case W_CHASERS:
index_affect_chaser_to_dock=index_do_dock;
break;
case W_GRID:
for(int i=0;i<4;i++)
{
if(index_show_grid_player[i]==1)
{
gridplayer_to_affect_is=i; break;
}
}
break;
case W_MOVER:
index_affect_to_dock_mover=index_do_dock;
break;
case W_DRAW:
index_affect_draw_to_dock=index_do_dock;
break;
case W_ECHO:
index_affect_echo_to_dock=index_do_dock;
break;
case W_TIME:
index_affect_time=index_do_dock;
break;
case W_TRACKINGVIDEO:
index_affect_video_tracking_to_dock=index_do_dock;
break;
case W_TRICHROMY:
index_affect_color_to_dock=index_do_dock;
break;
case W_AUDIO:
index_affect_audio_to_dock=index_do_dock;
player_to_affect_to_dock=0;
audio_type_for_dock_affectation_is=0;
break;
case W_CFGMENU:
if(config_page_is==1) { index_affect_dmxin=index_do_dock; }
else if(config_page_is==3) {index_do_affect_net_to_dock=index_do_dock; }
break;
default:
break;
}

break;
case 103: //modify
if(index_do_modify==0){reset_index_actions();}
index_do_modify=toggle(index_do_modify);
break;
case 104://report
if(index_do_report==0){reset_index_actions();}
index_do_report=toggle(index_do_report);
break;
case 105://clear
if(index_main_clear==0){reset_index_actions();}
index_main_clear=toggle(index_main_clear);
break;
case 106://midi affect solo
Midi_Faders_Affectation_Type++;
if(Midi_Faders_Affectation_Type>2){Midi_Faders_Affectation_Type=0;}
index_midi_mute=0;
reset_index_actions();
break;
case 107://midi mute
reset_index_actions();
index_midi_mute=toggle(index_midi_mute);
    if(index_midi_mute==1)
    {
    for(int y=0;y<3072;y++)
    { is_raccrochage_midi_remote[y]=1;}
    sprintf(string_Last_Order,">>Midi IN muted");
    }
    else {
    for(int y=0;y<3072;y++)
    { is_raccrochage_midi_remote[y]=0;}
    sprintf(string_Last_Order,">>Midi IN un-muted");
    }
break;
case 108://MAIN MENU
if(mouse_released==0)
{

              mouse_released=1;
              switch(index_show_main_menu)
              {
              case 0:add_a_window(W_MAINMENU);index_show_main_menu=1; break;
              case 1:substract_a_window(W_MAINMENU);index_show_main_menu=0; break;
              default:
              break;
              }

}
break;
case 109://Midi refresh fader send out
 index_global_midi_send_on_faders=toggle(index_global_midi_send_on_faders);
 set_all_faders_midi_out(index_global_midi_send_on_faders);
 do_light_midi_send_on_faders=1;
break;
case 110://BLIND
index_blind=toggle(index_blind);
break;
case 111: //direct CH
if(index_direct_chan==0 && multiple_direct_chan==0)
{
reset_index_actions();
reset_indexs_confirmation();
index_direct_chan=1; index_do_dock=index_direct_chan;
}
else if(index_direct_chan==1 && multiple_direct_chan==0)
{
index_direct_chan=1;
multiple_direct_chan=1;
index_do_dock=1;
}
else if(index_direct_chan==1 && multiple_direct_chan==1)
{
reset_index_actions();
reset_indexs_confirmation();
}

break;
case 112: // view
 index_inspekt=toggle(index_inspekt);  i_m_over_a_track=0;
break;
case 113://HIPASS
index_do_hipass=toggle( index_do_hipass);
index_inspekt=index_do_hipass;
break;
case 114://FGROUP
if(index_do_fgroup==0)
{
reset_index_actions();
reset_indexs_confirmation();
index_do_fgroup=1;
}
else
{
reset_index_actions();
}
index_do_dock=index_do_fgroup;
break;
default:
break;
}
}

}
if(index_show_main_menu==1 ){window_bring_to_front(W_MAINMENU);}
mouse_released=1;
}
}
