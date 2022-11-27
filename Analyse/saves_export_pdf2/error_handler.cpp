error_handler (HPDF_STATUS   error_no,
{
    sprintf (string_Last_Order,"ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
             (HPDF_UINT)detail_no);
    longjmp(env, 1);
}
