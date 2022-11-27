int diodes_artnet(int x_diods, int y_diods)
{
    petitchiffre.Print("Art-Net:",x_diods, y_diods);
    for(int dd=0; dd<16; dd++)
    {
        Circle myartnet_diode_vide( x_diods+10+(dd*20), y_diods+10, 5.0, 5.0 );
        myartnet_diode_vide.DrawOutline(CouleurLigne.WithAlpha(0.2));
    }
    return(0);
}
