void deroule_repertoire_export_import(int xrep, int yrep, const std::string label)
{
    petitchiffre.Print("Content of import_export folder:",xrep+10,yrep+170);
    Rect BackDeroule(Vec2D(xrep,yrep+155),Vec2D(245,185));
    BackDeroule.SetRoundness(15);
    BackDeroule.Draw(CouleurConfig.WithAlpha(0.7));

    for (int y=0; y<8; y++)
    {
        Rect OverFile(Vec2D(xrep+5,(yrep+185+(y*20)-10)),Vec2D(200,20));
        OverFile.SetRoundness(7.5);

        if(strcmp(importfile_name,list_import_files[importfile_selected])==0 && (importfile_selected==(y+line_import)))
        {
            OverFile.Draw(CouleurFond.WithAlpha(0.5));
        }


        if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+155 && mouse_y>(yrep+175+(y*20)) && mouse_y<(yrep+190+(y*20)))
        {
            OverFile.DrawOutline(CouleurLigne);
        }
        petitpetitchiffre.Print(list_import_files[line_import+y],xrep+10,yrep+185+(y*20));

    }



    Rect FrameSelected(Vec2D(xrep+5,yrep+347),Vec2D(240,30));
    FrameSelected.SetRoundness(7.5);
    FrameSelected.Draw(CouleurConfig);





    if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+5+200 && mouse_y>yrep+347 && mouse_y<yrep+367)
    {
        FrameSelected.DrawOutline(CouleurLigne);
    }




    FrameSelected.SetLineWidth(epaisseur_ligne_fader);
    FrameSelected.DrawOutline(CouleurLigne.WithAlpha(alpha_blinker));
    petitchiffre.Print(importfile_name,xrep+10,yrep+365);
    petitpetitchiffre.Print(string_typeexport_view,xrep+150,yrep+375);

    petitpetitchiffre.Print("Name must have extension: ",xrep+250,yrep+170 );
    petitchiffre.Print("Ascii: .asc .txt or .alq",xrep+250,yrep+185 );
    petitchiffre.Print("PDF: .pdf",xrep+250,yrep+200 );
    petitpetitchiffre.Print("Schwarzpeter: no extension",xrep+250,yrep+215 );

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
        else if(window_focus_id==W_SAVE && mouse_y>yrep+298 && mouse_y<yrep+322)
        {
            LineDown.Draw(CouleurSurvol);
        }
    }
    petitchiffre.Print("-",xrep+216,yrep+205);
    petitchiffre.Print("+",xrep+216,yrep+315);
    LineUp.DrawOutline(CouleurLigne);
    LineDown.DrawOutline(CouleurLigne);


    switch (index_export_choice)
    {
    case 0://ascii
        enable_export=1;
        enable_import=1;
        break;
    case 1://schwz
        enable_export=0;
        enable_import=1;
        break;
    case 2://alq
        enable_export=0;
        enable_import=1;
        break;
    case 3://pdf
        enable_export=1;
        enable_import=0;
        break;
    default:
        break;
    }
    if(enable_export==1)
    {
        Rect SaveExport(Vec2D(xrep+40,yrep+390),Vec2D(70,30));
        SaveExport.SetRoundness(7.5);
        if(window_focus_id==W_SAVE && mouse_x>xrep+40 && mouse_x<xrep+110 && mouse_y>yrep+390 && mouse_y<yrep+420)
        {
            SaveExport.Draw(CouleurSurvol);
        }
        petitchiffre.Print("SAVE",xrep+55,yrep+410);
        SaveExport.DrawOutline(CouleurLigne);
    }
    if(enable_import==1)
    {
        Rect LoadExport(Vec2D(xrep+140,yrep+390),Vec2D(70,30));
        LoadExport.SetRoundness(7.5);
        if(window_focus_id==W_SAVE && mouse_x>xrep+140 && mouse_x<xrep+210 && mouse_y>yrep+390 && mouse_y<yrep+420)
        {
            LoadExport.Draw(CouleurSurvol);
        }
        petitchiffre.Print("LOAD",xrep+155,yrep+410);
        LoadExport.DrawOutline(CouleurLigne);
    }
}
