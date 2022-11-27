int do_logical_ChannelScroller( int ScrollX, int ScrollY)
{

    if(mouse_x>=ScrollX-10 && mouse_x<ScrollX-10+100 && mouse_y>ScrollY-5 && mouse_y<ScrollY+270
            && index_over_A_window==0 &&  index_over_faderspace==0 && mouse_released==0)
    {
        if( Midi_Faders_Affectation_Type!=0 )
        {
            attribute_midi_solo_affectation(1624,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
        else
        {
            scroll_channelspace=mouse_y-ScrollY;
            index_moving_channel_scroller=1;
        }
    }
    return(0);
}
