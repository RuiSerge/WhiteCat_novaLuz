int refresh_hauteur_fenetre_grider()
{
    index_nbre_griderplayers_visibles=0;
    for(int yo=0; yo<core_user_define_nb_gridplayers; yo++)
    {
        if(index_show_grid_player[yo]==1)
        {
            index_nbre_griderplayers_visibles++;
        }
    }
    switch(show_global_view_grider)
    {
    case 0:
        hauteurGlobalGridviewer=0;
        break;
    case 1:
        hauteurGlobalGridviewer=100+(grider_nb_row*size_preview_case);
        break;
    default:
        break;
    }
    if(grider_nb_row>=10)
    {
        grider_facteur_hauteur=grider_nb_row;
    }
    else
    {
        grider_facteur_hauteur=10;
    }
    hauteurGrider=50+(index_nbre_griderplayers_visibles*(60+(grider_facteur_hauteur*size_grille)))+hauteurGlobalGridviewer;
    return(0);
}
