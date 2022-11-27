int fader_niveau_son(int xp, int yp, int numero)
{
Rect FaderSon(Vec2D(xp,yp),Vec2D(20,127));
FaderSon.SetRoundness(5);
Rect FaderSonNiveau(Vec2D(xp,yp+(127-player_niveauson[numero])),Vec2D(20,player_niveauson[numero]));
FaderSonNiveau.Draw(CouleurFader);
FaderSon.DrawOutline(CouleurLigne.WithAlpha(0.5));

petitpetitchiffre.Print(string_niveauson[numero],xp+22,yp+10);
petitpetitchiffre.Print(ol::ToString(player_niveauson[numero]),xp+22,yp+20);

if(window_focus_id==919 && Midi_Faders_Affectation_Type!=0 && mouse_x>xp && mouse_x<xp+20 && mouse_y>=yp && mouse_y<=yp+127 )
{
FaderSon.DrawOutline(CouleurBlind);
}

Line (Vec2D(xp+20,yp+107),Vec2D(xp+30,yp+112)).Draw(CouleurLigne);

Circle(Vec2D(xp+37,yp+117),7).Draw(CouleurBlind.WithAlpha(midi_send_out[616+numero]));
Circle(Vec2D(xp+37,yp+117),7).DrawOutline(CouleurLigne);

raccrochage_midi_visuel_vertical(xp,yp,616+numero,20,127);

return(0);
}
