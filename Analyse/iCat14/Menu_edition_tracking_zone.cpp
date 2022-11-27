int  Menu_edition_tracking_zone(int xed,int yed)
{
    char title_iCat_menu[16];

    Rect Button_M(Vec2D(xed-15,yed-10),Vec2D(105,20));
    Button_M.SetRoundness(4);
    Button_M.Draw(CouleurFond.WithAlpha(0.4));
    if(editing_GUI_type_iCat==4)
    {
        Button_M.Draw(CouleurSurvol);
    }
    petitchiffre.Print("Tracking Zones",xed-10,yed+2);
    if(mouse_x>xed-15 && mouse_x<xed+90 && mouse_y>yed-10 && mouse_y<yed+10
            && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
    {
        if(index_main_clear==1)//clear des sliders selectivement
        {
            index_ask_iCat_selectiv_clear=1;
            index_ask_confirm=1;
        }
        else
        {
            if(editing_GUI_type_iCat==4)
            {
                editing_GUI_type_iCat=0;
            }
            else editing_GUI_type_iCat=4;
        }
        mouse_released=1;
    }


    previous_button_view(xed-15,yed+15,0);
    next_button_view(xed+50,yed+15,0);
    Rect button_F(Vec2D(xed+10,yed+15),Vec2D(35,20));
    button_F.SetRoundness(4);
    button_F.Draw(CouleurFond.WithAlpha(0.4));
    sprintf(title_iCat_menu,"%d /%d",iCat_select_tracking_zone, iCat_nbre_de_tracking_zone[iCatPageis]);
    petitpetitchiffre.Print(title_iCat_menu,xed+12,yed+27);

    if(mouse_y>yed+15 && mouse_y< yed+35)
    {
        if(mouse_x>xed-15 && mouse_x<xed+5 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            previous_button_view(xed-15,yed+15,1);
            if(iCat_select_tracking_zone>0)
            {
                iCat_select_tracking_zone--;
            }
            else
            {
                iCat_select_tracking_zone=iCat_nbre_de_tracking_zone[iCatPageis];
            }
            mouse_released=1;
        }
        if(mouse_x>xed+50 && mouse_x<xed+70 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            next_button_view(xed+50,yed+15,1);
            if(iCat_select_tracking_zone<iCat_nbre_de_tracking_zone[iCatPageis])
            {
                iCat_select_tracking_zone++;
            }
            else
            {
                iCat_select_tracking_zone=iCat_nbre_de_tracking_zone[iCatPageis];
            }
            mouse_released=1;
        }
    }

    case_moins_view(xed+75,yed+15,0);
    case_plus_view(xed+75,yed+35,0);

    if(mouse_x>xed+75 && mouse_x<xed+90)
    {
        if(mouse_y>yed+15 && mouse_y<yed+30 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && editing_GUI_type_iCat==4)
        {
            case_moins_view(xed+75,yed+15,1);
            if(iCat_nbre_de_tracking_zone[iCatPageis]>0)
            {
                iCat_nbre_de_tracking_zone[iCatPageis]--;
                if(iCat_select_tracking_zone>iCat_nbre_de_tracking_zone[iCatPageis])
                {
                    iCat_select_tracking_zone=iCat_nbre_de_tracking_zone[iCatPageis];
                }
            }
            mouse_released=1;
        }
        if(mouse_y>yed+35 && mouse_y<yed+50 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && editing_GUI_type_iCat==4)
        {
            case_plus_view(xed+75,yed+35,1);
            if(iCat_nbre_de_tracking_zone[iCatPageis]<max_zones_icat)
            {
                iCat_nbre_de_tracking_zone[iCatPageis]++;
            }
            iCat_select_tracking_zone=iCat_nbre_de_tracking_zone[iCatPageis];
            mouse_released=1;
        }
    }


    char str_type_iCat[16];
    sprintf(str_type_iCat,"X: %d Y: %d",iCat_pos_trackzone[iCatPageis][iCat_select_tracking_zone][0],iCat_pos_trackzone[iCatPageis][iCat_select_tracking_zone][1]);
    petitpetitchiffre.Print(str_type_iCat,xed-10,yed+47);


    switch(ratio_iCat_trackzone[iCatPageis][iCat_select_tracking_zone])
    {
    case 1:
        sprintf(str_type_iCat,"small");
        break;
    case 2:
        sprintf(str_type_iCat,"med.");
        break;
    case 3:
        sprintf(str_type_iCat,"big");
        break;
    case 4:
        sprintf(str_type_iCat,"B I G");
        break;
    default:
        sprintf(str_type_iCat,"-");
        break;
    }
    pulse_bar_view(xed-12,yed+55, str_type_iCat);
    if(mouse_x>xed-12 && mouse_x<xed+18 && mouse_y>yed+55 && mouse_y<yed+75 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && editing_GUI_type_iCat==4 && iCat_select_tracking_zone!=0)
    {
        ratio_iCat_trackzone[iCatPageis][iCat_select_tracking_zone]++;
        if(ratio_iCat_trackzone[iCatPageis][iCat_select_tracking_zone]>4)
        {
            ratio_iCat_trackzone[iCatPageis][iCat_select_tracking_zone]=0;
        }
        mouse_released=1;
    }



    char string_temp_familly[25];
    Rect AffectTyp(Vec2D(xed-15,yed+95),Vec2D(100,20));
    AffectTyp.SetRoundness(4);
    AffectTyp.Draw(CouleurFond.WithAlpha(0.4));
    switch(iCat_trackzone_type_is[iCatPageis][iCat_select_tracking_zone] )//mover
    {
    case 0://desafected
        sprintf(string_temp_familly,"-");
        break;
    case 1://mover
        sprintf(string_temp_familly,"Mover");
        break;
    case 2://draw
        sprintf(string_temp_familly,"Draw Activ");
        break;
    case 3://draw
        sprintf(string_temp_familly,"Draw Matrix");
        break;
    default:
        break;
    }
    petitpetitchiffre.Print(string_temp_familly,xed-7,yed+107);

    if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+95 && mouse_y<yed+115 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT && editing_GUI_type_iCat==4 && iCat_select_tracking_zone!=0)
    {
        iCat_trackzone_type_is[iCatPageis][iCat_select_tracking_zone]++;
        if(iCat_trackzone_type_is[iCatPageis][iCat_select_tracking_zone]>3)
        {
            iCat_trackzone_type_is[iCatPageis][iCat_select_tracking_zone]=0;
        }
        mouse_released=1;
    }

    Rect AffectVar(Vec2D(xed+40,yed+120),Vec2D(45,20));
    AffectVar.SetRoundness(5);
    AffectVar.Draw(CouleurFond.WithAlpha(0.4));
    petitpetitchiffre.Print(ol::ToString(iCat_trackzone_affectation_is[iCatPageis][iCat_select_tracking_zone]),
                            xed+55,yed+132);

    if(mouse_x>xed+40 && mouse_x<xed+85 && mouse_y>yed+120 && mouse_y<yed+140 &&  window_focus_id==W_iCAT && editing_GUI_type_iCat==4)
    {
        AffectVar.DrawOutline(CouleurLigne);
        if(  mouse_button==1 && mouse_released==0 && iCat_select_tracking_zone!=0)
        {
            int temp_number=atoi(numeric);

            switch(iCat_trackzone_type_is[iCatPageis][iCat_select_tracking_zone])
            {
            case 1: // tracker move
                if(temp_number>48)
                {
                    temp_number=48;
                }
                iCat_trackzone_affectation_is[iCatPageis][iCat_select_tracking_zone]=temp_number;
                reset_numeric_entry();
                break;
            case 3:
                if(temp_number>6)
                {
                    temp_number=6;
                }
                iCat_trackzone_affectation_is[iCatPageis][iCat_select_tracking_zone]=temp_number;
                reset_numeric_entry();
                break;
            default:
                break;
            }

            mouse_released=1;
        }
    }

    return(0);
}
