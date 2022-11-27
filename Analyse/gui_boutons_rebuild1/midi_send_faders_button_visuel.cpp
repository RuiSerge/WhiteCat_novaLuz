int midi_send_faders_button_visuel(int Xb, int Yb)
{
Rect MidiMute_B(Vec2D(Xb,Yb),Vec2D(60,20));
MidiMute_B.SetRoundness(4);

MidiMute_B.DrawOutline(CouleurLigne);

petitpetitchiffre.Print("Midi Out",Xb+8,Yb+8);
petitpetitchiffre.Print("faders",Xb+10,Yb+18);
if(Midi_Faders_Affectation_Type!=0)
{
 MidiMute_B.DrawOutline(CouleurBlind);
 if(do_light_midi_send_on_faders==1)
 { MidiMute_B.Draw(CouleurFader);do_light_midi_send_on_faders=0;}
}
if(mouse_x>Xb && mouse_x<Xb+60 && mouse_y>Yb && mouse_y<Yb+20)
{
show_type_midi(1593, "MidiOUT Faders");
}
 return(0);
}
