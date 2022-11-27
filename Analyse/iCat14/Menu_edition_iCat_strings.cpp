int Menu_edition_iCat_strings(int xed, int yed)
{
    char title_iCat_menu[16];

    Rect String_M(Vec2D(xed-15,yed-10),Vec2D(105,20));
    String_M.SetRoundness(4);
    String_M.Draw(CouleurFond.WithAlpha(0.4));
    if(editing_GUI_type_iCat==3)
    {
        String_M.Draw(CouleurSurvol);
    }
    petitchiffre.Print("Strings",xed+10,yed+2);
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
            if(editing_GUI_type_iCat==3)
            {
                editing_GUI_type_iCat=0;
            }
            else editing_GUI_type_iCat=3;
        }
        mouse_released=1;
    }


    previous_button_view(xed-15,yed+15,0);
    next_button_view(xed+50,yed+15,0);
    Rect string_F(Vec2D(xed+10,yed+15),Vec2D(35,20));
    string_F.SetRoundness(4);
    string_F.Draw(CouleurFond.WithAlpha(0.4));
    sprintf(title_iCat_menu,"%d /%d",iCat_select_editing_string, iCat_nbre_de_strings[iCatPageis]);
    petitpetitchiffre.Print(title_iCat_menu,xed+12,yed+27);

    if(mouse_y>yed+15 && mouse_y< yed+35)
    {
        if(mouse_x>xed-15 && mouse_x<xed+5 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            editing_GUI_type_iCat=3;
            previous_button_view(xed-15,yed+15,1);
            if(iCat_select_editing_string>0)
            {
                iCat_select_editing_string--;
            }
            else
            {
                iCat_select_editing_string=iCat_nbre_de_strings[iCatPageis];
            }
            mouse_released=1;
        }
        if(mouse_x>xed+50 && mouse_x<xed+70 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            editing_GUI_type_iCat=3;
            next_button_view(xed+50,yed+15,1);
            if(iCat_select_editing_string<iCat_nbre_de_strings[iCatPageis])
            {
                iCat_select_editing_string++;
            }
            else
            {
                iCat_select_editing_string=iCat_nbre_de_strings[iCatPageis];
            }
            mouse_released=1;
        }
    }

    case_moins_view(xed+75,yed+15,0);
    case_plus_view(xed+75,yed+35,0);

    if(mouse_x>xed+75 && mouse_x<xed+90)
    {
        if(mouse_y>yed+15 && mouse_y<yed+30 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            editing_GUI_type_iCat=3;
            case_moins_view(xed+75,yed+15,1);
            if(iCat_nbre_de_strings[iCatPageis]>0)
            {
                iCat_nbre_de_strings[iCatPageis]--;
                if(iCat_select_editing_string>iCat_nbre_de_strings[iCatPageis])
                {
                    iCat_select_editing_string=iCat_nbre_de_strings[iCatPageis];
                }
            }
            mouse_released=1;
        }
        if(mouse_y>yed+35 && mouse_y<yed+50 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT )
        {
            editing_GUI_type_iCat=3;
            case_plus_view(xed+75,yed+35,1);
            if(iCat_nbre_de_strings[iCatPageis]<max_string_icat)
            {
                iCat_nbre_de_strings[iCatPageis]++;
            }
            iCat_select_editing_string=iCat_nbre_de_strings[iCatPageis];
            mouse_released=1;
        }
    }


    char str_type_iCat[16];
    sprintf(str_type_iCat,"X: %d Y: %d",iCat_pos_string[iCatPageis][iCat_select_editing_string][0],iCat_pos_string[iCatPageis][iCat_select_editing_string][1]);
    petitpetitchiffre.Print(str_type_iCat,xed-10,yed+47);


    switch(ratio_iCat_string[iCatPageis][iCat_select_editing_string])
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
    default:
        sprintf(str_type_iCat,"-");
        break;
    }
    pulse_bar_view(xed-12,yed+55, str_type_iCat);
    if(mouse_x>xed-12 && mouse_x<xed+18 && mouse_y>yed+55 && mouse_y<yed+75 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_string!=0)
    {
        editing_GUI_type_iCat=3;
        ratio_iCat_string[iCatPageis][iCat_select_editing_string]++;
        if(ratio_iCat_string[iCatPageis][iCat_select_editing_string]>3)
        {
            ratio_iCat_string[iCatPageis][iCat_select_editing_string]=1;
        }
        mouse_released=1;
    }



    char string_temp_familly[25];
    petitpetitchiffre.Print("Type:",xed-15,yed+90);
    Rect AffectTyp(Vec2D(xed-15,yed+95),Vec2D(100,20));
    AffectTyp.SetRoundness(4);
    AffectTyp.Draw(CouleurFond.WithAlpha(0.4));
    switch(iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string])
    {
    case 0://desafected
        sprintf(string_temp_familly,"-");
        break;
    case 1: //Feedback
        sprintf(string_temp_familly,"Feedback:");
        break;
    case 2: //sequenciel
        sprintf(string_temp_familly,"Sequences:");
        break;
    default:
        break;
    }
    petitpetitchiffre.Print(string_temp_familly,xed-7,yed+107);

    if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+95 && mouse_y<yed+115 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_string!=0)
    {
        editing_GUI_type_iCat=3;
        iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string]++;
        if(iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string]>2)
        {
            iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string]=0;
        }
        iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string]=0;
        mouse_released=1;
    }




    petitpetitchiffre.Print("Action:",xed-15,yed+122);
    Rect AffectAct(Vec2D(xed-15,yed+125),Vec2D(100,20));
    AffectAct.SetRoundness(4);
    AffectAct.Draw(CouleurFond.WithAlpha(0.4));
    switch(iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string])
    {
    case 0://desafected
        sprintf(string_temp_familly,"-");
        break;
    case 1: //Feedback

        switch(iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string])
        {
        case 0://desafected
            sprintf(string_temp_familly,"-");
            break;
        case 1: //input
            sprintf(string_temp_familly,"Input");
            break;
        case 2://last ch
            sprintf(string_temp_familly,"Last CH.");
            break;
        case 3://dimmers
            sprintf(string_temp_familly,"DIM.");
            break;
        case 4://last order
            sprintf(string_temp_familly,"Last Order");
            break;
        case 5:
            sprintf(string_temp_familly,"Confirm");
            break;
        default:
            break;
        }

        break;

    case 2://sequences
        switch(iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string])
        {
        case 0://desafected
            sprintf(string_temp_familly,"-");
            break;
        case 1: //X1
            sprintf(string_temp_familly,"Stage");
            break;
        case 2://X2
            sprintf(string_temp_familly,"Preset");
            break;
        case 3://Before 1
            sprintf(string_temp_familly,"Mem. Before 1");
            break;
        case 4://Mem +
            sprintf(string_temp_familly,"Mem. After 1");
            break;
        default:
            break;
        }
        break; //fin  stringsequences
    default:
        break;
    }
    petitpetitchiffre.Print(string_temp_familly,xed-7,yed+137);
    if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+125 && mouse_y<yed+145 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_string!=0)
    {
        editing_GUI_type_iCat=3;
        iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string]++;
        int max_menu=0;
        switch ( iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string])
        {
        case 1:
            max_menu=4;//feedbacks strings
            break;
        case 2:
            max_menu=4;//sequencieal strings
            break;
        default:
            break;
        }
        if(iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string]>max_menu)
        {
            iCat_affectation_string_action_is[iCatPageis][iCat_select_editing_string]=0;
        }
        mouse_released=1;
    }

    if(iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string]==2 )
    {
        //que pour sequenciel
        Rect AffectVar(Vec2D(xed+40,yed+150),Vec2D(45,20));
        AffectVar.SetRoundness(5);
        AffectVar.Draw(CouleurFond.WithAlpha(0.4));
        petitpetitchiffre.Print(ol::ToString(iCat_affectation_string_value_is[iCatPageis][iCat_select_editing_string]),
                                xed+55,yed+162);

        if(mouse_x>xed+40 && mouse_x<xed+40+45 && mouse_y>yed+150 && mouse_y<yed+150+20 &&  window_focus_id==W_iCAT )
        {
            editing_GUI_type_iCat=3;
            AffectVar.DrawOutline(CouleurLigne);
            if(  mouse_button==1 && mouse_released==0 && iCat_select_editing_string!=0)
            {
                int temp_number=atoi(numeric);
                reset_numeric_entry();
                switch(iCat_affectation_string_type_is[iCatPageis][iCat_select_editing_string])
                {
                case 2: //Mem after
                    if(temp_number>12)
                    {
                        temp_number=12;
                    }
                    break;
                default:
                    break;
                }
                iCat_affectation_string_value_is[iCatPageis][iCat_select_editing_string]=temp_number;
                mouse_released=1;
            }
        }
    }




    return(0);
}
