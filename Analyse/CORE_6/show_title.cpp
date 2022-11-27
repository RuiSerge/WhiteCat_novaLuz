int show_title()
{
    logo.Blit((largeur_ecran/2)-150,(hauteur_ecran/2));//ne s'affiche que en 32 bits
    neuroTitle.Print("WHITE CAT", (largeur_ecran/2)-200,(hauteur_ecran/2)-200);
    neuromoyen.Print(nickname_version, (largeur_ecran/2)+200,(hauteur_ecran/2)-260);
    neuro.Print("http://www.le-chat-noir-numerique.fr", (largeur_ecran/2)-160,(hauteur_ecran/2)-170);
    petitchiffre.Print("(c)christoph guillermet", (largeur_ecran/2)-55,(hauteur_ecran/2)-150);
    petitpetitchiffre.Print(versionis, (largeur_ecran/2)-70,(hauteur_ecran/2)-120);

    return(0);
}
