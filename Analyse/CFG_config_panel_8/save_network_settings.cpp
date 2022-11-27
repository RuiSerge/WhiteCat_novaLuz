int save_network_settings()
{
FILE *fp;
char rep_conf_ntwk[512];
sprintf(rep_conf_ntwk,"%s\\user\\config_network.txt",mondirectory);
if((fp=fopen(rep_conf_ntwk,"w")))
{

fprintf(fp,"#arguments: Receive art-net Socket  \n");
fprintf(fp,"%s\n",IP_artnet_IN);
fprintf(fp,"#arguments: Send art-net Socket \n");
fprintf(fp,"%s\n",IP_artnet_OUT);
fprintf(fp,"#arguments: Art-net UDP PORT IN / UDP PORT OUT \n");
fprintf(fp,"%d / %d /\n",serveurport_artnet, clientport_artnet);
fprintf(fp,"#arguments: Fantastick-iCat Socket /\n");
fprintf(fp,"%s\n",IP_fantastick);
fprintf(fp,"#arguments: Fantastick-iCat  SEND TO adress ( iPhone/iPad) \n");
fprintf(fp,"%s\n",specified_fs_ip);
fprintf(fp,"Fantastick-iCat UDP PORT IN from FS / iCat UDP PORT OUT TO FS / Iterations /\n");
fprintf(fp,"%d / %d / %d /\n",serveurport_iCat,clientport_iCat,nbre_d_envois_de_l_info);

}
fclose(fp);
sprintf(string_Last_Order,">>Saved Network configuration");
return(0);
}
