int constrain_banger_param(int lp)
{
    switch (bangers_type[index_banger_selected][lp])
    {
    case 0://rien
        bangers_action[index_banger_selected][lp]=0;
        break;
    case 1://faders
        if(bangers_action[index_banger_selected][lp]>41)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 2://midi send
        if(bangers_action[index_banger_selected][lp]>30)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 3://windows
        if(bangers_action[index_banger_selected][lp]>18)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 4://alarmes
        if(index_type==1 && index_enable_edit_banger==1)
        {
            for(int tt=0; tt<24; tt++)
            {
                string_alarm[index_banger_selected][tt]=numeric[tt];
            }
            string_alarm[index_banger_selected][24]='\0';
            reset_numeric_entry();
            numeric_postext=0;
            sprintf(string_Last_Order,">>GIVED NAME ALARM FOR BANGER %d ",index_banger_selected+1);
        }
        break;
    case 5://audio
        if(bangers_action[index_banger_selected][lp]>15)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 6: //sequenciel
        if(bangers_action[index_banger_selected][lp]>8)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 7://chaser window
        if(bangers_action[index_banger_selected][lp]>16)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 8://minifaders
        if(bangers_action[index_banger_selected][lp]>17)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 9://icat
        if(bangers_action[index_banger_selected][lp]>4)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 10://chrono
        if(bangers_action[index_banger_selected][lp]>2)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 11://set channel
        if(bangers_action[index_banger_selected][lp]>15)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 12://set banger
        if(bangers_action[index_banger_selected][lp]>3)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 13://midi mute
        if(bangers_action[index_banger_selected][lp]>9)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 14://grid
        if(bangers_action[index_banger_selected][lp]>23)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 15://hardware
        if(bangers_action[index_banger_selected][lp]>3)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 16://emulate kbd
        if(bangers_action[index_banger_selected][lp]>62)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 17://draw
        if(bangers_action[index_banger_selected][lp]>10)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 18://echo
        if(bangers_action[index_banger_selected][lp]>25)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    case 19://wave
        if(bangers_action[index_banger_selected][lp]>12)
        {
            bangers_action[index_banger_selected][lp]=0;
        }
        break;
    default:
        break;
    }

    return(0);
}
