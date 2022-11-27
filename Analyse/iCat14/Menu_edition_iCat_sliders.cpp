int Menu_edition_iCat_sliders(int xed, int yed)
{
    char title_iCat_menu[16];

    Rect Slider_M(Vec2D(xed-15,yed-10),Vec2D(105,20));
    Slider_M.SetRoundness(4);
    Slider_M.Draw(CouleurFond.WithAlpha(0.4));
    if(editing_GUI_type_iCat==1)
    {
        Slider_M.Draw(CouleurSurvol);
    }
    petitchiffre.Print("Sliders",xed+10,yed+2);
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
            if(editing_GUI_type_iCat==1)
            {
                editing_GUI_type_iCat=0;
            }
            else editing_GUI_type_iCat=1;
        }
        mouse_released=1;
    }


    previous_button_view(xed-15,yed+15,0);
    next_button_view(xed+50,yed+15,0);
    Rect Slider_F(Vec2D(xed+10,yed+15),Vec2D(35,20));
    Slider_F.SetRoundness(4);
    Slider_F.Draw(CouleurFond.WithAlpha(0.4));
    sprintf(title_iCat_menu,"%d /%d",iCat_select_editing_slider, iCat_nbre_de_sliders[iCatPageis]);
    petitpetitchiffre.Print(title_iCat_menu,xed+12,yed+27);

    if(mouse_y>yed+15 && mouse_y< yed+35)
    {
        if(mouse_x>xed-15 && mouse_x<xed+5 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            editing_GUI_type_iCat=1;
            previous_button_view(xed-15,yed+15,1);
            if(iCat_select_editing_slider>0)
            {
                iCat_select_editing_slider--;
            }
            else
            {
                iCat_select_editing_slider=iCat_nbre_de_sliders[iCatPageis];
            }
            mouse_released=1;
        }
        if(mouse_x>xed+50 && mouse_x<xed+70 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
        {
            editing_GUI_type_iCat=1;
            next_button_view(xed+50,yed+15,1);
            if(iCat_select_editing_slider<iCat_nbre_de_sliders[iCatPageis])
            {
                iCat_select_editing_slider++;
            }
            else
            {
                iCat_select_editing_slider=0;
            }
            mouse_released=1;
        }
    }

    case_moins_view(xed+75,yed+15,0);
    case_plus_view(xed+75,yed+35,0);

    if(mouse_x>xed+75 && mouse_x<xed+90)
    {
        if(mouse_y>yed+15 && mouse_y<yed+30 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT )
        {
            editing_GUI_type_iCat=1;
            case_moins_view(xed+75,yed+15,1);
            if(iCat_nbre_de_sliders[iCatPageis]>0)
            {
                iCat_nbre_de_sliders[iCatPageis]--;
                if(iCat_select_editing_slider>iCat_nbre_de_sliders[iCatPageis])
                {
                    iCat_select_editing_slider=iCat_nbre_de_sliders[iCatPageis];
                }
            }
            mouse_released=1;
        }
        if(mouse_y>yed+35 && mouse_y<yed+50 && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT )
        {
            editing_GUI_type_iCat=1;
            case_plus_view(xed+75,yed+35,1);
            if(iCat_nbre_de_sliders[iCatPageis]<max_sliders_icat)
            {
                iCat_nbre_de_sliders[iCatPageis]++;
            }
            iCat_select_editing_slider=iCat_nbre_de_sliders[iCatPageis];
            mouse_released=1;
        }
    }


    char str_type_iCat[16];
    sprintf(str_type_iCat,"X: %d Y: %d",iCat_pos_slider[iCatPageis][iCat_select_editing_slider][0],iCat_pos_slider[iCatPageis][iCat_select_editing_slider][1]);
    petitpetitchiffre.Print(str_type_iCat,xed-10,yed+47);


    switch(ratio_iCat_slider[iCatPageis][iCat_select_editing_slider])
    {
    case 1:
        sprintf(str_type_iCat,"small");//abandonn�
        break;
    case 2:
        sprintf(str_type_iCat,"med.");
        break;
    case 3:
        sprintf(str_type_iCat,"big");
        break;
    default:
        sprintf(str_type_iCat,"-") ;
        break;
    }
    pulse_bar_view(xed-12,yed+55, str_type_iCat);
    if(mouse_x>xed-12 && mouse_x<xed+18 && mouse_y>yed+55 && mouse_y<yed+75 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_slider!=0)
    {
        editing_GUI_type_iCat=1;
        ratio_iCat_slider[iCatPageis][iCat_select_editing_slider]++;
        if(ratio_iCat_slider[iCatPageis][iCat_select_editing_slider]>3)
        {
            ratio_iCat_slider[iCatPageis][iCat_select_editing_slider]=1;
        }
        mouse_released=1;
    }



    switch (iCat_orientation_slider[iCatPageis][iCat_select_editing_slider])
    {
    case 0:
        sprintf(str_type_iCat,"     Vertical");
        break;
    case 1:
        sprintf(str_type_iCat,"   Horizontal");
        break;
    default:
        break;
    }
    toggling_bar_view(xed+20,yed+55, 0,str_type_iCat);

    if(mouse_x>xed+20 && mouse_x<xed+80 && mouse_y>yed+55 && mouse_y<yed+75 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_slider!=0)
    {
        editing_GUI_type_iCat=1;
        iCat_orientation_slider[iCatPageis][iCat_select_editing_slider]=toggle(iCat_orientation_slider[iCatPageis][iCat_select_editing_slider]);
        mouse_released=1;
    }



    char string_temp_familly[25];
    petitpetitchiffre.Print("Type:",xed-15,yed+90);
    Rect AffectTyp(Vec2D(xed-15,yed+95),Vec2D(100,20));
    AffectTyp.SetRoundness(4);
    AffectTyp.Draw(CouleurFond.WithAlpha(0.4));
    switch(iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider])
    {
    case 1: //faders  lvl
        sprintf(string_temp_familly,"Fader Level:");
        break;
    case 2://faders speeed
        sprintf(string_temp_familly,"Fader Speed:");
        break;
    case 3://sequenciel
        sprintf(string_temp_familly,"Sequences:");
        break;
    case 4://grand master
        sprintf(string_temp_familly,"GrandMaster");
        break;
    case 5://level wheel
        sprintf(string_temp_familly,"Level Wheel");
        break;
    case 6://mover
        sprintf(string_temp_familly,"Mover:");
        break;
    case 7://draw
        sprintf(string_temp_familly,"Draw Press.:");
        break;
    case 8://draw
        sprintf(string_temp_familly,"Draw Decay:");
        break;
    case 9://draw
        sprintf(string_temp_familly,"Draw Ghost:");
        break;
    case 10://draw
        sprintf(string_temp_familly,"Draw Act.Press");
        break;
    case 11://draw
        sprintf(string_temp_familly,"Draw Act.Decay");
        break;
    case 12://draw
        sprintf(string_temp_familly,"Draw Act.Ghost");
        break;

    default:
        sprintf(string_temp_familly,"-");
        break;
    }
    petitpetitchiffre.Print(string_temp_familly,xed-7,yed+107);

    if(mouse_x>xed-15 && mouse_x<xed+85 && mouse_y>yed+95 && mouse_y<yed+115 &&
            mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT  && iCat_select_editing_slider!=0)
    {
        editing_GUI_type_iCat=1;
        iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider]++;
        if(iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider]>12)
        {
            iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider]=0;
        }
        mouse_released=1;
    }


    Rect AffectVar(Vec2D(xed+40,yed+120),Vec2D(45,20));
    AffectVar.SetRoundness(5);
    AffectVar.Draw(CouleurFond.WithAlpha(0.4));
    petitpetitchiffre.Print(ol::ToString(iCat_affectation_slider_value_is[iCatPageis][iCat_select_editing_slider]),
                            xed+55,yed+132);

    if(mouse_x>xed+40 && mouse_x<xed+85 && mouse_y>yed+120 && mouse_y<yed+140 &&  window_focus_id==W_iCAT )
    {
        AffectVar.DrawOutline(CouleurLigne);
        if(  mouse_button==1 && mouse_released==0 && iCat_select_editing_slider!=0)
        {
            editing_GUI_type_iCat=1;
            int temp_number=atoi(numeric);
            reset_numeric_entry();
            switch(iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider])
            {
            case 1: //faders  lvl
                if(temp_number>48)
                {
                    temp_number=48;
                }
                break;
            case 2://faders speeed
                if(temp_number>48)
                {
                    temp_number=48;
                }
                break;
            case 4://seq scene et preset et vitesse
                if(temp_number>3)
                {
                    temp_number=3;
                }
                break;
            case 6:
                if(temp_number>16)
                {
                    temp_number=16;
                }
                break;
            case 7://draw
                if(temp_number>6)
                {
                    temp_number=6;
                }
                break;
            case 8://draw
                if(temp_number>6)
                {
                    temp_number=6;
                }
                break;
            case 9://draw
                if(temp_number>6)
                {
                    temp_number=6;
                }
                break;
            case 10://draw
                if(temp_number>6)
                {
                    temp_number=6;
                }
                break;
            case 15://echo
                break;

            default:
                break;
            }
            iCat_affectation_slider_value_is[iCatPageis][iCat_select_editing_slider]=temp_number;
            mouse_released=1;
        }
    }

    Rect DubB(Vec2D(xed-15,yed+150),Vec2D(30,15));

    petitpetitchiffre.Print("Dub",xed-10,yed+160);

    DubB.SetRoundness(4);
    DubB.Draw(CouleurFond.WithAlpha(0.4));

    if(mouse_x>xed-15 && mouse_x<xed+15 && mouse_y>yed+150 && mouse_y<yed+165
            && mouse_button==1 && mouse_released==0 && window_focus_id==W_iCAT)
    {
        editing_GUI_type_iCat=1;
        if(iCat_nbre_de_sliders[iCatPageis]<max_sliders_icat)
        {
            int iCatrefslider=iCat_select_editing_slider;
            iCat_nbre_de_sliders[iCatPageis]++;
            iCat_select_editing_slider=iCat_nbre_de_sliders[iCatPageis];
            iCat_orientation_slider[iCatPageis][iCat_select_editing_slider] = iCat_orientation_slider[iCatPageis][iCatrefslider] ;
            iCat_pos_slider[iCatPageis][iCat_select_editing_slider][0]=iCat_pos_slider[iCatPageis][iCatrefslider][0]+grid_icat_modulo;
            iCat_pos_slider[iCatPageis][iCat_select_editing_slider][1]=iCat_pos_slider[iCatPageis][iCatrefslider][1]+grid_icat_modulo;
            ratio_iCat_slider[iCatPageis][iCat_select_editing_slider]=ratio_iCat_slider[iCatPageis][iCatrefslider];
            iCat_affectation_slider_type_is[iCatPageis][iCat_select_editing_slider] = iCat_affectation_slider_type_is[iCatPageis][iCatrefslider];
            iCat_affectation_slider_value_is[iCatPageis][iCat_select_editing_slider] = iCat_affectation_slider_value_is[iCatPageis][iCatrefslider];

            sprintf(string_Last_Order,"Dubbed iCat Slider !");
        }
        mouse_released=1;
    }

    return(0);
}
