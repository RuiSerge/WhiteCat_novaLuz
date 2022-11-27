void draw_fleche_link  (HPDF_Page    page,
{

    HPDF_Page_MoveTo (page, x, y -10);
    HPDF_Page_LineTo (page, x+10, y - 10);
    HPDF_Page_MoveTo (page, x+10, y - 10);
    HPDF_Page_LineTo (page, x+10, y -18 );
    HPDF_Page_MoveTo (page, x+10, y - 18);
    HPDF_Page_LineTo (page, x+6, y -14 );
    HPDF_Page_MoveTo (page, x+10, y - 18);
    HPDF_Page_LineTo (page, x+14, y -14 );
    HPDF_Page_Stroke (page);


}
