int do_logical_MoveCloseBox(int xmv,int ymv, int idwindow)
{

    if(window_focus_id==idwindow)
    {
        if(mouse_y>ymv-15 && mouse_y<ymv+15 && mouse_y>hauteur_ChannelMenu)
        {
            if(mouse_x>xmv-15 && mouse_x<xmv+15)
            {
                if(mouse_button==1 && mouse_released==0 &&  im_moving_a_window==0 && original_posx==mouse_x && original_posy==mouse_y)
                {
                    substract_a_window(idwindow);
                    mouse_released=1;
                }
            }
            else if(((mouse_x>xmv+40-15 && mouse_x<xmv+40+15)|| im_moving_a_window==1)&& (original_posx==mouse_x && original_posy==mouse_y))
            {
                move_window(idwindow);
            }

        }
    }

    return(0);
}
