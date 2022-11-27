int load_iCat_page ( int preset_page_iCat)
{

    iCatPageis=preset_page_iCat;
    recalculate_iCatBuilder_window_size();
    if(iCat_select_editing_slider>iCat_nbre_de_sliders[preset_page_iCat])
    {
        iCat_select_editing_slider=iCat_nbre_de_sliders[preset_page_iCat];
        if(iCat_select_editing_slider>max_sliders_icat)
        {
            iCat_select_editing_slider=0;
        }
    }
    if(iCat_select_editing_button>iCat_nbre_de_boutons[preset_page_iCat])
    {
        iCat_select_editing_button=iCat_nbre_de_boutons[preset_page_iCat];
        if(iCat_select_editing_button>max_buttons_icat)
        {
            iCat_select_editing_button=0;
        }
    }
    if(iCat_select_editing_string>iCat_nbre_de_strings[preset_page_iCat])
    {
        iCat_select_editing_string=iCat_nbre_de_strings[preset_page_iCat];
        if(iCat_select_editing_string>max_string_icat)
        {
            iCat_select_editing_string=0;
        }
    }
    if(iCat_select_tracking_zone>iCat_nbre_de_tracking_zone[preset_page_iCat])
    {
        iCat_select_tracking_zone=iCat_nbre_de_tracking_zone[preset_page_iCat];
        if(iCat_select_tracking_zone>max_zones_icat)
        {
            iCat_select_tracking_zone=0;
        }
    }
    nbrbytessendediCat=sendto(sockiCat, "clearmodels",sizeof("clearmodels"),0,(SOCKADDR*)&siniCat,sinsizeiCat); //dans routine laod avant appel du rafraichissement

    sprintf(string_Last_Order,"Loaded iCat page %d",preset_page_iCat+1);


    return(0);
}
