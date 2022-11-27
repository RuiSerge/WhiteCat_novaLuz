int clear_iCat_buttons( int preset_page_iCat)
{

    iCat_nbre_de_boutons[preset_page_iCat]=0;
    for(int nbl=0; nbl<max_buttons_icat; nbl++)
    {
        iCat_pos_bouton[preset_page_iCat][nbl][0]=0;
        iCat_pos_bouton[preset_page_iCat][nbl][1]=0;
        iCat_affectation_bouton_type_is[preset_page_iCat][nbl]=0;//type 1 faders, 2 sequentiel, 3 audio family
        iCat_affectation_bouton_action_is[preset_page_iCat][nbl]=0;//sous famille, les actions
        iCat_affectation_bouton_value_is[preset_page_iCat][nbl]=0;//valeur de la famille 1/48 stage/preset/accel
        ratio_iCat_button[preset_page_iCat][nbl]=2;//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }
    iCat_select_editing_button=0;
    return(0);
}
