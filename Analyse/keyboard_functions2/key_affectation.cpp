int key_affectation()
{
    if ((key_shifts & KB_SHIFT_FLAG  || index_false_shift==1) && index_patch_window==1)
    {
        if(numeric_postext>0)//attribution directe
        {
            iddim=atoi(numeric);
            if(iddim<513 && iddim!=0)
            {
                Dimmers_selected[iddim]=1;
            }
            last_dim_selected=iddim;
            reset_numeric_entry();
            numeric_postext=0;
        }

        for(int i=0; i<513; i++)
        {
            if(Dimmers_selected[i]==1)
            {
                Patch[i]=last_ch_selected;

                if(index_build_patch_from_plot==1)
                {
                    for (int l=0; l<4; l++)
                    {
                        for(int u=1; u<=nbre_symbols_on_plot[l]; u++)
                        {
                            if  ( symbol_is_selected[l][u] == 1 &&  symbol_channel_is[l][u] == last_ch_selected  )
                            {
                                symbol_dimmer_is[l][u]= iddim;
                            }
                        }
                    }
                }

            }
        }



        generate_channel_view_list_from_patched_circuits();
        if(index_patch_affect_is_done==1)//reset de ma string de control
        {
            strcpy(string_monitor_patch,"");
            index_patch_affect_is_done=0;
        }



        char tmp_str_ch[4];
        sprintf(tmp_str_ch,"%d",last_ch_selected);
        strcat(string_monitor_patch," To Ch:");
        strcat(string_monitor_patch,tmp_str_ch);
        index_patch_affect_is_done=1;
        patch_unselect_all_dimmers();
        for (int ci=1; ci<514; ci++)
        {
            Selected_Channel[ci]=0;
        }
        last_ch_selected=0;
    }
    else if (key_shifts & KB_CTRL_FLAG || index_false_control==1)
    {
        sprintf(string_Last_Order,">> Setted Time");
        read_time_string_entry();
    }

    else
    {
        if(index_ask_confirm==0)
        {
            if(index_type==0)
            {

                bool detect_selectch_on=0;
                for(int chk_ch=1; chk_ch<514; chk_ch++)
                {
                    if (Selected_Channel[chk_ch]==1)
                    {
                        detect_selectch_on=1;
                    }
                }
                if(detect_selectch_on==1)
                {
                    int chlevelis=0;
                    if(dmx_view==0)
                    {
                        if(atof(numeric)>0)
                        {
                            chlevelis=(int)((atof(numeric) *2.55) +1);// + 1 pour arrondir le pourcentage lors de la conversion % -> dmx
                        }
                        else
                        {
                            chlevelis=0;
                        }
                    }
                    else if (dmx_view==1)
                    {
                        chlevelis= atol(numeric);
                    }

                    if(chlevelis>255)
                    {
                        chlevelis=255;
                    }
                    if(chlevelis<0)
                    {
                        chlevelis=0;
                    }

                    for (int ci=1; ci<514; ci++)
                    {
                        switch(index_do_hipass)
                        {
                        case 0://normal
                            if(Selected_Channel[ci]==1 && index_blind==0)
                            {
                                bufferSaisie[ci]=chlevelis;
                            }
                            else if(Selected_Channel[ci]==1  && index_blind==1)
                            {
                                bufferBlind[ci]=chlevelis;
                            }
                            break;
                        case 1://mode hipass faders
                            if(Selected_Channel[ci]==1)
                            {
                                FaderManipulating=highest_level_comes_from_fader[ci]-1;
                                if(DockTypeIs[FaderManipulating][dock_used_by_fader_is[FaderManipulating]]==0)//pas les contenus dynamiques, juste les circuits enregistrés on the fly
                                {
                                    FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][ci]  =chlevelis;
                                }

                            }
                            break;
                        default:
                            break;
                        }
                    }
                    switch(dmx_view)
                    {
                    case 0:
                        sprintf(string_Last_Order,">> Selection AT %d",(int)(chlevelis/2.55));
                        break;
                    case 1:
                        sprintf(string_Last_Order,">> Selection AT %d", chlevelis);
                        break;
                    default:
                        break;
                    }
                    reset_numeric_entry();
                    index_level_attribue=1;
                }
            }
        }
        else if(index_ask_confirm==1)
        {

            operations_confirmation();

            reset_index_actions();
            reset_indexs_confirmation();

            substract_a_window(W_ASKCONFIRM);
            window_focus_id=previous_window_focus_id;

        }
    }
    return(0);
}
