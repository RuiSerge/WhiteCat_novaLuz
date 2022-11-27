int scan_audiofolder()
{

    //reset
    for (int o=0; o<128; o++)
    {
        strcpy(list_audio_files[o],"");
    }
    //detection
    struct al_ffblk f;
    bool isSomeone=0;
    int nrbe_de_fichiers=0;
    sprintf(rep_audio,"%s\\audio\\%s\\",mondirectory,audio_folder);
    chdir(rep_audio);

    if(!al_findfirst("*.*",&f,-1))
    {
        while(!al_findnext(&f))
        {//18/6/2015 correction christoph  unsigned int a
            int f_name_len = strlen(f.name);
            for(int a=0; a< f_name_len; a++)
            {
                //19/12/14 correction christoph ruiserge
                if(f.name[a]=='.' && a<=f_name_len-3)
                {
                    if((f.name[a+1]=='W' &&  f.name[a+2]=='A' &&  f.name[a+3]=='V')
                            ||(f.name[a+1]=='w' &&  f.name[a+2]=='a' &&  f.name[a+3]=='v')
                            ||(f.name[a+1]=='M' &&  f.name[a+2]=='P' &&  f.name[a+3]=='3')
                            ||(f.name[a+1]=='m' &&  f.name[a+2]=='p' &&  f.name[a+3]=='3')
                      )
                    {
                        isSomeone=true;
                        break;
                    }
                    else
                    {
                        isSomeone=false;
                    }
                }
            }
            // we've found a directory!
            if(isSomeone && nrbe_de_fichiers<128)
            {
                sprintf(list_audio_files[nrbe_de_fichiers+1],f.name);
                nrbe_de_fichiers++;
            }
        }
    }
    al_findclose(&f);
    audio_number_total_in_folder=nrbe_de_fichiers;
    sprintf(rep,"%s\\",mondirectory);
    chdir (rep);
    return(0);
}
