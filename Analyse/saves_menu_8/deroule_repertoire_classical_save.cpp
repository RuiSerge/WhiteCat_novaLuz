void deroule_repertoire_classical_save(int xrep, int yrep, const std::string label)
{
    const std::string name_of_rep = label.substr(0,24);
    petitchiffre.Print("Content of SAVES folder:",xrep+10,yrep+170);
    Rect BackDeroule(Vec2D(xrep,yrep+155),Vec2D(245,185));
    BackDeroule.SetRoundness(15);
    BackDeroule.Draw(CouleurConfig.WithAlpha(0.7));

    for (int y=0; y<8; y++)
    {
        Rect OverFile(Vec2D(xrep+5,(yrep+185+(y*20)-10)),Vec2D(200,20));
        OverFile.SetRoundness(7.5);
        if(strcmp(savefile_name,list_save_files[savefile_selected])==0 && (savefile_selected==(y+line_save)))
        {
            OverFile.Draw(CouleurFond.WithAlpha(0.5));
        }

        if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+155 && mouse_y>(yrep+175+(y*20)) && mouse_y<(yrep+190+(y*20)))
        {
            OverFile.DrawOutline(CouleurLigne);
        }

        petitpetitchiffre.Print(list_save_files[line_save+y],xrep+10,yrep+185+(y*20));
    }
    Rect FrameSelected(Vec2D(xrep+5,yrep+347),Vec2D(240,30));
    FrameSelected.SetRoundness(7.5);
    FrameSelected.Draw(CouleurConfig);
    if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+245 && mouse_y>yrep+347 && mouse_y<yrep+377)
    {
        FrameSelected.DrawOutline(CouleurLigne);
    }
    FrameSelected.SetLineWidth(epaisseur_ligne_fader);
    FrameSelected.DrawOutline(CouleurLigne.WithAlpha(alpha_blinker));
    petitchiffre.Print(savefile_name,xrep+10,yrep+365);
    Circle LineUp(Vec2D(xrep+220,yrep+200),12);
    LineUp.Draw(CouleurFond);
    Circle LineDown(Vec2D(xrep+220,yrep+310),12);
    LineDown.Draw(CouleurFond);
    if(window_focus_id==W_SAVE && mouse_x>xrep+208 && mouse_x<xrep+232)
    {
        if(mouse_y>yrep+188 && mouse_y<yrep+212)
        {
            LineUp.Draw(CouleurSurvol);
        }
        else if(mouse_y>yrep+298 && mouse_y<yrep+322)
        {
            LineDown.Draw(CouleurSurvol);
        }
    }
    petitchiffre.Print("-",xrep+216,yrep+205);
    petitchiffre.Print("+",xrep+216,yrep+315);
    LineUp.DrawOutline(CouleurLigne);
    LineDown.DrawOutline(CouleurLigne);
    Rect SaveB(Vec2D(xrep+40,yrep+390),Vec2D(70,30));
    SaveB.SetRoundness(7.5);
    if(window_focus_id==W_SAVE && mouse_x>xrep+40 && mouse_x<xrep+110 && mouse_y>yrep+390 && mouse_y<yrep+420)
    {
        SaveB.Draw(CouleurSurvol);
    }
    petitchiffre.Print("SAVE",xrep+55,yrep+410);
    SaveB.DrawOutline(CouleurLigne);


    Rect LoadB(Vec2D(xrep+140,yrep+390),Vec2D(70,30));
    LoadB.SetRoundness(7.5);
    if(window_focus_id==W_SAVE && mouse_x>xrep+140 && mouse_x<xrep+210 && mouse_y>yrep+390 && mouse_y<yrep+420)
    {
        LoadB.Draw(CouleurSurvol);
    }
    petitchiffre.Print("LOAD",xrep+155,yrep+410);
    LoadB.DrawOutline(CouleurLigne);


    Rect ResetB(Vec2D(xrep+280,yrep+390),Vec2D(70,30));
    ResetB.SetRoundness(7.5);

    if(window_focus_id==W_SAVE && mouse_x>xrep+280 && mouse_x<xrep+350 && mouse_y>yrep+390 && mouse_y<yrep+420)
    {
        ResetB.Draw(CouleurSurvol);
    }
    petitchiffre.Print("RESET",xrep+295,yrep+410);
    ResetB.DrawOutline(CouleurLigne);


}
