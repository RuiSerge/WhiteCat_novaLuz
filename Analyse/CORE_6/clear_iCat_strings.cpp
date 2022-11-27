int clear_iCat_strings( int preset_page_iCat)
{
    iCat_nbre_de_strings[preset_page_iCat]=0;
    for(int nbl=0; nbl<max_string_icat; nbl++)
    {
        iCat_pos_string[preset_page_iCat][nbl][0]=0;
        iCat_pos_string[preset_page_iCat][nbl][1]=0;
        iCat_affectation_string_type_is[preset_page_iCat][nbl]=0;//type 1 faders, 2 sequentiel, 3 audio family
        iCat_affectation_string_action_is[preset_page_iCat][nbl]=0;//sous famille, les actions
        ratio_iCat_string[preset_page_iCat][nbl]=2;//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }
    iCat_select_editing_string=0;
    return(0);
}
