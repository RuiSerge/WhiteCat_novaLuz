int check_graphics_mouse_handling()
{

do_logical_ChannelScroller(ChScrollX, ChScrollY);

if(index_over_channelspace==1 && window_focus_id==0)
{
logical_channelspace();             //classique et custom
}



do_logical_grand_master(1050, 55, 40);




if((mouse_x<largeur_ChannelMenu && mouse_y>hauteur_ChannelMenu )||(mouse_x>largeur_ChannelMenu  ))
{

switch(window_focus_id)
{
case W_SAVEREPORT:
     do_logical_MoveCloseBox(report_SL_X+20,report_SL_Y+25,W_SAVEREPORT);
break;
case W_TRICHROMY:
     do_logical_Interface_Trichromie(xtrichro_window,ytrichro_window,125,15);
     do_logical_MoveCloseBox(xtrichro_window+20-158,ytrichro_window+25-206,W_TRICHROMY);
break;
case W_NUMPAD:
     do_logical_visual_numeric_pad(xnum_window,ynum_window);
     do_logical_FunctionBoxChannel(xnum_window+405,ynum_window+85,60,30,15);
     do_logical_MoveCloseBox(xnum_window+405,ynum_window+25,W_NUMPAD);
break;
case W_TRACKINGVIDEO:
     do_logical_Interface_video_window(videoX,videoY);
     do_logical_MoveCloseBox(videoX+20,videoY+25,W_TRACKINGVIDEO);
break;
case W_ARTPOLLREPLY:
     do_logical_MoveCloseBox(artpoll_replyX+435,artpoll_replyY+25,W_ARTPOLLREPLY);
break;
case W_FADERS :
     do_logical_FaderSpace(XFader-((int)(scroll_faderspace*facteur_scroll_fader_space)),YFader,int(50*size_faders),int(150+((190-150)*size_faders)),48);//x y / largeurfader / espacement des faders, nbr faders to draw
break;
case W_PATCH:
     do_logical_PatchBox(xpatch_window, ypatch_window, Patch_Scroll_Factor);
     if(index_menu_curve==1)
     {do_logical_menu_curve(xpatch_window+455, ypatch_window);}
     do_logical_MoveCloseBox(xpatch_window+20,ypatch_window+25, W_PATCH);
break;
case W_TIME:
     do_logical_Time_Window(xtime_window, ytime_window,100);
     do_logical_MoveCloseBox(xtime_window+20,ytime_window+25,W_TIME);
break;
case W_SEQUENCIEL:
     do_logical_Sequenciel_Window(xseq_window, yseq_window,670+(260*show_gridplayer_in_seq),hauteur_globale_sequenciel);
     do_logical_MoveCloseBox(xseq_window+20,yseq_window+25,W_SEQUENCIEL);
break;
case W_ASKCONFIRM:
     do_logical_MoveCloseBox(XConfirm+20,YConfirm+25,W_ASKCONFIRM);
break;
case W_PLOT:
     do_logical_Plot_window(x_plot,y_plot);
     do_logical_MoveCloseBox(x_plot+20,y_plot+25,W_PLOT);
break;
case W_ECHO:
     do_logical_echo_window(x_echo,y_echo);
     do_logical_MoveCloseBox(x_echo+20,y_echo+25,W_ECHO);
break;
case W_DRAW:
     do_logical_Draw_Window(x_Wdraw,y_Wdraw);
     do_logical_MoveCloseBox(x_Wdraw+20,y_Wdraw+25, W_DRAW);
break;
case W_LIST:
     do_logical_liste_projecteurs(Xlistproj ,Ylistproj);
     do_logical_MoveCloseBox(Xlistproj+20,Ylistproj+25,W_LIST);
break;
case W_SAVE:
     do_logical_Save_Menu(xsave_window,ysave_window);
     do_logical_MoveCloseBox(xsave_window+20,ysave_window+25,W_SAVE);
break;
case W_MAINMENU:
     do_logical_Menus(x_mainmenu,y_mainmenu);
     do_logical_MoveCloseBox(x_mainmenu+20,y_mainmenu+25,W_MAINMENU);
break;
case W_BANGER:
     do_logical_fenetre_banger(X_banger,Y_banger);
     do_logical_MoveCloseBox(X_banger+20,Y_banger+25,W_BANGER);
break;
case W_ALARM:

     do_logical_MoveCloseBox(XAlarm+20,YAlarm+25, W_ALARM) ;
break;
case W_AUDIO:
     do_logical_fenetre_audio(XAudio,YAudio);
     do_logical_MoveCloseBox(XAudio+20,YAudio+25,W_AUDIO);
break;
case W_CFGMENU:
     do_logical_MoveCloseBox(window_cfgX+20,window_cfgY+20,W_CFGMENU);
break;
case W_WIZARD:
     do_logical_MoveCloseBox(Xwizard+20,Ywizard+20,W_WIZARD);
break;
case W_MINIFADERS:
     mini_faders_panel_core(xMinifaders,yMinifaders,20);
     do_logical_MoveCloseBox(xMinifaders+10,yMinifaders-30,W_MINIFADERS);
break;
case W_CHASERS:
     do_logical_fenetre_chasers( Xchasers,Ychasers);
     do_logical_MoveCloseBox(Xchasers+20,Ychasers+20,W_CHASERS);
break;
case W_MOVER:

     do_logical_MoveCloseBox(xmover_window+20, ymover_window-20,W_MOVER);
break;
case W_iCAT:
     do_logical_MoveCloseBox( X_gui_iCat+20,Y_gui_iCat+20,W_iCAT);
break;
case W_GRID:
     do_logical_Grider_Box(grider_window_x, grider_window_y);
     do_logical_MoveCloseBox( grider_window_x+20,grider_window_y+20,W_GRID);
break;
case W_MY_WINDOW:
     do_logical_my_window_Box(my_window_x, my_window_y);
     do_logical_MoveCloseBox( my_window_x+20,my_window_y+20,W_MY_WINDOW);
break;
case W_WAVE:
     do_logical_fenetre_wave_menus(position_x_wave_menus, position_y_wave_menus);
     do_logical_MoveCloseBox( position_x_wave_menus+20,position_y_wave_menus+20,W_WAVE);
break;
default:
break;
}
}

do_logical_ChannelsMenuSelection(ChannelXMenu,ChannelYMenu);

 return(0);
}
