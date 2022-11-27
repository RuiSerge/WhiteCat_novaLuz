int fermeture_serveur_artnet()
{
 	shutdown(sock,2);
    closesocket(sock);
    sprintf(string_Last_Order,">>Closed Art-Net serveur");
    artnet_serveur_is_initialized=0;
 return(0);
}
