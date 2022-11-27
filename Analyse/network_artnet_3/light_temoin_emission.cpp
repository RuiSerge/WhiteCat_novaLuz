int light_temoin_emission(int outgoing_artnet, int x_diods, int y_diods)
{
Circle myartnet_temoin(x_diods+10+(outgoing_artnet*20), y_diods+10, 5.0, 5.0 );
myartnet_temoin.Draw( CouleurGreen.WithAlpha(alpha_blinker) );
return(0);
}
