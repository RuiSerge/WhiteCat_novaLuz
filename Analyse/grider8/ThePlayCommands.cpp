int ThePlayCommands(int xb, int yb, int num_grider)
{
    play_button_view(xb+10,yb,grider_is_playing[num_grider]);
    seek_button_view(xb+40,yb,0);
    minichiffre.Print(ol::ToString(index_grider_seek_pos[num_grider]+1),xb+65,yb);
    playstop_button_view(xb+70,yb,grider_autostopmode[num_grider]);

    if(window_focus_id==W_GRID && mouse_y>yb && mouse_y<yb+20 )
    {
        if(mouse_x>xb+10 && mouse_x<xb+30 )// PLAY GRID
        {
            char sttmp[24];
            sprintf(sttmp,"Play GridPl.%d",num_grider+1);
            show_type_midi(1492+num_grider,sttmp );

        }
        else if(mouse_x>xb+40 && mouse_x<xb+60 )//SEEK GRID
        {
            char sttmp[24];
            sprintf(sttmp,"Seek GridPl.%d",num_grider+1);
            show_type_midi(1496+num_grider,sttmp );
            if(mouse_b&1)
            {
                seek_button_view(xb+40,yb,1);
            }
        }



        else if(mouse_x>xb+70 && mouse_x<xb+90 )//AUTO STOP PLAY GRID
        {
            char sttmp[24];
            sprintf(sttmp,"AutoStop GridPl.%d",num_grider+1);
            show_type_midi(1500+num_grider,sttmp );
        }
    }//fin check y
    return(0);
}
