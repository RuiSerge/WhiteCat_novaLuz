int do_Schwartzpeter_import()
{
    rest(10);
    index_is_saving=1;
    sprintf(rep,"%s\\import_export\\schwz\\%s",mondirectory,importfile_name);
    chdir(rep);


    FILE *fpscwz=NULL;

    if ((fpscwz=fopen(f_cues, "rb"))==NULL)
    {
        sprintf(string_save_load_report[1],"Error opening file %s", f_cues);
        b_report_error[0]=1;
    }
    else
    {
        if (fread(SchwzMemoires, sizeof(int), SchwzMemoires_size, fpscwz) !=SchwzMemoires_size)
        {
            sprintf(string_save_load_report[1],"Error reading file %s", f_cues);
            b_report_error[0]=1;
        }
        else
        {
            sprintf(string_save_load_report[1],"Schwartzpeter's Memories imported");
        }
    }
    if ((fpscwz=fopen(f_boolcues, "rb"))==NULL)
    {
        sprintf(string_save_load_report[2],"Error opening file %s", f_boolcues);
        b_report_error[2]=1;
    }
    else
    {
        if (fread(SchwzMemoiresExistantes, sizeof(bool), SchwzMemoiresExistantes_size, fpscwz) !=SchwzMemoiresExistantes_size)
        {
            sprintf(string_save_load_report[2],"Error reading file %s", f_boolcues);
            b_report_error[2]=1;
        }
        else
        {
            sprintf(string_save_load_report[2],"Schwartzpeter's Existing Memories imported");
        }
    }
    if ((fpscwz=fopen(f_autogo, "rb"))==NULL)
    {
        sprintf(string_save_load_report[3],"Error opening file %s", f_autogo);
        b_report_error[3]=1;
    }
    else
    {
        if (fread(Schwzautogo, sizeof(bool), Schwzautogo_size, fpscwz) !=Schwzautogo_size)
        {
            sprintf(string_save_load_report[3],"Error reading file %s", f_autogo);
            b_report_error[3]=1;
        }
        else
        {
            sprintf(string_save_load_report[3],"Schwartzpeter's Autopo imported");
        }
    }
    if ((fpscwz=fopen(f_times, "rb"))==NULL)
    {
        sprintf(string_save_load_report[4],"Error opening file %s", f_times);
        b_report_error[4]=1;
    }
    else
    {
        if (fread(SchwzMemTime, sizeof(float), SchwzMemTime_size, fpscwz) !=SchwzMemTime_size)
        {
            sprintf(string_save_load_report[4],"Error reading file %s", f_times);
            b_report_error[4]=1;
        }
        else
        {
            sprintf(string_save_load_report[4],"Schwartzpeter's Times Memories imported");
        }
    }
    if ((fpscwz=fopen(f_patch, "rb"))==NULL)
    {
        sprintf(string_save_load_report[5],"Error opening file %s", f_patch);
        b_report_error[5]=1;
    }
    else
    {
        if (fread(SchwzPatch, sizeof(int), SchwzPatch_size, fpscwz) !=SchwzPatch_size)
        {
            sprintf(string_save_load_report[5],"Error reading file %s", f_patch);
            b_report_error[5]=1;
        }
        else
        {
            sprintf(string_save_load_report[5],"Schwartzpeter's Patch imported");
        }
    }
    if ((fpscwz=fopen(f_descriptif, "rb"))==NULL)//?
    {
        sprintf(string_save_load_report[6],"Error opening file %s", f_descriptif);
        b_report_error[6]=1;
    }
    else
    {
        if (fread(Schwzdescriptif_mem, sizeof(char), Schwzdescriptif_size, fpscwz) !=Schwzdescriptif_size)
        {
            sprintf(string_save_load_report[6],"Error reading file %s", f_descriptif);
            b_report_error[6]=1;
        }
        else
        {
            sprintf(string_save_load_report[6],"Schwartzpeter's Memories Description imported");
        }
    }
    if ( (fpscwz=fopen(f_shadow_sub, "rb") )==NULL)
    {
        sprintf(string_save_load_report[7],"Error opening file %s", f_shadow_sub);
        b_report_error[7]=1;
    }
    else
    {
        if ( fread(Schwzshadow_sub, sizeof(int), Schwzsize_of_shadow_sub, fpscwz) != Schwzsize_of_shadow_sub)
        {
            sprintf(string_save_load_report[7],"Error reading file %s", f_shadow_sub);
            b_report_error[7]=1;
        }
        else
        {
            sprintf(string_save_load_report[1],"Schwartzpeter ShadowSubs imported");
        }
    }
    fclose(fpscwz);
    int schwzmem_before=0;
    for (int m=1; m<5000; m++)
    {
        MemoiresExistantes[m]=SchwzMemoiresExistantes[m];
        for (int c=0; c<121; c++)
        {
            Memoires[m][c]=(unsigned char)(SchwzMemoires[c][m]*2.55);
            if(SchwzMemoires[c][m]==100)
            {
                Memoires[m][c]=255;
            }
        }
        Links_Memoires[m]=Schwzautogo[m];
        Times_Memoires[m][0]=SchwzMemTime[m][3];
        Times_Memoires[m][1]=SchwzMemTime[m][1];
        Times_Memoires[m][2]=SchwzMemTime[schwzmem_before][2];
        Times_Memoires[m][3]=SchwzMemTime[schwzmem_before][0];

        for(int t=0; t<11; t++)
        {
            if(Schwzdescriptif_mem[m][t]=='\0')
            {
                break;
            }
            else
            {
                descriptif_memoires[m][t]=Schwzdescriptif_mem[m][t];
            }
        }
        descriptif_memoires[m][23]='\0';//christoph 16/06/14 debug instead of "\n"
        if(SchwzMemoiresExistantes[m]==1)
        {
            schwzmem_before=m;
        }
    }


    for (int di=0; di<513; di++)
    {
        Patch[di]=SchwzPatch[di];
    }
    for (int f=0; f<8; f++)
    {
        for(int f2=1; f2<6; f2++)
        {
            DockIsSelected[f*f2][0]=1;
            DockTypeIs[f*f2][0]=0;
            for (int co=0; co<121; co++)
            {
                FaderDockContains[f*f2][0][co]=(unsigned char)Schwzshadow_sub[f][f2-1][co];
            }
        }
    }
    sprintf(rep,"%s",mondirectory);
    chdir (rep);

    index_is_saving=0;
    return(0);
}
