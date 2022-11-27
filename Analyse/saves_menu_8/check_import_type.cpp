int check_import_type()
{

if(index_is_saving==0)
{
if(strcmp(importfile_name,"ascii")==0){scan_importfolder("ascii");}
else if(strcmp(importfile_name,"pdf")==0){scan_importfolder("pdf");}
else if(strcmp(importfile_name,"plot")==0  ){scan_importfolder("plot");}
else if(strcmp(importfile_name,"schwz")==0){scan_importfolder("schwz");index_export_choice=1;isSchwz=1;}//christoph 16/06/14 debug perte fonctionnalité import whitecat
else if(strcmp(importfile_name,"..")==0){scan_importfolder("");line_import=0;}
else
{
int f_name_len = strlen(importfile_name);
            // check if it's a dir or a file
          for(int a=0;a<f_name_len;a++)
          {
           if( importfile_name[a]=='.')
           {
                if((importfile_name[a+1]=='a' &&  importfile_name[a+2]=='s' &&  importfile_name[a+3]=='c')
                || (importfile_name[a+1]=='A' &&  importfile_name[a+2]=='S' &&  importfile_name[a+3]=='C')
                || (importfile_name[a+1]=='t' &&  importfile_name[a+2]=='x' &&  importfile_name[a+3]=='t')
                || (importfile_name[a+1]=='T' &&  importfile_name[a+2]=='X' &&  importfile_name[a+3]=='T')
                )
                {
                    isSchwz=0; isPdf=0; isAlq=0;
                    isASCII=1;index_export_choice=0;
                    sprintf(string_typeexport_view,">> ascii file");
                    scan_importfolder("ascii");
                    break;
                }

                if((importfile_name[a+1]=='a' &&  importfile_name[a+2]=='l' &&  importfile_name[a+3]=='q')
                || (importfile_name[a+1]=='A' &&  importfile_name[a+2]=='L' &&  importfile_name[a+3]=='Q'))
                {
                    isSchwz=0;  isPdf=0;
                    isASCII=0; isAlq=1;index_export_choice=2;
                    sprintf(string_typeexport_view,">> ascii alq file");
                    scan_importfolder("ascii");
                    break;
                }

                if((importfile_name[a+1]=='p' &&  importfile_name[a+2]=='d' &&  importfile_name[a+3]=='f')
                ||(importfile_name[a+1]=='P' &&  importfile_name[a+2]=='D' &&  importfile_name[a+3]=='F'))
                {   isSchwz=0;  isASCII=0; isAlq=0;
                    isPdf=1;index_export_choice=3;
                    sprintf(string_typeexport_view,">> PDF file");
                    scan_importfolder("pdf");
                    break;
                }


                else
                {
                isASCII=0; isPdf=0; isAlq=0; isSchwz=1;index_export_choice=1;
                sprintf(string_typeexport_view,">> schwartzpeter");
                scan_importfolder("schwz");
                }

           }
    }
}
}


return(0);
}
