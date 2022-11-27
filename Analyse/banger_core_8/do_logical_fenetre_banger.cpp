int do_logical_fenetre_banger(int xb,int yb)
{

    if( mouse_x>xb+190 && mouse_x<xb+190+50 && mouse_y>yb+10 && mouse_y<yb+10+25)
    {
        if(index_main_clear==0)
        {
            int dat=atoi(numeric);
            if(dat>0 && dat <=127)
            {
                index_banger_selected=dat-1;
                reset_numeric_entry();
            }
        }
        else
        {
            index_ask_clear_banger=1;
            index_banger_to_copy_in=index_banger_selected;
            index_ask_confirm=1;
        }
        mouse_released=1;
    }

    if(mouse_x>xb+160-12 && mouse_x<xb+160+12 && mouse_y>yb+55-12 && mouse_y<yb+55+12)
    {

        switch(miditable[0][742])
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
        sprintf(string_last_midi_id,"Banger Plus is Ch: %d Pitch: %d Typ: %s",miditable[1][742],miditable[2][742],thetypinfo);
        if( Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(742,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
        else
        {
            if(index_banger_selected<126)
            {
                index_banger_selected++;
            }
            else
            {
                index_banger_selected=0;
            }
            mouse_released=1;
        }
    }
    if( mouse_x>xb+120-12 && mouse_x<xb+120+12 && mouse_y>yb+55-12 && mouse_y<yb+55+12)
    {

        switch(miditable[0][741])
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
        sprintf(string_last_midi_id,"Banger Minus is Ch: %d Pitch: %d Typ: %s",miditable[1][741],miditable[2][741],thetypinfo);
        if(Midi_Faders_Affectation_Type!=0 )//config midi
        {
            attribute_midi_solo_affectation(741,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
        else
        {
            if(index_banger_selected>0)
            {
                index_banger_selected--;
            }
            else
            {
                index_banger_selected=126;
            }
            mouse_released=1;
        }
    }
    if(mouse_x>(xb+280) && mouse_x<(xb+280+90) && mouse_y>(yb+10) && mouse_y<(yb+10+20))
    {
        index_copy_banger=toggle(index_copy_banger);
        mouse_released=1;
    }

    if(mouse_x>(xb+410) && mouse_x<(xb+410+50) && mouse_y>(yb+10) && mouse_y<(yb+10+20))
    {
        index_enable_edit_banger=toggle(index_enable_edit_banger);
        mouse_released=1;
    }

    if(mouse_x>(xb+490) && mouse_x<(xb+540) && mouse_y>(yb+10) && mouse_y<(yb+30))
    {
        do_loop_banger[index_banger_selected]=toggle(do_loop_banger[index_banger_selected]);
        ticker_loop_banger[index_banger_selected]=0;
        if(do_loop_banger[index_banger_selected]==1)
        {
            start_time_for_banger[index_banger_selected]=actual_time;
            end_time_for_banger[index_banger_selected]=default_time_of_the_bang;
            for (int o=0; o<6; o++) //reset des évènements
            {
                event_sended[index_banger_selected][o]=0;
                if(bangers_delay[index_banger_selected][o]>end_time_for_banger[index_banger_selected])
                {
                    end_time_for_banger[index_banger_selected]=bangers_delay[index_banger_selected][o];
                }
            }
            bang_is_sended[index_banger_selected]=0;//reset du bang sended is
        }
        mouse_released=1;
    }
    if(mouse_x>(xb+550) && mouse_x<(xb+600) && mouse_y>(yb+10) && mouse_y<(yb+30))
    {
        time_loop_banger[index_banger_selected]=atof(numeric);
        reset_numeric_entry();
        mouse_released=1;
    }


    if(mouse_x>(xb+410) && mouse_x<(xb+410+50) && mouse_y>(yb+40) && mouse_y<(yb+40+30))
    {

        switch(miditable[0][734])
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
        sprintf(string_last_midi_id,"Bang It Button is Ch: %d Pitch: %d Typ: %s", miditable[1][734],miditable[2][734],thetypinfo);
        if( Midi_Faders_Affectation_Type!=0 )//config midi
        {
            attribute_midi_solo_affectation(734,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
        else
        {
            start_time_for_banger[index_banger_selected]=actual_time;
            end_time_for_banger[index_banger_selected]=default_time_of_the_bang;
            for (int o=0; o<6; o++) //reset des évènements
            {
                event_sended[index_banger_selected][o]=0;
                if(bangers_delay[index_banger_selected][o]>end_time_for_banger[index_banger_selected])
                {
                    end_time_for_banger[index_banger_selected]=bangers_delay[index_banger_selected][o];
                }
            }
            bang_is_sended[index_banger_selected]=0;//reset du bang sended is
            mouse_released=1;
        }
    }

    if(mouse_x>xb+200 && mouse_x<xb+320 && mouse_y> (yb+40) && mouse_y< (yb+40)+30 && index_enable_edit_banger==1)
    {
        for(int tt=0; tt<24; tt++)
        {
            bangers_name[index_banger_selected][tt]=numeric[tt];
        }
        bangers_name[index_banger_selected][24]='\0';
        reset_numeric_entry();
        numeric_postext=0;
        if(index_text_auto_close==1)
        {
            index_type=0;
        }
        sprintf(string_Last_Order,">>GIVED A NAME FOR BANGER %d ",index_banger_selected+1);
        mouse_released=1;
    }



    for (int lp=0; lp<6; lp++) //6 ev en bang
    {

        if(mouse_x>xb+450-10 && mouse_x<xb+450+10 && mouse_y>yb+110+(lp*30)-10 && mouse_y<yb+110+(lp*30)+10)
        {

            switch(miditable[0][735+lp])
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
            sprintf(string_last_midi_id,"BangSolo %d is Ch: %d Pitch: %d Typ: %s",lp+1, miditable[1][735+lp],miditable[2][735+lp],thetypinfo);

            if(Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(735+lp,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }
            else
            {
                if(mouse_released==0)
                {
                    Bang_event(index_banger_selected,lp);
                    mouse_released=1;
                }
            }
        }

        if(window_focus_id==917 && mouse_x>xb+30 && mouse_x<xb+30+100 && mouse_y>yb+100+(lp*30) && mouse_y<yb+100+(lp*30)+20 && index_enable_edit_banger==1)
        {
            bangers_type[index_banger_selected][lp]++;
            reset_banger_event(index_banger_selected,lp);
            constrain_banger_type(lp);
            mouse_released=1;
        }

        if(window_focus_id==917 && mouse_x>xb+150 && mouse_x<xb+150+100 && mouse_y>yb+100+(lp*30) && mouse_y<yb+100+(lp*30)+20 && index_enable_edit_banger==1 )
        {
            bangers_action[index_banger_selected][lp]++;
            reset_banger_params(index_banger_selected,lp);
            constrain_banger_param(lp);
            mouse_released=1;
        }

        if(mouse_x>xb+270 && mouse_x<xb+270+40 && mouse_y>yb+100+(lp*30) && mouse_y<yb+100+(lp*30)+20 && index_enable_edit_banger==1)
        {
            bangers_params[index_banger_selected][lp][0]=atol(numeric);
            reset_numeric_entry();
            mouse_released=1;
        }
        if(mouse_x>xb+320 && mouse_x<xb+320+40 && mouse_y>yb+100+(lp*30) && mouse_y<yb+100+(lp*30)+20 && index_enable_edit_banger==1)
        {
            bangers_params[index_banger_selected][lp][1]=atol(numeric);
            reset_numeric_entry();
            mouse_released=1;
        }
        if(mouse_x>xb+380 && mouse_x<xb+380+40 && mouse_y>yb+100+(lp*30) && mouse_y<yb+100+(lp*30)+20 && index_enable_edit_banger==1)
        {
            bangers_delay[index_banger_selected][lp]=atof(numeric);
            reset_numeric_entry();
            mouse_released=1;
        }

    }


    do_logical_feedback_banger(xb+480,yb+50);

    return(0);
}
