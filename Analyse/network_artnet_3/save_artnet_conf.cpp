int save_artnet_conf()
{
    FILE *fp;
    char rep_conf_dmx[1024];
    sprintf(rep_conf_dmx,"%s\\user\\config_artnet.txt",mondirectory);
    if((fp=fopen(rep_conf_dmx,"w")))
    {
        fprintf(fp,"#arguments: broadcast (1) ou unicast (0) // puis Univers Dmx surlequel envoyer ( 0 à 15)");
        fprintf(fp,"\n%d %d",index_broadcast,Univers);
        fprintf(fp,"\n#arguments: si en broadcast: l'adresse doit etre de type X.X.X. / si en unicast X.X.X.X");
        fprintf(fp,"\n%s",ip_artnet);
    }
    fclose(fp);
    return(0);
}
