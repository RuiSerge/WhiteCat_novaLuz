int Channel_macros_core(int xlist, int ylist)
{
    int temp_mini;
    int temp_limit;
    if(index_edit_listproj==1 && mouse_released==0 && window_focus_id==914 && last_ch_selected!=0)
    {
        for(int i=0; i<nbre_macros_per_channel; i++)
        {
            if( mouse_y>ylist+25+(25*i) && mouse_y<ylist+25+(25*i)+20 )
            {

                if(mouse_x>xlist && mouse_x<xlist+80  )
                {
                    if(channel_macro_reaction[last_ch_selected][i]<max_channel_macro_reaction)
                    {
                        channel_macro_reaction[last_ch_selected][i]++;
                    }
                    else
                    {
                        channel_macro_reaction[last_ch_selected][i]=0;
                    }
                    mouse_released=1;
                }

                else if(mouse_x>xlist+90 && mouse_x<xlist+90+40 )
                {

                    int temp_val=atoi(numeric);

                    if(channel_macro_reaction[last_ch_selected][i]<7)
                    {
                        switch(dmx_view)
                        {
                        case 0:
                            if(temp_val>=0 && temp_val<=100)
                            {
                                channel_macro_val[last_ch_selected][i][0]=(int)((temp_val *2.55) +1);
                                if(channel_macro_val[last_ch_selected][i][0]==1)
                                {
                                    channel_macro_val[last_ch_selected][i][0]=0;
                                }
                                reset_numeric_entry();
                            }
                            break;
                        case 1:
                            if(temp_val>=0 && temp_val<=255)
                            {
                                channel_macro_val[last_ch_selected][i][0]=temp_val;
                                reset_numeric_entry();
                            }
                            break;
                        default:
                            break;
                        }
                    }

                    else if(channel_macro_reaction[last_ch_selected][i]>=7) //follow channel
                    {
                        temp_mini=1;
                        temp_limit=512;
                        if(temp_val>=temp_mini && temp_val<=temp_limit)
                        {
                            channel_macro_val[last_ch_selected][i][0]=temp_val;
                            reset_numeric_entry();
                        }
                    }

                    mouse_released=1;
                }

                else if(mouse_x>xlist+140 && mouse_x<xlist+140+80  )
                {
                    if(channel_macro_action[last_ch_selected][i]<max_channel_macro_action)
                    {
                        channel_macro_action[last_ch_selected][i]++;
                    }
                    else
                    {
                        channel_macro_action[last_ch_selected][i]=0;
                    }
                    mouse_released=1;
                }


                else if(mouse_x>xlist+230 && mouse_x<xlist+230+40 )
                {
                    int temp_val=atoi(numeric);
                    switch(channel_macro_action[last_ch_selected][i])
                    {
                    case 0:
                        break;
                    case 1:
                        temp_mini=1;
                        temp_limit=127;
                        break;
                    case 2:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 3:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 4:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 5:
                        temp_mini=1;
                        temp_limit=4;;
                        break;
                    case 6:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 7:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 8:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 9:
                        temp_mini=1;
                        temp_limit=4;
                        break;
                    case 10:
                        temp_mini=0;
                        temp_limit=127;
                        break;
                    case 11:
                        temp_mini=0;
                        temp_limit=127;
                        break;
                    case 12:
                        temp_mini=0;
                        temp_limit=127;
                        break;
                    case 13:
                        temp_mini=0;
                        temp_limit=127;
                        break;
                    case 14:
                        temp_mini=1;
                        temp_limit=48;
                        break;
                    case 15:
                        temp_mini=1;
                        temp_limit=48;
                        break;
                    case 16:
                        temp_mini=1;
                        temp_limit=48;
                        break;
                    case 17:
                        temp_mini=1;
                        temp_limit=100;
                        break;
                    default:
                        break;
                    }
                    if(temp_val>=temp_mini&& temp_val<=temp_limit)
                    {
                        channel_macro_val[last_ch_selected][i][1]=temp_val;
                        reset_numeric_entry();
                    }
                    mouse_released=1;
                }

                if(mouse_x>xlist+280 && mouse_x<xlist+280+35  )
                {
                    macro_channel_on[last_ch_selected][i]=toggle(macro_channel_on[last_ch_selected][i]);
                    mouse_released=1;
                }

            }

        }
    }
    return(0);
}
