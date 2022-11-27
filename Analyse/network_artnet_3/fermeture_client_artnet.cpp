int fermeture_client_artnet()
{
 	shutdown(sockartnet,2);
    closesocket(sockartnet);
    sprintf(string_Last_Order,">>Closed Art-Net Client");
    client_artnet_is_closed=1;
 return(0);
}
