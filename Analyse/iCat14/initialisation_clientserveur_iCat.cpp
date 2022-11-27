int initialisation_clientserveur_iCat()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0),&wsa);
    sinServiCat.sin_family=AF_INET;
    sinServiCat.sin_addr.s_addr= inet_addr(IP_fantastick);

    sinServiCat.sin_port=htons(serveurport_iCat);
    sockRiCat=socket(AF_INET,SOCK_DGRAM,0);
    bind(sockRiCat,(SOCKADDR*)&sinServiCat,sizeof(sinServiCat));
    u_long imode = 1;
    ioctlsocket(sockRiCat, FIONBIO, &imode);
    sinsizeServiCat=sizeof(sinServiCat);
    sprintf(string_Last_Order,"Fantastick Server initialized");

    memset(fantastick_message,0,sizeof(fantastick_message));
    iCat_serveur_is_initialized=1;

    gethostname(hostnamebuffer, sizeof(hostnamebuffer));
    phe = gethostbyname(hostnamebuffer);
    int Ipsearch = 0;
    while((phe->h_addr_list[Ipsearch+1])!=NULL)
    {
        Ipsearch++;
    }
    detection_reseaux();


    siniCat.sin_family=AF_INET;
    siniCat.sin_addr.s_addr=inet_addr(specified_fs_ip);
    siniCat.sin_port=htons( clientport_iCat);
    sockiCat=socket(AF_INET,SOCK_DGRAM,0); //On initialise le socket avec SOCK_DGRAM pour dire qu'on est en UDP
    bind(sockiCat,(SOCKADDR*)&siniCat,sizeof(siniCat)); //Liaison entre la structure et la socket


    sinsizeiCat=sizeof(siniCat);
    char test_chaine[32]= {"opengl 1"};
    nbrbytessendediCat=sendto(sockiCat,  test_chaine,sizeof(test_chaine),0,(SOCKADDR*)&siniCat,sinsizeiCat);
    sprintf(test_chaine,"clearmodels");
    nbrbytessendediCat=sendto(sockiCat,  test_chaine,sizeof(test_chaine),0,(SOCKADDR*)&siniCat,sinsizeiCat);

    client_icat_is_closed=0;
    index_re_init_clientserveur_icat=0;
    return(0);
}
