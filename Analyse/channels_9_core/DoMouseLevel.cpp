int DoMouseLevel()
{
    if (mouse_z>last_scroll_mouse_for_chan )
    {

        simulate_keypress(KEY_UP << 8);
        last_scroll_mouse_for_chan= mouse_z;
    }
    else if (mouse_z<last_scroll_mouse_for_chan )
    {

        simulate_keypress(KEY_DOWN << 8);
        last_scroll_mouse_for_chan= mouse_z;
    }

    if (window_focus_id==W_BANGER &&  mouse_x>=X_banger && mouse_x<=X_banger+480 && mouse_y>=Y_banger && mouse_y<=Y_banger+300  )//banger
    {
        switch(over_family)
        {
        case 0:
            if(editing_banger_family ==1 &&  over_banger_event>0)
            {
                if(mouse_z>mouse_level_for_event)
                {
                    bangers_type[index_banger_selected][ over_banger_event-1]++;
                    reset_banger_event(index_banger_selected, over_banger_event-1);
                    constrain_banger_type( over_banger_event-1);
                    position_mouse_z(0);  //reset
                    mouse_level_for_event=mouse_z;
                    mouse_level_for_banger=mouse_z;
                    editing_banger_family=0;
                    editing_banger_action=0;
                }
                if(mouse_z<mouse_level_for_event)
                {
                    bangers_type[index_banger_selected][ over_banger_event-1]--;
                    if(bangers_type[index_banger_selected][ over_banger_event-1]<0)
                    {
                        bangers_type[index_banger_selected][ over_banger_event-1]=0;
                    };
                    reset_banger_event(index_banger_selected, over_banger_event-1);
                    position_mouse_z(0);  //reset
                    mouse_level_for_event=mouse_z;
                    mouse_level_for_banger=mouse_z;
                    editing_banger_family=0;
                    editing_banger_action=0;
                }
            }
            break;
        case 1:
            if(editing_banger_action==1 && over_banger_action>0)
            {
                if(mouse_z>mouse_level_for_banger)
                {
                    position_mouse_z(0);//reset
                    mouse_level_for_banger=mouse_z;
                    mouse_level_for_event=mouse_z;
                    editing_banger_family=0;
                    editing_banger_action=0;
                    bangers_action[index_banger_selected][over_banger_action-1]++;
                    reset_banger_params(index_banger_selected,over_banger_action-1);
                    constrain_banger_param(over_banger_action-1);
                }
                if(mouse_z<mouse_level_for_banger)
                {
                    position_mouse_z(0);//reset
                    mouse_level_for_banger=mouse_z;
                    mouse_level_for_event=mouse_z;
                    bangers_action[index_banger_selected][over_banger_action-1]--;
                    if(bangers_action[index_banger_selected][over_banger_action]<0)
                    {
                        bangers_action[index_banger_selected][over_banger_action-1]=0;
                    }
                    reset_banger_params(index_banger_selected,over_banger_action-1);
                }
            }
            break;
        default:
            break;
        }
    }
    else
    {
        mouse_level_for_event=mouse_z;
        mouse_level_for_banger=mouse_z;
        editing_banger_family=0;
        editing_banger_action=0;
    }
    return(0);
}
