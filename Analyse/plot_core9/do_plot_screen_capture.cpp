int do_plot_screen_capture(char capturename[25])
{
    int thex=0;
    int they=0;
    int thesix=0;
    int thesiy=0;

    if(index_menus_lighting_plot==3)
    {
        thex=x_plot;
        they=y_plot+position_plan_y;
        thesix=plot_window_x_size;
        thesiy=plot_window_y_size-position_plan_y;
    }
    else
    {
        thex=x_plot+position_plan_x;
        they=y_plot+position_plan_y ;
        thesix=plot_window_x_size-position_plan_x;
        thesiy=plot_window_y_size-position_plan_y;
    }

    if (thesix> SCREEN_W)
    {
        thesix=SCREEN_W;
    }
    if(thesiy> SCREEN_H)
    {
        thesiy=SCREEN_H;
    }

    Bitmap MySnapshot(thesix, thesiy);
    MySnapshot.CopyFromScreen( thex, they);

    char tmmm[256];
    sprintf(tmmm,"import_export/plot/%s.jpg",capturename);
    MySnapshot.Save( tmmm );


    return(0);
}
