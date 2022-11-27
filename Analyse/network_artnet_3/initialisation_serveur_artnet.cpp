int initialisation_serveur_artnet()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0),&wsa);

    sinServ.sin_family=AF_INET;
    sinServ.sin_addr.s_addr=inet_addr(IP_artnet_IN);
    sinServ.sin_port=htons(serveurport_artnet);
    sock=socket(AF_INET,SOCK_DGRAM,0);
    bind(sock,(SOCKADDR*)&sinServ,sizeof(sinServ));
    u_long imode = 1;
    ioctlsocket(sock, FIONBIO, &imode);
    sinsizeServ=sizeof(sinServ);
    sprintf(string_Last_Order,"Art-Net Server initialized");
    memset(artnet_message,0,sizeof(artnet_message));
    gethostname(hostnamebuffer, sizeof(hostnamebuffer));
    phe = gethostbyname(hostnamebuffer);
    int Ipsearch = 0;
    while((phe->h_addr_list[Ipsearch+1])!=NULL)
    {
        Ipsearch++;
    }
    detection_reseaux();

    memcpy(&sinServ.sin_addr.s_addr, phe->h_addr_list[network_OUT_is_selected], phe->h_length);

    artnet_serveur_is_initialized=1;
    return(0);
}
