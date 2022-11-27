int do_ASCII_export()
{

index_is_saving=1;
rest(100);
sprintf(rep,"%s\\import_export\\ascii",mondirectory);

chdir(rep);


FILE *fp=NULL;


if((fp=fopen(importfile_name,"wt")))
{
    fprintf(fp,"MANUFACTURER WHITE CAT (c)CHRISTOPH GUILLERMET\n");
    fprintf(fp,"%s\n",versionis);
    fprintf(fp,"IDENT 3.0\n");

fprintf(fp,"CLEAR ALL\n\n");

fprintf(fp,"CLEAR CUES\n");
int s=0;
int m=0;
int level_export=0;

 save_load_print_to_screen("memoires");

    for (m=0; m<10000; m++)
    {
        if (MemoiresExistantes[m]==1)
                {
                fprintf(fp,"\nCUE ");
                fprintf(fp,"%d.%d\n", (m/10),(m%10));

                fprintf(fp,"TEXT %s", descriptif_memoires[m]);
                ////0=DIN  1=IN 2=DOUT 3=OUT
                //sprintf(header_export,"Stage: d:%.1f  OUT: %.1f  | Memory: d:%.1f  IN: %.1f", Times_Memoires[m][2], Times_Memoires[m][3],Times_Memoires[m][0],Times_Memoires[m][1]);

                fprintf(fp,"\nDOWN %.1f %.1f ", Times_Memoires[m][3], Times_Memoires[m][2]);
                fprintf(fp,"\nUP %.1f %.1f ", Times_Memoires[m][1], Times_Memoires[m][0]);
                if (Links_Memoires[m]==0) { fprintf(fp,"\n$$WAIT 0\n");}
                if (Links_Memoires[m]==1) { fprintf(fp,"\n$$WAIT 0.1\n");}

                fprintf(fp,"CHAN ");

                for ( s=1;s<513;s++)
                                {

                                if (Memoires[m][s]>0)
                                                                {
                                                                level_export=(int) (Memoires[m][s]);
                                                                fprintf(fp,"%d/H%x ",s, level_export ); //essai level

                                                                }
                                }

                 fprintf(fp,"\n");
                 }

     }
fprintf(fp,"\n");
fprintf(fp,"CLEAR PATCH\n");
fprintf(fp,"\nPATCH 1 ");

int retour_ligne=0;

for (int cpatch=1; cpatch<513; cpatch++)
{
for (int cpatch2=1;cpatch2<513;cpatch2++)
{
if (Patch[cpatch2]==cpatch)
{
fprintf (fp," %d<%d@100 ", cpatch, cpatch2);
retour_ligne++;
if (retour_ligne>5)
{
fprintf (fp,"\nPATCH 1 ");
retour_ligne=0;
}
}
}
}

fprintf (fp,"\n");
fprintf (fp,"\nCLEAR SUBMASTERS");


for(int d=0;d<6;d++)
{
for(int f=0;f<48;f++)
{
if( DockTypeIs[f][d]==0)
{
fprintf (fp,"\n");
fprintf (fp,"SUB %d\n",(f+(48*d)+1));
fprintf(fp,"UP %.1f\n",time_per_dock[f][d][1]);
fprintf(fp,"DOWN %.1f\n",time_per_dock[f][d][3]);

fprintf(fp,"CHAN ");
for ( s=1;s<513;s++)
{
if (FaderDockContains[f][d][s]!=0 )
{
level_export=(int)(FaderDockContains[f][d][s]);
fprintf(fp,"%d/H%x ",s, level_export ); //essai level
}
}
fprintf(fp,"\n");
}
}
}

fprintf(fp,"\n\nENDDATA");
}
fclose(fp);

sprintf(rep,"%s",mondirectory);
chdir (rep);
index_is_saving=0;

return(0);
}
