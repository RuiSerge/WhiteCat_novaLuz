int BoxGuiBuilder_iCat ( int gx, int gy)
{

    Rect backFS(Vec2D(gx,gy),Vec2D(largeuriCat,hauteuriCat));
    backFS.SetRoundness(5);
    backFS.SetLineWidth(triple_epaisseur_ligne_fader);
    backFS.Draw(CouleurConfig);
    if( window_focus_id==W_iCAT)
    {
        backFS.DrawOutline(CouleurFader);
    }
    else
    {
        backFS.DrawOutline(CouleurLigne);
    }
    neuro.Print( "FantaStick-iCat Interface Builder",(gx+100), (gy+25));


    switch(surface_type)
    {
    case 0:
        toggling_bar_view(gx+20,gy+40, iCat_preset_orientation[iCatPageis], "   iPOD ");
        break;
    case 1:
        toggling_bar_view(gx+20,gy+40, iCat_preset_orientation[iCatPageis], "   iPAD ");
        break;
    default:
        break;
    }
    if(mouse_x>gx+20 && mouse_x<gx+90 && mouse_y>gy+40 && mouse_y<gy+60 && window_focus_id==W_iCAT && im_moving_a_window==0 )
    {
        if( mouse_button==1 && mouse_released==0)
        {
            surface_type++;
            if(surface_type>1)
            {
                surface_type=0;
            }
            recalculate_iCatBuilder_window_size();
            mouse_released=1;
        }
    }


    char tmpch[24];
    switch(iCat_preset_orientation[iCatPageis])
    {
    case 0:
        sprintf(tmpch,"    Vertical");
        break;
    case 1:
        sprintf(tmpch," Horizontal 1");
        break;
    case 2:
        sprintf(tmpch," Horizontal 2");
        break;
    default:
        sprintf(tmpch,"-");
        break;
    }

    toggling_bar_view(gx+100,gy+40, iCat_preset_orientation[iCatPageis], tmpch);

    Rect iCatPresetO(Vec2D(gx+100,gy+40),Vec2D(70,20));
    iCatPresetO.SetRoundness(5);
    if(mouse_x>gx+100 && mouse_x<gx+170 && mouse_y>gy+40 && mouse_y<gy+60 && window_focus_id==W_iCAT && im_moving_a_window==0)
    {
        if( Midi_Faders_Affectation_Type!=0)
        {
            iCatPresetO.DrawOutline(CouleurBlind);
            //midi report
            switch(miditable[0][1275])
            {
            case 0:
                sprintf(thetypinfo,"Note");
                break;
            case 1:
                sprintf(thetypinfo,"Key On");
                break;
            case 2:
                sprintf(thetypinfo,"Key Off");
                break;
            case 4:
                sprintf(thetypinfo,"Ctrl Change");
                break;
            default:
                break;
            }
            sprintf(string_last_midi_id,"iCat Page Orientation is Ch: %d Pitch: %d Type: %s", miditable[1][1275],miditable[2][1275],thetypinfo);
            if(mouse_button==1 && mouse_released==0)
            {
                attribute_midi_to_control(1275,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }

        }
        else
        {
            if( mouse_button==1 && mouse_released==0)
            {

                iCat_preset_orientation[iCatPageis]++;
                if(iCat_preset_orientation[iCatPageis]>2)
                {
                    iCat_preset_orientation[iCatPageis]=0;
                }
                recalculate_iCatBuilder_window_size();

                do_refresh_iCat(iCatPageis);
                mouse_released=1;
            }
        }
    }


    Rect AffectModulo(Vec2D(gx+180,gy+40),Vec2D(45,20));
    AffectModulo.SetRoundness(5);
    AffectModulo.Draw(CouleurFond.WithAlpha(0.4));
    petitchiffre.Print("%", gx+185,gy+52);
    petitpetitchiffre.Print(ol::ToString(grid_icat_modulo), gx+200,gy+52);

    if(mouse_x>gx+180 && mouse_x<gx+225 && mouse_y>gy+40 && mouse_y<gy+60 &&  window_focus_id==W_iCAT)
    {
        AffectModulo.DrawOutline(CouleurLigne);
        if(  mouse_button==1 && mouse_released==0 )
        {
            int temp_number=atoi(numeric);
            grid_icat_modulo=temp_number;
            if(grid_icat_modulo<1)
            {
                grid_icat_modulo=1;
            }
            else if(grid_icat_modulo>50)
            {
                grid_icat_modulo=50;
            }
            reset_numeric_entry();
            mouse_released=1;
        }
    }


    Rect CopyB(Vec2D(gx+240,gy+40),Vec2D(45,20));
    CopyB.SetRoundness(5);
    CopyB.Draw(CouleurFond.WithAlpha(0.4));
    if(index_icat_copyPage==1)
    {
        CopyB.Draw(CouleurFader);
    }
    petitpetitchiffre.Print("Copy", gx+245,gy+40+12);

    if(mouse_x>gx+240 && mouse_x<gx+285 && mouse_y>gy+40 && mouse_y<gy+60 &&  window_focus_id==W_iCAT)
    {
        if(  mouse_button==1 && mouse_released==0 )
        {
            index_icat_copyPage=toggle(index_icat_copyPage);
            iCatPageToCopyIn=iCatPageis;
            mouse_released=1;
        }
    }



    toggling_bar_view(gx+300,gy+40, iCat_preset_orientation[iCatPageis], "  Refresh");
    Rect iCatPresetR(Vec2D(gx+300,gy+40),Vec2D(70,20));
    iCatPresetR.SetRoundness(5);
    if(mouse_x>gx+300 && mouse_x<gx+370 && mouse_y>gy+40 && mouse_y<gy+60 && window_focus_id==W_iCAT )
    {
        if( Midi_Faders_Affectation_Type!=0)
        {
            iCatPresetR.DrawOutline(CouleurBlind);
            //midi report
            switch(miditable[0][1276])
            {
            case 0:
                sprintf(thetypinfo,"Note");
                break;
            case 1:
                sprintf(thetypinfo,"Key On");
                break;
            case 2:
                sprintf(thetypinfo,"Key Off");
                break;
            case 4:
                sprintf(thetypinfo,"Ctrl Change");
                break;
            default:
                break;
            }
            sprintf(string_last_midi_id,"iCat Page Refresh is Ch: %d Pitch: %d Type: %s", miditable[1][1276],miditable[2][1276],thetypinfo);
            if(mouse_button==1 && mouse_released==0)
            {
                attribute_midi_to_control(1276,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }

        }
        else
        {
            if( mouse_button==1 && mouse_released==0)
            {
                do_refresh_iCat(iCatPageis);
                mouse_released=1;
            }
        }
    }

    Rect iCatPresetM(Vec2D(gx+380,gy+40),Vec2D(50,20));
    iCatPresetM.SetRoundness(7.5);
    iCatPresetM.Draw(CouleurFond.WithAlpha(0.5));
    petitpetitchiffre.Print("-",gx+400,gy+53);
    if(mouse_x> gx+380 && mouse_x<gx+430 && mouse_y>gy+40 && mouse_y<gy+60 && window_focus_id==W_iCAT)
    {
        if( Midi_Faders_Affectation_Type!=0)
        {
            iCatPresetM.DrawOutline(CouleurBlind);

            //midi report
            switch(miditable[0][1265])
            {
            case 0:
                sprintf(thetypinfo,"Note");
                break;
            case 1:
                sprintf(thetypinfo,"Key On");
                break;
            case 2:
                sprintf(thetypinfo,"Key Off");
                break;
            case 4:
                sprintf(thetypinfo,"Ctrl Change");
                break;
            default:
                break;
            }
            sprintf(string_last_midi_id,"iCat Page Minus is Ch: %d Pitch: %d Type: %s", miditable[1][1265],miditable[2][1265],thetypinfo);
            if(mouse_button==1 && mouse_released==0)
            {
                attribute_midi_to_control(1265,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }

        }
        else
        {
            if( mouse_button==1 && mouse_released==0)
            {
                iCatPageis--;
                if(iCatPageis<0)
                {
                    iCatPageis=7;
                }
                load_iCat_page(iCatPageis);
                do_send_icat_init_page=1;
                mouse_released=1;
            }
        }
    }

    Rect iCatPresetP(Vec2D(gx+440,gy+40),Vec2D(50,20));
    iCatPresetP.SetRoundness(7.5);
    iCatPresetP.Draw(CouleurFond.WithAlpha(0.5));
    petitpetitchiffre.Print("+",gx+460,gy+53);
    if(mouse_x> gx+440 && mouse_x<gx+490 && mouse_y>gy+40 && mouse_y<gy+60  && window_focus_id==W_iCAT)
    {
        if(Midi_Faders_Affectation_Type!=0)
        {
            iCatPresetP.DrawOutline(CouleurBlind);
            //midi report
            switch(miditable[0][1266])
            {
            case 0:
                sprintf(thetypinfo,"Note");
                break;
            case 1:
                sprintf(thetypinfo,"Key On");
                break;
            case 2:
                sprintf(thetypinfo,"Key Off");
                break;
            case 4:
                sprintf(thetypinfo,"Ctrl Change");
                break;
            default:
                break;
            }
            sprintf(string_last_midi_id,"iCat Page Plus is Ch: %d Pitch: %d Type: %s", miditable[1][1266],miditable[2][1266],thetypinfo);
            if(mouse_button==1 && mouse_released==0)
            {
                attribute_midi_to_control(1266,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                mouse_released=1;
            }

        }
        else
        {
            if( mouse_button==1 && mouse_released==0)
            {
                iCatPageis++;
                if(iCatPageis>7)
                {
                    iCatPageis=0;
                }
                load_iCat_page(iCatPageis);
                do_send_icat_init_page=1;
                mouse_released=1;
            }
        }
    }


    for(int o=0; o<8; o++) //8 docks pages iCat
    {
        Rect iCatPreset(Vec2D(gx+20+(o*60),gy+70),Vec2D(50,20));
        iCatPreset.SetRoundness(7.5);
        iCatPreset.SetLineWidth(tiers_epaisseur_ligne_fader);
        if( iCatPageis==o)
        {
            iCatPreset.Draw(CouleurFader);
        }
        else
        {
            iCatPreset.Draw(CouleurFond.WithAlpha(0.5));
        }
        petitpetitchiffre.Print(ol::ToString(o+1),gx+42+(o*60),gy+83);
        if(mouse_x> gx+20+(o*60) && mouse_x<gx+70+(o*60) && mouse_y>gy+70 && mouse_y<gy+90  && window_focus_id==W_iCAT)
        {
            if( Midi_Faders_Affectation_Type!=0)
            {
                iCatPreset.DrawOutline(CouleurBlind);
                //midi report
                switch(miditable[0][1267+o])
                {
                case 0:
                    sprintf(thetypinfo,"Note");
                    break;
                case 1:
                    sprintf(thetypinfo,"Key On");
                    break;
                case 2:
                    sprintf(thetypinfo,"Key Off");
                    break;
                case 4:
                    sprintf(thetypinfo,"Ctrl Change");
                    break;
                default:
                    break;
                }
                sprintf(string_last_midi_id,"iCat Page %d is Ch: %d Pitch: %d Type: %s",o+1, miditable[1][1267+o],miditable[2][1267+o],thetypinfo);
                if(mouse_button==1 && mouse_released==0)
                {
                    attribute_midi_to_control(1267+o,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
                    mouse_released=1;
                }

            }
            else
            {
                if( mouse_button==1 && mouse_released==0)
                {

                    if(index_main_clear==1 && index_icat_copyPage==0)
                    {
                        iCatPageis=o;
                        index_ask_confirm=1;
                        index_ask_clear_iCatpage=1;
                    }
                    else if(index_icat_copyPage==1)
                    {
                        iCatPageToCopyIn=o;
                        index_ask_confirm=1;
                        index_ask_icat_copyPage=1;
                    }
                    else
                    {
                        iCatPageis=o;
                        load_iCat_page(iCatPageis);
                        do_send_icat_init_page=1;
                    }

                    mouse_released=1;
                }
            }
        }
    }



    Tablier_GUI_editor(gx+20,gy+100);
    Menu_edition_iCat_sliders(gx+20,gy+H_tablier_iCat+130);
    Menu_edition_iCat_boutons(gx+150,gy+H_tablier_iCat+130);
    Menu_edition_iCat_strings(gx+280,gy+H_tablier_iCat+130);
    Menu_edition_tracking_zone(gx+410,gy+H_tablier_iCat+130);


    return(0);
}
