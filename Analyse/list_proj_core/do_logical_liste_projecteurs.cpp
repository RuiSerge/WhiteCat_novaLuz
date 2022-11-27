int do_logical_liste_projecteurs(int xlist,int ylist)
{


    for(int co=1; co<List_view_nbre_channels; co++)
    {
        if(mouse_x>(xlist+60) && mouse_x<(xlist+60)+185 && mouse_y>(ylist+50+(25*co))-15 && mouse_y<(ylist+50+(25*co)+8))
        {
            if(co+line_list_is<513)
            {

                if(index_type==1 && index_edit_listproj==1)
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        descriptif_projecteurs[co+line_list_is][tt]=numeric[tt];
                    }
                    descriptif_projecteurs[co+line_list_is][24]='\0';
                    reset_numeric_entry();
                    if(index_text_auto_close==1)
                    {
                        index_type=0;
                    }

                    for(int fa=0; fa<48; fa++)
                    {
                        for(int dk=0; dk<6; dk++)
                        {
                            if( DockTypeIs[fa][dk]==10 && FaderDirectChan[fa][dk]==co+line_list_is)
                            {
                                sprintf(DockName[fa][dk],descriptif_projecteurs[last_ch_selected]);
                            }
                        }
                    }
                    mouse_released=1;
                }
                else
                {
                    if(index_level_attribue==1)//pour d�selection auto
                    {
                        for(int y=1; y<512; y++)
                        {
                            Selected_Channel[y]=0;
                            last_ch_selected=0;
                        }
                        index_level_attribue=0;
                        if(index_plot_window==1)
                        {
                            substract_channel_selection_to_layers_plot();
                        }
                    }

                    if (index_ch_thruth==0)//selection normale
                    {
                        Selected_Channel[co+line_list_is]=1-(Temp_Selected_Channel[co+line_list_is]); //chainage mouse released sorti
                        last_ch_selected=co+line_list_is;
                        if(index_plot_window==1)
                        {
                            add_channel_selection_to_layers_plot();
                            substract_channel_selection_to_layers_plot();
                        }
                    }
                    else if (index_ch_thruth==1)//selection thruth
                    {
                        Channel_select_thruth(last_ch_selected,co+line_list_is);
                        index_ch_thruth=0;
                        if(index_plot_window==1)
                        {
                            add_channel_selection_to_layers_plot();
                            substract_channel_selection_to_layers_plot();
                        }
                        mouse_released=1;
                    }
                }
            }
        }
    }

    if(mouse_x>xlist+290 && mouse_x<xlist+330)
    {

        if( mouse_y>ylist+16 && mouse_y<ylist+36)
        {

            index_edit_listproj=toggle(index_edit_listproj);
            mouse_released=1;
        }
        if( mouse_y>ylist+51 && mouse_y<ylist+71)
        {
            line_list_is-=1;
            if(line_list_is<0)
            {
                line_list_is=0;
            }
            mouse_released=1;
        }

        if( mouse_y>ylist+81 && mouse_y<ylist+101)
        {
            if(line_list_is<513)
            {
                line_list_is+=1;
            }
            if(line_list_is>513)
            {
                line_list_is=513;
            }
            mouse_released=1;
        }
    }
    if(mouse_x>xlist+270 && mouse_x<xlist+330 && mouse_y>ylist+145 && mouse_y<ylist+150)
    {

        line_list_is=((mouse_y-ylist-146)/5);
    }

    else if( mouse_x>xlist+270 && mouse_x<xlist+330 && mouse_y>=ylist+150 && mouse_y<ylist+407)
    {
        line_list_is=(mouse_y-ylist-149)*2;
        if(line_list_is<1)
        {
            line_list_is=1;
        }
        else if(line_list_is>513)
        {
            line_list_is=513;
        }
    }


    Channel_macros_core(xlist+10,ylist+470);


    return(0);
}
