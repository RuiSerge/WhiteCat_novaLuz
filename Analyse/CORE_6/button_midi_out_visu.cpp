int button_midi_out_visu(int xmi, int ymi, int control)
{
    Circle BMidiOut( xmi,ymi, 10);//box du fader
    BMidiOut.SetLineWidth(epaisseur_ligne_fader);

    if(midi_send_out[control]==1)
    {
        BMidiOut.Draw(CouleurBlind);
    }
    BMidiOut.DrawOutline(CouleurLigne.WithAlpha(0.5));

    return(0);
}
