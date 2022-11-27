int Save_Core_Config()
{
FILE *fpp;
if((fpp=fopen("user/config_core.txt","w")))//etait wb
{
fprintf(fpp,"#arguments: nb_faders / nb_docks / nb_chasers/ nb_tracks per chasers / nb_gridplayers / nb_bangers /\n");
fprintf(fpp, "%d / %d / %d / %d / %d / %d / %d /\n" , core_user_define_nb_faders, core_user_define_nb_docks ,core_user_define_nb_chasers,
core_user_define_nb_tracks_per_chasers,core_user_define_nb_gridplayers,core_user_define_nb_bangers,core_user_define_nb_echo);
fprintf(fpp,"#arguments: do faders (0-1) /do cuelist (0-1) / do bangers (0-1)/ do trichro (0-1) / do videotracking (0-1) / do chasers (0/1) / do Grid (0-1) /\n");
fprintf(fpp, "%d / %d / %d / %d / %d / %d / %d / %d / %d /\n" ,core_do_calculations[0],core_do_calculations[1],core_do_calculations[2],
    core_do_calculations[3],core_do_calculations[4],core_do_calculations[5],core_do_calculations[6],core_do_calculations[7], core_do_calculations[8]  );
fprintf(fpp,"#arguments: BPS RATE (25-200, should be 50) / DMX IN RATE (25-50) / \n");
fprintf(fpp, "%d / %d /\n",BPS_RATE,dmxINrate);
fclose(fpp);  sprintf(string_save_load_report[idf],"Saved config_core.txt");

}



if( !fpp )
	{
	 sprintf(string_save_load_report[idf],"!user/config_core.txt");
   }
return(0);
}
