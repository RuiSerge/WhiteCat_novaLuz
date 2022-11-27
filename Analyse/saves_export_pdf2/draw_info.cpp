void draw_info  (HPDF_Page    page,
{
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, x, y - 10);
    HPDF_Page_ShowText (page, label);
    HPDF_Page_EndText (page);

    //  HPDF_Page_Stroke (page);
}
