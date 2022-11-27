int launchpad_set_led(int control, int color)
{
if(miditable[0][control]<5 && miditable[1][control]<128 && miditable[2][control]<128)//pour éviter d'envoyer une note inexistante et de planter midishare
{
send_my_midi_note(miditable[0][control],miditable[1][control],miditable[2][control],color, 25);
}
 return(0);
}
