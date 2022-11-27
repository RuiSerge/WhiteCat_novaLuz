void saut_de_page()
{
sprintf(header_export,"page %d", num_page_pdf);
draw_numpage(page,width/2,20,header_export);
page=HPDF_AddPage(pdf);cmptline_pdf=0;
num_page_pdf++;
HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne
HPDF_Page_BeginText (page);
HPDF_Page_SetFontAndSize (page, def_font, 10);
HPDF_Page_EndText (page);
strcpy(header_export,"");
}
