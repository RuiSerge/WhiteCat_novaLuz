int clear_iCat_trackingzone(int preset_page_iCat)
{
    iCat_nbre_de_tracking_zone[preset_page_iCat]=0;
    for(int nbl=0; nbl<max_zones_icat; nbl++)
    {
        iCat_pos_trackzone[preset_page_iCat][nbl][0]=0;
        iCat_pos_trackzone[preset_page_iCat][nbl][1]=0;
        iCat_trackzone_type_is[preset_page_iCat][nbl]=0;
        iCat_trackzone_affectation_is[preset_page_iCat][nbl]=0;
        iCat_affectation_string_action_is[preset_page_iCat][nbl]=0;
        ratio_iCat_trackzone[preset_page_iCat][nbl]=0;//multiplicateur des proportions de s boutons. 1 / 2 / 3
    }

    iCat_select_tracking_zone=0;

    return(0);
}
