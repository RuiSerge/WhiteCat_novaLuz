int Boxes()
{
ChannelScroller(ChScrollX, ChScrollY);

if(ClassicalChannelView ==1)
{
Canvas::SetClipping(0,ChannelYMenu+hauteur_ChannelMenu,largeur_ecran,hauteur_ecran);
ClassicalChannelSpace(XChannels, YChannels,  scroll_channelspace);// x y espacement latéral // espacement vertical // scrolling down
Canvas::DisableClipping();
}

else
{
int pos_y_vision=0;
Canvas::SetClipping(XChannels,ChannelYMenu+hauteur_ChannelMenu ,XChannels+600 , hauteur_ecran);
for(int i=0;i<nbre_de_vues_circuits;i++)
{
if(Channel_View_MODE[i]==1 )
{
Draw_Channel_Preset_Title(XChannels, YChannels+pos_y_vision-(int)(((float)scroll_channelspace)/ ratioview),i);
pos_y_vision+= 60;
Draw_Channel_Preset_View(XChannels, YChannels+pos_y_vision-(int)(((float)scroll_channelspace)/ ratioview), i);
pos_y_vision+=((channel_number_of_lines[i])* (70))+ hauteur_preset_titre;
}
}
Canvas::DisableClipping();
}


RetourInfos(680,40);
grand_master(1050, 55);//x y largeur
show_windows_list_id(1100, 50);//debug windows

petitchiffre.Print(versionis,680,195);
petitchiffre.Print(nickname_version,680,205);




petitchiffre.Print("Focus: ",680,220);
petitchiffre.Print(ol::ToString(window_focus_id),720,220);
petitchiffre.Print("Over Window: ",680,230);
petitchiffre.Print(ol::ToString(index_over_A_window),770,230);
petitchiffre.Print("Debug: ",760,220);
petitchiffre.Print(string_debug,800, 220);

Rect RetourConduite(Vec2D(680,240),Vec2D(270,40));
RetourConduite.SetRoundness(5);
RetourConduite.Draw(CouleurBlind.WithAlpha(0.5));
RetourConduite.DrawOutline(CouleurLigne);
petitchiffre.Print("Last_save / SAVE:",685,255);
petitchiffre.Print(my_show_is_coming_from,685,270);

Rect False(Vec2D(970,240),Vec2D(55,15));
False.Draw(CouleurBlind.WithAlpha(index_false_shift*alpha_blinker));
False.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print("F-Shift",975,252);

False.MoveTo(Vec2D(970,265));
False.Draw(CouleurBlind.WithAlpha(index_false_control*alpha_blinker));
False.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print("F-Ctrl",980,277);

*/

for (int f=63;f>=0;f--)
{

     switch (window_opened[f])
     {
        case W_SAVEREPORT:
        Show_report_save_load();
        MoveCloseBox(report_SL_X+20,report_SL_Y+25,W_SAVEREPORT);
        break;
        case W_TRICHROMY:
        Interface_Trichromie(xtrichro_window,ytrichro_window,125,15);
        MoveCloseBox(xtrichro_window+20-158,ytrichro_window+25-206,W_TRICHROMY);
        break;
        case W_NUMPAD:
        visual_numeric_pad(xnum_window,ynum_window);
        FunctionBoxChannel(xnum_window+405,ynum_window+85,60,30,15);//x y largeurbox hauteur largeur box separateurspace);
        MoveCloseBox(xnum_window+405,ynum_window+25,W_NUMPAD);
        break;
        case W_TRACKINGVIDEO:
        Interface_video_window(videoX,videoY);
        MoveCloseBox(videoX+20,videoY+25,W_TRACKINGVIDEO);
        break;
        case W_ARTPOLLREPLY:
        show_artpoll_reply(artpoll_replyX,artpoll_replyY);
        MoveCloseBox(artpoll_replyX+435,artpoll_replyY+25,W_ARTPOLLREPLY);
        break;
        case W_FADERS :
        FaderSpace(XFader-((int)(scroll_faderspace*facteur_scroll_fader_space)),YFader,182,max_faders);//x y / largeurfader / espacement des faders, nbr faders to draw
        break;
        case W_PATCH:
        PatchBox(xpatch_window, ypatch_window, Patch_Scroll_Factor);
        MoveCloseBox(xpatch_window+20,ypatch_window+25, W_PATCH);
        break;
        case W_ECHO:
        echo_window(x_echo,y_echo);
        MoveCloseBox(x_echo+20,y_echo+25,W_ECHO);
        break;
        case W_DRAW:
        Draw_Window(x_Wdraw,y_Wdraw);
        MoveCloseBox(x_Wdraw+20,y_Wdraw+25, W_DRAW);
        break;
        case W_TIME:
        Time_Window(xtime_window, ytime_window,100);
        MoveCloseBox(xtime_window+20,ytime_window+25,W_TIME);
        break;
        case W_SEQUENCIEL:
        Sequenciel_Window(xseq_window, yseq_window,670+(260*show_gridplayer_in_seq),hauteur_globale_sequenciel);
        MoveCloseBox(xseq_window+20,yseq_window+25,W_SEQUENCIEL);
        break;
        case W_MAINMENU:
        Menus(x_mainmenu,y_mainmenu);
        MoveCloseBox(x_mainmenu+20,y_mainmenu+25,W_MAINMENU);
        break;
        case W_ASKCONFIRM:
        fenetre_confirm();
        MoveCloseBox(XConfirm+20,YConfirm+25,W_ASKCONFIRM);
        break;
        case W_PLOT:
        Plot_window(x_plot,y_plot);
        MoveCloseBox(x_plot+20,y_plot+25,W_PLOT);
        break;
        case W_LIST:
        liste_projecteurs(Xlistproj ,Ylistproj);
        MoveCloseBox(Xlistproj+20,Ylistproj+25,W_LIST);
        break;
        case W_SAVE:
        Save_Menu(xsave_window,ysave_window);
        MoveCloseBox(xsave_window+20,ysave_window+25,W_SAVE);
        break;
        case W_WAVE:
        fenetre_wave_menus(position_x_wave_menus,position_y_wave_menus);
        MoveCloseBox(position_x_wave_menus+20,position_y_wave_menus+25,W_WAVE);
        break;
        case W_BANGER:
        fenetre_banger(X_banger,Y_banger);
        MoveCloseBox(X_banger+20,Y_banger+25,W_BANGER);
        break;
        case W_ALARM:
        alarm_window();
        MoveCloseBox(XAlarm+20,YAlarm+25, W_ALARM) ;
        break;
        case W_AUDIO:
        fenetre_audio(XAudio,YAudio);
        MoveCloseBox(XAudio+20,YAudio+25,W_AUDIO);
        break;
        case W_CFGMENU:
        config_general_menu();
        MoveCloseBox(window_cfgX+20,window_cfgY+20,W_CFGMENU);
        break;
        case W_WIZARD:
        fenetre_wizard(Xwizard,Ywizard);
        MoveCloseBox(Xwizard+20,Ywizard+20,W_WIZARD);
        break;
        case W_MINIFADERS:
        mini_faders_panel_visu(xMinifaders,yMinifaders,20);
        MoveCloseBox(xMinifaders+10,yMinifaders-30,W_MINIFADERS);
        break;
        case W_CHASERS:
        chaser_window( Xchasers,Ychasers);
        MoveCloseBox(Xchasers+20,Ychasers+20,W_CHASERS);
        break;
        case W_MOVER:
        mover_box(xmover_window, ymover_window);
        MoveCloseBox(xmover_window+20, ymover_window-20,W_MOVER);
        break;
        case W_iCAT:
        BoxGuiBuilder_iCat( X_gui_iCat, Y_gui_iCat);
        MoveCloseBox( X_gui_iCat+20,Y_gui_iCat+20,W_iCAT);
        break;
        case W_GRID:
        Grider_Box(grider_window_x, grider_window_y);
        MoveCloseBox( grider_window_x+20,grider_window_y+20,W_GRID);
        break;
        case W_MY_WINDOW:
        my_window_Box(my_window_x, my_window_y);
        MoveCloseBox( my_window_x+20,my_window_y+20,W_MY_WINDOW);
        break;
        default:
        break;
      }
   }


ChannelsMenuSelection(ChannelXMenu,ChannelYMenu);//menu par dessus


if(numeric_postext>0 || index_type==1)
{
Rect nameAera( Vec2D( 670, 27), Vec2D ( 380,40));
nameAera.SetRoundness(15);
nameAera.SetLineWidth(triple_epaisseur_ligne_fader);
nameAera.Draw(CouleurFader.WithAlpha(index_type));
Rect UnderText(Vec2D(670,32),Vec2D((numeric_postext*14)+50,30));
UnderText.SetRoundness(7.5);
UnderText.Draw(CouleurFond);
UnderText.Draw(CouleurLigne.WithAlpha(0.1));
UnderText.DrawOutline(CouleurFader);
neuro.Print(string_numeric_entry,680,55);//input chaine clavier numerique
}

return(0);

}
