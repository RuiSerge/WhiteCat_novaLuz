int move_window(int idwindowis)
{
if(mouse_button==1 && window_focus_id==idwindowis && mouse_y>hauteur_ChannelMenu)
 {

 switch(window_focus_id)
 {
 case W_SAVEREPORT:
 report_SL_X=mouse_x-(40+15);
 report_SL_Y=mouse_y-25;
 im_moving_a_window=1;
 break;

 case W_TRICHROMY:
 xtrichro_window=mouse_x+100;
 ytrichro_window=mouse_y+180;
 //rafraichissement du curseur Hue
 vx =(int) (cos(angle_snap)*125);
 vy =(int) (sin(angle_snap)*125);
 position_curseur_hue_x= xtrichro_window+vx;
 position_curseur_hue_y=ytrichro_window+vy ;
 im_moving_a_window=1;
 break;
 case W_NUMPAD:
 xnum_window=mouse_x-(405+30+15);
 ynum_window=mouse_y-25;
 rafraichissement_padwheel();
 im_moving_a_window=1;
 break;
 case W_TRACKINGVIDEO:
 videoX=mouse_x-(40+15);
 videoY=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_ARTPOLLREPLY:
 artpoll_replyX=mouse_x-470; artpoll_replyY=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_FADERS:
 break;
 case W_PATCH:
 xpatch_window=mouse_x-(40+15);
 ypatch_window=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_TIME:
 xtime_window=mouse_x-(40+15);
 ytime_window=mouse_y-25;
 //rafraichissement du curseur
   vtimex = (cos(angle_timesnap)*100);
   vtimey = (sin(angle_timesnap)*100);
   position_curseur_time_x= xtime_window+vtimex+150;
   position_curseur_time_y= ytime_window+vtimey+150;
 im_moving_a_window=1;
 break;
 case W_SEQUENCIEL:
 xseq_window=mouse_x-(40+15);
 yseq_window=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_ASKCONFIRM:
 XConfirm=mouse_x-(40+15);
 YConfirm=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_PLOT:
 x_plot=mouse_x-(40+15);
 y_plot=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_ECHO:
 x_echo=mouse_x-(40+15);
 y_echo=mouse_y-25;
 im_moving_a_window=1;
 break;

 case W_MAINMENU:
 x_mainmenu=mouse_x-(40+15);
 y_mainmenu=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_LIST:
 Xlistproj=mouse_x-(40+15);
 Ylistproj=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_SAVE:
 xsave_window=mouse_x-(40+15);
 ysave_window=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_BANGER:
 X_banger=mouse_x-(40+15);
 Y_banger=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_ALARM:
 XAlarm=mouse_x-(40+15);
 YAlarm=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_AUDIO:
 XAudio=mouse_x-(40+15);
 YAudio=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_CFGMENU:
 window_cfgX=mouse_x-(40+15);
 window_cfgY=mouse_y-25;
 rafraichissement_clockwheel();
 im_moving_a_window=1;
 break;
 case W_WIZARD://wizard window
 Xwizard=mouse_x-(40+15);
 Ywizard=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_MINIFADERS://minifaders
 xMinifaders=mouse_x-50;
 yMinifaders=mouse_y+25;
 im_moving_a_window=1;
 break;
 case W_CHASERS://chasers
 Xchasers=mouse_x-(40+15);
 Ychasers=mouse_y-20;
 im_moving_a_window=1;
 break;
 case W_MOVER://mover
 xmover_window=mouse_x-(40+15);
 ymover_window=mouse_y+20;
 im_moving_a_window=1;
 break;
 case W_iCAT://iCatbuilder
 X_gui_iCat=mouse_x-(40+15);
 Y_gui_iCat=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_GRID://grid
 grider_window_x=mouse_x-(40+15);
 grider_window_y=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_DRAW:
 x_Wdraw=mouse_x-(40+15);
 y_Wdraw=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_WAVE:
 position_x_wave_menus=mouse_x-(40+15);
 position_y_wave_menus=mouse_y-25;
 im_moving_a_window=1;
 break;
 case W_MY_WINDOW:
 my_window_x=mouse_x-(40+15);
 my_window_y=mouse_y-25;
 im_moving_a_window=1;
 break;
 default:
 break;
 }
}

 return(0);
}
