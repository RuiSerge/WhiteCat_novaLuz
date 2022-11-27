int do_colors()
{
    int lefaderacolorer=colorpreset_linked_to_dock[dock_color_selected][0];
    int ledockacolorer=colorpreset_linked_to_dock[dock_color_selected][1];

    if(dock_color_type[dock_color_selected]==0)//trichro
    {
        for (int  doC=1; doC<514; doC++)
        {
            if(dock_color_channels[dock_color_selected][0][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_red;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
            else  if(dock_color_channels[dock_color_selected][1][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_green;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
            else  if(dock_color_channels[dock_color_selected][2][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_blue;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
        }
    }
    else if(dock_color_type[dock_color_selected]==1)//quadri, desaturation par le jaune
    {
        for (int  doC=1; doC<513; doC++)
        {
            if(dock_color_channels[dock_color_selected][0][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_red;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
            else  if(dock_color_channels[dock_color_selected][1][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_green;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
            else  if(dock_color_channels[dock_color_selected][2][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_blue;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
            else  if(dock_color_channels[dock_color_selected][3][doC]==1)
            {
                dock_color_buffer_C[dock_color_selected][doC]=my_yellow;
                FaderDockContains[lefaderacolorer][ledockacolorer][doC] =dock_color_buffer_C[dock_color_selected][doC];
            }
        }
    }
    return(0);
}
