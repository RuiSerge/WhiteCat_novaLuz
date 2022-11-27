int scan_planfolder()//plot
{
    struct al_ffblk f;
    bool isSomeone;
    int nrbe_de_fichiers=0;
    sprintf(rep,"%s\\plans\\",mondirectory);
    chdir(rep);

    if(!al_findfirst("*.*",&f,-1))
    {
        while(!al_findnext(&f))
        {
            //christoph 19/12/14
            int f_name_len = strlen(f.name);
            isSomeone=true; // we've found a directory!
            bool index_check_is_supported=0;
            //christoph 20/06/2015 unsigned int
            for(int a=0; a<f_name_len; a++)
            {
                if( f.name[a]=='.' && a<=f_name_len-3)
                {
                    if(
                        (f.name[a+1]=='j' &&  f.name[a+2]=='p' &&  f.name[a+3]=='g')
                        || (f.name[a+1]=='b' &&  f.name[a+2]=='m' &&  f.name[a+3]=='p')
                        || (f.name[a+1]=='t' &&  f.name[a+2]=='g' &&  f.name[a+3]=='a')
                        || (f.name[a+1]=='p' &&  f.name[a+2]=='n' &&  f.name[a+3]=='g')
                        || (f.name[a+1]=='J' &&  f.name[a+2]=='P' &&  f.name[a+3]=='G')
                        || (f.name[a+1]=='B' &&  f.name[a+2]=='M' &&  f.name[a+3]=='P')
                        || (f.name[a+1]=='T' &&  f.name[a+2]=='G' &&  f.name[a+3]=='A')
                        || (f.name[a+1]=='P' &&  f.name[a+2]=='N' &&  f.name[a+3]=='G')
                    )
                    {
                        index_check_is_supported=1;
                        break;
                    }
                }
            }


            if(isSomeone && nrbe_de_fichiers<127 && index_check_is_supported==1 )
            {
                sprintf(list_import_plans[nrbe_de_fichiers],f.name);
                nrbe_de_fichiers++;
            }
        }

    }
    al_findclose(&f);
    sprintf(rep,"%s\\",mondirectory);
    chdir (rep);
    return(0);
}
