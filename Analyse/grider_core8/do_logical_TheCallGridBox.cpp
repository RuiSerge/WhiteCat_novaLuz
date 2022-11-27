int do_logical_TheCallGridBox(int xb, int yb, int num_grider)
{

    if(mouse_x>xb+10 && mouse_x<xb+10+50 && mouse_y>yb && mouse_y<yb+20)
    {
        if(mouse_released==0)
        {
            if( Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(1528+num_grider,Midi_Faders_Affectation_Mode);
            }
            else
            {
                if(numeric_postext>0)
                {
                    int temp_num_grid=atoi(numeric);
                    if(temp_num_grid>0 && temp_num_grid<128)
                    {
                        bool was_playing=grider_is_playing[num_grider];
                        grider_is_playing[num_grider]=0;
                        grid_niveauX1[num_grider]=255;
                        grid_niveauX2[num_grider]=0;
                        grid_floatX1[num_grider]=255.0;
                        grid_floatX2[num_grider]=0.0;
                        grid_fraction_X2_in[num_grider]=0.0;
                        grid_fraction_X1_out[num_grider]=0.0;

                        index_grider_selected[num_grider]=temp_num_grid-1;//avant modif du 5 nov que cette ligne la

                        index_grider_step_is[num_grider]=0;
                        gridder_prepare_cross(num_grider, index_grider_selected[num_grider], index_grider_step_is[num_grider]);


                        if(grider_seekto_mode[num_grider]==1 && grid_seekpos[index_grider_selected[num_grider]][index_grider_step_is[num_grider]]>0)//seek position original fonction
                        {
                            index_grider_seek_pos[num_grider]=grid_seekpos[index_grider_selected[num_grider]][index_grider_step_is[num_grider]];
                        }

                        if(was_playing==1)
                        {
                            grider_is_playing[num_grider]=1;
                        }

                        reset_numeric_entry();
                    }
                }
                else if(index_main_clear==1)
                {
                    grid_to_clear=index_grider_selected[num_grider];
                    step_grid_to_clear=index_grider_step_is[index_grider_selected[num_grider]];
                    index_ask_confirm=1;
                    index_clear_a_grid=1;
                }
            }
            mouse_released=1;
        }
    }

    if(mouse_x>xb+70 && mouse_x<xb+70+170 && mouse_y>yb && mouse_y<yb+20 && index_type==1 && mouse_released==0)
    {
        for(int tt=0; tt<24; tt++)
        {
            grider_name[index_grider_selected[num_grider]][tt]=numeric[tt];
        }
        grider_name[index_grider_selected[num_grider]][24]='\0';
        reset_numeric_entry();
        numeric_postext=0;
        if(index_text_auto_close==1)
        {
            index_type=0;
        }
        mouse_released=1;
    }


    if(mouse_x>xb+265-12 && mouse_x<xb+265+12 && mouse_y>yb+10-12 && mouse_y<yb+10+12)
    {

        if(mouse_released==0)
        {
            if( Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(1476+num_grider,Midi_Faders_Affectation_Mode);
            }
            else
            {
                if(index_grider_selected[num_grider]>0)
                {
                    index_grider_selected[num_grider]--;
                }
            }
            mouse_released=1;
        }
    }


    if( mouse_x>xb+295-12 && mouse_x<xb+295+12 && mouse_y>yb+10-12 && mouse_y<yb+10+12)
    {

        if( mouse_released==0)
        {
            if(Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(1480+num_grider,Midi_Faders_Affectation_Mode);
            }
            else
            {
                if(index_grider_selected[num_grider]<127)
                {
                    index_grider_selected[num_grider]++;
                }
            }
            mouse_released=1;
        }
    }
    return(0);
}
