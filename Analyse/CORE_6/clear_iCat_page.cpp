int clear_iCat_page ( int preset_page_iCat)
{
    clear_iCat_sliders( preset_page_iCat);
    clear_iCat_buttons( preset_page_iCat);
    clear_iCat_strings( preset_page_iCat);
    clear_iCat_trackingzone( preset_page_iCat);



    sprintf(string_Last_Order,"Cleared iCat page %d",preset_page_iCat+1);
    do_send_icat_init_page=1;
    return(0);
}
