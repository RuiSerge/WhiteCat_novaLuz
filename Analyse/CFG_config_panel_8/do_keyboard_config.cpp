int do_keyboard_config( int x_cfg,int y_cfg, int largeur_cfg, int hauteur_cfg)
{
    petitchiffre.Print("KEYBOARD MAPPING",x_cfg, y_cfg);
    Rect OverKey(Vec2D(x_cfg,y_cfg),Vec2D(60,20));
    OverKey.SetRoundness(1.8);
    Rect Function(Vec2D(x_cfg,y_cfg),Vec2D(120,20));
    Function.SetRoundness(1.8);
    Rect Param(Vec2D(x_cfg,y_cfg),Vec2D(30,20));
    Param.SetRoundness(1.8);
    for(int i=0; i<10; i++)
    {
        OverKey.MoveTo(Vec2D(x_cfg,y_cfg+15+(i*25)));
        OverKey.Draw(CouleurGreen.WithAlpha(0.5));
        Function.MoveTo(Vec2D(x_cfg+75,y_cfg+15+(i*25)));
        Function.Draw(CouleurBlind.WithAlpha(0.5));
        Param.MoveTo(Vec2D(x_cfg+205,y_cfg+15+(i*25)));
        Param.Draw(CouleurBlind.WithAlpha(0.5));
        petitchiffre.Print(kbd_custom[index_liste_kbd_custom+i],x_cfg+10,y_cfg+20+(i*25));
    }
    return(0);
}
