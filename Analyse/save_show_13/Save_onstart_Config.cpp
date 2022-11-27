int Save_onstart_Config()
{
FILE *fpp;
if((fpp=fopen("user/config_onstart.txt","w")))//etait wb
{
fprintf(fpp,"#arguments:values 0-1: open camera / open arduino / open iCat server / expert_mode /\n");
fprintf(fpp, "%d / %d / %d / %d /\n" ,  camera_on_open, open_arduino_on_open , enable_iCat, expert_mode);
fclose(fpp);  sprintf(string_save_load_report[idf],"Saved config_onstart.txt");
}


if( !fpp )
	{
	 sprintf(string_save_load_report[idf],"!user/config_onstart.txt");
   }
return(0);
}
