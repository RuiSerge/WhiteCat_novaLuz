int main() {
int main() {

load_screen_config();

Settings::SetWindowBorder(false);//plus de momde border window, car inutilisable avec les menus

Setup::SetupProgram(KEYBOARD | MOUSE);

if(index_fullscreen==0)
{Setup::SetupScreen( largeur_ecran, hauteur_ecran,WINDOWED, desktop_color_depth() );}
else {Setup::SetupScreen( largeur_ecran, hauteur_ecran,FULLSCREEN, desktop_color_depth() );}

   HWND hwnd = win_get_window();
    if (hwnd != NULL)
        MoveWindow(hwnd, posX_mainwindow, posY_mainwindow, SCREEN_W, SCREEN_H, true);


   install_joystick(JOY_TYPE_AUTODETECT);
   calibrate_joystick_name(0);


   install_timer();

   jpgalleg_init();

   LOCK_FUNCTION(ticker_dmxIn);
   install_int_ex(ticker_dmxIn , ticker_dmxIn_rate);


   LOCK_FUNCTION(ticker_artnet);
   LOCK_VARIABLE(ticks_for_artnet);
   install_int_ex(ticker_artnet , ticker_artnet_rate);

   rest(100);

   LOCK_VARIABLE(ticks);
   LOCK_FUNCTION(ticker);
   install_int_ex(ticker , ticker_rate);

   //refonte
   LOCK_VARIABLE(ticks_arduino);
   LOCK_FUNCTION(ticker_arduino);
   install_int_ex(ticker_arduino ,BPS_TO_TIMER(ARDUINO_RATE));

   LOCK_VARIABLE(ticks_wave);
   LOCK_FUNCTION(ticker_WAVE);
   install_int_ex(ticker_WAVE ,BPM_TO_TIMER(BPM_WAVE_RATE));

    LOCK_FUNCTION(my_callback);
    mouse_callback = my_callback;


   LOCK_FUNCTION(dixiemes_de_secondes);
   install_int_ex(dixiemes_de_secondes , ticker_dixiemes_de_secondes_check);


   LOCK_FUNCTION( ticker_full_loop);
   install_int_ex(ticker_full_loop,ticker_full_loop_rate );

    LOCK_FUNCTION(ticker_midi_clock);
    install_int_ex(ticker_midi_clock,ticker_midi_clock_rate );

   load_indexes();
   LoadWhiteCatColorProfil();

   Canvas::Fill(CouleurFond);
   Canvas::Refresh();



   Load_Fonts();
   save_load_print_to_screen("Loaded Fonts");


   logo.Load( "gfx/logo.png" );//ne s'affiche que en 32 bits !!!

   if( logo.Load( "gfx/logo.png" ) != true )
      {
      allegro_message( "Couldn't load gfx/logo.png" );
      exit( -1 );
      }



    /*sab 28/11/2014 deb */
    whc_mousePointer::c_Init(whc_mousePointer::arrow,"gfx/arrow.png");
    whc_mousePointer::c_Init(whc_mousePointer::arrow_down,"gfx/arrow_down.png");
    whc_mousePointer::c_Init(whc_mousePointer::drag,"gfx/drag.png");
    /*sab 28/11/2014 fin */
	whc_hotkeys_init("whc_hotkey_user.txt","whc_hotkey_standard.txt") ;  // 1er ficher recherch� dans le r�pertoire \user - s'l n'existe pas encore on prend le 2d fichier qui est cherch� dans ressources
	save_load_print_to_screen("Loaded hotkeys");




    Canvas::Fill(CouleurFond);
    Canvas::Refresh();



   save_load_print_to_screen("Loaded Gfx");


   sprintf(string_last_ch,"Last Ch. selected: %d", last_ch_selected);
   sprintf(string_Last_Order,">> This is Last Order");


  save_load_print_to_screen("Loading setup conf");
 Load_setup_conf(); //avant tout sinon, le cfg ecrit ailleurs et ca fout la zone
 save_load_print_to_screen("Init Arrays");

 for (int r=0;r<72;r++)
 {
 specify_who_to_save_load[r]=1;
 }


 GlobInit();//rajout version 0.8.2.3
 reset_all_bangers();
 generation_Tableau_noms_clavier_FR() ;
 save_load_print_to_screen("Init Midi");
 InitMidi();//init avant les appels de fichiers
 midi_init_sepecial_case_key_on();//pour r�gler pb de cle flashs et key on key off
 ////////////////////////////////////////////////////////////

 load_onstart_config();
 load_core_config();
  ///////////////////////////////////////////////////////
 save_load_print_to_screen("Loading Dmx conf");
 load_dmx_conf();
 save_load_print_to_screen("Loading Art-net conf");
 load_artnet_conf();

 detection_mise_en_place_carte_reseaux();

 load_network_conf();//icat
 save_load_print_to_screen("Loading Art-netnetwork conf");


 save_load_print_to_screen("Loading Video conf");
 Load_Video_Conf();
 sprintf(tmp_ip_artnet,ip_artnet);


 load_show_coming_from();
 idf++;


 On_Open_name_of_directory();

 save_load_print_to_screen("Loading Gels List");
 load_gel_list_numerical();
 idf++;

 Canvas::Fill(CouleurFond);
 Canvas::Refresh();
 save_load_print_to_screen("Init Sound");
 InitSound();
 Load_Show();

 init_kbd_custom();
 save_load_print_to_screen("Init Keyboard");
 Show_report_save_load();

 save_load_print_to_screen("Init Dmx");
 Init_dmx_interface();

 if(camera_on_open==1)
 {
 save_load_print_to_screen("Init Camera");
 InitVideo();

 }





scan_importfolder("");
scan_savesfolder();


if( open_arduino_on_open==1)
{
save_load_print_to_screen("Init Arduino");
arduino_init(0);
}


prepare_move_values(dock_move_selected);//prepa
Prepare_Cross_Spline(dock_move_selected);

save_load_print_to_screen("Init Backamnesia");
 if(set_display_switch_mode(SWITCH_BACKGROUND))
 {set_display_switch_mode(SWITCH_BACKAMNESIA);}


init_done=1;
if(there_is_an_error_on_save_load==1){index_show_save_load_report=1;there_is_change_on_show_save_state=1;    }

 mouse_released=0;
 entered_main=1;
if(enable_launchpad==1)
{reset_launchpad();}

 init_artnet_variables();

    if(allow_artnet_in==1 && artnet_serveur_is_initialized==0)
      {
	initialisation_serveur_artnet();
     }

 init_iphone_fonts();
 if (enable_iCat==1)
 {
 initialisation_clientserveur_iCat();

 nbrbytessendediCat=sendto(sockiCat, "opengl 1",sizeof("opengl 1"),0,(SOCKADDR*)&siniCat,sinsizeiCat);
 init_iCat_data();//varibales de stockage
 someone_changed_in_sequences=1;//icat
 do_send_icat_init_page=1;
 do_refresh_iCat(iCatPageis);

 }


bmp_buffer_trichro= create_bitmap(315,550);
clear_bitmap(bmp_buffer_trichro);


rafraichissement_padwheel();
rafraichissement_clockwheel();

recalculate_draw_sizes(draw_preset_selected);

bang_is_sended[index_banger_selected]=1;

rest(100);

starting_wcat=1;
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


if(index_loading_a_sound_file!=0)
{
for(int i=0;i<4;i++)
{
  if(player_ignited[i]==1 && player_position_on_save[i]<=length_of_file_in_player[i] )
  {
  switch(i)
  {
  case 0:
  player1->setPosition(player_position_on_save[i]);
  break;
  case 1:
  player2->setPosition(player_position_on_save[i]);
  break;
  case 2:
  player3->setPosition(player_position_on_save[i]);
  break;
  case 3:
  player4->setPosition(player_position_on_save[i]);
  break;
  default:
  break;
  }
 position_of_file_in_player[i]=player_position_on_save[i];
}
}
}


reset_temp_state_for_channel_macros_launch();//christoph 18/12/14 pour intialisation au d�marrage de wcat des channels macros

starting_wcat=0;



while(index_quit!=1)
{


MemoiresExistantes[0]=1;
show_im_recording_a_time=0;// met � z�ro l'affichage du stock visuel du time



 switch(index_art_polling)
 {
    case 0:
    main_actions_on_screen();
    break;
    case 1:
      if((bytesreceived = recvfrom(sock,artpollreply_message,sizeof(artpollreply_message),0,(SOCKADDR*)&sinS,&sinsize)!=0))
      {      AnalyseArtPollReply();      }
      Procedure("Art-Net Polling","Please wait 3 seconds, polling network ...");
    break;
    default: break;
   }


if(there_is_change_on_show_save_state==1)
{
check_save_load_report_window();
there_is_change_on_show_save_state=0;
}

if(index_show_chrono==1){show_foreground_chrono(xtime_window+115,ytime_window-80);}

Canvas::Refresh();
if(index_do_a_screen_capture==1){do_a_screen_capture();index_do_a_screen_capture=0;}
if(index_do_a_plot_screen_capture==1 ){do_plot_screen_capture(plot_name_of_capture);index_do_a_plot_screen_capture=0;}

}

entered_main=0;
substract_a_window(W_ASKCONFIRM);
window_focus_id=window_who_is_on_top();

init_done=0;//evite envois data pendant save de fermeture


Canvas::Refresh();
Canvas::Fill(CouleurFond);


save_load_print_to_screen("Quitting");
Show_report_save_load();
save_load_print_to_screen("Closing dmx");
Close_dmx_interface();
save_load_print_to_screen("Closing Arduino");
arduino_close(0);

save_load_print_to_screen("Closing video");
CloseVideo();
save_load_print_to_screen("Closing midi");

 if (enable_iCat==1 && iCat_serveur_is_initialized==1)
 {
 fermeture_clientserveur_iCat();
 //if(client_icat_is_closed==1)  fermeture_client_iCat();
 }


QuitMidi() ;
save_load_print_to_screen("Saving Show");
if(index_please_do_not_save==0)//a garder sinon plante sur le please not save
{
Save_Show();
save_load_print_to_screen("Saving Video Conf");
Save_Video_Conf();
save_load_print_to_screen("Saving Screen Conf");
Save_Screen_Config();
save_load_print_to_screen("Saving Setup Conf");
Save_setup_conf();

}
destroy_bitmap(bmp_buffer_trichro);

remove_timer();
WSACleanup ();//liberation librairie socket
return 0;
}
