int detection_reseaux()
{
for(int u=0;u<8;u++)
{
sprintf(IP_detected_dmxOUT[u],"-");
}

struct in_addr **addr_list;
addr_list = (struct in_addr **)phe->h_addr_list;


for(int p=0;addr_list[p]!=NULL;p++)
{
sprintf(IP_detected_dmxOUT[p] ,inet_ntoa(*addr_list[p]));
}


return(0);
}
