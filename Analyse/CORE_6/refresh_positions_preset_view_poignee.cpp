int refresh_positions_preset_view_poignee()
{


    total_pixel_vision=0;

    for(int i=0; i<nbre_de_vues_circuits; i++)
    {
        if(Channel_View_MODE[i]==1)
        {
            total_pixel_vision+=(70*channel_number_of_lines[i])+ hauteur_preset_titre;
            scroll_pos_preset[i]= total_pixel_vision;
        }
    }

    ratioview=270.0/total_pixel_vision;
    return(0);
}
