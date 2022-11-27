int recalculate_draw_sizes(int  preset)
{
    draw_largeur_case[preset]=555/draw_preset_parameters[preset][0];
    draw_hauteur_case[preset]=430/draw_preset_parameters[preset][1];
    draw_modulo_largeur_case[preset]=draw_tracking_aera_size_x%draw_preset_parameters[preset][0];
    draw_modulo_hauteur_case[preset]=draw_tracking_aera_size_y%draw_preset_parameters[preset][1];
    draw_tracking_aera_size_x=(draw_largeur_case[preset]*draw_preset_parameters[preset][0])+ draw_modulo_largeur_case[preset];
    draw_tracking_aera_size_y=(draw_hauteur_case[preset]*draw_preset_parameters[preset][1])+ draw_modulo_hauteur_case[preset];
    return(0);
}
