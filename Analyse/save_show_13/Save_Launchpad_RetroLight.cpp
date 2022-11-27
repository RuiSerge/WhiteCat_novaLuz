int Save_Launchpad_RetroLight()
{
    FILE *fpp;
    if((fpp=fopen("user/launchpad_lighting.txt","w")))//etait wb
    {
        fprintf(fpp,"#arguments: orange / green / yellow / red  / ambre / dark orange /\n");
        fprintf(fpp, "%d / %d / %d / %d / %d / %d /\n",  lch_orange, lch_green, lch_yellow, lch_red, lch_ambre, lch_orange_fonce);
        fclose(fpp);
        sprintf(string_save_load_report[idf],"Saved launchpad_lighting.txt");
    }

    if( !fpp )
    {
        sprintf(string_save_load_report[idf],"!user/launchpad_lighting.txt");
    }
    return(0);
}
