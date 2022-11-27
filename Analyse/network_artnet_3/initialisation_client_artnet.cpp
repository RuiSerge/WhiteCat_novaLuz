int initialisation_client_artnet()
{
    detection_mise_en_place_carte_reseaux();
    /*
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0),&wsa);

    //adresse locale et nom de machine
     gethostname(hostnamebuffer, sizeof(hostnamebuffer));
     phe = gethostbyname(hostnamebuffer);

     int Ipsearch = 0;
     while((phe->h_addr_list[Ipsearch+1])!=NULL)
     {
     Ipsearch++;
     }
     detection_reseaux();
    */
    /*
    memcpy(&sinS.sin_addr.s_addr, phe->h_addr_list[network_OUT_is_selected], phe->h_length);

     sprintf(string_ip,inet_ntoa(sinS.sin_addr));

     //extraction en tableau de 4 char

     sscanf (string_ip, "%d.%d.%d.%d", my_ip_is, my_ip_is + 1,
                           my_ip_is + 2, my_ip_is + 3);

    //               printf ("\nI am: %d.%d.%d.%d\n", (unsigned char)my_ip_is[0], (unsigned char)my_ip_is[1],
    //                      (unsigned char)my_ip_is[2],(unsigned char)my_ip_is[3]);

    */

    sinS.sin_family=AF_INET;
    sinS.sin_addr.s_addr=inet_addr(ip_artnet);
    sinS.sin_port=htons( clientport_artnet);

    sockartnet=socket(AF_INET,SOCK_DGRAM,0); //On initialise le socket avec SOCK_DGRAM pour dire qu'on est en UDP

    if(index_broadcast==1)//init broadcast mode, sinon est en unicast
    {
        if (setsockopt(sockartnet, SOL_SOCKET, SO_BROADCAST, &broadcast,
                       sizeof broadcast) == -1)
        {
            perror("setsockopt (SO_BROADCAST)");
            exit(1);
        }
    }

    bind(sockartnet,(SOCKADDR*)&sinS,sizeof(sinS)); //Liaison entre la structure et la socket


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
