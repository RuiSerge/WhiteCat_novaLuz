int Save_Sequenciel_Conf()
{
    FILE *fpo;
    if((fpo=fopen("sequenciel.txt","w")))
    {
        fprintf(fpo,"#arguments: mem_on_stage*10 / mem_on_preset*10 / master_stage / master_preset / speed /\n");
        fprintf(fpo,"%d / %d / %d / %d / %d /\n",position_onstage, position_preset,niveauX1,niveauX2,crossfade_speed);
        fprintf(fpo,"%.1f /\n",default_time);
        fprintf(fpo,"%d %d /\n", go_channel_is,pause_channel_is);
        sprintf(string_save_load_report[idf],"Saved sequenciel.txt");
        fclose(fpo);
    }
    else
    {
        sprintf(string_save_load_report[idf],"Error on sequenciel.txt");
        b_report_error[idf]=1;
    }

    return(0);
}
