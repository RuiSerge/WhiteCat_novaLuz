int do_logical_TheGrid_commands ( int xb, int yb, int num_grid_player)
{

    if(mouse_x>xb-5 && mouse_x<xb+127+5 && mouse_y>=yb+30 && mouse_y<=yb+30+10 )
    {
        if(Midi_Faders_Affectation_Type!=0)//config midi
        {
            attribute_midi_solo_affectation(1508+num_grid_player,Midi_Faders_Affectation_Mode);
        }
        else
        {
            if(grid_player_slave[num_grid_player]==0)
            {
                set_mouse_range(xb-5,yb+30,xb+127+5,yb+30+10);
                grid_crossfade_speed[num_grid_player]=mouse_x-xb;
                if(grid_crossfade_speed[num_grid_player]<0)
                {
                    grid_crossfade_speed[num_grid_player]=0;
                }
                else  if(grid_crossfade_speed[num_grid_player]>127)
                {
                    grid_crossfade_speed[num_grid_player]=127;
                }
                //integration gridplayer 1 au sequenciel
                if(index_link_speed_crossfade_to_gpl1==1 && num_grid_player==0)
                {
                    grid_crossfade_speed[0]=crossfade_speed;
                    midi_levels[1508]=crossfade_speed;
                }
                gridder_prepare_cross(num_grid_player,index_grider_selected[num_grid_player],index_grider_step_is[num_grid_player]);
            }
        }
    }

    if(mouse_x>xb+150 && mouse_x<xb+150+40 && mouse_y>yb+25 && mouse_y<yb+25+15)
    {
        if(mouse_released==0)
        {
            if(Midi_Faders_Affectation_Type!=0)//config midi
            {
                attribute_midi_solo_affectation(1504+num_grid_player,Midi_Faders_Affectation_Mode);
            }
            else
            {
                grid_player_slave[num_grid_player]=toggle(grid_player_slave[num_grid_player]);
            }
            mouse_released=1;
        }
    }




    for(int sp=0; sp<4; sp++)
    {
        if( mouse_x>xb && mouse_x<xb+10 && mouse_y>yb+70+(sp*20) && mouse_y<yb+70+(sp*20)+10 )
        {
            if( mouse_released==0 )
            {
                if( Midi_Faders_Affectation_Type!=0)
                {
                    attribute_midi_solo_affectation(1512+(sp*4)+num_grid_player,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    switch(sp)
                    {
                    case 0:
                        grider_goto_mode[num_grid_player]=toggle(grider_goto_mode[num_grid_player]);
                        break;
                    case 1:
                        grider_count_mode[num_grid_player]=toggle(grider_count_mode[num_grid_player]);
                        break;
                    case 2:
                        grider_seekto_mode[num_grid_player]=toggle(grider_seekto_mode[num_grid_player]);
                        break;
                    case 3:
                        grider_stoplay_mode[num_grid_player]=toggle(grider_stoplay_mode[num_grid_player]);
                        break;
                    default:
                        break;
                    }
                }
                mouse_released=1;
            }
        }
    }//fin boucle4

    if( index_enable_edit_Grider==1  && mouse_x>xb+105 && mouse_x<xb+105+30 && mouse_y>yb+70 && mouse_y<yb+70+15 )
    {
        if(  mouse_released==0 )
        {
            grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]=atoi(numeric)-1;
            if(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]<0)
            {
                grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]=-1;   //désaffectation
            }
            if(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]>127)
            {
                grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][0]=127;
            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }
    if(index_enable_edit_Grider==1  &&  mouse_x>xb+150 && mouse_x<xb+150+40 && mouse_y>yb+70 && mouse_y<yb+70+15 )
    {
        if( mouse_released==0)
        {
            grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]=atoi(numeric)-1;
            if(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]<0)
            {
                grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]=-1;   //désaffectation
            }
            if(grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]>1023)
            {
                grid_goto[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]][1]=1023;
            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }

    if( index_enable_edit_Grider==1  && mouse_x>xb+150 && mouse_x<xb+150+40 && mouse_y>yb+90 && mouse_y<yb+90+15  )
    {
        if( mouse_released==0)
        {
            grid_count[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=atoi(numeric);
            if(grid_count[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]<0)
            {
                grid_count[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=0;
            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }


    if( index_enable_edit_Grider==1  && mouse_x>xb+150 && mouse_x<xb+150+40 && mouse_y>yb+110 && mouse_y<yb+110+15  )
    {
        if( mouse_released==0)
        {
            grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=atoi(numeric)-1;
            if(grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]<0)
            {
                grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=-1;   //désaffectation
            }
            if(grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]>1023)
            {
                grid_seekpos[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=1023;
            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }

    if( index_enable_edit_Grider==1  && mouse_x>xb+100 && mouse_x<xb+100+90 && mouse_y>yb+130 && mouse_y<yb+130+15 && mouse_b&1 && mouse_released==0)
    {
        grid_stoplay[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]=toggle(grid_stoplay[index_grider_selected[num_grid_player]][index_grider_step_is[num_grid_player]]);
        mouse_released=1;
    }
    return(0);
}
