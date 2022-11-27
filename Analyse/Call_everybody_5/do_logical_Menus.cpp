int do_logical_Menus( int xmenu, int ymenu)
{
    if(window_focus_id==W_MAINMENU)
    {
        if(mouse_x> xmenu+330 && mouse_x< xmenu+360 && mouse_y>ymenu+8  && mouse_y<ymenu+23 && mouse_button==1 && mouse_released==0)
        {
            index_text_auto_close=toggle(index_text_auto_close);
            mouse_released=1;
        }


        int IDmidi=0;
        int IDcommand=0;
        char nom_commande[24];
        char raccourci_commande[24];
        bool stae=0;
        for(int cl=0; cl<5; cl++)
        {
            switch(cl)
            {
            case 0://sequenciel window
                IDmidi=751;
                IDcommand=cl;
                sprintf(nom_commande,"CueList");
                sprintf(raccourci_commande,"F9");
                stae=index_window_sequentiel;
                break;
            case 1://time
                IDmidi=748;
                IDcommand=cl;
                sprintf(nom_commande,"Time");
                sprintf(raccourci_commande,"F6");
                stae=index_time;
                break;
            case 2://banger
                IDmidi=753;
                IDcommand=cl;
                sprintf(nom_commande,"Banger");
                sprintf(raccourci_commande,"F11");
                stae=index_show_banger_window;
                break;
            case 3://wizard
                IDmidi=1329;
                IDcommand=cl;
                sprintf(nom_commande,"Wizard");
                sprintf(raccourci_commande,"-");
                stae= index_show_wizard_window;
                break;
            case 4://save
                IDmidi=1330;
                IDcommand=cl;
                strcpy(nom_commande,"Save");
                strcpy(raccourci_commande,"");
                stae=index_menu_save;
                break;
            default:
                break;
            }
            command_button_logical(xmenu+10,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi,IDcommand);// int x, inty ,bool state, char *textedesc, int midiaffectation
        }



        for(int cl=0; cl<6; cl++)
        {
            switch(cl)
            {
            case 0:
                IDmidi=1331;
                IDcommand=cl+10;
                sprintf(nom_commande,"Patch");
                sprintf(raccourci_commande,"Shift-P");
                stae=index_patch_window;
                break;
            case 1:
                IDmidi=1332;
                IDcommand=cl+10;
                strcpy(nom_commande,"List");
                strcpy(raccourci_commande,"");
                stae=index_list_projecteurs;
                break;
            case 2:
                IDmidi=1594;
                IDcommand=cl+10;
                strcpy(nom_commande,"Light Plot");
                strcpy(raccourci_commande,"");
                stae=index_plot_window;
                break;
            case 3:
                IDmidi=1335;
                IDcommand=cl+10;
                strcpy(nom_commande,"Freeze");
                strcpy(raccourci_commande,"");
                stae=index_do_freeze;
                break;
            case 4:
                IDmidi=1541;
                IDcommand=cl+10;
                strcpy(nom_commande,"Exclude");
                strcpy(raccourci_commande,"");
                stae=index_do_exclude;
                break;
            case 5://my window
                IDmidi=2047; // c est la derniere commande midi, a changer et  définir voir tableau affectations midi
                IDcommand=cl+10;
                strcpy(nom_commande,"MY WINDOW");
                strcpy(raccourci_commande,"");
                stae= index_my_window;
                break;
            default:
                break;
            }
            command_button_logical(xmenu+80,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi,IDcommand);// int x, inty ,bool state, char *textedesc, int midiaffectation
        }


        for(int cl=0; cl<6; cl++)
        {
            switch(cl)
            {
            case 0:
                IDmidi=752;
                IDcommand=cl+20;
                sprintf(nom_commande,"Faders");
                sprintf(raccourci_commande,"F10");
                stae=index_show_faders;
                break;
            case 1:
                IDmidi=1336;
                IDcommand=cl+20;
                sprintf(nom_commande,"MiniFaders");
                sprintf(raccourci_commande,"Shift-F10");
                stae=index_show_minifaders;
                break;
            case 2:
                IDmidi=749;
                IDcommand=cl+20;
                sprintf(nom_commande,"Trichromy");
                sprintf(raccourci_commande,"F7");
                stae=index_trichro_window;
                break;
            case 3:
                IDmidi=1337;
                IDcommand=cl+20;
                sprintf(nom_commande,"Chasers");
                sprintf(raccourci_commande,"Shift-C");
                stae=index_window_chasers;
                break;
            case 4:
                IDmidi=1340;
                IDcommand=cl+20;
                strcpy(nom_commande,"GridPl.");
                strcpy(raccourci_commande,"");
                stae=index_grider_window;
                break;
            case 5:
                IDmidi=1829;
                IDcommand=cl+20;
                strcpy(nom_commande,"WAVE");
                strcpy(raccourci_commande,"");
                stae=index_wave_menu_window;
                break;
            default:
                break;
            }
            command_button_logical(xmenu+150,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi,IDcommand);// int x, inty ,bool state, char *textedesc, int midiaffectation
        }



        for(int cl=0; cl<6; cl++)
        {
            switch(cl)
            {
            case 0:
                IDmidi=750;
                IDcommand=cl+30;
                sprintf(nom_commande,"Track.Vid.");
                sprintf(raccourci_commande,"F8");
                stae=index_video_window;
                break;
            case 1:
                IDmidi=1339;
                IDcommand=cl+30;
                strcpy(nom_commande,"Mover");
                strcpy(raccourci_commande,"");
                stae=index_show_mover_window;
                break;
            case 2:
                IDmidi=1662;
                IDcommand=cl+30;
                strcpy(nom_commande,"ECHO");
                strcpy(raccourci_commande,"");
                stae=index_show_echo_window;
                break;
            case 3:
                IDmidi=756;
                IDcommand=cl+30;
                sprintf(nom_commande,"AudioPl.");
                sprintf(raccourci_commande,"Ctrl-A");
                stae=index_show_audio_window;
                break;
            case 4:
                IDmidi=747;
                IDcommand=cl+30;
                sprintf(nom_commande,"Name");
                sprintf(raccourci_commande,"F5");
                stae=index_type;
                break;
            case 5:
                IDmidi=1659;
                IDcommand=cl+30;
                strcpy(nom_commande,"Draw");
                strcpy(raccourci_commande,"");
                break;
            default:
                break;
            }
            command_button_logical(xmenu+220,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi,IDcommand);// int x, inty ,bool state, char *textedesc, int midiaffectation
        }



        for(int cl=0; cl<5; cl++)
        {
            switch(cl)
            {
            case 0:
                IDmidi=755;
                IDcommand=cl+40;
                sprintf(nom_commande,"CFG-Menu");
                sprintf(raccourci_commande,"Shift-F11");
                stae=index_show_config_window;
                break;
            case 1:
                IDmidi=1341;
                IDcommand=cl+40;
                strcpy(nom_commande,"iCat Builder");
                strcpy(raccourci_commande,"");
                stae=index_window_gui_iCat;
                break;
            case 2:
                IDmidi=1338;
                IDcommand=cl+40;
                sprintf(nom_commande,"N-Pad");
                sprintf(raccourci_commande,"P");
                stae=index_visual_pad;
                break;
            case 3:
                IDmidi=1342;
                IDcommand=cl+40;
                strcpy(nom_commande,"Help");
                strcpy(raccourci_commande,"");
                stae=index_call_help;
                break;
            case 4:
                IDmidi=757;
                IDcommand=cl+40;
                sprintf(nom_commande,"QUIT");
                sprintf(raccourci_commande,"CTRL-F12");
                stae=index_do_quit_with_save;
                break;
            default:
                break;
            }
            command_button_logical(xmenu+290,ymenu+50+(cl*25),stae,nom_commande,raccourci_commande,IDmidi,IDcommand);// int x, inty ,bool state, char *textedesc, int midiaffectation
        }
    }
    return(0);
}
