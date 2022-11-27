void draw_section (HPDF_Page    page,
{

HPDF_Page_SetLineWidth (page, 30);//epaisseur
HPDF_Page_SetRGBStroke (page, R, G, B);//couleur ligne
HPDF_Page_SetLineCap (page, HPDF_ROUND_END);
HPDF_Page_SetFontAndSize (page, def_font, 25);

    HPDF_Page_MoveTo (page, x , y );
    HPDF_Page_LineTo (page, x+500, y );
    HPDF_Page_Stroke (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, x, y-7);
    HPDF_Page_ShowText (page, label);
    HPDF_Page_EndText (page);

HPDF_Page_SetFontAndSize (page, def_font, 10);
HPDF_Page_SetLineWidth (page, 1);//epaisseur
HPDF_Page_SetRGBStroke (page, 0.0, 0.5, 0.5);//couleur ligne
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
