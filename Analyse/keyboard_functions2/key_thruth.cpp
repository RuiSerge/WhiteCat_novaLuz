int key_thruth()
{


    if ((key_shifts & KB_SHIFT_FLAG  || index_false_shift==1) && index_patch_window==1)
    {
        iddim=atol(numeric);
        int previous_dim_selected=last_dim_selected;
        last_dim_selected=iddim;
        if(iddim>0 && iddim<513)
        {
            if(previous_dim_selected<last_dim_selected)
            {
                for (int cit=previous_dim_selected; cit<=last_dim_selected; cit++)
                {
                    Dimmers_selected[cit]=1;
                }
            }
            if (previous_dim_selected>last_dim_selected)
            {
                for (int cit=last_dim_selected; cit<=previous_dim_selected; cit++)
                {
                    Dimmers_selected[cit]=1;
                }
            }

            if(strcmp(string_monitor_patch,"")!=0)
            {
                char * pch;
                pch = strstr(string_monitor_patch, " TO ");
                if(pch!=0)
                {
                    strcpy(string_monitor_patch,"");
                }
                else
                {
                    strcat(string_monitor_patch," TO ");
                    strcat(string_monitor_patch,"D.");
                    strncat(string_monitor_patch,numeric,numeric_postext);
                    strcat(string_monitor_patch," ");
                    numeric_postext=0;
                    reset_numeric_entry();
                }
            }
        }
    }

    else //selection circuits
    {
        idchannel=atol(numeric);
        previous_ch_selected=last_ch_selected;
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
                }
                else if(check_presence_of_a_channel_in_views(idchannel)==0)
                {
                    sprintf(string_Last_Order,"This Channel is not in an activ View");
                    numeric_postext=0;
                    reset_numeric_entry();
                }

                if(previous_ch_selected<last_ch_selected)
                {
                    for (int cit=previous_ch_selected; cit<=last_ch_selected; cit++)
                    {
                        if(check_presence_of_a_channel_in_views(cit)==1)
                        {
                            Selected_Channel[cit]=1;
                        }
                    }
                }
                if (previous_ch_selected>last_ch_selected)
                {
                    for (int cit=last_ch_selected; cit<=previous_ch_selected; cit++)
                    {
                        if(check_presence_of_a_channel_in_views(cit)==1)
                        {
                            Selected_Channel[cit]=1;
                        }
                    }
                }
                break;
            case 1:

                Selected_Channel[idchannel]=1;
                last_ch_selected=idchannel;
                numeric_postext=0;
                reset_numeric_entry();

                if(previous_ch_selected<last_ch_selected)
                {
                    for (int cit=previous_ch_selected; cit<=last_ch_selected; cit++)
                    {
                        Selected_Channel[cit]=1;
                    }
                }
                if (previous_ch_selected>last_ch_selected)
                {
                    for (int cit=last_ch_selected; cit<=previous_ch_selected; cit++)
                    {
                        Selected_Channel[cit]=1;
                    }
                }
                break;
            default:
                break;
            }

        }

        add_channel_selection_to_layers_plot();
        sprintf(string_Last_Order,">> Selected from Ch %d to Ch %d", previous_ch_selected, last_ch_selected);
    }
    return(0);
}
