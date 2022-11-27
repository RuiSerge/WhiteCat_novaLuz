int affect_dmx_in(int callb_x, int callb_y)
{
    Rect MonCallButton(Vec2D(callb_x,callb_y),Vec2D(100,30));
    MonCallButton.SetRoundness(7.5);
    MonCallButton.SetLineWidth(demi_epaisseur_ligne_fader);

    MonCallButton.DrawOutline(CouleurLigne);

    if (index_affect_dmxin==1)
    {
        MonCallButton.Draw(CouleurFader);
        MonCallButton.DrawOutline(CouleurFader);
    }
    petitchiffre.Print("DmxIn>Dock",callb_x+5, callb_y+20);
    if(window_focus_id==W_CFGMENU && mouse_x>callb_x && mouse_x<callb_x+100 && mouse_y>callb_y && mouse_y<callb_y+30 && window_focus_id==920)
    {
        if(mouse_button==1 && mouse_released==0)
        {
            if(index_affect_dmxin==0)
            {
                reset_index_actions();
                reset_indexs_confirmation();
                index_affect_dmxin=1;
            }
            else
            {
                reset_index_actions();
            }
            index_do_dock=index_affect_dmxin;
            mouse_released=1;
        }
    }

    return(0);
}
