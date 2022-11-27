int raccrochage_midi_logical_vertical(int Xb, int Yb, int IDmidi, int largeur, int hauteur)
{

if(mouse_x>Xb+largeur+6 && mouse_x<Xb+largeur+14 && mouse_y>=Yb+hauteur-1 && mouse_y<=Yb+hauteur+9)
{
if(mouse_button==1 && mouse_released==0)
{
is_raccrochage_midi_remote[IDmidi]=toggle(is_raccrochage_midi_remote[IDmidi]);
mouse_released=1;
}
}
return(0);
}
