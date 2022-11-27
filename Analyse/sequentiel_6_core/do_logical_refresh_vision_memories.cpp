int do_logical_refresh_vision_memories( int x_seq, int y_seq)
{
    if(mouse_y>y_seq+110 && mouse_y<y_seq+140)
    {
        if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
        {
            affect_time_entry_to_mem(2,position_preset);
            mouse_released=1;
        }
        if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
        {
            affect_time_entry_to_mem(3,position_preset);
            mouse_released=1;
        }
        if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
        {
            if(index_go==0 && index_pause==0 && index_go_back==0 )
            {

                call_stage=1;
                call_preset=0;
                do_call_time_and_rec_f1_f2_f3(position_onstage);
                mouse_released=1;
            }
        }
        if(mouse_x> x_seq+170 && mouse_x<x_seq+180)//exclude mem from cuelist
        {
            MemoiresExclues[position_onstage]=toggle(MemoiresExclues[position_onstage]);
            mouse_released=1;
        }

        if(mouse_x> x_seq+185 && mouse_x<x_seq+185+40)//LINKS
        {
            reset_indexs_confirmation();
            index_do_link_memonstage=1;
            index_ask_confirm=1;
            mouse_released=1;
        }
        if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
        {
            affect_banger_number=atol(numeric);
            if(affect_banger_number>=0 && affect_banger_number<128)
            {
                reset_indexs_confirmation();
                index_do_banger_memonstage=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: banger is between 1 and 127, 0 to desaffect !");
            }
        }

        if(mouse_x> x_seq+275 && mouse_x<x_seq+300)//Gridplayer
        {
            gpl1_affect_step_to_mem=atoi(numeric);
            if(gpl1_affect_step_to_mem>=0 && gpl1_affect_step_to_mem<=1024)
            {
                reset_indexs_confirmation();
                index_do_affect_step_gridplayer_to_mem=1;
                index_mem_to_be_affected_by_gpl=position_onstage;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: step is between 1 and 1024, 0 to desaffect !");
            }
        }

        if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
        {

            if(index_type==1)
            {

                if(mouse_y>y_seq+110 && mouse_y<y_seq+110+15)
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        descriptif_memoires[position_onstage][tt]=numeric[tt];
                    }
                    descriptif_memoires[position_onstage][24]='\0';
                }
                else
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        annotation_memoires[position_onstage][tt]=numeric[tt];
                    }
                    annotation_memoires[position_onstage][24]='\0';
                }

                reset_numeric_entry();
                numeric_postext=0;
                someone_changed_in_sequences=1;//icat
                mouse_released=1;
            }
            if(index_text_auto_close==1)
            {
                index_type=0;
            }

        }
    }

    if(mouse_y>y_seq+140 && mouse_y<y_seq+170)
    {
        if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
        {
            affect_time_entry_to_mem(0,position_preset);
            mouse_released=1;
        }
        if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
        {
            affect_time_entry_to_mem(1,position_preset);
            mouse_released=1;
        }
        if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
        {
            if(index_go==0 && index_pause==0 && index_go_back==0 )//pas de cross en cours
            {

                call_preset=1;
                call_stage=0;
                do_call_time_and_rec_f1_f2_f3(position_preset);

                mouse_released=1;
            }
            else if((index_go==1 || index_pause==1 ) && index_go_back==0 ) //cross ou pause en cours
            {
                reset_indexs_confirmation();
                index_do_jump_while_cross=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
        }
        if(mouse_x> x_seq+170 && mouse_x<x_seq+180)//exclude mem from cuelist
        {
            MemoiresExclues[position_preset]=toggle(MemoiresExclues[position_preset]);
            mouse_released=1;
        }

        if(mouse_x> x_seq+185  && mouse_x<x_seq+180+35)//LINKS
        {
            reset_indexs_confirmation();
            index_do_link_memonpreset=1;
            index_ask_confirm=1;
            mouse_released=1;
        }
        if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
        {
            affect_banger_number=atol(numeric);
            if(affect_banger_number>=0 && affect_banger_number<128)
            {
                reset_indexs_confirmation();
                index_do_banger_memonpreset=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: banger is between 1 and 127 !");
            }
        }
        if(mouse_x> x_seq+275 && mouse_x<x_seq+300)//Gridplayer
        {
            gpl1_affect_step_to_mem=atoi(numeric);
            if(gpl1_affect_step_to_mem>=0 && gpl1_affect_step_to_mem<1024)
            {
                reset_indexs_confirmation();
                index_do_affect_step_gridplayer_to_mem=1;
                index_mem_to_be_affected_by_gpl=position_preset;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: step is between 1 and 1023, 0 to desaffect !");
            }
        }
        if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
        {
            if(index_type==1)
            {
                if(mouse_y>y_seq+140 && mouse_y<y_seq+155)
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        descriptif_memoires[position_preset][tt]=numeric[tt];
                    }
                    descriptif_memoires[position_preset][24]='\0';
                }
                else
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        annotation_memoires[position_preset][tt]=numeric[tt];
                    }
                    annotation_memoires[position_preset][24]='\0';
                }
                someone_changed_in_sequences=1;//icat
                reset_numeric_entry();
                numeric_postext=0;
                if(index_text_auto_close==1)
                {
                    index_type=0;
                }
                mouse_released=1;
            }

        }
    }
    if(mouse_y>y_seq+80 && mouse_y< y_seq+100)
    {
        if(mouse_x> x_seq+170 && mouse_x<x_seq+180)//exclude mem from cuelist
        {
            MemoiresExclues[mem_before_one]=toggle(MemoiresExclues[mem_before_one]);
            mouse_released=1;
        }

        if(mouse_x> x_seq+185  && mouse_x<x_seq+180+35)//LINKS
        {
            reset_indexs_confirmation();
            index_do_link_membefore=1;
            index_ask_confirm=1;
            mouse_released=1;
        }

        if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
        {
            affect_banger_number=atol(numeric);
            if(affect_banger_number>=0 && affect_banger_number<128)
            {
                reset_indexs_confirmation();
                index_do_banger_membeforeone=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: banger is between 1 and 127 !");
            }
        }
        if(mouse_x> x_seq+275 && mouse_x<x_seq+300)//Gridplayer
        {
            gpl1_affect_step_to_mem=atoi(numeric);
            if(gpl1_affect_step_to_mem>=0 && gpl1_affect_step_to_mem<1024)
            {
                reset_indexs_confirmation();
                index_do_affect_step_gridplayer_to_mem=1;
                index_mem_to_be_affected_by_gpl=mem_before_one;
                index_ask_confirm=1;
                mouse_released=1;
            }
            else
            {
                sprintf(string_Last_Order,">> Wrong entry: step is between 1 and 1023, 0 to desaffect !");
            }
        }
        if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
        {
            if(index_type==1)
            {
                if(mouse_y>y_seq+80 && mouse_y<y_seq+95)
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        descriptif_memoires[mem_before_one][tt]=numeric[tt];
                    }
                    descriptif_memoires[mem_before_one][24]='\0';
                }
                else
                {
                    for(int tt=0; tt<24; tt++)
                    {
                        annotation_memoires[mem_before_one][tt]=numeric[tt];
                    }
                    annotation_memoires[mem_before_one][24]='\0';
                }
                reset_numeric_entry();
                numeric_postext=0;
                if(index_text_auto_close==1)
                {
                    index_type=0;
                }
                mouse_released=1;
            }
        }
    }


    int index_nbre_mem_visues=0;
    for(int memsearch=position_preset+1; memsearch<10000; memsearch++)
    {
        if(memsearch>=9999)
        {
            memsearch=0;
        }
        if(MemoiresExistantes[memsearch]==1 && index_nbre_mem_visues<nbre_memoires_visualisables_en_preset)
        {
            index_nbre_mem_visues++;

            if(mouse_y>y_seq+145+(35*index_nbre_mem_visues)  && mouse_y< y_seq+145+30+(35*index_nbre_mem_visues))
            {

                if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
                {
                    call_stage=0;
                    call_preset=0;
                    do_call_time_and_rec_f1_f2_f3(memsearch);
                    mouse_released=1;
                }
                if(mouse_x> x_seq+170 && mouse_x<x_seq+180)//exclude mem from cuelist
                {
                    MemoiresExclues[memsearch]=toggle(MemoiresExclues[memsearch]);
                    mouse_released=1;
                }

                if(mouse_x> x_seq+185  && mouse_x<x_seq+180+35)//LINKS
                {
                    other_mem_in_loop=memsearch;
                    reset_indexs_confirmation();
                    index_do_link_memother=1;
                    index_ask_confirm=1;
                    mouse_released=1;
                }
                if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
                {
                    affect_banger_number=atol(numeric);
                    if(affect_banger_number>=0 && affect_banger_number<128)
                    {
                        other_mem_in_loop=memsearch;
                        reset_indexs_confirmation();
                        index_do_banger_memother=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                    else
                    {
                        sprintf(string_Last_Order,">> Wrong entry: banger is between 1 and 127 !");
                    }
                }
                if(mouse_x> x_seq+275 && mouse_x<x_seq+300)//Gridplayer
                {
                    gpl1_affect_step_to_mem=atoi(numeric);
                    if(gpl1_affect_step_to_mem>=0 && gpl1_affect_step_to_mem<1024)
                    {
                        reset_indexs_confirmation();
                        index_do_affect_step_gridplayer_to_mem=1;
                        index_mem_to_be_affected_by_gpl=memsearch;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                    else
                    {
                        sprintf(string_Last_Order,">> Wrong entry: step is between 1 and 1023, 0 to desaffect !");
                    }
                }
                if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
                {
                    if(index_type==1)
                    {

                        if(mouse_y> y_seq+140+(35*index_nbre_mem_visues) && mouse_y < y_seq+140+(35*index_nbre_mem_visues)+15)
                        {
                            for(int tt=0; tt<24; tt++)
                            {
                                descriptif_memoires[memsearch][tt]=numeric[tt];
                            }
                            descriptif_memoires[memsearch][24]='\0';
                        }
                        else
                        {
                            for(int tt=0; tt<24; tt++)
                            {
                                annotation_memoires[memsearch][tt]=numeric[tt];
                            }
                            annotation_memoires[memsearch][24]='\0';
                        }
                        reset_numeric_entry();
                        numeric_postext=0;
                        if(index_text_auto_close==1)
                        {
                            index_type=0;
                        }
                        mouse_released=1;
                    }
                }
            }

            if(index_nbre_mem_visues>=nbre_memoires_visualisables_en_preset)
            {
                break;
            }

        }
    }

    return(0);
}
