int do_logical_Draw_Channel_Preset_Title(int xchan, int ychan, int prst_v)
{


    if(window_focus_id==0 && mouse_button==1  && mouse_released==0 && prst_v!=0 )
    {
        if(mouse_y>ychan && mouse_y<ychan+20  )
        {
            if(mouse_x> xchan+40 && mouse_x<xchan+40+210)
            {
                if(prst_v>0 && index_type==1 )
                {
                    sprintf( channel_view_Name[prst_v],numeric);
                    reset_numeric_entry();
                    numeric_postext=0;
                    mouse_released=1;
                }
            }
            else if(mouse_x>  xchan+435 && mouse_x<xchan+435+20)
            {
                if(channel_view_type_of_behaviour[prst_v]!=1)
                {
                    channel_view_type_of_behaviour[prst_v]=1;
                }
                else
                {
                    channel_view_type_of_behaviour[prst_v]=0;
                }
                mouse_released=1;
            }
            else if(mouse_x>  xchan+460 && mouse_x<xchan+460+20 )
            {
                if(channel_view_type_of_behaviour[prst_v]!=2)
                {
                    channel_view_type_of_behaviour[prst_v]=2;
                }
                else
                {
                    channel_view_type_of_behaviour[prst_v]=0;
                }
                mouse_released=1;
            }

            else if(mouse_x>  xchan+485 && mouse_x<xchan+485+30  )
            {
                channel_view_mode_builder[prst_v]=toggle(channel_view_mode_builder[prst_v]);
                mouse_released=1;
            }

            /* else if(mouse_x>  xchan+520 && mouse_x<xchan+520+55 )
             {
             channel_view_is=prst_v;
             if(index_do_dock==1)
             {
             if(channel_view_type_of_behaviour[channel_view_is]==0 &&  channel_view_mode_builder[channel_view_is]==0)
             {index_ask_record_selection_of_view=1 ; index_ask_confirm=1; mouse_released=1;}
             else  {index_ask_build_view=1; index_ask_confirm=1; mouse_released=1;  }
             }

             else if(index_do_modify==1)
             {
             index_ask_modify_selection_of_view=1 ;index_ask_confirm=1;   mouse_released=1;
             }
             else if(index_do_report==1)
             {
             index_ask_report_selection_of_view=1;index_ask_confirm=1;      mouse_released=1;
             }
             else if(index_main_clear==1)
             {
             index_ask_clear_selection_of_view=1;   mouse_released=1;
             }

             } */


        }

    }

    return(0);
}
