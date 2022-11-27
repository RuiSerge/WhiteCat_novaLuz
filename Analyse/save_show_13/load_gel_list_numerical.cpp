int load_gel_list_numerical()
{
sprintf(rep,"%s\\ressources",mondirectory);
chdir(rep);
volatile bool index_ok=1;
char line [256];
char tmp_name_of_mark[72];
char tmp_name_of_gel[96];
int tmp_ref=0;
int tmprvb[3];
int index_type_of_gel=-1;
int marker_de_gel[4];
float transmission=-1;;
for(int i=0;i<4;i++)
{
marker_de_gel[i]=0;
}

FILE *f=NULL;


if ((f=fopen("gel_list_num_order.txt", "rt"))== NULL)
{
    sprintf(string_save_load_report[0],"Error opening %s","gel_list_num_order.txt"); b_report_error[0]=1;
    idf++;
}
else
    {
	do {
		if (fgets(line,256,f)!=NULL)
		{
		sscanf(line,"%s\t%d\t%s\t%d\t%d\t%d\t%f\n",&tmp_name_of_mark,&tmp_ref,&tmp_name_of_gel,&tmprvb[0],&tmprvb[1],&tmprvb[2],&transmission);

        if(strcmp(tmp_name_of_mark,"Lee")==0){index_type_of_gel=0;}
        if(strcmp(tmp_name_of_mark,"Rosco")==0){index_type_of_gel=1;}
        if(strcmp(tmp_name_of_mark,"GamColor")==0){index_type_of_gel=2;}
        if(strcmp(tmp_name_of_mark,"Apollo")==0){index_type_of_gel=3;}

        if(marker_de_gel[index_type_of_gel]<10000 && index_type_of_gel>=0 && index_type_of_gel<=3 )
        {

        refs_of_gels[index_type_of_gel][marker_de_gel[index_type_of_gel]]=tmp_ref; //numerical reference
        sprintf(name_of_gels[index_type_of_gel][marker_de_gel[index_type_of_gel]],tmp_name_of_gel);//nom des gels
        for(int i=0;i<3;i++)
        {
            rvb_of_gels[index_type_of_gel][(marker_de_gel[index_type_of_gel])][i]=tmprvb[i];//rvb of gels
        }
        gel_transimission[index_type_of_gel][marker_de_gel[index_type_of_gel]]=transmission;
        marker_de_gel[index_type_of_gel]++;
        }
        //reset values
        transmission=-1;
        if(strcmp(line,"ENDDATA")==0){index_ok=0;}
		}
		else break;
	}
	while (index_ok!=0);

}

sprintf(rep,"%s\\",mondirectory);
chdir(rep);
return(0);
}
