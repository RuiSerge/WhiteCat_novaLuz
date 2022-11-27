int do_refresh_iCat(int iCatPage)
{
    finished_to_send_orders_to_iCat=0;
    index_false_shift=0;
    index_false_control=0;//pour éviter les pbs lors des changements de pages avec une commande shift toujours active



    recalculate_iCatBuilder_window_size();




    for(int u=0; u<nbre_d_envois_de_l_info; u++)
    {

        nbrbytessendediCat=sendto(sockiCat,  "opengl 1",sizeof("opengl 1"),0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(StrOrderToiCat,"orientation %d",iCat_preset_orientation[iCatPageis]);
        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

        for(int sl=1; sl<iCat_nbre_de_sliders[iCatPageis]+1; sl++)
        {
            To_iCat_DrawSlider(sl,iCat_pos_slider[iCatPageis][sl][0],iCat_pos_slider[iCatPageis][sl][1],
                               iCat_affectation_slider_type_is[iCatPageis][sl],iCat_affectation_slider_value_is[iCatPageis][sl]);

        }
        for(int bl=1; bl<iCat_nbre_de_boutons[iCatPageis]+1; bl++)
        {
            To_iCat_DrawButton(bl,iCat_pos_bouton[iCatPageis][bl][0],iCat_pos_bouton[iCatPageis][bl][1],
                               iCat_affectation_bouton_type_is[iCatPageis][bl], iCat_affectation_bouton_action_is[iCatPageis][bl],iCat_affectation_bouton_value_is[iCatPageis][bl]);
        }
        for(int bl=1; bl<iCat_nbre_de_strings[iCatPageis]+1; bl++)
        {
            To_iCat_DrawString(bl,iCat_pos_string[iCatPageis][bl][0],iCat_pos_string[iCatPageis][bl][1],
                               iCat_affectation_string_type_is[iCatPageis][bl], iCat_affectation_string_action_is[iCatPageis][bl]);
        }
        for(int bl=1; bl<iCat_nbre_de_tracking_zone[iCatPageis]+1; bl++)
        {
            To_iCat_DrawTrackingZone(bl,iCat_pos_trackzone[iCatPageis][bl][0],iCat_pos_trackzone[iCatPageis][bl][1],
                                     pos_iCat_tracker[iCatPageis][bl][0], pos_iCat_tracker[iCatPageis][bl][1] );
        }

    }

    index_refresh_valeurs_continous=1;
    refresh_continuously_iCat_sliders();//MAJ niveaux
    refresh_continuously_iCat_buttons();
    index_refresh_valeursTRCK_continous=1;
    refresh_continuously_iCat_trackerzones();
    someone_changed_in_sequences=1;//icat
    someone_changed_in_time_sequences=1;
    Fantastick_check_string();
    index_refresh_valeursTRCK_continous=0;
    index_refresh_valeurs_continous=0;
    finished_to_send_orders_to_iCat=1;

    return(0);
}
