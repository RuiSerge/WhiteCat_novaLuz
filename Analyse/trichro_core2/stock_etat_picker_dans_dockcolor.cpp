int stock_etat_picker_dans_dockcolor(int dcolor_selected)
{
dock_color_type[dcolor_selected]=index_quadri;
x_y_picker_par_colordock[dcolor_selected][0]=(int)picker_x;
x_y_picker_par_colordock[dcolor_selected][1]=(int)picker_y;
angle_hue_par_colordock[dcolor_selected]=angle_snap;
picker_trichro[dcolor_selected][0]=r_pick;
picker_trichro[dcolor_selected][1]=v_pick;
picker_trichro[dcolor_selected][2]=b_pick;
picker_trichro[dcolor_selected][3]=my_yellow;

return(0);
}
