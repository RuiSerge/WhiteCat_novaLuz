int show_foreground_chrono(int xtime, int ytime)
{
    Rect Bckg_b(Vec2D(xtime-10,ytime),Vec2D(270,60));
    Bckg_b.SetRoundness(15);
    Bckg_b.Draw(CouleurFond.WithAlpha(0.7));
    Bckg_b.SetLineWidth(triple_epaisseur_ligne_fader);
    Bckg_b.DrawOutline( CouleurLigne.WithAlpha(0.5) );
    neuroTitle.Print(visu_big_chrono, xtime+15, ytime+50,240,RIGHT);

    return(0);
}
