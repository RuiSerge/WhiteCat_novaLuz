int To_iCat_DrawButton(int id, int x1,int y1, int affectation, int action, int valeur_b)
{
    char string_temp_familly[25];
    char string_temp_id[25];
    char string_mf_id[25];
    int decalagex=0;
    int decalagey=0;
    switch(iCat_affectation_bouton_type_is[iCatPageis][id])
    {
    case 0://desafected
        sprintf(string_temp_familly,"-");
        break;
    case 1: //faders
        sprintf(string_temp_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 0://desafected
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/button.jpg",id);
            break;
        case 1: //fader up
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_up_off.jpg",id);
            break;
        case 2://fader down
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_down_off.jpg",id);
            break;
        case 3://Fader saw
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_saw_off.jpg",id);
            break;
        case 4://prev dock
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_prev_off.jpg",id);
            break;
        case 5://next dock
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_next_off.jpg",id);
            break;
        case 6://aller retour
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_ar_off.jpg",id);
            break;
        case 7://lock
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lock_off.jpg",id);
            break;
        case 8://flash
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/lfo_flash_off.jpg",id);
            break;

        case 9://loop a dock
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_off.jpg",id);
            break;
        case 10://loop all dock
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loopall_off.jpg",id);
            break;
        case 11://play embeded chaser
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/play_off.jpg",id);
            break;
        case 12://seek embeded chaser
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/seek_off.jpg",id);
            break;
        case 13://loop embeded chaser
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/loop_off.jpg",id);
            break;
        default:
            break;
        }
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat,"model tBut%d text %s",id,string_temp_id);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d position %d %d 0",id,(x1*2)+(2*ratio_iCat_button[iCatPageis][id]), (y1*2)+(ratio_iCat_button[iCatPageis][id]*(largueur_bouton)));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d font %s",id,iphone_fonts[5]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d fontsize %d",id, 10*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        break;
    //fin faders

    case 2://minifaders
        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 0://desafected
            break;
        case 1: //fader up
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_up_off.jpg",id);
            break;
        case 2://fader down
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_down_off.jpg",id);
            break;
        case 3://Fader saw
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_saw_off.jpg",id);
            break;
        case 4://"ToPREVDoid");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_prev_off.jpg",id);
            break;
        case 5://"ToNEXTDoid");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_next_off.jpg",id);
            break;
        case 6://"Up/Down");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_ar_off.jpg",id);
            break;
        case 7://"LOCK");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lock_off.jpg",id);
            break;
        case 8://"FLASH");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lfo_flash_off.jpg",id);
            break;
        case 9://"L/Unloop doid");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_loop_off.jpg",id);
            break;
        case 10://"L/Unloop all");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_loopall_off.jpg",id);
            break;
        case 11://"Dock -");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_bt_dockminus.jpg",id);
            break;
        case 12://"Dock +");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_bt_dockplus.jpg",id);
            break;
        case 13://"Play eCHASER");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_play_off.jpg",id);
            break;
        case 14://all at 0
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/at_zero.jpg",id);
            break;
        case 15://Set pos
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_setpos.jpg",id);
            break;
        case 16://"Select M.Fader");
            sprintf(string_mf_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
            sprintf(StrOrderToiCat,"model MFnum%d text %s",id,string_mf_id);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2)-10, (y1*2)+((ratio_iCat_button[iCatPageis][id]*(20+largueur_bouton))/2));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d fontsize %d",id, 18*ratio_iCat_button[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_bt_carre_vide.png",id);
            break;
        case 17://Unselect all
            sprintf(string_mf_id,"UnS");
            sprintf(StrOrderToiCat,"model MFnum%d text %s",id,string_mf_id);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton-20))/2), (y1*2)+10+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d fontsize %d",id, 12*ratio_iCat_button[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_bt_carre_vide.png",id);
            break;
        case 18://select all
            sprintf(string_mf_id,"ALL");
            sprintf(StrOrderToiCat,"model MFnum%d text %s",id,string_mf_id);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton-20))/2), (y1*2)+10+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d fontsize %d",id, 12*ratio_iCat_button[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_bt_carre_vide.png",id);
            break;
        case 19://"Select M.FaderPst");
            sprintf(string_temp_id,"MF.pst");
            sprintf(string_mf_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
            sprintf(StrOrderToiCat,"model MFnum%d text %s",id,string_mf_id);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2)-10, (y1*2)+((ratio_iCat_button[iCatPageis][id]*(20+largueur_bouton))/2));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d fontsize %d",id, 18*ratio_iCat_button[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_sel_pst.png",id);
            break;
        case 20://"Select Lock preset");
            sprintf(string_temp_id,"LCK.pst");
            sprintf(string_mf_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
            sprintf(StrOrderToiCat,"model MFnum%d text %s",id,string_mf_id);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2)-10, (y1*2)+((ratio_iCat_button[iCatPageis][id]*(20+largueur_bouton))/2));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model MFnum%d fontsize %d",id, 18*ratio_iCat_button[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/mf_lck_pst.png",id);
            break;

        default:
            break;
        }
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        sprintf(StrOrderToiCat, "model tBut%d position %d %d 0",id,(x1*2), (y1*2)+20+(ratio_iCat_button[iCatPageis][id]*(largueur_bouton+5)));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d font %s",id,iphone_fonts[0]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d fontsize %d",id, 10*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        break;
    case 3://sequences
        decalagey=0;
        decalagex=0;
        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 1:
            sprintf(string_temp_id,"GO");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/go_off.jpg",id);
            decalagex=7;
            decalagey=30;
            break;
        case 2:
            sprintf(string_temp_id,"Back");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/goback_off.jpg",id);
            decalagey=30;
            decalagex=5;
            break;
        case 3:
            strcpy(string_temp_id,"");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/jump_off.jpg",id);
            decalagey=30;
            decalagex=5;
            break;
        case 4:
            sprintf(string_temp_id,"St-");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
            decalagex=10;
            decalagey=5;
            break;
        case 5:
            sprintf(string_temp_id,"St+");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
            decalagex=10;
            decalagey=5;
            break;
        case 6:
            sprintf(string_temp_id,"PsT -");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
            decalagex=5;
            decalagey=5;
            break;
        case 7:
            sprintf(string_temp_id,"PsT +");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
            decalagex=5;
            decalagey=5;
            break;
        case 8:
            sprintf(string_temp_id,"Goto");
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
            decalagex=5;
            decalagey=5;
            break;
        default:
            strcpy(string_temp_id,"");
            break;
        }
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        sprintf(StrOrderToiCat,"model tBut%d text %s",id,string_temp_id);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d position %d %d 0",id,(x1*2)+(  decalagex*ratio_iCat_button[iCatPageis][id]), (y1*2)+(ratio_iCat_button[iCatPageis][id]*((largueur_bouton/2)+ decalagey)));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d font %s",id,iphone_fonts[0]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model tBut%d fontsize %d",id, 10*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        break;

    case 4:
        decalagex=0;

        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 0:
            sprintf(string_mf_id,"0");
            break;
        case 1:
            sprintf(string_mf_id,"1");
            break;
        case 2:
            sprintf(string_mf_id,"2");
            break;
        case 3:
            sprintf(string_mf_id,"3");
            break;
        case 4:
            sprintf(string_mf_id,"4");
            break;
        case 5:
            sprintf(string_mf_id,"5");
            break;
        case 6:
            sprintf(string_mf_id,"6");
            break;
        case 7:
            sprintf(string_mf_id,"7");
            break;
        case 8:
            sprintf(string_mf_id,"8");
            break;
        case 9:
            sprintf(string_mf_id,"9");
            break;
        case 10:
            sprintf(string_mf_id,".");
            break;
        case 11:
            sprintf(string_mf_id,"+");
            break;
        case 12:
            sprintf(string_mf_id,"-");
            break;
        case 13:
            sprintf(string_mf_id,"ALL");
            decalagex=10;
            break;
        case 14:
            sprintf(string_mf_id,"INV");
            decalagex=10;
            break;
        case 15:
            sprintf(string_mf_id,"TAB");
            decalagex=10;
            break;
        case 16:
            sprintf(string_mf_id,"ESC");
            decalagex=10;
            break;
        case 17:
            sprintf(string_mf_id,"ENT");
            decalagex=10;
            break;
        case 18:
            sprintf(string_mf_id,"/100");
            decalagex=15;
            break;
        case 19:
            sprintf(string_mf_id,"/0");
            break;
        case 20://backspace
            sprintf(string_mf_id,"BCKS");
            decalagex=20;
            break;
        case 21://DEL
            sprintf(string_mf_id,"DEL");
            decalagex=10;
            break;
        case 22://arrow Up
            sprintf(string_mf_id,"UP");
            break;
        case 23://arrow down
            sprintf(string_mf_id,"DWN");
            decalagex=15;
            break;
        case 24://arrow left
            sprintf(string_mf_id,"LEFT");
            decalagex=15;
            break;
        case 25://arrow right
            sprintf(string_mf_id,"RGHT");
            decalagex=15;
            break;
        case 26:
            sprintf(string_mf_id,"F1");
            break;
        case 27:
            sprintf(string_mf_id,"F2");
            break;
        case 28:
            sprintf(string_mf_id,"F3");
            break;
        case 29:
            sprintf(string_mf_id,"F4");
            break;
        case 30:
            sprintf(string_mf_id,"F11");
            break;
        case 31:
            sprintf(string_mf_id,"F12");
            break;
        case 32:
            sprintf(string_mf_id,"SHFT");
            decalagex=15;
            break;
        case 33:
            sprintf(string_mf_id,"CTRL");
            decalagex=15;
            break;
        default:
            break;
        }

        sprintf(StrOrderToiCat,"model SimB%d text %s",id,string_mf_id);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton-10-decalagex))/2), (y1*2)+((10+(ratio_iCat_button[iCatPageis][id]*largueur_bouton))/2));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d font %s",id,iphone_fonts[5]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d fontsize %d",id, 10*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_carre_vide.png",id);
        break;
    case 5://banger
        decalagex=0;
        sprintf(string_mf_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
        sprintf(StrOrderToiCat,"model SimB%d text %s",id,string_mf_id);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton-15-decalagex))/2), (y1*2)+((20+(ratio_iCat_button[iCatPageis][id]*largueur_bouton))/2));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d font %s",id,iphone_fonts[5]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d fontsize %d",id, 10*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        decalagex=largueur_bouton;
        sprintf(StrOrderToiCat,"model DescB%d text %s",id,bangers_name[(iCat_affectation_bouton_value_is[iCatPageis][id]-1)]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model DescB%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton-decalagex))/2), (y1*2)+((20+(ratio_iCat_button[iCatPageis][id]*largueur_bouton))));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model DescB%d font %s",id,iphone_fonts[5]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model DescB%d fontsize %d",id, 5*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/rond_banger_off.png",id);


        break;

    case 6://icat commandes
        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 1:
            sprintf(string_mf_id,"-");
            break;
        case 2:
            sprintf(string_mf_id,"+");
            break;
        case 3:
            sprintf(string_mf_id,"%d",iCat_affectation_bouton_value_is[iCatPageis][id]);
            break;
        case 4:
            sprintf(string_mf_id,"R");
            break;
        case 5:
            sprintf(string_mf_id,"O");
            break;
        default:
            break;
        }

        sprintf(StrOrderToiCat,"model SimB%d text %s",id,string_mf_id);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d position %d %d 0",id,(x1*2)+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2), (y1*2)+15+((ratio_iCat_button[iCatPageis][id]*(largueur_bouton))/2));
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d font %s",id,iphone_fonts[5]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat, "model SimB%d fontsize %d",id, 20*ratio_iCat_button[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/bt_iCat.png",id);
        break;
    case 7://DRAW

        switch(iCat_affectation_bouton_action_is[iCatPageis][id])
        {
        case 1://"Brush Type"); selected
            switch(draw_brush_type[draw_preset_selected])
            {
            case 0:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_point.jpg",id);
                break;
            case 1:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_gpl.jpg",id);
                break;
            default:
                break;
            }
            break;
        case 2://draw_mode selected
            switch(draw_mode[draw_preset_selected])
            {
            case 0:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_draw.jpg",id);
                break;
            case 1:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_erase.jpg",id);
                break;
            case 2:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_solo.jpg",id);
                break;
            case 3:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_ghost.jpg",id);
                break;
            default:
                break;
            }
            break;
        case 3://"Brush Type"); by matrice
            switch(draw_brush_type[(iCat_affectation_bouton_value_is[iCatPageis][id]-1)])
            {
            case 0:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_point.jpg",id);
                break;
            case 1:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_gpl.jpg",id);
                break;
            default:
                break;
            }
            break;
        case 4://draw_mode by matrice
            switch(draw_mode[(iCat_affectation_bouton_value_is[iCatPageis][id])])
            {
            case 0:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_draw.jpg",id);
                break;
            case 1:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_erase.jpg",id);
                break;
            case 2:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_solo.jpg",id);
                break;
            case 3:
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_mode_ghost.jpg",id);
                break;
            default:
                break;
            }
            break;
        case 5://preset draw

            if(iCat_affectation_bouton_value_is[iCatPageis][id]-1==draw_preset_selected)
            {
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_preset_selected.png",id);
            }
            else
            {
                sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/draw_preset_vide.png",id);
            }
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat,"model TDrawPst%d text %d",id,iCat_affectation_bouton_value_is[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat, StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            sprintf(StrOrderToiCat, "model TDrawPst%d position %d %d 0",id,(x1*2)+(2*ratio_iCat_button[iCatPageis][id]), (y1*2)+(ratio_iCat_button[iCatPageis][id]*(largueur_bouton)));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model TDrawPst%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(StrOrderToiCat, "model TDrawPst%d fontsize %d",id, 18*ratio_iCat_button[iCatPageis][id]);

            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    nbrbytessendediCat=sendto(sockiCat,StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

    sprintf(StrOrderToiCat,"model button%d scale %.1f %.1f 0",id, 0.25*ratio_iCat_button[iCatPageis][id], 0.25*ratio_iCat_button[iCatPageis][id]);//0.25=128/32
    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
    sprintf(StrOrderToiCat,"model button%d position %d %d 0",id,  (x1*2)+((largueur_bouton*ratio_iCat_button[iCatPageis][id])/2), (y1*2)+((largueur_bouton*ratio_iCat_button[iCatPageis][id])/2));
    nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

    return(0);
}
