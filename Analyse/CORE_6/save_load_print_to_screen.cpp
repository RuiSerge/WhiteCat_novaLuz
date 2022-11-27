void save_load_print_to_screen(const std::string label)
{
    const std::string string_print_to_screen = label.substr (0,64);

    if(index_do_quick_save==0)
    {
        show_title();
    }
    Rect nameAera( Vec2D( ((largeur_ecran/2)-200),((hauteur_ecran/2)-100)), Vec2D ( 400,70));
    nameAera.SetRoundness(15);
    nameAera.SetLineWidth(epaisseur_ligne_fader*3);
    nameAera.Draw(CouleurSurvol);
    nameAera.DrawOutline(CouleurLigne);
    neuro.Print(string_print_to_screen,((largeur_ecran/2)-150),((hauteur_ecran/2)-60));

    write_text_to_log_file("");
    write_text_to_log_file(string_print_to_screen);
    write_text_to_log_file(rep);
    Canvas::Refresh();
}
