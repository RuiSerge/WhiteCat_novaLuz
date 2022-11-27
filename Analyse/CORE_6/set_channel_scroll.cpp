int set_channel_scroll( int ch)
{
    switch (ClassicalChannelView)
    {
    case 0:
    {
        int pr=check_wich_channel_is_in_view(ch);
        scroll_channelspace=(int)(ratioview*scroll_pos_preset[pr-1]);
        break;
    }
    case 1:
    {
        if(ch>0 && ch<48)
        {
            scroll_channelspace=0;
        }
        else  if(ch>=48 && ch<97)
        {
            scroll_channelspace=23;
        }
        else  if(ch>=97 && ch<145)
        {
            scroll_channelspace=47;
        }
        else  if(ch>=145 && ch<193)
        {
            scroll_channelspace=70;
        }
        else  if(ch>=193 && ch<241)
        {
            scroll_channelspace=95;
        }
        else  if(ch>=241 && ch<289)
        {
            scroll_channelspace=117;
        }
        else  if(ch>=289 && ch<337)
        {
            scroll_channelspace=141;
        }
        else  if(ch>=337 && ch<385)
        {
            scroll_channelspace=163;
        }
        else  if(ch>=385 && ch<433)
        {
            scroll_channelspace=187;
        }
        else  if(ch>=433 && ch<481)
        {
            scroll_channelspace=210;
        }
        else  if(ch>=481)
        {
            scroll_channelspace=236;
        }
        break;
        default:
            break;
        }
    }
    return(0);
}
