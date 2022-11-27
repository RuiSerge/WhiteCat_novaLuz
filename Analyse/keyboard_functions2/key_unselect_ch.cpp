int key_unselect_ch()
{
reset_numeric_entry();

if(key[KEY_LSHIFT]|| index_false_shift==1)
{
             if( index_patch_window==1 && index_ask_confirm==0)
             {
             patch_unselect_all_dimmers();
             strcpy(string_monitor_patch,"");
             index_patch_affect_is_done=0;
             }
}


else
{

             for (int ci=1;ci<514;ci++)
             {Selected_Channel[ci]=0;}
             last_ch_selected=0;
             index_type=0;index_level_attribue=0;
             substract_channel_selection_to_layers_plot();
             if(window_focus_id==W_PLOT )
             {
                if(index_menus_lighting_plot==1) unselect_all_shapes();
                else if( index_menus_lighting_plot==2 || index_menus_lighting_plot==4)
                {
                    for(int i=0;i<4;i++)
                    {
                         reset_symbols_selected(i);
                    }
                }
              }


             if(index_ask_confirm==1)
             {
             reset_indexs_confirmation();
             reset_index_actions();
             substract_a_window(W_ASKCONFIRM);
             window_focus_id=previous_window_focus_id;
             add_a_window(window_focus_id);
             }
}

return(0);
}
