int key_minus_ch()
{
    if ((key_shifts & KB_SHIFT_FLAG  || index_false_shift==1) && index_patch_window==1)
    {
        iddim=atol(numeric);

        if(iddim>0 && iddim<513)
        {
            Dimmers_selected[iddim]=0;
            strcat(string_monitor_patch,"D.");
            strncat(string_monitor_patch,numeric,numeric_postext);
            strcat(string_monitor_patch,"-");
            numeric_postext=0;
            reset_numeric_entry();
            set_patch_scroll(iddim);
        }
    }
    else
    {
        if(index_type==0)
        {
            idchannel=atol(numeric);
            if(idchannel>0 && idchannel<513)
            {
                switch (ClassicalChannelView)
                {
                case 0:
                    if(check_presence_of_a_channel_in_views(idchannel)==1)
                    {
                        Selected_Channel[idchannel]=0;
                        numeric_postext=0;
                        reset_numeric_entry();
                        set_channel_scroll(last_ch_selected);
                        substract_channel_selection_to_layers_plot();
                    }
                    else if(check_presence_of_a_channel_in_views(idchannel)==0)
                    {
                        sprintf(string_Last_Order,"This Channel is not in an activ View");
                        numeric_postext=0;
                        reset_numeric_entry();
                    }
                    break;
                case 1:
                    Selected_Channel[idchannel]=0;
                    numeric_postext=0;
                    reset_numeric_entry();
                    set_channel_scroll(last_ch_selected);
                    substract_channel_selection_to_layers_plot();
                    break;
                default:
                    break;
                }


            }
        }
    }
    return(0);
}
