int do_ASCII_import()
{
    index_is_saving=1;
    sprintf(rep,"%s\\import_export\\ascii",mondirectory);
    chdir(rep);



    char line [512];
    int cue=0;
    float down=0.0;
    float up=0.0;
    int chan=0;
    int level=0;//garder en int sinon la lecture ne se fait pas !
    float autogotime=0.0;
    int dimmer=0;
    char *temp;
    int sub=0;
    int ok= -1;
    int flagcue= -1;
    int flagpatch= -1;
    int flagsub=-1;
    int first_cue_from_import=0;



    FILE *f=NULL;


    if ((f=fopen(importfile_name, "rt"))== NULL)
    {
        sprintf(string_save_load_report[0],"Error opening %s",importfile_name);
        b_report_error[0]=1;

    }
    else
    {
        do
        {
            if (fgets(line,512,f)!=NULL)
            {
                if (strncmp(line, "CUE",3)==0)
                {
                    float tmpcueval= strtof(line+4,NULL);
                    cue = (int)(tmpcueval*10);
                    MemoiresExistantes[cue]=1;
                    if(first_cue_from_import==0)
                    {
                        first_cue_from_import=cue;
                    }
                    flagcue=1;
                    flagsub=-1;
                    flagpatch=-1;

                }

                if(flagcue==1)//cues
                {

                    if(strncmp(line,"TEXT",4)==0)
                    {
                        for (int p=0; p<24; p++)
                        {
                            descriptif_memoires[cue][p]=line[p+5];
                        }
                        descriptif_memoires[cue][24]='\0';
                    }

                    ////0=DIN  1=IN 2=DOUT 3=OUT
                    //sprintf(header_export,"Stage: d:%.1f  OUT: %.1f  | Memory: d:%.1f  IN: %.1f", Times_Memoires[m][2], Times_Memoires[m][3],Times_Memoires[m][0],Times_Memoires[m][1]);


                    if(strncmp(line,"DOWN",4)==0)
                    {
                        down=(float)strtof(line+5,NULL);
                        Times_Memoires[cue][3]=down;

                    }
                    if(strncmp(line,"UP",2)==0)
                    {
                        up=(float)strtof(line+3,NULL);
                        Times_Memoires[cue][1]=up;

                    }
                    if(strncmp(line,"$$WAIT",6)==0)
                    {
                        autogotime=(float)strtof(line+7,NULL);
                        if (autogotime>0)
                        {
                            Links_Memoires[cue]=1;
                        }
                        //	Times_Memoires[cue][0]=autogotime;
                        //	Times_Memoires[cue][2]=autogotime;
                    }

                    if(strncmp(line,"CHAN",4)==0)
                    {
                        temp= strtok(line+5," ");
                        while((temp!=NULL) && (strcmp(temp,"\n")!=0))
                        {
                            sscanf(temp,"%d/H%x\n",&chan,&level);//debug 3/12/14 christoph
                            Memoires[cue][chan]=(unsigned char)level;
                            temp=strtok(NULL," ");
                        }
                    }
                }//fin cues

                if (strncmp(line, "SET DEFAULT PATCH",17)==0 || strncmp(line, "CLEAR PATCH",11)==0  )
                {

                    flagcue=-1;
                    flagsub=-1;
                    flagpatch=1;
                    if (strncmp(line, "SET DEFAULT PATCH",17)==0 )
                    {
                        patch_to_default_selected();
                    }
                    else if (strncmp(line, "CLEAR PATCH",11)==0 )
                    {
                        patch_clear_selected();
                    }
                }
                if (flagpatch==1)//patch
                {
                    if(strncmp(line,"PATCH 1",7)==0)
                    {
                        temp= strtok(line+7," ");
                        while((temp!=NULL) && (strcmp(temp,"\n")!=0))
                        {
                            sscanf(temp,"%d<%d\n",&chan,&dimmer);
                            if(dimmer<513 && chan<513)
                            {
                                Patch[dimmer]=chan;
                            }
                            temp=strtok(NULL," ");

                        }
                    }
                }//fin patch


                //subs

                if (strncmp(line, "SUB",3)==0)
                {
                    sub= (int)strtof(line+4,NULL);
                    flagsub=1;
                    flagcue=-1;
                    flagpatch=-1;
                }

                if(flagsub==1)
                {
                    int sub_f=0;
                    int sub_d=0;

                    if(sub<50 && sub!=0)
                    {
                        sub_f=sub-1;
                        sub_d=0;
                    }
                    else
                    {
                        sub_f=((sub-1)%48);
                        sub_d=((sub-1)/48);
                    }


                    if(strncmp(line,"TEXT",4)==0)
                    {

                        for (int p=0; p<24; p++)
                        {
                            DockName[sub_f][sub_d][p]=line[p+5];
                        }
                        DockName[sub_f][sub_d][24]='\0';
                    }

                    if(strncmp(line,"DOWN",4)==0)
                    {
                        down=(float)strtof(line+5,NULL);
                        //sab 02/03/2014 IMPACT time_per_dock[sub_f][sub_d][3]==down;
                        time_per_dock[sub_f][sub_d][3]=down;

                    }
                    if(strncmp(line,"UP",2)==0)
                    {
                        up=(float)strtof(line+3,NULL);
                        time_per_dock[sub_f][sub_d][1]=up;

                    }
                    if(strncmp(line,"$$WAIT",6)==0)
                    {
                        autogotime=(float)strtof(line+7,NULL);
                        time_per_dock[sub_f][sub_d][0]=autogotime;
                        time_per_dock[sub_f][sub_d][2]=autogotime;
                    }

                    if(strncmp(line,"CHAN",4)==0)
                    {
                        DockTypeIs[sub_f][sub_d]=0;
                        temp= strtok(line+5," ");
                        while((temp!=NULL) && (strcmp(temp,"\n")!=0))
                        {
                            sscanf(temp,"%d/H%x\n",&chan,&level);//debug 3/12/14 christoph
                            if(chan<513)
                            {
                                FaderDockContains[sub_f][sub_d][chan]=(unsigned char)level ;
                                temp=strtok(NULL," ");
                            }
                        }

                    }

                }//fin subs

            }
            else break;
            if(strcmp(line,"ENDDATA")==0)
            {
                ok=0;
            }
        }
        while (ok!=0);

        fclose(f);
    }
    scan_for_free_dock();
    position_onstage=first_cue_from_import;
    refresh_mem_onstage(position_onstage);
    detect_mem_before_one();
    detect_mem_preset();
    refresh_mem_onpreset(position_preset);
    index_window_sequentiel=1;
    sprintf(rep,"%s",mondirectory);
    chdir (rep);
    index_is_saving=0;
    return(0);
}
