int config_general_menu()
{
    //Dessine le cadre de fond avec couleur du pourtour selon que la fenêtre a le focus ou non
    Rect CadreGeneralConfig(Vec2D(window_cfgX,window_cfgY),Vec2D(largeurCFGwindow,hauteurCFGwindow+40));
    CadreGeneralConfig.SetRoundness(15);
    CadreGeneralConfig.SetLineWidth(triple_epaisseur_ligne_fader);
    CadreGeneralConfig.Draw(CouleurConfig);

    if(window_focus_id==W_CFGMENU)
    {
        CadreGeneralConfig.DrawOutline(CouleurBlind);
    }
    else
    {
        CadreGeneralConfig.DrawOutline(CouleurLigne);
    }

    // Groupe d'onglets
    int nbr_onglets = 8; // sab 12/08/2016 :  nbr_onglets (7 -> 8)
    std::vector <char*> onglet_libelle (nbr_onglets);
    onglet_libelle[0]= "DMX cfg";
    onglet_libelle[1]= "Midi cfg";
    onglet_libelle[2]= "Network";
    onglet_libelle[3]= "Screen";
    onglet_libelle[4]= "Arduino";
    onglet_libelle[5]= "GENERAL";
    onglet_libelle[6]= "Core cfg";
    onglet_libelle[7]= "Hotkeys";

    int grp_tab_espace_bord_left_X  = 90;
    int grp_tab_espace_bord_right_X = 10;
    int grp_tab_espace_bord_top_Y   = 5;

    //Dessine les onglets de la fenêtre de configuration et détecte si l'on a cliqué sur l'un d'eux
	int grp_tab_largeur 	= largeurCFGwindow - grp_tab_espace_bord_left_X - grp_tab_espace_bord_right_X;
	//
    int zone_onglet_largeur(floor(grp_tab_largeur / nbr_onglets)) ;  // floor --> arrondi inférieur ; ceil--> arrondi supérieur
    int espace_entre_onglet = 10 ;
    //
    int onglet_largeur 		= zone_onglet_largeur - espace_entre_onglet;
    int onglet_hauteur		= 40 ;
	//
    int grp_tab_X 			= window_cfgX + zone_onglet_largeur;  //position X sur l'écran  du groupe d'onglets
	//
	int espace_bord_txt_X 	= 5; //position du texte par rapport au bord ue l'onglet
	int espace_bord_txt_Y   = 25 ;

    for (int choix=0; choix < nbr_onglets ; choix++)
    {
        Rect CadreOnglet(Vec2D( grp_tab_X+(choix * zone_onglet_largeur),
								window_cfgY + grp_tab_espace_bord_top_Y),
						 Vec2D( onglet_largeur, onglet_hauteur));
        CadreOnglet.SetRoundness(7.5);
        CadreOnglet.Draw(CouleurBleuProcedure.WithAlpha(0.8));
		//
        if(config_page_is==choix+1)
        {
            CadreOnglet.SetLineWidth(epaisseur_ligne_fader/2);
            CadreOnglet.DrawOutline(CouleurLigne);
            CadreOnglet.Draw(CouleurConfig.WithAlpha(1));
        }
        // Logical
        if((hk_manager.hk_user_update_isOn()!=true)  // pas de mouse effect si en attente de saisie d'une hotkey pou redefinir le lien avec une fonction
			&& mouseOverTab_W_CFGMENU(choix, grp_tab_X, espace_entre_onglet, onglet_largeur, onglet_hauteur, grp_tab_espace_bord_top_Y))
        {
            if(config_page_is!=choix+1)
            {
                CadreOnglet.Draw(CouleurSurvol);
            }

            if(mouseClicLeft.isDown() && mouseClicLeft.isToBeProcessed() && window_focus_id==W_CFGMENU)
            {
                config_page_is=choix+1;

                reset_indexes_conf();
                switch(choix)
                {
                case 0 :
                	index_config_dmx=1;
                    break;
                case 1 :
                    index_config_midi=1;
                    break;
                case 2 :
                    index_config_network=1;
                    break;
                case 3 :
                    index_setup_gfx=1;
                    break;
                case 4 :
                    index_config_arduino=1;
                    break;
                case 5 :
                    index_config_general=1;
                    break;
                case 6 :
                    index_config_core=1;
                    break;
                case 7 :
                    index_config_tab_hotkeys = true;
                    break;
                }
                mouseClicLeft.SetProcessed();
            }
        }
        neuromoyen.Print(onglet_libelle[choix],
						 grp_tab_X + (choix*zone_onglet_largeur) + espace_bord_txt_X,
						 window_cfgY + grp_tab_espace_bord_top_Y + espace_bord_txt_Y,
						 onglet_largeur - 2 * espace_bord_txt_X,	//espace dispo en largeur pour le texte
						 CENTER);
    }

    //fond panneau de l'onglet
    Rect ConfigPanel(Vec2D( window_cfgX, window_cfgY + onglet_hauteur), 			//recouvre le bas des onglets
					 Vec2D( largeurCFGwindow, hauteurCFGwindow));
    ConfigPanel.SetRoundness(15);
    ConfigPanel.Draw(CouleurConfig);
    ConfigPanel.DrawOutline(CouleurLigne);
    //efface ligne entre onglet actif et son panneau
    Rect CleanLine( Vec2D( 	grp_tab_X + ((config_page_is-1) * zone_onglet_largeur),
								window_cfgY + onglet_hauteur - epaisseur_ligne_fader),
						Vec2D(  onglet_largeur, epaisseur_ligne_fader * 4 ));
    CleanLine.Draw(CouleurBleuProcedure.WithAlpha(1));
    CleanLine.Draw(CouleurConfig.WithAlpha(1));

    do_panel_config(window_cfgX, window_cfgY + onglet_hauteur);

    return(0);
}
