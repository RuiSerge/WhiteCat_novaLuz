void scan_importfolder(const char* subdir)
{
    for(int i=0; i<127; i++)
    {
        strcpy(list_import_files[i],"");
    }

    struct al_ffblk f;
    bool isSomeone;
    int nrbe_de_fichiers=0;
    sprintf(rep,"%s\\import_export\\%s",mondirectory,subdir);
    chdir(rep);

    if(!al_findfirst("*.*",&f,-1))
    {
        while(!al_findnext(&f))
        {
            isSomeone=true;


            // we've found a directory!
            if(isSomeone && nrbe_de_fichiers<127)
            {
                sprintf(list_import_files[nrbe_de_fichiers],f.name);
                nrbe_de_fichiers++;
            }
        }
    }
    al_findclose(&f);
    sprintf(rep,"%s\\",mondirectory);
    chdir (rep);
}
