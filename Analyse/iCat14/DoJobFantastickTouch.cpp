int DoJobFantastickTouch()
{

    for(int tp=0; tp<fs_max_points+1; tp++) //nbre detectes vir�s, car si on lache un potard en cours on est plus au nombre de points limit�s en pos
    {
        check_button(tp);     //d'abord les boutons pou �viter d avoir des blocages avec les sliders
        check_slider(tp);
        check_tracker_zone(tp);
    }

    return(0);
}
