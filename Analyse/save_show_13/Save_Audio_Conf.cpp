int Save_Audio_Conf()
{
FILE *fpo;
if((fpo=fopen("audio_conf.txt","w")))
{
fprintf(fpo,"#arguments: audiofolder\n");
fprintf(fpo,"%s\n",audio_folder);
sprintf(string_save_load_report[idf],"Saved audio_conf.txt");
fclose(fpo);
}
else {sprintf(string_save_load_report[idf],"Error on audio_conf.txt");b_report_error[idf]=1; fclose(fpo);}

return(0);
}
