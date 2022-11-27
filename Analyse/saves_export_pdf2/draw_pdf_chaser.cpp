int draw_pdf_chaser(int chaser_num, HPDF_Page    page)
{

    HPDF_Page_SetRGBStroke (page, 0.0, 0.5, 0.0);//couleur ligne
    HPDF_Page_BeginText (page);
    HPDF_Page_SetFontAndSize (page, def_font, 10);
    HPDF_Page_EndText (page);
    strcpy(header_export,"");

    sprintf(header_export,"CHASER %d",chaser_num+1 );
    draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    sprintf(header_export,"Description: %s", chaser_name[chaser_num]);
    draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    char tmp_y[16];
    switch(chaser_time_mode[chaser_num])
    {
    case 0:
        sprintf(tmp_y,"Time Standard");
        break;
    case 1:
        sprintf(tmp_y,"TimeJoin");
        break;
    default:
        break;
    }
    sprintf(header_export,"Time Unit: %f Time Mode: %s ", time_unit[chaser_num], tmp_y);
    draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    switch(chaser_way[chaser_num])
    {
    case 0:
        sprintf(tmp_y,"Forward Way");
        break;
    case 1:
        sprintf(tmp_y,"Backward Way");
        break;
    default:
        break;
    }
    if(chaser_aller_retour[chaser_num]==1)
    {
        sprintf(header_export,"%s , aller-retour mode", tmp_y);
    }
    else
    {
        sprintf(header_export, tmp_y);
    }
    draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    switch(chaser_is_playing[chaser_num])
    {
    case 0:
        sprintf(tmp_y,"PLAY OFF");
        break;
    case 1:
        sprintf(tmp_y,"PLAY ON");
        break;
    default:
        break;
    }
    if(chaser_is_in_loop[chaser_num]==1)
    {
        sprintf(header_export,"%s , LOOP ON", tmp_y);
    }
    else
    {
        sprintf(header_export, tmp_y);
    }
    draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    sprintf(header_export,"Chaser last affectation: Fader %d Dock %d ", view_chaser_affected_to_fader[chaser_selected][0]+1,view_chaser_affected_to_fader[chaser_selected][1]+1);
    draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
    cmptline_pdf++;
    if(index_slave_chaser_to_accelerometre[chaser_num]==1)
    {
        sprintf(header_export,"Chaser LFO Slaviness: %.2f",chaser_slaviness[chaser_num]);
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
    }
    cmptline_pdf++;
    cmptline_pdf++;
    cmptline_pdf++;
    for(int ind=0; ind<nbre_de_cases_par_track; ind++)
    {
        if( chaser_begin_step_is[chaser_num]==ind)
        {
            HPDF_Page_SetRGBFill (page, 1.0, 0.5, 0.0);//couleur remplissage
            HPDF_Page_SetRGBStroke (page, 1.0, 0.5, 0.0);//couleur ligne
            HPDF_Page_Rectangle  (page, 120+(ind*12),debut_lignes -(position_ligne1+(cmptline_pdf*12)), 12,12);
            HPDF_Page_FillStroke (page);
            HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
        }
        if( chaser_end_step_is[chaser_num]==ind)
        {
            HPDF_Page_SetRGBFill (page, 1.0, 0.0, 0.0);//couleur remplissage
            HPDF_Page_SetRGBStroke (page, 1.0, 0.0, 0.0);//couleur ligne
            HPDF_Page_Rectangle  (page, 120+(ind*12),debut_lignes -(position_ligne1+(2+cmptline_pdf*12)+24), 12,12);
            HPDF_Page_FillStroke(page);
            HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
        }
    }
    HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
    HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
    for(int ind=0; ind<nbre_de_cases_par_track; ind++)
    {
        sprintf(header_export,"%d", ind+1);
        draw_info(page, 120+(ind*12),debut_lignes -(position_ligne1+(cmptline_pdf*12)),header_export);
    }
    cmptline_pdf++;
    cmptline_pdf++;
    cmptline_pdf++;

    for(int tr=0; tr<nbre_tracks_par_chaser; tr++)
    {
        for(int ind=0; ind<nbre_de_cases_par_track; ind++)
        {
            if( chaser_step_operation[chaser_num][tr][ind]!=0)//si quelquechosedans track
            {
                float colRt, colGt, colBt;
                switch (chaser_step_operation[chaser_num][tr][ind])
                {
                case 1:
                    colRt=1.0;
                    colGt=0.5;
                    colBt=0.0;
                    break;
                case 2:
                    colRt=0.0;
                    colGt=1.0;
                    colBt=0.0;
                    break;
                case 3:
                    colRt=1.0;
                    colGt=0.0;
                    colBt=0.0;
                    break;
                default:
                    break;
                }
                HPDF_Page_SetRGBFill (page,colRt, colGt, colBt);//couleur remplissage
                HPDF_Page_SetRGBStroke (page, colRt, colGt, colBt);//couleur ligne
                HPDF_Page_Rectangle  (page, 120+(ind*12),debut_lignes -(position_ligne1+(cmptline_pdf*12)+12+(tr*12)), 12,12);
                HPDF_Page_FillStroke (page);
                HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);//couleur ligne
            }
        }
    }

    HPDF_Page_SetLineWidth (page, 0.25);
    HPDF_Page_SetGrayStroke (page, 0.5);
    HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage
    /* horizontales */
    for(int lych=(int)cmptline_pdf; lych<=cmptline_pdf+nbre_tracks_par_chaser; lych++ )
    {
        HPDF_Page_MoveTo (page, 120, debut_lignes -(position_ligne1+(lych*12)));
        HPDF_Page_LineTo (page, 120+(12*nbre_de_cases_par_track), debut_lignes -(position_ligne1+(lych*12)));
        HPDF_Page_Stroke (page);
    }
    /* verticales */
    for(int lxch=0; lxch<=nbre_de_cases_par_track; lxch++ )
    {
        HPDF_Page_MoveTo (page, 120+(lxch*12), debut_lignes -(position_ligne1+(cmptline_pdf*12)-(4*12)));
        HPDF_Page_LineTo (page, 120+(lxch*12), debut_lignes -(position_ligne1+((cmptline_pdf+nbre_tracks_par_chaser)*12)));
        HPDF_Page_Stroke (page);
    }

    char tmp_u[6];
    for(int ly=0; ly<nbre_tracks_par_chaser; ly++)
    {
        switch( track_is_on[chaser_num][ly])
        {
        case 0:
            sprintf(tmp_u,"OFF");
            break;
        case 1:
            sprintf(tmp_u,"ON");
            break;
        default:
            break;
        }
        sprintf(header_export,"Tr:%d %s(%d)",ly+1,tmp_u,track_level[chaser_num][ly]);
        draw_info(page, 40, debut_lignes -(position_ligne1 +(cmptline_pdf*12)+(ly*12)),header_export);
    }

    cmptline_pdf+=24;
    cmptline_pdf++;
    cmptline_pdf++;
    int comptch=0;
    bool there_is_someone_inside_this_track=0;
    for(int t=0; t<nbre_tracks_par_chaser; t++)
    {
        there_is_someone_inside_this_track=0;
        for(int c=1; c<513; c++)
        {
            if(TrackContains[chaser_num][t][c]!=0)
            {
                there_is_someone_inside_this_track=1;
                break;
            }
        }

        if(there_is_someone_inside_this_track==1 && TrackTypeIs[chaser_num][t]==0)//si quelqu un dans piste et type de track CIRCUITS
        {
            sprintf(header_export,"Track: %d  / Description: %s",t+1,chaser_track_name[chaser_num][t]);
            draw_title(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
            cmptline_pdf++;
            strcpy(header_export,"");
            if(cmptline_pdf>max_ligne_pdf)
            {
                sprintf(header_export,"page %d", num_page_pdf);
                draw_numpage(page,width/2,20,header_export);
                page=HPDF_AddPage(pdf);
                cmptline_pdf=0;
                num_page_pdf++;
                HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne
                HPDF_Page_BeginText (page);
                HPDF_Page_SetFontAndSize (page, def_font, 10);
                HPDF_Page_EndText (page);
                strcpy(header_export,"");
            }
            comptch=0;
            for(int c=1; c<513; c++)
            {
                if(TrackContains[chaser_num][t][c]!=0)
                {
                    if(comptch==0)
                    {
                        cmptline_pdf++;    //retour ligne après 10 circuits
                        strcpy(header_export,"");
                    }

                    switch(dmx_view)
                    {
                    case 0:
                        sprintf(little_header,"%d=%d   ",c,(int)((float)(TrackContains[chaser_num][t][c])/2.55));
                        break;
                    case 1:
                        sprintf(little_header,"%d=%d   ",c,TrackContains[chaser_num][t][c]);
                        break;
                    default:
                        break;
                    }
                    strcat(header_export,little_header);
                    comptch++;
                    if(comptch>10)
                    {
                        comptch=0;
                        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
                        cmptline_pdf++;
                        if(cmptline_pdf>max_ligne_pdf)
                        {
                            sprintf(header_export,"page %d", num_page_pdf);
                            draw_numpage(page,width/2,20,header_export);
                            page=HPDF_AddPage(pdf);
                            cmptline_pdf=0;
                            num_page_pdf++;
                            HPDF_Page_SetRGBStroke (page, 0.8, 0.0, 0.0);//couleur ligne
                            HPDF_Page_BeginText (page);
                            HPDF_Page_SetFontAndSize (page, def_font, 10);
                            HPDF_Page_EndText (page);
                            strcpy(header_export,"");
                        }
                    }
                }
            }
            draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
            strcpy(header_export,"");
            cmptline_pdf++;
        }//fin si quelqu un dedans en mode circuits
        else if( TrackTypeIs[chaser_num][t]==1)//si mémoire affectée à piste
        {
            sprintf(header_export,"Track: %d  / Description: %s",t+1,chaser_track_name[chaser_num][t]);
            draw_title(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
            cmptline_pdf++;
            strcpy(header_export,"");
            if(cmptline_pdf>max_ligne_pdf)
            {
                sprintf(header_export,"page %d", num_page_pdf);
                draw_numpage(page,width/2,20,header_export);
                page=HPDF_AddPage(pdf);
                cmptline_pdf=0;
                num_page_pdf++;
                HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne
                HPDF_Page_BeginText (page);
                HPDF_Page_SetFontAndSize (page, def_font, 10);
                HPDF_Page_EndText (page);
                strcpy(header_export,"");
            }
            cmptline_pdf++;
            sprintf(header_export,"Contains Mem. %.1f",(float (TrackHasMem[chaser_num][t])/10));
            draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
            strcpy(header_export,"");
            cmptline_pdf++;
        }
        cmptline_pdf++;
    }

    cmptline_pdf++;
    cmptline_pdf++;
    cmptline_pdf++;
    cmptline_pdf++;
    cmptline_pdf++;
    return(0);
}
