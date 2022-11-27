int bouton_view_launchpad_pos_core(int xcha, int ycha, bool state)
{

if( mouse_x>xcha+20-12 && mouse_x<xcha+20+12 && mouse_y>ycha+25-12 && mouse_y<ycha+25+12)
{
show_type_midi(1113, "Launchpad Ctrl Pos Minus");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1113,Midi_Faders_Affectation_Mode);
}
else
{
chaser_step_launchpad[chaser_selected]--;
if(chaser_step_launchpad[chaser_selected]<0){chaser_step_launchpad[chaser_selected]=0;}
}
mouse_released=1;
}
if(mouse_x>xcha+50-12 && mouse_x<xcha+50+12 && mouse_y>ycha+25-12 && mouse_y<ycha+25+12)
{
show_type_midi(1114, "Launchpad Ctrl Pos Plus");
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1114,Midi_Faders_Affectation_Mode);
}
else
{
chaser_step_launchpad[chaser_selected]++;
if(chaser_step_launchpad[chaser_selected]>nbre_de_cases_par_track-8 ) {chaser_step_launchpad[chaser_selected]=nbre_de_cases_par_track-8;}
}
mouse_released=1;
}
return(0);
}
