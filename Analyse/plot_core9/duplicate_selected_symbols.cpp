int duplicate_selected_symbols(int calc)
{
    int compteur=0;
    int new_position=0;

    for(int i=0; i<=nbre_symbols_on_plot[calc]; i++)
    {
        if( symbol_is_selected[calc][i]==1)
        {
            compteur++;
            new_position=nbre_symbols_on_plot[calc]+compteur;
            if(new_position<127)
            {
                symbol_type[calc][new_position]=symbol_type[calc][i];
                symbol_is_selected[calc][new_position]=symbol_is_selected[calc][i];
                angle_symbol[calc][new_position]=angle_symbol[calc][i];
                pos_symbol[calc][new_position][0]=pos_symbol[calc][i][0]+10;
                pos_symbol[calc][new_position][1]=pos_symbol[calc][i][1]+10;
                symbol_channel_is[calc][new_position]=symbol_channel_is[calc][i];

                for(int opt=0; opt<3; opt++) //aout 2016 était 5
                {
                    gelat[calc][new_position][opt]=gelat[calc][i][opt];
                    gelat_family[calc][new_position][opt]=gelat_family[calc][i][opt];
                }
                for(int opt=0; opt<5; opt++)
                {
                    relatif_plot_xy[calc][new_position][opt][0]=relatif_plot_xy[calc][i][opt][0];
                    relatif_plot_xy[calc][new_position][opt][1]=relatif_plot_xy[calc][i][opt][1];
                }
                symbol_channel_is[calc][new_position]=symbol_channel_is[calc][i];
                symbol_dimmer_is[calc][new_position]=0;                       //PAS LES DIMMERS SINON SOUCI D AFFECTATION AVEC LE PATCH
            }
            else
            {
                break;
            }
            symbol_is_selected[calc][i]=0;
        }
    }
    nbre_symbols_on_plot[calc]+=compteur;
    if(nbre_symbols_on_plot[calc]>127)
    {
        nbre_symbols_on_plot[calc]=127;   //rajout aout 2016
    }
    last_selected_symbol_is=nbre_symbols_on_plot[calc];
    plot_generate_appareils_list();

    return(0);
}
