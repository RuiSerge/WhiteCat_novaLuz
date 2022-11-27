int pdf_draw_infos_of_step(HPDF_REAL xx, HPDF_REAL yy,int grd,int stp)
{
    HPDF_Page_SetFontAndSize (page, def_font,6);

    char the_in[12];
    char the_out[12];

    char the_delay_in[12];
    char the_delay_out[12];

    strcpy(header_export,"");//nettoyage pour les temps

    affichage_time_format(grid_times[grd][stp][1]);//in
    sprintf(the_in,string_conversion_timeis);
    affichage_time_format(grid_times[grd][stp][3]);//out
    sprintf(the_out,string_conversion_timeis);
    affichage_time_format(grid_times[grd][stp][0]);//din
    sprintf(the_delay_in,string_conversion_timeis);
    affichage_time_format(grid_times[grd][stp][2]);//dout
    sprintf(the_delay_out,string_conversion_timeis);

    if(grid_times[grd][stp][0]>0)
    {
        sprintf(header_export,"d. %s",the_delay_in);
    }
    strcat(header_export," IN ");
    strcat(header_export,the_in);
    draw_info(page,xx,yy-6,header_export);
    strcpy(header_export,"");

    if(grid_times[grd][stp][2]>0)
    {
        sprintf(header_export,"d. %s",the_delay_out);
    }
    strcat(header_export," OUT ");
    strcat(header_export,the_out);
    draw_info(page,xx,yy-12,header_export);
    strcpy(header_export,"");

    if(grid_goto[grd][stp][0]!=-1 || grid_goto[grd][stp][1]!=-1)
    {
        sprintf(header_export,"Goto:  %d - %d",grid_goto[grd][stp][0]+1, grid_goto[grd][stp][1]+1 );
        draw_info(page,xx,yy-18,header_export);
    }


    if(grid_count[grd][stp]!=0)
    {
        sprintf(header_export,"Count: %d",grid_count[grd][stp]+1 );
        draw_info(page,xx,yy-24,header_export);
    }


    if(grid_seekpos[grd][stp]!=-1)
    {
        sprintf(header_export,"Seek: %d",grid_seekpos[grd][stp]+1 );
        draw_info(page,xx,yy-30,header_export);
    }

    if(grid_stoplay[grd][stp]==1)
    {
        sprintf(header_export,"[ STOP PLAY ]" );
        draw_info(page,xx,yy-36,header_export);
    }
    return(0);
}
