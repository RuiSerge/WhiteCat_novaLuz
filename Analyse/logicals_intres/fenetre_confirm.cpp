int fenetre_confirm()
{
    entetes_confirmation();

    Rect FenetreConfirm(Vec2D(XConfirm,YConfirm),Vec2D(400,100));
    FenetreConfirm.SetRoundness(15);
    FenetreConfirm.SetLineWidth(epaisseur_ligne_fader*3);
    FenetreConfirm.Draw(CouleurFond);
    FenetreConfirm.Draw(CouleurBlind.WithAlpha(alpha_blinker));
    if(window_focus_id==W_ASKCONFIRM)
    {
        FenetreConfirm.DrawOutline(CouleurFader);
    }
    else
    {
        FenetreConfirm.DrawOutline(CouleurLigne);
    }

    neuromoyen.Print( string_confirmation,XConfirm+110,YConfirm+10+18, 250,  JUSTIFY);


    Rect EscBox(Vec2D(XConfirm+110,YConfirm+60),Vec2D(70,30));
    EscBox.SetRoundness(7.5);
    EscBox.Draw(CouleurFond);

    if(mouse_x>XConfirm+110 && mouse_x<XConfirm+110+70 && mouse_y>YConfirm+60 && mouse_y<YConfirm+60+30 && window_focus_id==W_ASKCONFIRM)
    {
        EscBox.Draw(CouleurFader);
        if(mouse_button==1 && mouse_released==0)
        {
            reset_indexs_confirmation();
            reset_index_actions();
            substract_a_window(W_ASKCONFIRM);
            substract_a_window(previous_window_focus_id);
            mouse_released=1;
            window_focus_id=previous_window_focus_id;
            add_a_window(window_focus_id);
        }
    }
    EscBox.DrawOutline(CouleurLigne);
    petitchiffre.Print("ESC",XConfirm+110+18, YConfirm+60+18);

    Rect OkBox(Vec2D(XConfirm+240,YConfirm+60),Vec2D(70,30));
    OkBox.SetRoundness(7.5);
    OkBox.Draw(CouleurFond);
    if(mouse_x>XConfirm+240 && mouse_x<XConfirm+240+70 && mouse_y>YConfirm+60 && mouse_y<YConfirm+60+30  && window_focus_id==W_ASKCONFIRM)
    {
        OkBox.Draw(CouleurFader);
        if(mouse_button==1 && mouse_released==0)
        {
            operations_confirmation();
            reset_index_actions();
            reset_indexs_confirmation();
            mouse_released=1;
            substract_a_window(W_ASKCONFIRM);
            window_focus_id=previous_window_focus_id;
            add_a_window(window_focus_id);
        }
    }
    OkBox.DrawOutline(CouleurLigne);
    petitchiffre.Print("OK",XConfirm+245+18, YConfirm+60+18);

    if(expert_mode==1)
    {
        operations_confirmation();
        reset_index_actions();
        reset_indexs_confirmation();
        mouse_released=1;
        substract_a_window(W_ASKCONFIRM);
        window_focus_id=previous_window_focus_id;
    }

    return(0);
}
