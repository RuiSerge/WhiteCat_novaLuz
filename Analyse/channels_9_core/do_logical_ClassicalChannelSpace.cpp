int do_logical_ClassicalChannelSpace( int xchan, int ychan, int scroll)//les 512 circuits
{

    int maxchan_per_ligne=13;
    for (int l=0; l<43; l++)
    {
        if (l==42)
        {
            maxchan_per_ligne=9;   //derniere ligne à 512
        }

        for (int c=1; c<maxchan_per_ligne; c++)
        {

            if ( mouse_x>   ((xchan-10) + (45*c)) && mouse_x< ((xchan+30) + (45*c))
                    && mouse_y> (((ychan*l)+ 40) - (int)((float)(scroll)* Ch_Scroll_Factor) )
                    && mouse_y< (((ychan*l)+ 100 - (int)((float)(scroll)* Ch_Scroll_Factor)) )
                    && index_over_A_window==0 && index_over_faderspace==0
               )
            {

                if(index_level_attribue==1)//pour déselection lors prochain circuit piqué dominique guesdon 10aout 2010
                {
                    for(int y=1; y<512; y++)
                    {
                        Selected_Channel[y]=0;
                        last_ch_selected=0;
                        if(index_plot_window==1)
                        {
                            substract_channel_selection_to_layers_plot();
                        }
                    }
                    index_level_attribue=0;
                }

                if (index_ch_thruth==0)//selection normale
                {
                    Selected_Channel[c+(l*12)]=1-(Temp_Selected_Channel[c+(l*12)]); //chainage mouse released sorti
                    if(Selected_Channel[c+(l*12)]==1)
                    {
                        last_ch_selected=c+(l*12);
                    }
                    if(index_plot_window==1)
                    {
                        add_channel_selection_to_layers_plot();
                        substract_channel_selection_to_layers_plot();
                    }
                }
                else if (index_ch_thruth==1)//selection thruth
                {
                    Channel_select_thruth(last_ch_selected,c+(l*12));
                    last_ch_selected=c+(l*12);
                    index_ch_thruth=0;
                    mouse_released=1;
                    if(index_plot_window==1)
                    {
                        add_channel_selection_to_layers_plot();
                        substract_channel_selection_to_layers_plot();
                    }
                }
            }
        }

    }

    return(0);
}
