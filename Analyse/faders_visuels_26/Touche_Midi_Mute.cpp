int Touche_Midi_Mute(int xmute, int ymute)
{
    Rect BmidiMute(Vec2D(xmute,ymute),Vec2D(int(72),25));
    BmidiMute.SetRoundness(7.5);
    BmidiMute.SetLineWidth(epaisseur_ligne_fader);

    BmidiMute.Draw(CouleurFader.WithAlpha(alpha_blinker*index_midi_mute));
    BmidiMute.DrawOutline(CouleurLigne);
    petitchiffre.Print("Mute MidiIN",xmute+3,ymute+15);
    return(0);
}
