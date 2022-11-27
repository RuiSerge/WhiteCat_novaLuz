int raccrochage_midi_logical_horizontal_audio(int Xb, int Yb, int IDmidi, int largeur, int hauteur)
{

if(mouse_x>Xb+largeur+7 && mouse_x<Xb+largeur+13 && mouse_y>=Yb+hauteur+12 && mouse_y<=Yb+hauteur+18 )
{
if(mouse_button==1 && mouse_released==0)
{
is_raccrochage_midi_remote[IDmidi]=toggle(is_raccrochage_midi_remote[IDmidi]);
mouse_released=1;
}
}
return(0);
}
