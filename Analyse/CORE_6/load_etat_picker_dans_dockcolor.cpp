int load_etat_picker_dans_dockcolor(int dcolor_selected )
{
    index_quadri=dock_color_type[dcolor_selected];
    picker_x=x_y_picker_par_colordock[dcolor_selected][0];
    picker_y=x_y_picker_par_colordock[dcolor_selected][1];
    angle_snap=angle_hue_par_colordock[dcolor_selected];

    vx = cos(angle_snap)*125;
    vy = sin(angle_snap)*125;
    position_curseur_hue_x= xtrichro_window+vx;
    position_curseur_hue_y=ytrichro_window+vy ;

    r_pick=picker_trichro[dcolor_selected][0];
    v_pick=picker_trichro[dcolor_selected][1];
    b_pick=picker_trichro[dcolor_selected][2];
    my_yellow=picker_trichro[dcolor_selected][3];
    midi_levels[497]=(int)(angle_snap/((PI*360) / (180*127)));
    if(midi_send_out[497]==1)
    {
        index_send_midi_out[497]=1;
    }
    return(0);
}
