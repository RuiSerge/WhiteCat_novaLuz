int do_keyboard_conf(int cfgnetw_X, int cfgnetw_Y)//ancienne version
{

    petitchiffre.Print("Keyboard Mapping: ",cfgnetw_X, cfgnetw_Y);
    Line(Vec2D(cfgnetw_X,cfgnetw_Y+5),Vec2D(cfgnetw_X+90,cfgnetw_Y+5)).Draw(CouleurLigne);
    sprintf(string_clavier_is,"Asc= %d Allg= %d KEY= %s ",scan_ascii_is,scan_allegro_key_is,string_key_id);
    petitchiffre.Print(string_clavier_is,cfgnetw_X,cfgnetw_Y+20);
    char str_iskeyfunct[25];
    for (int oi=0; oi<nbre_key_persos; oi++)
    {
        Rect keyParam(Vec2D(cfgnetw_X+60,cfgnetw_Y+25+(oi*30)),Vec2D(50,25));
        keyParam.SetRoundness(7.5);
        keyParam.SetLineWidth(epaisseur_ligne_fader);
        keyParam.Draw(CouleurFond.WithAlpha(0.5));
        switch(oi)
        {
        case 0:
            sprintf(str_iskeyfunct,"AT LEVEL");
            break;
        case 1:
            sprintf(str_iskeyfunct,"CH +");
            break;
        case 2:
            sprintf(str_iskeyfunct,"CH -");
            break;
        case 3:
            sprintf(str_iskeyfunct,"THRU");
            break;
        case 4:
            sprintf(str_iskeyfunct,"CLEAR");
            break;
        default:
            break;
        }
        if(mouse_x>cfgnetw_X+60 && mouse_x<cfgnetw_X+60+50 && mouse_y>cfgnetw_Y+25+(oi*30) && mouse_y<cfgnetw_Y+25+(oi*30)+25)
        {
            keyParam.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                int tmp_valAsc=atoi(numeric);
                if((tmp_valAsc>0 && tmp_valAsc<255)|| tmp_valAsc==999)//999 pour eviter de bloquer les commandes en 0 ascii , genre touches de fonctions
                {
                    mapping_temporaire[oi]=tmp_valAsc;
                }
                reset_numeric_entry();
                mouse_released=1;
            }
        }
        petitpetitchiffre.Print(str_iskeyfunct,cfgnetw_X,cfgnetw_Y+40+(oi*30));
        petitpetitchiffre.Print(ol::ToString(mapping_temporaire[oi]),cfgnetw_X+75,cfgnetw_Y+40+(oi*30));
    }

    return(0);
}
