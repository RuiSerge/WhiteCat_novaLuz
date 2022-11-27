int detection_over_window()
{
bool stop_detect=0;
int window_is=0;
if(mouse_y>hauteur_ChannelMenu )
{
for(int i=0;i<63;i++)
{
switch(window_opened[i])
        {
        case W_SAVEREPORT:
        if( mouse_x>= report_SL_X && mouse_x<= report_SL_X+350 && mouse_y>=report_SL_Y && mouse_y<=report_SL_Y+160)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_TRICHROMY:
        if( mouse_x>= xtrichro_window-158 && mouse_x<= xtrichro_window+157+(show_gel_list*gel_size_window) && mouse_y>=ytrichro_window-206  && mouse_y<= ytrichro_window+344)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_NUMPAD:
        if( mouse_x>= xnum_window && mouse_x<= xnum_window+480 && mouse_y>=ynum_window  && mouse_y<= ynum_window+300)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_TRACKINGVIDEO:
        if( mouse_x>= videoX && mouse_x<= videoX+frame_video_x+35 && mouse_y>=videoY  && mouse_y<= videoY+frame_video_y+460)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_ARTPOLLREPLY:
        if ( mouse_x>=artpoll_replyX && mouse_x<=artpoll_replyX+500 && mouse_y>=artpoll_replyY && mouse_y<=artpoll_replyY+400)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_FADERS :
        if(mouse_y>(YFader-80) && mouse_x<LargeurEspaceFaderSize)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_PATCH:
        if( (index_menu_curve==0 && mouse_x>=xpatch_window && mouse_x<=xpatch_window+450 && mouse_y>=ypatch_window && mouse_y<=ypatch_window+600)
        || ( index_menu_curve==1 && mouse_x>=xpatch_window && mouse_x<=xpatch_window+450+320 && mouse_y>=ypatch_window && mouse_y<=ypatch_window+600))
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_TIME:
        if (mouse_x>=xtime_window && mouse_x<=xtime_window+370 && mouse_y>=ytime_window && mouse_y<=ytime_window+300)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_SEQUENCIEL:
        if(mouse_x>=xseq_window && mouse_x<=xseq_window+670+(260*show_gridplayer_in_seq) && mouse_y>=yseq_window && mouse_y<=yseq_window+hauteur_globale_sequenciel)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_ASKCONFIRM:
        if(mouse_x>=XConfirm && mouse_x<=XConfirm+400 && mouse_y>=YConfirm && mouse_y<=YConfirm+100 )
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_PLOT:
        if(mouse_x>=x_plot && mouse_x<=x_plot+plot_window_x_size && mouse_y>=y_plot && mouse_y<=y_plot+plot_window_y_size )
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_ECHO:
        if(mouse_x>=x_echo && mouse_x<=x_echo+echo_window_x_size && mouse_y>=y_echo && mouse_y<=y_echo+echo_window_y_size )
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_DRAW:
        if(mouse_x>=x_Wdraw && mouse_x<=x_Wdraw+draw_window_x_size && mouse_y>=y_Wdraw && mouse_y<=y_Wdraw+draw_window_y_size )
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_LIST:
        if(mouse_x>=Xlistproj && mouse_x<=Xlistproj+350 && mouse_y>=Ylistproj && mouse_y<=Ylistproj+600)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_SAVE:
        if(mouse_x>=xsave_window && mouse_x<=xsave_window+420 && mouse_y>=ysave_window && mouse_y<=ysave_window+520)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_MAINMENU:
        if(mouse_x>x_mainmenu && mouse_x<=x_mainmenu+size_x_mainmenu && mouse_y>=y_mainmenu && mouse_y<=y_mainmenu+size_y_mainmenu)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_BANGER:
        if(mouse_x>=X_banger && mouse_x<=X_banger+size_X_Banger && mouse_y>=Y_banger && mouse_y<=Y_banger+size_Y_Banger)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_ALARM:
        if( mouse_x>=XAlarm && mouse_x<=XAlarm+300 && mouse_y>=YAlarm && mouse_y<=YAlarm+110)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_AUDIO:
        if(mouse_x>=XAudio && mouse_x<=XAudio+600 && mouse_y>=YAudio && mouse_y<=YAudio+150+(index_nbre_players_visibles*6*20))
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_CFGMENU:
        if(mouse_x>=window_cfgX && mouse_x<=window_cfgX+largeurCFGwindow && mouse_y>=window_cfgY  && mouse_y<=window_cfgY+hauteurCFGwindow+40)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_WIZARD:
        if( mouse_x>=Xwizard && mouse_x<=Xwizard+480 && mouse_y>=Ywizard && mouse_y<=Ywizard+420)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_MINIFADERS:
        if( mouse_x>=xMinifaders-10 && mouse_x<=xMinifaders+700 && mouse_y>=yMinifaders-50 && mouse_y<=yMinifaders+400)
        {window_is=window_opened[i];stop_detect=1;}//index_over_minifaders=1 index_show_minifaders==1
        break;
        case W_CHASERS:
        if( mouse_x>=Xchasers && mouse_x<=Xchasers+620 && mouse_y>=Ychasers && mouse_y<=Ychasers+160+(nbre_track_visualisables*40))
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_MOVER:
        if(mouse_x>=xmover_window && mouse_x<=xmover_window+1000 && mouse_y>=ymover_window-40 && mouse_y<=ymover_window+660)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_iCAT:
        if(mouse_x>=X_gui_iCat && mouse_x<=X_gui_iCat+largeuriCat && mouse_y>=Y_gui_iCat && mouse_y<=Y_gui_iCat+hauteuriCat)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_GRID:
        if( mouse_x>=grider_window_x && mouse_x<=grider_window_x+largeurGrider && mouse_y>=grider_window_y && mouse_y<=grider_window_y+hauteurGrider)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_WAVE:
        if( mouse_x>=position_x_wave_menus && mouse_x<=position_x_wave_menus+size_x_wave_menus && mouse_y>=position_y_wave_menus && mouse_y<=position_y_wave_menus+size_y_wave_menus)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        case W_MY_WINDOW:
        if( mouse_x>=my_window_x && mouse_x<=my_window_x+largeur_my_window && mouse_y>=my_window_y && mouse_y<=my_window_y+hauteur_my_window)
        {window_is=window_opened[i];stop_detect=1;}
        break;
        default:
        break;
        }
if(stop_detect==1){break;}
}
}
if(stop_detect==0){index_over_A_window=0;}
else {index_over_A_window=1;window_bring_to_front(window_is);}






if(index_over_A_window==0 && mouse_y> hauteur_ChannelMenu && mouse_x<560 )
{
index_over_channelspace=1;
}
else {index_over_channelspace=0;}

return(window_is);
}
