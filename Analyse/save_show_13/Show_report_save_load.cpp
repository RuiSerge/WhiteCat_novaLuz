int Show_report_save_load()
{
    Rect Report_Save_Load(Vec2D(report_SL_X, report_SL_Y), Vec2D( 350,160));
    Report_Save_Load.SetRoundness(15);
    Report_Save_Load.SetLineWidth(epaisseur_ligne_fader*3);
    Report_Save_Load.Draw(CouleurFond);
    Report_Save_Load.DrawOutline(CouleurLigne);
    if(window_focus_id==W_SAVEREPORT)
    {
        Report_Save_Load.DrawOutline(CouleurFader);
    }

    Rect MinusPosMyRep(Vec2D(report_SL_X+290,report_SL_Y+76),Vec2D(50,20));
    MinusPosMyRep.SetRoundness(7.5);
    MinusPosMyRep.SetLineWidth(epaisseur_ligne_fader);
    Rect PlusPosMyRep(Vec2D(report_SL_X+290,report_SL_Y+106),Vec2D(50,20));
    PlusPosMyRep.SetRoundness(7.5);
    PlusPosMyRep.SetLineWidth(epaisseur_ligne_fader);

    for(int co=0; co<10; co++)
    {
        Rect AlarmFile(Vec2D((report_SL_X+5),(report_SL_Y+52+(10*co))),Vec2D(300,12));
        AlarmFile.SetRoundness(5);
        if(b_report_error[co+position_view_line]==1)
        {
            AlarmFile.Draw(Rgba::RED.WithAlpha(alpha_blinker));
        }
        petitchiffre.Print( ol::ToString(co+position_view_line),(report_SL_X+5), (report_SL_Y+60+(10*co)));
        petitchiffre.Print( string_save_load_report[co+position_view_line],(report_SL_X+30), (report_SL_Y+60+(10*co)));
    }

    MinusPosMyRep.Draw(CouleurFond);
    PlusPosMyRep.Draw(CouleurFond);
    if(window_focus_id==W_SAVEREPORT)
    {
        if(mouse_x>report_SL_X+290 && mouse_x<report_SL_X+340)
        {

            if( mouse_y>report_SL_Y+76 && mouse_y<report_SL_Y+96)
            {
                MinusPosMyRep.Draw(CouleurSurvol);
                if(mouse_button==1 &&  mouse_released==0 )
                {
                    MinusPosMyRep.Draw(CouleurFader);
                    position_view_line-=5;
                    if(position_view_line<0)
                    {
                        position_view_line=0;
                    }
                }
            }
            if( mouse_y>report_SL_Y+106 && mouse_y<report_SL_Y+136)
            {
                PlusPosMyRep.Draw(CouleurSurvol);
                if(mouse_button==1 &&  mouse_released==0 )
                {
                    PlusPosMyRep.Draw(CouleurFader);
                    position_view_line+=5;
                    if(position_view_line>(255-10))
                    {
                        position_view_line=(255-10);
                    }
                }
            }

        }

    }

    MinusPosMyRep.DrawOutline(CouleurLigne);
    PlusPosMyRep.DrawOutline(CouleurLigne);
    petitchiffre.Print("line -",report_SL_X+300, report_SL_Y+90);
    petitchiffre.Print("line +",report_SL_X+300, report_SL_Y+120);




    petitchiffre.Print( mondirectory,(report_SL_X+10+90), (report_SL_Y+20));
    petitchiffre.Print( nomduspectacle,(report_SL_X+10+90), (report_SL_Y+35));


    return(0);
}
