int pdf_draw_little_gridplayer(HPDF_REAL xx, HPDF_REAL yy)
{
for(int l=0;l<=grider_nb_row;l++ )
     {
        HPDF_Page_MoveTo (page, xx, yy-(l*6));
        HPDF_Page_LineTo (page, xx+(grider_nb_col*6), yy-(l*6));
        HPDF_Page_Stroke (page);
    }
    for(int col=0;col<=grider_nb_col;col++ )
     {
        HPDF_Page_MoveTo (page, xx+(col*6), yy);
        HPDF_Page_LineTo (page, xx+(col*6), yy-(grider_nb_row*6));
        HPDF_Page_Stroke (page);
    }

return(0);
}
