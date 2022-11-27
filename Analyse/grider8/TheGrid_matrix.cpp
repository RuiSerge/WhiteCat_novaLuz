int TheGrid_matrix ( int xb, int yb,int num_grid_player)
{
    int grid_selected=index_grider_selected[num_grid_player];
    int gr_st_selected=index_grider_step_is[num_grid_player];

    for (int co=0; co<=grider_nb_col; co++)
    {
        Line(Vec2D(xb+(co*15),yb),Vec2D(xb+(co*15),yb+(grider_nb_row*15))).Draw(CouleurLigne.WithAlpha(0.5));
    }

    for(int lo=0; lo<=grider_nb_row; lo++)
    {
        Line(Vec2D(xb,yb+(lo*15)),Vec2D(xb+(grider_nb_col*15),yb+(lo*15))).Draw(CouleurLigne.WithAlpha(0.5));
    }

    int tmpx=0;
    int tmpy=0;
    int tempfu=0;
    for(int fu=0; fu<grider_nb_col; fu++)
    {
        for(int lo=0; lo<grider_nb_row; lo++)
        {
            tmpx=xb+(fu*15);
            tmpy=yb+(lo*15);
            tempfu=(fu+(lo*grider_nb_col));
            Rect QuadCh(Vec2D(tmpx,tmpy),Vec2D(15,15));
            if(grid_levels[grid_selected][gr_st_selected][(fu+(lo*grider_nb_col))]==255)
            {
                QuadCh.Draw(CouleurFader);
            }
            else if(grid_levels[grid_selected][gr_st_selected][tempfu]>0 && grid_levels[grid_selected][gr_st_selected][tempfu]<255)
            {
                QuadCh.Draw(CouleurGreen.WithAlpha(3*(1.0/255.0)*(grid_levels[grid_selected][gr_st_selected][tempfu])));
            }
            if(grid_levels[grid_selected][gr_st_selected-1][tempfu]>0)
            {
                Rect QuadPrev(Vec2D(tmpx,tmpy),Vec2D(5,5));
                QuadPrev.Draw(CouleurSurvol);
            }
            if(grid_levels[grid_in_preset[num_grid_player][0]][grid_in_preset[num_grid_player][1]][tempfu]>0)
            {
                Rect QuadNext(Vec2D(tmpx+10,tmpy),Vec2D(5,5));
                QuadNext.Draw(CouleurLigne);
            }
        }
    }

    Rect ShowOffset(Vec2D(0,0),Vec2D(15,15));
    for(int pr=0; pr<6; pr++)
    {
        if( draw_brush_type[pr]==1 && draw_get_gpl[pr]==num_grid_player+1)//si GPL tracké depuis DRAW
        {
            ShowOffset.MoveTo(Vec2D(xb+ (((draw_offset_gpl[pr]-1)%grider_nb_col)*15), yb+ (((draw_offset_gpl[pr]-1)/grider_nb_col)*15)   ));
            ShowOffset.SetLineWidth(2.0);
            ShowOffset.DrawOutline(CouleurLevel);
            minichiffre.Print(ol::ToString(pr+1), xb+ (((draw_offset_gpl[pr]-1)%grider_nb_col)*15), yb+ (((draw_offset_gpl[pr]-1)/grider_nb_col)*15)+7);
        }
    }

    if(window_focus_id==W_GRID )
    {
        if(mouse_x>=xb && mouse_x<=xb+(grider_nb_col*15) && mouse_y>=yb && mouse_y<=yb+(grider_nb_row*15))
        {
            int unite=((mouse_x-xb)/15)+1;
            int dizaine=((mouse_y-yb)/15);

            position_grid_editing=(dizaine*grider_nb_col)+unite-1;
            temoin_over_grid_channel=position_grid_editing+grider_begin_channel_is;
            Rect Backchiffres(Vec2D(mouse_x-5, mouse_y-25),Vec2D(40,25));
            Backchiffres.SetRoundness(5);
            Backchiffres.Draw(CouleurFond.WithAlpha(0.4));
            petitchiffre.Print(ol::ToString(temoin_over_grid_channel),mouse_x,mouse_y-15);
            if(grid_levels[grid_selected][gr_st_selected][temoin_over_grid_channel-1]>0)
            {
                char tmp_st[36];
                switch(dmx_view)
                {
                case 0:
                    sprintf(tmp_st,"OverChan: %d Level: %d",temoin_over_grid_channel,(int)(((float)grid_levels[grid_selected][gr_st_selected][temoin_over_grid_channel-1])/2.55));
                    break;
                case 1:
                    sprintf(tmp_st,"OverChan: %d Level: %d",temoin_over_grid_channel,grid_levels[grid_selected][gr_st_selected][temoin_over_grid_channel-1]);
                    break;
                default:
                    break;
                }
                neuromoyen.Print(tmp_st,mouse_x+10,mouse_y-5);
            }

        }
    }

    return(0);
}
