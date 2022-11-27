int initialisation_client_artnet()
{
detection_mise_en_place_carte_reseaux();
*/
*/

sinS.sin_family=AF_INET;
sinS.sin_addr.s_addr=inet_addr(ip_artnet);
sinS.sin_port=htons( clientport_artnet);

sockartnet=socket(AF_INET,SOCK_DGRAM,0); //On initialise le socket avec SOCK_DGRAM pour dire qu'on est en UDP

if(index_broadcast==1)//init broadcast mode, sinon est en unicast
{
 if (setsockopt(sockartnet, SOL_SOCKET, SO_BROADCAST, &broadcast,
        sizeof broadcast) == -1) {
        perror("setsockopt (SO_BROADCAST)");
        exit(1);
    }
}

bind(sockartnet,(SOCKADDR*)&sinS,sizeof(sinS)); //Liaison entre la structure et la socket


 //non-blocking mode setting avec ioctlsocket
u_long imode = 1;
ioctlsocket( sockartnet, FIONBIO, &imode);

sinsize=sizeof(sinS);


sprintf(string_Last_Order,">>Init Art-net OK:  %s /port: %d", ip_artnet,clientport_artnet);

if (index_broadcast==1)
	{
	sprintf(string_display_dmx_params,"ART-NET: Broadcast to network %s Univ. %d",ip_artnet, Univers);
    }
else if (index_broadcast==0)
	{
	sprintf(string_display_dmx_params,"ART-NET: Unicast to %s Univ. %d",ip_artnet, Univers);
    }
client_artnet_is_closed=0;
return(0);
}
