int my_window_Box(int mx, int my)
{
    Rect fond_my_window(Vec2D(mx,my), Vec2D( largeur_my_window,hauteur_my_window));
    fond_my_window.SetRoundness(15);
    fond_my_window.SetLineWidth(triple_epaisseur_ligne_fader);
    fond_my_window.Draw(CouleurFond);
    if(window_focus_id==W_MY_WINDOW)//si elle est sélectionnée bord orange
    {
        fond_my_window.DrawOutline(CouleurFader);
    }
    else
    {
        fond_my_window.DrawOutline(CouleurLigne);
    }
    neuro.Print( "My Window",(mx+110), (my+30));

    loop_button_view(mx+260,my+100,my_window_variable_boolean);


    Rect FaderFrame(Vec2D(mx,my),Vec2D(20,127));
    FaderFrame.SetRoundness(3);

    for(int i=0; i<6; i++)
    {
        petitchiffre.Print(ol::ToString(my_window_fader_value[i] ),mx+12+(i*35),my+58);
        FaderFrame.MoveTo(Vec2D(mx+10+(i*35),my+70));
        Rect FaderLevel(Vec2D(mx+10+(i*35),my+70+127-my_window_fader_value[i] ), Vec2D(20,my_window_fader_value[i] ));
        FaderLevel.SetRoundness(3);
        FaderLevel.Draw(CouleurFader);
        FaderFrame.DrawOutline(CouleurLigne);
    }

    return(0);
}
