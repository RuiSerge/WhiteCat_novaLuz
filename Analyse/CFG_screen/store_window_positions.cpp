int store_window_positions()
{
windows_position[1][0]=xpatch_window;
windows_position[1][1]=ypatch_window;
windows_position[2][0]=xtime_window;
windows_position[2][1]=ytime_window;
windows_position[3][0]=xseq_window;
windows_position[3][1]=yseq_window;
windows_position[4][0]=xtrichro_window;
windows_position[4][1]=ytrichro_window;
windows_position[5][0]=xnum_window;
windows_position[5][1]=ynum_window;
windows_position[6][0]=videoX;
windows_position[6][1]=videoY;
windows_position[7][1]=YFader;
windows_position[8][0]=XAudio;
windows_position[8][1]=YAudio;
windows_position[9][0]=XGConfig;
windows_position[9][1]=YGConfig;
windows_position[10][0]=XConfirm;
windows_position[10][1]=YConfirm;

windows_position[11][0]=grider_window_x;
windows_position[12][1]=grider_window_y;
windows_position[12][0]=x_plot;
windows_position[12][1]=y_plot;

windows_position[13][0]=window_cfgX;
windows_position[13][1]=window_cfgY;
windows_position[14][0]=Xwizard;
windows_position[14][1]=Ywizard;
windows_position[15][0]=xMinifaders;
windows_position[15][1]=yMinifaders;
windows_position[16][0]=Xchasers;
windows_position[16][1]=Ychasers;
windows_position[17][0]=xmover_window;
windows_position[17][1]=ymover_window;
windows_position[18][0]=X_gui_iCat;
windows_position[18][1]=Y_gui_iCat;
return(0);
}
