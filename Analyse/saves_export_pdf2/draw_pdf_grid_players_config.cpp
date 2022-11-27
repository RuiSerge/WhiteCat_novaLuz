int draw_pdf_grid_players_config()
{

HPDF_Page_SetRGBStroke (page, 0.0, 0.5, 0.0);//couleur ligne
HPDF_Page_BeginText (page);
HPDF_Page_SetFontAndSize (page, def_font, 10);
HPDF_Page_EndText (page);
strcpy(header_export,"");


strcpy(header_export,"Channels Configuration Grid:" );
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);



sprintf(header_export,"Starting Channel: %d",grider_begin_channel_is );
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
cmptline_pdf++;

sprintf(header_export,"On save your 4 GridPlayers were in this state:" );
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int i=0;i<4;i++)
{
draw_pdf_gridayer_state(i);
}



sprintf(header_export,"GridPlayer Channel Routing:" );
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);


HPDF_Page_SetLineWidth (page, 0.25);
HPDF_Page_SetGrayStroke (page, 0.5);
HPDF_Page_SetRGBFill (page, 0.0, 0.0, 0.0);//couleur remplissage


    /* horizontales */
    for(int lych=0;lych<=grider_nb_row;lych++ )
     {
        HPDF_Page_MoveTo (page, 100, debut_lignes -(position_ligne1+(cmptline_pdf*12))-(lych*16));
        HPDF_Page_LineTo (page, 100+(16*grider_nb_col), debut_lignes -(position_ligne1+(cmptline_pdf*12))-(lych*16));
        HPDF_Page_Stroke (page);
    }
  /* verticales */
    for(int lxch=0;lxch<=grider_nb_col;lxch++ )
     {
        HPDF_Page_MoveTo (page, 100+(lxch*16), debut_lignes -(position_ligne1+(cmptline_pdf*12)));
        HPDF_Page_LineTo (page, 100+(lxch*16), debut_lignes -(position_ligne1+(cmptline_pdf*12)+(grider_nb_row*16)));
        HPDF_Page_Stroke (page);
    }


HPDF_Page_SetFontAndSize (page, def_font, 7);
for(int l=0;l<grider_nb_row;l++)
{
for(int co=0;co<grider_nb_col;co++)
{
sprintf(header_export,"%d",grider_begin_channel_is+(l*grider_nb_col)+co);
draw_info(page, 104+(16*co), debut_lignes -(position_ligne1+(cmptline_pdf*12))-(l*16),header_export);
}
}
HPDF_Page_SetFontAndSize (page, def_font, 10);

cmptline_pdf+=grider_nb_row;


sprintf(header_export,"page %d", num_page_pdf);
draw_numpage(page,width/2,20,header_export);
page=HPDF_AddPage(pdf);cmptline_pdf=0;
num_page_pdf++;
HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne
HPDF_Page_BeginText (page);
HPDF_Page_SetFontAndSize (page, def_font, 10);
HPDF_Page_EndText (page);
strcpy(header_export,"");

for(int gd=0;gd<127;gd++)
{
if(check_there_is_someone_in_grid(gd)==1)
{
sprintf(header_export,"Grid number %d: %s",gd+1,grider_name[gd]);
draw_title(page, 120, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
draw_pdf_grid(gd,20,debut_lignes -(position_ligne1 +(cmptline_pdf*12)));
saut_de_page();
}

}

return(0);
}
