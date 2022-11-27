bool mouseOverTab_W_CFGMENU(int tabNum, int espace_au_bord_X, int espace_entre_onglet, int largeur_onglet, int hauteur_onglet, int espace_au_bord_Y)
{
    int onglet_zone_X = espace_entre_onglet + largeur_onglet;

    return  (window_focus_id==W_CFGMENU
             && mouse_x > (espace_au_bord_X + tabNum * onglet_zone_X)
             && mouse_x < (espace_au_bord_X + tabNum * onglet_zone_X + largeur_onglet)
             && mouse_y > (window_cfgY + espace_au_bord_Y)
             && mouse_y < (window_cfgY + espace_au_bord_Y + hauteur_onglet) );
}
