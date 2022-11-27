int Save_Window_Conf()
{

FILE *fpi;
if((fpi=fopen("config_windows.txt","w")))//etait wb
{
fprintf(fpi,"#arguments: X Y position of windows: Colors / Numeric / Video / Patch /\n");
fprintf(fpi,"%d %d / %d  %d / %d %d / %d %d /\n",xtrichro_window , ytrichro_window , xnum_window , ynum_window , videoX , videoY, xpatch_window, ypatch_window);
fprintf(fpi,"#arguments:  Save Load Report / Time / Sequenciel /\n");
fprintf(fpi,"%d %d / %d %d / %d %d /\n",report_SL_X,report_SL_Y, xtime_window, ytime_window, xseq_window, yseq_window);
fprintf(fpi,"#arguments:   FadersSpace(Y only) / Config window / Confirm Box / MiniSeq / Save Window\n");
fprintf(fpi,"%d / %d %d / %d %d /\n",YFader, XConfirm, YConfirm,xsave_window, ysave_window );
fprintf(fpi,"#arguments: X Y position of windows: Help Window / Alarm window / Config window / Banger\n");
fprintf(fpi,"%d %d / %d %d / %d %d / %d %d /\n",XAlarm,YAlarm,XAudio,YAudio, window_cfgX, window_cfgY, X_banger,Y_banger);
fprintf(fpi,"#arguments: X Y position of windows: Wizard window/ Minifaders / List / Chasers\n");
fprintf(fpi,"%d %d / %d  %d / %d %d / %d %d / %d %d /\n",Xwizard,Ywizard,xMinifaders, yMinifaders, Xlistproj, Ylistproj, Xchasers, Ychasers, xmover_window, ymover_window);
fprintf(fpi,"#arguments: X Y position of windows: iCatBuilder / Grider / Plot / Main Menu / Draw / Echo /\n");
fprintf(fpi,"%d %d / %d %d / %d %d / %d %d / %d %d / %d %d /\n",X_gui_iCat,Y_gui_iCat,grider_window_x,grider_window_y, x_plot, y_plot, x_mainmenu, y_mainmenu, x_Wdraw,y_Wdraw,x_echo,y_echo);

fclose(fpi);
}
sprintf(string_save_load_report[idf],"Saved config_windows.txt");

return(0);
}
