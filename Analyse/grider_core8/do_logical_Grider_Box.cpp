int do_logical_Grider_Box(int xb, int yb)
{


    for(int o=0; o<core_user_define_nb_gridplayers; o++)
    {
        if( mouse_x>xb+540+(o*15) && mouse_x<xb+540+(o*15)+10 && mouse_y>yb+20 && mouse_y<yb+20+10)
        {
            if( mouse_released==0)
            {
                if( Midi_Faders_Affectation_Type!=0)//config midi
                {
                    attribute_midi_solo_affectation(1472+o,Midi_Faders_Affectation_Mode);
                }
                else
                {
                    index_show_grid_player[o]=toggle(index_show_grid_player[o]);
                    refresh_hauteur_fenetre_grider();
                }
                mouse_released=1;
            }
        }
    }
    if( mouse_y>yb+15 && mouse_y<yb+15+20 )
    {
        if(mouse_x>xb+245 && mouse_x<xb+245+40 &&  index_enable_edit_Grider==1)//chan edit
        {
            if(mouse_released==0 )
            {
                int temp_begchan=atoi(numeric);
                if(temp_begchan>0 && temp_begchan<512)
                {
                    grider_begin_channel_is=temp_begchan;
                }
                reset_numeric_entry();
                mouse_released=1;
            }
        }
        if(mouse_x>xb+315 && mouse_x<xb+315+40 &&  index_enable_edit_Grider==1 )//col edit
        {
            if(mouse_released==0)
            {
                int temp_col=atoi(numeric);
                if(temp_col>0 && temp_col<=24)
                {
                    grider_nb_col=temp_col;
                }
                reset_numeric_entry();
                mouse_released=1;
            }
        }
        if(mouse_x>xb+385 && mouse_x<xb+385+40 &&  index_enable_edit_Grider==1)//rows edit
        {

            if(mouse_released==0 )
            {
                int temp_row=atoi(numeric);
                if(temp_row>0 && temp_row<=24)
                {
                    grider_nb_row=temp_row;
                    refresh_hauteur_fenetre_grider();
                }
                reset_numeric_entry();
                mouse_released=1;
            }
        }
        if(mouse_x>xb+430 && mouse_x<xb+430+50)//edit mode
        {
            if(mouse_released==0 )
            {
                index_enable_edit_Grider=toggle(index_enable_edit_Grider);
                if(index_enable_edit_Grider==0)
                {
                    for(int i=0; i<4; i++)
                    {
                        to_step_editing_mode[i]=0;
                    }
                }
                mouse_released=1;
            }

        }
    }


    switch(show_global_view_grider)
    {
    case 0:
        hauteurGlobalGridviewer=0;
        break;
    case 1:
        hauteurGlobalGridviewer=100+(grider_nb_row*size_preview_case);
        do_logical_GlobalGridViewer(xb,yb+40,size_preview_case);  //x y taille de previsu de la grille
        break;
    default:
        break;
    }

    if(mouse_x>xb+495 && mouse_x<xb+495+40 && mouse_y>yb+20 && mouse_y<yb+20+10)
    {
        show_global_view_grider=toggle(show_global_view_grider);
        refresh_hauteur_fenetre_grider();
        mouse_released=1;
    }



    int numerodeplayer_affiche=0;
    for(int yo=0; yo<core_user_define_nb_gridplayers; yo++)
    {
        if(index_show_grid_player[yo]==1)
        {
            do_logical_Grid_player(xb, yb+50+hauteurGlobalGridviewer+(numerodeplayer_affiche*(60+(grider_facteur_hauteur*size_grille))), yo);
            numerodeplayer_affiche++;
        }
    }

    return(0);
}
