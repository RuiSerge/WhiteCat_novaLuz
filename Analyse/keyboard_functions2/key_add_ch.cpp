int key_add_ch()
{
    if ((key_shifts & KB_SHIFT_FLAG  || index_false_shift==1) && index_patch_window==1)
    {
        iddim=atol(numeric);

        if(index_patch_affect_is_done==1)//reset de ma string de control
        {
            strcpy(string_monitor_patch,"");
            index_patch_affect_is_done=0;
        }

        if( iddim>0 &&  iddim<513)
        {
            Dimmers_selected[iddim]=1;
            last_dim_selected= iddim;
            strcat(string_monitor_patch,"D.");
            strncat(string_monitor_patch,numeric,numeric_postext);
            strcat(string_monitor_patch,"+");
            numeric_postext=0;
            reset_numeric_entry();
            set_patch_scroll( iddim);
        }
    }
    else
    {
        if(index_type==0)
        {

            idchannel=atol(numeric);
            if(index_level_attribue==1)//deselection si un niveau a ete attribue
            {
                for (int ci=1; ci<514; ci++)
                {
                    Selected_Channel[ci]=0;
                }
                last_ch_selected=0;
                index_level_attribue=0;
                substract_channel_selection_to_layers_plot();
            }
            if(idchannel>0 && idchannel<513)
            {
                switch (ClassicalChannelView)
                {
                case 0:
                    if(check_presence_of_a_channel_in_views(idchannel)==1)
                    {
                        Selected_Channel[idchannel]=1;
                        last_ch_selected=idchannel;
                        numeric_postext=0;
                        reset_numeric_entry();
                        set_channel_scroll(last_ch_selected);
                        add_channel_selection_to_layers_plot();
                    }
                    else if(check_presence_of_a_channel_in_views(idchannel)==0)
                    {
                        sprintf(string_Last_Order,"This Channel is not in an activ View");
                        numeric_postext=0;
                        reset_numeric_entry();
                    }
                    break;
                case 1:
                    Selected_Channel[idchannel]=1;
                    last_ch_selected=idchannel;
                    numeric_postext=0;
                    reset_numeric_entry();
                    set_channel_scroll(last_ch_selected);
                    add_channel_selection_to_layers_plot();
                    break;
                default:
                    break;
                }


            }
        }
    }
    return(0);
}
