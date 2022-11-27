int draw_pdf_echo_config()
{
    for(int pr=0; pr<24; pr++)
    {

        HPDF_Page_SetRGBStroke (page, 0.0, 0.4, 0.9);//couleur ligne
        HPDF_Page_BeginText (page);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_EndText (page);
        strcpy(header_export,"");


        sprintf(header_export,"Echo Preset: %d",pr +1);
        draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

        sprintf(header_export,"Pointing Fader: %d",echo_pointing_fader_num[pr] );
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        verification_fin_de_page();

        switch(echo_is_echo_mode[pr])
        {
        case 0:
            sprintf(header_export,"Echo Mode is /OFF ");
            break;
        case 1:
            sprintf(header_export,"Echo Mode is /ON ");
            break;
        default:
            break;
        }
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        verification_fin_de_page();


        switch(echo_channel_manipulate_mode[pr])
        {
        case 0:
            sprintf(header_export,"ChanMode is CH/LEVEL");
            break;
        case 1:
            sprintf(header_export,"ChanMode is CH/GROUND");
            break;
        default:
            break;
        }
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        verification_fin_de_page();

        sprintf(header_export,"Channel position is: %d ",echo_grid_channel_position[pr]+1 );
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        verification_fin_de_page();

        sprintf(header_export,"Gravity: %.2f     Mass: %.2f     Energy:%.2f ",
                echo_global_params[pr][0],echo_global_params[pr][1],echo_global_params[pr][2] );
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        cmptline_pdf++;
        verification_fin_de_page();



    }
    return(0);
}
