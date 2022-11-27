void draw_numpage(HPDF_Page page, float x, float y,  const char *str_numpage)
{

HPDF_Page_BeginText (page);
HPDF_Page_TextOut (page, x,y ,str_numpage);
HPDF_Page_EndText (page);
}
