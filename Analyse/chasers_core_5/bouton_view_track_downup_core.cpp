int bouton_view_track_downup_core(int xcha, int ycha, bool state)
{
if( mouse_x>xcha+20-12 && mouse_x<xcha+20+12 && mouse_y>ycha+25-12 && mouse_y<ycha+25+12)
{
show_type_midi(976, "View Track UP");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(976,Midi_Faders_Affectation_Mode);
}
else
{
position_affichage_track_num[chaser_selected]--;
if(position_affichage_track_num[chaser_selected]<0){position_affichage_track_num[chaser_selected]=0;}
}
mouse_released=1;
}
if(mouse_x>xcha+20-12 && mouse_x<xcha+20+12 && mouse_y>ycha+55-12 && mouse_y<ycha+55+12)
{
show_type_midi(977, "View Track DOWN");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(977,Midi_Faders_Affectation_Mode);
}
else
{
position_affichage_track_num[chaser_selected]++;
if(position_affichage_track_num[chaser_selected]> core_user_define_nb_tracks_per_chasers-nbre_track_visualisables)
{position_affichage_track_num[chaser_selected]= core_user_define_nb_tracks_per_chasers-nbre_track_visualisables;}
mouse_released=1;
}
}
return(0);
}
