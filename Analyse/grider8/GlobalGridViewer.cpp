int GlobalGridViewer(int xb, int yb)
{
    Line(Vec2D(xb,yb),Vec2D(xb+largeurGrider,yb)).Draw(CouleurLigne);
    neuromoyen.Print("Grid",xb,yb+23);
    Rect GriderNum(Vec2D(xb+40,yb+10),Vec2D(50,20));
    GriderNum.SetRoundness(5);
    GriderNum.DrawOutline(CouleurLigne.WithAlpha(0.5));
    neuromoyen.Print(ol::ToString(grid_selected_for_view +1),(xb+50), (yb+23));
    if(window_focus_id==W_GRID && mouse_x>xb+40 && mouse_x<xb+90 && mouse_y>yb+10 && mouse_y<yb+30 )
    {
        GriderNum.DrawOutline(CouleurLigne);
    }

    neuromoyen.Print("Step",xb+110,yb+23);
    Rect GriderSt(Vec2D(xb+150,yb+10),Vec2D(50,20));
    GriderSt.SetRoundness(5);
    GriderSt.DrawOutline(CouleurLigne.WithAlpha(0.5));
    neuromoyen.Print(ol::ToString(grid_step_view+1),(xb+160), (yb+23));
    if(window_focus_id==W_GRID && mouse_x>xb+150 && mouse_x<xb+200 && mouse_y>yb+10 && mouse_y<yb+30 )
    {
        GriderSt.DrawOutline(CouleurLigne);
    }

    previous_button_view(xb+220,yb+10,0);
    next_button_view(xb+250,yb+10,0);

    int def_nombre_grilles_previsu=largeurGrider/((grider_nb_col*5)+20);
    if(def_nombre_grilles_previsu==10)
    {
        def_nombre_grilles_previsu-=2;
    }
    else if(def_nombre_grilles_previsu>10 && def_nombre_grilles_previsu<18)
    {
        def_nombre_grilles_previsu-=1;
    }
    else if(def_nombre_grilles_previsu>15)
    {
        def_nombre_grilles_previsu-=2;
    }


    int tmpx=0;
    int tmpy=0;
    int tempfu=0;
    int tempstep=0;
    int tmpblx=0;
    int tmpbly=0;

    for(int pos=0; pos<def_nombre_grilles_previsu; pos++)
    {


        if(grid_step_view+pos<1023)
        {
            for (int co=0; co<=grider_nb_col; co++)
            {
                Line(Vec2D(20+xb+(co*5)+(pos*grider_nb_col*5)+(20*pos),yb+40),Vec2D(20+xb+(co*5)+(pos*grider_nb_col*5)+(20*pos),yb+40+(grider_nb_row*5))).Draw(CouleurLigne.WithAlpha(0.5));
            }

            for(int lo=0; lo<=grider_nb_row; lo++)
            {
                Line(Vec2D(20+xb+(pos*grider_nb_col*5)+(20*pos),yb+40+(lo*5)),Vec2D(20+xb+(pos*grider_nb_col*5)+(grider_nb_col*5)+(20*pos),yb+40+(lo*5))).Draw(CouleurLigne.WithAlpha(0.5));
            }

            for(int fu=0; fu<grider_nb_col; fu++)
            {
                for(int lo=0; lo<grider_nb_row; lo++)
                {
                    tmpx=20+xb+(fu*5)+(pos*grider_nb_col*5)+(20*pos);
                    tmpy=yb+40+(lo*5);
                    tempfu=fu+(lo*grider_nb_col);
                    tempstep=grid_step_view+pos;
                    tmpblx=20+xb+(pos*grider_nb_col*5)+(20*pos);
                    tmpbly=yb+60+(grider_nb_row*5);
                    if(grid_times[grid_selected_for_view][grid_step_view+pos][0]>0 || grid_times[grid_step_view+pos][tempstep][2]>0)
                    {
                        minichiffrerouge.Print(string_grid_view_timing_global[pos],tmpblx,yb+38);
                    }

                    if(grid_levels[grid_selected_for_view][tempstep][tempfu]==255)
                    {
                        Rect QuadChF(Vec2D(tmpx,tmpy),Vec2D(5,5));
                        QuadChF.Draw(CouleurFader);
                    }
                    else if(grid_levels[grid_selected_for_view][tempstep][tempfu]>0
                            && grid_levels[grid_selected_for_view][grid_step_view+pos][tempfu]<255)
                    {
                        Rect QuadCh(Vec2D(tmpx,tmpy),Vec2D(5,5));
                        QuadCh.Draw(CouleurGreen);
                    }
                }
            }
            neuromoyen.Print(ol::ToString(tempstep+1),tmpblx,tmpbly);
            Rect AutoStopB(Vec2D(tmpblx+40,tmpbly-10),Vec2D(30,10));
            AutoStopB.Draw(CouleurBlind.WithAlpha(grid_stoplay[grid_selected_for_view][tempstep]));

            minichiffre.Print(string_grid_view_timing_global[pos],tmpblx,tmpbly+10);
            minichiffregris.Print("Goto",tmpblx,tmpbly+20);
            minichiffregris.Print(ol::ToString(grid_goto[grid_selected_for_view][tempstep][0]+1),20+tmpblx,tmpbly+20);
            minichiffregris.Print(ol::ToString(grid_goto[grid_selected_for_view][tempstep][1]+1),40+tmpblx,tmpbly+20);
            minichiffregris.Print("Seek",tmpblx,tmpbly+30);
            minichiffregris.Print(ol::ToString(grid_seekpos[grid_selected_for_view][tempstep]+1),40+tmpblx,tmpbly+30);



        }
    }



    return(0);
}
