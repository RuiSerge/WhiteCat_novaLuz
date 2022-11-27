int Menus( int xmenu, int ymenu)
{
Rect MyMainMenu(Vec2D(xmenu,ymenu),Vec2D(size_x_mainmenu,size_y_mainmenu));
MyMainMenu.SetRoundness(15);
MyMainMenu.Draw(CouleurFond);
MyMainMenu.SetLineWidth(5);
if(window_focus_id==W_MAINMENU)
{
MyMainMenu.DrawOutline(CouleurFader);
}
else {MyMainMenu.DrawOutline(CouleurLigne); }
neuro.Print("MENUS",xmenu+100,ymenu+30);


Rect Autoclose( Vec2D( xmenu+330,ymenu+8), Vec2D ( 30,15));
Autoclose.SetRoundness(5);
Autoclose.Draw(CouleurBlind.WithAlpha(index_text_auto_close));
Autoclose.DrawOutline(CouleurLigne);
petitchiffre.Print("Text",xmenu+295, ymenu+20);
petitchiffre.Print("AutoClose",xmenu+295, ymenu+34);
petitchiffre.Print("XX",xmenu+337, ymenu+20);




int IDmidi=0;
char nom_commande[24];
char raccourci_commande[24];
bool stae=0;




for(int cl=0;cl<5;cl++)
{
switch(cl)
{
case 0://sequenciel window
IDmidi=751;
sprintf(nom_commande,"CUELIST");
sprintf(raccourci_commande,"F9");
stae=index_window_sequentiel;
break;
case 1://time
IDmidi=748;
sprintf(nom_commande,"TIME");
sprintf(raccourci_commande,"F6");
stae=index_time;
break;
case 2://banger
IDmidi=753;
sprintf(nom_commande,"BANGER");
sprintf(raccourci_commande,"F11");
stae=index_show_banger_window;
break;
case 3://wizard
IDmidi=1329;
strcpy(nom_commande,"WIZARD");
strcpy(raccourci_commande,"");
stae= index_show_wizard_window;
break;
case 4://save
IDmidi=1330;
strcpy(nom_commande,"SAVE");
strcpy(raccourci_commande,"");
stae=index_menu_save;
break;
default:
break;
}
command_button_view(xmenu+10,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi);// int x, inty ,bool state, char *textedesc, int midiaffectation
}

for(int cl=0;cl<6;cl++)
{
switch(cl)
{
case 0:
IDmidi=1331;
sprintf(nom_commande,"PATCH");
sprintf(raccourci_commande,"Shift-P");
stae=index_patch_window;
break;
case 1:
IDmidi=1332;
strcpy(nom_commande,"LIST");
strcpy(raccourci_commande,"");
stae=index_list_projecteurs;
break;
case 2:
IDmidi=1594;
strcpy(nom_commande,"LIGHT PLOT");
strcpy(raccourci_commande,"");
stae=index_plot_window;
break;
case 3:
IDmidi=1335;
strcpy(nom_commande,"Freeze");
strcpy(raccourci_commande,"");
stae=index_do_freeze;
break;
case 4:
IDmidi=1541;
strcpy(nom_commande,"Exclude");
strcpy(raccourci_commande,"");
stae=index_do_exclude;
break;
case 5://my window
IDmidi=2047; //a re définir voir tableau affectations midi
strcpy(nom_commande,"MY WINDOW");
strcpy(raccourci_commande,"");
stae= index_my_window;
break;
default:
break;
}
command_button_view(xmenu+80,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi);// int x, inty ,bool state, char *textedesc, int midiaffectation
}


for(int cl=0;cl<6;cl++)
{
switch(cl)
{
case 0:
IDmidi=752;
sprintf(nom_commande,"FADERS");
sprintf(raccourci_commande,"F10");
stae=index_show_faders;
break;
case 1:
IDmidi=1336;
sprintf(nom_commande,"MiniFaders");
sprintf(raccourci_commande,"Shift-F10");
stae=index_show_minifaders;
break;
case 2:
IDmidi=749;
sprintf(nom_commande,"Trichromy");
sprintf(raccourci_commande,"F7");
stae=index_trichro_window;
break;
case 3:
IDmidi=1337;
sprintf(nom_commande,"CHASERS");
sprintf(raccourci_commande,"Shift-C");
stae=index_window_chasers;
break;
case 4:
IDmidi=1340;
strcpy(nom_commande,"GRID PL.");
strcpy(raccourci_commande,"");
stae=index_grider_window;
break;
case 5:
IDmidi=1829;
strcpy(nom_commande,"WAVE");
strcpy(raccourci_commande,"");
stae=index_wave_menu_window;
break;
default:
break;
}
command_button_view(xmenu+150,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi);// int x, inty ,bool state, char *textedesc, int midiaffectation
}


for(int cl=0;cl<6;cl++)
{
switch(cl)
{
case 0:
IDmidi=750;
sprintf(nom_commande,"Track.Vid.");
sprintf(raccourci_commande,"F8");
stae=index_video_window;
break;
case 1:
IDmidi=1339;
strcpy(nom_commande,"Mover");
strcpy(raccourci_commande,"");
stae=index_show_mover_window;
break;
case 2:
IDmidi=1662;
strcpy(nom_commande,"ECHO");
strcpy(raccourci_commande,"");
stae=index_show_echo_window;
break;
case 3:
IDmidi=756;
sprintf(nom_commande,"AUDIO PL.");
sprintf(raccourci_commande,"Ctrl-A");
stae=index_show_audio_window;
break;
case 4:
IDmidi=747;
sprintf(nom_commande,"NAME");
sprintf(raccourci_commande,"F5");
stae=index_type;
break;
case 5:
IDmidi=1659;
strcpy(nom_commande,"DRAW");
strcpy(raccourci_commande,"");
stae=index_draw_window;
break;
default:
break;
}
command_button_view(xmenu+220,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi);// int x, inty ,bool state, char *textedesc, int midiaffectation
}

for(int cl=0;cl<5;cl++)
{
switch(cl)
{
case 0:
IDmidi=755;
sprintf(nom_commande,"CFG-Menu");
sprintf(raccourci_commande,"Shift-F11");
stae=index_show_config_window;
break;

case 1:
IDmidi=1341;
strcpy(nom_commande,"iCat Builder");
strcpy(raccourci_commande,"");
stae=index_window_gui_iCat;
break;
case 2:
IDmidi=1338;
sprintf(nom_commande,"N-Pad");
sprintf(raccourci_commande,"P");
stae=index_visual_pad;
break;
case 3:
IDmidi=1342;
strcpy(nom_commande,"Help");
strcpy(raccourci_commande,"");
stae=index_call_help;
break;
case 4:
IDmidi=757;
sprintf(nom_commande,"QUIT");
sprintf(raccourci_commande,"Ctrl-F12");
stae=index_do_quit_with_save;
break;
default:
break;
}
command_button_view(xmenu+290,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi);// int x, inty ,bool state, char *textedesc, int midiaffectation
}

return(0);
}
