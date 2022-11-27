int copy_iCatPage(int pagesource, int pagedest)
{
    iCat_preset_orientation[pagedest]=iCat_preset_orientation[pagesource];

    iCat_nbre_de_sliders[pagedest]=iCat_nbre_de_sliders[pagesource];
    for(int i=0; i<24; i++)
    {
        iCat_pos_slider[pagedest][i][0]=iCat_pos_slider[pagesource][i][0];
        iCat_pos_slider[pagedest][i][1]=iCat_pos_slider[pagesource][i][1];
        iCat_orientation_slider[pagedest][i]=iCat_orientation_slider[pagesource][i];
        iCat_affectation_slider_type_is[pagedest][i]=iCat_affectation_slider_type_is[pagesource][i];
        iCat_affectation_slider_value_is[pagedest][i]=iCat_affectation_slider_value_is[pagesource][i];
        ratio_iCat_slider[pagedest][i]=ratio_iCat_slider[pagesource][i];
    }

    iCat_nbre_de_boutons[pagedest]=iCat_nbre_de_boutons[pagesource];
    for(int nbl=0; nbl<48; nbl++)
    {
        iCat_pos_bouton[pagedest][nbl][0]=iCat_pos_bouton[pagesource][nbl][0];
        iCat_pos_bouton[pagedest][nbl][1]=iCat_pos_bouton[pagesource][nbl][1];
        iCat_affectation_bouton_type_is[pagedest][nbl]=iCat_affectation_bouton_type_is[pagesource][nbl];
        iCat_affectation_bouton_action_is[pagedest][nbl]=iCat_affectation_bouton_action_is[pagesource][nbl];
        iCat_affectation_bouton_value_is[pagedest][nbl]=iCat_affectation_bouton_value_is[pagesource][nbl];
        ratio_iCat_button[pagedest][nbl]=ratio_iCat_button[pagesource][nbl];//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }


    iCat_nbre_de_strings[pagedest]=iCat_nbre_de_strings[pagesource];
    for(int nbl=0; nbl<24; nbl++)
    {
        iCat_pos_string[pagedest][nbl][0]=iCat_pos_string[pagesource][nbl][0];
        iCat_pos_string[pagedest][nbl][1]=iCat_pos_string[pagesource][nbl][1];
        iCat_affectation_string_type_is[pagedest][nbl]=iCat_affectation_string_type_is[pagesource][nbl];
        iCat_affectation_string_action_is[pagedest][nbl]=iCat_affectation_string_action_is[pagesource][nbl];
        ratio_iCat_string[pagedest][nbl]=ratio_iCat_string[pagesource][nbl];//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }

    iCat_nbre_de_tracking_zone[pagedest]=iCat_nbre_de_tracking_zone[pagesource];
    for(int nbl=0; nbl<4; nbl++)
    {
        iCat_pos_trackzone[pagedest][nbl][0]=iCat_pos_trackzone[pagesource][nbl][0];
        iCat_pos_trackzone[pagedest][nbl][1]=iCat_pos_trackzone[pagesource][nbl][1];
        iCat_trackzone_type_is[pagedest][nbl]=iCat_trackzone_type_is[pagesource][nbl];
        iCat_trackzone_type_is[pagedest][nbl]=iCat_trackzone_type_is[pagesource][nbl];
        iCat_trackzone_affectation_is[pagedest][nbl]=iCat_trackzone_affectation_is[pagesource][nbl];
        iCat_trackzone_affectation_is[pagedest][nbl]=iCat_trackzone_affectation_is[pagesource][nbl];
        iCat_affectation_string_action_is[pagedest][nbl]=iCat_affectation_string_action_is[pagesource][nbl];
        ratio_iCat_trackzone[pagedest][nbl]=ratio_iCat_trackzone[pagesource][nbl];//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }



    iCat_select_editing_button=0;
    iCat_select_editing_slider=0;
    iCat_select_editing_string=0;
    iCat_select_tracking_zone=0;

    sprintf(string_Last_Order,"Copied iCat page %d in page %d",pagesource+1, pagedest+1);
    index_icat_copyPage=0;

    return(0);
}
