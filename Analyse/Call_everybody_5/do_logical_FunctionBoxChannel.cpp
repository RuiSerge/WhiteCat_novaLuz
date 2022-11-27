int do_logical_FunctionBoxChannel(int fx,int fy, int flarg, int fhaut, int space)
{
    for (int df=0; df<5; df++)
    {
        if (mouse_x>=fx && mouse_x<=fx+flarg && mouse_y>=(fy + (df*fhaut)+ (space*df)) && mouse_y<=(fy+fhaut + (df*fhaut)+ (space*df)) && mouse_released==0 )
        {

            switch (df)
            {
            case 0: //select all
                if( Midi_Faders_Affectation_Type!=0)//config midi
                {
                    switch(miditable[0][682])
                    {
                    case 0:
                        sprintf(thetypinfo,"Note");
                        break;
                    case 1:
                        sprintf(thetypinfo,"Key On");
                        break;
                    case 2:
                        sprintf(thetypinfo,"Key Off");
                        break;
                    case 4:
                        sprintf(thetypinfo,"Ctrl Change");
                        break;
                    default:
                        break;
                    }
                    sprintf(string_last_midi_id,"NumPad ALL is Ch: %d Pitch: %d Typ: %s",miditable[1][682],miditable[2][682],thetypinfo);
                    attribute_midi_solo_affectation(682,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    simulate_keypress(KEY_Y<<8);
                }
                break;
            case 1://inverse sel
                if( Midi_Faders_Affectation_Type!=0)//config midi
                {
                    switch(miditable[0][683])
                    {
                    case 0:
                        sprintf(thetypinfo,"Note");
                        break;
                    case 1:
                        sprintf(thetypinfo,"Key On");
                        break;
                    case 2:
                        sprintf(thetypinfo,"Key Off");
                        break;
                    case 4:
                        sprintf(thetypinfo,"Ctrl Change");
                        break;
                    default:
                        break;
                    }
                    sprintf(string_last_midi_id,"NumPad INV is Ch: %d Pitch: %d Typ: %s",miditable[1][683],miditable[2][683],thetypinfo);
                    attribute_midi_solo_affectation(683,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    simulate_keypress(KEY_U<<8);
                }
                break;

            case 2: //to channel funct
                if(Midi_Faders_Affectation_Type!=0)//config midi
                {
                    switch(miditable[0][684])
                    {
                    case 0:
                        sprintf(thetypinfo,"Note");
                        break;
                    case 1:
                        sprintf(thetypinfo,"Key On");
                        break;
                    case 2:
                        sprintf(thetypinfo,"Key Off");
                        break;
                    case 4:
                        sprintf(thetypinfo,"Ctrl Change");
                        break;
                    default:
                        break;
                    }
                    sprintf(string_last_midi_id,"NumPad Thru is Ch: %d Pitch: %d Typ: %s",miditable[1][684],miditable[2][684],thetypinfo);
                    attribute_midi_solo_affectation(684,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    simulate_keypress(KEY_TAB<<8);
                }
                break;
            case 3:
                channel_copy();
                break;
            case 4:
                channel_paste();
                break;
            default:
                break;
            }
            mouse_released=1;
        }
    }
    return(0);
}
