int reset_and_recall_iCat_images()
{
    if (enable_iCat==1 && iCat_serveur_is_initialized==1)
    {

        nbrbytessendediCat=sendto(sockiCat, "clearmodels",sizeof("clearmodels"),0,(SOCKADDR*)&siniCat,sinsizeiCat);
        nbrbytessendediCat=sendto(sockiCat, "clearimagecache",sizeof("clearimagecache"),0,(SOCKADDR*)&siniCat,sinsizeiCat);

        char name_library[128][25];
        sprintf(name_library[0],"lfo_up_off.jpg");
        sprintf(name_library[1],"lfo_up_on.jpg");
        sprintf(name_library[2],"lfo_down_off.jpg");
        sprintf(name_library[3],"lfo_down_on.jpg");
        sprintf(name_library[4],"lfo_saw_off.jpg");
        sprintf(name_library[5],"lfo_saw_on.jpg");
        sprintf(name_library[6],"lfo_prev_off.jpg");
        sprintf(name_library[7],"lfo_prev_on.jpg");
        sprintf(name_library[8],"lfo_next_off.jpg");
        sprintf(name_library[9],"lfo_next_on.jpg");
        sprintf(name_library[10],"lfo_ar_off.jpg");
        sprintf(name_library[11],"lfo_ar_on.jpg");
        sprintf(name_library[12],"lock_off.jpg");
        sprintf(name_library[13],"lock_on.jpg");
        sprintf(name_library[14],"lfo_flash_off.jpg");
        sprintf(name_library[15],"lfo_flash_on.jpg");
        sprintf(name_library[16],"play_off.jpg");
        sprintf(name_library[17],"play_on.jpg");
        sprintf(name_library[18],"loop_off.jpg");
        sprintf(name_library[19],"loop_on.jpg");
        sprintf(name_library[20],"loopall_off.jpg");
        sprintf(name_library[21],"loopall_on.jpg");
        sprintf(name_library[22],"seek_off.jpg");

        sprintf(name_library[23],"autogo_view.jpg");
        sprintf(name_library[24],"bt_dockminus.jpg");
        sprintf(name_library[25],"bt_dockplus.jpg");
        sprintf(name_library[26],"at_zero.jpg");
        sprintf(name_library[27],"mf_setpos.jpg");
        sprintf(name_library[28],"bt_carre_vide.png");
        sprintf(name_library[29],"mf_bt_carre_vide.png");
        sprintf(name_library[30],"mf_lfo_up_off.jpg");
        sprintf(name_library[31],"mf_lfo_up_on.jpg");
        sprintf(name_library[32],"mf_lfo_down_off.jpg");
        sprintf(name_library[33],"mf_lfo_down_on.jpg");
        sprintf(name_library[34],"mf_lfo_saw_off.jpg");
        sprintf(name_library[35],"mf_lfo_saw_on.jpg");
        sprintf(name_library[36],"mf_lfo_prev_off.jpg");
        sprintf(name_library[37],"mf_lfo_prev_on.jpg");
        sprintf(name_library[38],"mf_lfo_next_off.jpg");
        sprintf(name_library[39],"mf_lfo_next_on.jpg");
        sprintf(name_library[40],"mf_lfo_ar_off.jpg");
        sprintf(name_library[41],"mf_lfo_ar_on.jpg");
        sprintf(name_library[42],"mf_lock_off.jpg");
        sprintf(name_library[43],"mf_lock_on.jpg");
        sprintf(name_library[44],"mf_lfo_flash_off.jpg");
        sprintf(name_library[45],"mf_lfo_flash_on.jpg");
        sprintf(name_library[46],"mf_play_off.jpg");
        sprintf(name_library[47],"mf_play_on.jpg");
        sprintf(name_library[48],"mf_loop_off.jpg");
        sprintf(name_library[49],"mf_loop_on.jpg");
        sprintf(name_library[50],"mf_loopall_off.jpg");
        sprintf(name_library[51],"mf_loopall_on.jpg");
        sprintf(name_library[52],"mf_seek_off.jpg");
        sprintf(name_library[53],"mf_lck_pst.png");
        sprintf(name_library[54],"mf_sel_pst.png");


        sprintf(name_library[55],"button.jpg");
        sprintf(name_library[56],"jump_off.jpg");

        sprintf(name_library[57],"go_off.jpg");
        sprintf(name_library[58],"go_on.jpg");
        sprintf(name_library[59],"goback_off.jpg");
        sprintf(name_library[60],"goback_on.jpg");
        sprintf(name_library[61],"go_on.jpg");


        sprintf(name_library[62],"bt_iCat.png");
        sprintf(name_library[63],"rond_off.jpg");
        sprintf(name_library[64],"rond_on.jpg");
        sprintf(name_library[65],"rond_banger_off.png");
        sprintf(name_library[66],"rond_banger_on.png");

        sprintf(name_library[67],"draw_point.jpg");
        sprintf(name_library[68],"draw_line.jpg");
        sprintf(name_library[69],"draw_cross.jpg");
        sprintf(name_library[70],"draw_cross_ex.jpg");
        sprintf(name_library[71],"draw_trian_plain.jpg");
        sprintf(name_library[72],"draw_trian_outl.jpg");
        sprintf(name_library[73],"draw_circle_plain.jpg");
        sprintf(name_library[74],"draw_circle_outl.jpg");
        sprintf(name_library[75],"draw_square_plain.jpg");
        sprintf(name_library[76],"draw_square_outl.jpg");
        sprintf(name_library[77],"draw_rect_plain.jpg");
        sprintf(name_library[78],"draw_rect_outl.jpg");
        sprintf(name_library[79],"draw_mode_draw.jpg");
        sprintf(name_library[80],"draw_mode_erase.jpg");
        sprintf(name_library[81],"draw_mode_solo.jpg");
        sprintf(name_library[82],"draw_mode_ghost.jpg");

        sprintf(name_library[83],"draw_preset_selected.png");
        sprintf(name_library[84],"draw_preset_vide.png");

        sprintf(name_library[85],"finished");

        for(int loopi=0; loopi<85; loopi++)
        {
            sprintf(StrOrderToiCat,"model button%d image http://www.le-chat-noir-numerique.fr/iCat/%s",loopi,name_library[loopi]);
            nbrbytessendediCat=sendto(sockiCat, StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        }

        sprintf(StrOrderToiCat,"model slider0d image http://www.le-chat-noir-numerique.fr/iCat/slider.jpg");
        nbrbytessendediCat=sendto(sockiCat, StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        //fin confition enbabled and initiated

        nbrbytessendediCat=sendto(sockiCat, "opengl 1",sizeof("opengl 0"),0,(SOCKADDR*)&siniCat,sinsizeiCat);
        nbrbytessendediCat=sendto(sockiCat, "opengl 1",sizeof("opengl 1"),0,(SOCKADDR*)&siniCat,sinsizeiCat);

    }
    return(0);
}
