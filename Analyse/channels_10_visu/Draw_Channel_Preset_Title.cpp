int Draw_Channel_Preset_Title(int xchan, int ychan, int prst_v)
{

    Rect Background_title(Vec2D(xchan+40,ychan),Vec2D(210,20));
    Background_title.SetRoundness(5);
    Background_title.Draw(CouleurLigne.WithAlpha(0.05));

    neuromoyen.Print( ol::ToString(prst_v+1), xchan+25,ychan+15);
    petitpetitchiffre.Print(ol::ToString(channel_number_in_View[prst_v]),xchan+35,ychan+5);
    neuromoyen.Print( channel_view_Name[prst_v], xchan+45,ychan+15);
    Line(Vec2D(xchan,ychan+25),Vec2D(xchan+600,ychan+25)).Draw(CouleurLigne);


    Rect Build(Vec2D(xchan+520,ychan),Vec2D(55,20));
    Build.SetRoundness(3);

    if(prst_v!=0)//pas la vue patch�e
    {
        Rect M(Vec2D(xchan+435,ychan),Vec2D(20,20));
        M.SetRoundness(3);
        Rect F(Vec2D(xchan+460,ychan),Vec2D(20,20));
        F.SetRoundness(3);

        if(channel_view_mode_builder[prst_v]==1 && channel_view_type_of_behaviour[prst_v]==0)
        {
            M.Draw(CouleurBlind);
            F.Draw(CouleurFader);
        }

        switch(channel_view_type_of_behaviour[prst_v])
        {
        case 1:
            M.Draw(CouleurBlind);
            break;
        case 2:
            F.Draw(CouleurFader);
            break;
        default:
            break;
        }

        M.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitpetitchiffregris.Print("M",xchan+440,ychan+13);


        F.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitpetitchiffregris.Print("F",xchan+467,ychan+13);


        Rect All(Vec2D(xchan+485,ychan),Vec2D(30,20));
        All.SetRoundness(3);
        All.Draw(CouleurBlind.WithAlpha( channel_view_mode_builder[prst_v]));
        All.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitpetitchiffregris.Print("ALL",xchan+490,ychan+13);



        Build.DrawOutline(CouleurLigne.WithAlpha(0.5));
        petitpetitchiffregris.Print("Build View",xchan+524,ychan+13);

    }


    if(window_focus_id==0 )
    {
        if(mouse_y>ychan && mouse_y<ychan+20  )
        {
            if(mouse_x> xchan+40 && mouse_x<xchan+250)
            {
                Background_title.DrawOutline(CouleurLigne);
            }

            else if(mouse_x>  xchan+520 && mouse_x<xchan+575 && prst_v!=0 )
            {
                Build.DrawOutline(CouleurFader.WithAlpha(0.5));
                //logique a garder inside sinon ca plante grave !
                if(mouse_button==1 && mouse_released==0)
                {
                    channel_view_is=prst_v;
                    if(index_do_dock==1)
                    {
                        if(channel_view_type_of_behaviour[channel_view_is]==0 &&  channel_view_mode_builder[channel_view_is]==0)
                        {
                            index_ask_record_selection_of_view=1 ;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                        else
                        {
                            index_ask_build_view=1;
                            index_ask_confirm=1;
                            mouse_released=1;
                        }
                    }

                    else if(index_do_modify==1)
                    {
                        index_ask_modify_selection_of_view=1 ;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                    else if(index_do_report==1)
                    {
                        index_ask_report_selection_of_view=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                    else if(index_main_clear==1)
                    {
                        index_ask_clear_selection_of_view=1;
                        index_ask_confirm=1;
                        mouse_released=1;
                    }
                }
            }

        }
    }

    return(0);
}
