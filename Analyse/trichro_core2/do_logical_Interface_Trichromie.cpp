int do_logical_Interface_Trichromie(int xchroma, int ychroma, int rayon, int largeurchroma)
{


    if(mouse_x>xchroma-60 && mouse_x<xchroma+80 && mouse_y>ychroma-190 && mouse_y<ychroma-160)
    {

        if(index_quadri==0)
        {
            index_quadri=1;
            dock_color_type[dock_color_selected]=1;
        }
        else if(index_quadri==1)
        {
            index_quadri=0;
            dock_color_type[dock_color_selected]=0;
        }
        mouse_released=1;
    }


    if(mouse_x>xchroma+90 && mouse_x<xchroma+150 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
    {
        show_gel_list=toggle(show_gel_list);
        mouse_released=1;
    }


    if(mouse_x>xchroma+20 && mouse_x<xchroma+150 && mouse_y>ychroma+300 && mouse_y< ychroma+330)
    {
        if(index_affect_color_to_dock==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_affect_color_to_dock=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_affect_color_to_dock;
        mouse_released=1;
    }


    if( Midi_Faders_Affectation_Type!=0)//config midi
    {
        //midi report
        switch(miditable[0][497])
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
        sprintf(string_last_midi_id,"COLOR WHEEL FADER is Ch: %d Pitch: %d Typ: %s", miditable[1][497],miditable[2][497],thetypinfo);

        if(mouse_x>xchroma-140 && mouse_x<xchroma+140 && mouse_y>ychroma-140 && mouse_y<ychroma+140)
        {
            attribute_midi_solo_affectation(497,Midi_Faders_Affectation_Mode);
            mouse_released=1;
        }
    }




    if(mouse_y>ychroma+165 && mouse_y<ychroma+185)
    {
        if(mouse_x> xchroma-130 && mouse_x< xchroma-80 )//RED
        {
            if (index_inspekt==1)
            {
                show_who_is_in_dock_color(dock_color_selected,0);
            }
            couleur_to_affect=0;
            bool there_is_asel_chan=0;

            switch(index_paste_on_the_fly)
            {
            case 0:
                for(int p=1; p<513; p++)
                {
                    if(Selected_Channel[p]==1)
                    {
                        there_is_asel_chan=1;
                        break;
                    }
                }

                if(there_is_asel_chan==1 && (index_do_dock==1|| index_do_modify==1 || index_do_report==1))
                {
                    index_do_affect_color_trichro=1;
                    index_ask_confirm=1;
                }

                else
                {
                    index_do_affect_color_trichro=0;
                    index_ask_confirm=0;
                    sprintf(string_Last_Order,"No channel selected to store as color");
                }
                break;
            case 1:
                if(index_blind==0)
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferSaisie[p]=my_red;
                        }
                    }
                }
                else
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferBlind[p]=my_red;
                        }
                    }
                }
                sprintf(string_Last_Order,"Pasted On the Fly RED result");
                break;
            default:
                break;
            }
            mouse_released=1;
        }

        else if (mouse_x> xchroma-65 && mouse_x< xchroma-15 )//GREEN
        {
            if (index_inspekt==1)
            {
                show_who_is_in_dock_color(dock_color_selected,1);
            }
            couleur_to_affect=1;
            bool there_is_asel_chan=0;
            switch(index_paste_on_the_fly)
            {
            case 0:
                for(int p=1; p<513; p++)
                {
                    if(Selected_Channel[p]==1)
                    {
                        there_is_asel_chan=1;
                        break;
                    }
                }
                if(there_is_asel_chan==1 && (index_do_dock==1|| index_do_modify==1 || index_do_report==1))
                {
                    index_do_affect_color_trichro=1;
                    index_ask_confirm=1;
                }
                else
                {
                    sprintf(string_Last_Order,"No channel selected to store as color");
                }
                break;
            case 1:
                if(index_blind==0)
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferSaisie[p]=my_green;
                        }
                    }
                }
                else
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferBlind[p]=my_green;
                        }
                    }
                }
                sprintf(string_Last_Order,"Pasted On the Fly GREEN result");
                break;
            default:
                break;
            }
            mouse_released=1;
        }

        else if (mouse_x> xchroma && mouse_x< xchroma+50 )//BLUE
        {
            if (index_inspekt==1)
            {
                show_who_is_in_dock_color(dock_color_selected,2);
            }

            couleur_to_affect=2;
            bool there_is_asel_chan=0;
            switch(index_paste_on_the_fly)
            {
            case 0:
                for(int p=1; p<513; p++)
                {
                    if(Selected_Channel[p]==1)
                    {
                        there_is_asel_chan=1;
                        break;
                    }
                }
                if(there_is_asel_chan==1 && (index_do_dock==1|| index_do_modify==1 || index_do_report==1))
                {
                    index_do_affect_color_trichro=1;
                    index_ask_confirm=1;
                }
                else
                {
                    sprintf(string_Last_Order,"No channel selected to store as color");
                }
                break;
            case 1:
                if(index_blind==0)
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferSaisie[p]=my_blue;
                        }
                    }
                }
                else
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferBlind[p]=my_blue;
                        }
                    }
                }
                sprintf(string_Last_Order,"Pasted On the Fly BLUE result");
                break;
            default:
                break;
            }
            mouse_released=1;
        }

        else if (mouse_x> xchroma+65 && mouse_x< xchroma+115 )//YELLOW
        {
            if (index_inspekt==1)
            {
                show_who_is_in_dock_color(dock_color_selected,3);
            }
            couleur_to_affect=3;
            bool there_is_asel_chan=0;
            switch(index_paste_on_the_fly)
            {
            case 0:
                for(int p=1; p<513; p++)
                {
                    if(Selected_Channel[p]==1)
                    {
                        there_is_asel_chan=1;
                        break;
                    }
                }
                if(there_is_asel_chan==1&& (index_do_dock==1|| index_do_modify==1 || index_do_report==1))
                {
                    index_do_affect_color_trichro=1;
                    index_ask_confirm=1;
                }
                else
                {
                    sprintf(string_Last_Order,"No channel selected to store as color");
                }
                break;
            case 1:
                if(index_blind==0)
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferSaisie[p]=my_yellow;
                        }
                    }
                }
                else
                {
                    for(int p=1; p<513; p++)
                    {
                        if(Selected_Channel[p]==1)
                        {
                            bufferBlind[p]=my_yellow;
                        }
                    }
                }
                sprintf(string_Last_Order,"Pasted On the Fly YELLOW result");
                break;
            default:
                break;
            }
            mouse_released=1;
        }
    }



    if(mouse_x> xchroma+140-10 && mouse_x< xchroma+140+10 && mouse_y>ychroma+110-10 && mouse_y<ychroma+110+10)
    {

        if(midi_send_out[497]==0)
        {
            midi_send_out[497]=1;
        }
        else if(midi_send_out[497]==1)
        {
            midi_send_out[497]=0;
        }
        mouse_released=1;
    }

    raccrochage_midi_logical_circulaire (xchroma-6, ychroma, 497, 125, 125);




    for (int dock_color=0; dock_color<4; dock_color++)
    {
        if(mouse_x>xchroma-130+(65*dock_color) && mouse_x<xchroma-80+(65*dock_color) && mouse_y>ychroma+215 && mouse_y<ychroma+235)
        {
            if( Midi_Faders_Affectation_Type!=0)
            {
                if(dock_color==0 && Midi_Faders_Affectation_Type==2)
                {
                    attribute_midi_to_control(949,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    attribute_midi_solo_affectation(949+dock_color, Midi_Faders_Affectation_Mode);
                }
            }
            else
            {
                dock_color_selected=dock_color;
                load_etat_picker_dans_dockcolor(dock_color_selected);
                sprintf(string_Last_Order,">>Dock Color Selected %d",(dock_color_selected+1));
                mouse_released=1;
            }
        }
    }
    for (int dock_colortwo=0; dock_colortwo<4; dock_colortwo++)
    {
        if(mouse_x>xchroma-130+(65*dock_colortwo) && mouse_x<xchroma-80+(65*dock_colortwo) && mouse_y>ychroma+255 && mouse_y<ychroma+275)
        {
            if(Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(949+(dock_colortwo+4), Midi_Faders_Affectation_Mode);
            }
            else
            {
                dock_color_selected=dock_colortwo+4;
                load_etat_picker_dans_dockcolor(dock_color_selected);
                sprintf(string_Last_Order,">>Dock Color Selected %d",dock_color_selected+1);
                mouse_released=1;
            }
        }
    }

    if(mouse_x>xchroma-150 && mouse_x<xchroma-20 && mouse_y>ychroma+300 && mouse_y< ychroma+330)
    {
        if(mouse_b&1 &&  mouse_released==0 && window_focus_id==902)
        {
            index_paste_on_the_fly=toggle(index_paste_on_the_fly);
            mouse_released=1;
        }
    }


    if(show_gel_list==1)
    {

        if(mouse_x>xchroma+180 && mouse_x<xchroma+250 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
        {
            index_gel_type_selected++;
            if(index_gel_type_selected>3)index_gel_type_selected=0;
            mouse_released=1;
        }
        if(mouse_x>xchroma+260 && mouse_x<xchroma+330 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
        {
            show_designer_list=toggle(show_designer_list);
            switch(show_designer_list)
            {
            case 0://numerical order
                break;
            case 1://designer order
                break;
            default:
                break;
            }
            mouse_released=1;
        }

        if(mouse_x>xchroma+340 && mouse_x<xchroma+390 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
        {
            call_ref_number=atoi(numeric);
            mouse_released=1;
            if(call_ref_number<10000 && call_ref_number!=0)
            {

                for (int i=0; i<10000; i++)
                {
                    if(refs_of_gels[index_gel_type_selected][i]==call_ref_number )
                    {
                        gel_position[index_gel_type_selected]=i;
                        report_gels_to_rvb_trichro(index_gel_type_selected,gel_position[index_gel_type_selected]);
                        break;
                    }
                }
                reset_numeric_entry();
            }

        }
        if(mouse_y>ychroma-187 && mouse_y<ychroma-163)
        {
            if(mouse_x>xchroma+398 && mouse_x<xchroma+422)
            {
                if(gel_position[index_gel_type_selected]>10)gel_position[index_gel_type_selected]-=10;
                mouse_released=1;
            }
            if(mouse_x>xchroma+428 && mouse_x<xchroma+452)
            {
                if(gel_position[index_gel_type_selected]<10000-10)gel_position[index_gel_type_selected]+=10;
                mouse_released=1;
            }
        }

        if(mouse_x>xchroma+510 && mouse_x<xchroma+550 && mouse_y>ychroma-185 && mouse_y<ychroma-165)
        {
            index_use_transmission=toggle(index_use_transmission);
            mouse_released=1;
        }

        for(int i=0; i<30; i++)
        {
            if( mouse_x>xchroma+175 && mouse_x<xchroma+485 && mouse_y>ychroma-150+(i*16) && mouse_y<ychroma-134+(i*16) )
            {
                call_ref_number=refs_of_gels[index_gel_type_selected][gel_position[index_gel_type_selected]+i];
                report_gels_to_rvb_trichro(index_gel_type_selected,gel_position[index_gel_type_selected]+i);
                mouse_released=1;
            }
        }
    }


    return(0);
}
