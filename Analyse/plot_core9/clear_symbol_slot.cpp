int clear_symbol_slot(int calc, int s)
{
    symbol_type[calc][s]=999;//999 hors liste
    symbol_is_selected[calc][s]=0;
    angle_symbol[calc][s]=0.0;
    pos_symbol[calc][s][0]=0;
    pos_symbol[calc][s][1]=0;
    stored_plot_position[s][0]=0;
    stored_plot_position[s][1]=0;
    symbol_channel_is[calc][s]=0;
    symbol_dimmer_is[calc][s]=0;
    gelat[calc][s][0]=0;
    gelat[calc][s][1]=0;
    gelat[calc][s][2]=0;
    gelat_family[calc][s][0]=0;
    gelat_family[calc][s][1]=0;
    gelat_family[calc][s][2]=0;
    symbol_is_linked_to[calc][s]=0;
    for(int opt=0; opt<5; opt++)
    {
        relatif_plot_xy[calc][s][opt][0]=0;
        relatif_plot_xy[calc][s][opt][1]=0;
    }
    for(int n=0; n<4; n++)
    {
        strcpy(symbol_note[calc][s][n],"");
    }

    clear_grouped_to_symbols(calc, s);
    return(0);
}
