void deroule_repertoire_plans(int xrep, int yrep, const std::string label)
{
    const std::string name_of_rep = label.substr(0,24);

    Rect BackDeroule(Vec2D(xrep,yrep+155),Vec2D(210,185));
    BackDeroule.SetRoundness(5);
    BackDeroule.Draw(CouleurBleuProcedure.WithAlpha(0.4));
    BackDeroule.Draw(CouleurPlotLine.WithAlpha(0.4));
    petitchiffre.Print("Plans folder (.jpg .bmp .png .tga)",xrep+10,yrep+170);

    Canvas::SetClipping( xrep,yrep,xrep+230,yrep+175);

    for (int y=0; y<8; y++)
    {
        Rect OverFile(Vec2D(xrep+5,(yrep+185+(y*20)-10)),Vec2D(180,20));
        OverFile.SetRoundness(7.5);
        if(strcmp( Name_of_plane_is,list_import_plans[importplan_selected])==0 && (importplan_selected==(y+line_importplan)))
        {
            OverFile.Draw(CouleurFond.WithAlpha(0.5));
        }

        petitchiffrenoir.Print(list_import_plans[line_importplan+y],xrep+10,yrep+187+(y*20));
        if(window_focus_id==W_PLOT &&  index_editing_theatre_plan==0 && mouse_x>xrep+5 && mouse_x<xrep+155 && mouse_y>(yrep+175+(y*20)) && mouse_y<(yrep+190+(y*20)))
        {
            OverFile.DrawOutline(CouleurLigne);
        }

    }


    Canvas::DisableClipping();

    Circle LineUp(Vec2D(xrep+190,yrep+200),12);
    LineUp.Draw(CouleurFond);
    Circle LineDown(Vec2D(xrep+190,yrep+310),12);
    LineDown.Draw(CouleurFond);

    petitchiffre.Print("-",xrep+186,yrep+205);
    petitchiffre.Print("+",xrep+186,yrep+315);
    LineUp.DrawOutline(CouleurLigne);
    LineDown.DrawOutline(CouleurLigne);

    Rect BoutonRescan(Vec2D(xrep+150,yrep+345),Vec2D(60,20));
    BoutonRescan.SetRoundness(4);
    BoutonRescan.Draw(CouleurPlotLine.WithAlpha(0.6));
    petitchiffre.Print("Rescan !",xrep+155,yrep+357);

    if( window_focus_id==W_PLOT &&  index_editing_theatre_plan==0 && mouse_x>xrep+150 && mouse_x<xrep+210 && mouse_y>(yrep+345) && mouse_y<(yrep+365))
    {
        BoutonRescan.DrawOutline(CouleurLigne);
    }

}
