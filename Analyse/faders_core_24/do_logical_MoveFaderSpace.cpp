int do_logical_MoveFaderSpace(int ydelimitation)
{
    if( window_focus_id==W_FADERS && mouse_x< LargeurEspaceFaderSize && mouse_y>=ydelimitation-5 && mouse_y<=ydelimitation+35  )
    {

        if( Midi_Faders_Affectation_Type!=0)
        {
            if(mouse_button==1 && mouse_released==0 &&  window_focus_id==W_FADERS)
            {
                if(  mouse_x>scroll_faderspace+50 && mouse_x<scroll_faderspace+100  )//deplacement Y
                {
                    attribute_midi_solo_affectation(1627,Midi_Faders_Affectation_Mode);
                }
                else if  (  mouse_x>scroll_faderspace && mouse_x<scroll_faderspace+50  )//deplacement X
                {
                    attribute_midi_solo_affectation(767,Midi_Faders_Affectation_Mode);
                }
                mouse_released=1;
            }
        }
        else
        {
            index_moving_fader_space=1;
            if(index_moving_y_slide==0 && ( mouse_x<scroll_faderspace+50 || mouse_x>scroll_faderspace+100) )
            {
                index_moving_x_slide=1;
                index_moving_y_slide=0;
            }
            if(index_moving_x_slide==0 &&  mouse_x>scroll_faderspace+50 && mouse_x<scroll_faderspace+100 )//handle vetical
            {
                index_moving_y_slide=1;
                index_moving_x_slide=0;
            }

        }
    }


    if(index_moving_x_slide==1)
    {
        scroll_faderspace=mouse_x-25;
    }
    else if(index_moving_y_slide==1)
    {
        YFader=mouse_y+30+25;
    }

    return(0);
}
