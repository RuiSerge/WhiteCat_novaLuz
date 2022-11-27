int do_network_config( int x_cfg_sc,int y_cfg_sc, int largeur_cfg_sc, int hauteur_cfg_sc)
{

Canvas::SetClipping( x_cfg_sc, y_cfg_sc, largeur_cfg_sc, hauteur_cfg_sc);

Box_IP_routing (  x_cfg_sc+20, y_cfg_sc+70);
do_artnet_affect_config(x_cfg_sc+20, y_cfg_sc+250);

Box_artnet_udpport(x_cfg_sc+240, y_cfg_sc+40);
BoxiCat(x_cfg_sc+240, y_cfg_sc+150);



Canvas::DisableClipping();
return(0);
}
