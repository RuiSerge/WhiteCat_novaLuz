int do_logical_TheGrid_divers( int xb, int yb, int num_grid_player)
{
    if(mouse_x>xb+60 && mouse_x<xb+60+50 && mouse_y>yb && mouse_y<yb+30 &&  mouse_released==0)
    {

        index_do_dock=index_affect_color_to_dock;
        if(num_grid_player==gridplayer_to_affect_is)
        {
            reset_index_actions();
            index_do_dock=0;
        }
        else
        {
            reset_index_actions();
            reset_indexs_confirmation();
            gridplayer_to_affect_is=num_grid_player;
            index_do_dock=1;
        }


        mouse_released=1;
    }

    if(  index_enable_edit_Grider==1 && mouse_x>xb && mouse_x<xb+10 && mouse_y>yb+45 && mouse_y<yb+45+10 && mouse_released==0)
    {
        to_step_editing_mode[num_grid_player]=toggle(to_step_editing_mode[num_grid_player]);
        mouse_released=1;
    }

    if( index_enable_edit_Grider==1 && mouse_x>xb+60 && mouse_x<xb+60+40 && mouse_y>yb+45 && mouse_y<yb+45+15 && mouse_released==0  )
    {
        int tempstepto=atoi(numeric)-1;
        if(tempstepto>index_grider_step_is[num_grid_player] && tempstepto<1023)
        {
            index_StepTo[num_grid_player]=tempstepto;
        }
        reset_numeric_entry();
        mouse_released=1;
    }




    if(  index_enable_edit_Grider==1 && mouse_x>xb && mouse_x<xb+50 && mouse_y>yb+75 && mouse_y<yb+75+15 && mouse_released==0)
    {
        index_for_copy_grid=1;
        index_grid_tostep_or_not=to_step_editing_mode[num_grid_player];
        from_gridstep_to=index_StepTo[num_grid_player];
        destination_grid_for_copy= index_Grid_copyto[num_grid_player][0];
        destination_step_for_copy= index_Grid_copyto[num_grid_player][1];
        grid_to_clear=index_grider_selected[num_grid_player];       //utilisé pour menus confirm
        step_grid_to_clear=index_grider_step_is[num_grid_player]; //utilisé pour les menus confirm
        index_ask_confirm=1;
        mouse_released=1;
    }

    //insert mode
    if( index_enable_edit_Grider==1 &&  mouse_x>xb+55 && mouse_x<xb+55+50 && mouse_y>yb+75 && mouse_y<yb+75+15 )
    {
        index_for_insert_grid=1;
        destination_step_for_copy= index_Grid_copyto[num_grid_player][1];//le nombre de steps à insérer après la position actuelle
        grid_to_clear=index_grider_selected[num_grid_player];       //utilisé pour menus confirm
        step_grid_to_clear=index_grider_step_is[num_grid_player]; //utilisé pour les menus confirm
        index_ask_confirm=1;
        mouse_released=1;
    }
    if(index_enable_edit_Grider==1 && mouse_x>xb && mouse_x<xb+30 && mouse_y>yb+95 && mouse_y<yb+95+15 && mouse_released==0)
    {
        int tempstepto=atoi(numeric)-1;
        if(tempstepto>=0 && tempstepto<127)
        {
            index_Grid_copyto[num_grid_player][0]=tempstepto;
        }
        reset_numeric_entry();
        mouse_released=1;
    }
    if(index_enable_edit_Grider==1 && mouse_x>xb+45 && mouse_x<xb+45+40 && mouse_y>yb+95 && mouse_y<yb+95+15 && mouse_released==0 )
    {
        int tempstepto=atoi(numeric)-1;
        if(tempstepto>=0 && tempstepto<1023)
        {
            index_Grid_copyto[num_grid_player][1]=tempstepto;
        }
        reset_numeric_entry();
        mouse_released=1;
    }

    //snap fader
    if( index_enable_edit_Grider==1  &&  mouse_x>xb && mouse_x<xb+105 && mouse_y>yb+135 && mouse_y<yb+135+15 && mouse_released==0)
    {
        if(index_do_dock==1 && numeric_postext>0)
        {
            int getfad=atoi(numeric)-1;
            if(getfad>=0 && getfad<48)
            {
                GplSnapFader[num_grid_player]=getfad;
            }
            reset_numeric_entry();
            mouse_released=1;
            index_do_dock=0;
        }
        else//enregistrement
        {
            for(int i=0; i<513; i++)
            {
                if(i+grider_begin_channel_is+1<513)
                {
                    grid_levels[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][i]=FaderDoDmx[(GplSnapFader[num_grid_player])][i+grider_begin_channel_is];
                }
            }
            mouse_released=1;
        }
    }



    if(num_grid_player==0 )//asservissement speed au séquenciel
    {
        if(mouse_x>xb && mouse_x<xb+105 && mouse_y>yb+115 && mouse_y<yb+115+15 && mouse_released==0)
        {
            if(Midi_Faders_Affectation_Type!=0)
            {
                attribute_midi_solo_affectation(1540,Midi_Faders_Affectation_Mode);
            }

            else
            {
                index_link_speed_crossfade_to_gpl1=toggle(index_link_speed_crossfade_to_gpl1);
                if(index_link_speed_crossfade_to_gpl1==1)
                {
                    grid_crossfade_speed[0]=crossfade_speed;
                    midi_levels[1508]=crossfade_speed;
                }
            }
            mouse_released=1;
        }
    }

    return(0);
}
