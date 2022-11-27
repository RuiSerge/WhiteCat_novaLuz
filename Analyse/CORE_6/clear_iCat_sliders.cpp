int clear_iCat_sliders( int preset_page_iCat)
{
    iCat_nbre_de_sliders[preset_page_iCat]=0;
    for(int i=0; i<max_sliders_icat; i++)
    {
        iCat_pos_slider[preset_page_iCat][i][0]=0;
        iCat_pos_slider[preset_page_iCat][i][1]=0;
        iCat_orientation_slider[preset_page_iCat][i]=0;
        iCat_affectation_slider_type_is[preset_page_iCat][i]=0;
        iCat_affectation_slider_value_is[preset_page_iCat][i]=0;
        ratio_iCat_slider[preset_page_iCat][i]=2;
        slider_is_touched[preset_page_iCat][i]=0;
        before_slider_is_touched[preset_page_iCat][i]=0;
        slider_is_controlled_by_point[preset_page_iCat][i]=0;
        level_from_touch[preset_page_iCat][i]=0;
    }
    iCat_select_editing_slider=0;
    return(0);
}
