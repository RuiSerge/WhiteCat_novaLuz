int Load_audiofiles_cues()
{
    FILE *cfg_file = NULL ;
    char read_buff_winfil[ 512 ] ;
    //sab 02/03/2014 unused int it=0;
    char tmp_audio_f[512];
    sprintf(tmp_audio_f,"audio\\%s\\audio_cues_in_out.txt",audio_folder);
    cfg_file = fopen(tmp_audio_f, "rt" );

    if( !cfg_file )
    {
        sprintf(string_save_load_report[idf],"Error on opening %s",audio_folder);
        b_report_error[idf]=1;
    }

    else
    {
        sprintf(string_save_load_report[idf],"audio_cues_in_out.txt opened");
        //premiere ligne les args
        if( !fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file ) )
        {
            sprintf(string_save_load_report[idf],"Error on reading audio_cues_in_out.txt");
            b_report_error[idf]=1;
        }

        else
        {

            //sab 02/03/2014 unused char *tremp;
            int temp_ain[128];
            int temp_aout[128];
            int index_af=0;
            bool index_stop=0;
            for(int u=0; u<127; u++)
            {
                fgets( read_buff_winfil, sizeof( read_buff_winfil ),cfg_file );
                char tmp_name_f[72];
                sscanf(read_buff_winfil, "%s / %d / %d\n",  tmp_name_f,&temp_ain[index_af],&temp_aout[index_af] );

                for(int po=0; po<127; po++)
                {
                    if(strcmp(list_audio_files[po],tmp_name_f)==0 && index_stop==0)
                    {
                        audiofile_cue_in_out_pos[po][0]=temp_ain[index_af];
                        audiofile_cue_in_out_pos[po][1]=temp_aout[index_af];
                        index_stop=1;
                        index_af++;
                    }
                }
                index_stop=0;
            }
        }
        sprintf(string_save_load_report[idf],"audio_cues_in_out.txt readed");
        fclose( cfg_file );
    }


    return(0);
}
