int Save_my_dmx_conf()
{

FILE *fp;
char rep_conf_dmx[1024];
sprintf(rep_conf_dmx,"%s\\user\\config_dmx.txt",mondirectory);
if((fp=fopen(rep_conf_dmx,"w")))
{
fprintf(fp,"#arguments: 1st line:  Unused / Art-Net / Enttec Open / Enttec Pro / Sunlite / Unused / Unused \n");
fprintf(fp,"%d / %d / %d / %d / %d / %d /\n",do_DMX_out[0],do_DMX_out[1],do_DMX_out[2],do_DMX_out[3],do_DMX_out[4],do_DMX_out[5]);
}
fclose(fp);
save_artnet_conf();

sprintf(string_Last_Order,">>Saved DMX configuration");
return(0);
}
