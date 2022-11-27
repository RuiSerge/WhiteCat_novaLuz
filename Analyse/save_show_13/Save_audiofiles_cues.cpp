int Save_audiofiles_cues()
{
    FILE *fpo;
    char tmp_audio_f[512];
    sprintf(tmp_audio_f,"audio\\%s\\audio_cues_in_out.txt",audio_folder);
    if((fpo=fopen(tmp_audio_f,"w")))
    {
        fprintf(fpo,"#arguments: audiofilename / cuein / cueout\n");
        for(int i=1; i<127; i++)
        {
            if(strcmp(list_audio_files[i],"")!=0)//si aps iren en nom de fichier
            {
                fprintf(fpo,"%s / %d / %d\n",list_audio_files[i],audiofile_cue_in_out_pos[i][0],audiofile_cue_in_out_pos[i][1]);
            }
        }
        sprintf(string_save_load_report[idf],"Saved %s",tmp_audio_f);
        fclose(fpo);
    }

    else
    {
        sprintf(string_save_load_report[idf],"Error on audio_cues_in_out.txt");
        b_report_error[idf]=1;
    }


    return(0);
}
