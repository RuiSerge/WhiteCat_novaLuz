int detection_mise_en_place_carte_reseaux()
{
WSADATA wsa;
WSAStartup(MAKEWORD(2,0),&wsa);
 gethostname(hostnamebuffer, sizeof(hostnamebuffer));
 phe = gethostbyname(hostnamebuffer);

 int Ipsearch = 0;
 while((phe->h_addr_list[Ipsearch+1])!=NULL)
 {
 Ipsearch++;
 }
 detection_reseaux();
return(0);
}
