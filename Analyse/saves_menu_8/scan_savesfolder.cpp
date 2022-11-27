int scan_savesfolder()
{
    struct al_ffblk f;
    bool isDir;
    int nbre_de_shows=0;
    sprintf(rep,"%s\\saves",mondirectory);
    chdir(rep);

    if(!al_findfirst("*.*",&f,-1))
    {

            while(!al_findnext(&f))
            {
            int f_name_len = strlen(f.name);
            isDir=true;
            // check if it's a dir or a file
            for( int a=0;a<f_name_len;a++)
            {
                if(f.name[a]=='.')
                {
                    isDir=false;
                    break;
                }
            }
            // we've found a directory!
            if(isDir)
            {
		    sprintf(list_save_files[nbre_de_shows],f.name);
		    nbre_de_shows++;
            }
            }
    }
    al_findclose(&f);
sprintf(rep,"%s\\",mondirectory);
chdir (rep);
return(0);
}
