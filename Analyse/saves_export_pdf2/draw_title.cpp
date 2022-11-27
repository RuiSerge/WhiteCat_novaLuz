void draw_title  (HPDF_Page    page,
{
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, x, y - 10);
    HPDF_Page_ShowText (page, label);
    HPDF_Page_EndText (page);

    HPDF_Page_MoveTo (page, x, y - 12);
    HPDF_Page_LineTo (page, x + 600, y - 12);
    HPDF_Page_Stroke (page);
    cmptline_pdf++;
    cmptline_pdf++;
    verification_fin_de_page();
}
