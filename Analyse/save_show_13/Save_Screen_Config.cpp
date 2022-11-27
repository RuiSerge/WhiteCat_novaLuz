int Save_Screen_Config()
{
FILE *fpp;
if((fpp=fopen("user/config_screens.txt","w")))//etait wb
{
fprintf(fpp,"#arguments: fullscreen / largeur_ecran / hauteur_ecran / pos_x / pos_y\n");
fprintf(fpp, "%d / %d %d / %d %d /\n" , index_fullscreen, largeur_ecran, hauteur_ecran, posX_mainwindow, posY_mainwindow);
fclose(fpp);  sprintf(string_save_load_report[idf],"Saved config_screen.txt");
}


if( !fpp )
	{
	 sprintf(string_save_load_report[idf],"!user/config_screens.txt");
   }
return(0);
}
