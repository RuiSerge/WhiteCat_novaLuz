int draw_pdf_draw_config()
{

    for(int pr=0; pr<6; pr++)
    {

        HPDF_Page_SetRGBStroke (page, 0.0, 0.7, 0.7);//couleur ligne
        HPDF_Page_BeginText (page);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_EndText (page);
        strcpy(header_export,"");


        sprintf(header_export,"Draw Matrix: %d",pr +1);
        draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

        sprintf(header_export,"Col: %d Row: %d",draw_preset_parameters[pr][0],draw_preset_parameters[pr][1] );
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;

        switch(draw_mode[pr])
        {
        case 0:
            sprintf(header_export,"Draw MODE: DRAW ( Additiv )");
            break;
        case 1:
            sprintf(header_export,"Draw MODE: ERASE ( Soustractiv )");
            break;
        case 2:
            sprintf(header_export,"Draw MODE: SOLO");
            break;
        case 3:
            sprintf(header_export,"Draw MODE: GHOST");
            break;
        default:
            break;
        }
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;

        switch(draw_brush_type[pr])
        {
        case 0:
            sprintf(header_export,"DOT brush selected");
            break;
        case 1:
            sprintf(header_export,"GRIDPLAYER selected");
            break;
        default:
            break;
        }
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        cmptline_pdf++;
        cmptline_pdf++;
        cmptline_pdf++;


        HPDF_Page_SetLineWidth (page, 0.25);
        HPDF_Page_SetGrayStroke (page, 0.5);
        HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage

        recalculate_draw_sizes(pr);

        HPDF_REAL larg=draw_largeur_case[pr]/1.2;
        HPDF_REAL haut=draw_hauteur_case[pr]/1.2;

        for(int lych=0; lych<=draw_preset_parameters[pr][1]; lych++ )
        {
            HPDF_Page_MoveTo (page, 100, debut_lignes -(position_ligne1+(cmptline_pdf*12))-(lych*haut));
            HPDF_Page_LineTo (page, 100+(larg*draw_preset_parameters[pr][0]), debut_lignes -(position_ligne1+(cmptline_pdf*12))-(lych*haut));
            HPDF_Page_Stroke (page);
        }
        /* verticales */
        for(int lxch=0; lxch<=draw_preset_parameters[pr][0]; lxch++ )
        {
            HPDF_Page_MoveTo (page, 100+(lxch*larg), debut_lignes -(position_ligne1+(cmptline_pdf*12)));
            HPDF_Page_LineTo (page, 100+(lxch*larg), debut_lignes -(position_ligne1+(cmptline_pdf*12)+(draw_preset_parameters[pr][1]*haut)));
            HPDF_Page_Stroke (page);
        }



        int the_ch=0;
        float val=0.0;
        HPDF_REAL xp=0;
        HPDF_REAL yp=0;

        for(int ligne=0; ligne<draw_preset_parameters[pr][1]; ligne++)
        {
            for(int col=0; col<draw_preset_parameters[pr][0]; col++)
            {
                the_ch=((ligne*draw_preset_parameters[pr][0])+col);

                if(draw_preset_levels[pr][the_ch]!=0)
                {

                    xp=100+(col*larg);
                    yp=debut_lignes -(position_ligne1+(cmptline_pdf*12))-(ligne*haut);
                    val=( draw_preset_levels[pr][the_ch]+0.2) ;//(+0.2 pour le noir);

                    HPDF_Page_SetRGBFill (page,val*0.2,val*0.7,val*0.7);//couleur remplissage
                    HPDF_Page_Rectangle  (page, xp, yp-haut, larg,haut);
                    HPDF_Page_FillStroke (page);
                    HPDF_Page_SetRGBFill (page,0.0, 0.0, 0.0);//couleur ligne
                    HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne

                }
            }
        }

        HPDF_Page_SetLineWidth (page, 0.25);
        HPDF_Page_SetGrayStroke (page, 0.5);
        HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage


        HPDF_Page_SetFontAndSize (page, def_font, 4);
        for(int l=0; l<draw_preset_parameters[pr][1]; l++)
        {
            for(int co=0; co<draw_preset_parameters[pr][0]; co++)
            {
                sprintf(header_export,"%d",draw_preset_channel_routing[pr][co+(l*draw_preset_parameters[pr][0])] );
                draw_info(page, 104+(larg*co), debut_lignes -(position_ligne1+(cmptline_pdf*12))-(l*haut),header_export);
            }
        }
        HPDF_Page_SetFontAndSize (page, def_font, 10);

        saut_de_page();
    }

    return(0);
}
